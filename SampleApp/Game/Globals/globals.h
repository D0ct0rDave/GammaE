// --------------------------------------------------------
#ifndef GlobalsH
#define GlobalsH
// --------------------------------------------------------

// --------------------------------------------------------
// Collision System
// --------------------------------------------------------
#include "Math/GammaE_Math.h"
#include "Collision/GammaE_Collision.h"

extern CCOL_CollisionSystem		gCollisionSystem;
extern CCOL_TRN_TriListGen		gCOLTrn_TLG;
extern CCOL_Scn_TriListGen		gCOLScn_TLG;
extern CCOL_MT_CommonMesh		gCOLScn_MCT;
extern CCOL_MT_TerrainMesh		gCOLScn_TCT;
extern float					gColDst[6];

// --------------------------------------------------------
// Engine3D
// --------------------------------------------------------
#include "E3D/GammaE_E3D.h"

extern CE3D_OGL_Win_Renderer	gRenderer;
extern float					gDeltaT;

// --------------------------------------------------------
// Game Scene
// --------------------------------------------------------
#include "Game/GameScene/CGameScene.h"
#include "Scene/GammaE_Scene.h"
extern	CObject3D_Node			gDynObjs;
// --------------------------------------------------------
// Camera
// --------------------------------------------------------
#include "Game/Entities/GameCamera/CGameCamera.h"
#include "Scene/CObject3D_Camera.h"

extern CGameCamera				*gCameraEnt;
extern CObject3D_Camera			gCamera;
// --------------------------------------------------------
// GameMap
// --------------------------------------------------------
#include "Game/GameScene/GameMap/GEMap/CGEMap.h"
extern CGEMap					*gpGameMap;

// --------------------------------------------------------
// Game HUD
// --------------------------------------------------------
#include "Game/GameScene/CHUDMgr.h"
extern CHUDMgr					gHUDMgr;

// --------------------------------------------------------
// Game Background
// --------------------------------------------------------
#include "Game/GameScene/CBackgroundMgr.h"
extern CBackgroundMgr			gBackMgr;

// --------------------------------------------------------
// Game Particle Systems
// --------------------------------------------------------
#include "Game/GameScene/CParticleSystemMgr.h"
extern CParticleSystemMgr		gPSysMgr;

// --------------------------------------------------------
// Game Player Model
// --------------------------------------------------------
#include "Scene/GammaE_Scene.h"
extern CObject3D_AnimCfgGen		*gPlayerModel;
extern CObject3D_Transf			*gPlayerNode;

// --------------------------------------------------------
// Game realtime shadow
// --------------------------------------------------------
#include "SceneObjects/GammaE_ScnObj.h"
extern CShadowCaster			gShadowCaster;

// --------------------------------------------------------
// Game player
// --------------------------------------------------------
#include "Game/Entities/Player/CPlayer.h"
extern	CPlayer					*gPlayer;

// --------------------------------------------------------
// World entities
// --------------------------------------------------------
#include "Game/Entities/CGameListEntity.h"
#include "Game/Entities/RTMapEntities/CRTME_Platform.h"
extern CGameListEntity	gWorldEntities;

extern CStArray  <CCOL_Collider  *> gaoActorColliders;
extern CDynArray <CRTME_Platform *> gaoPlatforms;
// --------------------------------------------------------
#endif
// --------------------------------------------------------