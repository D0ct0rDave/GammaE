// ----------------------------------------------------------------------------
// Global module defines
// ----------------------------------------------------------------------------
#define GAMMAE_SOUND
#define _USE_GEMAP_
// #define _USE_TERRAIN_
// #define _USE_MAP_
// #define _USE_BSP_
// #define _USE_LENSFLARE_
// #define _USE_DUMMIES_
// #define _USE_REFLECTOR_
#define _USE_PLAYERMODEL_
#define _USE_CONSOLE_
// #define _USE_PARTICLES_
// #define _USE_DETAILER_
#define _USE_SHADOWCAST_

// ----------------------------------------------------------------------------
// Includes necesarios para el programa
// ----------------------------------------------------------------------------
#include "Game/Globals/Globals.h"
#include "ApplicationLoop.h"

#include "Math/GammaE_Math.h"
#include "E3D/GammaE_E3D.h"
#include "Scene/GammaE_Scene.h"
#include "SceneObjects/GammaE_ScnObj.h"

#include "Memory/GammaE_Mem.h"

#include "Terrain/GammaE_Terrain.h"

#include "Input/CommandBinder/CommandBinder.h"
#include "Input/CommandDispatcher/ClientCmdDispatcher.h"
#include "Game/GameInit/CGame_KeyBinder.h"

#include "Game/GameScene/CGameScene.h"
#include "Game/Entities/Player/ePlayerCommands.h"
#include "Game/Entities/GameCamera/CGameCamera.h"
#include "Game/Entities/GameCamera/CGame_DetailCamera.h"
#include "Game/Entities/GameHUD/CGameHUD.h"
#include "Game/Entities/CBoxEntity.h"
#include "Game/Entities/CSphereEntity.h"
#include "Game/Entities/RTMapEntities/CRTMapEntities.h"

#include "Game/GameScene/GameMap/GameDummy/GameDum_Loader.h"

#include "Game/GameScene/GameMap/CGameMapLoader.h"




#include "Misc/GammaE_Misc.h"
#include "ProcTex.h"



#ifdef _BORLANDC_
	#include <dir.h>
#else
	#ifdef _MBCS
	#include <direct.h>
	#endif
#endif
// ----------------------------------------------------------------------------
// Variables utilizadas por el programa
// ----------------------------------------------------------------------------
CMesh_Rect				*Rect;
CObject3D_Leaf			*SuperBoxLeaf;
CObject3D_Node			*SuperBox;
CParticleSystem		    *PS;

CE3D_Viewport		   Viewport;
CE3D_Camera			   PerspCam;
CE3D_Projector		   PerspPrj;
CE3D_Camera			   OrthoCam;	
CE3D_Projector		   OrthoPrj;
char				   *szCmdLine;

CObject3D_Reflector	   *Reflector;

// ----------------------------------------------------------------------------
// Map
// ----------------------------------------------------------------------------
CObject3D			*poMapModel;

// ----------------------------------------------------------------------------
// Dummies
// ----------------------------------------------------------------------------
CObject3D			*poDummyScene;

// ----------------------------------------------------------------------------
// Terrain
// ----------------------------------------------------------------------------
TERSceneLoader		TL;
CObject3D			*Terrain;

// ----------------------------------------------------------------------------
// Personaje 
// ----------------------------------------------------------------------------
CObject3D_AnimCfgGen	*MD2Model;

// ----------------------------------------------------------------------------
// Game entities
// ----------------------------------------------------------------------------
CGame_DetailCamera			GDCam;
CGameHUD					GHUD;

CDetailer					*poDetailer;

// ----------------------------------------------------------------------------
bool bFinnishApplication = false;
// ----------------------------------------------------------------------------

unsigned int CameraMovementFlags = 0;
// ----------------------------------------------------------------------------
bool		 bMouseDown = false;

int			 iOldX;
int			 iOldY;

float		 fOldPitch = 0;
float		 fPitch    = 0;
float		 fOldYaw   = 0;
float		 fYaw      = 0;
CVect3		 CamDir;
CVect3		 CamUp;
CVect3		 CamSide;


unsigned int uiScrWidth  = 0;
unsigned int uiScrHeight = 0;
// ----------------------------------------------------------------------------
// Console variables
// ----------------------------------------------------------------------------
CConsole	*Console;
CE3D_Shader	*MBack  = NULL;
CE3D_Shader	*MFont  = NULL; 

