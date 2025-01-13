//## begin module%3A9AB8C503B6.cm preserve=no
//## end module%3A9AB8C503B6.cm

//## begin module%3A9AB8C503B6.cp preserve=no
//## end module%3A9AB8C503B6.cp

//## Module: CE3D_OGL_Win_Renderer%3A9AB8C503B6; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Drivers\OGL\CE3D_OGL_Win_Renderer.cpp

//## begin module%3A9AB8C503B6.additionalIncludes preserve=no
//## end module%3A9AB8C503B6.additionalIncludes

//## begin module%3A9AB8C503B6.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include "Misc/GammaE_Misc.h"

#include "CE3D_OGL_Win_Renderer.h"
#include <tex.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glext.h>

// The format of the functions we're gonna get hold of.
typedef void (APIENTRY *PFNGLCOLORTABLEEXT)(int, int, int, int, int, const void * );

//Our two function pointers.
PFNGLCOLORTABLEEXT glColorTableEXT;

//## end module%3A9AB8C503B6.includes

// CE3D_OGL_Win_Renderer
#include "E3D\Drivers\OGL\CE3D_OGL_Win_Renderer.h"
//## begin module%3A9AB8C503B6.additionalDeclarations preserve=yes

//---------------------------------------------------------------------------
// Driver specific options
//---------------------------------------------------------------------------
#define E3D_RENDERER_OP_GDI 	0x00000100

//---------------------------------------------------------------------------
unsigned int GetTextureFormat(PixelFormat pixelFormat)
{
    switch (pixelFormat)
    {
		case PixelFormat::ARGB32:return(GL_RGBA);
		case PixelFormat::RGB24: return(GL_RGB);
		case PixelFormat::GRAY8: return(GL_LUMINANCE);
		case PixelFormat::PALETTE:return(GL_COLOR_INDEX);

		default:
				return(GL_RGBA);
    }
}
//---------------------------------------------------------------------------
unsigned int GetTextureInternalFormat(PixelFormat pixelFormat)
{
     switch (pixelFormat)
    {
        case PixelFormat::ARGB32:return(GL_RGBA);
        case PixelFormat::RGB24: return(GL_RGB);
        case PixelFormat::GRAY8: return(GL_LUMINANCE);
		case PixelFormat::PALETTE: return(GL_COLOR_INDEX8_EXT);
		
		default:
			return(0);
    }
}
//---------------------------------------------------------------------------
GLenum eGetStencilAct(eE3D_StencilAction _eSA)
{
	switch (_eSA)
	{
		case eE3D_SA_None:	return(GL_KEEP);
		case eE3D_SA_Keep:	return(GL_KEEP);
		case eE3D_SA_Zero:	return(GL_ZERO);
		case eE3D_SA_Inc:	return(GL_INCR);
		case eE3D_SA_Dec:	return(GL_DECR);
		case eE3D_SA_Inv:	return(GL_INVERT);
		default:
				return(GL_KEEP);
	}
}

GLenum eGetStencilFunc(eE3D_StencilFunc _eSF)
{
	switch (_eSF)
	{
		case eE3D_SF_None:		return(GL_ALWAYS);
		case eE3D_SF_Never:		return(GL_NEVER);
		case eE3D_SF_Less:		return(GL_LESS);
		case eE3D_SF_LEqual:	return(GL_LEQUAL);
		case eE3D_SF_Greater:	return(GL_GREATER);
		case eE3D_SF_GEqual:	return(GL_GEQUAL);
		case eE3D_SF_Equal:		return(GL_EQUAL);
		case eE3D_SF_NotEqual:	return(GL_NOTEQUAL);
		case eE3D_SF_Always:	return(GL_ALWAYS);
		default:
				return(GL_ALWAYS);
	}
}

GLenum eGetFogMode(eE3D_FogMode _eFM)
{
	switch (_eFM)
	{
		case eE3D_FM_None:	return(GL_LINEAR);
		case eE3D_FM_Linear:return(GL_LINEAR);
		case eE3D_FM_Exp:	return(GL_EXP);
		case eE3D_FM_Exp2:	return(GL_EXP2);
		default:
				return(GL_LINEAR);
	}
}

GLenum eGetDepthFunc(eE3D_ZTestFunc _ZT)
{
	switch (_ZT)
	{
		case eE3D_ZTF_None:		return(GL_ALWAYS);
		case eE3D_ZTF_Never:	return(GL_NEVER);
		case eE3D_ZTF_Less:		return(GL_LESS);
		case eE3D_ZTF_LEqual:	return(GL_LEQUAL);
		case eE3D_ZTF_Greater:	return(GL_GREATER);
		case eE3D_ZTF_GEqual:	return(GL_GEQUAL);
		case eE3D_ZTF_Equal:	return(GL_EQUAL);
		case eE3D_ZTF_NotEqual:	return(GL_NOTEQUAL);
		case eE3D_ZTF_Always:	return(GL_ALWAYS);
		default:
				return(GL_ALWAYS);
	}
}

GLenum eGetLightID(int _iLightID)
{
	return(GL_LIGHT0 + _iLightID);
}



// For Lighting
#define		 MAX_LIGHTS	 8
CVect4		 oLPos	 [MAX_LIGHTS];
unsigned int uiEnabledLights = 0;



#ifdef _DEBUG

static void CONTROL_ERRORS()
{
	int iError;
	do{

		iError = glGetError();
		if (iError != GL_NO_ERROR)
		{
			int a=0;
		}
	}while (iError != GL_NO_ERROR);
}
#else
#define CONTROL_ERRORS()
#endif

//---------------------------------------------------------------------------
//#define _DEBUG_WIREFRAME

//## end module%3A9AB8C503B6.additionalDeclarations


// Class CE3D_OGL_Win_Renderer 

CE3D_OGL_Win_Renderer::CE3D_OGL_Win_Renderer()
  //## begin CE3D_OGL_Win_Renderer::CE3D_OGL_Win_Renderer%.hasinit preserve=no
  //## end CE3D_OGL_Win_Renderer::CE3D_OGL_Win_Renderer%.hasinit
  //## begin CE3D_OGL_Win_Renderer::CE3D_OGL_Win_Renderer%.initialization preserve=yes
  //## end CE3D_OGL_Win_Renderer::CE3D_OGL_Win_Renderer%.initialization
{
  //## begin CE3D_OGL_Win_Renderer::CE3D_OGL_Win_Renderer%.body preserve=yes

	// Setup NULL color
	CE3D_ShIns_Color *poColor = mNew CE3D_ShIns_Color;
	poColor->oColor.SetColor(1.0f,0.0f,0.0f,0.5f);
    E3D_NULL_SHADER.AddInstruction(poColor);

	//---------------------------------------------------------------------------
	// Create and initialize engine associated objects
	//---------------------------------------------------------------------------
	REStats.cDTime   = 0;
	REStats.DTimes[0] = REStats.DTimes[1] = REStats.DTimes[2] = REStats.DTimes[3] = 1;
	REStats.FPS      = 1.0f;
  //## end CE3D_OGL_Win_Renderer::CE3D_OGL_Win_Renderer%.body
}


