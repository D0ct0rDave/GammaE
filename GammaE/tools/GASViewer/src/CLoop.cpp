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

CGViewport		    Viewport;
CGCamera			PerspCam;
CGProjector		    PerspPrj;
CGSceneCamera       gCamera;

CGSceneNode*		CLoop::m_poScene = NULL;
// ----------------------------------------------------------------------------
static char s_szCurDir[1024];
const CGString& sPushFileDirectory(char* _szFilename)
{
#ifdef WIN32
	GetCurrentDirectory(1024, s_szCurDir);
	CGString sDir = Utils::ExtractFileDir(CGString(_szFilename));
	static CGString sFile = Utils::ExtractFileName(CGString(_szFilename));
	SetCurrentDirectory(sDir.szString());
	return sFile;
#else
	return CGString();
#endif

}

void PopFileDirectory()
{
#ifdef WIN32
	SetCurrentDirectory(s_szCurDir);
#endif
}
// ----------------------------------------------------------------------------
void CLoop::Init(void* _hWnd)
{
	globals.m_hWnd = (HWND)_hWnd;
	RECT Rect;
	GetWindowRect(globals.m_hWnd,&Rect);

	// Initialize some objects in the system
	globals.m_uiScrWidth  = Rect.right - Rect.left;
	globals.m_uiScrHeight = Rect.bottom - Rect.top;

    CGRenderer::I()->bInit(globals.m_hWnd,E3D_RENDERER_OP_GDI | E3D_RENDERER_OP_DBUFFER,globals.m_uiScrWidth,globals.m_uiScrHeight,32);


	CGShaderDefFileWH::I()->iLoad("data/Shaders.txt");
	CGShaderDefFileWH::I()->iLoad("data/particleshaders.txt");

	Viewport.ScrCX = 0.0f;
    Viewport.ScrCY = 0.0f;
    Viewport.ScrTX = 1.0f;
    Viewport.ScrTY = 1.0f;

    // La orientacion de la cámara se determina utilizando 3 vectores
    // que son los ejes locales de la cámara
	// PerspCam.Pos.V3 ( 4, 10,270);
	PerspCam.SetPos( 0.0f,-500.0f,0.0f);
	CGVect3 oDir(0, 0, 1);
	CGVect3 oUp(0, 1, 0);
	CGVect3 oSide;
	oSide.CrossProd(oDir, oUp);
	PerspCam.SetVectors(oDir, oUp, oSide);

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
	Register();

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

	if (m_poScene != NULL)
	{
		
		const float FREQ = 1.0f/4.0f;
		float fAngle = globals.m_fTime*FREQ;
		
		CGVect3 oCenter = CGVect3::oZero();
		CGVect3 oRange(1.0f,1.0f,1.0f);
		CGVect3 oPos;
		
		if (m_poScene->poGetBV() != NULL)
		{
			oCenter = m_poScene->poGetBV()->oGetCenter();
			oRange = m_poScene->poGetBV()->GetExtents();
			PerspCam.LookAt(oCenter);
		}

		float fAmplitude = oRange.fModule() * 2.0f;

		oPos.x = oCenter.x + fAmplitude * Math::fSin(fAngle);
		oPos.y = oCenter.y;
		oPos.z = oCenter.z + fAmplitude * Math::fCos(fAngle);

		PerspCam.SetPos(oPos.x,oPos.y,oPos.z);
		PerspCam.LookAt(oCenter);
	}

	CGSCNVAnimUpdater::I()->Update(&gCamera, _fDeltaT);
}
// ----------------------------------------------------------------------------
void CLoop::Render()
{
	if (CGRenderer::I() == NULL) return;

	// World think entities
 	CGColor oColor(0.2f,0,0,1);
    CGRenderer::I()->BeginRender();
    CGRenderer::I()->SetFogPars(E3D_FM_Linear,0.1f,1000.0f,0.01f,&oColor);

		// Render camera scene
        if (m_poScene)
		{
			m_poScene->Ref();
			gCamera.SetObject(m_poScene, 0);
			CGSCNVRenderer::I()->Render(&gCamera);
		}

    CGRenderer::I()->EndRender();
}
// ----------------------------------------------------------------------------
void CLoop::LoadGAS(char* _szFilename,char* _szDirectory)
{
	CGString sFile = sPushFileDirectory(_szFilename);
	

		SCNUt_AnimSceneLoader oLoader;
		CGSceneAnimActionSet* poActionSet = (CGSceneAnimActionSet *)oLoader.poLoad(_szFilename);

		CLoop::m_poScene = poActionSet;

	PopFileDirectory();
}
// ----------------------------------------------------------------------------
void CLoop::LoadGTS(char* _szFilename,char* _szDirectory)
{
	CGString sFile = sPushFileDirectory(_szFilename);

	SCNUt_MaterialTable oMatTable;
	SCNUt_TriSceneLoader oLoader;
	SCNUt_TriScene* poScn = oLoader.poLoad(_szFilename,oMatTable);

		if (poScn)
		{
			/*
			for (int iMat=0;iMat<oMatTable.uiNumElems();iMat++)
			{
				CE3D_Shader* poShader = CE3D_ShaderWH::I()->poCreateShader( oMatTable.poGet(iMat) );

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
			*/

			// Generate the bsp: This may take a while...
			SCNUt_SceneBuilder	oScnBuild;
			CGGraphBVFactory::SetBVMode(EGBoundingVolumeType::BVT_AABB);
			m_poScene = oScnBuild.poBuildScene(*poScn,oMatTable);
			CGSCNVBoundVolBuilder::I()->Visit(m_poScene);
		}

	PopFileDirectory();
}
// ----------------------------------------------------------------------------
void CLoop::LoadGEM(char* _szFilename)
{
	CGString sFile = sPushFileDirectory(_szFilename);

		CLoaderGEM oLoader;
		m_poScene = oLoader.poLoad(sFile);
		CGSCNVBoundVolBuilder::I()->Visit(m_poScene);

	PopFileDirectory();
}
// ----------------------------------------------------------------------------
void CLoop::SaveGEM(char* _szFilename)
{
    if (m_poScene == NULL)
        return;        

    CSaverGEM oSaver;
    oSaver.bSave(_szFilename,m_poScene);
}
// ----------------------------------------------------------------------------
void CLoop::LoadMD2(char* _szFilename)
{
	CGString sFile = sPushFileDirectory(_szFilename);

		CLoaderMD2 oLoader;
		CGSceneAnimActionSet* poQ2Model = oLoader.pLoadQ2Player(sFile);
		CGSCNVBoundVolBuilder::I()->Visit(poQ2Model);
		poQ2Model->SetAction(1);
			
		m_poScene = poQ2Model;

	PopFileDirectory();
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
