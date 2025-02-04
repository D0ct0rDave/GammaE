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

CGViewport		    goViewport;
CGCamera			goPerspCam;
CGProjector		    goPerspPrj;
CGSceneCamera       goCamera;

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
	CGShaderDefFileWH::I()->iLoad("Shaders.txt");

	goViewport.ScrCX = 0.0f;
    goViewport.ScrCY = 0.0f;
    goViewport.ScrTX = 1.0f;
    goViewport.ScrTY = 1.0f;

    // La orientacion de la c�mara se determina utilizando 3 vectores
    // que son los ejes locales de la c�mara
	// goPerspCam.Pos.V3 ( 4, 10,270);
	goPerspCam.SetPos( 0.0f,-500.0f,0.0f);
	CGVect3 oDir(0, 1, 0);
	CGVect3 oUp(0, 0, 1);
	CGVect3 oSide(1,0,0);
	goPerspCam.SetVectors(oDir, oUp, oSide);

	goPerspPrj.ePrjType = E3D_PT_Perspective;
	goPerspPrj.fFOV     = 45.0f;
    goPerspPrj.fNear    = 1.0f;
    goPerspPrj.fFar     = 2000.0f;

	// -------------------------------
	// Orthographic projection camnera
	// -------------------------------
    CGRenderer::I()->SetViewport (&goViewport);
    CGRenderer::I()->SetCamera   (&goPerspCam);
	CGRenderer::I()->SetProjector(&goPerspPrj);

    CGRenderer::I()->DisableFrustumCulling();
	CGRenderer::I()->SetZPars(E3D_ZTF_LEqual,E3D_ZW_Enable);
	CGColor oColor(0.2f, 0, 0, 1);
	CGRenderer::I()->SetFogPars(E3D_FM_Linear, 0.1f, 1000.0f, 0.01f, &oColor);
	CGRenderer::I()->EnableBVRender();

  	goCamera.Init	    (100);
	goCamera.SetCamera   (&goPerspCam);
	goCamera.SetProjector(&goPerspPrj);
	goCamera.SetViewport (&goViewport);

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
			goPerspCam.LookAt(oCenter);
		}

		float fAmplitude = oRange.fModule() * 2.0f;

		oPos.x = oCenter.x + fAmplitude * Math::fSin(fAngle);
		oPos.y = oCenter.y + fAmplitude * Math::fCos(fAngle);
		oPos.z = oCenter.z;

		goPerspCam.SetPos(oPos.x,oPos.y,oPos.z);
		goPerspCam.LookAt(oCenter);
	}

	CGSCNVAnimUpdater::I()->Update(&goCamera, _fDeltaT);
}
// ----------------------------------------------------------------------------
void CLoop::Render()
{
	if (CGRenderer::I() == NULL) return;

	// World think entities
	CGRenderer::I()->BeginRender();

		// Render camera scene
        if (m_poScene)
		{
			m_poScene->Ref();
			goCamera.SetObject(m_poScene, 0);
			CGSCNVRenderer::I()->Render(&goCamera);
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
