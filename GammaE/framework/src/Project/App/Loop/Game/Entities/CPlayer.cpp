#ifdef PROFILE
#pragma optimize ("",off)
#endif

// -----------------------------------------------------------------------------
#include "CPlayer.h"
#include "sfx.h"
#include "antares.h"

// DMC: PROJECTQ #include "Loop/Shadow/CShadowMgr.h"
#include "Game/GameGraphics/CEntRend.h"
#include "Game/CGame.h"
#include "Game/CGameGlobals.h"
#include "Game/Ents/CEntityMgr.h"
#include "Game/Ents/CEntCollision.h"
#include "Game/GameUtils/CBulletMgr.h"
#include "Game/GameUtils/CExplosionMgr.h"

#include "Common/GameGlobals.h"

static int gsiPS = 0;
static int gsiF  = 0;

// -----------------------------------------------------------------------------
#define ANIM_STAND 0
#define ANIM_RUN   1
#define ANIM_PUSH  2
#define ANIM_DOWN  3
#define ANIM_UP    4
#define ANIM_JUMP  5

#define PST_BASE		10
#define PST_STAND		(PST_BASE+0)
#define PST_RUN			(PST_BASE+1)
#define PST_PUSH		(PST_BASE+2)
#define PST_DOWN0		(PST_BASE+10)
#define PST_DOWN1		(PST_BASE+11)
#define PST_DOWN2		(PST_BASE+12)
#define PST_UP		    (PST_BASE+4)
#define PST_JUMP	    (PST_BASE+5)
#define PST_OTHER		(PST_BASE+6)
// -----------------------------------------------------------------------------
#define POLVILLO_TIME				0.25f
#define PLAYER_DISRUPTING_TIME		3.0f
// -----------------------------------------------------------------------------
class GEOM_Group;

void ProcessGraphicObject(GEOM_Group* _poG)
{
	// _poG->m_poFrame->m_oMatrix.Scale(0.125f);
	/*
	for (int i=0;i<_poG->m_iSecNum;i++)
	{
	}
	*/
}
// -----------------------------------------------------------------------------
CPlayer::CPlayer()
{
	m_eState = ENTSTATE_ALIVE;

	m_bColl  = true;
	
	m_oVMovX.Set(1.0f,0.0f,0.0f);
	m_oVMovZ.Set(0.0f,0.0f,1.0f);

	m_oLOfs.Set(0,0,0);
	m_oLAngles.Set(0,0,0);

	m_fPolvilloTime = 0.0f;
	m_fLCOfs        = -0.02f;

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
	
	// Roll Averager
	m_oRollAvg.Init(0.0f,0.25f);
}
// -----------------------------------------------------------------------------
CPlayer::~CPlayer()
{
}
// -----------------------------------------------------------------------------
#define SQ(a) ((a)*(a))
void CPlayer::Init(CVect3& _oPos,int _iPlayerID)
{
	// Set the player ID
	m_iPlayerID = _iPlayerID;

	// Load model
	m_poGI = pNew CGraphicInstance( "Player" );

	// Setup startup position
	m_oPos    = _oPos;
	m_oOPos   = m_oPos;	
	m_poGI->Pos(m_oPos);
	m_poGI->Scale(-1.0f);
	// m_poGI->Scale(-0.001f);

	// Add entity to the entity manager
	// if (_bAddEntity)
	CEntityMgr::iAddEntity(this);

	// Add to render entities
	CEntRend::iAdd(this);

	// Get radius
	BuildBV();
	/*
	m_poBV = pNew CBVSphere;
	((CBVSphere*)m_poBV)->m_fRadius = fMin(fMin ((m_poGI->poGraphicResource()->oMaxs().x - m_poGI->poGraphicResource()->oMins().x)*0.5f,
												 (m_poGI->poGraphicResource()->oMaxs().y - m_poGI->poGraphicResource()->oMins().y)*0.5f),
					  	                         (m_poGI->poGraphicResource()->oMaxs().z - m_poGI->poGraphicResource()->oMins().z)*0.5f);
	*/
	Visible(true);

	m_iPlayerID = _iPlayerID;

	// Set local position
	m_oLOfs.Set(0,0,0);
	m_oLAngles.Set(0,0,0);

	// Setup global variable
	gpoPlayer[m_iPlayerID] = this;

	m_eState = ENTSTATE_ALIVE;

	Enable();

	gsiF  = CFlareMgr::iAddFlare(0,m_oPos,PSYSMGR_INFINITE_LIFE);
	gsiPS = CPSysMgr::iAddPSys(0,m_oPos,PSYSMGR_INFINITE_LIFE);
}
// -----------------------------------------------------------------------------
CVect3 oGetIPTDir(IPT_Stick& _oIPT)
{
	CVect3 oDir;

	oDir.x = ((float)_oIPT.right/255.0f) - ((float)_oIPT.left/255.0f);
	oDir.y = ((float)_oIPT.up   /255.0f) - ((float)_oIPT.down/255.0f);
	oDir.z = 0.0f;

	return(oDir);
}
// -----------------------------------------------------------------------------
CVect3 gMAXSPD		(200.0f,200.0f,1e-4f);