// ----------------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------------
void AppLoop_OnCamForward  (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnCamBackward (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnCamUp       (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnCamDown     (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnCamLeft     (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnCamRight    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void AppLoop_OnWalkForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnWalkBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnWalkUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnWalkDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnWalkLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnWalkRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void AppLoop_OnTurnUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnTurnDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnTurnLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnTurnRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void AppLoop_OnExit	       (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnJump        (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnAttack      (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnAttack2     (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnMouseMove   (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_ToggleConsole (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_Screenshot    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnShowNormals (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void AppLoop_OnShowBBoxes  (unsigned int Enabled,unsigned int Par1,unsigned int Par2);


void AppLoop_ControlCommands();


void AppLoop_UpdateWorkingSet(bool _bForce);
// ----------------------------------------------------------------------------
// Sound System
// ----------------------------------------------------------------------------
#ifdef GAMMAE_SOUND

#include "SoundSystem/GammaE_SoundSystem.h"

//CSoundRenderer_Bass	SndRenderer;
CSoundRenderer_DSound	SndRenderer;
CSoundReceiver			SndRcv;
CSoundEmiter			SndEmiter;
CSound					*poSound;

#endif
// ----------------------------------------------------------------------------
CChrono MainChrono;
// ----------------------------------------------------------------------------
void AppLoop_InitSoundSystem(void *uiWinHandler)
{
	#ifdef GAMMAE_SOUND
	
	if (! SndRenderer.Init(uiWinHandler,16,44100,1024))
		CONPrintf("Error intializing sound renderer. Start using no sound\n");

	CSampleWH::SetForcedParams(44100,16);
	CSampleWH::Init(256);
	CSoundWH::Init (256);

	#endif
}

void AppLoop_LoadSounds()
{
	#ifdef GAMMAE_SOUND
	// int iSmp = SmpWH.iLoadSample("I:\\Projects\\GammaE\\engine.wav");
	// int iSmp = SmpWH.iLoadSample("F:\\Sound\\Untitled.wav");
	// int iSmp = CSampleWH::iLoadSample("F:/Sound/Samples/EFFECTS/EFF1.WAV");
	// int iSmp = CSampleWH::iLoadSample("F:/Sound/Samples/EFF_VOI/INMYHOUS.WAV");
	int iSmp = CSampleWH::iLoadSample("j:/Sound/Samples/weapons/laser2.WAV");
	if (iSmp == -1) return;

	// int iSmp2 = CSampleWH::iLoadSample("F:/Sound/Samples/EFFECTS/EFF2.WAV");
	/*
	int iSmp2 = CSampleWH::iLoadSample("F:/Sound/Samples/laser2.WAV");
	if (iSmp2 == -1) return;
	*/

	poSound = mNew CSound;
	poSound->iAddLayer(false,CSampleWH::poGetSample(iSmp));
	// poSound->iAddLayer(true,CSampleWH::poGetSample(iSmp2));
	CSoundWH::iAddSound(poSound,"Shot");

	SndRcv.Pos.V3(0,0,0);
	SndRcv.Speed.V3(0,0,0);
	SndRenderer.SetReceiver(&SndRcv);	
	#endif
}

void AppLoop_RenderSound()
{
	// RenderSound
	#ifdef GAMMAE_SOUND
	SndRcv.Pos.Assign (PerspCam.Pos );
	SndRcv.Dir.Assign (PerspCam.Dir );
	SndRcv.Up.Assign  (PerspCam.Up  );
	SndRcv.Side.Assign(PerspCam.Side);

	SndRenderer.Render(gDeltaT);
	#endif
}
// ----------------------------------------------------------------------------
// 
// ----------------------------------------------------------------------------
void AppLoop_RenderProcTex(void *Par)
{
	int a=a+1;
}

void AppLoop_LoadMaterials()
{	
	// Add shader extensions
	ProcTex_Init();
	
	CE3D_ShaderExtDB::AddExtension("PROCTEX_1",ProcTex_Think);

	CE3D_ShaderDefWH::Init(1024);
	CE3D_ShaderDefWH::iAddShaderFile("Shaders.txt");
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
void AppLoop_SetupPlayer(char *_szPlayerModel)
{	
	#ifdef _USE_PLAYERMODEL_
		
		// -- Creating / Loading
		CLoaderGEM oGEMLoader;
		char szString[1024];
		strcpy(szString,"base/models/players/");
		strcat(szString,_szPlayerModel);
		
		CGraphBV_Manager::SetBVMode(eGraphBV_Box);
		gPlayerModel = (CObject3D_AnimCfgGen *)oGEMLoader.pLoad(szString);		

		gPlayerNode = mNew CObject3D_Transf();
		gPlayerNode->SetObject(gPlayerModel);
		gPlayerNode->ComputeBoundVol();
		
		// Pers->ComputeBoundVol();
		// Pers->SetYaw(90);
		// ------------------
		// Setup player
		// ------------------
		gPlayer = mNew CPlayer;
		gPlayer->Init(gPlayerNode,gPlayerModel);

		/// Player.SetRocketFact(NULL);
		
		// -- Entities
		// GCam.SetPlayer(&Player);
		// GHUD.SetPlayer(&Player);

		// Add to the actor collider array
		gaoActorColliders.iAdd( &gPlayer->roColObj() );

		gWorldEntities.iAddEntity(gPlayer);
	#endif
}
// ----------------------------------------------------------------------------
void AppLoop_SetupTerrain(char *_szTerrainScene)
{
	#ifdef _USE_TERRAIN_		

		// -- Creating / Loading		
		Terrain = TL.Load(_szTerrainScene);
		Terrain->ComputeBoundVol();
		
		// Setup terrain collision object	
		int iNumSectors = TL.HF->iGetSecsPerRow() * TL.HF->iGetSecsPerCol();

		// Terrain triangle list generator
		gCOLTrn_TLG.Init(TL.HF->iGetSecsPerRow(),
						 TL.HF->iGetSecsPerCol(),
						 TL.iSectorRes,
						 TL.fSectorSize);

		for (int i=0;i<iNumSectors;i++)
			gCOLTrn_TLG.SetSector(i,(CHFSector*)TL.HF->GetSector(i));

		// Setup terrain collision tester
		gCOLScn_TCT.Init(TL.HF,TL.iSectorRes,TL.fSectorSize);

		// ------------------
		// Get Skybox
		// ------------------
		CObject3D_Node *SkyBox  = TL.GetSkyBox();
		CObject3D_Leaf *SkyDome = TL.GetSkyDome();
		
		// ------------------
		// Setup fog
		// ------------------
		CVect3 FogColor(TL.EnvPars.fFogColor[0],		
						TL.EnvPars.fFogColor[1],
						TL.EnvPars.fFogColor[2]);

		//	TL.EnvPars.iFogType = 0;
		switch (TL.EnvPars.iFogType)
		{
			case 0:
					break;
			case 1:	gpoE3DRenderer->EnableFog();
					gpoE3DRenderer->SetFogParams(0,
									TL.EnvPars.fFogNear,
									TL.EnvPars.fFogFar,
									FogColor);				
					break;
			case 2: gpoE3DRenderer->EnableFog();
					gpoE3DRenderer->SetFogParams(1,
									TL.EnvPars.fFogDens,
									0,
									FogColor);
					break;
			case 3:	gpoE3DRenderer->EnableFog();
					gpoE3DRenderer->SetFogParams(2,
									TL.EnvPars.fFogDens,
									0,
									FogColor);
					break;
		}

		
		PerspPrj.fFar = TL.EnvPars.fCamFar;

		// -- Adding to scene
		// gameScene.AddSceneObject(SkyDome);
		
		CObject3D_Node *poNode = mNew CObject3D_Node;
		CVect3 oPos(TL.EnvPars.fXOfs,TL.EnvPars.fYOfs,0.0f);
		
		poNode->SetPos(oPos);
		poNode->Init(2);
		poNode->iAddObject(Terrain);		
		poNode->ComputeBoundVol();

		gCamera.iAddObject(SkyDome);
		gCamera.iAddObject(poNode);
		// gameBackgroundMgr->SetBackground(SkyDome);
		
		// -- Collisions
		CCOL_Collider *TerrainCollider = new CCOL_Collider;
		TerrainCollider->Init(	CGame_ePET_Terrain,
								&gCOLTrn_TLG,
								&gCOLScn_TCT,
								eCOL_CT_GraphicStatic,
								eCOL_TT_NgbTri,
								Terrain,0);
		gCollisionSystem.iAddObject( *TerrainCollider );
	#endif
}
// ----------------------------------------------------------------------------
void AppLoop_SetupMap(char *_szMapScene)
{	
	#ifdef _USE_MAP_
		// -- Creating / Loading
		CLoaderGEM oGEMLoader;		
		poMapModel = oGEMLoader.pLoad(_szMapScene);
		poMapModel->ComputeBoundVol();
		

		/*
		CGraphBV_Manager::SetBVMode(eGraphBV_Sphere);

		CObject3D_Leaf	*poLeaf  = mNew CObject3D_Leaf;
		CMesh_Sphere	*poSphere= mNew CMesh_Sphere(32,5.0f);
		poLeaf->SetMesh(poSphere);
		poLeaf->SetShader(CE3D_ShaderWH::poCreateShader("Brick"));
		poLeaf->ComputeBoundVol();
		poMapModel = (CObject3D*)poLeaf;
		*/

		// ((CObject3D_Leaf *)poMapModel)->poGetMesh()->usNumPrims = 1;

		// -- Adding to scene
		gCamera.iAddObject(poMapModel);

		//
		CCOL_Collider *MapCollider = new CCOL_Collider;
		MapCollider->Init(	CGame_ePET_Map,
							&gCOLScn_TLG,
							&gCOLScn_MCT,
							eCOL_CT_Static,eCOL_TT_None,eCOL_TT_None,
							poMapModel,0,0);
		
		// -- Setting collisions
		gCollisionSystem.iAddObject( MapCollider );
	#endif
}
// ----------------------------------------------------------------------------
void AppLoop_SetupBsp(char *_szBspFile,char *_szQ2BaseDir)
{
	#ifdef _USE_BSP_
		// -- Creating / Loading
		CLoaderBSP2		oBSPLoader;		
		CObject3D	*poBSPObj;
		
		CGraphBV_Manager::SetBVMode(eGraphBV_Box);
		oBSPLoader.SetQ2BaseDir(_szQ2BaseDir);
		poBSPObj = (CObject3D*)oBSPLoader.pLoad(_szBspFile);
		
		SCNUt_SceneCompiler oScnComp;
		oScnComp.CompileScene(poBSPObj);

		// -- Adding to scene
		gCamera.AddSceneObject((CObject3D*)poBSPObj);

		//
		/*
		CCOL_Collider *oBSPCollider = new CCOL_Collider;
		oBSPCollider->Init(	CGame_ePET_Map,
							&gCOLScn_TLG,
							&gCOLScn_MCT,
							eCOL_CT_GraphicStatic,
							eCOL_TT_NgbTri,
							(CObject3D*)poBSPObj,0);

		// -- Setting collisions
		gCollisionSystem.iAddObject( *oBSPCollider );
		*/

	#endif
}
// ----------------------------------------------------------------------------
void AppLoop_SetupDummies(char *_szDummieScene)
{
	#ifdef _USE_DUMMIES_
			
		// -- Creating / Loading			
		CLoaderGEM oGEMLoader;
		poDummyScene = (CObject3D*)oGEMLoader.pLoad(_szDummieScene);
		
		// GameDum_Loader oDumLoader;
		// poDummyScene  = oDumLoader.pLoad("I:/Projects/GammaE/Dummies.dnf");
		
/*
		SCNUt_SceneCompiler oScnComp;
		oScnComp.CompileScene(poDummyScene);
*/
		// -- Adding to scene
		gCamera.AddSceneObject(poDummyScene);

	#endif	
}
// ----------------------------------------------------------------------------
void AppLoop_SetupLensFlare()
{
	#ifdef _USE_LENSFLARE_
		
		// -- Creating / Loading
		float sphi=sin(TL.EnvPars.fLightPhiAngle*_PI_OVER_180_);
		float cphi=cos(TL.EnvPars.fLightPhiAngle*_PI_OVER_180_);
		float srho=sin(TL.EnvPars.fLightRhoAngle*_PI_OVER_180_);
		float crho=cos(TL.EnvPars.fLightRhoAngle*_PI_OVER_180_);

		CVect3 SunPos;	
		SunPos.V3(cphi*crho,-sphi*crho,srho);
		SunPos.Scale(1000.0f);

		CLensFlare *pLensFlare = mNew CLensFlare();
		pLensFlare->InitLensFlare(8,SunPos);	


		// Setup materials
		CE3D_Shader *pMatA,*pMatB,*pMatC;
		
		pMatA = CE3D_ShaderWH::poCreateShader("FlareSpark"); 
		pMatB = CE3D_ShaderWH::poCreateShader("FlareGlow"); 
		pMatC = CE3D_ShaderWH::poCreateShader("FlareGlow2"); 

		// Setup colors
		CVect4 ColA,ColB,ColC,ColD,ColE;
		
		ColA.V4(1.0f,1.0f,1.0f  ,1.0f);	 // white
		ColB.V4(0.52f,0.0f,1.0f ,1.0f);	 // purple
		ColC.V4(0.0f,1.0f,0.776f,0.35f); // aqua
		ColD.V4(1.0f,0.0f,0.0f  ,0.5f);  // lime
		ColE.V4(0.8f,1.0f,0.0f  ,0.25f); // red

		pLensFlare->SetupFlareElem(0,0.075 ,-0.7 ,ColD,pMatB);
		pLensFlare->SetupFlareElem(1,0.15  ,-0.5 ,ColB,pMatA);
		pLensFlare->SetupFlareElem(2,0.7   , 0   ,ColA,pMatA);
		pLensFlare->SetupFlareElem(3,0.11  , 0.15,ColB,pMatA);
		pLensFlare->SetupFlareElem(4,0.02  , 0.2 ,ColC,pMatB);
		pLensFlare->SetupFlareElem(5,0.11  , 0.5 ,ColC,pMatA);
		pLensFlare->SetupFlareElem(6,0.11  , 0.7 ,ColE,pMatA);
		pLensFlare->SetupFlareElem(7,0.15  , 1.2 ,ColD,pMatB);
		
		// -- Adding to scene 
		gCamera.AddSceneObject(pLensFlare);
	#endif
}
// ----------------------------------------------------------------------------
void AppLoop_SetupDetailer()
{
	#ifdef _USE_DETAILER_
		
		// -- Creating / Loading
		poDetailer = mNew CDetailer();
		poDetailer->Init(5000);

		// -- Adding to scene
		gCamera.AddSceneObject(poDetailer);		

		// -- Setting entities	
		GDCam.SetDetailer(poDetailer);		
		GDCam.SetCamera	 (&PerspCam);	
		WorldEntities.iAddEntity(&GDCam);

		// -- Setting collisions
		gCollisionSystem.iAddObject(GDCam.ColObj);
	#endif
}
// ----------------------------------------------------------------------------
void AppLoop_SetupConsole()
{
	#ifdef _USE_CONSOLE_
		#define BASE_SIZE	20
		// -- Creating / Loading
		CGraphBV_Manager::SetBVMode(eGraphBV_Box);
		Console = mNew CConsole();
		CE3D_Shader *MBack  = CE3D_ShaderWH::poCreateShader("ConsoleBackground");
		CE3D_Shader *MFont  = CE3D_ShaderWH::poCreateShader("ConsoleFont"); 
		Console->Init(1.0f,0.5,3*BASE_SIZE,BASE_SIZE,MBack,MFont);	
		Console->ComputeBoundVol();

		// Create a camera object for console 
		CObject3D_Camera * OrthoCamObj = mNew CObject3D_Camera();

		OrthoCamObj->Init(5);

		OrthoCamObj->SetCamera   (&OrthoCam);
		OrthoCamObj->SetProjector(&OrthoPrj);
		OrthoCamObj->SetViewport (&Viewport );

		OrthoCamObj->iAddObject(Console);
		
		// -- Adding to scene
		gHUDMgr.SetHUD(OrthoCamObj);

		// -- Setting entities
		GHUD.SetConsole(Console);
		GHUD.Toggle();
		GHUD.Toggle();

	#endif
}
// ----------------------------------------------------------------------------
void AppLoop_SetupReflector()
{
	#ifdef _USE_REFLECTOR_
		
		// -- Creating / Loading

		// ------------------
		// Setup reflector
		// ------------------	
		Reflector = mNew CObject3D_Reflector;
		Reflector->Init(1);
		
		/*
		Reflector->Mirror->VXs[0].V3(   0,0,   0);
		Reflector->Mirror->VXs[1].V3(   0,0,1000);
		Reflector->Mirror->VXs[2].V3(1000,0,1000);
		Reflector->Mirror->VXs[3].V3(1000,0,   0);
		*/
			
		Reflector->Mirror->VXs[3].V3(   0,   0,10);
		Reflector->Mirror->VXs[2].V3(   0,4000,10);
		Reflector->Mirror->VXs[1].V3(4000,4000,10);
		Reflector->Mirror->VXs[0].V3(4000,   0,10);
		
		/*
		Reflector->Mirror->VXs[0].V3(0,   0,   0);
		Reflector->Mirror->VXs[1].V3(0,   0,1000);
		Reflector->Mirror->VXs[2].V3(0,1000,1000);
		Reflector->Mirror->VXs[3].V3(0,1000,   0);
		*/
		// Reflector->AddObject(Pers);	
		
		// -- Adding to scene
		gCamera.AddSceneObject(Reflector);

	#endif
}
// ----------------------------------------------------------------------------
void AppLoop_SetupParticleSystem()
{
	#ifdef _USE_PARTICLES_
		gCamera.iAddObject(&gPSysMgr);
	#endif
}
void AppLoop_SetupShadowCaster()
{
	#ifdef _USE_SHADOWCAST_
		gShadowCaster.Init(128);
	#endif
}
// ----------------------------------------------------------------------------
void AppLoop_LoadModels()
{
	// E3D_GraphBV_Manager.SetBVMode(0);
	char szDirectory[1024];
	GetCurrentDirectory(1024, szDirectory);

	// ------------------------------------------------
	// Map
	// ------------------------------------------------
	CLoaderGEM			oLoader;
	// CObject3D		*poNode = (CObject3D *)oLoader.pLoad("j:/graphics/mapper/cubo.gem");
	// CObject3D		*poNode = (CObject3D *)oLoader.pLoad("j:/graphics/mapper/octree.gem");
	// CObject3D		*poNode = (CObject3D *)oLoader.pLoad("j:/graphics/mapper/cubo_lit.gem");
	// CObject3D		*poNode = (CObject3D *)oLoader.pLoad("i:/projects/gammae/tools/octree/plane.gem");
	// CObject3D		*poNode = (CObject3D *)oLoader.pLoad("i:/projects/gammae/tools/octree/gem/plane_box2.gem");

	// ------------------------------------------------
	// Scene engine
	// ------------------------------------------------
	gCamera.Init	    (100);
	gCamera.SetCamera   (&PerspCam);
	gCamera.SetProjector(&PerspPrj);
	gCamera.SetViewport (&Viewport);
	gCameraEnt = mNew CGameCamera;
	gCameraEnt->SetCamera(&PerspCam);	
	
	// ------------------------------------------------
	// Collision system
	// ------------------------------------------------
	gCollisionSystem.Init(200);	
	gaoActorColliders.Init(1024);

	// ------------------------------------------------
	// Entity system / Setup game entities
	// ------------------------------------------------	
	GHUD.SetCamera(&PerspCam);

	gWorldEntities.Init(2000);	
 	gWorldEntities.iAddEntity(gCameraEnt);	// Add the camera entity
	gWorldEntities.iAddEntity(&GHUD);
	
	#ifdef _USE_PLAYERMODEL_
		// AppLoop_SetupPlayer("massacre/massacre.gem");
		AppLoop_SetupPlayer("hommer/hommer.gem");
	#endif

	// ------------------------------------------------
	// Game Map
	// ------------------------------------------------	
	#ifdef _USE_GEMAP_
		CGameMapLoader::iLoad("mapa5.gmp");		
	#endif
		

	#ifdef _USE_CONSOLE_
		AppLoop_SetupConsole();
	#endif

	#ifdef _USE_TERRAIN_
		AppLoop_SetupTerrain("data/maps/Canions/canion6.ter");
	#endif

	#ifdef _USE_DUMMIES_
		AppLoop_SetupDummies("data/maps/Canions/dummies5.gem");
	#endif

	#ifdef _USE_REFLECTOR_
		AppLoop_SetupReflector();
	#endif
	
	#ifdef _USE_MAP_
		// AppLoop_SetupMap("data/maps/Canions/castle2.gem");
		AppLoop_SetupMap("j:/graphics/mapper/cubo_lit.gem");
		// AppLoop_SetupMap("i:/projects/gammae/tools/octree/gem/planebox.gem");
	#endif
	
	#ifdef _USE_BSP_
		AppLoop_SetupBsp("K:/Quake2/baseq2/maps/q2dm1.bsp","K:/Quake2/baseq2/textures");
	#endif
		
	#ifdef _USE_LENSFLARE_
		AppLoop_SetupLensFlare();
	#endif
	
	#ifdef _USE_PARTICLES_
		AppLoop_SetupParticleSystem();	
	#endif

	#ifdef _USE_DETAILER_
		AppLoop_SetupDetailer();
	#endif

	#ifdef _USE_SHADOWCAST_
		AppLoop_SetupShadowCaster();
	#endif
		
		
		/*
		CBoxEntity *poBox;
		poBox = mNew CBoxEntity;
		poBox->Respawn();
		gWorldEntities.iAddEntity(poBox);
		*/
		/*
		CSphereEntity *poSphere;
		poSphere = mNew CSphereEntity;
		poSphere->Respawn();
		gWorldEntities.iAddEntity(poSphere);
		*/		
		/*
		#ifdef GAMMAE_COLLISION_SYSTEM	
		
		// Dummy object to test collision detection	system		
		SuperBoxGObj = (CMesh_DBox *)mNew CMesh_Box();
		SuperBoxGObj->ComputeBoundVol();
		SuperBoxLeaf = mNew CObject3D_Leaf();
		SuperBoxLeaf->SetMesh(SuperBoxGObj);
		SuperBoxLeaf->SetMaterial(MatWH.CreateMaterial("Brick"));		
		*/

		/*
		CBoxEntity		*Box;
		CObject3D_Node	*BoxNode;
			
		for (i=0;i<0;i++)
		{
			// New graphic node
			BoxNode	= mNew CObject3D_Node;
			BoxNode->Init(1);
			BoxNode->AddObject(SuperBoxLeaf);
			BoxNode->ComputeBoundVol();	
			
			// create and setup new entity
			Box		= mNew CBoxEntity;
			Box->SetGrObj(BoxNode);
			Box->GetColObj().GrObj = BoxNode;	
			Box->GetColObj().Init(i,NULL,NULL,
									eCOL_CT_GraphicDynamic,
									eCOL_TT_BV,
									BoxNode,64);

			// Add the new object to the collision scene
			gCollisionSystem.iAddObject( Box->GetColObj()  );

			// Add the new node to the graphic scene
			gCamera.AddSceneObject(BoxNode);

			// Add the new entity
			WorldEntities.iAddEntity(Box);
		}
		*/		

}
// ----------------------------------------------------------------------------
void AppLoop_LoadScene()
{
	AppLoop_LoadMaterials();
	AppLoop_LoadModels();
	AppLoop_UpdateWorkingSet(true);
}
// ----------------------------------------------------------------------------
void AppLoop_DestroyMaterials()
{
	// MipMapWH.InvalidateWarehouse();
    // TexObjWH.InvalidateWarehouse();
    CE3D_ShaderWH::Invalidate();    

	ProcTex_Finish();
}
// ----------------------------------------------------------------------------
void AppLoop_DestroyModels()
{
	//mDel (SuperBox);
}
// ----------------------------------------------------------------------------
void AppLoop_DestroyScene()
{
	AppLoop_DestroyMaterials();
	AppLoop_DestroyModels();
}
// ----------------------------------------------------------------------------
void AppLoop_SetupKeyBindings()
{
	CGame_KeyBinder KeyBinder;
	KeyBinder.Init("config.cfg");
}
// ----------------------------------------------------------------------------
void AppLoop_SetupCallbackFuncs()
{	
	// Camera commands
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMFORWARD ,AppLoop_OnCamForward  );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMBACKWARD,AppLoop_OnCamBackward );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMUP      ,AppLoop_OnCamUp       );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMDOWN    ,AppLoop_OnCamDown     );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMLEFT    ,AppLoop_OnCamLeft     );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMRIGHT   ,AppLoop_OnCamRight    );

	// Player commands
	ClientCmdDispatcher_SetDispatchCallback(KCMD_FORWARD    ,AppLoop_OnWalkForward );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_BACKWARD   ,AppLoop_OnWalkBackward);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_UP         ,AppLoop_OnWalkUp      );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_DOWN       ,AppLoop_OnWalkDown    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_LEFT       ,AppLoop_OnWalkLeft    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_RIGHT      ,AppLoop_OnWalkRight   );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNUP		,AppLoop_OnTurnUp      );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNDOWN	,AppLoop_OnTurnDown    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNLEFT	,AppLoop_OnTurnLeft    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNRIGHT	,AppLoop_OnTurnRight   );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_BUTTON1	,AppLoop_OnAttack2     );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_BUTTON0	,AppLoop_OnAttack      );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_GENMOVE	,AppLoop_OnMouseMove   );	

	ClientCmdDispatcher_SetDispatchCallback(KCMD_JUMP		,AppLoop_OnJump        );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_FUNC1		,AppLoop_OnShowNormals );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_FUNC2		,AppLoop_OnShowBBoxes  );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_EXIT		,AppLoop_OnExit        );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TOGGLECONSOLE,AppLoop_ToggleConsole);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SCREENSHOT	,AppLoop_Screenshot	   );
}
// ----------------------------------------------------------------------------
void AppLoop_OnCreate(void *uiWinHandler,unsigned int uiWndWidth,unsigned int uiWndHeight,char *pszCmdLine)
{	
	CE3D_ShaderWH::Init(1024);

	szCmdLine   = pszCmdLine;
	uiScrWidth  = uiWndWidth;
	uiScrHeight = uiWndHeight;
	
	gpoE3DRenderer = &gRenderer;
    gpoE3DRenderer->Init(uiWinHandler,E3D_RENDERER_OP_DBUFFER,uiWndWidth,uiWndHeight,32);

	Viewport.ScrCX = 0.0f;
    Viewport.ScrCY = 0.0f;
    Viewport.ScrTX = 1.0f;
    Viewport.ScrTY = 1.0f;
 
    // La orientacion de la cámara se determina utilizando 3 vectores
    // que son los ejes locales de la cámara
	// PerspCam.Pos.V3 ( 4, 10,270);
	PerspCam.Pos.V3 ( 0.0f,-8.0f,8.0f);

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
	OrthoPrj.ePrjType	= eE3DPrjType_Orthogonal;
	OrthoPrj.fFOV		= 90.0f;
	OrthoPrj.fNear		= 1.0f;
	OrthoPrj.fFar		= 1000.0f;
	
	OrthoCam.Pos.V3 ( 0, 0,100);
	OrthoCam.Side.V3(-1, 0,  0);
    OrthoCam.Up.V3  ( 0, 1,  0);
    OrthoCam.Dir.V3 ( 0, 0, -1);

    gpoE3DRenderer->SetViewport (&Viewport);
    gpoE3DRenderer->SetCamera   (&PerspCam);
	gpoE3DRenderer->SetProjector(&PerspPrj);

	// gpoE3DRenderer->EnableBBoxRender();
	// gpoE3DRenderer->EnableNormalRender();	

    gpoE3DRenderer->DisableFrustumCulling();
    // gpoE3DRenderer->DisableLighting();    
	gpoE3DRenderer->SetZPars(eE3D_ZTF_LEqual,eE3D_ZW_Enable);

// gpoE3DRenderer->EnableDefferredMode();

    CVect3 Position(1,1,1);
	/*
	Light_Directional* Light = mNew CLight_Directional();

    Light->SetParameters(Position);
    Light->AmbientColor.r = 0.25;	Light->AmbientColor.g = 0.25;  Light->AmbientColor.b = 0.25;
	Light->DiffuseColor.r = 1;		Light->DiffuseColor.g = 1;	   Light->DiffuseColor.b = 1;
	*/
	// gpoE3DRenderer->AddLight(Light);	
	// gpoE3DRenderer->AddLight((CLight *)Light);


	// ------------------------
	// Sound initialization stuff
	// ------------------------	
	AppLoop_InitSoundSystem(uiWinHandler);
	AppLoop_LoadSounds();	

	AppLoop_LoadScene();
	AppLoop_SetupKeyBindings();
	AppLoop_SetupCallbackFuncs();
}
// ----------------------------------------------------------------------------
void AppLoop_OnDestroy(void *uiWinHandler)
{
	AppLoop_DestroyScene();	
	gpoE3DRenderer->Finish();	
}
// ----------------------------------------------------------------------------
void AppLoop_OnResize (unsigned int uiWndWidth,unsigned int uiWndHeight)
{
	uiScrWidth  = uiWndWidth;
	uiScrHeight = uiWndHeight;	
	
	gpoE3DRenderer->SetScreenSize(uiWndWidth,uiWndHeight);
}
// ----------------------------------------------------------------------------
void AppLoop_OnIdle()
{
	// World think entities	
	MainChrono.Reset();
	MainChrono.Start();
	
	AppLoop_ControlCommands();

	// Update working set
	AppLoop_UpdateWorkingSet(false);

	gWorldEntities.Think(gDeltaT);			// Player,AI,other entities	thinking
	gWorldEntities.ProcessCmds(gDeltaT);	// Process the commands generated int Think step
	gWorldEntities.Interact(gDeltaT);		// Perform player and other entities interaction

	AppLoop_RenderSound();

	// Render scene	
	CGameScene::Render();

	MainChrono.Stop();
	gDeltaT  = MainChrono.ElapsedTime();
}	
// ----------------------------------------------------------------------------
// Camera event handlers
// ----------------------------------------------------------------------------
void AppLoop_OnCamForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
		CameraMovementFlags |= CMF_FORWARD;
	else
		CameraMovementFlags &= ~CMF_FORWARD;
}
void AppLoop_OnCamBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
		CameraMovementFlags |= CMF_BACKWARD;
	else
		CameraMovementFlags &= ~CMF_BACKWARD;
}

