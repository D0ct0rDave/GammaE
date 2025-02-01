// ----------------------------------------------------------------------------
#include <windows.h>
#include "CLoop.h"
#include "GammaE.h"

// ----------------------------------------------------------------------------
typedef struct TLoopGlobals
{
	HWND m_hWnd;
	uint m_uiScrWidth;
	uint m_uiScrHeight;
	float m_fTime;
	CGChrono m_oChrono;
}TLoopGlobals;

static TLoopGlobals globals;

CE3D_Viewport		    Viewport;
CE3D_Camera			    PerspCam;
CE3D_Projector		    PerspPrj;
CObject3D_Camera        gCamera;
CObject3D*				gpoScene = NULL;
// ----------------------------------------------------------------------------
void CLoop::Init(void* _hWnd)
{
	globals.m_hWnd = (HWND)_hWnd;
	RECT Rect;
	GetWindowRect(globals.m_hWnd,&Rect);

	// Initialize some objects in the system
	CE3D_ShaderWH::I()->Init(256);
	CE3D_ShaderDefFileWH::I()->Init(10);
	CE3D_ShaderDefWH::I()->Init(100);
	CMipMapWH::I()->Init(100);
	CTexObjWH::I()->Init(100);

	globals.m_uiScrWidth  = Rect.right - Rect.left;
	globals.m_uiScrHeight = Rect.bottom - Rect.top;

    CGRenderer::I()->Init(globals.m_hWnd,E3D_RENDERER_OP_GDI | E3D_RENDERER_OP_DBUFFER,globals.m_uiScrWidth,globals.m_uiScrHeight,32);

	Viewport.ScrCX = 0.0f;
    Viewport.ScrCY = 0.0f;
    Viewport.ScrTX = 1.0f;
    Viewport.ScrTY = 1.0f;

    // La orientacion de la cámara se determina utilizando 3 vectores
    // que son los ejes locales de la cámara
	// PerspCam.Pos.V3 ( 4, 10,270);
	PerspCam.Pos.V3 ( 0.0f,-20.0f,0.0f);

    PerspCam.Up.V3  ( 0, 0,   1);
	PerspCam.Dir.V3 ( 0, 1,   0);	PerspCam.Dir.Normalize();
	PerspCam.Side.CrossProd(PerspCam.Dir,PerspCam.Up);

	PerspPrj.ePrjType = eE3DPrjType_Perspective;
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
	CGRenderer::I()->SetZPars(eE3D_ZTF_LEqual,eE3D_ZW_Enable);

  	gCamera.Init	    (100);
	gCamera.SetCamera   (&PerspCam);
	gCamera.SetProjector(&PerspPrj);
	gCamera.SetViewport (&Viewport);

    // gCamera.iAddObject(NULL);

//	AppLoop_SetupKeyBindings();
//	AppLoop_SetupCallbackFuncs();

//   RTimer->Enabled = true;
//   tb_SizeChange(NULL);
    
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
	}	
}
// ----------------------------------------------------------------------------
void CLoop::Render()
{
	if (CGRenderer::I() == NULL) return;
    // AppLoop_ControlCommands();

	// World think entities
 	CGColor oColor(0.2f,0,0,1);
    CGRenderer::I()->BeginRender();
    CGRenderer::I()->SetFogPars(eE3D_FM_Linear,0.1f,1000.0f,0.01f,&oColor);
   
	
		// Render camera scene
		gCamera.PreRender();

            if (gpoScene)
                gpoScene->Render();

        gCamera.PostRender();

    CGRenderer::I()->EndRender();
}
// ----------------------------------------------------------------------------
void CLoop::LoadGTS(char* _szFilename,char* _szDirectory)
{
	#ifdef WIN32
	char szCurDir[1024];
	GetCurrentDirectory(1024,szCurDir);
	SetCurrentDirectory(_szDirectory);
	#endif
	

	SCNUt_TriSceneLoader oLoader;
	SCNUt_TriScene* poScn = oLoader.poLoad(_szFilename);

	if (poScn)
	{
		SCNUt_MaterialTable oMatTable;
		oMatTable.Init(1000);

		for (int iMat=0;iMat<oLoader.iNumMaterials;iMat++)
		{
			CE3D_Shader* poShader = CE3D_ShaderWH::I()->poCreateShader( oLoader.pszMaterials[iMat] );
			if (poShader == NULL)
			{
				char szStr[256];
				sprintf(szStr,"Material%d",iMat);

				CGColor oColor;

				oColor.r = MATH_Common::fRand();
				oColor.g = 0;
				oColor.b = 0;
				oColor.a = 1;

				poShader = CE3D_ShaderUtils::poGenerateShaderFromColor(oColor,szStr);
			}

			oMatTable.iAdd( poShader, oLoader.pszMaterials[iMat]);
		}

		// Generate the bsp: This may take a while...
		SCNUt_SceneBuilder	oScnBuild;
		CGraphBV_Manager::SetBVMode(eGraphBV_Box);
		gpoScene = oScnBuild.poBuildScene(*poScn,oMatTable);
		gpoScene->ComputeBoundVol();
}
    


   	#ifdef WIN32
	SetCurrentDirectory(szCurDir);
	#endif
}
// ----------------------------------------------------------------------------
