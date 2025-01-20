// -----------------------------------------------------------------------------
#include "CPollo.h"
#include "Loop/3DObjWH/C3DObjWH.h"
#include "Loop/Game/CGameGlobals.h"
#include "Loop/Game/Ents/CEntityMgr.h"
#include "Loop/EntRend/CEntRend.h"
#include "Loop/Game/Ents/CEntCollision.h"
#include "Loop/Game/Ents/CPlayer.h"
#include "Loop/Game/Ents/CRock.h"

#include "sfx.h"

// -----------------------------------------------------------------------------

#define ANIM_STAND 0
#define ANIM_RUN   1
#define ANIM_PUSH  2
#define ANIM_DOWN  3
#define ANIM_UP    4
#define ANIM_JUMP  5

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#define POLLO_MAXRUNTIME		6
#define POLLO_MINRUNTIME		4

#define	POLLO_MAXSPEED			4
#define	POLLO_MINSPEED			2

#define	POLLO_MINSTANDTIME		1.5
#define	POLLO_MAXSTANDTIME		3

#define	POLLO_MINATTACKTIME		5
#define	POLLO_MAXATTACKTIME		8

#define POLLO_HITTIME			4

#define POLLOBOMB_PERIOD		0.5f		// seconds between 2 consecutive bombs
#define POLLOBOMB_SPEED			10

#define	POLVILLO_TIME			0.25f

#define ONOMATOPELLAPERIOD		0.75f
#define ONOMATOPELLAPERIOD2		0.4f
#define MAX_POLLO_HITS			3
// -----------------------------------------------------------------------------

