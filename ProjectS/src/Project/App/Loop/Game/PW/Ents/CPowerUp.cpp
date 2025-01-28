#include "CPowerUP.h"

#include "antares.h"
#include "sfx.h"

#include "Game/CGameGlobals.h"
#include "Game/Ents/CEntityMgr.h"
#include "Game/GameGraphics/CEntRend.h"
#include "Game/Ents/CEntCollision.h"

// -----------------------------------------------------------------------------
CPowerUp::CPowerUp()
{
	m_iType = ENT_POWERUP;
}
// -----------------------------------------------------------------------------
CPowerUp::~CPowerUp()
{
}
// -----------------------------------------------------------------------------
void CPowerUp::Init(MTH_CPoint3& _oPos,int _iSubType)
{
	// m_poGI = pNew GEOM_Instance(_poGeo);

	// Create frame and setup startup position
	m_oIniPos = _oPos;
	m_oPos    = m_oIniPos;
	m_oOPos   = m_oIniPos;
	m_poGI->Pos(m_oPos);

	m_iSubType = _iSubType;	

	// Add to the entity manager
	CEntityMgr::iAddEntity(this);

	// Add to render entities
	m_iRI = CEntRend::iAdd(this);

	// Mal calculado pero bueno
//	m_fRadius = 0.75f; // (m_poGI->m_poModel->m_fBBXMax - m_poGI->m_poModel->m_fBBXMin)*0.5f;
	m_uiSFX = CPSysMgr::iAddPSys(21,m_oPos,MTH_CPoint3(0,0,0));

	CPSysMgr::Disable(m_uiSFX);
}
// -----------------------------------------------------------------------------
void CPowerUp::Spawn(MTH_CPoint3& _oPos)
{
	MTH_CPoint3 oPos = _oPos;
	oPos.y = 10.0f;

	Pos(oPos);
	m_eState = ENTSTATE_SPAWNING;

	// Enable FX
	CPSysMgr::Enable(m_uiSFX);
	m_oSpd.Set(0,-10.5f,0.0f);
}
// -----------------------------------------------------------------------------
#define FREQH	1.0f
#define FREQA	0.5f
#define AMP		0.5f

void CPowerUp::Think(float _fDeltaT)
{
	if ((m_eState == ENTSTATE_INACTIVE) || (m_eState == ENTSTATE_DEAD) || (m_eState == ENTSTATE_NONE)) return;
	
	switch (m_eState)
	{
		// Idle
		case ENTSTATE_IDLE:
		{
			// Simplemente que bote parriba y pabajo
			m_oPos.y = 1.0f + AMP*fSin(gfGlobalTime*_2PI_*FREQH);

			// m_poGI->SetAngles(0.0f,gfGlobalTime*_2PI_*FREQA,0.0f);
			m_poGI->Pos(m_oPos);
		}
		break;

		case ENTSTATE_SPAWNING:
		{
			// Update position
			m_oPos = m_oPos + m_oSpd*m_fDeltaT;
			
			if (m_oPos.y <= 0.0f)
			{
				m_oPos.y = 0.0f;

				// Update SFX position
				CPSysMgr::Disable(m_uiSFX);

				// Add exploding deberis
				CPSysMgr::iAddSHPSys(22,m_oPos,0.125f);	

				ShowEnable();
				m_eState = ENTSTATE_IDLE;
			}
			else
			{
				// Update SFX position
				CPSysMgr::UpdatePSys(m_uiSFX ,m_oPos);
			}
		}
		break;
	}
}
// -----------------------------------------------------------------------------
void CPowerUp::HideDisable()
{
	CPSysMgr::Disable(m_uiSFX);
	CVisEntity::HideDisable();
}
// -----------------------------------------------------------------------------