const float MAX_ROLL_ANGLE	= _PI_ / 3.0f;

void CPlayer::CheckNewPos(float _fDeltaT)
{
	IPT_Stick* poLStick	= &gaInput[m_iPlayerID].pressed.lstick;
	CVect3 oLDir	= oGetIPTDir(*poLStick);

	m_oPos.x = fClamp(0.0f,STD_SCR_WIDTH, m_oPos.x + oLDir.x*gMAXSPD.x * _fDeltaT );
	m_oPos.y = fClamp(0.0f,STD_SCR_HEIGHT,m_oPos.y - oLDir.y*gMAXSPD.y * _fDeltaT );
	m_oPos.z = -900.0f;

	// Set matrix
	Pos(m_oPos);
	
	// Control spaceship roll
	m_fRollAngle = m_oRollAvg.fAverager(_fDeltaT,oLDir.y * MAX_ROLL_ANGLE,0.25f);
	m_poGI->Pitch(m_fRollAngle*_180_OVER_PI_);
}
// -----------------------------------------------------------------------------
void CPlayer::CheckEntityCollisions()
{
	// Tanto si se ha conseguido mover como si no, puede haber habido colision.
	// Cuando el actor desliza sobre un objeto, una de las direcciones está bloqueada
	// mientras que se permite movimiento en otra, por lo tanto, hay colisión y movimiento.
	m_poCI = CEntCollision::poCheckCollision(this,ENT_WORLD | ENT_POWERUP | ENT_USER_00);

	/*
	// DMC ProjectQ
	if (m_poCI)
		CGame::m_poGM->bInteractiveAction(IA_Collision,this,m_poCI->poEnt);
	*/
}
// -----------------------------------------------------------------------------
void CPlayer::Think(float _fDeltaT)
{
	// 
	if ((m_eState == ENTSTATE_INACTIVE) || (m_eState == ENTSTATE_DEAD) || (m_eState == ENTSTATE_NONE)) return;

	// Collisions
	if (gaInput[m_iPlayerID].justpressed.select)
		m_bColl = ! m_bColl;

	CFlareMgr::UpdateFlare(gsiF, m_oPos);
	CPSysMgr::UpdatePSys  (gsiPS,m_oPos);

	switch (m_eState)
	{
		case ENTSTATE_ALIVE:
		{
			CheckNewPos(m_fDeltaT);	
			CheckEntityCollisions();

			// Handle weapons			
			/*
			m_poGI->m_oMat.GetCol2(&oDir);
			CVect3 oPos(m_fTCOfs,m_fHeight,0.0f);
			*/

			// Handle plasma weapon
			m_oWD[0].m_fShotTime = fMax(0.0f,m_oWD[0].m_fShotTime-m_fDeltaT);		// Time should pass although we're not pressing fire button

			if (gaInput[0].pressed.cross)
			{
				if (m_oWD[0].m_fShotTime <= 0.0f)
				{
					CVect3 oFPos1 = m_poGI->poGraphicResource()->oGetCP("CP_Fire1");
					CVect3 oFPos2 = m_poGI->poGraphicResource()->oGetCP("CP_Fire2");
					
					MTH_CMat4x4& oMat = m_poGI->roTransform();
					
					CVect3 oWFPos1,oWFPos2;
					roMat.MultVec3(oFPos1,oWFPos1);
					roMat.MultVec3(oFPos2,oWFPos2);

					m_oWD[0].m_fShotTime += m_oWD[0].m_fMaxShotTime;
					CBulletMgr::iAddBullet(0,oWFPos1,CVect3::oX(),this);
					CBulletMgr::iAddBullet(0,oWFPos2,CVect3::oX(),this);
				}
			}

			// Handle laser weapon
			m_oWD[1].m_fShotTime = fMax(0.0f,m_oWD[1].m_fShotTime-m_fDeltaT);		// Time should pass although we're not pressing fire button

			if (gaInput[0].pressed.r1)
			{
				if (m_oWD[1].m_fShotTime <= 0.0f)
				{
					CVect3 oFPos0 = m_poGI->poGraphicResource()->oGetCP("CP_Fire1");
					CVect3 oFPos1 = m_poGI->poGraphicResource()->oGetCP("CP_Fire2");
					CVect3 oFPos2 = m_poGI->poGraphicResource()->oGetCP("CP_Laser");

					MTH_CMat4x4& oMat = m_poGI->roTransform();

					CVect3 oWFPos0,oWFPos1,oWFPos2;
					roMat.MultVec3(oFPos0,oWFPos0);
					roMat.MultVec3(oFPos1,oWFPos1);
					roMat.MultVec3(oFPos2,oWFPos2);

					m_oWD[1].m_fShotTime += m_oWD[1].m_fMaxShotTime;
					CBulletMgr::iAddBullet(1,oWFPos2,CVect3::oX(),this);
				}
			}

			// Handle missile weapon
			if (gaInput[0].pressed.r2)
			{
				/*
				m_oWD[2].m_fShotTime -= m_fDeltaT;

				if (m_oWD[2].m_fShotTime <= 0.0f)
				{
					m_oWD[2].m_fShotTime += m_oWD[2].m_fMaxShotTime;
					CBulletMgr::iAddBullet(2,m_oPos,CVect3::oX(),this);
				}
				*/
				
				CExplosionMgr::AddExplosion(ET_ENEMY1,m_oPos);
			}
		}
		break;

		default:
		{

		}
		break;
		
		case PST_OTHER:
		break;
	}

	CEntity::Think(_fDeltaT);
}
// -----------------------------------------------------------------------------
void CPlayer::DisruptPlayer(float _fStrengh)
{
	m_fTime = (_fStrengh / 100.0f) * PLAYER_DISRUPTING_TIME;
	if ((m_eState<PST_DOWN0) || (m_eState>PST_DOWN2))
	{
		m_fRollAngle = 0.0f;
		// SetActorState(PST_DOWN0);
	}
	else
	{
		m_fRollAngle = _PI2_*fSRand();

		// Si tenemos más animaciones
		//		SetActorState(PST_DOWN1 + (rand() & 0x01));
	}
		
	// Takeout onomatopellas
	CVect3 oFP = m_oPos;
	oFP.x += fSRand()*2.0f;
	oFP.y += 2.0f + fRand();
	oFP.z += fSRand()*2.0f;

	CFlareMgr::iAddFlare((int)(fRand()*3.0f),oFP,1.0f);
}
/*
void CPlayer::Restart()
{
	CFlareMgr::iAddFlare((int)(fRand()*3.0f),CVect3(0,0,0),1.0f);
}
// -----------------------------------------------------------------------------
*/
#ifdef PROFILE
#pragma optimize ("",on)
#endif