CE3D_OGL_Win_Renderer::~CE3D_OGL_Win_Renderer()
{
  //## begin CE3D_OGL_Win_Renderer::~CE3D_OGL_Win_Renderer%.body preserve=yes
  	Finish();
  //## end CE3D_OGL_Win_Renderer::~CE3D_OGL_Win_Renderer%.body
}



//## Other Operations (implementation)
void CE3D_OGL_Win_Renderer::RenderBBox (CGraphBV* BVol)
{
  //## begin CE3D_OGL_Win_Renderer::RenderBBox%996790582.body preserve=yes
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
		glVertex3f(Pos.X()-fXSize,Pos.Y()-fYSize,Pos.Z() + fZSize);
		glVertex3f(Pos.X()-fXSize,Pos.Y()+fYSize,Pos.Z() + fZSize);		
		glVertex3f(Pos.X()+fXSize,Pos.Y()+fYSize,Pos.Z() + fZSize);
		glVertex3f(Pos.X()+fXSize,Pos.Y()-fYSize,Pos.Z() + fZSize);

		glVertex3f(Pos.X()-fXSize,Pos.Y()-fYSize,Pos.Z() + fZSize);
		glVertex3f(Pos.X()-fXSize,Pos.Y()+fYSize,Pos.Z() + fZSize);		
		glVertex3f(Pos.X()-fXSize,Pos.Y()+fYSize,Pos.Z() - fZSize);
		glVertex3f(Pos.X()-fXSize,Pos.Y()-fYSize,Pos.Z() - fZSize);		

		glVertex3f(Pos.X()+fXSize,Pos.Y()-fYSize,Pos.Z() + fZSize);
		glVertex3f(Pos.X()+fXSize,Pos.Y()+fYSize,Pos.Z() + fZSize);		
		glVertex3f(Pos.X()+fXSize,Pos.Y()+fYSize,Pos.Z() - fZSize);
		glVertex3f(Pos.X()+fXSize,Pos.Y()-fYSize,Pos.Z() - fZSize);		

		glVertex3f(Pos.X()-fXSize,Pos.Y()-fYSize,Pos.Z() - fZSize);
		glVertex3f(Pos.X()-fXSize,Pos.Y()+fYSize,Pos.Z() - fZSize);		
		glVertex3f(Pos.X()+fXSize,Pos.Y()+fYSize,Pos.Z() - fZSize);
		glVertex3f(Pos.X()+fXSize,Pos.Y()-fYSize,Pos.Z() - fZSize);
	glEnd();
	glEnable(GL_CULL_FACE);

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_TEXTURE_2D);
  //## end CE3D_OGL_Win_Renderer::RenderBBox%996790582.body
}

void CE3D_OGL_Win_Renderer::RenderNormals (CMesh* Mesh)
{
  //## begin CE3D_OGL_Win_Renderer::RenderNormals%1000845954.body preserve=yes
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
			
			glVertex3fv(pVX->v);
			glVertex3fv(pEnd.v);

			pVX++;
			pVN++;
		}

		glEnd();
		glEnable(GL_TEXTURE_2D);
	}
	
  //## end CE3D_OGL_Win_Renderer::RenderNormals%1000845954.body
}

void CE3D_OGL_Win_Renderer::BeginRender ()
{
  //## begin CE3D_OGL_Win_Renderer::BeginRender%1003953180.body preserve=yes
	Chrono_StartChrono();

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

	if (eStencilFunc != eE3D_SF_None)  BufferMask |= GL_STENCIL_BUFFER_BIT;
	if (eZTest       != eE3D_ZTF_None) BufferMask |= GL_DEPTH_BUFFER_BIT;

	glClear(BufferMask);
  //## end CE3D_OGL_Win_Renderer::BeginRender%1003953180.body
}

void CE3D_OGL_Win_Renderer::ClearCameraMatrix ()
{
  //## begin CE3D_OGL_Win_Renderer::ClearCameraMatrix%1003953181.body preserve=yes
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::ClearCameraMatrix%1003953181.body
}

void CE3D_OGL_Win_Renderer::ClearProjectorMatrix ()
{
  //## begin CE3D_OGL_Win_Renderer::ClearProjectorMatrix%1003953182.body preserve=yes
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::ClearProjectorMatrix%1003953182.body
}

void CE3D_OGL_Win_Renderer::DisableBBoxRender ()
{
  //## begin CE3D_OGL_Win_Renderer::DisableBBoxRender%1003953183.body preserve=yes
  	REState.BBoxRender = false;
  //## end CE3D_OGL_Win_Renderer::DisableBBoxRender%1003953183.body
}

void CE3D_OGL_Win_Renderer::DisableDefferredMode ()
{
  //## begin CE3D_OGL_Win_Renderer::DisableDefferredMode%1003953184.body preserve=yes
	REState.DefferredMode = false;

	if (oDefObjWH.iNumDefferredObjects())
    	RenderDefferredObjects();

  //## end CE3D_OGL_Win_Renderer::DisableDefferredMode%1003953184.body
}

void CE3D_OGL_Win_Renderer::DisableFrustumCulling ()
{
  //## begin CE3D_OGL_Win_Renderer::DisableFrustumCulling%1003953186.body preserve=yes
	REState.FrustumCulling = false;
  //## end CE3D_OGL_Win_Renderer::DisableFrustumCulling%1003953186.body
}

void CE3D_OGL_Win_Renderer::DisableNormalRender ()
{
  //## begin CE3D_OGL_Win_Renderer::DisableNormalRender%1003953188.body preserve=yes
	REState.NormalRender = false;
  //## end CE3D_OGL_Win_Renderer::DisableNormalRender%1003953188.body
}

void CE3D_OGL_Win_Renderer::EnableBBoxRender ()
{
  //## begin CE3D_OGL_Win_Renderer::EnableBBoxRender%1003953190.body preserve=yes
  	REState.BBoxRender = true;
  //## end CE3D_OGL_Win_Renderer::EnableBBoxRender%1003953190.body
}

void CE3D_OGL_Win_Renderer::EnableDefferredMode ()
{
  //## begin CE3D_OGL_Win_Renderer::EnableDefferredMode%1003953191.body preserve=yes
	REState.DefferredMode = true;
  //## end CE3D_OGL_Win_Renderer::EnableDefferredMode%1003953191.body
}

void CE3D_OGL_Win_Renderer::EnableFrustumCulling ()
{
  //## begin CE3D_OGL_Win_Renderer::EnableFrustumCulling%1003953193.body preserve=yes
	REState.FrustumCulling = true;
  //## end CE3D_OGL_Win_Renderer::EnableFrustumCulling%1003953193.body
}

void CE3D_OGL_Win_Renderer::EnableNormalRender ()
{
  //## begin CE3D_OGL_Win_Renderer::EnableNormalRender%1003953195.body preserve=yes
	REState.NormalRender = true;
  //## end CE3D_OGL_Win_Renderer::EnableNormalRender%1003953195.body
}

