//## begin module%3BD353840026.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD353840026.cm

//## begin module%3BD353840026.cp preserve=no
//## end module%3BD353840026.cp

//## Module: CLookupArray%3BD353840026; Pseudo Package body
//## Source file: i:\Projects\GammaE\Misc\TAD\CLookupArray.cpp

//## begin module%3BD353840026.additionalIncludes preserve=no
//## end module%3BD353840026.additionalIncludes

//## begin module%3BD353840026.includes preserve=yes
#include <assert.h>
#include <string.h>

#include "memory/gammae_mem.h"
//## end module%3BD353840026.includes

// CLookupArray
#include "Misc\TAD\CLookupArray.h"
//## begin module%3BD353840026.additionalDeclarations preserve=yes
//## end module%3BD353840026.additionalDeclarations


// Class CLookupArray 





CLookupArray::CLookupArray()
  //## begin CLookupArray::CLookupArray%.hasinit preserve=no
      : iNumElems(0), iMaxElems(0), Elems(NULL)
  //## end CLookupArray::CLookupArray%.hasinit
  //## begin CLookupArray::CLookupArray%.initialization preserve=yes
  //## end CLookupArray::CLookupArray%.initialization
{
  //## begin CLookupArray::CLookupArray%.body preserve=yes
  //## end CLookupArray::CLookupArray%.body
}


CLookupArray::~CLookupArray()
{
  //## begin CLookupArray::~CLookupArray%.body preserve=yes
  //## end CLookupArray::~CLookupArray%.body
}



//## Other Operations (implementation)
void CLookupArray::Init (int _iMaxElems)
{
  //## begin CLookupArray::Init%1003698093.body preserve=yes
	if (Elems) mDel []Elems;

	iMaxElems = _iMaxElems;
	iNumElems = 0;
	Elems     = mNew CLookupEntry[_iMaxElems];
  //## end CLookupArray::Init%1003698093.body
}

int CLookupArray::AddVar (char* _szString, void *_pValue)
{
  //## begin CLookupArray::AddVar%1003698094.body preserve=yes
	assert (Elems && "NULL elem array");
	if (iNumElems == iMaxElems) return (-1);

	Elems[iNumElems++].Init(_szString,_pValue);

	return (iNumElems-1);
  //## end CLookupArray::AddVar%1003698094.body
}

void * CLookupArray::pGetVar (char* _szString)
{
  //## begin CLookupArray::pGetVar%1003698095.body preserve=yes
	assert (Elems && "NULL elem array");
	
	for (int i=0;i<iNumElems;i++)
	{
		if (! strcmp(Elems[i].szString,_szString))
			return (Elems[i].pValue);
	}

	return (NULL);
  //## end CLookupArray::pGetVar%1003698095.body
}

// Additional Declarations
  //## begin CLookupArray%3BD353840026.declarations preserve=yes
  //## end CLookupArray%3BD353840026.declarations

//## begin module%3BD353840026.epilog preserve=yes
//## end module%3BD353840026.epilog
