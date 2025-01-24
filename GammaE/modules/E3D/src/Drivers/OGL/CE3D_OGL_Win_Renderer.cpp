// ----------------------------------------------------------------------------
#include "GammaE_Mem.h"
#include "GammaE_Misc.h"

#include "CE3D_OGL_Win_Renderer.h"

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glext.h>

#include "RenderVars/CE3D_RenderVars.h"

// The format of the functions we're gonna get hold of.
typedef void (APIENTRY *PFNGLCOLORTABLEEXT)(int, int, int, int, int, const void * );
PFNGLSECONDARYCOLOR3FVPROC								glSecondaryColor3fv = NULL;

//Our function pointers.
PFNGLCOLORTABLEEXT										glColorTableEXT;

PFNGLCREATEPROGRAMOBJECTARBPROC                         glCreateProgramObjectARB = NULL;
PFNGLCREATESHADEROBJECTARBPROC                          glCreateShaderObjectARB = NULL;
PFNGLSHADERSOURCEARBPROC                                glShaderSourceARB = NULL;
PFNGLCOMPILESHADERARBPROC                               glCompileShaderARB = NULL;
PFNGLGETOBJECTPARAMETERIVARBPROC                        glGetObjectParameterivARB = NULL;
PFNGLATTACHOBJECTARBPROC                                glAttachObjectARB = NULL;
PFNGLGETINFOLOGARBPROC                                  glGetInfoLogARB = NULL;
PFNGLLINKPROGRAMARBPROC                                 glLinkProgramARB = NULL;
PFNGLUSEPROGRAMOBJECTARBPROC                            glUseProgramObjectARB = NULL;
PFNGLGETUNIFORMLOCATIONARBPROC                          glGetUniformLocationARB = NULL;
PFNGLUNIFORM1FARBPROC                                   glUniform1fARB = NULL;
PFNGLUNIFORM1IARBPROC                                   glUniform1iARB = NULL;

// CE3D_OGL_Win_Renderer
#include "Drivers\OGL\CE3D_OGL_Win_Renderer.h"
#include "CE3D_OGL_MatrixStack.h"

CE3D_OGL_MatrixStack m_oCamMatrixStack;
CE3D_OGL_MatrixStack m_oWorldMatrixStack;
static CGColor m_oClearColor(0.25,0.25,0.25,1.0f);
//-----------------------------------------------------------------------------
unsigned int GetTextureFormat(EImageFormat PixelFormat)
{
    switch (PixelFormat)
    {
		case IF_RGBA:return(GL_RGBA);
        case IF_RGB: return(GL_RGB);
        // case TEX_PF_GRAY8: return(GL_LUMINANCE);
		case IF_PALETTE:return(GL_COLOR_INDEX);
			
		default:
				return(GL_RGBA);
	}
}
//-----------------------------------------------------------------------------
unsigned int GetTextureInternalFormat(EImageFormat PixelFormat)
{
     switch (PixelFormat)
    {
        case IF_RGBA:return(GL_RGBA8);
        case IF_RGB: return(GL_RGB8);
        // case TEX_PF_GRAY8: return(GL_LUMINANCE);
		case IF_PALETTE:return(GL_COLOR_INDEX8_EXT);
		
		default:
				return(0);
	}
}
//-----------------------------------------------------------------------------
GLenum eGetStencilAct(E3D_StencilAction _eSA)
{
	switch (_eSA)
	{
		case E3D_SA_None:	return(GL_KEEP);
		case E3D_SA_Keep:	return(GL_KEEP);
		case E3D_SA_Zero:	return(GL_ZERO);
		case E3D_SA_Inc:	return(GL_INCR);
		case E3D_SA_Dec:	return(GL_DECR);
		case E3D_SA_Inv:	return(GL_INVERT);
		default:
				return(GL_KEEP);
	}
}
// -----------------------------------------------------------------------------
GLenum eGetStencilFunc(E3D_StencilFunc _eSF)
{
	switch (_eSF)
	{
		case E3D_SF_None:		return(GL_ALWAYS);
		case E3D_SF_Never:		return(GL_NEVER);
		case E3D_SF_Less:		return(GL_LESS);
		case E3D_SF_LEqual:	return(GL_LEQUAL);
		case E3D_SF_Greater:	return(GL_GREATER);
		case E3D_SF_GEqual:	return(GL_GEQUAL);
		case E3D_SF_Equal:		return(GL_EQUAL);
		case E3D_SF_NotEqual:	return(GL_NOTEQUAL);
		case E3D_SF_Always:	return(GL_ALWAYS);
		default:
				return(GL_ALWAYS);
	}
}
// -----------------------------------------------------------------------------
GLenum eGetFogMode(E3D_FogMode _eFM)
{
	switch (_eFM)
	{
		case E3D_FM_None:	return(GL_LINEAR);
		case E3D_FM_Linear:	return(GL_LINEAR);
		case E3D_FM_Exp:	return(GL_EXP);
		case E3D_FM_Exp2:	return(GL_EXP2);
		default:
				return(GL_LINEAR);
	}
}
// -----------------------------------------------------------------------------
GLenum eGetDepthFunc(E3D_ZTestFunc _ZT)
{
	switch (_ZT)
	{
		case E3D_ZTF_None:		return(GL_ALWAYS);
		case E3D_ZTF_Never:		return(GL_NEVER);
		case E3D_ZTF_Less:		return(GL_LESS);
		case E3D_ZTF_LEqual:	return(GL_LEQUAL);
		case E3D_ZTF_Greater:	return(GL_GREATER);
		case E3D_ZTF_GEqual:	return(GL_GEQUAL);
		case E3D_ZTF_Equal:		return(GL_EQUAL);
		case E3D_ZTF_NotEqual:	return(GL_NOTEQUAL);
		case E3D_ZTF_Always:	return(GL_ALWAYS);
		default:
				return(GL_ALWAYS);
	}
}
// -----------------------------------------------------------------------------
GLenum eGetLightID(int _iLightID)
{
	return(GL_LIGHT0 + _iLightID);
}
// -----------------------------------------------------------------------------
// For Lighting
#define		 MAX_LIGHTS	 8
CVect4		 oLPos	 [MAX_LIGHTS];
unsigned int uiEnabledLights = 0;
// -----------------------------------------------------------------------------
#ifdef _DEBUG
static int s_iLastError = 0;
static int s_iError     = 0;

