//## begin module%3CA0F4370168.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F4370168.cm

//## begin module%3CA0F4370168.cp preserve=no
//## end module%3CA0F4370168.cp

//## Module: CQLEMapScn%3CA0F4370168; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\QLEMap\CQLEMapScn.cpp

//## begin module%3CA0F4370168.additionalIncludes preserve=no
//## end module%3CA0F4370168.additionalIncludes

//## begin module%3CA0F4370168.includes preserve=yes
#include <string.h>
#include "memory/gammae_mem.h"
//## end module%3CA0F4370168.includes

// CQLEMapScn
#include "Tools\GEMapCompiler\QLEMap\CQLEMapScn.h"
//## begin module%3CA0F4370168.additionalDeclarations preserve=yes
//## end module%3CA0F4370168.additionalDeclarations


// Class CQLEMapScn 



CQLEMapScn::CQLEMapScn()
  //## begin CQLEMapScn::CQLEMapScn%.hasinit preserve=no
      : iNumObjs(0), poQLEObj(NULL)
  //## end CQLEMapScn::CQLEMapScn%.hasinit
  //## begin CQLEMapScn::CQLEMapScn%.initialization preserve=yes
  //## end CQLEMapScn::CQLEMapScn%.initialization
{
  //## begin CQLEMapScn::CQLEMapScn%.body preserve=yes
  //## end CQLEMapScn::CQLEMapScn%.body
}


CQLEMapScn::~CQLEMapScn()
{
  //## begin CQLEMapScn::~CQLEMapScn%.body preserve=yes
  //## end CQLEMapScn::~CQLEMapScn%.body
}



//## Other Operations (implementation)
void CQLEMapScn::AddObject (CQLEObject* _poObj)
{
  //## begin CQLEMapScn::AddObject%1017256160.body preserve=yes
	CQLEObject* *poNewObjList;

	// Allocate space for old + new objects
	poNewObjList = mNew CQLEObject*[iNumObjs+1];

	// Copy old data
	if (poQLEObj) 
		memcpy(poNewObjList,poQLEObj,iNumObjs*sizeof(CQLEObject*));

	// Add new instruction
	poNewObjList[iNumObjs] = _poObj;
	
	// delete old data
	if (poQLEObj) mDel []poQLEObj;	// WARNING!: Que borra el puntero al obj o el obj

	// Update object		
	poQLEObj = poNewObjList;

	iNumObjs++;
  //## end CQLEMapScn::AddObject%1017256160.body
}

// Additional Declarations
  //## begin CQLEMapScn%3CA0F4370168.declarations preserve=yes
  //## end CQLEMapScn%3CA0F4370168.declarations

//## begin module%3CA0F4370168.epilog preserve=yes
//## end module%3CA0F4370168.epilog
