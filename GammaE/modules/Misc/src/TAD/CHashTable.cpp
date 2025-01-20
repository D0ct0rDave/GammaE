//## begin module%3BD351ED02AC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD351ED02AC.cm

//## begin module%3BD351ED02AC.cp preserve=no
//## end module%3BD351ED02AC.cp

//## Module: CHashTable%3BD351ED02AC; Pseudo Package body
//## Source file: i:\Projects\GammaE\Misc\TAD\CHashTable.cpp

//## begin module%3BD351ED02AC.additionalIncludes preserve=no
//## end module%3BD351ED02AC.additionalIncludes

//## begin module%3BD351ED02AC.includes preserve=yes
#include <assert.h>
#include "memory/gammae_mem.h"
//## end module%3BD351ED02AC.includes

// CHashTable
#include "Misc\TAD\CHashTable.h"
//## begin module%3BD351ED02AC.additionalDeclarations preserve=yes
//## end module%3BD351ED02AC.additionalDeclarations


// Class CHashTable 



CHashTable::CHashTable()
  //## begin CHashTable::CHashTable%.hasinit preserve=no
      : iNumCols(0), Elems(NULL)
  //## end CHashTable::CHashTable%.hasinit
  //## begin CHashTable::CHashTable%.initialization preserve=yes
  //## end CHashTable::CHashTable%.initialization
{
  //## begin CHashTable::CHashTable%.body preserve=yes
  //## end CHashTable::CHashTable%.body
}


CHashTable::~CHashTable()
{
  //## begin CHashTable::~CHashTable%.body preserve=yes
	if (Elems) mDel []Elems;
  //## end CHashTable::~CHashTable%.body
}



//## Other Operations (implementation)
void CHashTable::Init (int _iRows, int _iCols)
{
  //## begin CHashTable::Init%1003698088.body preserve=yes
	if (Elems) mDel []Elems;

	iNumCols = _iCols;
	Elems = mNew CLookupArray[_iCols];

	for (int i=0;i<_iCols;i++)
		Elems[i].Init(_iRows);

  //## end CHashTable::Init%1003698088.body
}

void CHashTable::AddVar (char *_szString, void *_pValue)
{
  //## begin CHashTable::AddVar%1003698089.body preserve=yes
	int iIndex = iGetIndex(_szString);
	Elems[iIndex].AddVar(_szString,_pValue);
  //## end CHashTable::AddVar%1003698089.body
}

void * CHashTable::pGetVar (char *_szString)
{
  //## begin CHashTable::pGetVar%1003698090.body preserve=yes
	int iIndex = iGetIndex(_szString);
	return ( Elems[iIndex].pGetVar(_szString) );
  //## end CHashTable::pGetVar%1003698090.body
}

int CHashTable::iGetIndex (char *_szString)
{
  //## begin CHashTable::iGetIndex%1003698092.body preserve=yes
	int iRes = 0;
	
	// Hash function
	while (*_szString) 
	{
		iRes += (int)*_szString;
		_szString++;
	}

	return (iRes % iNumCols);
  //## end CHashTable::iGetIndex%1003698092.body
}

// Additional Declarations
  //## begin CHashTable%3BD351ED02AC.declarations preserve=yes
  //## end CHashTable%3BD351ED02AC.declarations

//## begin module%3BD351ED02AC.epilog preserve=yes
//## end module%3BD351ED02AC.epilog