static void CHECKERRORS()
{
	s_iLastError = 0;

	do{
		s_iError = glGetError();

		if (s_iError != GL_NO_ERROR)
		{
			s_iLastError = s_iError;
		}

	}while (s_iError != GL_NO_ERROR);
}
#else
#define CHECKERRORS()
#endif

//#define _DEBUG_WIREFRAME
//-----------------------------------------------------------------------------
CE3D_OGL_Win_Renderer::CE3D_OGL_Win_Renderer()
{  
	// Setup NULL color
	CE3D_ShIns_Color *poColor = mNew CE3D_ShIns_Color;
	poColor->SetColor( CGColor(1.0f,0.0f,0.0f,0.5f) );
    E3D_NULL_SHADER.AddInstruction(poColor);

	//-----------------------------------------------------------------------------
	// Create and initialize engine associated objects
	//-----------------------------------------------------------------------------
	REStats.cDTime   = 0;
	REStats.DTimes[0]= REStats.DTimes[1] = REStats.DTimes[2] = REStats.DTimes[3] = 1;
	REStats.FPS      = 1.0f;
	REStats.DTime    = 0.0f;
}
// -----------------------------------------------------------------------------
CE3D_OGL_Win_Renderer::~CE3D_OGL_Win_Renderer()
{
  	Finish();
}
// -----------------------------------------------------------------------------
int CE3D_OGL_Win_Renderer::Init (handler _pHndDeviceContext, int _iOptions, int _iScrTX, int _iScrTY, int _iColorBits)
{
  	//-----------------------------------------------------------------------------
	// Begin Windows specific
	//-----------------------------------------------------------------------------
		#define OP_SetOption(variable,option) variable |= option
		#define OP_IsOption(variable,option) (variable & option)

		TPixelFormatDescriptor PFDescriptor;
		int PixelFormat;

		// Set the OpenGL properties required to draw to the given canvas and
		// create a rendering context for it.
		WND = (HWND) _pHndDeviceContext;
		DC = GetDC(WND);
		
		memset((void *)&PFDescriptor,0,sizeof(TPixelFormatDescriptor));

		PFDescriptor.nSize     = sizeof(TPixelFormatDescriptor);
		PFDescriptor.nVersion  = 1;
		PFDescriptor.dwFlags   = PFD_SUPPORT_OPENGL;

		if (GetObjectType(DC) == OBJ_MEMDC)
    		OP_SetOption(PFDescriptor.dwFlags,PFD_DRAW_TO_BITMAP);
		else
    		OP_SetOption(PFDescriptor.dwFlags,PFD_DRAW_TO_WINDOW);

		if (OP_IsOption(_iOptions,E3D_RENDERER_OP_DBUFFER)) OP_SetOption(PFDescriptor.dwFlags,PFD_DOUBLEBUFFER);
		if (OP_IsOption(_iOptions,E3D_RENDERER_OP_GDI    )) OP_SetOption(PFDescriptor.dwFlags,PFD_SUPPORT_GDI );
		if (OP_IsOption(_iOptions,E3D_RENDERER_OP_STEREO )) OP_SetOption(PFDescriptor.dwFlags,PFD_STEREO      );
		
		PFDescriptor.iPixelType   = PFD_TYPE_RGBA;
		PFDescriptor.cColorBits   = _iColorBits;
		PFDescriptor.cDepthBits   = 24;
		PFDescriptor.cStencilBits = 8;
		// PFDescriptor.iLayerType   = unsigned char (PFD_MAIN_PLANE);

		// just in case it didn't happen already
		PixelFormat = ChoosePixelFormat(DC,&PFDescriptor);
		if (! PixelFormat)
		{
			MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
			exit(1);
		}

		// Attempt to set the pixel format
		if (! SetPixelFormat(DC,PixelFormat,&PFDescriptor))
		{
			MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
			exit(1);
		}

  		// check the properties just set
		DescribePixelFormat(DC,PixelFormat,sizeof(TPixelFormatDescriptor),&PFDescriptor);
	
  		if (OP_IsOption(PFDescriptor.dwFlags,PFD_NEED_PALETTE)) SetupPalette(PFDescriptor);

		GLRC = wglCreateContext(DC);

 		// read implementation properties
		wglMakeCurrent(DC,GLRC);

	//-----------------------------------------------------------------------------
	// End Windows specific
	//-----------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// Setup openGL default state
	//-----------------------------------------------------------------------------
	iScrTX = _iScrTX;
	iScrTY = _iScrTY;
	   
	// Frame buffer clear color
	glClearColor(m_oClearColor.r,m_oClearColor.g,m_oClearColor.g,m_oClearColor.a);
    
	// Render buffer
    glDrawBuffer(GL_BACK);	

	//Stencil clear value
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
	glPolygonMode(GL_BACK ,GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK ,GL_FILL);
	#ifdef _DEBUG_WIREFRAME
	glPolygonMode(GL_FRONT_AND_BACK ,GL_LINE);
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
	
	GLfloat mat_specular[4]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat	global_amb[4]    = { 1.0f, 1.0f, 1.0f, 1.0f };

	glMaterialfv	(GL_FRONT, GL_SPECULAR,  mat_specular);
	glMaterialfv	(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightModelfv	(GL_LIGHT_MODEL_AMBIENT,global_amb);

	glColor4f(1,1,1,0);
	glHint      (GL_FOG_HINT,GL_DONT_CARE);

	// -------------------------------------
	// Enable paletted textures
	// -------------------------------------
	glColorTableEXT = (PFNGLCOLORTABLEEXT)wglGetProcAddress("glColorTableEXT");
	if (glColorTableEXT)
	{
		glEnable(GL_SHARED_TEXTURE_PALETTE_EXT);
	}
	else
	{
		// DMC: error / warning
	}

	glUseProgramObjectARB		= (PFNGLUSEPROGRAMOBJECTARBPROC)	wglGetProcAddress("glUseProgramObjectARB");
	glCreateProgramObjectARB	= (PFNGLCREATEPROGRAMOBJECTARBPROC)	wglGetProcAddress("glCreateProgramObjectARB");
	glShaderSourceARB			= (PFNGLSHADERSOURCEARBPROC)		wglGetProcAddress("glShaderSourceARB");
	glCreateShaderObjectARB		= (PFNGLCREATESHADEROBJECTARBPROC)	wglGetProcAddress("glCreateShaderObjectARB");
	glCompileShaderARB			= (PFNGLCOMPILESHADERARBPROC)		wglGetProcAddress("glCompileShaderARB");
	glGetObjectParameterivARB	= (PFNGLGETOBJECTPARAMETERIVARBPROC)wglGetProcAddress("glGetObjectParameterivARB");
	glAttachObjectARB			= (PFNGLATTACHOBJECTARBPROC)		wglGetProcAddress("glAttachObjectARB");
	glLinkProgramARB			= (PFNGLLINKPROGRAMARBPROC)			wglGetProcAddress("glLinkProgramARB");
	glGetInfoLogARB				= (PFNGLGETINFOLOGARBPROC)			wglGetProcAddress("glGetInfoLogARB");
	glGetUniformLocationARB		= (PFNGLGETUNIFORMLOCATIONARBPROC)	wglGetProcAddress("glGetUniformLocationARB");
	glUniform1fARB				= (PFNGLUNIFORM1FARBPROC)           wglGetProcAddress("glUniform1fARB");
	glUniform1iARB				= (PFNGLUNIFORM1IARBPROC)           wglGetProcAddress("glUniform1iARB");

	glSecondaryColor3fv			= (PFNGLSECONDARYCOLOR3FVPROC)      wglGetProcAddress("glSecondaryColor3fv");

	// -------------------------------------
	// Initialize material renderer
	// -------------------------------------
	oShaderRenderer.Init();

	return(1);	
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::Finish ()
{
  	if ((GLRC) && (DC))
    {
    	// Deactivate rendering context
	    wglMakeCurrent(0,0);
        // Destroy rendering context
    	wglDeleteContext(GLRC);

		ReleaseDC(WND,DC);
		
		GLRC = NULL;
		DC   = NULL;
	}
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::RenderBBox (CGraphBV* BVol)
{
	if (! BVol) return;

	float  fXSize = BVol->GetRange(0) * 0.5f;
	float  fYSize = BVol->GetRange(1) * 0.5f;
	float  fZSize = BVol->GetRange(2) * 0.5f;
	
	CVect3 Pos = BVol->GetCenter();

	glBlendFunc(GL_ONE,GL_ZERO);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

	glColor3f(1.0f,1.0f,0.25f);
	glBegin(GL_QUADS);
		glVertex3f(Pos.x-fXSize,Pos.y-fYSize,Pos.z + fZSize);
		glVertex3f(Pos.x-fXSize,Pos.y+fYSize,Pos.z + fZSize);		
		glVertex3f(Pos.x+fXSize,Pos.y+fYSize,Pos.z + fZSize);
		glVertex3f(Pos.x+fXSize,Pos.y-fYSize,Pos.z + fZSize);

		glVertex3f(Pos.x-fXSize,Pos.y-fYSize,Pos.z + fZSize);
		glVertex3f(Pos.x-fXSize,Pos.y+fYSize,Pos.z + fZSize);		
		glVertex3f(Pos.x-fXSize,Pos.y+fYSize,Pos.z - fZSize);
		glVertex3f(Pos.x-fXSize,Pos.y-fYSize,Pos.z - fZSize);		

		glVertex3f(Pos.x+fXSize,Pos.y-fYSize,Pos.z + fZSize);
		glVertex3f(Pos.x+fXSize,Pos.y+fYSize,Pos.z + fZSize);		
		glVertex3f(Pos.x+fXSize,Pos.y+fYSize,Pos.z - fZSize);
		glVertex3f(Pos.x+fXSize,Pos.y-fYSize,Pos.z - fZSize);		

		glVertex3f(Pos.x-fXSize,Pos.y-fYSize,Pos.z - fZSize);
		glVertex3f(Pos.x-fXSize,Pos.y+fYSize,Pos.z - fZSize);		
		glVertex3f(Pos.x+fXSize,Pos.y+fYSize,Pos.z - fZSize);
		glVertex3f(Pos.x+fXSize,Pos.y-fYSize,Pos.z - fZSize);
	glEnd();
	// glEnable(GL_CULL_FACE);

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_TEXTURE_2D);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::RenderNormals (CMesh* Mesh)
{
	if ( (Mesh->VNs) && (Mesh->VXs))	
	{
		glBlendFunc(GL_ONE,GL_ZERO);
		glDisable(GL_TEXTURE_2D);

		CVect3 *pVX = Mesh->VXs;
		CVect3 *pVN = Mesh->VNs;
		CVect3 pEnd;

		glBegin(GL_LINES);
		glColor3f(0.0f,0.0f,1.0f);

		for (int cVert=0;cVert<Mesh->usNumVerts;cVert++)
		{	
			pEnd.Assign(*pVN);	
			pEnd.Scale (2.0f);
			pEnd.Add(*pVX);			
			
			glVertex3fv(pVX->V());
			glVertex3fv(pEnd.V());

			pVX++;
			pVN++;
		}

		glEnd();
		glEnable(GL_TEXTURE_2D);
	}
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::DisableBBoxRender ()
{
   	REState.BBoxRender = false;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::DisableDefferredMode ()
{
	REState.DefferredMode = false;

	if (oDefObjWH.uiNumObjects())
    	RenderDefferredObjects();
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::DisableFrustumCulling ()
{
	REState.FrustumCulling = false;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::DisableNormalRender ()
{
  	REState.NormalRender = false;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::EnableBBoxRender ()
{
    	REState.BBoxRender = true;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::EnableDefferredMode ()
{
  	REState.DefferredMode = true;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::EnableFrustumCulling ()
{
  	REState.FrustumCulling = true;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::EnableNormalRender ()
{
  	REState.NormalRender = true;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::BeginRender ()
{
  	m_oChrono.Reset();
	m_oChrono.Start();

	// Invalidate Defferred objects warehouse
	oDefObjWH.Invalidate();

    // Initialize statistic variables
	REStats.NumTestedObjs 	 = 0;
	REStats.NumRenderedGObjs = 0;
    REStats.NumCulledObjs	 = 0;
    REStats.NumRenderedTris  = 0;
    REStats.NumRenderedVerts = 0;		

	GLint BufferMask;
	BufferMask = GL_COLOR_BUFFER_BIT;

	if (eStencilFunc != E3D_SF_None)  BufferMask |= GL_STENCIL_BUFFER_BIT;
	if (eZTest       != E3D_ZTF_None) BufferMask |= GL_DEPTH_BUFFER_BIT;

	glClear(BufferMask);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::EndRender ()
{   
	// If there are some defferred objects render them
	if (oDefObjWH.uiNumObjects())
    	RenderDefferredObjects();
	
	SwapBuffers(DC);	

	// Get delta time
	m_oChrono.Stop();
	REStats.DTime = (float)m_oChrono.dElapsedTime();
	REStats.DTimes[REStats.cDTime++] = REStats.DTime;	REStats.cDTime &= 0x03;
	
	// Compute FPS
	// REStats.FPS = 0;	for(int i=0;i<4;i++) REStats.FPS += 0.25f/REStats.DTimes[i];
	// REState.FPS = 0; for(int i=0;i<4;i++) REState.FPS += 1 / REStats.DTime[i];  REState.FPS /= 4;
    if (REStats.iCurrentFrame>3)
    	REStats.FPS = 1.0f / ((REStats.DTimes[0] + REStats.DTimes[1] + REStats.DTimes[2] + REStats.DTimes[3]) * 0.25f);
    else
        REStats.FPS = 1.0f / REStats.DTime;

	// Increase total render time
	REStats.fTotalTime += REStats.DTime;

	// One more frame
	REStats.iCurrentFrame++;
}
// -----------------------------------------------------------------------------
// World / Model Matrix
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::ClearWorldMatrix ()
{
	m_oWorldMatrixStack.LoadIdentity();
	/*
  	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	CHECKERRORS();
	*/
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetWorldMatrix (CMatrix4x4 *M)
{    
	m_oWorldMatrixStack.Load(*M);
	/*
	// copiar directamente a OpenGL
	glMatrixMode (GL_MODELVIEW);
	glLoadMatrixf(M->m);
	CHECKERRORS();
	*/
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::GetWorldMatrix (CMatrix4x4 *M)
{
	*M = m_oWorldMatrixStack.oGetTop();
/*
  	// coger directamente de OpenGL	
	glGetFloatv(GL_MODELVIEW_MATRIX,M->m);
	CHECKERRORS();
*/
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::PushWorldMatrix ()
{
	m_oWorldMatrixStack.Push();
	/*
  	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	CHECKERRORS();
	*/
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::PopWorldMatrix ()
{
	m_oWorldMatrixStack.Pop();
  	/*
  	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	CHECKERRORS();
	*/
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::MultiplyMatrix(CMatrix4x4 *Matrix)
{
	m_oWorldMatrixStack.Multiply(*Matrix);
	/*
	// Leaves X = MatrixStack*M
  	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(Matrix->m);
	CHECKERRORS();
	*/
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::PreMultiplyMatrix (CMatrix4x4 *Matrix)
{
	// Leaves X = M * MatrixStack
 	float m[16];

	glMatrixMode (GL_MODELVIEW);
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	CHECKERRORS();
	
	glLoadMatrixf(Matrix->m);
	CHECKERRORS();
	
	glMultMatrixf(m);
	CHECKERRORS();
}
// -----------------------------------------------------------------------------
// Camera matrix operations
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetCameraMatrix (CMatrix4x4 *M)
{
	m_oCamMatrixStack.Load( *M );

	/*
	// copiar directamente a OpenGL
	glMatrixMode (GL_MODELVIEW);
	glLoadMatrixf(M->m);
	CHECKERRORS();
	*/
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::GetCameraMatrix (CMatrix4x4 *M)
{
	*M = m_oCamMatrixStack.oGetTop();

/*
  	glGetFloatv(GL_MODELVIEW_MATRIX,M->m);
	CHECKERRORS();
*/

}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::ClearCameraMatrix ()
{
	m_oCamMatrixStack.LoadIdentity();

/*
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	CHECKERRORS();
*/
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::PushCameraMatrix ()
{
	m_oCamMatrixStack.Push();

/*
  	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	CHECKERRORS();
*/
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::PopCameraMatrix ()
{
	m_oCamMatrixStack.Pop();
	
/*
  	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	CHECKERRORS();
*/
}
// -----------------------------------------------------------------------------
// Projector matrix operations
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::ClearProjectorMatrix ()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	CHECKERRORS();
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetProjectorMatrix (CMatrix4x4 *M)
{
  	// copiar directamente a OpenGL
	glMatrixMode (GL_PROJECTION);
	glLoadMatrixf(M->m);
	CHECKERRORS();
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::GetProjectorMatrix (CMatrix4x4 *M)
{
  	glGetFloatv(GL_PROJECTION_MATRIX,M->m);
	CHECKERRORS();
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::PushProjectorMatrix ()
{
  	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	CHECKERRORS();
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::PopProjectorMatrix ()
{
  	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	CHECKERRORS();
}
// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::RenderDefferredObjects ()
{
  	
	// Sort meshes by material
	oDefObjWH.Sort();
	
	// Get the number of enabled lights
	unsigned int	uiOldEnabledLights = uiEnabledLights;

	PushWorldMatrix();
	
		// Loop through all deferred objects
		for (uint i=0;i< oDefObjWH.uiNumObjects();i++)
		{
			// Get object data
			CDefferredMeshEntry oDME = oDefObjWH.oGetObject(i);

			// Setup its modelview matrix
			SetWorldMatrix(&oDME.oMatrix);

			// Internal render
			RenderMesh_Int(oDME.poMesh,oDME.poShader,oDME.eMeshType);
		}

	PopWorldMatrix();

	// Restore light state
	uiEnabledLights = uiOldEnabledLights;

	oDefObjWH.Invalidate();
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::RenderMesh (CMesh *_poMesh)
{
   	RenderMesh(_poMesh,NULL);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::RenderMesh (CMesh *_poMesh, CE3D_Shader *_poShader)
{
    if (! _poShader)
		_poShader = &E3D_NULL_SHADER;

	if (! _poMesh->usNumPrims)
		return;

	if (REState.DefferredMode)
	{
		// Insert deferred objects
		CMatrix4x4 M;
		GetWorldMatrix(&M);
		oDefObjWH.bInsertDefferredObject(_poMesh,eE3DMT_Mesh,_poShader,M,uiEnabledLights);
	}
	else
	{
		RenderMesh_Int(_poMesh,_poShader,eE3DMT_Mesh);
	}

	REStats.NumRenderedGObjs++;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::RenderCompiledMesh (CCompiledMesh* _poCMesh)
{
  	RenderCompiledMesh(_poCMesh,NULL);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::RenderCompiledMesh (CCompiledMesh *_poCMesh, CE3D_Shader *_poShader)
{
  	if (! _poCMesh->usNumPrims) 
		return;

	// Compiled meshes with NULL materials are still valid since the material 
	// definition may be inside the compiled mesh 

	if (REState.DefferredMode)
	{	
		// Insert deferred objects
		CMatrix4x4 M;
		GetWorldMatrix(&M);
		oDefObjWH.bInsertDefferredObject(_poCMesh,eE3DMT_CompiledMesh,_poShader,M,uiEnabledLights);
	}
	else
	{
		RenderMesh_Int(_poCMesh,_poShader,eE3DMT_CompiledMesh);
	}

	REStats.NumRenderedGObjs++;
}
// -----------------------------------------------------------------------------
// Common internal render for both compiled or not compiled meshes
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::RenderMesh_Int(void *_poMesh, CE3D_Shader *_poShader,E3D_MeshType _eMeshType)
{
	PrepareLights();

	// Premultiply camera matrix by model matrix
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();


	CMatrix4x4 oM = m_oCamMatrixStack.oGetTop() * m_oWorldMatrixStack.oGetTop();

	glLoadMatrixf( oM.m );

/*	float m[16];
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	CHECKERRORS();
	glLoadMatrixf( m_oCamMatrixStack.oGetTop().m );
	CHECKERRORS();

	glMultMatrixf(m);
*/
	// glMultMatrixf(m_oCamMatrixStack.oGetTop().m);
	// CHECKERRORS();

		if (_eMeshType == eE3DMT_Mesh)
		{
			CMesh* poMesh = (CMesh*)_poMesh;

			if (REState.BBoxRender)		RenderBBox( poMesh->GetBoundVol() );
			if (REState.NormalRender)	RenderNormals(poMesh);

			oShaderRenderer.Render(poMesh,_poShader);
		}
		else
		{
			CCompiledMesh* poMesh = (CCompiledMesh*)_poMesh;

			if (REState.BBoxRender)		RenderBBox( poMesh->poGetBV() );
			// if (REState.NormalRender)	RenderNormals(poMesh);

			oShaderRenderer.Render(poMesh,_poShader);		
		}

	glPopMatrix();
	CHECKERRORS();
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetCurrentMaterial (CE3D_Shader *_poShader)
{
  	poCurrentShader = _poShader;
}
// -----------------------------------------------------------------------------
CE3D_Shader * CE3D_OGL_Win_Renderer::poGetCurrentMaterial ()
{
  	return (poCurrentShader);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetCurrentTextureContext (CGTextureObj *TexObj)
{
  	if (! TexObj)		return;
	if (! TexObj->m_poMipMap)	return;

	if (! TexObj->m_uiHandler)
    {
        // La textura no ha sido cargada en mem antes
        UploadTexture(TexObj);
        TexObj->Validate();
	}
    else
    {
        if (! TexObj->bValid())
        {
            UpdateTexture(TexObj);
            TexObj->Validate();
		}
		else
		{
			// Establecer el/ contexto de la textura    	
			glBindTexture(GL_TEXTURE_2D,TexObj->m_uiHandler);
			CHECKERRORS();
			
			if (TexObj->m_poMipMap->m_eFormat == IF_PALETTE)
			{				
				if (glColorTableEXT)
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
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::UpdateTexture (CGTextureObj *TexObj)
{
    unsigned int cLOD;
	
	glBindTexture(GL_TEXTURE_2D,TexObj->m_uiHandler);

	unsigned int uiTX = TexObj->m_poMipMap->m_uiTX;
	unsigned int uiTY = TexObj->m_poMipMap->m_uiTY;

    for (cLOD = 0;cLOD < TexObj->m_poMipMap->m_uiNumLODs;cLOD++)
    {
		// WINGDIAPI void APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
        glTexImage2D	(GL_TEXTURE_2D,
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
	if (TexObj->m_poMipMap->m_eFormat == IF_PALETTE)
	{	
		if (glColorTableEXT)
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
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::UploadTexture (CGTextureObj *TexObj)
{
    unsigned int cLOD;

    // Generar un handler para la textura
    glGenTextures(1,&TexObj->m_uiHandler);
	CHECKERRORS();

    // Establecer el contexto de la nueva textura
    glBindTexture(GL_TEXTURE_2D,TexObj->m_uiHandler);
	CHECKERRORS();
	
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	uint uiTX = TexObj->m_poMipMap->m_uiTX;
	uint uiTY = TexObj->m_poMipMap->m_uiTY;

    for (cLOD = 0;cLOD < TexObj->m_poMipMap->m_uiNumLODs;cLOD++)
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
    if (TexObj->m_uiUWrap == E3D_TEX_WRAP_REPEAT)
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    else
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);

    if (TexObj->m_uiVWrap == E3D_TEX_WRAP_REPEAT)
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    else
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);

    // Setup mignification filter
    switch (TexObj->m_uiMinFilter)
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
    switch (TexObj->m_uiMaxFilter)
    {
        case E3D_TEX_MAX_FILTER_NEAREST: glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
                                         break;
        case E3D_TEX_MAX_FILTER_LINEAR:  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
                                         break;
	}

	// Setup clut if needed
	if (TexObj->m_poMipMap->m_eFormat == IF_PALETTE)
	{				
		if (glColorTableEXT)
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
// -----------------------------------------------------------------------------
bool CE3D_OGL_Win_Renderer::UsingBBoxRender ()
{
  	return(REState.BBoxRender);
}
// -----------------------------------------------------------------------------
bool CE3D_OGL_Win_Renderer::UsingDefferredMode ()
{
  	return (REState.DefferredMode);    
}
// -----------------------------------------------------------------------------
bool CE3D_OGL_Win_Renderer::UsingFrustumCulling ()
{
    	return(REState.FrustumCulling);
}
// -----------------------------------------------------------------------------
bool CE3D_OGL_Win_Renderer::UsingNormalRender ()
{
    return (REState.NormalRender);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::UpdateViewing ()
{
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetViewport (CE3D_Viewport *_Viewport)
{
  	if (! _Viewport) return;
		
	Viewport	 = _Viewport;
	fAspectRatio = (Viewport->ScrTX*iScrTX) / (Viewport->ScrTY*iScrTY);

	//-----------!!!!!!!!!--------
	// coordenadas en float (normalizadas) no en int relativas a screen
	//-----------!!!!!!!!!--------

    // Set viewport coordinates
	glViewport(Viewport->ScrCX*iScrTX,
			   Viewport->ScrCY*iScrTY,
			   Viewport->ScrTX*iScrTX,
			   Viewport->ScrTY*iScrTY);
	CHECKERRORS();

	glScissor (Viewport->ScrCX*iScrTX,
			   Viewport->ScrCY*iScrTY,
			   Viewport->ScrTX*iScrTX,
			   Viewport->ScrTY*iScrTY);
	CHECKERRORS();

	if (Projector)
		Frustum.Compute(Projector,fAspectRatio);
}
// -----------------------------------------------------------------------------
CE3D_Viewport * CE3D_OGL_Win_Renderer::GetViewport ()
{
  	return(Viewport);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetCamera (CE3D_Camera *_Camera)
{
  	if (! _Camera) return;
	Camera = _Camera;

	// Camera matrix
	glMatrixMode(GL_MODELVIEW);	
	glPushMatrix();
	
		glLoadIdentity();
		CHECKERRORS();

		gluLookAt(	Camera->Pos.x,
					Camera->Pos.y,
					Camera->Pos.z,
    				Camera->Pos.x + Camera->Dir.x,
					Camera->Pos.y + Camera->Dir.y,
					Camera->Pos.z + Camera->Dir.z,
    				Camera->Up.x,
					Camera->Up.y,
					Camera->Up.z);
		CHECKERRORS();

  		// coger directamente de OpenGL
  		CMatrix4x4 oMat;
		glGetFloatv(GL_MODELVIEW_MATRIX,oMat.m);
		m_oCamMatrixStack.Load(oMat);

	// Restore old matrix
	glPopMatrix();
}
// -----------------------------------------------------------------------------
CE3D_Camera * CE3D_OGL_Win_Renderer::GetCamera ()
{
  	return(Camera);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetProjector (CE3D_Projector *_Projector)
{
  	if (!_Projector) return;

	Projector   = _Projector;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	CHECKERRORS();

	switch (Projector->ePrjType)
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

			gluPerspective(Projector->fFOV,fAspectRatio,Projector->fNear,Projector->fFar);
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
			float fSeparation = Projector->fNear * cosf(fAngle)/sinf(fAngle);

			glOrtho(-fSeparation*fAspectRatio,
					 fSeparation*fAspectRatio,
					-fSeparation,
					 fSeparation,					 
					 Projector->fNear,Projector->fFar);
			*/

			glOrtho(-fAspectRatio,
					 fAspectRatio,
					-1.0f,
					 1.0f,
					 Projector->fNear,Projector->fFar);

			CHECKERRORS();
		}
		break;
	}

	Frustum.Compute(Projector,fAspectRatio);	
}
// -----------------------------------------------------------------------------
CE3D_Projector * CE3D_OGL_Win_Renderer::GetProjector ()
{
  	return(Projector);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetScreenSize (int _iScrTX, int _iScrTY)
{
    	iScrTX = _iScrTX;
	iScrTY = _iScrTY;

	SetViewport(Viewport);	
}
// -----------------------------------------------------------------------------
CCompiledMesh * CE3D_OGL_Win_Renderer::poCompileMesh (CMesh *_poMesh, CE3D_Shader *_poShader)
{
  	assert  (_poMesh);
	if (_poMesh->GetMeshType() == E3D_MESH_NONE) return(NULL);

	CCompiledMesh		*poCMesh;

	// Setup compiled mesh info
	poCMesh = mNew CCompiledMesh;
	poCMesh->eMeshType  = _poMesh->GetMeshType();
	poCMesh->usNumPrims = _poMesh->usNumPrims;
	poCMesh->usNumVerts = _poMesh->usNumVerts;
	poCMesh->poCopyBV(_poMesh->GetBoundVol());
	
	// Create new display list
	poCMesh->iID = glGenLists(1);
	glNewList(poCMesh->iID,GL_COMPILE_AND_EXECUTE);

		// If _poMaterial == NULL, then only the vertexs are compiled the material definition
		oShaderRenderer.Render(_poMesh,_poShader);

	glEndList();

	return(poCMesh);

}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::DestroyCompiledMesh (CCompiledMesh *_poCMesh)
{  	
	// List and object will longer no be available
	glDeleteLists(_poCMesh->iID,1);
	mDel _poCMesh;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetupPalette (TPixelFormatDescriptor PFD)
{
    int nColors,i;
    TLogPalette  *lpPalette;
    unsigned char byRedMask,byGreenMask,byBlueMask;
    HPALETTE Palette;

	nColors =1 << PFD.cColorBits;

    lpPalette = (TLogPalette *) mAlloc(sizeof(TLogPalette)+(nColors*sizeof(TPaletteEntry)));

    lpPalette->palVersion    = 0x300;
    lpPalette->palNumEntries =nColors;

    byRedMask   =(1 << PFD.cRedBits)  -1;
    byGreenMask =(1 << PFD.cGreenBits)-1;
    byBlueMask  =(1 << PFD.cBlueBits) -1;

    for (i=0;i<nColors;i++)
    {
        lpPalette->palPalEntry[i].peRed   = (((i >> PFD.cRedShift)   & byRedMask)  *255) / byRedMask;
        lpPalette->palPalEntry[i].peGreen = (((i >> PFD.cGreenShift) & byGreenMask)*255) / byGreenMask;
        lpPalette->palPalEntry[i].peBlue  = (((i >> PFD.cBlueShift)  & byBlueMask) *255) / byBlueMask;
        lpPalette->palPalEntry[i].peFlags = 0;
	}

    Palette = CreatePalette(lpPalette);

    if (Palette)
    {
    	SelectPalette(DC,Palette,false);
    	RealizePalette(DC);
	}

	mFree(lpPalette);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::EnableFlatRendering ()
{
  	REState.FlatRender = true;

	glDisable	(GL_TEXTURE_2D);
	glShadeModel(GL_FLAT);
	glDisable	(GL_BLEND);

	if (uiEnabledLights)
		glDisable(GL_LIGHTING);

	glClearColor(1.0f,1.0f,1.0f,0.0f);
	glColor4f(0.5f,0.5f,0.5f,0.0f);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::DisableFlatRendering ()
{
  	REState.FlatRender = false;
	
	glEnable	(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glEnable	(GL_BLEND);
	
	if (uiEnabledLights)
		glEnable(GL_LIGHTING);

	glClearColor(m_oClearColor.r,m_oClearColor.g,m_oClearColor.g,m_oClearColor.a);
	glColor4f(1.0f,1.0f,1.0f,0.0f);
}
// -----------------------------------------------------------------------------
bool CE3D_OGL_Win_Renderer::UsingFlatRendering ()
{
  	return(REState.FlatRender);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::ReadBuffer (int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData)
{
  	switch (_eBufferType)
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
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::WriteBuffer (int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData)
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
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetStencilParams (bool _bEnable, E3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, E3D_StencilAction _eSFails, E3D_StencilAction _eZFails, E3D_StencilAction _eZPass)
{
  	E3D_StencilFunc	eSFAux;

	// ---------------------------
	// Handle first special cases:
	// ---------------------------

	// Last 
	if (_eStencilFunc == E3D_SF_Last)
	{
		if ((eStencilFunc == E3D_SF_None) && (eStencilFuncLast != E3D_SF_None))
			glEnable(GL_STENCIL_TEST);
		else
		{
			if ((eStencilFunc != E3D_SF_None) && (eStencilFuncLast == E3D_SF_None))
				glDisable(GL_STENCIL_TEST);
		}
		
		eStencilFunc = eStencilFuncLast;
		return;
	}

	// Disable
	if (_eStencilFunc == E3D_SF_None)
	{
		// Disable ?
		if (eStencilFunc != E3D_SF_None)
		{
			eStencilFuncLast= eStencilFunc;
			eStencilFunc    = E3D_SF_None;
			glDisable(GL_STENCIL_TEST);
		}
		
		return;
	}

	// Current
	if (_eStencilFunc != E3D_SF_Current)
	{
		// Enable function
		if (eStencilFunc == E3D_SF_None) glEnable(GL_STENCIL_TEST);
		// glFogf (GL_FOG_MODE,eGetFogMode(_eFogMode));
	}

	// Set the stencil function
	glStencilFunc(eGetStencilFunc(_eStencilFunc),_iRefValue,_iMask);

	// Set the stencil operation
	glStencilOp(eGetStencilAct(_eSFails),
				eGetStencilAct(_eZFails),
				eGetStencilAct(_eZPass));

	eStencilFunc    = _eStencilFunc;
	eStencilFuncLast= eStencilFunc;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetZPars (E3D_ZTestFunc _eZTest, E3D_ZWrite _eZWrite)
{
  	if (_eZTest != E3D_ZTF_Current)
	{
		// Disable ?	
		if (_eZTest == E3D_ZTF_None)
		{
			// Is enabled?
			if (eZTest != _eZTest)
			{		
				eZTestLast = eZTest;
				eZTest     = E3D_ZTF_None;
				glDisable(GL_DEPTH_TEST);
			}
		}
		else
		{
			if (_eZTest == E3D_ZTF_Last) _eZTest = eZTestLast;
			
			// Enable function
			if (eZTest == E3D_ZTF_None) glEnable(GL_DEPTH_TEST);

			// Set pars
			glDepthFunc(eGetDepthFunc(_eZTest));

			eZTest	   = _eZTest;
			eZTestLast = eZTest;
		}
	}

	if (_eZWrite != E3D_ZW_Current)
	{
		// Disable ?	
		if (_eZWrite == E3D_ZW_Disable)
		{	
			// Is enabled?
			if (eZWrite == E3D_ZW_Enable)
			{		
				eZWriteLast = E3D_ZW_Enable;
				eZWrite     = E3D_ZW_Disable;
				glDepthMask(GL_FALSE);
			}
		}
   else if (_eZWrite == E3D_ZW_Enable)
		{
			// Is disabled?
			if (eZWrite == E3D_ZW_Disable)
			{							
				eZWriteLast = E3D_ZW_Disable;
				eZWrite     = E3D_ZW_Enable;
				glDepthMask(GL_TRUE);
			}
		}
	else if  (_eZWrite == E3D_ZW_Last)
		{
			// Is disabled?
			eZWrite     = eZWriteLast;			
		
			if (eZWriteLast == E3D_ZW_Enable)
				glDepthMask(GL_TRUE);
			else
				glDepthMask(GL_FALSE);
		}
	}
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::MaskChannels (bool _bR, bool _bG, bool _bB, bool _bA)
{
  	glColorMask(_bR,_bG,_bB,_bA);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetFogPars(E3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, CGColor* _poColor)
{
  	
	// ---------------------------
	// Handle first special cases:
	// ---------------------------

	// Last 
	if (_eFogMode == E3D_FM_Last)
	{
		if ((eFogMode == E3D_FM_None) && (eFogModeLast != E3D_FM_None))
			glEnable(GL_FOG);
		else
		{
			if ((eFogMode != E3D_FM_None) && (eFogModeLast == E3D_FM_None))
				glDisable(GL_FOG);
		}
		
		eFogMode = eFogModeLast;
		return;
	}

	// Disable
	if (_eFogMode == E3D_FM_None)
	{
		// Disable ?
		if (eFogMode != E3D_FM_None)
		{
			eFogModeLast= eFogMode;
			eFogMode    = E3D_FM_None;
			glDisable(GL_FOG);								
		}
		
		return;
	}

	// Current
	if (_eFogMode != E3D_FM_Current)
	{
		// Enable function
		if (eFogMode == E3D_FM_None) glEnable(GL_FOG);		
		glFogf (GL_FOG_MODE,eGetFogMode(_eFogMode));	
	}

	// Set the fog parameters
	glFogf  (GL_FOG_START,_fStart);
	glFogf  (GL_FOG_END  ,_fEnd);
	glFogf  (GL_FOG_DENSITY,_fDensity);
	glFogfv (GL_FOG_COLOR,(float *)_poColor	);

	eFogMode	= _eFogMode;
	eFogModeLast= _eFogMode;
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::ClearBuffer (E3D_RenderBuffer_Type _eBuffer)
{
  	switch (_eBuffer)
	{
		case E3D_RB_Front:
		case E3D_RB_Back:		glClear(GL_COLOR_BUFFER_BIT);
								return;
		case E3D_RB_Z:			glClear(GL_DEPTH_BUFFER_BIT);
								return;
		case E3D_RB_Stencil:	glClear(GL_STENCIL_BUFFER_BIT);
								return;
		default:
				return;				
	}
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetupLight (int _iLightID, CE3D_Light& _oLight)
{
  	switch (_oLight.eType)
	{
		case LT_Point:
		{
			oLPos[_iLightID].x = _oLight.oPos.x;
			oLPos[_iLightID].y = _oLight.oPos.y;
			oLPos[_iLightID].z = _oLight.oPos.z;
			oLPos[_iLightID].w = 1.0f;
		}
		break;

		case LT_Directional:
			oLPos[_iLightID].x = _oLight.oDir.x;
			oLPos[_iLightID].y = _oLight.oDir.y;
			oLPos[_iLightID].z = _oLight.oDir.z;
			oLPos[_iLightID].w = 0.0f;
		break;

		case LT_Spot:
			/*
			glLightf (eLightID, GL_SPOT_CUTOFF			,_oLight.fSpCutOff);
			glLightfv(eLightID, GL_SPOT_DIRECTION		,_oLight.oSpDir.z);
			glLightfv(eLightID, GL_SPOT_EXPONENT		,fPos);	
			*/
		break;
	}

	
	GLenum	eLightID = eGetLightID(_iLightID);


	// ---------------------------------------
	/*
	glPushMatrix();
	glLoadIdentity();
	glLightfv(eLightID,GL_POSITION,oLPos[_iLightID].V());
	glPopMatrix();
	*/
	// ---------------------------------------

	

	glLightfv(eLightID, GL_AMBIENT	,(float*)&_oLight.oLitAmb );
	glLightfv(eLightID, GL_DIFFUSE	,(float*)&_oLight.oLitDiff);
	glLightfv(eLightID, GL_SPECULAR	,(float*)&_oLight.oLitSpec);

	glLightf (eLightID, GL_CONSTANT_ATTENUATION	,_oLight.fCAtt);
	glLightf (eLightID, GL_LINEAR_ATTENUATION	,_oLight.fLAtt);
	glLightf (eLightID, GL_QUADRATIC_ATTENUATION,_oLight.fQAtt);
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetLight (int _iLightID, bool _bEnable)
{
  	if (_bEnable)
	{
		uiEnabledLights |= (1<<_iLightID);
	}
	else
	{
		glDisable(eGetLightID(_iLightID));
		uiEnabledLights &= ~(1<<_iLightID);
	}
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::InvalidateTexture (CGTextureObj *TexObj)
{
	unsigned int cLOD;

    // Generar un handler para la textura
    glDeleteTextures(1,&TexObj->m_uiHandler);
	TexObj->m_uiHandler = 0;
}
// -----------------------------------------------------------------------------
// Additional Declarations
void CE3D_OGL_Win_Renderer::PrepareLights()
{
	if (uiEnabledLights)
	{
		glEnable(GL_LIGHTING);

		for (int iL=0;iL<MAX_LIGHTS;iL++)
		{
			if (uiEnabledLights & (1 << iL))
			{
				// Send light position to the GL
				glEnable (eGetLightID(iL));
				glLightfv(eGetLightID(iL),GL_POSITION,oLPos[iL].V());
			}
			else
				glEnable(eGetLightID(iL));
		}
	}
	else
	{
		glDisable(GL_LIGHTING);
		return;
	}
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::UploadProgram(CGProgram* _poProgram)
{
	char szError[1024];
	GLsizei length;

	_poProgram->m_hProgram = (handler)glCreateProgramObjectARB();
	glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
	CHECKERRORS();

	// Process vertex shader
	if (_poProgram->m_pucVSData != NULL)
	{
		_poProgram->m_hVS = (handler)glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
		glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
		CHECKERRORS();
		
		glShaderSourceARB((GLhandleARB)_poProgram->m_hVS,1,(const GLcharARB**)&_poProgram->m_pucVSData,NULL);
		glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
		CHECKERRORS();
		
		glCompileShaderARB((GLhandleARB)_poProgram->m_hVS);
		glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
		CHECKERRORS();
		
		glAttachObjectARB((GLhandleARB)_poProgram->m_hProgram,(GLhandleARB)_poProgram->m_hVS);
		glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
		CHECKERRORS();
	}

	// Process pixel shader
	if (_poProgram->m_pucPSData != NULL)
	{
		_poProgram->m_hPS = (handler)glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
		glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
		CHECKERRORS();
		
		glShaderSourceARB((GLhandleARB)_poProgram->m_hPS,1,(const GLcharARB**)&_poProgram->m_pucPSData,NULL);
		glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
		CHECKERRORS();
		
		glCompileShaderARB((GLhandleARB)_poProgram->m_hPS);
		glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
		CHECKERRORS();
		
		glAttachObjectARB((GLhandleARB)_poProgram->m_hProgram,(GLhandleARB)_poProgram->m_hPS);
		glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
		CHECKERRORS();
	}
	
	// Link the program
	glLinkProgramARB((GLhandleARB)_poProgram->m_hProgram);
	
	GLint resul;
	glGetObjectParameterivARB((GLhandleARB)_poProgram->m_hProgram,GL_OBJECT_LINK_STATUS_ARB,&resul);
	if (resul != 1)
	{
		glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
		CHECKERRORS();

		CGErrorLC::I()->Write(szError);
	}
	
	int my_sampler_uniform_location = glGetUniformLocationARB((GLhandleARB)_poProgram->m_hProgram, "TMU0Tex");
	glUniform1iARB(my_sampler_uniform_location, 0);
	CHECKERRORS();
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::UpdateProgram(CGProgram* _poProgram)
{

}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetCurrentProgram(CGProgram* _poProgram)
{
	if (glUseProgramObjectARB == NULL) return;

  	if (_poProgram == NULL)
	{
		glUseProgramObjectARB(0);
		CHECKERRORS();
  		return;
  	}

	if (_poProgram->m_hProgram == NULL)
    {
        // El programa no ha sido cargado en mem antes
        UploadProgram(_poProgram);
        _poProgram->Validate();
	}
    else
    {
        if (! _poProgram->bValid())
        {
            UpdateProgram(_poProgram);
            _poProgram->Validate();
		}
	}

	glUseProgramObjectARB((GLhandleARB)_poProgram->m_hProgram);

	char szError[1024];
	GLsizei length;
	glGetInfoLogARB((GLhandleARB)_poProgram->m_hProgram, 1024, &length, (GLcharARB *)szError);
	CHECKERRORS();	
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::InvalidateProgram(CGProgram* _poProgram)
{
}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetProgramParam(CGProgram* _poProgram,const CGString& _sParam,void*_pValue)
{

}
// -----------------------------------------------------------------------------
void CE3D_OGL_Win_Renderer::SetConstantColor(const CGColor& _oColor)
{
	// Qué pasa con el alpha? .... 
	// glSecondaryColor3fv();
	
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,_oColor.v() );

}
// -----------------------------------------------------------------------------
