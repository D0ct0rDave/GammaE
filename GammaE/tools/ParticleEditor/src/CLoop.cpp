// ----------------------------------------------------------------------------
#include <windows.h>
#include "CLoop.h"
#include "CGlobals.h"
#include "GammaE.h"
// ----------------------------------------------------------------------------
CE3D_Viewport		    Viewport;
CE3D_Camera			    PerspCam;
CE3D_Projector		    PerspPrj;
CObject3D_Camera        gCamera;
CObject3D*				gpoScene = NULL;
uint					guiPSGIdx = -1;
// ----------------------------------------------------------------------------
void CLoop::Init(void* _hWnd)
{
	globals.m_hWnd = (HWND)_hWnd;
	RECT Rect;
	GetWindowRect(globals.m_hWnd,&Rect);

	// Initialize some objects in the system
	globals.m_uiScrWidth  = Rect.right - Rect.left;
	globals.m_uiScrHeight = Rect.bottom - Rect.top;

    CGRenderer::I()->Init(globals.m_hWnd,E3D_RENDERER_OP_DBUFFER,globals.m_uiScrWidth,globals.m_uiScrHeight,32);

	Viewport.ScrCX = 0.0f;
    Viewport.ScrCY = 0.0f;
    Viewport.ScrTX = 1.0f;
    Viewport.ScrTY = 1.0f;

    // La orientacion de la cámara se determina utilizando 3 vectores
    // que son los ejes locales de la cámara
	// PerspCam.Pos.V3 ( 4, 10,270);
	PerspCam.Pos.V3 ( 0.0f,-10.0f,0.0f);

    PerspCam.Up.V3  ( 0, 0,   1);
	PerspCam.Dir.V3 ( 0, 1,   0);	PerspCam.Dir.Normalize();
	PerspCam.Side.CrossProd(PerspCam.Dir,PerspCam.Up);


	PerspPrj.ePrjType = E3D_PT_Perspective;
	PerspPrj.fFOV     = 45.0f;
    PerspPrj.fNear    = 1.0f;
    PerspPrj.fFar     = 2000.0f;

	// -------------------------------
	// Orthographic projection camnera
	// -------------------------------
    CGRenderer::I()->SetViewport (&Viewport);
    CGRenderer::I()->SetCamera   (&PerspCam);
	CGRenderer::I()->SetProjector(&PerspPrj);

    CGRenderer::I()->DisableFrustumCulling();
	CGRenderer::I()->SetZPars(E3D_ZTF_LEqual,E3D_ZW_Enable);

  	gCamera.Init	    (100);
	gCamera.SetCamera   (&PerspCam);
	gCamera.SetProjector(&PerspPrj);
	gCamera.SetViewport (&Viewport);

	CE3D_ShaderDefFileWH::I()->iLoad("data/Shaders.txt");
	CE3D_ShaderDefFileWH::I()->iLoad("data/particleshaders.txt");

	CGPSGDefFileWH::I()->iLoad("data/particles.def");

    // gCamera.iAddObject(NULL);

//	AppLoop_SetupKeyBindings();
//	AppLoop_SetupCallbackFuncs();

//   RTimer->Enabled = true;
//   tb_SizeChange(NULL);

	// Color
	CGColor oIColor(0,0,0,1);
	CGColor oFColor(1,1,1,0);
	float fIRFactor = 0.0f;
	float fFRFactor = 0.0f;
	
	// Size
	float fISize    = 0.20f;
	float fFSize	= 1.0f;
	float fIRSize   = 0.0f;
	float fFRSize	= 0.0f;
	
	// Angle
	float fIAngle	= 0.0f;
	float fFAngle   = 1.0f;
	float fIRAngle  = 1.0f;
	float fFRAngle  = 1.0f;
	
	// Dimensions
	float fIRadius  = 0.0f;
	float fFRadius  = 1.0f;
	float fIRRadius = 0.0f;
	float fFRRadius = 0.0f;

	globals.m_poPSGQ = mNew CGPSGGenericQuad();
	guiPSGIdx = CGPSysGenWH::I()->uiAdd(globals.m_poPSGQ,"test");

	globals.m_poPSGQ->SetMaxParticles(2000);
	globals.m_poPSGQ->SetEnergyFact(0.5f,0.5f);
	globals.m_poPSGQ->SetColorsPars(oIColor,oFColor,fIRFactor,fFRFactor);
	globals.m_poPSGQ->SetSizePars(fISize,fFSize,fIRSize,fFRSize);
	globals.m_poPSGQ->SetAnglePars(fIAngle,fFAngle,fIRAngle,fFRAngle);
	globals.m_poPSGQ->SetRadiusPars(fIRadius,fFRadius,fIRRadius,fFRRadius);
	globals.m_poPSGQ->SetShader( CE3D_ShaderWH::I()->poCreateShader("particletex0") );

    CVect3 oPos(0,0,0);
    CGPSIManager::I()->uiCreatePool("test",1);
	CGPSIManager::I()->poGet("test",1e6,oPos);

	gpoScene = CGPSIManager::I()->poGetNode();

    globals.m_fTime = 0.0f;
}
// ----------------------------------------------------------------------------
void CLoop::Loop()
{
	globals.m_oChrono.Stop();
	float fDeltaT  = globals.m_oChrono.dElapsedTime();
	globals.m_oChrono.Reset();
	globals.m_oChrono.Start();	

	Update(fDeltaT);
	Render();
}
// ----------------------------------------------------------------------------
void CLoop::Update(float _fDeltaT)
{
	globals.m_fTime += _fDeltaT;

	if (gpoScene != NULL)
	{
		/*
		const float FREQ = 1.0f/4.0f;
		float fAngle = globals.m_fTime*FREQ;
		
		CVect3 oCenter= gpoScene->poGetBoundVol()->GetCenter();
		CVect3 oRange = gpoScene->poGetBoundVol()->GetExtents();
		CVect3 oPos;
		
		float fAmplitude = oRange.fModule() * 2.0f;
		
		oPos.x = oCenter.x + fAmplitude*MATH_Common::fSin(fAngle);
		oPos.y = oCenter.y + fAmplitude*MATH_Common::fCos(fAngle);
		oPos.y = oCenter.z ;

		PerspCam.SetPos(oPos.x,oPos.y,oPos.z);
		PerspCam.LookAt(oCenter);
		*/
	}	
}
// ----------------------------------------------------------------------------
void CLoop::Render()
{
	if (CGRenderer::I() == NULL) return;
    // AppLoop_ControlCommands();

	// World think entities
 	CGColor oColor(0,0,0,1);
    CGRenderer::I()->BeginRender();
    CGRenderer::I()->SetFogPars(E3D_FM_Linear,0.1f,1000.0f,0.01f,&oColor);
    // CGRenderer::I()->EnableBBoxRender();
	
		// Render camera scene
		gCamera.PreRender();

            if (gpoScene)
                gpoScene->Render();

        gCamera.PostRender();

    CGRenderer::I()->EndRender();
}
// ----------------------------------------------------------------------------
void CLoop::LoadGEM(char* _szFilename)
{
	/*
	#ifdef WIN32
	char szCurDir[1024];
	GetCurrentDirectory(1024,szCurDir);
	CGString sDir  = ExtractFileDir ( CGString(_szFilename) );
	CGString sFile = ExtractFileName( CGString(_szFilename) );
	SetCurrentDirectory( sDir.szString() );
	#endif

	CLoaderGEM oLoader;
	gpoScene = oLoader.pLoad( (char*)sFile.szString() );
	gpoScene->ComputeBoundVol();

   	#ifdef WIN32
	SetCurrentDirectory(szCurDir);
	#endif
	*/
}
// ----------------------------------------------------------------------------