void CE3D_OGL_Win_Renderer::EndRender ()
{
  //## begin CE3D_OGL_Win_Renderer::EndRender%1003953197.body preserve=yes
  
	// If there are some defferred objects render them
	if (oDefObjWH.iNumDefferredObjects())
    	RenderDefferredObjects();
	
	SwapBuffers(DC);	

	// Get delta time
	REStats.DTime = (float)Chrono_EllapsedTime();
	REStats.DTimes[REStats.cDTime++] = REStats.DTime;	REStats.cDTime &= 0x03;
	
	// Compute FPS
	// REStats.FPS = 0;	for(int i=0;i<4;i++) REStats.FPS += 0.25f/REStats.DTimes[i];
	// REState.FPS = 0; for(int i=0;i<4;i++) REState.FPS += 1 / REStats.DTime[i];  REState.FPS /= 4;
    if (REStats.iCurrentFrame>3)
    	REStats.FPS = 1.0f / ((REStats.DTimes[0] + REStats.DTimes[1] + REStats.DTimes[2] + REStats.DTimes[3]) * 0.25f);
    else
        REStats.FPS = 1000.0f;

	
	// Increase total render time
	REStats.fTotalTime += REStats.DTime;

	// One more frame
	REStats.iCurrentFrame++;

  //## end CE3D_OGL_Win_Renderer::EndRender%1003953197.body
}

void CE3D_OGL_Win_Renderer::Finish ()
{
  //## begin CE3D_OGL_Win_Renderer::Finish%1003953198.body preserve=yes
	if ((GLRC) && (DC))
    {
    	// Deactivate rendering context
	    wglMakeCurrent(0,0);
        // Destroy rendering context
    	wglDeleteContext(GLRC);

		ReleaseDC(WND,DC);
    }
  //## end CE3D_OGL_Win_Renderer::Finish%1003953198.body
}

void CE3D_OGL_Win_Renderer::GetCameraMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_OGL_Win_Renderer::GetCameraMatrix%1003953200.body preserve=yes
	glGetFloatv(GL_MODELVIEW_MATRIX,M->m);
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::GetCameraMatrix%1003953200.body
}

CE3D_Shader * CE3D_OGL_Win_Renderer::poGetCurrentMaterial ()
{
  //## begin CE3D_OGL_Win_Renderer::poGetCurrentMaterial%1003953201.body preserve=yes
	return (poCurrentShader);
  //## end CE3D_OGL_Win_Renderer::poGetCurrentMaterial%1003953201.body
}

void CE3D_OGL_Win_Renderer::GetCurrentMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_OGL_Win_Renderer::GetCurrentMatrix%1003953202.body preserve=yes
	// coger directamente de OpenGL	
	glGetFloatv(GL_MODELVIEW_MATRIX,M->m);
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::GetCurrentMatrix%1003953202.body
}

void CE3D_OGL_Win_Renderer::GetProjectorMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_OGL_Win_Renderer::GetProjectorMatrix%1003953204.body preserve=yes
	glGetFloatv(GL_PROJECTION_MATRIX,M->m);
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::GetProjectorMatrix%1003953204.body
}

int CE3D_OGL_Win_Renderer::Init (void *_pHndDeviceContext, int _iOptions, int _iScrTX, int _iScrTY, int _iColorBits)
{
  //## begin CE3D_OGL_Win_Renderer::Init%1003953206.body preserve=yes
	//---------------------------------------------------------------------------
	// Begin Windows specific
	//---------------------------------------------------------------------------
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

	//---------------------------------------------------------------------------
	// End Windows specific
	//---------------------------------------------------------------------------

	//---------------------------------------------------------------------------
	// Setup openGL default state
	//---------------------------------------------------------------------------
	iScrTX = _iScrTX;
	iScrTY = _iScrTY;
	   
	// Frame buffer clear color
	glClearColor(0.5f,0.5f,0.5f,0.0f);
    
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
	glAlphaFunc(GL_GREATER,0.1f);    

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
	glEnable(GL_SHARED_TEXTURE_PALETTE_EXT);

	// -------------------------------------
	// Initialize material renderer
	// -------------------------------------
	oShaderRenderer.Init();
	return(1);	
  //## end CE3D_OGL_Win_Renderer::Init%1003953206.body
}

void CE3D_OGL_Win_Renderer::LoadIdentity ()
{
  //## begin CE3D_OGL_Win_Renderer::LoadIdentity%1003953207.body preserve=yes
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::LoadIdentity%1003953207.body
}

void CE3D_OGL_Win_Renderer::MultiplyMatrix (CMatrix4x4 *Matrix)
{
  //## begin CE3D_OGL_Win_Renderer::MultiplyMatrix%1003953208.body preserve=yes
  
	// Leaves X = MatrixStack*M
  	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(Matrix->m);
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::MultiplyMatrix%1003953208.body
}

void CE3D_OGL_Win_Renderer::PopCameraMatrix ()
{
  //## begin CE3D_OGL_Win_Renderer::PopCameraMatrix%1003953209.body preserve=yes
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::PopCameraMatrix%1003953209.body
}

void CE3D_OGL_Win_Renderer::PopMatrix ()
{
  //## begin CE3D_OGL_Win_Renderer::PopMatrix%1003953210.body preserve=yes
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::PopMatrix%1003953210.body
}

void CE3D_OGL_Win_Renderer::PopProjectorMatrix ()
{
  //## begin CE3D_OGL_Win_Renderer::PopProjectorMatrix%1003953211.body preserve=yes
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::PopProjectorMatrix%1003953211.body
}

void CE3D_OGL_Win_Renderer::PreMultiplyMatrix (CMatrix4x4 *Matrix)
{
  //## begin CE3D_OGL_Win_Renderer::PreMultiplyMatrix%1003953212.body preserve=yes

	// Leaves X = M * MatrixStack

  	float m[16];
	
	glMatrixMode (GL_MODELVIEW);
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	CONTROL_ERRORS();
	
	glLoadMatrixf(Matrix->m);
	CONTROL_ERRORS();
	
	glMultMatrixf(m);
	CONTROL_ERRORS();

  //## end CE3D_OGL_Win_Renderer::PreMultiplyMatrix%1003953212.body
}

void CE3D_OGL_Win_Renderer::PushCameraMatrix ()
{
  //## begin CE3D_OGL_Win_Renderer::PushCameraMatrix%1003953213.body preserve=yes
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::PushCameraMatrix%1003953213.body
}

void CE3D_OGL_Win_Renderer::PushMatrix ()
{
  //## begin CE3D_OGL_Win_Renderer::PushMatrix%1003953214.body preserve=yes
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::PushMatrix%1003953214.body
}

void CE3D_OGL_Win_Renderer::PushProjectorMatrix ()
{
  //## begin CE3D_OGL_Win_Renderer::PushProjectorMatrix%1003953215.body preserve=yes
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::PushProjectorMatrix%1003953215.body
}

