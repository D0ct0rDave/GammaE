// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "GammaE_Mem.h"
#include "GammaE_Misc.h"

#include "CGOGLWinRenderer.h"

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glext.h>

#include "RenderVars/CGRenderVars.h"

#include "Mesh/CGMesh.h"
#include "Mesh/CGCompiledMesh.h"

#include "Viewing/Camera/CGCamera.h"
#include "Viewing/Viewport/CGViewport.h"
#include "Viewing/Projector/CGProjector.h"

#include "MeshDB/CGDefferredMeshDB.h"

#include "Shaders/CGShader.h"
#include "Materials/CGTexObj.h"
#include "Materials/CGColor.h"
#include "Materials/CGProgram.h"
#include "Light/CGLight.h"
#include "GammaE_Math.h"

// ----------------------------------------------------------------------------
// The format of the functions we're gonna get hold of.
typedef void (APIENTRY * PFNGLCOLORTABLEEXT)(int, int, int, int, int, const void* );
PFNGLSECONDARYCOLOR3FVPROC glSecondaryColor3fv = NULL;

// Our function pointers.
PFNGLCOLORTABLEEXT glColorTableEXT;

PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB = NULL;
PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB = NULL;
PFNGLSHADERSOURCEARBPROC glShaderSourceARB = NULL;
PFNGLCOMPILESHADERARBPROC glCompileShaderARB = NULL;
PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB = NULL;
PFNGLATTACHOBJECTARBPROC glAttachObjectARB = NULL;
PFNGLGETINFOLOGARBPROC glGetInfoLogARB = NULL;
PFNGLLINKPROGRAMARBPROC glLinkProgramARB = NULL;
PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB = NULL;
PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB = NULL;
PFNGLUNIFORM1FARBPROC glUniform1fARB = NULL;
PFNGLUNIFORM1IARBPROC glUniform1iARB = NULL;

// CGOGLWinRenderer
#include "Drivers\OGL\CGOGLWinRenderer.h"
#include "CGOGLMatrixStack.h"
// ----------------------------------------------------------------------------
CGOGLMatrixStack m_oCamMatrixStack;
CGOGLMatrixStack m_oWorldMatrixStack;
static CGColor m_oClearColor(0.25,0.25,0.25,1.0f);
static CGShader E3D_NULL_SHADER;
// ----------------------------------------------------------------------------
uint GetTextureFormat(EImageFormat PixelFormat)
{
    switch ( PixelFormat )
    {
        case IF_RGBA:   return(GL_RGBA);

        case IF_RGB:    return(GL_RGB);

        // case TEX_PF_GRAY8: return(GL_LUMINANCE);
        case IF_PALETTE: return(GL_COLOR_INDEX);

        default:
        return(GL_RGBA);
    }
}
// ----------------------------------------------------------------------------
uint GetTextureInternalFormat(EImageFormat PixelFormat)
{
    switch ( PixelFormat )
    {
        case IF_RGBA:   return(GL_RGBA8);

        case IF_RGB:    return(GL_RGB8);

        // case TEX_PF_GRAY8: return(GL_LUMINANCE);
        case IF_PALETTE: return(GL_COLOR_INDEX8_EXT);

        default:
        return(0);
    }
}
// ----------------------------------------------------------------------------
GLenum eGetStencilAct(E3D_StencilAction _eSA)
{
    switch ( _eSA )
    {
        case E3D_SA_None:   return(GL_KEEP);

        case E3D_SA_Keep:   return(GL_KEEP);

        case E3D_SA_Zero:   return(GL_ZERO);

        case E3D_SA_Inc:    return(GL_INCR);

        case E3D_SA_Dec:    return(GL_DECR);

        case E3D_SA_Inv:    return(GL_INVERT);

        default:
        return(GL_KEEP);
    }
}
// ----------------------------------------------------------------------------
GLenum eGetStencilFunc(E3D_StencilFunc _eSF)
{
    switch ( _eSF )
    {
        case E3D_SF_None:       return(GL_ALWAYS);

        case E3D_SF_Never:      return(GL_NEVER);

        case E3D_SF_Less:       return(GL_LESS);

        case E3D_SF_LEqual:     return(GL_LEQUAL);

        case E3D_SF_Greater:    return(GL_GREATER);

        case E3D_SF_GEqual:     return(GL_GEQUAL);

        case E3D_SF_Equal:      return(GL_EQUAL);

        case E3D_SF_NotEqual:   return(GL_NOTEQUAL);

        case E3D_SF_Always:     return(GL_ALWAYS);

        default:
        return(GL_ALWAYS);
    }
}
// ----------------------------------------------------------------------------
GLenum eGetFogMode(E3D_FogMode _eFM)
{
    switch ( _eFM )
    {
        case E3D_FM_None:   return(GL_LINEAR);

        case E3D_FM_Linear: return(GL_LINEAR);

        case E3D_FM_Exp:    return(GL_EXP);

        case E3D_FM_Exp2:   return(GL_EXP2);

        default:
        return(GL_LINEAR);
    }
}
// ----------------------------------------------------------------------------
GLenum eGetDepthFunc(E3D_ZTestFunc _ZT)
{
    switch ( _ZT )
    {
        case E3D_ZTF_None:      return(GL_ALWAYS);

        case E3D_ZTF_Never:     return(GL_NEVER);

        case E3D_ZTF_Less:      return(GL_LESS);

        case E3D_ZTF_LEqual:    return(GL_LEQUAL);

        case E3D_ZTF_Greater:   return(GL_GREATER);

        case E3D_ZTF_GEqual:    return(GL_GEQUAL);

        case E3D_ZTF_Equal:     return(GL_EQUAL);

        case E3D_ZTF_NotEqual:  return(GL_NOTEQUAL);

        case E3D_ZTF_Always:    return(GL_ALWAYS);

        default:
        return(GL_ALWAYS);
    }
}
// ----------------------------------------------------------------------------
GLenum eGetLightID(int _iLightID)
{
    return(GL_LIGHT0 + _iLightID);
}
// ----------------------------------------------------------------------------
// For Lighting
#define      MAX_LIGHTS  8
CGVect4 oLPos   [MAX_LIGHTS];
uint uiEnabledLights = 0;
// ----------------------------------------------------------------------------
#ifdef _DEBUG
static int s_iLastError = 0;
static int s_iError = 0;

static void CHECKERRORS()
{
    s_iLastError = 0;

    do {
        s_iError = glGetError();

        if ( s_iError != GL_NO_ERROR )
        {
            s_iLastError = s_iError;
        }
    } while ( s_iError != GL_NO_ERROR );
}
#else
    #define CHECKERRORS()
#endif

