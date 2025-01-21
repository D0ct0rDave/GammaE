// ----------------------------------------------------------------------------
#include <windows.h>
#include "CLoop.h"
#include "CLoopCB.h"
#include "GammaE.h"
#include "CLoopGlobals.h"
#include "Video/CVideo.h"
#include "Game/CGame.h"
#include "Game/CGameGlobals.h"
#include "Game/GameScene/CGameScene.h"
#include "Collision/CGColliderDefinitionFileWH.h"

// ----------------------------------------------------------------------------
// Init Game Related Stuff
// ----------------------------------------------------------------------------
void CLoop::Init()
{
	CE3D_ShaderDefFileWH::I()->iLoad("data/Shaders.txt");
	CE3D_ShaderDefFileWH::I()->iLoad("data/particleshaders.txt");

	CGPSGDefFileWH::I()->iLoad("data/particles.def");

	CGTrailGenDefFileWH::I()->iLoad("data/trailgens.def");

	CGCoronaGenDefFileWH::I()->iLoad("data/coronagens.def");

	CGPathDefinitionFileWH::I()->iLoad("data/paths/clip0001.gpt");

	CGColliderDefinitionFileWH::I()->iLoad("data/colliders.def");

	// -------------------------------
	// Viewport Initialization
	// -------------------------------		
	gameGlobals.m_oViewport.ScrCX 		= 0.0f;
    gameGlobals.m_oViewport.ScrCY 		= 0.0f;
    gameGlobals.m_oViewport.ScrTX 		= 1.0f;
    gameGlobals.m_oViewport.ScrTY 		= 1.0f;
 
	// -------------------------------
	// Perspective projection camera
	// -------------------------------		
	gameGlobals.m_oPerspCam.Pos.V3 ( 0, -20.0f, 0);
 
    gameGlobals.m_oPerspCam.Up.V3  ( 0, 0, 1);
    gameGlobals.m_oPerspCam.Dir.V3 ( 0, 1, 0);
    gameGlobals.m_oPerspCam.Side.CrossProd(gameGlobals.m_oPerspCam.Dir,gameGlobals.m_oPerspCam.Up); 

	gameGlobals.m_oPerspPrj.ePrjType	= E3D_PT_Perspective;
	gameGlobals.m_oPerspPrj.fFOV		= 45.0f;
	gameGlobals.m_oPerspPrj.fNear		= 1.0f;
	gameGlobals.m_oPerspPrj.fFar		= 2000.0f;

	gameGlobals.m_oCamera.Init	      (100);
	gameGlobals.m_oCamera.SetViewport (&gameGlobals.m_oViewport);
	gameGlobals.m_oCamera.SetCamera   (&gameGlobals.m_oPerspCam);
	gameGlobals.m_oCamera.SetProjector(&gameGlobals.m_oPerspPrj);

	// -------------------------------
	// Orthographic projection camera
	// -------------------------------		
	/*
	gameGlobals.m_oOrthoPrj.ePrjType	= eE3DPrjType_Orthogonal;
		gameGlobals.m_oOrthoPrj.fFOV		= 45.0f;
		gameGlobals.m_oOrthoPrj.fNear		= 0.1f;
		gameGlobals.m_oOrthoPrj.fFar		= 100.0f;
		
		gameGlobals.m_oOrthoCam.Pos.V3 ( 0, 0,0.5);
		gameGlobals.m_oOrthoCam.Side.V3( 1, 0,  0);
	    gameGlobals.m_oOrthoCam.Up.V3  ( 0, 1,  0);
	    gameGlobals.m_oOrthoCam.Dir.V3 ( 0, 0, -1);*/
	

	// CGRenderer::I()->EnableBBoxRender();
	// CGRenderer::I()->EnableNormalRender();	

    CGRenderer::I()->DisableFrustumCulling();
	CGRenderer::I()->SetZPars(E3D_ZTF_LEqual, E3D_ZW_Enable);

// CGRenderer::I()->EnableDefferredMode();

    CE3D_Light Light;

    Light.oPos.V3(1,1,1);
	Light.eType = LT_Point;

    Light.oLitAmb.r = 0.25f;
	Light.oLitAmb.g = 0.25f;
	Light.oLitAmb.b = 0.25f;
	Light.oLitAmb.a = 0.0f;

    Light.oLitDiff.r = 1.0f;
	Light.oLitDiff.g = 1.0f;
	Light.oLitDiff.b = 1.0f;
	Light.oLitDiff.a = 0.0f;

	CGRenderer::I()->SetupLight(0,Light);

	// CGRenderer::I()->AddLight(Light);	
	// CGRenderer::I()->AddLight((CLight *)Light);

	// ------------------------
	// Sound initialization stuff
	// ------------------------
	#ifdef GAMMAE_SOUND
	if (! CGSoundRenderer::I()->Init(uiWinHandler,16,44100,256))
		printf("Error intializing sound renderer. Start using no sound\n");

	CSampleWH::I()->SetForcedParams(-1,-1);
	CSampleWH::I()->Init(256);
	CSoundWH::I()->Init(256);

	// int iSmp = SmpWH.iLoadSample("I:\\Projects\\GammaE\\engine.wav");
	// int iSmp = SmpWH.iLoadSample("F:\\Sound\\Untitled.wav");
	// int iSmp = CSampleWH::iLoadSample("F:/Sound/Samples/EFFECTS/EFF1.WAV");
	// int iSmp = CSampleWH::iLoadSample("F:/Sound/Samples/EFF_VOI/INMYHOUS.WAV");
	// int iSmp = CSampleWH::iLoadSample("data/sound/bgm/03 Flight Of The Icarus.wav",true);
	// int iSmp = CSampleWH::iLoadSample("data/sound/bgm/intro.wav");
	int iSmp = CSampleWH::I()->iLoad("data/sound/bgm/loop.wav",false);
	if (iSmp == -1) return;

	// int iSmp2 = CSampleWH::iLoadSample("F:/Sound/Samples/EFFECTS/EFF2.WAV");
	/*
	int iSmp2 = CSampleWH::iLoadSample("F:/Sound/Samples/laser2.WAV");
	if (iSmp2 == -1) return;
	*/

	poSound = mNew CSound;
	poSound->iAddLayer(true,CSampleWH::I()->poGet(iSmp));
	// poSound->iAddLayer(true,CSampleWH::poGetSample(iSmp2));
	CSoundWH::I()->iAdd(poSound,"BGM");
	// CSoundEmiter* poEmiter = SndRenderer.poAddEmiter(poSound,1.0f,CVect3(0,0,-2),10.0f);

	SndRcv.Pos.V3(0,0,0);
	SndRcv.Speed.V3(0,0,0);
	CGSoundRenderer::I()->SetReceiver(&SndRcv);
	#endif
	
		// E3D_GraphBV_Manager.SetBVMode(0);

	// ------------------------------------------------
	// Map
	// ------------------------------------------------
	// CLoaderGEM			oLoader;
	// CObject3D_Gen		*poNode = (CObject3D_Gen *)oLoader.pLoad("j:/graphics/mapper/cubo.gem");
	// CObject3D_Gen		*poNode = (CObject3D_Gen *)oLoader.pLoad("j:/graphics/mapper/octree.gem");
	// CObject3D_Gen		*poNode = (CObject3D_Gen *)oLoader.pLoad("j:/graphics/mapper/cubo_lit.gem");
	// CObject3D_Gen		*poNode = (CObject3D_Gen *)oLoader.pLoad("i:/projects/gammae/tools/octree/plane.gem");
	// CObject3D_Gen		*poNode = (CObject3D_Gen *)oLoader.pLoad("i:/projects/gammae/tools/octree/gem/plane_box2.gem");

	// ------------------------------------------------
	// Scene engine
	// ------------------------------------------------
	/*
	gCamera.Init	    (100);
	gCamera.SetViewport (&Viewport);
	gCamera.SetCamera   (&PerspCam);
	gCamera.SetProjector(&PerspPrj);

	*/
	//	CGameScene::oList.iAddObject( &gCamera );
	// ------------------------------------------------
	// Game Map
	// ------------------------------------------------	
	// Entities
	// gWorldEntities.Init(100);

	// Create the command interpreter	
	// gpoWordChallengeClient = mNew CWordChallengeClient;
	// gpoWordChallengeClient->Init(80,40);

	// gpoWordChallengeServer = mNew CWordChallengeServer;
	// gpoWordChallengeServer->Init();
	
	// Setup loop callbacks
	CLoopCB::Init();
	
	// Initialize Game
	CGame::I()->Init(0,0,0);
	
	// Initialize command interpreter
	loopGlobals.m_oCI.Init(60,30);
	loopGlobals.m_oCI.SetPrompt("Listening:\\>");
	loopGlobals.m_oCI.Enable();
	loopGlobals.m_oCI.FullClose();
	loopGlobals.m_oCI.Exec("EXEC data/config.cfg");
}
// ----------------------------------------------------------------------------
void CLoop::Finish()
{

}
// ----------------------------------------------------------------------------
bool CLoop::bLoop(float _fDeltaT)
{
	bool bRes = bUpdate(_fDeltaT);
	Render();

	return(bRes);
}
// ----------------------------------------------------------------------------
bool CLoop::bUpdate(float _fDeltaT)
{
	#ifdef GAMMAE_SOUND
	SndRcv.Pos.Assign (gameGlobals.m_oPerspCam.Pos );
	SndRcv.Dir.Assign (gameGlobals.m_oPerspCam.Dir );
	SndRcv.Up.Assign  (gameGlobals.m_oPerspCam.Up  );
	SndRcv.Side.Assign(gameGlobals.m_oPerspCam.Side);

	CGSoundRenderer::I()->Render(_fDeltaT);
	#endif
	
	_fDeltaT *= loopGlobals.m_fTimeMult;
	CGame::I()->Think(_fDeltaT );
	
	return(loopGlobals.m_bFinnishApplication);
}
// ----------------------------------------------------------------------------
void CLoop::Render()
{
	CGame::I()->Render();
}
// ----------------------------------------------------------------------------
