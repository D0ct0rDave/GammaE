//-----------------------------------------------------------------------------
#include "CGGameEntitySpawner.h"
//-----------------------------------------------------------------------------
void CGGameEntitySpawner::Init(uint _uiMaxEntities)
{
	// Initialize the spawn array
	m_oEntities.Init(_uiMaxEntities);	
}
//-----------------------------------------------------------------------------
void CGGameEntitySpawner::Spawn(CGGameEntity* _poEnt,float _fTime)
{
	if (_poEnt == NULL) return;

	// Add the entity
	TSpawnEntityPair* poSEP = m_oEntities.poGet();

	poSEP->m_poEntity	= _poEnt;
	poSEP->m_fTime		= _fTime;
}
//-----------------------------------------------------------------------------
void CGGameEntitySpawner::Think(float _fDeltaT)
{
	for (uint i=0;i<m_oEntities.uiMaxElems();)
	{
		TSpawnEntityPair* poSEP = m_oEntities.poElem(i);

		if (poSEP)
		{
			poSEP->m_fTime -= _fDeltaT;
			
			if (poSEP->m_fTime < 0.0f)
			{
				// Spawn the entity
				poSEP->m_poEntity->Spawn();
				poSEP->m_fTime = 0.0f;

				// Take this from the array
				m_oEntities.Release(poSEP);
			}
			else
				i++;
		}
		else
			i++;
	}
}
//-----------------------------------------------------------------------------
