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
#ifdef _MBCS
    #ifdef __BORLANDC__
        #undef _ASSERTE
        #include <vcl.h>
    #else
        #include <windows.h>
    #endif
#else
#endif
// ----------------------------------------------------------------------------
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glext.h>

#include "CGRenderer.h"

// CGOGLShaderRenderer
#include "Drivers\OGL\OGLShaderRender\CGOGLShaderRenderer.h"
// ----------------------------------------------------------------------------
// Our two function pointers.

// DEBUG_CODE
void __stdcall glActiveTextureARB_FACKED(uint)
{
}
void __stdcall glClientActiveTextureARB_FACKED(uint)
{
}
void __stdcall glBlendColor_FACKED(float,float,float,float)
{
}
// ! DEBUG_CODE

PFNGLLOCKARRAYSEXTPROC glLockArraysEXT = NULL;
PFNGLUNLOCKARRAYSEXTPROC glUnlockArraysEXT = NULL;
PFNGLACTIVETEXTUREARBPROC glActiveTextureARB = NULL;
PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB = NULL;
PFNGLBLENDCOLOREXTPROC glBlendColor = NULL;
// ----------------------------------------------------------------------------
#ifndef CHECKERRORS
    #ifdef _DEBUG
static void CHECKERRORS()
{
    int iError;
    do {
        iError = glGetError();
        if ( iError != GL_NO_ERROR )
        {
            int a = 0;
        }
    } while ( iError != GL_NO_ERROR );
}
    #else
        #define CHECKERRORS()
    #endif
