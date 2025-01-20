#include "CMissileField.h"

#include "antares.h"
#include "sfx.h"

#include "Loop/Special/Game/CGameGlobals.h"
#include "Loop/Special/Game/Ents/CEntityMgr.h"
#include "Loop/Special/Game/GameGraphics/CEntRend.h"
#include "Loop/Special/Game/Ents/CEntCollision.h"
// -----------------------------------------------------------------------------
#define MAX_SIMULTANEOUS_MISSILES 10
// -----------------------------------------------------------------------------
CMissileField::CMissileField()
{
	m_iType = ENT_USER_01;
}
// -----------------------------------------------------------------------------
CMissileField::~CMissileField()
{
}
// -----------------------------------------------------------------------------
void CMissileField::Init(float _fPos,float _fTime,float _fDensity)
{
	//
	m_uiMaxMissiles = MAX_SIMULTANEOUS_MISSILES* 0.6f; // _fDensity;

	// 
	MTH_CPoint3 oPos(_fPos,0,-910.0f);
	CGroupManager::Init(oPos,m_uiMaxMissiles,"Foot");
	
	//	
	m_fMaxTime = _fTime;
		
	//Add to the entity manager
	CEntityMgr::iAddEntity( this );

	//
	m_eState = ENTSTATE_IDLE;
}
// -----------------------------------------------------------------------------
void CMissileField::Think(float _fDeltaT)
{
	switch (m_eState)
	{
		case ENTSTATE_IDLE:
		{
			for (int i=0;i<m_oEntLst.iGetNbElem();i++)
			{
				CVisEntity* poEnt = m_oEntLst.oGetAt(i);

				CEntityMgr::iAddEntity(poEnt);
				CEntRend::iAdd(poEnt);
			}

			m_eState = ENTSTATE_ALIVE;
		}
		break;

		case ENTSTATE_ALIVE:
		{
			bool bLivingEntities = false;

			// Update entities independently if the time is over or not...
			for (int i=0;i<m_oEntLst.iGetNbElem();i++)
			{
				CEnemy* poEnt = m_oEntLst.oGetAt(i);

				if (poEnt->m_eState == ENTSTATE_ALIVE)
				{
					MTH_CPoint3 oPos = poEnt->m_oPos;
					oPos.x -= 1000.0f * _fDeltaT;
					poEnt->Pos( oPos );

					if (oPos.x < -100.0f)
						poEnt->HideDisable();

					bLivingEntities = true;
				}
			}

			// If the time is not over, awake inactive entities
			if (m_fTime < m_fMaxTime)
			{
				// Awake inactive entities
				for (int i=0;i<m_oEntLst.iGetNbElem();i++)
				{
					CEnemy* poEnt = m_oEntLst.oGetAt(i);

					if (poEnt->m_eState != ENTSTATE_ALIVE)
					{	
						// Set initial position
						MTH_CPoint3 oPos(m_oPos.x + fSRand()*(float)STD_SCR_WIDTH*0.5f,
										 fRand()*(float)STD_SCR_HEIGHT,
										 m_oPos.z);

						poEnt->Pos(oPos);

						//
						poEnt->ShowEnable();
					}					
				}
			}
			else if (! bLivingEntities)
			{
				Disable();	
			}
		}
	}
}
// -----------------------------------------------------------------------------