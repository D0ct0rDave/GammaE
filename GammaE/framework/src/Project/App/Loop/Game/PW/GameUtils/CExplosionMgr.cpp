// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Entity Message Manager
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

#include "CExplosionMgr.h"
#include "CExplosion.h"
#include "Game/GameUtils/Explosions/CGenericExplosion.h"
#include "sfx.h"
#include "Common/GameGlobals.h"
#include "CBulletMgr.h"
#include "Game/GameGraphics/sfx/CSFXObject.h"

// -----------------------------------------------------------------------------
#define WEAP_LASER_EXPLOSIONPSYS	10
#define WEAP_PLASMA_EXPLOSIONPSYS	18
// -----------------------------------------------------------------------------
MEM_DynamicArray <CExplosion*> CExplosionMgr::m_oExp;
// -----------------------------------------------------------------------------
void CExplosionMgr::Init()
{
	m_oExp.Init(100,100);
}
// -----------------------------------------------------------------------------
// Add a new explosion
void CExplosionMgr::AddExplosion(EExplosionType _eExplosionType,MTH_CPoint3& _oPos)
{
	switch (_eExplosionType)
	{
		case ET_PLASMA:
		CPSysMgr::iAddSHPSys(WEAP_PLASMA_EXPLOSIONPSYS,_oPos,0.5f,2000.0f);
		break;

		case ET_LASER:
		CPSysMgr::iAddSHPSys(WEAP_LASER_EXPLOSIONPSYS,_oPos,0.5f,2000.0f);
		break;
		
		case ET_ENEMYGENERIC:
		{
			CExplosion* poObj = pNew CGenericExplosion;

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
	for (int i=0;i<m_oExp.iGetNbElem();i++)
	{
		if (m_oExp.oGetAt(i))
		{
			CExplosion* poExp = m_oExp.oGetAt(i);
			
			poExp->Think(_fDeltaT);

			// Is the explosion still alive
			if (! poExp->bAlive())
			{
				m_oExp.Del(i);
				vDelete poExp;
			}
		}
	}
}
// -----------------------------------------------------------------------------		
// Rendering process for any of the 
void CExplosionMgr::Render()
{
	for (int i=0;i<m_oExp.iGetNbElem();i++)
	{
		if (m_oExp.oGetAt(i))
		{
			CExplosion* poExp = m_oExp.oGetAt(i);
			poExp->Render();
		}
	}
}
// -----------------------------------------------------------------------------