void CE3D_OGL_Win_Renderer::RenderDefferredObjects ()
{
  //## begin CE3D_OGL_Win_Renderer::RenderDefferredObjects%1003953216.body preserve=yes
	
	// Sort meshes by material
	oDefObjWH.Sort();

	int				cObj;
	CMatrix4x4		*poMatrix;
	void			*poMesh;
	CE3D_Shader		*poShader;
	eE3D_MeshType	eMT;
	int				iLights;
	unsigned int	uiOldEnabledLights = uiEnabledLights;

	PushMatrix();
	
		// Loop throught all defferred objects
		for (cObj=0;cObj< oDefObjWH.iNumDefferredObjects();cObj++)
		{
			// Get object data
			eMT = oDefObjWH.eGetObject(cObj,poMesh,poShader,poMatrix,uiEnabledLights);

			// Setup its modelview matrix
			SetCurrentMatrix(poMatrix);		

			// Prepare for lighting
			PrepareLights();

			switch (eMT)
			{
				case eE3DMT_Mesh:
				{
					// Render bounding box
					if (REState.BBoxRender)	RenderBBox(((CMesh *)poMesh)->GetBoundVol() );

					// Render normals
					if (REState.NormalRender) RenderNormals((CMesh *)poMesh);	

					// Render					
					oShaderRenderer.Render((CMesh *)poMesh,poShader);
				}
				break;

				case eE3DMT_CompiledMesh:
				{
					// Render bounding box
					if (REState.BBoxRender)	RenderBBox(((CCompiledMesh *)poMesh)->poGetBV() );

					// Render
					oShaderRenderer.Render((CCompiledMesh *)poMesh,poShader);
				}
				break;
			}
		}

	PopMatrix();

	// Restore light state
	uiEnabledLights = uiOldEnabledLights;

	oDefObjWH.Invalidate();
  //## end CE3D_OGL_Win_Renderer::RenderDefferredObjects%1003953216.body
}

void CE3D_OGL_Win_Renderer::RenderMesh (CMesh *_poMesh, CE3D_Shader *_poShader)
{
  //## begin CE3D_OGL_Win_Renderer::RenderMesh%1003953217.body preserve=yes
  	if (! _poShader) 
		_poShader = &E3D_NULL_SHADER;

	if (REState.DefferredMode)
	{	
		// Insert deferred objects
		CMatrix4x4 M;
		GetCurrentMatrix(&M);
		oDefObjWH.InsertDefferredObject(_poMesh,eE3DMT_Mesh,_poShader,M,uiEnabledLights);
	}
	else
	{
		PrepareLights();

		if (REState.BBoxRender)		RenderBBox(_poMesh->GetBoundVol() );
		if (REState.NormalRender)	RenderNormals(_poMesh);
		
		oShaderRenderer.Render(_poMesh,_poShader);
	}

	REStats.NumRenderedGObjs++;
  //## end CE3D_OGL_Win_Renderer::RenderMesh%1003953217.body
}

void CE3D_OGL_Win_Renderer::RenderMesh (CMesh *_poMesh)
{
  //## begin CE3D_OGL_Win_Renderer::RenderMesh%1003953218.body preserve=yes
  	RenderMesh(_poMesh,NULL);
  //## end CE3D_OGL_Win_Renderer::RenderMesh%1003953218.body
}

void CE3D_OGL_Win_Renderer::RenderCompiledMesh (CCompiledMesh *_poCMesh, CE3D_Shader *_poShader)
{
  //## begin CE3D_OGL_Win_Renderer::RenderCompiledMesh%1011911187.body preserve=yes
	// Compiled meshes with NULL materials are still valid since the material 
	// definition may be inside the compiled mesh 

	if (REState.DefferredMode)
	{	
		// Insert deferred objects
		CMatrix4x4 M;
		GetCurrentMatrix(&M);
		oDefObjWH.InsertDefferredObject(_poCMesh,eE3DMT_Mesh,_poShader,M,uiEnabledLights);
	}
	else
	{
		PrepareLights();

		if (REState.BBoxRender)	RenderBBox(_poCMesh->poGetBV() );
				
		oShaderRenderer.Render(_poCMesh,_poShader);
	}

	REStats.NumRenderedGObjs++;
  //## end CE3D_OGL_Win_Renderer::RenderCompiledMesh%1011911187.body
}

void CE3D_OGL_Win_Renderer::RenderCompiledMesh (CCompiledMesh* _poCMesh)
{
  //## begin CE3D_OGL_Win_Renderer::RenderCompiledMesh%1011911188.body preserve=yes
	RenderCompiledMesh(_poCMesh,NULL);
  //## end CE3D_OGL_Win_Renderer::RenderCompiledMesh%1011911188.body
}

void CE3D_OGL_Win_Renderer::Rotate (float Angle, float v0, float v1, float v2)
{
  //## begin CE3D_OGL_Win_Renderer::Rotate%1003953219.body preserve=yes
    glRotatef(Angle,v0,v1,v2);
  //## end CE3D_OGL_Win_Renderer::Rotate%1003953219.body
}

void CE3D_OGL_Win_Renderer::RotateX (float Angle)
{
  //## begin CE3D_OGL_Win_Renderer::RotateX%1003953220.body preserve=yes
	glRotatef(Angle,1.0f,0.0f,0.0f);
  //## end CE3D_OGL_Win_Renderer::RotateX%1003953220.body
}

void CE3D_OGL_Win_Renderer::RotateY (float Angle)
{
  //## begin CE3D_OGL_Win_Renderer::RotateY%1003953221.body preserve=yes
	glRotatef(Angle,0.0f,1.0f,0.0f);
  //## end CE3D_OGL_Win_Renderer::RotateY%1003953221.body
}

void CE3D_OGL_Win_Renderer::RotateZ (float Angle)
{
  //## begin CE3D_OGL_Win_Renderer::RotateZ%1003953222.body preserve=yes
	glRotatef(Angle,0.0f,0.0f,1.0f);
  //## end CE3D_OGL_Win_Renderer::RotateZ%1003953222.body
}

void CE3D_OGL_Win_Renderer::Scale (float x, float y, float z)
{
  //## begin CE3D_OGL_Win_Renderer::Scale%1003953223.body preserve=yes
  	glScalef(x,y,z);
  //## end CE3D_OGL_Win_Renderer::Scale%1003953223.body
}

void CE3D_OGL_Win_Renderer::ScaleX (float Value)
{
  //## begin CE3D_OGL_Win_Renderer::ScaleX%1003953224.body preserve=yes
	glScalef(Value,1.0f,1.0f);
  //## end CE3D_OGL_Win_Renderer::ScaleX%1003953224.body
}

void CE3D_OGL_Win_Renderer::ScaleY (float Value)
{
  //## begin CE3D_OGL_Win_Renderer::ScaleY%1003953225.body preserve=yes
	glScalef(1.0f,Value,1.0f);
  //## end CE3D_OGL_Win_Renderer::ScaleY%1003953225.body
}

void CE3D_OGL_Win_Renderer::ScaleZ (float Value)
{
  //## begin CE3D_OGL_Win_Renderer::ScaleZ%1003953226.body preserve=yes
  	glScalef(1.0f,1.0f,Value);
  //## end CE3D_OGL_Win_Renderer::ScaleZ%1003953226.body
}

void CE3D_OGL_Win_Renderer::SetCameraMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_OGL_Win_Renderer::SetCameraMatrix%1003953228.body preserve=yes
	// copiar directamente a OpenGL
	glMatrixMode (GL_MODELVIEW);
	glLoadMatrixf(M->m);
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::SetCameraMatrix%1003953228.body
}

void CE3D_OGL_Win_Renderer::SetCurrentMaterial (CE3D_Shader *_poShader)
{
  //## begin CE3D_OGL_Win_Renderer::SetCurrentMaterial%1003953229.body preserve=yes
	poCurrentShader = _poShader;
  //## end CE3D_OGL_Win_Renderer::SetCurrentMaterial%1003953229.body
}

