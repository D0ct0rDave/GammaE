// --------------------------------------------------------
#ifndef GameGlobalsH
#define GameGlobalsH

#include "AppGlobals.h"

// --------------------------------------------------------
// ORION ENTITY TYPE ID
#define OETI_WORLD						0
#define OETI_PLAYER						10

#define OETI_ENEMY						20
	#define OETI_ENEMY_SHIP25				0
	#define OETI_ENEMY_PERSECUTOR			1
	#define OETI_ENEMY_JUMPER				2
	#define OETI_ENEMY_TANK					3
	#define OETI_ENEMY_ROLLER				4
	#define OETI_ENEMY_SKIPPER				5

	#define OETI_ENEMY_BOSS1				20
	#define OETI_ENEMY_BOSS2				21
	#define OETI_ENEMY_BOSS3				22
	#define OETI_ENEMY_BOSS4				23
	#define OETI_ENEMY_BOSS5				24

#define OETI_PROJECTILE					30
	#define OETI_PROJ_BLASTER				0
	#define OETI_PROJ_LASER					1
	#define OETI_PROJ_HYPERBLASTER			2
	#define OETI_PROJ_CHAINMINGUN			3
	#define OETI_PROJ_RAILGUN				4
	#define OETI_PROJ_BFG					5

	#define OETI_PROJ_HOMMINGMISSILE		6
	#define OETI_PROJ_NAPALMMISSILE			7
	#define OETI_PROJ_CONCUSSIONMISSILE		8
	
	// Enemy projectiles
	#define OETI_PROJ_ELASER				9
	#define OETI_PROJ_PLASMA				10


#define MAX_WEAPS							9

#define OETI_POWERUP					40
	#define OETI_POWERUP_OPTION				0
	#define OETI_POWERUP_LASER				1
	#define OETI_POWERUP_HYPERBLASTER		2
	#define OETI_POWERUP_CHAINGUN			3
	#define OETI_POWERUP_RAILGUN			4
	#define OETI_POWERUP_BFG				5
	#define OETI_POWERUP_HOMMINGMISSILE		6
	#define OETI_POWERUP_NAPALMMISSILE		7
	#define OETI_POWERUP_CONCUSSIONMISSILE	8


// --------------------------------------------------------
// Collision System
// --------------------------------------------------------
extern CCOL_CollisionSystem			goCollisionSystem;
extern CCOL_TriList					goTRNTriList;
extern CCOL_TRN_TriListGen			goTRNTriListGen;
extern CCOL_MT_TerrainMesh			goTRNMeshTest;

// --------------------------------------------------------
// Game Scene
// --------------------------------------------------------
#include "Game/Scene/CGameScene.h"
extern	CObject3D_Node				goDynObjs;

// --------------------------------------------------------
// Terrain 
// --------------------------------------------------------
extern TERSceneLoader				goTL;

// --------------------------------------------------------
// Camera
// --------------------------------------------------------
#include "Game/Entities/GameCamera/CGameCamera.h"
#include "Scene/CObject3D_Camera.h"

extern CGameCamera					*gpoCameraEnt;
extern CObject3D_Camera				goCamera;
extern CObject3D_Camera				goHUDCam;
// --------------------------------------------------------
// Game HUD
// --------------------------------------------------------
#include "Game/Scene/CHUDMgr.h"
extern CHUDMgr						goHUDMgr;
extern CHeadUpDisplay				goHUD;

// --------------------------------------------------------
// Game background
// --------------------------------------------------------
extern CObject3D					*gpoBG;
extern CObject3D_Transf				*goBack;

// --------------------------------------------------------
// Global world elements
// --------------------------------------------------------
extern CTerrainCircuit				*gpoTerrain;
extern CObject3D					*gpoStWorld;
extern CObject3D_Transf				*gpoBackground;							
extern CObject3D_Mux				*gpoWorldLimit;
extern CObject3D_Leaf				*gpoWLLeaf;
extern CCOL_Collider				*gpoWLCol;
extern CLensFlare					*gpoLensFlare;

// --------------------------------------------------------
// Game Player Model
// --------------------------------------------------------
extern CObject3D					*gpoPlayerModel;
extern CObject3D_Transf				*gpoPlayerNode;
									
// --------------------------------------------------------
// Game realtime shadow
// --------------------------------------------------------
extern CShadowCaster				goShadowCaster;

// --------------------------------------------------------
// Game player
// --------------------------------------------------------
#include "Game/Entities/Player/CPlayer.h"
extern	CPlayer						*gpoPlayer;

// --------------------------------------------------------
// Game entities
// --------------------------------------------------------
#include "Game/Entities/CGameEntityList.h"
extern CGameEntityList				goGameEnt;

// --------------------------------------------------------
// World entities
// --------------------------------------------------------
#include "Game/Entities/CWorldEntityList.h"
#include "Game/Entities/World/CWorldEnt.h"
extern CWorldEntityList				goWorldEntList;
extern CWorldEnt					*gpoWorldEnt;

// --------------------------------------------------------
// Resource managers
// --------------------------------------------------------
#include "Game/Entities/Misc/CResourceMgr.h"
extern CResourceMgr					goProjectilMgr;
extern CResourceMgr					goPowerUpMgr;

/*
// Si se decide hacer cada tipo de proyectil en clases distintas, aunque
// todas deriven de la misma. Dependiendo de si la funcion Think se complica demasiado,
// casi es mejor dejar que los proyectiles sean una sola clase con un flag que indique
// el tipo de proyectil

extern CResourceMgr					go_Weap_LaserMgr;
extern CResourceMgr					go_Weap_HomMisMgr;
extern CResourceMgr					go_Weap_NapMisMgr;
*/


// --------------------------------------------------------
// Enemy ship Manager
// --------------------------------------------------------
#include "Game/Entities/Enemies/CShipMgr.h"
extern CShipMgr						goShipMgr;

// --------------------------------------------------------
// Sound System
// --------------------------------------------------------
enum eGAMESOUNDS{
	GAMESND_BGM,

	GAMESND_LBlaster,
	GAMESND_EBlaster,
	GAMESND_LLaserL,
	GAMESND_ELaserE,
	GAMESND_LHBlaster,
	GAMESND_EHBlaster,
	GAMESND_LChaingun,
	GAMESND_EChaingun,
	GAMESND_LRailgun,
	GAMESND_ERailgun,
	GAMESND_LBFG,
	GAMESND_EBFG,

	GAMESND_LHomming,
	GAMESND_EHomming,
	GAMESND_LNapalm,
	GAMESND_ENapalm,

	GAMESND_Select,
	GAMESND_MaxSounds
};

extern CSoundRenderer_DSound		goSndRenderer;
extern CSoundReceiver				goSndRcv;
extern CSound						goSound[GAMESND_MaxSounds];

/*
extern CStArray  <CCOL_Collider  *> gaoActorColliders;
extern CDynArray <CRTME_Platform *> gaoPlatforms;
*/
// --------------------------------------------------------
#endif
// --------------------------------------------------------