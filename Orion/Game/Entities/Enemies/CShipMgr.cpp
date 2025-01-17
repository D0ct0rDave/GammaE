#include "Game/Entities/Enemies/CShipMgr.h"


CShipMgr::CShipMgr()
{
}

CShipMgr::~CShipMgr()
{
}

void CShipMgr::Init(int _iMaxShips)
{
	oShips.Init(_iMaxShips);
}

void CShipMgr::Add(CShip *poShip)
{
	oShips.iAdd(poShip);
}

void CShipMgr::Think(float _fDelta)
{
	CShip* *poShip;
	for (int iShip=0;iShip<oShips.iMaxElems();iShip++)
	{
		poShip = oShips.poElem(iShip);
		if (poShip) (*poShip)->Think(_fDelta);
	}
}

void CShipMgr::ProcessCmds(float _fDelta)
{
	CShip* *poShip;
	for (int iShip=0;iShip<oShips.iMaxElems();iShip++)
	{
		poShip = oShips.poElem(iShip);
		if (poShip) (*poShip)->ProcessCmds(_fDelta);
	}
}
void CShipMgr::Interact(float _fDelta)
{
	CShip* *poShip;
	for (int iShip=0;iShip<oShips.iMaxElems();iShip++)
	{
		poShip = oShips.poElem(iShip);		
		if (poShip) (*poShip)->Interact(_fDelta);
	}
}

void CShipMgr::ComputeCollisionResponse()
{
	CShip* *poShip;
	for (int iShip=0;iShip<oShips.iMaxElems();iShip++)
	{
		poShip = oShips.poElem(iShip);
		if (poShip) (*poShip)->ComputeCollisionResponse();
	}
}