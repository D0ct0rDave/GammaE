// -----------------------------------------------------------------------------
#include "CFollowerGroupEnemy.h"
#include "Game/Ents/CEntityMgr.h"
#include "Game/GameGraphics/CEntRend.h"
// -----------------------------------------------------------------------------
CFollowerGroupEnemy::CFollowerGroupEnemy()
{
}
// -----------------------------------------------------------------------------
CFollowerGroupEnemy::~CFollowerGroupEnemy()
{
}
// -----------------------------------------------------------------------------
void CFollowerGroupEnemy::Init(int _iSubType,char*_szFilename,float _fSpawnPeriod)
{	
	switch (_iSubType)
	{
		case 0:
		{
			CFollowerGroupEntity::Init("RobotoMalo",10,_szFilename);

			for (int i=0;i<m_oEntLst.iGetNbElem();i++)
			{
				m_oEntLst.oGetAt(i)->Energy(20.0f);
				m_oEntLst.oGetAt(i)->m_poGI->Scale(3.5f);

				m_oEntLst.oGetAt(i)->BuildBV(); 
				m_oEntLst.oGetAt(i)->SwitchToState(ENTSTATE_IDLE);
			}

			m_fSpawnPeriod = 2.5f;
		}
		break;
		
		case 1:
		{
			CFollowerGroupEntity::Init("RobotoMalo",5,_szFilename);

			for (int i=0;i<m_oEntLst.iGetNbElem();i++)
			{
				m_oEntLst.oGetAt(i)->Energy(5);
				m_oEntLst.oGetAt(i)->m_poGI->Scale(3.5f);

				m_oEntLst.oGetAt(i)->BuildBV(); 				
				m_oEntLst.oGetAt(i)->SwitchToState(ENTSTATE_IDLE);
			}

			m_fSpawnPeriod = 0.75f;
		}
		break;
		
		case 2:
		{
			CFollowerGroupEntity::Init("RobotoMalo",15,_szFilename);

			for (int i=0;i<m_oEntLst.iGetNbElem();i++)
			{
				m_oEntLst.oGetAt(i)->Energy(10);
				m_oEntLst.oGetAt(i)->m_poGI->Scale(3.5f);

				m_oEntLst.oGetAt(i)->BuildBV(); 
				m_oEntLst.oGetAt(i)->SwitchToState(ENTSTATE_IDLE);
			}
			
			m_fSpawnPeriod = 0.25f;			
		}
		break;

	}
	
	// Add to the entity manager
	CEntityMgr::iAddEntity( this );
		
	//
	m_eState = ENTSTATE_IDLE;
}
// -----------------------------------------------------------------------------
void CFollowerGroupEnemy::Think(float _fDeltaT)
{
	switch (CEntity::m_eState)
	{
		case ENTSTATE_IDLE:
		{
/*		
			// Awake entities
			for (int i=0;i<m_oEntLst.iGetNbElem();i++)
			{
				m_oEntLst.oGetAt(i)->ShowEnable();
				
				// Add entity to render sys
				CEntRend::iAdd( m_oEntLst.oGetAt(i) );
			}
*/
			Enable();
		}
		break;

		case ENTSTATE_ALIVE:
		{
			if (m_fTime >= (m_fPathTime + m_fSpawnPeriod*m_oEntLst.iGetNbElem()))
				Disable();

			if (m_eState == ENTSTATE_ALIVE)
			{
				for (int i=0;i<m_oEntLst.iGetNbElem();i++)
				{
					if (m_fTime >= m_fSpawnPeriod*i)
					{
						CVisEntity* poEnt = m_oEntLst.oGetAt(i);

						// if its' not active so activate it
						if (poEnt->m_eState == ENTSTATE_IDLE)
						{
							CEntityMgr::iAddEntity(poEnt);
							CEntRend::iAdd(poEnt);
							poEnt->ShowEnable();
						}

						// Update position
						if (poEnt->m_eState == ENTSTATE_ALIVE)
						{
							float fTime = m_fTime - m_fSpawnPeriod*(float)i;

							// Deactivate it in case
							if (fTime > m_fPathTime)
							{
								CEntityMgr::DeleteEntity(poEnt);
								poEnt->HideDisable();
							}
							else
							{
								float fFact = fTime / m_fPathTime;
								MTH_CPoint3 oPos = m_oCurve.oGetPos(fFact);
								oPos.z = -900.0f;
								
								poEnt->m_oPos = oPos;
									poEnt->Pos( oPos );
							}
						}
					}
				}
			}
		}
	}
}
// -----------------------------------------------------------------------------