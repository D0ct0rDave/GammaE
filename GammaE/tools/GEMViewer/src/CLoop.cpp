// ----------------------------------------------------------------------------
#include <windows.h>
#include "CLoop.h"
#include "GammaE.h"
#include "Collision/CGColliderDefinitionFileWH.h"
#include "CLoopCB.h"
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

// ----------------------------------------------------------------------------
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
	globals.m_uiScrWidth  = Rect.right - Rect.left;
	globals.m_uiScrHeight = Rect.bottom - Rect.top;

    CGRenderer::I()->Init(globals.m_hWnd,E3D_RENDERER_OP_GDI | E3D_RENDERER_OP_DBUFFER,globals.m_uiScrWidth,globals.m_uiScrHeight,32);


	CE3D_ShaderDefFileWH::I()->iLoad("data/Shaders.txt");
	CE3D_ShaderDefFileWH::I()->iLoad("data/particleshaders.txt");
	CGColliderDefinitionFileWH::I()->iLoad("data/colliders.def");

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

    // gCamera.iAddObject(NULL);

//	AppLoop_SetupKeyBindings();
//	AppLoop_SetupCallbackFuncs();

//   RTimer->Enabled = true;
//   tb_SizeChange(NULL);
    	
	// Setup loop callbacks
	Register();
	CLoopCB::Init();

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
 	CGColor oColor(0,0,0,1);
    CGRenderer::I()->BeginRender();
    CGRenderer::I()->SetFogPars(E3D_FM_Linear,0.1f,1000.0f,0.01f,&oColor);
    CGRenderer::I()->EnableBBoxRender();
	
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
}
// ----------------------------------------------------------------------------
void CLoop::Register()
{
	// ---------------------------------------------------
	// Register Input Names: The application registers the inputs it recognizes
	// ---------------------------------------------------
	CGInputRegistry::I()->Register("UP",		38);
	CGInputRegistry::I()->Register("DOWN",		40);
	CGInputRegistry::I()->Register("LEFT",		37);
	CGInputRegistry::I()->Register("RIGHT",		39);
	CGInputRegistry::I()->Register("TAB",		9);
	CGInputRegistry::I()->Register("ENTER" ,	13);
	CGInputRegistry::I()->Register("ESCAPE",	27);
	CGInputRegistry::I()->Register("SPACE",		32);
	CGInputRegistry::I()->Register("BACKSPACE",	8);
	CGInputRegistry::I()->Register("CTRL",		17);
	CGInputRegistry::I()->Register("F1",		112);
	CGInputRegistry::I()->Register("F2",		113);
	CGInputRegistry::I()->Register("F3",		114);
	CGInputRegistry::I()->Register("F4",		115);
	CGInputRegistry::I()->Register("F5",		116);
	CGInputRegistry::I()->Register("F6",		117);
	CGInputRegistry::I()->Register("F7",		118);
	CGInputRegistry::I()->Register("F8",		119);
	CGInputRegistry::I()->Register("F9",		120);
	CGInputRegistry::I()->Register("F10",		121);	// no chuta!!!!
	CGInputRegistry::I()->Register("F11",		122);
	CGInputRegistry::I()->Register("F12",		123);	
	CGInputRegistry::I()->Register("º",  		220);
	CGInputRegistry::I()->Register("~",  		220);	// tecla º,ª y contrabarra
	CGInputRegistry::I()->Register(".",  		190);
	CGInputRegistry::I()->Register("/",  		111);
	CGInputRegistry::I()->Register("A",			'A');
	CGInputRegistry::I()->Register("B",			'B');
	CGInputRegistry::I()->Register("C",			'C');
	CGInputRegistry::I()->Register("D",			'D');
	CGInputRegistry::I()->Register("E",			'E');
	CGInputRegistry::I()->Register("F",			'F');
	CGInputRegistry::I()->Register("G",			'G');
	CGInputRegistry::I()->Register("H",			'H');
	CGInputRegistry::I()->Register("I",			'I');
	CGInputRegistry::I()->Register("J",			'J');
	CGInputRegistry::I()->Register("K",			'K');
	CGInputRegistry::I()->Register("L",			'L');
	CGInputRegistry::I()->Register("M",			'M');
	CGInputRegistry::I()->Register("N",			'N');
	CGInputRegistry::I()->Register("O",			'O');
	CGInputRegistry::I()->Register("P",			'P');
	CGInputRegistry::I()->Register("Q",			'Q');
	CGInputRegistry::I()->Register("R",			'R');
	CGInputRegistry::I()->Register("S",			'S');
	CGInputRegistry::I()->Register("T",			'T');
	CGInputRegistry::I()->Register("U",			'U');
	CGInputRegistry::I()->Register("V",			'V');
	CGInputRegistry::I()->Register("W",			'W');
	CGInputRegistry::I()->Register("X",			'X');
	CGInputRegistry::I()->Register("Y",			'Y');
	CGInputRegistry::I()->Register("Z",			'Z');

	CGInputRegistry::I()->Register("0",			'0');
	CGInputRegistry::I()->Register("1",			'1');
	CGInputRegistry::I()->Register("2",			'2');
	CGInputRegistry::I()->Register("3",			'3');
	CGInputRegistry::I()->Register("4",			'4');
	CGInputRegistry::I()->Register("5",			'5');
	CGInputRegistry::I()->Register("6",			'6');
	CGInputRegistry::I()->Register("7",			'7');
	CGInputRegistry::I()->Register("8",			'8');
	CGInputRegistry::I()->Register("9",			'9');

	CGInputRegistry::I()->Register("MOUSE",	0);
//	CGInputRegistry::I()->Register("BUTTON0",	CmdBinder_MOUSE_BUTTON0);
//	CGInputRegistry::I()->Register("BUTTON1",	CmdBinder_MOUSE_BUTTON1);
}
// ----------------------------------------------------------------------------
