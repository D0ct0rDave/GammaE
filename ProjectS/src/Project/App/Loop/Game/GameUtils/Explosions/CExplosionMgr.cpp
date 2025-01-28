// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Entity Message Manager
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

#include "CExplosionMgr.h"
#include "CExplosion.h"
#include "CGenericExplosion.h"
// #include "CBulletMgr.h"
// #include "Game/GameGraphics/sfx/CSFXObject.h"

// -----------------------------------------------------------------------------
#define WEAP_LASER_EXPLOSIONPSYS	10
#define WEAP_PLASMA_EXPLOSIONPSYS	18
// -----------------------------------------------------------------------------
CGStArray <CExplosion*> CExplosionMgr::m_oExp;
// -----------------------------------------------------------------------------
void CExplosionMgr::Init()
{
	m_oExp.Init(100);
}
// -----------------------------------------------------------------------------
// Add a new explosion
void CExplosionMgr::AddExplosion(EExplosionType _eExplosionType,const CVect3& _oPos)
{
	switch (_eExplosionType)
	{
		case ET_PLASMA:
		CGPSIManager::I()->poGet("psystype8",0.5f,_oPos);
		break;

		case ET_LASER:
		CGPSIManager::I()->poGet("laserexplosion",0.5f,_oPos);
		break;

		case ET_ENEMYGENERIC:
		{
			CExplosion* poObj = mNew CGenericExplosion;

			if (poObj)
			{
				poObj->Init(_oPos);
				m_oExp.iAdd(poObj);
			}
		}
		break;
	}
}
// -----------------------------------------------------------------------------
// Update the active explosions
void CExplosionMgr::Update(float _fDeltaT)
{
	for (uint i=0;i<m_oExp.uiNumElems();i++)
	{
		m_oExp[i]->Think(_fDeltaT);

		// Is the explosion still alive
		if (! m_oExp[i]->bAlive())
		{
			CExplosion* poExp = m_oExp[i];
			m_oExp.Del(i);
			mDel poExp;
		}
	}
}
// -----------------------------------------------------------------------------		
// Rendering process for any of the 
void CExplosionMgr::Render()
{
	for (uint i=0;i<m_oExp.uiNumElems();i++)
		m_oExp[i]->Render();
}
// -----------------------------------------------------------------------------