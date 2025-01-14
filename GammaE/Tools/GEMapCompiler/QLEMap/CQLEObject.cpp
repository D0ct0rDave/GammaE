//## begin module%3CA0F4770124.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F4770124.cm

//## begin module%3CA0F4770124.cp preserve=no
//## end module%3CA0F4770124.cp

//## Module: CQLEObject%3CA0F4770124; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\QLEMap\CQLEObject.cpp

//## begin module%3CA0F4770124.additionalIncludes preserve=no
//## end module%3CA0F4770124.additionalIncludes

//## begin module%3CA0F4770124.includes preserve=yes
#include "memory/GammaE_Mem.h"
#include <string.h>
//## end module%3CA0F4770124.includes

// CQLEObject
#include "Tools\GEMapCompiler\QLEMap\CQLEObject.h"
//## begin module%3CA0F4770124.additionalDeclarations preserve=yes
//## end module%3CA0F4770124.additionalDeclarations


// Class CQLEObject 











CQLEObject::CQLEObject()
  //## begin CQLEObject::CQLEObject%.hasinit preserve=no
      : eObjType(eQLEOT_None), iBrushNum(-1), iEntityNum(-1), iNumChObjs(0), piChObjList(NULL)
  //## end CQLEObject::CQLEObject%.hasinit
  //## begin CQLEObject::CQLEObject%.initialization preserve=yes
  //## end CQLEObject::CQLEObject%.initialization
{
  //## begin CQLEObject::CQLEObject%.body preserve=yes
  //## end CQLEObject::CQLEObject%.body
}


CQLEObject::~CQLEObject()
{
  //## begin CQLEObject::~CQLEObject%.body preserve=yes
  //## end CQLEObject::~CQLEObject%.body
}



//## Other Operations (implementation)
void CQLEObject::AddChildObject (int _iObj)
{
  //## begin CQLEObject::AddChildObject%1017265241.body preserve=yes
	int* piNewChObjs;

	// Allocate space for old + new instructions
	piNewChObjs = mNew int[iNumChObjs+1];

	// Copy old data
	if (piChObjList) 
		memcpy(piNewChObjs,piChObjList,iNumChObjs*sizeof(int));

	// Add new instruction
	piNewChObjs[iNumChObjs] = _iObj;
	
	// delete old data
	if (piChObjList) mDel []piChObjList;

	// Update object
	piChObjList = piNewChObjs;

	iNumChObjs++;
  //## end CQLEObject::AddChildObject%1017265241.body
}

// Additional Declarations
  //## begin CQLEObject%3CA0F4770124.declarations preserve=yes
  //## end CQLEObject%3CA0F4770124.declarations

//## begin module%3CA0F4770124.epilog preserve=yes
//## end module%3CA0F4770124.epilog
