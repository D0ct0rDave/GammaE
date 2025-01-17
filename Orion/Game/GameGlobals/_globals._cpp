#include "Globals.h"
#include "E3D/Drivers/OGL/CE3D_OGL_Win_Renderer.h"
// #include "E3D/GammaE_E3D.h"

// --------------------------------------------------------
// Collision system
// --------------------------------------------------------
CCOL_CollisionSystem	gCollisionSystem;
CCOL_TRN_TriListGen		gCOLTrn_TLG;
CCOL_Scn_TriListGen		gCOLScn_TLG;
CCOL_MT_CommonMesh		gCOLScn_MCT;
CCOL_MT_TerrainMesh		gCOLScn_TCT;
float					gColDst[6];
// --------------------------------------------------------
// Engine 3D
// --------------------------------------------------------
CE3D_OGL_Win_Renderer	gRenderer;
float					gDeltaT;
// --------------------------------------------------------
// Game Scene
// --------------------------------------------------------
#define	_MAX_DYNAMIC_OBJECTS_ 1024
#include "Game/GameScene/CGameScene.h"
#include "Scene/GammaE_Scene.h"

CObject3D_Node			gDynObjs(_MAX_DYNAMIC_OBJECTS_);

// --------------------------------------------------------
// Camera
// --------------------------------------------------------
CGameCamera				*gCameraEnt;
CObject3D_Camera		gCamera;

// --------------------------------------------------------
// GameMap
// --------------------------------------------------------
CGEMap					*gpGameMap;

// --------------------------------------------------------
// Game HUD
// --------------------------------------------------------
CHUDMgr					gHUDMgr;


// --------------------------------------------------------
// Game Background
// --------------------------------------------------------
CBackgroundMgr			gBackMgr;

// --------------------------------------------------------
// Game Particle Systems
// --------------------------------------------------------
CParticleSystemMgr		gPSysMgr;

// --------------------------------------------------------
// Game Player Model
// --------------------------------------------------------
CObject3D_AnimCfgGen	*gPlayerModel;
CObject3D_Transf		*gPlayerNode;

// --------------------------------------------------------
// Game realtime shadow
// --------------------------------------------------------
CShadowCaster			gShadowCaster;
// --------------------------------------------------------
// Game player
// --------------------------------------------------------
CPlayer					*gPlayer;

// --------------------------------------------------------
// World entities
// --------------------------------------------------------
#define MAX_ACTORS
CGameListEntity				 gWorldEntities;
CStArray  <CCOL_Collider  *> gaoActorColliders;
CDynArray <CRTME_Platform *> gaoPlatforms;