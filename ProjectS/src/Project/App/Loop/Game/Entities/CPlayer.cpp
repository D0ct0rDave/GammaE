// -----------------------------------------------------------------------------
#include "CPlayer.h"

#include "App/Loop/Game/CGameGlobals.h"
#include "App/Loop/Game/GameUtils/CBulletMgr.h"
#include "Collision/CGGEntityCollisionMgr.h"
#include "Collision/CGColliderResourceWH.h"
#include "Collision/CGColliderInstance.h"
#include "App/Loop/Game/GameUtils/Explosions/CExplosionMgr.h"
#include "ModelWH/CGModelWH.h"

// -----------------------------------------------------------------------------
const uint ENTSTATE_SPAWNING		= ENTSTATE_UNUSED;
const uint ENTSTATE_INVULNERABLE	= ENTSTATE_UNUSED + 1;
const uint ENTSTATE_READY			= ENTSTATE_UNUSED + 2;
// ----------------------------------------------------------------------------
// const CGString PLAYER_MODEL = "data/actors/BrainSlug/BrainSlug.gem";
// const CGString PLAYER_MODEL = "data/actors/MarvinPig/MarvinPig.gem";
// const CGString PLAYER_MODEL = "data/actors/mreye/mreye.gem";
// const CGString PLAYER_MODEL = "data/actors/egg/egg.gem";
// -----------------------------------------------------------------------------

/// Habilities
/// 
const float fRunSpeed[3]  = { 2.0f, 3.0f, 6.0f };
const float fJumpSpeed[3] = { 4.0f, 10.0f, 0.0f };
const float fStrength[3]  = { 0.5f, 1.0f, 2.0f };
const float fShootSpeed[3]  = { 0.5f, 1.0f, 2.0f };

const uint HEAD  = 0;
const uint TORSO = 1;
const uint LEGS  = 2;


