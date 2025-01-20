#include "CVPairGroupManager.h"

#include "antares.h"
#include "sfx.h"

#include "Loop/Special/Game/CGameGlobals.h"
#include "Loop/Special/Game/Ents/CEntityMgr.h"
#include "Loop/Special/Game/GameGraphics/CEntRend.h"
#include "Loop/Special/Game/Ents/CEntCollision.h"
// -----------------------------------------------------------------------------
CVPairGroupManager::CVPairGroupManager()
{
	m_iType = ENT_USER_01;
}
// -----------------------------------------------------------------------------
CVPairGroupManager::~CVPairGroupManager()
{
}
// -----------------------------------------------------------------------------
void CVPairGroupManager::Init(MTH_CPoint3& _oPos,int _iSubType)
{
	CGroupManager::Init(_oPos,_iSubType);
	CreateGroup(2,"RobotoMalo");

	switch (m_iSubType)
	{
		case 0:
		{
			m_oEntLst.oGetAt(0)->m_oSpeed.Set( 0,-200, 0);
			m_oEntLst.oGetAt(1)->m_oSpeed.Set( 0,-200, 0);
			m_oEntLst.oGetAt(0)->Pos( MTH_CPoint3(340,0,0) );
			m_oEntLst.oGetAt(1)->Pos( MTH_CPoint3(320,0,0) );
		}
		break;


		case 1:
		{
			m_oEntLst.oGetAt(0)->m_oSpeed.Set( 200,0, 0);
			m_oEntLst.oGetAt(1)->m_oSpeed.Set( 200,0, 0);
			m_oEntLst.oGetAt(0)->Pos( MTH_CPoint3(0,200,0) );
			m_oEntLst.oGetAt(1)->Pos( MTH_CPoint3(0,280,0) );
		}
		break;
		
		case 2:
		{
			m_oEntLst.oGetAt(0)->m_oSpeed.Set(-200,0, 0);
			m_oEntLst.oGetAt(1)->m_oSpeed.Set(-200,0, 0);
			m_oEntLst.oGetAt(0)->Pos( MTH_CPoint3(700,100,0) );
			m_oEntLst.oGetAt(1)->Pos( MTH_CPoint3(700,380,0) );
		}
		break;
	}

	m_eState = ENTSTATE_IDLE;
}
// -----------------------------------------------------------------------------
void CVPairGroupManager::Think(float _fDeltaT)
{
	switch (m_eState)
	{
		case ENTSTATE_IDLE:
		{
			// Awake entities
			for (int i=0;i<m_oEntLst.iGetNbElem();i++)
			{
				m_oEntLst.oGetAt(i)->ShowEnable();
				
				// Add entity to render sys
				CEntRend::iAdd( m_oEntLst.oGetAt(i) );
			}

			m_eState = ENTSTATE_ALIVE;
		}
		break;

		case ENTSTATE_ALIVE:
		{
			for (int i=0;i<m_oEntLst.iGetNbElem();i++)
			{	
				m_oEntLst.oGetAt(i)->m_oPos += (m_oEntLst.oGetAt(i)->m_oSpeed * _fDeltaT);
				m_oEntLst.oGetAt(i)->Pos( m_oEntLst.oGetAt(i)->m_oPos );
			}	
		}
	}
}
// -----------------------------------------------------------------------------