
#include "Game\Entities\CWorldEntityList.h"

CWorldEntityList::CWorldEntityList()
{

}


CWorldEntityList::~CWorldEntityList()
{
}

void CWorldEntityList::Think (float _fDelta)
{
	int cEnt;	

	// Player,AI,other entities	thinking
	for (cEnt=0;cEnt < poEnt.iNumElems();cEnt++)	
	{
		if (poEnt.poElem(cEnt))
			(*poEnt.poElem(cEnt))->Think(_fDelta);
	}
	
	// Process the commands generated int Think step
	for (cEnt=0;cEnt < poEnt.iNumElems();cEnt++)	
	{
		if (poEnt.poElem(cEnt))
			(*poEnt.poElem(cEnt))->ProcessCmds(_fDelta);
	}
	
	// Perform player and other entities interaction
	for (cEnt=0;cEnt < poEnt.iNumElems();cEnt++)	
	{
		if (poEnt.poElem(cEnt))
			(*poEnt.poElem(cEnt))->Interact(_fDelta);
	}
}

void CWorldEntityList::Init (int _iMaxEntities)
{ 
	poEnt.Init(_iMaxEntities);
}