void CE3D_OGL_Win_Renderer::SetCurrentMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_OGL_Win_Renderer::SetCurrentMatrix%1003953230.body preserve=yes
  
	// copiar directamente a OpenGL
	glMatrixMode (GL_MODELVIEW);
	glLoadMatrixf(M->m);
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::SetCurrentMatrix%1003953230.body
}

void CE3D_OGL_Win_Renderer::SetCurrentTextureContext (TTextureObj *TexObj)
{
  //## begin CE3D_OGL_Win_Renderer::SetCurrentTextureContext%1003953231.body preserve=yes
	if (! TexObj)		return;
	if (! TexObj->MipMapObj)	return;

	if (! TexObj->MipMapObj->Handler)
    {
        // La textura no ha sido cargada en mem antes
        UploadTexture(TexObj);
        TexObj->MipMapObj->Update = false;
    }
    else
    {    	
        if (TexObj->MipMapObj->Update)
        {
            UpdateTexture(TexObj);
            TexObj->MipMapObj->Update = false;
        }
		else
		{
			// Establecer el/ contexto de la textura    	
			glBindTexture(GL_TEXTURE_2D,TexObj->MipMapObj->Handler);
			if (TexObj->MipMapObj->mipMap->lods[0]->pixelFormat == PixelFormat::PALETTE)
			{					
				glColorTableEXT(GL_SHARED_TEXTURE_PALETTE_EXT,
								GL_RGB,
								TexObj->MipMapObj->mipMap->lods[0]->palette->numColors,
								GL_RGB,
								GL_UNSIGNED_BYTE,
								TexObj->MipMapObj->mipMap->lods[0]->palette->data);
			}
		}
    }
  //## end CE3D_OGL_Win_Renderer::SetCurrentTextureContext%1003953231.body
}

void CE3D_OGL_Win_Renderer::SetProjectorMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_OGL_Win_Renderer::SetProjectorMatrix%1003953234.body preserve=yes
	// copiar directamente a OpenGL
	glMatrixMode (GL_PROJECTION);
	glLoadMatrixf(M->m);
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::SetProjectorMatrix%1003953234.body
}

void CE3D_OGL_Win_Renderer::Translate (float x, float y, float z)
{
  //## begin CE3D_OGL_Win_Renderer::Translate%1003953236.body preserve=yes
  	glTranslatef(x,y,z);
  //## end CE3D_OGL_Win_Renderer::Translate%1003953236.body
}

void CE3D_OGL_Win_Renderer::TranslateX (float Value)
{
  //## begin CE3D_OGL_Win_Renderer::TranslateX%1003953237.body preserve=yes
	glTranslatef(Value,0.0f,0.0f);
  //## end CE3D_OGL_Win_Renderer::TranslateX%1003953237.body
}

void CE3D_OGL_Win_Renderer::TranslateY (float Value)
{
  //## begin CE3D_OGL_Win_Renderer::TranslateY%1003953238.body preserve=yes
	glTranslatef(0.0f,Value,0.0f);
  //## end CE3D_OGL_Win_Renderer::TranslateY%1003953238.body
}

void CE3D_OGL_Win_Renderer::TranslateZ (float Value)
{
  //## begin CE3D_OGL_Win_Renderer::TranslateZ%1003953239.body preserve=yes
    glTranslatef(0.0f,0.0f,Value);
  //## end CE3D_OGL_Win_Renderer::TranslateZ%1003953239.body
}

void CE3D_OGL_Win_Renderer::UpdateTexture (TTextureObj *TexObj)
{
  //## begin CE3D_OGL_Win_Renderer::UpdateTexture%1003953240.body preserve=yes
	unsigned int cLOD;
	
	glBindTexture(GL_TEXTURE_2D,TexObj->MipMapObj->Handler);

	for (cLOD = 0;cLOD < TexObj->MipMapObj->mipMap->lods.size();cLOD++)
    {
		Texture* lod = TexObj->MipMapObj->mipMap->lods[cLOD];
        glTexImage2D(GL_TEXTURE_2D,
                    cLOD,
                    GetTextureInternalFormat(lod->pixelFormat),
					lod->width,
					lod->height,
                    0,
                    GetTextureFormat(lod->pixelFormat),
                    GL_UNSIGNED_BYTE,
					lod->data);
    }
	
	// Setup clut if needed
	if (TexObj->MipMapObj->mipMap->lods[0]->pixelFormat == PixelFormat::PALETTE)
	{					
		glColorTableEXT(GL_SHARED_TEXTURE_PALETTE_EXT,
						GL_RGB,
						TexObj->MipMapObj->mipMap->lods[0]->palette->numColors,
						GL_RGB,
						GL_UNSIGNED_BYTE,
						TexObj->MipMapObj->mipMap->lods[0]->palette->data);
	}
  //## end CE3D_OGL_Win_Renderer::UpdateTexture%1003953240.body
}

void CE3D_OGL_Win_Renderer::UploadTexture (TTextureObj *TexObj)
{
  //## begin CE3D_OGL_Win_Renderer::UploadTexture%1003953241.body preserve=yes
	unsigned int cLOD;

    // Generar un handler para la textura
    glGenTextures(1,&TexObj->MipMapObj->Handler);

	// Establecer el contexto de la nueva textura
    glBindTexture(GL_TEXTURE_2D, TexObj->MipMapObj->Handler);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (cLOD = 0;cLOD < TexObj->MipMapObj->mipMap->lods.size();cLOD++)
	{
		Texture* lod = TexObj->MipMapObj->mipMap->lods[cLOD];
		glTexImage2D(GL_TEXTURE_2D,
			cLOD,
			GetTextureInternalFormat(lod->pixelFormat),
			lod->width,
			lod->height,
			0,
			GetTextureFormat(lod->pixelFormat),
			GL_UNSIGNED_BYTE,
			lod->data);
	}

    // Establecer algunas propiedades para este objeto textura
    if (TexObj->UWrap == E3D_TEX_WRAP_REPEAT)
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    else
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);

    if (TexObj->VWrap == E3D_TEX_WRAP_REPEAT)
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    else
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);

    // Setup mignification filter
    switch (TexObj->MinFilter)
    {
        case E3D_TEX_MIN_FILTER_NEAREST: glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
                                         break;
        case E3D_TEX_MIN_FILTER_LINEAR:  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
                                         break;
    }

    // Setup magnification filter
    switch (TexObj->MaxFilter)
    {
        case E3D_TEX_MAX_FILTER_NEAREST: glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
                                         break;
        case E3D_TEX_MAX_FILTER_LINEAR:  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
                                         break;
    }
	
	// Setup clut if needed
	if (TexObj->MipMapObj->mipMap->lods[0]->pixelFormat == PixelFormat::PALETTE)
	{					
		glColorTableEXT(GL_SHARED_TEXTURE_PALETTE_EXT,
						GL_RGB,
						TexObj->MipMapObj->mipMap->lods[0]->palette->numColors,
						GL_RGB,
						GL_UNSIGNED_BYTE,
						TexObj->MipMapObj->mipMap->lods[0]->palette->data);
	}
  //## end CE3D_OGL_Win_Renderer::UploadTexture%1003953241.body
}

