// -----------------------------------------------------------------------------
#include "CAntiGlobox.h"
#include "Loop/3DObjWH/C3DObjWH.h"
#include "Loop/Game/CGameGlobals.h"
#include "Loop/Game/Ents/CEntityMgr.h"
#include "Loop/EntRend/CEntRend.h"
#include "Loop/Game/Ents/CEntCollision.h"

#include "sfx.h"
// -----------------------------------------------------------------------------
CAntiGlobox::CAntiGlobox()
{
	m_iType  = ENT_ROCK;
	m_iState = ENTSTATE_IDLE;
}
// -----------------------------------------------------------------------------
CAntiGlobox::~CAntiGlobox()
{
}
// -----------------------------------------------------------------------------
void CAntiGlobox::Init(MTH_CPoint3& _oPos)
{
	// Load model
	m_poGI = pNew GEOM_Instance( C3DObjWH::poGetObj("data/models/enemies/boss/antiglobox/antiglobox.geo") );
//	m_poModel = C3DObjWH::poGetObj("data/models/players/globox/globox.geo");

	// setup startup position
	m_oPos    = _oPos;
	m_oOPos   = m_oPos;	
	m_poGI->SetPosition(_oPos);

	// Add to the entity manager
	CEntityMgr::iAddEntity(this);

	// Add to render entities
	m_iRI = CEntRend::iAdd(this);

	// Mal calculado pero bueno
	m_fRadius = (m_poGI->m_poModel->m_fBBXMax - m_poGI->m_poModel->m_fBBXMin)*0.5f;
}
// -----------------------------------------------------------------------------
void CAntiGlobox::CheckNewPos(float _fDeltaT)
{
	// Is the rock Idle ???
	m_oOPos  = m_oPos;
	
	if (m_iState != ENTSTATE_MOVING)
		return;

	if (bEq(m_oSpd.fGetSqLenght(),0.0f))
	{
		m_oSpd.Set(0,0,0);
		m_iState = ENTSTATE_IDLE;
		return;
	}

	m_oOPos = m_oPos;
	m_oPos += m_oSpd*_fDeltaT;

	// -----------------------
	// Set new rock position
	TCollisionInfo* poCI = CEntCollision::poCheckCollision(this,ENT_WORLD | ENT_ROCK | ENT_PLAYER);
	if (poCI)
	{
		m_oPos.x = fInterpol(m_oOPos.x,m_oPos.x,poCI->fU0);
		m_oPos.y = fInterpol(m_oOPos.y,m_oPos.y,poCI->fU0);
		m_oPos.z = fInterpol(m_oOPos.z,m_oPos.z,poCI->fU0);

		m_oSpd.Set(0,0,0);
		m_iState == ENTSTATE_IDLE;

		// Rock has just crashed against something
		CPSysMgr::iAddSHPSys(100,m_oPos,0.25f);
	}

	// -----------------------
	// Set new rock position
	m_poGI->SetPosition(m_oPos);
}
// -----------------------------------------------------------------------------
void CAntiGlobox::Think(float _fDeltaT)
{
	if (m_iState == ENTSTATE_NONE) return;

	/*
	switch (m_iState)
	{	
		case ENTSTATE_DEAD:		
		{
			return;
		}
		break;

		// Idle
		case ENTSTATE_IDLE:
		{
			
		}
		break;

		// Rock has just been thwrown
		case ENTSTATE_STARTMOVING:
		{			
			m_iState = ENTSTATE_RETMOVING;
			m_fTime  = 0.2f;
		}
		break;
		
		// Rock is retaining its movement
		case ENTSTATE_RETMOVING:
		{
			m_fTime -= _fDeltaT;
			if (m_fTime <= 0.0f)
			{
				m_iState = ENTSTATE_MOVING;
				m_fTime  = 0.0f;
				CPSysMgr::iAddSHPSys(100,m_oPos,0.25f);
			}
		}
		break;
		
		// Rock is moving
		case ENTSTATE_MOVING:
		{
			// ENT_CheckRockAgainstEntities(_poEnt);
			// ENT_CheckNewRockPosition(_poEnt);

			// Check rock position
			CheckNewPos(_fDeltaT);

			// if (bCheckRockOutOfMap())
			{
				// Do nothing more
				m_iState = ENTSTATE_DEAD;

				// Do not render anymore
				CEntRend::UpdateEnt(m_iRI,false);
				return;
			}
		}
		break;
	}
	*/
}
// -----------------------------------------------------------------------------