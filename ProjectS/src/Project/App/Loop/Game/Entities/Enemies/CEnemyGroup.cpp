//-----------------------------------------------------------------------------
#include "CEnemyGroup.h"
#include "CEnemy.h"
#include "Collision/CGColliderResource.h"
//-----------------------------------------------------------------------------
CEnemyGroup::CEnemyGroup()
{
}
//-----------------------------------------------------------------------------
void CEnemyGroup::Init(unsigned int _uiNumElems,float _fSpawnTime,float _fEnergy,const CGVect3& _oPos,const CGString& _sAIScript,const CGString& _sGraphicRes,const CGString& _sPath)
{
	// Set the spanw time
	m_fSpawnTime = _fSpawnTime;
	
	CGPathResource* poPathRes = NULL;
	if (_sPath != "") poPathRes = CGPathResourceWH::I()->poFind(_sPath);
	if (poPathRes) m_poPath = poPathRes->poGetPath();

	// Create the group
	for (uint i=0;i<_uiNumElems;i++)
	{
		CEnemy* poEnt	= mNew CEnemy;
		
		// Initialize the entity		
		poEnt->Init(_fEnergy,_oPos,_sAIScript,_sGraphicRes,m_poPath,1.0f);

		// Add the entity to the group
		m_oEntLst.uiAdd( poEnt );
	}
	
	// Add entity to the entity manager
	m_uiGID = CGGameEntityMgr::I()->uiRegister(this);

	// 
	Reset();
}
//-----------------------------------------------------------------------------
void CEnemyGroup::Think(float _fDeltaT)
{
	switch ( eGetState() )
	{
		case ENTSTATE_ALIVE:
		{
			if (m_fTime >= (m_poPath->fTime() + m_fSpawnTime*m_oEntLst.uiNumElems()))
			{
				Reset();
				return;
			}
			
			if ((m_fTime >= m_uiSpawnedEnts*m_fSpawnTime) && (m_uiSpawnedEnts<m_oEntLst.uiNumElems()))
			{
				m_oEntLst[m_uiSpawnedEnts]->Spawn();
				m_oEntLst[m_uiSpawnedEnts]->Move(0.0f);	// Set entity initial position
				m_uiSpawnedEnts++;
			}
		}
	}
}
//-----------------------------------------------------------------------------
void CEnemyGroup::Reset()
{
	m_uiSpawnedEnts = 0;

	CGGameEntity::Reset();

	for (uint i=0;i<m_oEntLst.uiNumElems();i++)
		m_oEntLst[i]->Reset();
}
//-----------------------------------------------------------------------------
/*
void CEnemyGroup::OnEnterState(TEntityState _eState)
{
	switch ( _eState )
	{
		case ENTSTATE_ALIVE:
		break;
	}
}
*/
//-----------------------------------------------------------------------------