bool CE3D_OGL_Win_Renderer::UsingBBoxRender ()
{
  //## begin CE3D_OGL_Win_Renderer::UsingBBoxRender%1003953242.body preserve=yes
	return(REState.BBoxRender);
  //## end CE3D_OGL_Win_Renderer::UsingBBoxRender%1003953242.body
}

bool CE3D_OGL_Win_Renderer::UsingDefferredMode ()
{
  //## begin CE3D_OGL_Win_Renderer::UsingDefferredMode%1003953243.body preserve=yes
	return (REState.DefferredMode);    
  //## end CE3D_OGL_Win_Renderer::UsingDefferredMode%1003953243.body
}

bool CE3D_OGL_Win_Renderer::UsingFrustumCulling ()
{
  //## begin CE3D_OGL_Win_Renderer::UsingFrustumCulling%1003953245.body preserve=yes
  	return(REState.FrustumCulling);
  //## end CE3D_OGL_Win_Renderer::UsingFrustumCulling%1003953245.body
}

bool CE3D_OGL_Win_Renderer::UsingNormalRender ()
{
  //## begin CE3D_OGL_Win_Renderer::UsingNormalRender%1003953247.body preserve=yes
  return (REState.NormalRender);
  //## end CE3D_OGL_Win_Renderer::UsingNormalRender%1003953247.body
}

void CE3D_OGL_Win_Renderer::UpdateViewing ()
{
  //## begin CE3D_OGL_Win_Renderer::UpdateViewing%1003953258.body preserve=yes
  //## end CE3D_OGL_Win_Renderer::UpdateViewing%1003953258.body
}

void CE3D_OGL_Win_Renderer::SetViewport (CE3D_Viewport *_Viewport)
{
  //## begin CE3D_OGL_Win_Renderer::SetViewport%1003953259.body preserve=yes
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
	CONTROL_ERRORS();

	glScissor (Viewport->ScrCX*iScrTX,
			   Viewport->ScrCY*iScrTY,
			   Viewport->ScrTX*iScrTX,
			   Viewport->ScrTY*iScrTY);
	CONTROL_ERRORS();

	if (Projector)
		Frustum.Compute(Projector,fAspectRatio);
  //## end CE3D_OGL_Win_Renderer::SetViewport%1003953259.body
}

CE3D_Viewport * CE3D_OGL_Win_Renderer::GetViewport ()
{
  //## begin CE3D_OGL_Win_Renderer::GetViewport%1003953260.body preserve=yes
	return(Viewport);
  //## end CE3D_OGL_Win_Renderer::GetViewport%1003953260.body
}

void CE3D_OGL_Win_Renderer::SetCamera (CE3D_Camera *_Camera)
{
  //## begin CE3D_OGL_Win_Renderer::SetCamera%1003953261.body preserve=yes
	if (! _Camera) return;
	Camera = _Camera;
	
	// Camera matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	CONTROL_ERRORS();

    gluLookAt(	Camera->Pos.v[0],
				Camera->Pos.v[1],
				Camera->Pos.v[2],
    			Camera->Pos.v[0]+Camera->Dir.v[0],
				Camera->Pos.v[1]+Camera->Dir.v[1],
				Camera->Pos.v[2]+Camera->Dir.v[2],
    			Camera->Up.v[0],
				Camera->Up.v[1],
				Camera->Up.v[2]);
	CONTROL_ERRORS();
  //## end CE3D_OGL_Win_Renderer::SetCamera%1003953261.body
}

CE3D_Camera * CE3D_OGL_Win_Renderer::GetCamera ()
{
  //## begin CE3D_OGL_Win_Renderer::GetCamera%1003953262.body preserve=yes
	return(Camera);
  //## end CE3D_OGL_Win_Renderer::GetCamera%1003953262.body
}

void CE3D_OGL_Win_Renderer::SetProjector (CE3D_Projector *_Projector)
{
  //## begin CE3D_OGL_Win_Renderer::SetProjector%1003953263.body preserve=yes
	if (!_Projector) return;

	Projector   = _Projector;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	CONTROL_ERRORS();

	switch (Projector->ePrjType)
	{
		case eE3DPrjType_Perspective:	
		{			
			/*
			glFrustum( -tan(Projector->fFOV*_PI_OVER_180)*fAspectRatio,
					    tan(Projector->fFOV*_PI_OVER_180)*fAspectRatio,
    				   -tan(Projector->fFOV*_PI_OVER_180),			    
						tan(Projector->fFOV*_PI_OVER_180),
						Projector->fNear,Projector->fFar);
			*/			

			gluPerspective(Projector->fFOV,fAspectRatio,Projector->fNear,Projector->fFar);
			CONTROL_ERRORS();
		}
		break;

		case eE3DPrjType_Orthogonal:
		{
			glOrtho(-0.5f*fAspectRatio,
					 0.5f*fAspectRatio,
					 0.5f,
					-0.5f,
					 Projector->fNear,Projector->fFar);
			CONTROL_ERRORS();
		}
		break;
	}

	Frustum.Compute(Projector,fAspectRatio);	
  //## end CE3D_OGL_Win_Renderer::SetProjector%1003953263.body
}

CE3D_Projector * CE3D_OGL_Win_Renderer::GetProjector ()
{
  //## begin CE3D_OGL_Win_Renderer::GetProjector%1003953264.body preserve=yes
	return(Projector);
  //## end CE3D_OGL_Win_Renderer::GetProjector%1003953264.body
}

void CE3D_OGL_Win_Renderer::SetScreenSize (int _iScrTX, int _iScrTY)
{
  //## begin CE3D_OGL_Win_Renderer::SetScreenSize%1006393129.body preserve=yes
  	iScrTX = _iScrTX;
	iScrTY = _iScrTY;

	SetViewport(Viewport);	
  //## end CE3D_OGL_Win_Renderer::SetScreenSize%1006393129.body
}

CCompiledMesh * CE3D_OGL_Win_Renderer::poCompileMesh (CMesh *_poMesh, CE3D_Shader *_poShader)
{
  //## begin CE3D_OGL_Win_Renderer::poCompileMesh%1011911189.body preserve=yes
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

  //## end CE3D_OGL_Win_Renderer::poCompileMesh%1011911189.body
}

void CE3D_OGL_Win_Renderer::DestroyCompiledMesh (CCompiledMesh *_poCMesh)
{
  //## begin CE3D_OGL_Win_Renderer::DestroyCompiledMesh%1011911201.body preserve=yes
	
	// List and object will longer no be available
	glDeleteLists(_poCMesh->iID,1);
	mDel _poCMesh;

  //## end CE3D_OGL_Win_Renderer::DestroyCompiledMesh%1011911201.body
}

void CE3D_OGL_Win_Renderer::SetupPalette (TPixelFormatDescriptor PFD)
{
  //## begin CE3D_OGL_Win_Renderer::SetupPalette%983399603.body preserve=yes
  	int nColors,i;
    TLogPalette  *lpPalette;
    unsigned char byRedMask,byGreenMask,byBlueMask;
    HPALETTE Palette;

	nColors =1 << PFD.cColorBits;

    lpPalette = (TLogPalette *) malloc(sizeof(TLogPalette)+(nColors*sizeof(TPaletteEntry)));

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

	free(lpPalette);
  //## end CE3D_OGL_Win_Renderer::SetupPalette%983399603.body
}