#endif
// ----------------------------------------------------------------------------
CGOGLShaderRenderer::CGOGLShaderRenderer() : m_poCurrentBV(NULL), m_poCurrentCGMesh(NULL), m_poCurrentMesh(NULL), m_uiMaxTMUs(1), m_uiCurrentTMU(0), m_bFlushGeometry(false), m_bGeometryFlushed(false)
{
}
// ----------------------------------------------------------------------------
CGOGLShaderRenderer::~CGOGLShaderRenderer()
{
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Init ()
{
    #ifdef WIN32
    glLockArraysEXT = (PFNGLLOCKARRAYSEXTPROC)          wglGetProcAddress("glLockArraysEXT");
    glUnlockArraysEXT = (PFNGLUNLOCKARRAYSEXTPROC)        wglGetProcAddress("glUnlockArraysEXT");
    glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)       wglGetProcAddress("glActiveTextureARB");
    glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC) wglGetProcAddress("glClientActiveTextureARB");
    glBlendColor = (PFNGLBLENDCOLOREXTPROC)          wglGetProcAddress("glBlendColor");

    // DEBUG_CODE
    if ( glActiveTextureARB == NULL ) glActiveTextureARB = glActiveTextureARB_FACKED;
    if ( glClientActiveTextureARB == NULL ) glClientActiveTextureARB = glClientActiveTextureARB_FACKED;
    if ( glBlendColor == NULL ) glBlendColor = glBlendColor_FACKED;
    // ! DEBUG_CODE

    #endif
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render_ShInsProgram(CGShInsProgram* _poTI)
{
    CGRenderer::I()->SetCurrentProgram( _poTI->poGetProgram() );
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render_ShInsTexture (CGShInsTexture* _poTI)
{
    // Enable texturing for current TMU
    glEnable(GL_TEXTURE_2D);

    m_uiCurrentTMU++;
    if ( m_uiCurrentTMU == m_uiMaxTMUs ) m_bFlushGeometry = true;

    CGRenderer::I()->SetCurrentTexture(_poTI->m_poTex);
    Render_Geometry();
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render_ShInsColor (CGShInsColor* _poTI)
{
    // Disable texturing for current TMU
    glDisable(GL_TEXTURE_2D);

    m_uiCurrentTMU++;
    if ( m_uiCurrentTMU == m_uiMaxTMUs ) m_bFlushGeometry = true;

    CGRenderer::I()->SetConstantColor( _poTI->oGetColor() );

    glBlendColor( _poTI->oGetColor().r, _poTI->oGetColor().g,_poTI->oGetColor().b,_poTI->oGetColor().a);
    glBlendFunc(GL_CONSTANT_ALPHA,GL_ONE_MINUS_CONSTANT_ALPHA);

    Render_Geometry();
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render_ShInsWireframe (CGShInsWireframe* _poTI)
{
    // Set polygon mode
    glPolygonMode(GL_BACK,GL_LINE);
    glPolygonMode(GL_FRONT,GL_LINE);

    // Disable texturing for current TMU
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_CULL_FACE);

    m_uiCurrentTMU++;
    if ( m_uiCurrentTMU == m_uiMaxTMUs ) m_bFlushGeometry = true;

    CGRenderer::I()->SetConstantColor( _poTI->oGetColor() );

    glBlendColor( _poTI->oGetColor().r,_poTI->oGetColor().g,_poTI->oGetColor().b,_poTI->oGetColor().a);
    glBlendFunc(GL_CONSTANT_ALPHA,GL_ONE_MINUS_CONSTANT_ALPHA); // ??? Siempre deberia ir aqui???

    Render_Geometry();

    // Restore polygon mode
    glPolygonMode(GL_BACK,GL_FILL);
    glPolygonMode(GL_FRONT,GL_FILL);
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render_ShInsExtension (CGShInsExtension* _poTI)
{
    m_uiCurrentTMU++;
    if ( m_uiCurrentTMU == m_uiMaxTMUs ) m_bFlushGeometry = true;

    _poTI->pFunction() ( (void*)&m_poCurrentMesh );
    Render_Geometry();
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render_ShInsGeoOp (CGShInsGeoOp* _poTI)
{
    float fValue;

    if ( _poTI->poGetEvaluator() )
        fValue = _poTI->poGetEvaluator()->fGetValue();
    else
        fValue = 0.0f;

    glMatrixMode(GL_MODELVIEW);
    switch ( _poTI->eGetGOpType() )
    {
        case eSIGeoOp_RotateX:
        glRotatef(fValue,1.0f,0.0f,0.0f);
        break;

        case eSIGeoOp_RotateY:
        glRotatef(fValue,0.0f,1.0f,0.0f);
        break;

        case eSIGeoOp_RotateZ:
        glRotatef(fValue,0.0f,0.0f,1.0f);
        break;

        case eSIGeoOp_Scale:
        glScalef (fValue,fValue,fValue);
        break;

        case eSIGeoOp_ScaleX:
        glScalef (fValue,1.0f,1.0f);
        break;

        case eSIGeoOp_ScaleY:
        glScalef (1.0f,fValue,1.0f);
        break;

        case eSIGeoOp_ScaleZ:
        glScalef (1.0f,1.0f,fValue);
        break;

        case eSIGeoOp_TransX:
        glTranslatef(fValue,0.0f,0.0f);
        break;

        case eSIGeoOp_TransY:
        glTranslatef(0.0f,fValue,0.0f);
        break;

        case eSIGeoOp_TransZ:
        glTranslatef(0.0f,0.0f,fValue);
        break;
    }
    CHECKERRORS();
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render_ShInsTexOp (CGShInsTexOp* _poTI)
{
    float fValue;

    if ( _poTI->poGetEvaluator() )
        fValue = _poTI->poGetEvaluator()->fGetValue();
    else
        fValue = 0.0f;

    glMatrixMode(GL_TEXTURE);
    switch ( _poTI->eGetTOpType() )
    {
        case eSITexOp_Rotate:
        glRotatef(fValue,0.0f,0.0f,1.0f);

        break;

        case eSITexOp_Scale:
        glScalef (fValue,fValue,1.0f);
        break;

        case eSITexOp_ScaleU:
        glScalef (fValue,1.0f,1.0f);
        break;

        case eSITexOp_ScaleV:
        glScalef (1.0f,fValue,1.0f);
        break;

        case eSITexOp_TransU:
        glTranslatef(fValue,0.0f,0.0f);
        break;

        case eSITexOp_TransV:
        glTranslatef(0.0f,fValue,0.0f);
        break;

        case eSITexOp_ReflectMap:
        glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);

        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        break;

        case eSITexOp_EnvMap:
        /*
           // DMC REFACT
           float fX;
           float fY;
           fX = poCurrentBV->GetRange(0);
           fY = poCurrentBV->GetRange(1);
           if ( fX ) fX = 0.5f / fX;
           if ( fY ) fY = 0.5f / fY;
           glScalef(fX,fY,1.0f);

           glEnable(GL_TEXTURE_GEN_S);
           glEnable(GL_TEXTURE_GEN_T);

           glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_EYE_LINEAR);
           glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_EYE_LINEAR);
         */
        break;

        case eSITexOp_Matrix:
        glMultMatrixf( _poTI->m_poMat->pfGetData() );
        break;

        case eSITexOp_FrameSet:
        int iFrame;
        int iXFrame;
        int iYFrame;
        int iTotalFrames;
        float fSPF;
        float fXStep;
        float fYStep;

        fXStep = 1.0f / _poTI->m_uiImgCols;
        fYStep = 1.0f / _poTI->m_uiImgRows;

        iTotalFrames = _poTI->m_uiImgCols * _poTI->m_uiImgRows;
        fSPF = 1.0f / (iTotalFrames * _poTI->m_fFreq);

        iFrame = (int)(CGRenderer::I()->oGetStats().m_fTotalTime / fSPF) % iTotalFrames;
        iYFrame = iFrame / _poTI->m_uiImgCols;
        iXFrame = iFrame - (iYFrame * _poTI->m_uiImgCols);

        glTranslatef(iXFrame * fXStep,iYFrame * fYStep,0.0f);
        glScalef(fXStep,fYStep,1.0f);
        break;
    }
    CHECKERRORS();
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render_ShInsBlendOp (CGShInsBlendOp* _poTI)
{
    m_bGeometryFlushed = false;

    // <WARNING: DEBUG CODE>
    glDisable  (GL_CULL_FACE);
    m_bEnableCF = true;

    switch ( _poTI->eGetBlendMode() )
    {
        // ------------------
        // Blending ops
        // ------------------
        case E3D_BM_Copy:
        {
            glBlendFunc(GL_ONE,GL_ZERO);
            glEnable   (GL_CULL_FACE);
            m_bEnableCF = false;
        }
        break;

        case E3D_BM_Mult:
        glBlendFunc(GL_DST_COLOR,GL_ZERO);
        break;

        case E3D_BM_Mult2x:
        glBlendFunc(GL_DST_COLOR,GL_SRC_COLOR);
        break;

        case E3D_BM_Add:
        glBlendFunc(GL_ONE,GL_ONE);
        break;

        case E3D_BM_AddAndMult:
        glBlendFunc(GL_DST_COLOR,GL_ONE);
        break;

        case E3D_BM_MultAndAdd:
        glBlendFunc(GL_ONE,GL_SRC_COLOR);
        break;

        case E3D_BM_Alpha:
        {
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable   (GL_ALPHA_TEST);
            m_bDisableAT = true;
        }
        break;

        case E3D_BM_AlphaAdd:
        {
            glBlendFunc(GL_SRC_ALPHA, GL_ONE);
            glEnable   (GL_ALPHA_TEST);
            m_bDisableAT = true;
        }
        break;

        case E3D_BM_AlphaInv:
        {
            glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_SRC_ALPHA);
            glEnable   (GL_ALPHA_TEST);
            m_bDisableAT = true;
        }
        break;

        case E3D_BM_AlphaThrough:    // Useful for dummy management
        {
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable   (GL_ALPHA_TEST);
            m_bDisableAT = true;
        }

        break;
    }
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render_ShInsZOp (CGShInsZOp* _poTI)
{
    CGRenderer::I()->SetZPars( _poTI->eGetZTestFunc(), _poTI->eGetZWrite() );
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render_Geometry ()
{
    // WARNING DEBUG CODE
    glDisable(GL_CULL_FACE);

    if ( m_bFlushGeometry )
    {
        switch ( m_eMeshType )
        {
            case E3D_MT_Mesh:
            RenderMesh(m_poCurrentMesh);
            break;

            case E3D_MT_CompiledMesh:
            RenderCompiledMesh(m_poCurrentCGMesh);
            break;
        }

        m_uiCurrentTMU = 0;
        m_bGeometryFlushed = true;
    }

    // Current texture unit
    InitTMU(m_uiCurrentTMU);

    // Reset the program to fixed function
    CGRenderer::I()->SetCurrentProgram(NULL);
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::InitTMU (uint _uiTMU)
{
    // First set current TMU
    switch ( m_uiCurrentTMU )
    {
        case 0:
        glActiveTextureARB(GL_TEXTURE0_ARB);
        glClientActiveTextureARB(GL_TEXTURE0_ARB);
        break;

        case 1:
        glActiveTextureARB(GL_TEXTURE1_ARB);
        glClientActiveTextureARB(GL_TEXTURE1_ARB);
        break;

        case 2:
        glActiveTextureARB(GL_TEXTURE2_ARB);
        glClientActiveTextureARB(GL_TEXTURE2_ARB);
        break;

        case 3:
        glActiveTextureARB(GL_TEXTURE3_ARB);
        glClientActiveTextureARB(GL_TEXTURE3_ARB);
        break;
        // ..
    }

    if ( m_bDisableAT )
    {
        glDisable(GL_ALPHA_TEST);
        m_bDisableAT = false;
    }

    if ( m_bEnableCF )
    {
        // <WARNING: DEBUG CODE>
        // glDisable (GL_CULL_FACE);	// DEBUG
        glEnable    (GL_CULL_FACE);
        glDepthFunc (GL_LEQUAL);
        glDepthMask (GL_TRUE);
        m_bEnableCF = false;
    }

// Enable texturing for this texture unit
    glEnable(GL_TEXTURE_2D);

// Reset texture matrix
    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
    CHECKERRORS();

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);

// Setup default blending mode
    glBlendFunc(GL_ONE,GL_ZERO);

// Set previous z pars
    CGRenderer::I()->SetZPars(E3D_ZTF_Last, E3D_ZW_Last);
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::BeginShaderRender ()
{
    InitTMU(0);

    // glDisable (GL_CULL_FACE);	// DEBUG
    glEnable (GL_CULL_FACE);

    /*
       glActiveTextureARB(GL_TEXTURE0_ARB);
       glDisable(GL_TEXTURE_2D);

       glActiveTextureARB(GL_TEXTURE1_ARB);
       glDisable(GL_TEXTURE_2D);

       glActiveTextureARB(GL_TEXTURE2_ARB);
       glDisable(GL_TEXTURE_2D);

       glActiveTextureARB(GL_TEXTURE3_ARB);
       glDisable(GL_TEXTURE_2D);
     */

    // OPTIMIZATION: glLockArrays Util cuando varias pasadas sobre el mismo objeto!
    // We are telling OGL that from this point, we will not perform any modification
    // in the vertex buffers
    // glLockArraysEXT(0,CurrentMesh->usNumVerts);
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::EndShaderRender ()
{
    // Unlock the arrays
    // glUnlockArraysEXT();
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::RenderShader (CGShader* _poShader)
{
    if ( !_poShader ) return;

    CGShaderInstruction* poShIns;
    for ( int iIns = 0; iIns < _poShader->iGetNumInstructions(); iIns++ )
    {
        poShIns = _poShader->pGetInstruction(iIns);

        if ( poShIns )
        {
            switch ( poShIns->eGetInstructionType() )
            {
                case E3D_SHI_Program:
                if ( !CGRenderer::I()->oGetState().m_bFlatRender )
                    Render_ShInsProgram( (CGShInsProgram*)poShIns );
                else
                {
                    m_bFlushGeometry = true;
                    Render_Geometry();
                }
                break;

                case E3D_SHI_Texture:
                if ( !CGRenderer::I()->oGetState().m_bFlatRender )
                    Render_ShInsTexture( (CGShInsTexture*)poShIns );
                else
                {
                    m_bFlushGeometry = true;
                    Render_Geometry();
                }
                break;

                case E3D_SHI_Color:
                if ( !CGRenderer::I()->oGetState().m_bFlatRender )
                    Render_ShInsColor( (CGShInsColor*)poShIns );
                else
                {
                    m_bFlushGeometry = true;
                    Render_Geometry();
                }
                break;

                case E3D_SHI_Wireframe:
                if ( !CGRenderer::I()->oGetState().m_bFlatRender )
                    Render_ShInsWireframe( (CGShInsWireframe*)poShIns );
                else
                {
                    m_bFlushGeometry = true;
                    Render_Geometry();
                }
                break;

                case E3D_SHI_Extension:
                if ( !CGRenderer::I()->oGetState().m_bFlatRender )
                    Render_ShInsExtension( (CGShInsExtension*)poShIns );
                else
                {
                    m_bFlushGeometry = true;
                    Render_Geometry();
                }
                break;

                case E3D_SHI_GeoOp:
                Render_ShInsGeoOp( (CGShInsGeoOp*)poShIns );
                break;

                case E3D_SHI_TexOp:
                if ( !CGRenderer::I()->oGetState().m_bFlatRender )
                    Render_ShInsTexOp( (CGShInsTexOp*)poShIns );
                break;

                case E3D_SHI_BlendOp:
                if ( !CGRenderer::I()->oGetState().m_bFlatRender )
                    Render_ShInsBlendOp( (CGShInsBlendOp*)poShIns );
                break;

                case E3D_SHI_ZOp:
                Render_ShInsZOp( (CGShInsZOp*)poShIns );
                break;

                case E3D_SHI_SetTMU:
                break;
            }
        }
    }
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render (CGMesh* _poMesh, CGShader* _poShader)
{
    assert (_poMesh && "NULL Mesh operand");

    m_eMeshType = E3D_MT_Mesh;
    m_poCurrentMesh = _poMesh;
    m_poCurrentBV = _poMesh->poGetBV();

    if ( _poShader )
    {
        BeginShaderRender();
        RenderShader(_poShader);
        EndShaderRender();
    }
    else
    {
        // Only process geometric data
        RenderMesh(_poMesh);
    }
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::Render (CGCompiledMesh* _poCGMesh, CGShader* _poShader)
{
    assert (_poCGMesh && "NULL Mesh operand");

    m_eMeshType = E3D_MT_CompiledMesh;
    m_poCurrentCGMesh = _poCGMesh;
    m_poCurrentBV = _poCGMesh->poGetBV();

    if ( _poShader )
    {
        BeginShaderRender();
        RenderShader(_poShader);
        EndShaderRender();
    }
    else
        RenderCompiledMesh(_poCGMesh);
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::RenderMesh (CGMesh* _poMesh)
{
    // Setup color array. If any
    CHECKERRORS();

    uint uiTris = 0;

    if ( CGRenderer::I()->oGetState().m_bFlatRender )
    {
        /*
           if ((_poMesh->VCs) && !(CGRenderer::I()->REState.m_bFlatRender))
           {
            glEnableClientState(GL_COLOR_ARRAY);
            glColorPointer(4,GL_FLOAT,0,_poMesh->VCs);
           }
           else
         */
        glDisableClientState(GL_COLOR_ARRAY);

        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
    }
    else
    {
        if ( _poMesh->m_poVC )
        {
            glEnableClientState(GL_COLOR_ARRAY);
            glColorPointer(4,GL_FLOAT,0,_poMesh->m_poVC);
        }
        else
        {
            glDisableClientState(GL_COLOR_ARRAY);
        }

        // Setup texcoord array. If any
        if ( _poMesh->m_poUV )
        {
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            // <WARNING!!!>
            // Special case (if _poMesh->UVs == _poMesh->VXs)

            if ( (void*)_poMesh->m_poUV == (void*)_poMesh->m_poVX )
                glTexCoordPointer(3,GL_FLOAT,0,_poMesh->m_poUV);
            else
                glTexCoordPointer(2,GL_FLOAT,0,_poMesh->m_poUV);
        }
        else
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        // Setup second texcoord array. if multitexture
        if ( _poMesh->m_poUV )
        {
            glActiveTextureARB  (GL_TEXTURE1_ARB);
            glEnableClientState (GL_TEXTURE_COORD_ARRAY);

            // <WARNING!!!>
            // Special case (if _poMesh->UVs == _poMesh->VXs)
            if ( (void*)_poMesh->m_poUV == (void*)_poMesh->m_poVX )
                glTexCoordPointer(3,GL_FLOAT,0,_poMesh->m_poUV);
            else
                glTexCoordPointer(2,GL_FLOAT,0,_poMesh->m_poUV);

            glActiveTextureARB  (GL_TEXTURE0_ARB);
        }

        // Setup normal array. If any
        if ( _poMesh->m_poVN )
        {
            glEnableClientState(GL_NORMAL_ARRAY);
            glNormalPointer    (GL_FLOAT,0,_poMesh->m_poVN);
        }
        else
            glDisableClientState(GL_NORMAL_ARRAY);
    }

    // Setup vertex array. Always != null.
    glVertexPointer(3,GL_FLOAT,0,_poMesh->m_poVX);

    switch ( m_poCurrentMesh->eGetPrimitiveType() )
    {
        case E3D_PT_NONE:
        return;
        break;

        case E3D_PT_TRIS:          // Draw the elements
        uiTris = _poMesh->uiGetNumPrims();
        glDrawElements (GL_TRIANGLES,_poMesh->uiGetNumIndices(),GL_UNSIGNED_SHORT,(void*)_poMesh->m_pusIdx);
        break;

        case E3D_PT_QUADS:
        uiTris = _poMesh->uiGetNumPrims() * 2;
        glDrawElements (GL_QUADS,_poMesh->uiGetNumIndices(),GL_UNSIGNED_SHORT,(void*)_poMesh->m_pusIdx);
        break;

        case E3D_PT_TRIFANS:
        uiTris = _poMesh->uiGetNumPrims();
        glDrawElements (GL_TRIANGLE_FAN,_poMesh->uiGetNumIndices(), GL_UNSIGNED_SHORT, (void*)_poMesh->m_pusIdx);
        break;

        case E3D_PT_TRISTRIPS:
        uiTris = _poMesh->uiGetNumPrims();
        glDrawElements (GL_TRIANGLE_STRIP,_poMesh->uiGetNumIndices(),GL_UNSIGNED_SHORT,(void*)_poMesh->m_pusIdx);
        break;

        case E3D_PT_QUADSTRIPS:
        uiTris = _poMesh->uiGetNumPrims() * 2;
        glDrawElements (GL_QUAD_STRIP,_poMesh->uiGetNumIndices(),GL_UNSIGNED_SHORT,(void*)_poMesh->m_pusIdx);
        break;

        case E3D_PT_NITRIS:
        uiTris = _poMesh->uiGetNumPrims();
        glDrawArrays   (GL_TRIANGLES,0,_poMesh->uiGetNumPrims() * 3);
        break;

        case E3D_PT_NIQUADS:
        uiTris = _poMesh->uiGetNumPrims() * 2;
        glDrawArrays   (GL_QUADS,0,_poMesh->uiGetNumPrims() * 4);
        break;

        case E3D_PT_NITRISTRIP:
        uiTris = _poMesh->uiGetNumPrims();
        glDrawArrays   (GL_TRIANGLE_STRIP,0,_poMesh->uiGetNumPrims() + 2);
        break;
    }

    CGRenderer::I()->oGetStats().m_uiNumRenderedTris += uiTris;
    CGRenderer::I()->oGetStats().m_uiNumRenderedVerts += _poMesh->uiGetNumVXs();

    CHECKERRORS();
}
// ----------------------------------------------------------------------------
void CGOGLShaderRenderer::RenderCompiledMesh (CGCompiledMesh* _poCGMesh)
{
    glCallList( (GLuint)m_poCurrentCGMesh->hGetHandler() );

    CGRenderer::I()->oGetStats().m_uiNumRenderedTris += m_poCurrentCGMesh->uiGetNumPrims();
    CGRenderer::I()->oGetStats().m_uiNumRenderedVerts += m_poCurrentCGMesh->uiGetNumVXs();
}
// ----------------------------------------------------------------------------
