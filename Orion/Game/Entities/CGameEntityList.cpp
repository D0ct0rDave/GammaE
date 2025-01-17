
#include "Game\Entities\CGameEntityList.h"

CGameEntityList::CGameEntityList()
{

}


CGameEntityList::~CGameEntityList()
{
}

void CGameEntityList::Think (float _fDelta)
{
	int cEnt;	

	for (cEnt=0;cEnt < poEnt.iNumElems();cEnt++)	
	{
		if (poEnt.poElem(cEnt))
			(*poEnt.poElem(cEnt))->Think(_fDelta);
	}
}

void CGameEntityList::Init (int _iMaxEntities)
{ 
	poEnt.Init(_iMaxEntities);
}