void AppLoop_OnCamUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{	
	if (Enabled)
		CameraMovementFlags |= CMF_UP;
	else
		CameraMovementFlags &= ~CMF_UP;
}

void AppLoop_OnCamDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
		CameraMovementFlags |= CMF_DOWN;
	else
		CameraMovementFlags &= ~CMF_DOWN;
}

void AppLoop_OnCamLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
		CameraMovementFlags |= CMF_LEFT;
	else
		CameraMovementFlags &= ~CMF_LEFT;
}

void AppLoop_OnCamRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{	
	if (Enabled)
		CameraMovementFlags |= CMF_RIGHT;
	else
		CameraMovementFlags &= ~CMF_RIGHT;	
}

// ----------------------------------------------------------------------------
// Player event handlers
// ----------------------------------------------------------------------------
void AppLoop_OnWalkForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{		
	gPlayer->ControlCmds(PC_Forward,Enabled,1.0f);
}

void AppLoop_OnWalkBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gPlayer->ControlCmds(PC_Backward,Enabled,-1.0f);
}

void AppLoop_OnWalkUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gPlayer->ControlCmds(PC_Up,Enabled,1.0f);
}

void AppLoop_OnWalkDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gPlayer->ControlCmds(PC_Down,Enabled,-1.0f);
}