// #define _DEBUG_WIREFRAME
// ----------------------------------------------------------------------------
CGOGLWinRenderer::CGOGLWinRenderer()
{
    // Setup NULL color
    CGShInsColor* poColor = mNew CGShInsColor;
    poColor->SetColor( CGColor(1.0f,0.0f,0.0f,0.5f) );
    E3D_NULL_SHADER.AddInstruction(poColor);

    // ----------------------------------------------------------------------------
    // Create and initialize engine associated objects
    // ----------------------------------------------------------------------------
    m_oREStats.m_fFPS = 1.0f;
    m_oREStats.m_fDelta = 0.0f;
    m_oREStats.m_uiCurrentFrame = 0;
    m_oREStats.m_fTotalTime = 0.0f;
}
// ----------------------------------------------------------------------------
CGOGLWinRenderer::~CGOGLWinRenderer()
{
    Finish();
}
// ----------------------------------------------------------------------------
bool CGOGLWinRenderer::bInit(handler _hDeviceContext, uint _uiOptions, uint _uiScrTX, uint _uiScrTY, uint _uiColorBits)
{
    // ----------------------------------------------------------------------------
    // Begin Windows specific
    // ----------------------------------------------------------------------------
#define OP_SetOption(variable,option) variable |= option
#define OP_IsOption(variable,option) (variable & option)

    TPixelFormatDescriptor PFDescriptor;
    int PixelFormat;

    // Set the OpenGL properties required to draw to the given canvas and
    // create a rendering context for it.
    WND = (HWND) _hDeviceContext;
    DC = GetDC(WND);

    memset( (void*)&PFDescriptor,0,sizeof(TPixelFormatDescriptor) );

    PFDescriptor.nSize = sizeof(TPixelFormatDescriptor);
    PFDescriptor.nVersion = 1;
    PFDescriptor.dwFlags = PFD_SUPPORT_OPENGL;

    if ( GetObjectType(DC) == OBJ_MEMDC )
        OP_SetOption(PFDescriptor.dwFlags,PFD_DRAW_TO_BITMAP);
    else
        OP_SetOption(PFDescriptor.dwFlags,PFD_DRAW_TO_WINDOW);

    if ( OP_IsOption(_uiOptions,E3D_RENDERER_OP_DBUFFER) ) OP_SetOption(PFDescriptor.dwFlags,PFD_DOUBLEBUFFER);
    if ( OP_IsOption(_uiOptions,E3D_RENDERER_OP_GDI    ) ) OP_SetOption(PFDescriptor.dwFlags,PFD_SUPPORT_GDI );
    if ( OP_IsOption(_uiOptions,E3D_RENDERER_OP_STEREO ) ) OP_SetOption(PFDescriptor.dwFlags,PFD_STEREO      );

    PFDescriptor.iPixelType = PFD_TYPE_RGBA;
    PFDescriptor.cColorBits = _uiColorBits;
    PFDescriptor.cDepthBits = 24;
    PFDescriptor.cStencilBits = 8;
    // PFDescriptor.iLayerType   = unsigned char (PFD_MAIN_PLANE);

    // just in case it didn't happen already
    PixelFormat = ChoosePixelFormat(DC,&PFDescriptor);
    if ( !PixelFormat )
    {
        MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK | MB_ICONEXCLAMATION);
        exit(1);
    }

    // Attempt to set the pixel format
    if ( !SetPixelFormat(DC,PixelFormat,&PFDescriptor) )
    {
        MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK | MB_ICONEXCLAMATION);
        exit(1);
    }

    // check the properties just set
    DescribePixelFormat(DC,PixelFormat,sizeof(TPixelFormatDescriptor),&PFDescriptor);

    if ( OP_IsOption(PFDescriptor.dwFlags,PFD_NEED_PALETTE) ) SetupPalette(PFDescriptor);

    GLRC = wglCreateContext(DC);

    // read implementation properties
    wglMakeCurrent(DC,GLRC);

    // ----------------------------------------------------------------------------
    // End Windows specific
    // ----------------------------------------------------------------------------

    // ----------------------------------------------------------------------------
    // Setup openGL default state
    // ----------------------------------------------------------------------------
    m_uiScrTX = _uiScrTX;
    m_uiScrTY = _uiScrTY;

    // Frame buffer clear color
    glClearColor(m_oClearColor.r,m_oClearColor.g,m_oClearColor.g,m_oClearColor.a);

    // Render buffer
    glDrawBuffer(GL_BACK);

    // Stencil clear value
    glClearStencil(0);

    // Z Buffer func.
    glEnable   (GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Culling function
    glEnable(GL_CULL_FACE);
    glDisable(GL_CULL_FACE); // DEBUG_CODE
    // glCullFace(GL_BACK);

    #ifdef _DEBUG
    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonMode(GL_BACK,GL_LINE);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    #ifdef _DEBUG_WIREFRAME
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    #endif
    #endif

    // Enable texuring
    glEnable (GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Activar alpha test
    // glEnable   (GL_ALPHA_TEST);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GREATER,0.0f);

    // Desactivar el render con color
    glDisableClientState(GL_COLOR_ARRAY);

    // Activar el resto necesarios
    glEnableClientState (GL_VERTEX_ARRAY);
    glEnableClientState (GL_TEXTURE_COORD_ARRAY);

    // Lighting disabled by default
    glDisable(GL_LIGHTING);

    GLfloat mat_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat mat_shininess[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    GLfloat global_amb[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glMaterialfv    (GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv    (GL_FRONT, GL_SHININESS, mat_shininess);
    glLightModelfv  (GL_LIGHT_MODEL_AMBIENT,global_amb);

    glColor4f(1,1,1,0);
    glHint      (GL_FOG_HINT,GL_DONT_CARE);

    // -------------------------------------
    // Enable paletted textures
    // -------------------------------------
    glColorTableEXT = (PFNGLCOLORTABLEEXT)wglGetProcAddress("glColorTableEXT");
    if ( glColorTableEXT )
    {
        glEnable(GL_SHARED_TEXTURE_PALETTE_EXT);
    }
    else
    {
        // DMC: error / warning
    }

    glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC)    wglGetProcAddress("glUseProgramObjectARB");
    glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC) wglGetProcAddress("glCreateProgramObjectARB");
    glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC)        wglGetProcAddress("glShaderSourceARB");
    glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC)  wglGetProcAddress("glCreateShaderObjectARB");
    glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC)       wglGetProcAddress("glCompileShaderARB");
    glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)wglGetProcAddress("glGetObjectParameterivARB");
    glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC)        wglGetProcAddress("glAttachObjectARB");
    glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC)         wglGetProcAddress("glLinkProgramARB");
    glGetInfoLogARB = (PFNGLGETINFOLOGARBPROC)          wglGetProcAddress("glGetInfoLogARB");
    glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC)  wglGetProcAddress("glGetUniformLocationARB");
    glUniform1fARB = (PFNGLUNIFORM1FARBPROC)           wglGetProcAddress("glUniform1fARB");
    glUniform1iARB = (PFNGLUNIFORM1IARBPROC)           wglGetProcAddress("glUniform1iARB");

    glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)      wglGetProcAddress("glSecondaryColor3fv");

    // -------------------------------------
    // Initialize material renderer
    // -------------------------------------
    oShaderRenderer.Init();

    return(1);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::Finish ()
{
    if ( (GLRC) && (DC) )
    {
        // Deactivate rendering context
        wglMakeCurrent(0,0);
        // Destroy rendering context
        wglDeleteContext(GLRC);

        ReleaseDC(WND,DC);

        GLRC = NULL;
        DC = NULL;
    }
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::RenderBV(CGBoundingVolume* BVol)
{
    /*
       // DMC REFACT

       if ( !BVol ) return;

       float fXSize = BVol->GetRange(0) * 0.5f;
       float fYSize = BVol->GetRange(1) * 0.5f;
       float fZSize = BVol->GetRange(2) * 0.5f;

       CGVect3 Pos = BVol->GetCenter();

       glBlendFunc(GL_ONE,GL_ZERO);
       glDisable(GL_TEXTURE_2D);
       glDisable(GL_CULL_FACE);
       glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

       glColor3f(1.0f,1.0f,0.25f);
       glBegin(GL_QUADS);
       glVertex3f(Pos.x - fXSize,Pos.y - fYSize,Pos.z + fZSize);
       glVertex3f(Pos.x - fXSize,Pos.y + fYSize,Pos.z + fZSize);
       glVertex3f(Pos.x + fXSize,Pos.y + fYSize,Pos.z + fZSize);
       glVertex3f(Pos.x + fXSize,Pos.y - fYSize,Pos.z + fZSize);

       glVertex3f(Pos.x - fXSize,Pos.y - fYSize,Pos.z + fZSize);
       glVertex3f(Pos.x - fXSize,Pos.y + fYSize,Pos.z + fZSize);
       glVertex3f(Pos.x - fXSize,Pos.y + fYSize,Pos.z - fZSize);
       glVertex3f(Pos.x - fXSize,Pos.y - fYSize,Pos.z - fZSize);

       glVertex3f(Pos.x + fXSize,Pos.y - fYSize,Pos.z + fZSize);
       glVertex3f(Pos.x + fXSize,Pos.y + fYSize,Pos.z + fZSize);
       glVertex3f(Pos.x + fXSize,Pos.y + fYSize,Pos.z - fZSize);
       glVertex3f(Pos.x + fXSize,Pos.y - fYSize,Pos.z - fZSize);

       glVertex3f(Pos.x - fXSize,Pos.y - fYSize,Pos.z - fZSize);
       glVertex3f(Pos.x - fXSize,Pos.y + fYSize,Pos.z - fZSize);
       glVertex3f(Pos.x + fXSize,Pos.y + fYSize,Pos.z - fZSize);
       glVertex3f(Pos.x + fXSize,Pos.y - fYSize,Pos.z - fZSize);
       glEnd();
       // glEnable(GL_CULL_FACE);

       glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
       glEnable(GL_TEXTURE_2D);
     */
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::RenderNormals (CGMesh* Mesh)
{
    if ( (Mesh->m_poVN) && (Mesh->m_poVX) )
    {
        glBlendFunc(GL_ONE,GL_ZERO);
        glDisable(GL_TEXTURE_2D);

        CGVect3* pVX = Mesh->m_poVX;
        CGVect3* pVN = Mesh->m_poVN;
        CGVect3 pEnd;

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,1.0f);

        for ( int cVert = 0; cVert < Mesh->uiGetNumVXs(); cVert++ )
        {
            pEnd.Assign(*pVN);
            pEnd.Scale (2.0f);
            pEnd.Add(*pVX);

            glVertex3fv( pVX->V() );
            glVertex3fv( pEnd.V() );

            pVX++;
            pVN++;
        }

        glEnd();
        glEnable(GL_TEXTURE_2D);
    }
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::DisableBVRender ()
{
    m_oREState.m_bBVRender = false;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::DisableDefferredMode ()
{
    m_oREState.m_bDefferredMode = false;

    if ( m_oDefObjWH.uiNumObjects() )
        RenderDefferredObjects();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::DisableFrustumCulling ()
{
    m_oREState.m_bFrustumCulling = false;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::DisableNormalRender ()
{
    m_oREState.m_bNormalRender = false;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::EnableBVRender ()
{
    m_oREState.m_bBVRender = true;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::EnableDefferredMode ()
{
    m_oREState.m_bDefferredMode = true;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::EnableFrustumCulling ()
{
    m_oREState.m_bFrustumCulling = true;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::EnableNormalRender ()
{
    m_oREState.m_bNormalRender = true;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::BeginRender ()
{
    m_oChrono.Reset();
    m_oChrono.Start();

    // Invalidate Defferred objects warehouse
    m_oDefObjWH.Invalidate();

    // Initialize statistic variables
    m_oREStats.m_uiNumTestedObjs = 0;
    m_oREStats.m_uiNumRenderedObjs = 0;
    m_oREStats.m_uiNumCulledObjs = 0;
    m_oREStats.m_uiNumRenderedTris = 0;
    m_oREStats.m_uiNumRenderedVerts = 0;

    GLint BufferMask;
    BufferMask = GL_COLOR_BUFFER_BIT;

    if ( m_eStencilFunc != E3D_SF_None ) BufferMask |= GL_STENCIL_BUFFER_BIT;
    if ( m_eZTest != E3D_ZTF_None ) BufferMask |= GL_DEPTH_BUFFER_BIT;

    glClear(BufferMask);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::EndRender ()
{
    // If there are some defferred objects render them
    if ( m_oDefObjWH.uiNumObjects() )
        RenderDefferredObjects();

    SwapBuffers(DC);

    // Get delta time
    m_oChrono.Stop();

    // /
    m_oREStats.m_fDelta = (float)m_oChrono.dElapsedTime();

    // /
    if ( m_oREStats.m_fDelta > 0.0f )
        m_oREStats.m_fFPS = 1.0f / m_oREStats.m_fDelta;
    else
        m_oREStats.m_fFPS = _INFINITE_;

    // Increase total render time
    m_oREStats.m_fTotalTime += m_oREStats.m_fDelta;

    // One more frame
    m_oREStats.m_uiCurrentFrame++;
}
// ----------------------------------------------------------------------------
// World / Model Matrix
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::ClearWorldMatrix ()
{
    m_oWorldMatrixStack.LoadIdentity();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetWorldMatrix (CGMatrix4x4* M)
{
    m_oWorldMatrixStack.Load(*M);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::GetWorldMatrix (CGMatrix4x4* M)
{
    *M = m_oWorldMatrixStack.oGetTop();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::PushWorldMatrix ()
{
    m_oWorldMatrixStack.Push();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::PopWorldMatrix ()
{
    m_oWorldMatrixStack.Pop();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::MultiplyMatrix(CGMatrix4x4* Matrix)
{
    m_oWorldMatrixStack.Multiply(*Matrix);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::PreMultiplyMatrix (CGMatrix4x4* Matrix)
{
    // Leaves X = M * MatrixStack
    CGMatrix4x4 oMat;
    oMat.Multiply( *Matrix,m_oWorldMatrixStack.oGetTop() );

    m_oWorldMatrixStack.Load(oMat);
}
// ----------------------------------------------------------------------------
// Camera matrix operations
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetCameraMatrix (CGMatrix4x4* M)
{
    m_oCamMatrixStack.Load( *M );
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::GetCameraMatrix (CGMatrix4x4* M)
{
    *M = m_oCamMatrixStack.oGetTop();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::ClearCameraMatrix ()
{
    m_oCamMatrixStack.LoadIdentity();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::PushCameraMatrix ()
{
    m_oCamMatrixStack.Push();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::PopCameraMatrix ()
{
    m_oCamMatrixStack.Pop();
}
// ----------------------------------------------------------------------------
// Projector matrix operations
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::ClearProjectorMatrix ()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    CHECKERRORS();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetProjectorMatrix (CGMatrix4x4* M)
{
    // copiar directamente a OpenGL
    glMatrixMode (GL_PROJECTION);
    glLoadMatrixf( M->pfGetData() );
    CHECKERRORS();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::GetProjectorMatrix (CGMatrix4x4* M)
{
    glGetFloatv( GL_PROJECTION_MATRIX,M->pfGetData() );
    CHECKERRORS();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::PushProjectorMatrix ()
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    CHECKERRORS();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::PopProjectorMatrix ()
{
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    CHECKERRORS();
}
// ----------------------------------------------------------------------------
//
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::RenderDefferredObjects ()
{
    // Sort meshes by material
    m_oDefObjWH.Sort();

    // Get the number of enabled lights
    uint uiOldEnabledLights = uiEnabledLights;

    PushWorldMatrix();

    // Loop through all deferred objects
    for ( uint i = 0; i < m_oDefObjWH.uiNumObjects(); i++ )
    {
        // Get object data
        CGDefferredMeshEntry oDME = m_oDefObjWH.oGetObject(i);

        // Internal render
        RenderMesh_Int(oDME.poMesh,oDME.poShader,oDME.oMatrix);
    }

    PopWorldMatrix();

    // Restore light state
    uiEnabledLights = uiOldEnabledLights;

    m_oDefObjWH.Invalidate();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::RenderMesh (CGBaseMesh* _poMesh)
{
    RenderMesh(_poMesh,m_poCurrentShader);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::RenderMesh (CGBaseMesh* _poMesh, CGShader* _poShader)
{
    if ( _poShader == NULL )
        _poShader = &E3D_NULL_SHADER;

    if ( _poMesh->uiGetNumPrims() == 0 )
        return;

    // Retrieve the modelview matrix
    CGMatrix4x4 oM = m_oCamMatrixStack.oGetTop() * m_oWorldMatrixStack.oGetTop();

    // Test visibility: if not visible, then don't render it
    if ( (m_oREState.m_bFrustumCulling) && ( _poMesh->poGetBV() ) )
    {
        // Number of tested objects against frustum
        m_oREStats.m_uiNumTestedObjs++;

        if ( !Math::bBVIntersectFrustum( *_poMesh->poGetBV(),oM,m_oFrustum) )
        {
            // Number of not visible objects
            m_oREStats.m_uiNumCulledObjs++;
            return;
        }
    }

    // Number of objects sent to render
    m_oREStats.m_uiNumRenderedObjs++;

    if ( m_oREState.m_bDefferredMode )
    {
        // Insert deferred objects
        m_oDefObjWH.bInsertDefferredObject(_poMesh,_poShader,oM,uiEnabledLights);
    }
    else
    {
        RenderMesh_Int(_poMesh,_poShader,oM);
    }

    m_oREStats.m_uiNumRenderedObjs++;
}
// ----------------------------------------------------------------------------
// Common internal render for both compiled or not compiled meshes
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::RenderMesh_Int(CGBaseMesh* _poMesh, CGShader* _poShader,const CGMatrix4x4& _oMVTransf)
{
    PrepareLights();

    // Premultiply camera matrix by model matrix
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadMatrixf( _oMVTransf.pfGetData() );

/*	float m[16];
    glGetFloatv(GL_MODELVIEW_MATRIX,m);
    CHECKERRORS();
    glLoadMatrixf( m_oCamMatrixStack.oGetTop().m );
    CHECKERRORS();

    glMultMatrixf(m);
 */
    // glMultMatrixf(m_oCamMatrixStack.oGetTop().m);
    // CHECKERRORS();

    if ( _poMesh->eGetType() == E3D_MT_Mesh )
    {
        CGMesh* poMesh = (CGMesh*)_poMesh;

        if ( m_oREState.m_bBVRender ) RenderBV( poMesh->poGetBV() );
        if ( m_oREState.m_bNormalRender ) RenderNormals(poMesh);

        oShaderRenderer.Render(poMesh,_poShader);
    }
    else
    {
        CGCompiledMesh* poMesh = (CGCompiledMesh*)_poMesh;

        if ( m_oREState.m_bBVRender ) RenderBV( poMesh->poGetBV() );
        // if (REState.m_bNormalRender)	RenderNormals(poMesh);

        oShaderRenderer.Render(poMesh,_poShader);
    }

    glPopMatrix();
    CHECKERRORS();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetCurrentMaterial (CGShader* _poShader)
{
    m_poCurrentShader = _poShader;
}
// ----------------------------------------------------------------------------
CGShader* CGOGLWinRenderer::poGetCurrentMaterial ()
{
    return (m_poCurrentShader);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetCurrentTexture (CGTextureObj* TexObj)
{
    if ( !TexObj ) return;
    if ( !TexObj->m_poMipMap ) return;

    if ( !TexObj->m_uiHandler )
    {
        // La textura no ha sido cargada en mem antes
        UploadTexture(TexObj);
        TexObj->Validate();
    }
    else
    {
        if ( !TexObj->bValid() )
        {
            UpdateTexture(TexObj);
            TexObj->Validate();
        }
        else
        {
            // Establecer el/ contexto de la textura
            glBindTexture(GL_TEXTURE_2D,TexObj->m_uiHandler);
            CHECKERRORS();

            if ( TexObj->m_poMipMap->m_eFormat == IF_PALETTE )
            {
                if ( glColorTableEXT )
                {
                    glColorTableEXT(GL_SHARED_TEXTURE_PALETTE_EXT,
                                    GL_RGB,
                                    256,
                                    GL_RGB,
                                    GL_UNSIGNED_BYTE,
                                    TexObj->m_poMipMap->m_pPalette);
                    CHECKERRORS();
                }
            }
        }
    }
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::UpdateTexture (CGTextureObj* TexObj)
{
    uint cLOD;

    glBindTexture(GL_TEXTURE_2D,TexObj->m_uiHandler);

    uint uiTX = TexObj->m_poMipMap->m_uiTX;
    uint uiTY = TexObj->m_poMipMap->m_uiTY;

    for ( cLOD = 0; cLOD < TexObj->m_poMipMap->m_uiNumLODs; cLOD++ )
    {
        // WINGDIAPI void APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
        glTexImage2D    (GL_TEXTURE_2D,
                         cLOD,
                         GetTextureInternalFormat(TexObj->m_poMipMap->m_eFormat),
                         uiTX,
                         uiTY,
                         0,
                         GetTextureFormat(TexObj->m_poMipMap->m_eFormat),
                         GL_UNSIGNED_BYTE,
                         TexObj->m_poMipMap->m_pLOD[cLOD]);
        CHECKERRORS();

        uiTX >>= 1;
        uiTY >>= 1;
    }

    // Setup clut if needed
    if ( TexObj->m_poMipMap->m_eFormat == IF_PALETTE )
    {
        if ( glColorTableEXT )
        {
            glColorTableEXT(GL_SHARED_TEXTURE_PALETTE_EXT,
                            GL_RGB,
                            256,
                            GL_RGB,
                            GL_UNSIGNED_BYTE,
                            TexObj->m_poMipMap->m_pPalette);
            CHECKERRORS();
        }
    }
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::UploadTexture (CGTextureObj* TexObj)
{
    uint cLOD;

    // Generar un handler para la textura
    glGenTextures(1,&TexObj->m_uiHandler);
    CHECKERRORS();

    // Establecer el contexto de la nueva textura
    glBindTexture(GL_TEXTURE_2D,TexObj->m_uiHandler);
    CHECKERRORS();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    uint uiTX = TexObj->m_poMipMap->m_uiTX;
    uint uiTY = TexObj->m_poMipMap->m_uiTY;

    for ( cLOD = 0; cLOD < TexObj->m_poMipMap->m_uiNumLODs; cLOD++ )
    {
        glTexImage2D (GL_TEXTURE_2D,
                      cLOD,
                      GetTextureInternalFormat(TexObj->m_poMipMap->m_eFormat),
                      uiTX,
                      uiTY,
                      0,
                      GetTextureFormat(TexObj->m_poMipMap->m_eFormat),
                      GL_UNSIGNED_BYTE,
                      TexObj->m_poMipMap->m_pLOD[cLOD]);
        CHECKERRORS();

        uiTX >>= 1;
        uiTY >>= 1;
    }

    // Establecer algunas propiedades para este objeto textura
    if ( TexObj->m_uiUWrap == E3D_TEX_WRAP_REPEAT )
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    else
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);

    if ( TexObj->m_uiVWrap == E3D_TEX_WRAP_REPEAT )
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    else
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);

    // Setup mignification filter
    switch ( TexObj->m_uiMinFilter )
    {
        case E3D_TEX_MIN_FILTER_NEAREST:
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        break;

        case E3D_TEX_MIN_FILTER_LINEAR:
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        break;

        case E3D_TEX_MIN_FILTER_NEAREST_MIPMAP_NEAREST:
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST_MIPMAP_NEAREST);
        break;

        case E3D_TEX_MIN_FILTER_NEAREST_MIPMAP_LINEAR:
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST_MIPMAP_LINEAR);
        break;

        case E3D_TEX_MIN_FILTER_LINEAR_MIPMAP_NEAREST:
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
        break;

        case E3D_TEX_MIN_FILTER_LINEAR_MIPMAP_LINEAR:
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
        break;
    }

    // Setup magnification filter
    switch ( TexObj->m_uiMaxFilter )
    {
        case E3D_TEX_MAX_FILTER_NEAREST: glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        break;

        case E3D_TEX_MAX_FILTER_LINEAR:  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        break;
    }

    // Setup clut if needed
    if ( TexObj->m_poMipMap->m_eFormat == IF_PALETTE )
    {
        if ( glColorTableEXT )
        {
            glColorTableEXT(GL_SHARED_TEXTURE_PALETTE_EXT,
                            GL_RGB,
                            256,
                            GL_RGB,
                            GL_UNSIGNED_BYTE,
                            TexObj->m_poMipMap->m_pPalette);
            CHECKERRORS();
        }
    }
}
// ----------------------------------------------------------------------------
bool CGOGLWinRenderer::bUsingBBRender ()
{
    return(m_oREState.m_bBVRender);
}
// ----------------------------------------------------------------------------
bool CGOGLWinRenderer::bUsingDefferredMode ()
{
    return (m_oREState.m_bDefferredMode);
}
// ----------------------------------------------------------------------------
bool CGOGLWinRenderer::bUsingFrustumCulling ()
{
    return(m_oREState.m_bFrustumCulling);
}
// ----------------------------------------------------------------------------
bool CGOGLWinRenderer::bUsingNormalRender ()
{
    return (m_oREState.m_bNormalRender);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetViewport (CGViewport* _Viewport)
{
    if ( !_Viewport ) return;

    m_poViewport = _Viewport;
    m_fAspectRatio = (m_poViewport->ScrTX * m_uiScrTX) / (m_poViewport->ScrTY * m_uiScrTY);

    // -----------!!!!!!!!!--------
    // coordenadas en float (normalizadas) no en int relativas a screen
    // -----------!!!!!!!!!--------

    // Set viewport coordinates
    glViewport(m_poViewport->ScrCX * m_uiScrTX,
               m_poViewport->ScrCY * m_uiScrTY,
               m_poViewport->ScrTX * m_uiScrTX,
               m_poViewport->ScrTY * m_uiScrTY);
    CHECKERRORS();

    glScissor (m_poViewport->ScrCX * m_uiScrTX,
               m_poViewport->ScrCY * m_uiScrTY,
               m_poViewport->ScrTX * m_uiScrTX,
               m_poViewport->ScrTY * m_uiScrTY);
    CHECKERRORS();

    if ( m_poProjector )
    {
        CGMatrix4x4 oMat;
        oMat.LoadIdentity();
        m_oFrustum.Init(oMat,m_poProjector->fFOV,m_poProjector->fFOV * m_fAspectRatio,m_poProjector->fNear,m_poProjector->fFar);
    }
}
// ----------------------------------------------------------------------------
CGViewport* CGOGLWinRenderer::poGetViewport ()
{
    return(m_poViewport);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetCamera (CGCamera* _Camera)
{
    if ( !_Camera ) return;
    m_poCamera = _Camera;

    // Camera matrix
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glLoadIdentity();
    CHECKERRORS();

    gluLookAt(  m_poCamera->oGetPos().x,
                m_poCamera->oGetPos().y,
                m_poCamera->oGetPos().z,
                m_poCamera->oGetPos().x + m_poCamera->oGetDir().x,
                m_poCamera->oGetPos().y + m_poCamera->oGetDir().y,
                m_poCamera->oGetPos().z + m_poCamera->oGetDir().z,
                m_poCamera->oGetUp().x,
                m_poCamera->oGetUp().y,
                m_poCamera->oGetUp().z);
    CHECKERRORS();

    // coger directamente de OpenGL
    CGMatrix4x4 oMat;
    glGetFloatv( GL_MODELVIEW_MATRIX,oMat.pfGetData() );
    m_oCamMatrixStack.Load(oMat);

    // Restore old matrix
    glPopMatrix();
}
// ----------------------------------------------------------------------------
CGCamera* CGOGLWinRenderer::poGetCamera ()
{
    return(m_poCamera);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetProjector (CGProjector* _Projector)
{
    if ( !_Projector ) return;

    m_poProjector = _Projector;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    CHECKERRORS();

    switch ( m_poProjector->ePrjType )
    {
        case E3D_PT_Perspective:
        {
            /*
               glFrustum( -tan(Projector->fFOV*_PI_OVER_180)*fAspectRatio,
                        tan(Projector->fFOV*_PI_OVER_180)*fAspectRatio,
                       -tan(Projector->fFOV*_PI_OVER_180),
                        tan(Projector->fFOV*_PI_OVER_180),
                        Projector->fNear,Projector->fFar);
             */

            gluPerspective(m_poProjector->fFOV,m_fAspectRatio,m_poProjector->fNear,m_poProjector->fFar);
            CHECKERRORS();
        }
        break;

        case E3D_PT_Orthogonal:
        {
            /*
               gluOrtho2D(-0.5f*fAspectRatio,
                        0.5f*fAspectRatio,
                       -0.5f,
                        0.5f);
             */

            /*
               gluOrtho2D(-fAspectRatio,
                        fAspectRatio,
                        1.0f,
                       -1.0f);

             */

            /*
               // DMC: quitado aunque sin comprender muy bien el cometido
               // de este cálculo.
               float fAngle = Projector->fFOV * _PI_OVER_180_;
               float fSeparation = Projector->fNear * fCos(fAngle)/fSin(fAngle);

               glOrtho(-fSeparation*fAspectRatio,
                     fSeparation*fAspectRatio,
                    -fSeparation,
                     fSeparation,
                     Projector->fNear,Projector->fFar);
             */

            glOrtho(-m_fAspectRatio,
                    m_fAspectRatio,
                    -1.0f,
                    1.0f,
                    m_poProjector->fNear,m_poProjector->fFar);

            CHECKERRORS();
        }
        break;
    }

    CGMatrix4x4 oMat;
    oMat.LoadIdentity();
    m_oFrustum.Init(oMat,m_poProjector->fFOV,m_poProjector->fFOV * m_fAspectRatio,m_poProjector->fNear,m_poProjector->fFar);
}
// ----------------------------------------------------------------------------
CGProjector* CGOGLWinRenderer::poGetProjector ()
{
    return(m_poProjector);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetScreenSize (uint _uiScrTX, uint _uiScrTY)
{
    m_uiScrTX = _uiScrTX;
    m_uiScrTY = _uiScrTY;

    SetViewport(m_poViewport);
}
// ----------------------------------------------------------------------------
CGCompiledMesh* CGOGLWinRenderer::poCompileMesh (CGMesh* _poMesh, CGShader* _poShader)
{
    assert  (_poMesh);
    if ( _poMesh->eGetPrimitiveType() == E3D_PT_NONE ) return(NULL);

    CGCompiledMesh* poCGMesh = mNew CGCompiledMesh;
    // Initialize the compiled mesh crating a new display list
    poCGMesh->Init( (handler)glGenLists(1),_poMesh->eGetPrimitiveType(),_poMesh->uiGetNumVXs(),_poMesh->uiGetNumPrims() );

    // DMC REFACT    poCGMesh->poCopyBV( _poMesh->poGetBoundVol() );
    poCGMesh->SetBV(NULL);

    glNewList( (GLuint)poCGMesh->hGetHandler(),GL_COMPILE_AND_EXECUTE );

    // If _poMaterial == NULL, then only the vertexs are compiled the material definition
    oShaderRenderer.Render(_poMesh,_poShader);

    glEndList();

    return(poCGMesh);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::DestroyCompiledMesh (CGCompiledMesh* _poCGMesh)
{
    // List and object will longer no be available
    glDeleteLists( (GLuint)_poCGMesh->hGetHandler(),1 );
    mDel _poCGMesh;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetupPalette (TPixelFormatDescriptor PFD)
{
    int nColors,i;
    TLogPalette* lpPalette;
    unsigned char byRedMask,byGreenMask,byBlueMask;
    HPALETTE Palette;

    nColors = 1 << PFD.cColorBits;

    lpPalette = (TLogPalette*) MEMAlloc( sizeof(TLogPalette) + ( nColors * sizeof(TPaletteEntry) ) );

    lpPalette->palVersion = 0x300;
    lpPalette->palNumEntries = nColors;

    byRedMask = (1 << PFD.cRedBits) - 1;
    byGreenMask = (1 << PFD.cGreenBits) - 1;
    byBlueMask = (1 << PFD.cBlueBits) - 1;

    for ( i = 0; i < nColors; i++ )
    {
        lpPalette->palPalEntry[i].peRed = ( ( (i >> PFD.cRedShift) & byRedMask ) * 255 ) / byRedMask;
        lpPalette->palPalEntry[i].peGreen = ( ( (i >> PFD.cGreenShift) & byGreenMask ) * 255 ) / byGreenMask;
        lpPalette->palPalEntry[i].peBlue = ( ( (i >> PFD.cBlueShift) & byBlueMask ) * 255 ) / byBlueMask;
        lpPalette->palPalEntry[i].peFlags = 0;
    }

    Palette = CreatePalette(lpPalette);

    if ( Palette )
    {
        SelectPalette(DC,Palette,false);
        RealizePalette(DC);
    }

    MEMFree(lpPalette);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::EnableFlatRendering ()
{
    m_oREState.m_bFlatRender = true;

    glDisable   (GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);
    glDisable   (GL_BLEND);

    if ( uiEnabledLights )
        glDisable(GL_LIGHTING);

    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glColor4f(0.5f,0.5f,0.5f,0.0f);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::DisableFlatRendering ()
{
    m_oREState.m_bFlatRender = false;

    glEnable    (GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glEnable    (GL_BLEND);

    if ( uiEnabledLights )
        glEnable(GL_LIGHTING);

    glClearColor(m_oClearColor.r,m_oClearColor.g,m_oClearColor.g,m_oClearColor.a);
    glColor4f(1.0f,1.0f,1.0f,0.0f);
}
// ----------------------------------------------------------------------------
bool CGOGLWinRenderer::bUsingFlatRendering ()
{
    return(m_oREState.m_bFlatRender);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::ReadBuffer (int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData)
{
    switch ( _eBufferType )
    {
        case E3D_RB_Front:
        {
            glReadBuffer(GL_FRONT);
            glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE,_pData);
            return;
        }

        case E3D_RB_Back:
        {
            glReadBuffer(GL_BACK);
            glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE,_pData);
            return;
        }

        case E3D_RB_Z:
        {
            glReadBuffer(GL_DEPTH);
            glReadPixels(_iX,_iY,_iTX,_iTY,GL_DEPTH_COMPONENT,GL_UNSIGNED_INT,_pData);
            return;
        }

        case E3D_RB_Stencil:
        {
            glReadBuffer(GL_STENCIL);
            glReadPixels(_iX,_iY,_iTX,_iTY,GL_STENCIL_INDEX,GL_UNSIGNED_BYTE,_pData);
            return;
        }
    }
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::WriteBuffer (int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData)
{
/*
    void glDrawPixels(
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,

    const GLvoid *pixels)	switch (_eBufferType)
    {
        case E3D_RB_Front:
        {
            glReadBuffer(GL_FRONT);
            glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE);
            return;
        }

        case E3D_RB_Back:
        {
            glReadBuffer(GL_BACK);
            glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE);
            return;
        }
        case E3D_RB_Z:
        {
            glReadBuffer(GL_DEPTH_BUFFER);
            glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE);
            return;
        }

        case E3D_RB_Stencil:
        {
            glReadBuffer(GL_STENCIL_BUFFER);
            glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE);
            return;
        }
    }
 */
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetStencilParams (bool _bEnable, E3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, E3D_StencilAction _eSFails, E3D_StencilAction _eZFails, E3D_StencilAction _eZPass)
{
    E3D_StencilFunc eSFAux;

    // ---------------------------
    // Handle first special cases:
    // ---------------------------

    // Last
    if ( _eStencilFunc == E3D_SF_Last )
    {
        if ( (m_eStencilFunc == E3D_SF_None) && (m_eStencilFuncLast != E3D_SF_None) )
            glEnable(GL_STENCIL_TEST);
        else
        {
            if ( (m_eStencilFunc != E3D_SF_None) && (m_eStencilFuncLast == E3D_SF_None) )
                glDisable(GL_STENCIL_TEST);
        }

        m_eStencilFunc = m_eStencilFuncLast;
        return;
    }

    // Disable
    if ( _eStencilFunc == E3D_SF_None )
    {
        // Disable ?
        if ( m_eStencilFunc != E3D_SF_None )
        {
            m_eStencilFuncLast = m_eStencilFunc;
            m_eStencilFunc = E3D_SF_None;
            glDisable(GL_STENCIL_TEST);
        }

        return;
    }

    // Current
    if ( _eStencilFunc != E3D_SF_Current )
    {
        // Enable function
        if ( m_eStencilFunc == E3D_SF_None ) glEnable(GL_STENCIL_TEST);
        // glFogf (GL_FOG_MODE,eGetFogMode(_eFogMode));
    }

    // Set the stencil function
    glStencilFunc(eGetStencilFunc(_eStencilFunc),_iRefValue,_iMask);

    // Set the stencil operation
    glStencilOp( eGetStencilAct(_eSFails),
                eGetStencilAct(_eZFails),
                eGetStencilAct(_eZPass) );

    m_eStencilFunc = _eStencilFunc;
    m_eStencilFuncLast = m_eStencilFunc;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetZPars (E3D_ZTestFunc _eZTest, E3D_ZWrite _eZWrite)
{
    if ( _eZTest != E3D_ZTF_Current )
    {
        // Disable ?
        if ( _eZTest == E3D_ZTF_None )
        {
            // Is enabled?
            if ( m_eZTest != _eZTest )
            {
                m_eZTestLast = m_eZTest;
                m_eZTest = E3D_ZTF_None;
                glDisable(GL_DEPTH_TEST);
            }
        }
        else
        {
            if ( _eZTest == E3D_ZTF_Last ) _eZTest = m_eZTestLast;

            // Enable function
            if ( m_eZTest == E3D_ZTF_None ) glEnable(GL_DEPTH_TEST);

            // Set pars
            glDepthFunc( eGetDepthFunc(_eZTest) );

            m_eZTest = _eZTest;
            m_eZTestLast = m_eZTest;
        }
    }

    if ( _eZWrite != E3D_ZW_Current )
    {
        // Disable ?
        if ( _eZWrite == E3D_ZW_Disable )
        {
            // Is enabled?
            if ( m_eZWrite == E3D_ZW_Enable )
            {
                m_eZWriteLast = E3D_ZW_Enable;
                m_eZWrite = E3D_ZW_Disable;
                glDepthMask(GL_FALSE);
            }
        }
        else
        if ( _eZWrite == E3D_ZW_Enable )
        {
            // Is disabled?
            if ( m_eZWrite == E3D_ZW_Disable )
            {
                m_eZWriteLast = E3D_ZW_Disable;
                m_eZWrite = E3D_ZW_Enable;
                glDepthMask(GL_TRUE);
            }
        }
        else
        if ( _eZWrite == E3D_ZW_Last )
        {
            // Is disabled?
            m_eZWrite = m_eZWriteLast;

            if ( m_eZWriteLast == E3D_ZW_Enable )
                glDepthMask(GL_TRUE);
            else
                glDepthMask(GL_FALSE);
        }
    }
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::MaskChannels (bool _bR, bool _bG, bool _bB, bool _bA)
{
    glColorMask(_bR,_bG,_bB,_bA);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetFogPars(E3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, CGColor* _poColor)
{
    // ---------------------------
    // Handle first special cases:
    // ---------------------------

    // Last
    if ( _eFogMode == E3D_FM_Last )
    {
        if ( (m_eFogMode == E3D_FM_None) && (m_eFogModeLast != E3D_FM_None) )
            glEnable(GL_FOG);
        else
        {
            if ( (m_eFogMode != E3D_FM_None) && (m_eFogModeLast == E3D_FM_None) )
                glDisable(GL_FOG);
        }

        m_eFogMode = m_eFogModeLast;
        return;
    }

    // Disable
    if ( _eFogMode == E3D_FM_None )
    {
        // Disable ?
        if ( m_eFogMode != E3D_FM_None )
        {
            m_eFogModeLast = m_eFogMode;
            m_eFogMode = E3D_FM_None;
            glDisable(GL_FOG);
        }

        return;
    }

    // Current
    if ( _eFogMode != E3D_FM_Current )
    {
        // Enable function
        if ( m_eFogMode == E3D_FM_None ) glEnable(GL_FOG);
        glFogf ( GL_FOG_MODE,eGetFogMode(_eFogMode) );
    }

    // Set the fog parameters
    glFogf  (GL_FOG_START,_fStart);
    glFogf  (GL_FOG_END,_fEnd);
    glFogf  (GL_FOG_DENSITY,_fDensity);
    glFogfv (GL_FOG_COLOR,(float*)_poColor );

    m_eFogMode = _eFogMode;
    m_eFogModeLast = _eFogMode;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::ClearBuffer(E3D_RenderBuffer_Type _eBuffer)
{
    switch ( _eBuffer )
    {
        case E3D_RB_Front:
        case E3D_RB_Back:       glClear(GL_COLOR_BUFFER_BIT);
        return;

        case E3D_RB_Z:          glClear(GL_DEPTH_BUFFER_BIT);
        return;

        case E3D_RB_Stencil:    glClear(GL_STENCIL_BUFFER_BIT);
        return;

        default:
        return;
    }
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetupLight (int _iLightID, CGLight& _oLight)
{
    switch ( _oLight.m_eType )
    {
        case LT_Point:
        {
            oLPos[_iLightID].x = _oLight.m_oPos.x;
            oLPos[_iLightID].y = _oLight.m_oPos.y;
            oLPos[_iLightID].z = _oLight.m_oPos.z;
            oLPos[_iLightID].w = 1.0f;
        }
        break;

        case LT_Directional:
        {
            oLPos[_iLightID].x = _oLight.m_oDir.x;
            oLPos[_iLightID].y = _oLight.m_oDir.y;
            oLPos[_iLightID].z = _oLight.m_oDir.z;
            oLPos[_iLightID].w = 0.0f;
        }
        break;

        case LT_Spot:
        /*
           glLightf (eLightID, GL_SPOT_CUTOFF			,_oLight.fSpCutOff);
           glLightfv(eLightID, GL_SPOT_DIRECTION		,_oLight.oSpDir.z);
           glLightfv(eLightID, GL_SPOT_EXPONENT		,fPos);
         */
        break;
    }

    GLenum eLightID = eGetLightID(_iLightID);

    // ---------------------------------------
    /*
       glPushMatrix();
       glLoadIdentity();
       glLightfv(eLightID,GL_POSITION,oLPos[_iLightID].V());
       glPopMatrix();
     */
    // ---------------------------------------
    glLightfv(eLightID, GL_AMBIENT,(float*)&_oLight.m_oLitAmb );
    glLightfv(eLightID, GL_DIFFUSE,(float*)&_oLight.m_oLitDiff);
    glLightfv(eLightID, GL_SPECULAR,(float*)&_oLight.m_oLitSpec);

    glLightf (eLightID, GL_CONSTANT_ATTENUATION,_oLight.m_fCAtt);
    glLightf (eLightID, GL_LINEAR_ATTENUATION,_oLight.m_fLAtt);
    glLightf (eLightID, GL_QUADRATIC_ATTENUATION,_oLight.m_fQAtt);
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetLight (int _iLightID, bool _bEnable)
{
    if ( _bEnable )
    {
        uiEnabledLights |= (1 << _iLightID);
    }
    else
    {
        glDisable( eGetLightID(_iLightID) );
        uiEnabledLights &= ~(1 << _iLightID);
    }
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::InvalidateTexture (CGTextureObj* TexObj)
{
    uint cLOD;

    // Generar un handler para la textura
    glDeleteTextures(1,&TexObj->m_uiHandler);
    TexObj->m_uiHandler = 0;
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::PrepareLights()
{
    if ( uiEnabledLights )
    {
        glEnable(GL_LIGHTING);

        for ( int iL = 0; iL < MAX_LIGHTS; iL++ )
        {
            if ( uiEnabledLights & (1 << iL) )
            {
                // Send light position to the GL
                glEnable ( eGetLightID(iL) );
                glLightfv( eGetLightID(iL),GL_POSITION,oLPos[iL].V() );
            }
            else
                glEnable( eGetLightID(iL) );
        }
    }
    else
    {
        glDisable(GL_LIGHTING);
        return;
    }
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::UploadProgram(CGProgram* _poProgram)
{
    char szError[1024];
    GLsizei length;

    _poProgram->m_hProgram = (handler)glCreateProgramObjectARB();
    glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
    CHECKERRORS();

    // Process vertex shader
    if ( _poProgram->m_pucVSData != NULL )
    {
        _poProgram->m_hVS = (handler)glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
        glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
        CHECKERRORS();

        glShaderSourceARB( (GLhandleARB)_poProgram->m_hVS,1,(const GLcharARB* *)&_poProgram->m_pucVSData,NULL );
        glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
        CHECKERRORS();

        glCompileShaderARB( (GLhandleARB)_poProgram->m_hVS );
        glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
        CHECKERRORS();

        glAttachObjectARB( (GLhandleARB)_poProgram->m_hProgram,(GLhandleARB)_poProgram->m_hVS );
        glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
        CHECKERRORS();
    }

    // Process pixel shader
    if ( _poProgram->m_pucPSData != NULL )
    {
        _poProgram->m_hPS = (handler)glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
        glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
        CHECKERRORS();

        glShaderSourceARB( (GLhandleARB)_poProgram->m_hPS,1,(const GLcharARB* *)&_poProgram->m_pucPSData,NULL );
        glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
        CHECKERRORS();

        glCompileShaderARB( (GLhandleARB)_poProgram->m_hPS );
        glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
        CHECKERRORS();

        glAttachObjectARB( (GLhandleARB)_poProgram->m_hProgram,(GLhandleARB)_poProgram->m_hPS );
        glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
        CHECKERRORS();
    }

    // Link the program
    glLinkProgramARB( (GLhandleARB)_poProgram->m_hProgram );

    GLint resul;
    glGetObjectParameterivARB( (GLhandleARB)_poProgram->m_hProgram,GL_OBJECT_LINK_STATUS_ARB,&resul );
    if ( resul != 1 )
    {
        glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
        CHECKERRORS();

        CGErrorLC::I()->Write(szError);
    }

    int my_sampler_uniform_location = glGetUniformLocationARB( (GLhandleARB)_poProgram->m_hProgram, "TMU0Tex" );
    glUniform1iARB(my_sampler_uniform_location, 0);
    CHECKERRORS();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::UpdateProgram(CGProgram* _poProgram)
{
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetCurrentProgram(CGProgram* _poProgram)
{
    if ( glUseProgramObjectARB == NULL ) return;

    if ( _poProgram == NULL )
    {
        glUseProgramObjectARB(0);
        CHECKERRORS();
        return;
    }

    if ( _poProgram->m_hProgram == NULL )
    {
        // El programa no ha sido cargado en mem antes
        UploadProgram(_poProgram);
        _poProgram->Validate();
    }
    else
    {
        if ( !_poProgram->bValid() )
        {
            UpdateProgram(_poProgram);
            _poProgram->Validate();
        }
    }

    glUseProgramObjectARB( (GLhandleARB)_poProgram->m_hProgram );

    char szError[1024];
    GLsizei length;
    glGetInfoLogARB( (GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB*)szError );
    CHECKERRORS();
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::InvalidateProgram(CGProgram* _poProgram)
{
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetProgramParam(CGProgram* _poProgram,const CGString& _sParam,void* _pValue)
{
}
// ----------------------------------------------------------------------------
void CGOGLWinRenderer::SetConstantColor(const CGColor& _oColor)
{
    // Qu� pasa con el alpha? ....
    // glSecondaryColor3fv();

    glMaterialfv( GL_FRONT_AND_BACK,GL_DIFFUSE,_oColor.v() );
}
// ----------------------------------------------------------------------------
