#include <stdlib.h>	// for NULL definition

#include "CEntityMgr.h"

CEntity* CEntityMgr::m_poList[MAX_ENTITIES];
int 	 CEntityMgr::m_iNumEnt;
// -----------------------------------------------------------------------------		
void CEntityMgr::Reset()
{
	// Delete all entities
	int iEnt;
	for (iEnt=0;iEnt<MAX_ENTITIES;iEnt++)	
		m_poList[iEnt] = NULL;
	
	m_iNumEnt = 0;
}
// -----------------------------------------------------------------------------
void CEntityMgr::Think(float _fDeltaT)
{
	for (int iEnt=0;iEnt<MAX_ENTITIES;iEnt++)
	{
		if (m_poList[iEnt])
			if (m_poList[iEnt]->m_eState != ENTSTATE_INACTIVE)
			{
				m_poList[iEnt]->PreThink(_fDeltaT);
				m_poList[iEnt]->Think(_fDeltaT);
			}
 	}
}
// -----------------------------------------------------------------------------
int CEntityMgr::iAddEntity(CEntity *_poEnt)
{
	// handle circular queue
	int iTestEnts = 0;

	do
	{
		if (m_poList[m_iNumEnt] == NULL)
		{
			m_poList[m_iNumEnt] = _poEnt;
			return(m_iNumEnt);
		}

		m_iNumEnt = (m_iNumEnt+1) % MAX_ENTITIES;
		iTestEnts++;

	}while (iTestEnts<MAX_ENTITIES);

	return(-1);
}
// -----------------------------------------------------------------------------
void CEntityMgr::DeleteEntity(CEntity *_poEnt)
{
	for (int i=0;i<MAX_ENTITIES;i++)
	{
		if (m_poList[i] == _poEnt)
			m_poList[i] = NULL;
	}
}
// -----------------------------------------------------------------------------
CEntity *CEntityMgr::poGetEntity(int _iEntID)
{
	return ( m_poList[_iEntID] );
}
// -----------------------------------------------------------------------------