void AppLoop_OnWalkLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gPlayer->ControlCmds(PC_Left,Enabled,1.0f);
}

void AppLoop_OnWalkRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gPlayer->ControlCmds(PC_Right,Enabled,-1.0f);	
}

void AppLoop_OnJump        (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	// gPlayer->ControlCmds(PC_Jump,Enabled,1.0f);
	CVect3 Pos(0,0,0);	
	// SndRenderer.poAddOmni(poSound,Pos,1.0f);
/*
	if (Enabled)
		SndRenderer.poAddOmniEmiter(poSound,0.5f);
*/

	if (Enabled)
	{
		static float fRadius = 1000.0f;
		CSoundEmiter *poEmiter = SndRenderer.poAddEmiter(poSound,gPlayer->roColObj().Pos,0.5f);
		poEmiter->fRadius = fRadius;
	}

}
// ----------------------------------------------------------------------------
void AppLoop_OnTurnUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gPlayer->ControlCmds(PC_Yaw,Enabled, 5.0f);
}	
void AppLoop_OnTurnDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gPlayer->ControlCmds(PC_Yaw,Enabled,-5.0f);
}
void AppLoop_OnTurnLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gPlayer->ControlCmds(PC_Roll,Enabled,5.0f);
}
void AppLoop_OnTurnRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gPlayer->ControlCmds(PC_Roll,Enabled,-5.0f);
}
void AppLoop_ToggleConsole(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled) GHUD.Toggle();
}
// ----------------------------------------------------------------------------
void AppLoop_Screenshot    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
	{
		/*
		if (! gpoE3DRenderer->UsingFlatRendering())
			gpoE3DRenderer->EnableFlatRendering();
		else
			gpoE3DRenderer->DisableFlatRendering();
		*/	
	}
}
// ----------------------------------------------------------------------------
void AppLoop_OnShowNormals (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
	{
		if(gRenderer.UsingNormalRender())
			gRenderer.DisableNormalRender();
		else
			gRenderer.EnableNormalRender();
	}
}		
// ----------------------------------------------------------------------------
void AppLoop_OnShowBBoxes  (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
	{
		if(gRenderer.UsingBBoxRender())
			gRenderer.DisableBBoxRender();
		else
			gRenderer.EnableBBoxRender();
	}
}
// ----------------------------------------------------------------------------
void AppLoop_OnAttack       (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	bMouseDown = Enabled;

	if (Enabled)
	{
		bMouseDown = true;

		iOldX     = Par1;
		iOldY     = Par2;

		fOldPitch = fPitch;
		fOldYaw	  = fYaw;
		
		CamUp.  Assign( PerspCam.Up  );
		CamSide.Assign( PerspCam.Side);
		CamDir.Assign ( PerspCam.Dir );
	}
	else
		bMouseDown = false;

}
void AppLoop_OnAttack2(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gPlayer->ControlCmds(PC_Shot,Enabled,5.0f);
}
// ----------------------------------------------------------------------------
void AppLoop_OnMouseMove    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	#define CAM_ANGLE_SCALE	2.0f

	int		   iXDiff;
	int		   iYDiff;
	float	   dPitch;
	float      dYaw;
	CMatrix4x4 R;

	if ( bMouseDown )
	{
		iXDiff = iOldX - (int)Par1;
		iYDiff = (int)Par2 - iOldY;

		iOldX = Par1;
		iOldY = Par2;

		dPitch = ((float)iYDiff/(float)uiScrHeight) * _PI_ / CAM_ANGLE_SCALE;		
		dYaw   = ((float)iXDiff/(float)uiScrWidth ) * _PI_ / CAM_ANGLE_SCALE;

		fPitch =  fOldPitch + dPitch;
		fYaw   =  fOldYaw   + dYaw;
		
		// Setup previous camera vector
	    // Establecer los nuevos ejes: Transformarlos con los nuevos ángulos incrementados		
		R.LoadIdentity();
		R.RotateFromArbitraryAxis( dPitch,PerspCam.Side.X(),PerspCam.Side.Y(),PerspCam.Side.Z() );
		R.TransformVector(PerspCam.Up  );
		R.TransformVector(PerspCam.Dir );
		PerspCam.Side.CrossProd(PerspCam.Dir,PerspCam.Up);

		R.LoadIdentity();
        R.RotateFromArbitraryAxis( dYaw,PerspCam.Up.X() ,PerspCam.Up.Y() ,PerspCam.Up.Z() );				
		R.TransformVector(PerspCam.Side);
        R.TransformVector(PerspCam.Dir );
	}
}
// ----------------------------------------------------------------------------
bool AppLoop_bFinnishApp()
{
	return(bFinnishApplication);
}