CPollo::CPollo()
{
	m_iType  = ENT_USER_00;
	m_iState = ENTSTATE_ALIVE;

	// Actor animation states table initialization
	m_iBaseState = PST_BASE;

	SetAnimPars(PST_STAND	,1,ANIM_STAND);
	SetAnimPars(PST_RUN		,1,ANIM_RUN);
	SetAnimPars(PST_ATTACK	,1,ANIM_STAND);
	SetAnimPars(PST_HIT     ,1,ANIM_STAND);	
	SetAnimPars(PST_DEAD    ,1,ANIM_STAND);
	SetAnimPars(PST_OTHER	,1,ANIM_STAND);

	m_fTime		= 1.0f;
	m_bColl     = true;

	for (int i=0;i<MAX_MISSILES;i++)
		m_poPB[i] = pNew CPolloBomb;
		
	m_fSpeedMult = 1.0f;
	m_fTimeMult  = 1.0f;
	m_uiHits     = 0;
}
// -----------------------------------------------------------------------------
CPollo::~CPollo()
{
}
// -----------------------------------------------------------------------------
void CPollo::Init(MTH_CPoint3& _oPos)
{
	CActor::Init(_oPos,"data/models/enemies/boss/PolloGordo/PolloGordo.geo","PolloGordo",true);
	
	SetActorState(PST_STAND);
	m_fTime = 0.0f;
}
// -----------------------------------------------------------------------------
void CPollo::CheckThrownRocks(float _fDeltaT)
{
	m_poCI = CEntCollision::poCheckCollision(this,ENT_ROCK);
	
	if (m_poCI)
	{
		if (m_poCI->poEnt->m_iState == ENTSTATE_MOVING)
		{
			// Disrupt pollo!
			
			// 1 de cada X rocas puede quitar vida al pollo loco o si es retornada por el usuario
			#define ROCA_MALALECHE_SPD 50.0f

			// if (fRand()	<= 0.3f)
			float fLottery = fRand();
			if ((fLottery <= 0.3f) || (m_poCI->poEnt->m_oSpd.fGetLength() > ROCA_MALALECHE_SPD))
			{
				PolloHit();
				m_poCI->poEnt->Kill();

				scr_printf( "Prob: %.2f, Spd: %.2f\n",fLottery,m_poCI->poEnt->m_oSpd.fGetLength());
			}
			else
			{
				// La lanza a toda leche, contra el player!
				MTH_CPoint3 oSpd = m_poCI->poEnt->m_oSpd;

				oSpd.Unit();
				oSpd *= -ROCA_MALALECHE_SPD;

				((CRock*)m_poCI->poEnt)->Push( oSpd , 0.0f );
				m_poCI->poEnt->m_oPos = m_poCI->poEnt->m_oOPos;
				m_oPos = m_oOPos;

				/*
				m_poCI->poEnt->m_oPos.x = fInterpol(m_poCI->poEnt->m_oOPos.x,m_poCI->poEnt->m_oPos.x,m_poCI->fU0);
				m_poCI->poEnt->m_oPos.y = fInterpol(m_poCI->poEnt->m_oOPos.y,m_poCI->poEnt->m_oPos.y,m_poCI->fU0);
				m_poCI->poEnt->m_oPos.z = fInterpol(m_poCI->poEnt->m_oOPos.z,m_poCI->poEnt->m_oPos.z,m_poCI->fU0);

				m_oPos.x = fInterpol(m_oOPos.x,m_oPos.x,m_poCI->fU0);
				m_oPos.y = fInterpol(m_oOPos.y,m_oPos.y,m_poCI->fU0);
				m_oPos.z = fInterpol(m_oOPos.z,m_oPos.z,m_poCI->fU0);
				*/
			}
		}
	}
}
// -----------------------------------------------------------------------------
void CPollo::CheckNewPos(float _fDeltaT)
{
	if (m_oSpd.fGetSqLenght() == 0.0f) return;
	
	MTH_CPoint3 oSpd = m_oSpd;

	if (! CActor::bCheckNewPos(_fDeltaT,ENT_WORLD | ENT_ROCK /* | ENT_PLAYER */ ))
	{
		switch (m_poCI->poEnt->m_iType)
		{
			// -------
			case ENT_ROCK:
			{
				if (m_poCI->poEnt->m_iState != ENTSTATE_MOVING)
					m_poCI->poEnt->Kill();
			}
			break;

			// -------
			case ENT_PLAYER:
			{
				((CPlayer*)m_poCI->poEnt)->DisruptPlayer(100.0f);
			}
			break;
		}

		// Invert speed
		m_oSpd = oSpd*(-1.0f);
	}
}
// -----------------------------------------------------------------------------
void CPollo::PolloHit()
{
	m_uiHits++;
	if (m_uiHits < MAX_POLLO_HITS)
	{
		SetActorState(PST_HIT);

		m_fTime = POLLO_HITTIME*m_fTimeMult;
		MTH_CPoint3 oFS = m_oPos + MTH_CPoint3(0,4.0f,0.0f);
		CFlareMgr::iAddFlare( 5,oFS,3.0f);	
		
		m_fSpeedMult*= 2.0f;	
		m_fTimeMult *= 0.75f;
	}
	else
	{
		SetActorState(PST_DEAD);

		MTH_CPoint3 oFS = m_oPos + MTH_CPoint3(0,4.0f,0.0f);
		CFlareMgr::iAddFlare( 5,oFS,5.0f);
	}
}
// -----------------------------------------------------------------------------
void CPollo::Think(float _fDeltaT)
{
	if ((m_iState == ENTSTATE_INACTIVE) || (m_iState == ENTSTATE_NONE)) return;

	switch (m_iState)
	{
		// ---------------
		case PST_STAND:
		{
			CheckThrownRocks(_fDeltaT);

			// Next timeout
			m_fTime -= _fDeltaT;

			if ((int)(gfGlobalTime / ONOMATOPELLAPERIOD) > (int)(gfLastGlobalTime / ONOMATOPELLAPERIOD))
			{
				// Ha pasado un periodo
				MTH_CPoint3 oFP = m_oPos;
				oFP.x += fSRand()*2.0f;
				oFP.y += 4.0f + fRand();
				oFP.z += fSRand()*2.0f;

				CFlareMgr::iAddFlare( 3 + (int)(fRand()*2.0f),oFP,1.0f);
			}


			if (m_fTime <= 0.0f)
			{
				// Setup new speed
				m_oSpd.x = m_fSpeedMult * fInterpol(POLLO_MINSPEED,POLLO_MAXSPEED,fRand());

				// set a random direction
				if (fSRand() < 0)
					m_oSpd.x *= -1.0f;
				
				// Set runing state
				SetActorState(PST_RUN);

				// Setup running timeout
				m_fTime = m_fTimeMult * fInterpol(POLLO_MINRUNTIME,POLLO_MAXRUNTIME,fRand());
			}
		}
		break;

		// ---------------
		case PST_HIT:
		{
			m_fRollAngle = _PI2_;
			
			m_fTime -= _fDeltaT;
			if (m_fTime <= 0.0f)
			{		
				m_fTime  = 0.0f;
				m_iState = PST_STAND;
				m_fRollAngle = 0.0f;
			}
		}
		break;

		// ---------------
		case PST_DEAD:
		{
			// Add onomatopellas
			if ((int)(gfGlobalTime / ONOMATOPELLAPERIOD2) > (int)(gfLastGlobalTime / ONOMATOPELLAPERIOD2))
			{
				// Ha pasado un periodo
				MTH_CPoint3 oFP = m_oPos;
				oFP.x += fSRand()*2.0f;
				oFP.y += 4.0f + fRand();
				oFP.z += fSRand()*2.0f;

				CFlareMgr::iAddFlare( 3 + (int)(fRand()*2.0f),oFP,1.0f);
			}
		
			m_fRollAngle = _PI2_;
		}
		break;

		// ---------------
		case PST_ATTACK:
		{
			CheckThrownRocks(_fDeltaT);

			// Point to the player
			MTH_CPoint3 oDir = gpoPlayer[0]->m_oPos - m_oPos;
			oDir.Unit();

			m_fOrAngle = atan2(oDir.x,oDir.z) + _PI_;

			// Lanzar un huevo si toca
			m_fBombTime += _fDeltaT;
			if (m_fBombTime >= POLLOBOMB_PERIOD)
			{
				for (int i=0;i<MAX_MISSILES;i++)
				{
					if ((m_poPB[i]->m_iState == ENTSTATE_DEAD) ||(m_poPB[i]->m_iState == ENTSTATE_INACTIVE))
					{
						MTH_CPoint3 oSpd = oDir * POLLOBOMB_SPEED * m_fSpeedMult;
						m_poPB[i]->Init(m_oPos,oSpd);
						break;
					}
				}

				m_fBombTime -= POLLOBOMB_PERIOD;
			}

			// Next timeout
			m_fTime -= _fDeltaT;

			if (m_fTime <= 0.0f)
			{
				SetActorState(PST_RUN);

				// Setup running timeout
				m_fTime = m_fTimeMult *fInterpol(POLLO_MINRUNTIME,POLLO_MAXRUNTIME,fRand());
			}
		}
		break;
		
		// ---------------
		case PST_RUN:
		{
			CheckNewPos(_fDeltaT);
			
			CheckThrownRocks(_fDeltaT);

			// Add SFX
			m_fPolvilloTime -= _fDeltaT;
			if (m_fPolvilloTime <= 0.0f)
			{
				// Add polvillo
				CPSysMgr::iAddSHPSys(18,m_oPos,0.25);
				m_fPolvilloTime = POLVILLO_TIME;
			}


			m_fTime -= _fDeltaT;
			if (m_fTime < 0.0f)
			{
					// Look of there is a encrucijada ?
				if (fSRand() < 0.0f)
				{
					SetActorState(PST_STAND);

					// Next timeout
					m_fTime  = m_fTimeMult * fInterpol(POLLO_MINSTANDTIME,POLLO_MAXSTANDTIME,fRand());
				}						
				else
				{
					// 
					m_fBombTime = 0.0f;

					SetActorState(PST_ATTACK);

					// Next timeout
					m_fTime  = m_fTimeMult *fInterpol(POLLO_MINATTACKTIME,POLLO_MAXATTACKTIME,fRand());
				}				
			}
		}
		break;

		// Now for cinematics
		case PST_OTHER:
		{
		}
		break;
	}

	CActor::Think(_fDeltaT);
}
// -----------------------------------------------------------------------------