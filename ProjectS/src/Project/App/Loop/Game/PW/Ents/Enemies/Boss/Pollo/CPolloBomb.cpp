// -----------------------------------------------------------------------------
#include "CPolloBomb.h"
#include "Loop/3DObjWH/C3DObjWH.h"
#include "Loop/Game/CGameGlobals.h"
#include "Loop/Game/Ents/CEntityMgr.h"
#include "Loop/EntRend/CEntRend.h"
#include "Loop/Game/Ents/CEntCollision.h"
#include "sfx.h"

#include "Loop/Game/Ents/CPlayer.h"

#define FREQ 5
// -----------------------------------------------------------------------------
CPolloBomb::CPolloBomb()
{
	m_poGI = pNew GEOM_Instance( C3DObjWH::poGetObj("data/models/enemies/boss/pollogordo/pollobomb.geo") );
	m_iType     = ENT_USER_01;

	// Create frame and setup startup position
	m_oPos.Set(0,0,0);
	m_oOPos		= m_oPos;
	m_poGI->SetPosition(m_oPos);

	// Add to the entity manager
	CEntityMgr::iAddEntity(this);

	// Add to render entities
	m_iRI = CEntRend::iAdd(this);

	// Mal calculado pero bueno
	m_fRadius = (m_poGI->m_poModel->m_fBBXMax - m_poGI->m_poModel->m_fBBXMin)*0.5f;

	m_fTime  = 0.0f;
	m_iState = ENTSTATE_INACTIVE;
	
	m_uiSFX = CPSysMgr::iAddPSys(8,m_oPos,MTH_CPoint3(0,0,0));
	CPSysMgr::Disable(m_uiSFX);
}
// -----------------------------------------------------------------------------
CPolloBomb::~CPolloBomb()
{
}
// -----------------------------------------------------------------------------
void CPolloBomb::Init(MTH_CPoint3& _oPos)
{
	m_oPos = _oPos;
}
// -----------------------------------------------------------------------------
void CPolloBomb::Init(MTH_CPoint3& _oPos,MTH_CPoint3& _oSpd)
{
	// Setup position
	m_oPos	= _oPos;
	m_oSpd	= _oSpd;

	m_poGI->SetPosition(m_oPos);

	// Start model animation
	m_poGI->m_poModel->AnimPlay();

	// Show entity
	SetVisible(true);

	// Come alive this entity
	m_iState = ENTSTATE_ALIVE;
	
	// 
	CPSysMgr::Enable(m_uiSFX);
}
// -----------------------------------------------------------------------------
void CPolloBomb::CheckNewPos(float _fDeltaT)
{
	// Is the rock Idle ???
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
		m_iState = ENTSTATE_DEAD;		
		m_poGI->m_poModel->AnimStop();
		
		// Hide this entity
		SetVisible(false);

		// Disable Trail FX
		CPSysMgr::Disable(m_uiSFX);
	
		// Rock has just crashed against something
		CPSysMgr::iAddSHPSys(6,m_oPos,0.25f);

		// Collided entity management
		switch (poCI->poEnt->m_iType)
		{
			case ENT_PLAYER:
			{
				// Make the player go down for a while
				((CPlayer*)poCI->poEnt)->DisruptPlayer(100.0f);
			}
			break;

			case ENT_ROCK:
			{
				poCI->poEnt->Kill();
			}
			break;
		}
	}

	// -----------------------
	// Set new rock position
	m_poGI->SetPosition(m_oPos);
	
	m_fTime += _fDeltaT;
	m_poGI->SetAngles(m_fTime*FREQ*_2PI_,0.0f,0.0f);

	// Disable Trail FX
	CPSysMgr::UpdatePSys(m_uiSFX,m_oPos);
}
// -----------------------------------------------------------------------------
void CPolloBomb::Think(float _fDeltaT)
{
	if (m_iState == ENTSTATE_NONE) return;

	if (m_iState == ENTSTATE_ALIVE)
	{
		CheckNewPos(_fDeltaT);
	}
}
// -----------------------------------------------------------------------------