void AppLoop_OnExit	       (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	bFinnishApplication = true;
}
// ----------------------------------------------------------------------------
void AppLoop_ControlCommands()
{
    // Computo del vector de incremento
	static float	fInc = 64.0f;
	CVect3	Inc;

    Inc.V3(0,0,0);

    if (CameraMovementFlags & CMF_FORWARD ) Inc.Add(PerspCam.Dir );
    if (CameraMovementFlags & CMF_BACKWARD) Inc.Sub(PerspCam.Dir );
    if (CameraMovementFlags & CMF_UP      ) Inc.Add(PerspCam.Up  );
    if (CameraMovementFlags & CMF_DOWN    ) Inc.Sub(PerspCam.Up  );
    if (CameraMovementFlags & CMF_LEFT    ) Inc.Sub(PerspCam.Side);
    if (CameraMovementFlags & CMF_RIGHT   ) Inc.Add(PerspCam.Side);

    Inc.Scale(fInc*gDeltaT);

	if(Inc.Module()>0)
	{
		// Incremento de la posicion de la cámara
		PerspCam.Pos.Add(Inc); 
	}
}
// ----------------------------------------------------------------------------
// Añade la información relativa a 1 habitación en concreto, al working set actual
// ----------------------------------------------------------------------------
void AppLoop_UpdateRoomData(CGEMapRoom *_poRoom,int _iRoom)
{
	// -----------------
	// Update entity info
	// -----------------
	int iEnt;
	for (iEnt=0;iEnt<_poRoom->iNumEnts;iEnt++)
	{
		if (_poRoom->poEnts[iEnt])
			gWorldEntities.iAddEntity( _poRoom->poRTEnts[iEnt] );

		switch (_poRoom->poEnts[iEnt]->eClass)
		{
			case eMapEnt_Light:
			{
				gPSysMgr.iAddParticleSystem(((CRTME_Light*)_poRoom->poRTEnts[iEnt])->poSwitch);
			}
			break;
			
			case eMapEnt_Platform:
			{
				// CRTME_Platform *poPlatEnt = (CRTME_Platform*)_poRoom->poRTEnts[iEnt];
				// gCamera.SetObject( &poPlatEnt->oGrObj,gCamera.iNumSubObjs()-1);
			}
			break;
		}
	}

	// -----------------
	// Update Collisions
	// -----------------

	// Add the static part
	gCollisionSystem.iAddObject(&CGameMapLoader::aoRoomColliders[_iRoom]->oStaticObj);

	// Add the dynamic part
	for (iEnt=0;iEnt<CGameMapLoader::aoRoomColliders[_iRoom]->aoDynObjs.iNumElems();iEnt++)	
		gCollisionSystem.iAddObject( &CGameMapLoader::aoRoomColliders[_iRoom]->aoDynObjs[iEnt] );
	
}
// ----------------------------------------------------------------------------
// Cambia el working set actual sobre el que se está trabajando
// ----------------------------------------------------------------------------
void AppLoop_UpdateWorkingSet(bool _bForce)
{
	if (!gpGameMap) return;

	// Aqui se gestiona los posibles cambios en los subsistemas del juego
	// si hay un cambio de nodo, entonces el working set cambia. esto es,
	// habrá nuevas entidades, nuevos sonidos, nuevos efectos, etc...
	int iRoom = gpGameMap->iGetRoomFromPos(gCamera.poGetCamera()->Pos);
	
	// No es posible cambiar el working set ( no estamos en ninguna habitación)
	if (iRoom == -1) return;

	if ((iRoom == gpGameMap->iCurrentRoom) && (!_bForce)) return;

	// Cambio completo de working set!!!
	gpGameMap->iCurrentRoom = iRoom;

	// Reset de los subsistemas
	gPSysMgr.Reset();
	gCollisionSystem.Reset();
	// gCollisionSystem.iAddObject( &GCam.ColObj );	// Creo que no es necesario

	gWorldEntities.Reset();
	gWorldEntities.iAddEntity(gPlayer);
 	gWorldEntities.iAddEntity(gCameraEnt);
	gWorldEntities.iAddEntity(&GHUD);

	// Reinicializacion de los subsistemas
	CGEMapRoom	*poCurRoom = gpGameMap->aoRooms[gpGameMap->iCurrentRoom];
	AppLoop_UpdateRoomData(poCurRoom,gpGameMap->iCurrentRoom);

	int iARoom;
	for (iRoom=0;iRoom<poCurRoom->iNumARooms;iRoom++)
	{
		iARoom = poCurRoom->piARoom[iRoom];
		AppLoop_UpdateRoomData(gpGameMap->aoRooms[ iARoom],iARoom);
	}
}
// ----------------------------------------------------------------------------