void CE3D_OGL_Win_Renderer::EnableFlatRendering ()
{
  //## begin CE3D_OGL_Win_Renderer::EnableFlatRendering%1018547526.body preserve=yes
	REState.FlatRender = true;

	glDisable	(GL_TEXTURE_2D);
	glShadeModel(GL_FLAT);
	glDisable	(GL_BLEND);

	if (uiEnabledLights)
		glDisable(GL_LIGHTING);

	glClearColor(1.0f,1.0f,1.0f,0.0f);
	glColor4f(0.5f,0.5f,0.5f,0.0f);
  //## end CE3D_OGL_Win_Renderer::EnableFlatRendering%1018547526.body
}

void CE3D_OGL_Win_Renderer::DisableFlatRendering ()
{
  //## begin CE3D_OGL_Win_Renderer::DisableFlatRendering%1018547527.body preserve=yes
	REState.FlatRender = false;
	
	glEnable	(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glEnable	(GL_BLEND);
	
	if (uiEnabledLights)
		glEnable(GL_LIGHTING);

	glClearColor(0.5f,0.5f,0.5f,0.0f);
	glColor4f(1.0f,1.0f,1.0f,0.0f);
  //## end CE3D_OGL_Win_Renderer::DisableFlatRendering%1018547527.body
}

bool CE3D_OGL_Win_Renderer::UsingFlatRendering ()
{
  //## begin CE3D_OGL_Win_Renderer::UsingFlatRendering%1018547528.body preserve=yes
	return(REState.FlatRender);
  //## end CE3D_OGL_Win_Renderer::UsingFlatRendering%1018547528.body
}

void CE3D_OGL_Win_Renderer::ReadBuffer (int _iX, int _iY, int _iTX, int _iTY, eE3D_RenderBuffer_Type _eBufferType, void* _pData)
{
  //## begin CE3D_OGL_Win_Renderer::ReadBuffer%1018547529.body preserve=yes
	switch (_eBufferType)
	{
		case eE3D_RB_Front:	
		{
			glReadBuffer(GL_FRONT);
			glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE,_pData);
			return;
		}
				
		case eE3D_RB_Back:
		{
			glReadBuffer(GL_BACK);
			glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE,_pData);
			return;
		}
		case eE3D_RB_Z:
		{
			glReadBuffer(GL_DEPTH);
			glReadPixels(_iX,_iY,_iTX,_iTY,GL_DEPTH_COMPONENT,GL_UNSIGNED_INT,_pData);
			return;
		}

		case eE3D_RB_Stencil:
		{
			glReadBuffer(GL_STENCIL);
			glReadPixels(_iX,_iY,_iTX,_iTY,GL_STENCIL_INDEX,GL_UNSIGNED_BYTE,_pData);
			return;
		}
	}	
  //## end CE3D_OGL_Win_Renderer::ReadBuffer%1018547529.body
}

void CE3D_OGL_Win_Renderer::WriteBuffer (int _iX, int _iY, int _iTX, int _iTY, eE3D_RenderBuffer_Type _eBufferType, void* _pData)
{
  //## begin CE3D_OGL_Win_Renderer::WriteBuffer%1018547530.body preserve=yes

/*
	void glDrawPixels(
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
  
	const GLvoid *pixels)	switch (_eBufferType)
	{
		case eE3D_RB_Front:	
		{
			glReadBuffer(GL_FRONT);
			glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE);
			return;
		}
				
		case eE3D_RB_Back:
		{
			glReadBuffer(GL_BACK);
			glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE);
			return;
		}
		case eE3D_RB_Z:
		{
			glReadBuffer(GL_DEPTH_BUFFER);
			glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE);
			return;
		}

		case eE3D_RB_Stencil:
		{
			glReadBuffer(GL_STENCIL_BUFFER);
			glReadPixels(_iX,_iY,_iTX,_iTY,GL_RGBA,GL_UNSIGNED_BYTE);
			return;
		}
	}
*/
  //## end CE3D_OGL_Win_Renderer::WriteBuffer%1018547530.body
}

