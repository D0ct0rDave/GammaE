//-----------------------------------------------------------------------------
#include "CGGameEntityMgr.h"

//-----------------------------------------------------------------------------
void CGGameEntityMgr::Think(float _fDeltaT)
{
	for (uint i=0;i<m_oEL.uiNumElems();i++)	
	{
		CGGameEntity* poEnt = m_oEL.oGetElem(i);

		if ((poEnt != NULL) && (poEnt->bIsEnabled()))
		{
			poEnt->PreThink(_fDeltaT);
			poEnt->Think(_fDeltaT);
		}
	}
}
//-----------------------------------------------------------------------------
uint CGGameEntityMgr::uiRegister(CGGameEntity* _poEntity)
{
	return ( m_oEL.uiAddVar(_poEntity->sUID(),_poEntity) );
}
//-----------------------------------------------------------------------------
void CGGameEntityMgr::Remove(CGGameEntity* _poEntity)
{
	int iIdx = m_oEL.iGetElemIdx(_poEntity);
	if (iIdx != -1)
		Remove(iIdx);
}
//-----------------------------------------------------------------------------
void CGGameEntityMgr::Remove(uint _uiEntityIdx)
{
	m_oEL.Del(_uiEntityIdx);
}
//-----------------------------------------------------------------------------
uint CGGameEntityMgr::uiNumEntities()
{
	return( m_oEL.uiNumElems() );
}
//-----------------------------------------------------------------------------
CGGameEntity* CGGameEntityMgr::poGetEntity(uint _uiEntityIdx)
{
	return ( m_oEL.oGetElem(_uiEntityIdx) );
}
//-----------------------------------------------------------------------------
CGGameEntity* CGGameEntityMgr::poGetEntity(const CGString& _sEntity)
{
	return ( m_oEL.oGetVar(_sEntity) );
}
//-----------------------------------------------------------------------------
