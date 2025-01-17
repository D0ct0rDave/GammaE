#include "Game/GameGlobals/GameGlobals.h"

// --------------------------------------------------------
// Collision System
// --------------------------------------------------------
CCOL_CollisionSystem			goCollisionSystem;
CCOL_TriList					goTRNTriList;
CCOL_TRN_TriListGen				goTRNTriListGen;
CCOL_MT_TerrainMesh				goTRNMeshTest;

// --------------------------------------------------------
// Game Scene
// --------------------------------------------------------
#define	_MAX_DYNAMIC_OBJECTS_ 1024
CObject3D_Node					goDynObjs(_MAX_DYNAMIC_OBJECTS_);

// --------------------------------------------------------
// Global world elements
// --------------------------------------------------------
CTerrainCircuit					*gpoTerrain;
CObject3D						*gpoStWorld;
CObject3D_Transf				*gpoBackground;
CObject3D_Mux					*gpoWorldLimit;
CObject3D_Leaf					*gpoWLLeaf;
CCOL_Collider					*gpoWLCol;
CLensFlare						*gpoLensFlare;
// --------------------------------------------------------
// Terrain 
// --------------------------------------------------------
TERSceneLoader					goTL;

// --------------------------------------------------------
// Camera
// --------------------------------------------------------
CGameCamera						*gpoCameraEnt;
CObject3D_Camera				goCamera;
CObject3D_Camera				goHUDCam;

// --------------------------------------------------------
// Game HUD
// --------------------------------------------------------
CHUDMgr							goHUDMgr;
CHeadUpDisplay					goHUD;

// --------------------------------------------------------
// Game background
// --------------------------------------------------------
CObject3D						*gpoBG;
CObject3D_Transf				*goBack;


// --------------------------------------------------------
// Game Player Model
// --------------------------------------------------------
CObject3D						*gpoPlayerModel;
CObject3D_Transf				*gpoPlayerNode;

// --------------------------------------------------------
// Game realtime shadow
// --------------------------------------------------------
CShadowCaster					goShadowCaster;

// --------------------------------------------------------
// Game player
// --------------------------------------------------------
CPlayer							*gpoPlayer;


// --------------------------------------------------------
// Game entities
// --------------------------------------------------------
CGameEntityList goGameEnt;

// --------------------------------------------------------
// World entities
// --------------------------------------------------------
CWorldEntityList				goWorldEntList;
CWorldEnt						*gpoWorldEnt;


// --------------------------------------------------------
// Projectile manager
// --------------------------------------------------------
CResourceMgr					goProjectilMgr;

// --------------------------------------------------------
// Powerup manager
// --------------------------------------------------------
CResourceMgr					goPowerUpMgr;

// --------------------------------------------------------
// Resource managers
// --------------------------------------------------------

// --------------------------------------------------------
// Enemy ship Manager
// --------------------------------------------------------
CShipMgr						goShipMgr;

// --------------------------------------------------------
// Sound System
// --------------------------------------------------------
CSound							goSound[GAMESND_MaxSounds];



/*
CStArray  <CCOL_Collider  *> gaoActorColliders;
CDynArray <CRTME_Platform *> gaoPlatforms;
*/