void CE3D_OGL_Win_Renderer::SetStencilParams (bool _bEnable, eE3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, eE3D_StencilAction _eSFails, eE3D_StencilAction _eZFails, eE3D_StencilAction _eZPass)
{
  //## begin CE3D_OGL_Win_Renderer::SetStencilParams%1018547531.body preserve=yes
	eE3D_StencilFunc	eSFAux;

	// ---------------------------
	// Handle first special cases:
	// ---------------------------

	// Last 
	if (_eStencilFunc == eE3D_SF_Last)
	{
		if ((eStencilFunc == eE3D_SF_None) && (eStencilFuncLast != eE3D_SF_None))
			glEnable(GL_STENCIL_TEST);
		else
		{
			if ((eStencilFunc != eE3D_SF_None) && (eStencilFuncLast == eE3D_SF_None))
				glDisable(GL_STENCIL_TEST);
		}
		
		eStencilFunc = eStencilFuncLast;
		return;
	}

	// Disable
	if (_eStencilFunc == eE3D_SF_None)
	{
		// Disable ?
		if (eStencilFunc != eE3D_SF_None)
		{
			eStencilFuncLast= eStencilFunc;
			eStencilFunc    = eE3D_SF_None;
			glDisable(GL_STENCIL_TEST);
		}
		
		return;
	}

	// Current
	if (_eStencilFunc != eE3D_SF_Current)
	{
		// Enable function
		if (eStencilFunc == eE3D_SF_None) glEnable(GL_STENCIL_TEST);
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
  //## end CE3D_OGL_Win_Renderer::SetStencilParams%1018547531.body
}

void CE3D_OGL_Win_Renderer::SetZPars (eE3D_ZTestFunc _eZTest, eE3D_ZWrite _eZWrite)
{
  //## begin CE3D_OGL_Win_Renderer::SetZPars%1018547536.body preserve=yes
	if (_eZTest != eE3D_ZTF_Current)
	{
		// Disable ?	
		if (_eZTest == eE3D_ZTF_None)
		{
			// Is enabled?
			if (eZTest != _eZTest)
			{		
				eZTestLast = eZTest;
				eZTest     = eE3D_ZTF_None;
				glDisable(GL_DEPTH_TEST);
			}
		}
		else
		{
			if (_eZTest == eE3D_ZTF_Last) _eZTest = eZTestLast;
			
			// Enable function
			if (eZTest == eE3D_ZTF_None) glEnable(GL_DEPTH_TEST);

			// Set pars
			glDepthFunc(eGetDepthFunc(_eZTest));

			eZTest	   = _eZTest;
			eZTestLast = eZTest;			
		}
	}


	if (_eZWrite != eE3D_ZW_Current)
	{
		// Disable ?	
		if (_eZWrite == eE3D_ZW_Disable)
		{	
			// Is enabled?
			if (eZWrite == eE3D_ZW_Enable)
			{		
				eZWriteLast = eE3D_ZW_Enable;
				eZWrite     = eE3D_ZW_Disable;
				glDepthMask(GL_FALSE);
			}
		}
   else if (_eZWrite == eE3D_ZW_Enable)
		{
			// Is disabled?
			if (eZWrite == eE3D_ZW_Disable)
			{							
				eZWriteLast = eE3D_ZW_Disable;
				eZWrite     = eE3D_ZW_Enable;
				glDepthMask(GL_TRUE);
			}
		}
	else if  (_eZWrite == eE3D_ZW_Last)
		{
			// Is disabled?
			eZWrite     = eZWriteLast;			
		
			if (eZWriteLast == eE3D_ZW_Enable)
				glDepthMask(GL_TRUE);
			else
				glDepthMask(GL_FALSE);
		}
	}
  //## end CE3D_OGL_Win_Renderer::SetZPars%1018547536.body
}

void CE3D_OGL_Win_Renderer::MaskChannels (bool _bR, bool _bG, bool _bB, bool _bA)
{
  //## begin CE3D_OGL_Win_Renderer::MaskChannels%1018623772.body preserve=yes
	glColorMask(_bR,_bG,_bB,_bA);
  //## end CE3D_OGL_Win_Renderer::MaskChannels%1018623772.body
}

void CE3D_OGL_Win_Renderer::SetFogPars (eE3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, TFColor* _poColor)
{
  //## begin CE3D_OGL_Win_Renderer::SetFogPars%1018623773.body preserve=yes
	
	// ---------------------------
	// Handle first special cases:
	// ---------------------------

	// Last 
	if (_eFogMode == eE3D_FM_Last)
	{
		if ((eFogMode == eE3D_FM_None) && (eFogModeLast != eE3D_FM_None))
			glEnable(GL_FOG);
		else
		{
			if ((eFogMode != eE3D_FM_None) && (eFogModeLast == eE3D_FM_None))
				glDisable(GL_FOG);
		}
		
		eFogMode = eFogModeLast;
		return;
	}
	
	// Disable
	if (_eFogMode == eE3D_FM_None)
	{
		// Disable ?	
		if (eFogMode != eE3D_FM_None)
		{
			eFogModeLast= eFogMode;
			eFogMode    = eE3D_FM_None;
			glDisable(GL_FOG);								
		}
		
		return;
	}

	// Current
	if (_eFogMode != eE3D_FM_Current)
	{
		// Enable function
		if (eFogMode == eE3D_FM_None) glEnable(GL_FOG);		
		glFogf (GL_FOG_MODE,eGetFogMode(_eFogMode));	
	}

	// Set the fog parameters
	glFogf  (GL_FOG_START,_fStart);
	glFogf  (GL_FOG_END  ,_fEnd);
	glFogf  (GL_FOG_DENSITY,_fDensity);
	glFogfv (GL_FOG_COLOR,(float *)_poColor	);

	eFogMode	= _eFogMode;
	eFogModeLast= _eFogMode;
  //## end CE3D_OGL_Win_Renderer::SetFogPars%1018623773.body
}

void CE3D_OGL_Win_Renderer::ClearBuffer (eE3D_RenderBuffer_Type _eBuffer)
{
  //## begin CE3D_OGL_Win_Renderer::ClearBuffer%1018623775.body preserve=yes
	switch (_eBuffer)
	{
		case eE3D_RB_Front:
		case eE3D_RB_Back:		glClear(GL_COLOR_BUFFER_BIT);
								return;
		case eE3D_RB_Z:			glClear(GL_DEPTH_BUFFER_BIT);
								return;
		case eE3D_RB_Stencil:	glClear(GL_STENCIL_BUFFER_BIT);
								return;
		default:
				return;				
	}
  //## end CE3D_OGL_Win_Renderer::ClearBuffer%1018623775.body
}

void CE3D_OGL_Win_Renderer::SetupLight (int _iLightID, CE3D_Light& _roLight)
{
  //## begin CE3D_OGL_Win_Renderer::SetupLight%1032001950.body preserve=yes
	switch (_roLight.eType)
	{
		case LT_Point:
		{
			oLPos[_iLightID].v[0] = _roLight.oPos.v[0];
			oLPos[_iLightID].v[1] = _roLight.oPos.v[1];
			oLPos[_iLightID].v[2] = _roLight.oPos.v[2];
			oLPos[_iLightID].v[3] = 1.0f;
		}
		break;

		case LT_Directional:
			oLPos[_iLightID].v[0] = _roLight.oDir.v[0];
			oLPos[_iLightID].v[1] = _roLight.oDir.v[1];
			oLPos[_iLightID].v[2] = _roLight.oDir.v[2];
			oLPos[_iLightID].v[3] = 0.0f;
		break;

		case LT_Spot:
			/*
			glLightf (eLightID, GL_SPOT_CUTOFF			,_roLight.fSpCutOff);
			glLightfv(eLightID, GL_SPOT_DIRECTION		,_roLight.oSpDir.v);
			glLightfv(eLightID, GL_SPOT_EXPONENT		,fPos);	
			*/
		break;
	}

	
	GLenum	eLightID = eGetLightID(_iLightID);


	// ---------------------------------------
	/*
	glPushMatrix();
	glLoadIdentity();
	glLightfv(eLightID,GL_POSITION,oLPos[_iLightID].v);
	glPopMatrix();
	*/
	// ---------------------------------------

	

	glLightfv(eLightID, GL_AMBIENT	,(float*)&_roLight.oLitAmb );
	glLightfv(eLightID, GL_DIFFUSE	,(float*)&_roLight.oLitDiff);
	glLightfv(eLightID, GL_SPECULAR	,(float*)&_roLight.oLitSpec);

	glLightf (eLightID, GL_CONSTANT_ATTENUATION	,_roLight.fCAtt);
	glLightf (eLightID, GL_LINEAR_ATTENUATION	,_roLight.fLAtt);
	glLightf (eLightID, GL_QUADRATIC_ATTENUATION,_roLight.fQAtt);
  //## end CE3D_OGL_Win_Renderer::SetupLight%1032001950.body
}

void CE3D_OGL_Win_Renderer::SetLight (int _iLightID, bool _bEnable)
{
  //## begin CE3D_OGL_Win_Renderer::SetLight%1032019131.body preserve=yes
	if (_bEnable)
	{
		uiEnabledLights |= (1<<_iLightID);
	}
	else
	{
		glDisable(eGetLightID(_iLightID));
		uiEnabledLights &= ~(1<<_iLightID);
	}
  //## end CE3D_OGL_Win_Renderer::SetLight%1032019131.body
}

// Additional Declarations
  //## begin CE3D_OGL_Win_Renderer%3A9AB8C503B6.declarations preserve=yes
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
				glLightfv(eGetLightID(iL),GL_POSITION,oLPos[iL].v);				
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
  //## end CE3D_OGL_Win_Renderer%3A9AB8C503B6.declarations
//## begin module%3A9AB8C503B6.epilog preserve=yes
//## end module%3A9AB8C503B6.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CE3D_OGL_Win_Renderer::DisableLighting%1003953187.body preserve=no
//## end CE3D_OGL_Win_Renderer::DisableLighting%1003953187.body

#endif
