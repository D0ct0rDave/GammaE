//## begin module%3B62D89300C8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B62D89300C8.cm

//## begin module%3B62D89300C8.cp preserve=no
//## end module%3B62D89300C8.cp

//## Module: CGameListEntity%3B62D89300C8; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\CGameListEntity.cpp

//## begin module%3B62D89300C8.additionalIncludes preserve=no
//## end module%3B62D89300C8.additionalIncludes

//## begin module%3B62D89300C8.includes preserve=yes
#include "memory/GammaE_mem.h"
#include <string.h>
//## end module%3B62D89300C8.includes

// CGameListEntity
#include "Game\Entities\CGameListEntity.h"
//## begin module%3B62D89300C8.additionalDeclarations preserve=yes
//## end module%3B62D89300C8.additionalDeclarations


// Class CGameListEntity 




CGameListEntity::CGameListEntity()
  //## begin CGameListEntity::CGameListEntity%.hasinit preserve=no
      : poEntities(NULL), iMaxEntities(0), iNumEntities(0)
  //## end CGameListEntity::CGameListEntity%.hasinit
  //## begin CGameListEntity::CGameListEntity%.initialization preserve=yes
  //## end CGameListEntity::CGameListEntity%.initialization
{
  //## begin CGameListEntity::CGameListEntity%.body preserve=yes
  //## end CGameListEntity::CGameListEntity%.body
}


CGameListEntity::~CGameListEntity()
{
  //## begin CGameListEntity::~CGameListEntity%.body preserve=yes
  	if (poEntities) mDel  []poEntities;
  //## end CGameListEntity::~CGameListEntity%.body
}



//## Other Operations (implementation)
void CGameListEntity::Think (float _fDelta)
{
  //## begin CGameListEntity::Think%996332272.body preserve=yes
	int cEnt;	

	for (cEnt=0;cEnt < iNumEntities;cEnt++)	
	{
		if (poEntities[cEnt])
		{
			poEntities[cEnt]->Think(_fDelta);

			if (poEntities[cEnt]->Destroy)
			{
				mDel (poEntities[cEnt]);
				poEntities[cEnt] = NULL;
			}
		}
	}
  //## end CGameListEntity::Think%996332272.body
}

void CGameListEntity::Init (int _iMaxEntities)
{
  //## begin CGameListEntity::Init%996332273.body preserve=yes
	iMaxEntities = _iMaxEntities;
	iNumEntities = 0;
	poEntities    = mNew CGameEntity *[_iMaxEntities];

	memset(poEntities,0,sizeof(CGameEntity *)*iMaxEntities);
  //## end CGameListEntity::Init%996332273.body
}

int CGameListEntity::iAddEntity (CGameEntity* _pEntity)
{
  //## begin CGameListEntity::iAddEntity%996522676.body preserve=yes
	assert (poEntities && "Undefined entity array");

	poEntities[iNumEntities++] = _pEntity;
	return(iNumEntities-1);
  //## end CGameListEntity::iAddEntity%996522676.body
}

void CGameListEntity::SetEntity (int _iEntNum, CGameEntity *_pEntity)
{
  //## begin CGameListEntity::SetEntity%996332274.body preserve=yes
	assert (poEntities && "Undefined entity array");
	assert ((_iEntNum < iNumEntities) && "Entity overflow");

	poEntities[_iEntNum] = _pEntity;
  //## end CGameListEntity::SetEntity%996332274.body
}

CGameEntity * CGameListEntity::poGetEntity (int _iEntNum)
{
  //## begin CGameListEntity::poGetEntity%996522677.body preserve=yes
  	assert (poEntities && "Undefined entity array");
	assert ((_iEntNum < iNumEntities) && "Entity overflow");
	return ( poEntities[_iEntNum] );
  //## end CGameListEntity::poGetEntity%996522677.body
}

void CGameListEntity::Reset ()
{
  //## begin CGameListEntity::Reset%1021237867.body preserve=yes
	iNumEntities=0;
  //## end CGameListEntity::Reset%1021237867.body
}

void CGameListEntity::ProcessCmds (float _fDelta)
{
  //## begin CGameListEntity::ProcessCmds%1021565345.body preserve=yes
	int cEnt;	

	for (cEnt=0;cEnt < iNumEntities;cEnt++)	
	{
		if (poEntities[cEnt])
			poEntities[cEnt]->ProcessCmds(_fDelta);
	}
  //## end CGameListEntity::ProcessCmds%1021565345.body
}

void CGameListEntity::Interact (float _fDelta)
{
  //## begin CGameListEntity::Interact%1021565347.body preserve=yes
	int cEnt;	

	for (cEnt=0;cEnt < iNumEntities;cEnt++)	
	{
		if (poEntities[cEnt])
			poEntities[cEnt]->Interact(_fDelta);
	}
  //## end CGameListEntity::Interact%1021565347.body
}

// Additional Declarations
  //## begin CGameListEntity%3B62D89300C8.declarations preserve=yes
  //## end CGameListEntity%3B62D89300C8.declarations

//## begin module%3B62D89300C8.epilog preserve=yes
//## end module%3B62D89300C8.epilog
