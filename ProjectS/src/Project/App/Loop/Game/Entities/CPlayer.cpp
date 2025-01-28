// -----------------------------------------------------------------------------
#include "CPlayer.h"

#include "App/Loop/Game/CGameGlobals.h"
#include "App/Loop/Game/GameUtils/CBulletMgr.h"
#include "Collision/CGGEntityCollisionMgr.h"
#include "Collision/CGColliderResourceWH.h"
#include "Collision/CGColliderInstance.h"
#include "App/Loop/Game/GameUtils/Explosions/CExplosionMgr.h"
// -----------------------------------------------------------------------------
const uint ENTSTATE_SPAWNING		= ENTSTATE_UNUSED;
const uint ENTSTATE_INVULNERABLE	= ENTSTATE_UNUSED + 1;
const uint ENTSTATE_READY			= ENTSTATE_UNUSED + 2;
// ----------------------------------------------------------------------------
// const CGString PLAYER_MODEL = "data/actors/BrainSlug/BrainSlug.gem";
const CGString PLAYER_MODEL = "data/actors/MarvinPig/MarvinPig.gem";
// const CGString PLAYER_MODEL = "data/actors/umbrella/umbrella.gem";
// const CGString PLAYER_MODEL = "data/actors/mreye/mreye.gem";
// const CGString PLAYER_MODEL = "data/actors/egg/egg.gem";
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
}
// -----------------------------------------------------------------------------
CPlayer::~CPlayer()
{
}
// -----------------------------------------------------------------------------
#define SQ(a) ((a)*(a))
void CPlayer::Init(const CVect3& _oPos,int _iPlayerID)
{
	// Set the player ID
	m_iPlayerID = _iPlayerID;

	// Load model
	CGGraphicInstance* poPlayer = mNew CGGraphicInstance( PLAYER_MODEL );
	GraphicInstance( poPlayer );
	// m_poGI->Scale(-0.001f);

	poPlayer->Pos( _oPos );
	// poPlayer->Scale( 0.05f );
	poPlayer->Pitch( _PI2_ );

	CGGameEntityMgr::I()->uiRegister(this);

	// Set logger component
	Logger( mNew CGLogger() );

	// Set logic component
	Logic( mNew CGScriptInstance( SCRIPT_PATH + "/" + sClass()+".lua" ) );

	// Set input component
	Input( mNew CGInputHandler() );

	poInput()->Register("up");
	poInput()->Register("down");
	poInput()->Register("left");
	poInput()->Register("right");
	poInput()->Register("fire");

	CGGameRegistry::I()->uiAddVar( "PlayerInput", poInput() );
	uiAddUserData(mNew CSmoother(0.125));

	// Create a collision structure
	CGColliderInstance* poCI = mNew CGColliderInstance(PLAYER_MODEL);
	poCI->m_fScale = 1.0f;
	poCI->m_oPos   = CVect3::oZero();
	poCI->m_oOldPos= CVect3::oZero();

	// Composite object
	Collider((CCOL_Collider*)poCI);

	// Setup this global variable
	CGGameRegistry::I()->uiAddVar( "player", this );
	
	gameGlobals.m_poPlayer = this;
	
	// Setup initial state
	Reset();
}
// -----------------------------------------------------------------------------
void CPlayer::UpdatePos(const CVect3& _oNewPos)
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
		Kill();
	}
}
// -----------------------------------------------------------------------------
void CPlayer::Think(float _fDeltaT)
{
	CGGameEntity::Think(_fDeltaT);

	if (eGetState() == ENTSTATE_READY)
	{
		// Only check collisions if player is ready
		CheckEntityCollisions();

		// Handle plasma weapon
		m_oWD[0].m_fShotTime = MATH_Common::fMax(0.0f,m_oWD[0].m_fShotTime-m_fDeltaT);		// Time should pass although we're not pressing fire button

		if ( poInput()->fGetValue("fire") != 0.0f)
		{
			if (m_oWD[0].m_fShotTime <= 0.0f)
			{
				CVect3 oFPos1 = CVect3::oZero(); // poGraphicInstance()->poGraphicResource()->poGetCP("CP_Fire1")) ? poGraphicInstance()->poGraphicResource()->poGetCP("CP_Fire1")->m_oPos;
				CVect3 oFPos2 = CVect3::oZero(); // (poGraphicInstance()->poGraphicResource()->poGetCP("CP_Fire2")) ? poGraphicInstance()->poGraphicResource()->poGetCP("CP_Fire2")->m_oPos;

				const CMatrix4x4& oMat = poGraphicInstance()->oTransform();
				
				CVect3 oWFPos1 = oFPos1;
				CVect3 oWFPos2 = oFPos2;

				oMat.TransformPoint(oWFPos1);
				oMat.TransformPoint(oWFPos2);

				m_oWD[0].m_fShotTime += m_oWD[0].m_fMaxShotTime;
				CBulletMgr::iAddBullet(0,oWFPos1,CVect3::oX(),this);
				CBulletMgr::iAddBullet(0,oWFPos2,CVect3::oX(),this);
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