static uint m_uiModelIdxs[3] = {0,0,0};
// -----------------------------------------------------------------------------
CGSceneAnimNode*		m_poModels[3][3];
CGSceneAnimActionSet*	m_poMgr = NULL;
CGSceneAnimGroup*		m_poAnimGroup = NULL;
// -----------------------------------------------------------------------------
CPlayer::CPlayer()
{
	m_eState = ENTSTATE_NONE;

	// Plasma
	m_oWD[0].m_iAmmo		= -1;
	m_oWD[0].m_fMaxShotTime	= 1.0f / CBulletMgr::oGetBulletType(0).m_fFreq;
	m_oWD[0].m_fShotTime	= 0.0f;	// first shot should start inmediatly
	m_oWD[0].m_iLevel		= 0;

	// Laser
	m_oWD[1].m_iAmmo		= -1;
	m_oWD[1].m_fMaxShotTime = 1.0f / CBulletMgr::oGetBulletType(1).m_fFreq;
	m_oWD[1].m_fShotTime	= 0.0f; // first shot should start inmediatly
	m_oWD[1].m_iLevel		= 0;

	// Missile
	m_oWD[2].m_iAmmo		= -1;
	m_oWD[2].m_fMaxShotTime = 1.0f / CBulletMgr::oGetBulletType(2).m_fFreq;
	m_oWD[2].m_fShotTime	= 0.0f; // first shot should start inmediatly
	m_oWD[2].m_iLevel		= 0;
	m_bJumping = false;
	m_fJumpSpd = 0.0f;
}
// -----------------------------------------------------------------------------
CPlayer::~CPlayer()
{
}
// -----------------------------------------------------------------------------
#define SQ(a) ((a)*(a))
void CPlayer::Init(const CGVect3& _oPos,int _iPlayerID)
{
	// Set the player ID
	m_iPlayerID = _iPlayerID;

	// Load model
	CGGraphicInstance* poPlayer = mNew CGGraphicInstance(PLAYER_MODEL);

	m_poModels[HEAD][0] = (CGSceneAnimNode*)CGModelWH::I()->poGetModel("data/actors/head_jason.gem");
	m_poModels[HEAD][1] = (CGSceneAnimNode*)CGModelWH::I()->poGetModel("data/actors/head_old.gem");
	m_poModels[HEAD][2] = (CGSceneAnimNode*)CGModelWH::I()->poGetModel("data/actors/head_old.gem");

	m_poModels[TORSO][0] = (CGSceneAnimNode*)CGModelWH::I()->poGetModel("data/actors/body_jason.gem");
	m_poModels[TORSO][1] = (CGSceneAnimNode*)CGModelWH::I()->poGetModel("data/actors/body_hulk.gem");
	m_poModels[TORSO][2] = (CGSceneAnimNode*)CGModelWH::I()->poGetModel("data/actors/body_cop.gem");

	m_poModels[LEGS][0] = (CGSceneAnimNode*)CGModelWH::I()->poGetModel("data/actors/legs_jason.gem");
	m_poModels[LEGS][1] = (CGSceneAnimNode*)CGModelWH::I()->poGetModel("data/actors/legs_robot.gem");
	m_poModels[LEGS][2] = (CGSceneAnimNode*)CGModelWH::I()->poGetModel("data/actors/legs_old.gem");

	m_poAnimGroup = mNew CGSceneAnimGroup;
	m_poAnimGroup->uiAddAnimObject(m_poModels[HEAD][0]);
	m_poAnimGroup->uiAddAnimObject(m_poModels[TORSO][0]);
	m_poAnimGroup->uiAddAnimObject(m_poModels[LEGS][0]);

	m_poMgr = mNew CGSceneAnimActionSet;
	m_poMgr->SetAnimObject(m_poAnimGroup);

	/*
	// DMC: Refactor
	for (uint j=0;j<3;j++)
	{	for (uint i=0;i<3;i++)
		{
			CGSceneAnimCfg* poAnimCfg = (CGSceneAnimCfg*)m_poModels[j][i];
			for (uint k=0;k<poAnimCfg->iNumFrameAnims;k++)
			{
				uint uiFrames = (poAnimCfg->FrameAnim[k].FinalFrame -  poAnimCfg->FrameAnim[k].InitialFrame);
				poAnimCfg->FrameAnim[k].TotalTime = (float)uiFrames / 30.0f;
				poAnimCfg->FrameAnim[k].FrameTime = poAnimCfg->FrameAnim[k].TotalTime  / (float)uiFrames;
			}
		}
	}
	*/

	poPlayer->poGraphicResource()->SetModel(m_poMgr);

	poPlayer->Scale(0.01f);
	poPlayer->Pos( CGVect3(7,GROUND_HEIGHT,0) );
	poPlayer->Pitch(_PI2_);
	poPlayer->Yaw(_PI_);
	poPlayer->Roll(_PI_);

	m_bJumping = true;	// empezamos en el aire
	GraphicInstance( poPlayer );
	CGGameEntityMgr::I()->uiRegister(this);

	// Set logger component
	Logger( mNew CGLogger() );

	// Set logic component
	// Logic( mNew CGScriptInstance( SCRIPT_PATH + "/" + sClass()+".lua" ) );

	// Set input component
	Input( mNew CGInputHandler() );

	poInput()->Register("up");
	poInput()->Register("down");
	poInput()->Register("left");
	poInput()->Register("right");
	poInput()->Register("fire");
	poInput()->Register("jump");

	CGGameRegistry::I()->uiAddVar( "PlayerInput", poInput() );
	uiAddUserData(mNew CGSmoother(0.125));

	// Create a collision structure
	CGColliderInstance* poCI = mNew CGColliderInstance(PLAYER_MODEL);
	poCI->m_fScale = 1.0f;
	poCI->m_oPos   = CGVect3::oZero();
	poCI->m_oOldPos= CGVect3::oZero();

	// Composite object
	Collider((CCOL_Collider*)poCI);

	// Setup this global variable
	CGGameRegistry::I()->uiAddVar( "player", this );

	gameGlobals.m_poPlayer = this;


	// Setup initial state
	Reset();
}
// -----------------------------------------------------------------------------
void CPlayer::UpdatePos(const CGVect3& _oNewPos)
{
	CGGameEntity::UpdatePos(_oNewPos);

	// 
	CGColliderInstance* poCol = (CGColliderInstance*)poCollider();
	poCol->m_oOldPos = poCol->m_oPos;
	poCol->m_oPos	 = _oNewPos;
}
// -----------------------------------------------------------------------------
void CPlayer::CheckEntityCollisions()
{
	// Tanto si se ha conseguido mover como si no, puede haber habido colision.
	// Cuando el actor desliza sobre un objeto, una de las direcciones está bloqueada
	// mientras que se permite movimiento en otra, por lo tanto, hay colisión y movimiento.
	CGCollisionInfo* poCI = CGGEntityCollisionMgr::I()->poCheckCollision(this);
	
	if (poCI)
	{		
		//if (poCI->m_poEnt->sClass())
		{
			//
			int a = 0;
		}
		// else
			// Kill();
	}
}
// -----------------------------------------------------------------------------
void CPlayer::ShuffleModels()
{
	for (uint i=0;i<3;i++)
	{
		m_uiModelIdxs[i] = Math::fRand()*3;
	}
	
	// Resetup models
	m_poAnimGroup->Clear();
	m_poAnimGroup->uiAddAnimObject(m_poModels[HEAD ][m_uiModelIdxs[HEAD ]]);
	m_poAnimGroup->uiAddAnimObject(m_poModels[TORSO][m_uiModelIdxs[TORSO]]);
	m_poAnimGroup->uiAddAnimObject(m_poModels[LEGS ][m_uiModelIdxs[LEGS ]]);
}
// -----------------------------------------------------------------------------
void CPlayer::Think(float _fDeltaT)
{
	CGGameEntity::Think(_fDeltaT);

	CGVect3 oPos = poGraphicInstance()->oPos();
	CGVect3 oNewPos(0,0,0);
	CGVect3 oSpd(0,0,0);

	/// Check X
	oSpd.x = (poInput()->fGetValue("right") - poInput()->fGetValue("left")) *_fDeltaT* fRunSpeed[ m_uiModelIdxs[LEGS] ];
	oNewPos.x = oPos.x + oSpd.x;

	// Check height
	// Check Y
	oNewPos.y = oPos.y;
	if (! m_bJumping)
	{
		if (poInput()->fGetValue("jump"))
		{
  			ShuffleModels();
				
			m_bJumping = true;
			m_fJumpSpd = fJumpSpeed[ m_uiModelIdxs[LEGS] ];
		}

		// poner altura del tile
		// float fH = gameGlobals.m_poMap->fGetGroundHeight(oPos);
		// oNewPos.y = fH; // + offset
	}
	else
	{
		// Apply gravity
		m_fJumpSpd = m_fJumpSpd + -9.8f*_fDeltaT;

		oSpd.y =  + m_fJumpSpd;
		oNewPos.y = oPos.y + oSpd.y;
	}
	
	if (oNewPos.y < GROUND_HEIGHT)
	{
		oNewPos.y = GROUND_HEIGHT;	
		m_bJumping = false;
	}
	if (oNewPos.x < 10)
	{
		oNewPos.x = 10;
		m_bJumping = false;
	}

	oPos = oNewPos;
	poGraphicInstance()->Pos(oPos);

	TEntityState eState =eGetState();
	if (eState == ENTSTATE_ALIVE)
	{
		// Only check collisions if player is ready
		CheckEntityCollisions();

		// Handle plasma weapon
		m_oWD[0].m_fShotTime = Math::fMax(0.0f,m_oWD[0].m_fShotTime-m_fDeltaT);		// Time should pass although we're not pressing fire button

		if ( poInput()->fGetValue("fire") != 0.0f)
		{
			if (m_oWD[0].m_fShotTime <= 0.0f)
			{
				CGVect3 oFPos1 = CGVect3::oZero(); // poGraphicInstance()->poGraphicResource()->poGetCP("CP_Fire1")) ? poGraphicInstance()->poGraphicResource()->poGetCP("CP_Fire1")->m_oPos;
				CGVect3 oFPos2 = CGVect3::oZero(); // (poGraphicInstance()->poGraphicResource()->poGetCP("CP_Fire2")) ? poGraphicInstance()->poGraphicResource()->poGetCP("CP_Fire2")->m_oPos;

				const CGMatrix4x4& oMat = poGraphicInstance()->oTransform();
				
				CGVect3 oWFPos1 = oFPos1;
				CGVect3 oWFPos2 = oFPos2;

				oMat.TransformPoint(&oWFPos1);
				oMat.TransformPoint(&oWFPos2);

				m_oWD[0].m_fShotTime += m_oWD[0].m_fMaxShotTime;
				CBulletMgr::iAddBullet(0,oWFPos1,CGVect3::oX(),this);
				CBulletMgr::iAddBullet(0,oWFPos2,CGVect3::oX(),this);
			}
		}
	}
}
// -----------------------------------------------------------------------------
void CPlayer::Kill()
{
	CGColliderInstance* poCol = (CGColliderInstance*)poCollider();
	CExplosionMgr::AddExplosion(ET_ENEMYGENERIC,poCol->m_oPos);

	Reset();
}
// -----------------------------------------------------------------------------
