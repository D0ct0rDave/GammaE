//## begin module%3BD352610028.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD352610028.cm

//## begin module%3BD352610028.cp preserve=no
//## end module%3BD352610028.cp

//## Module: CLookupEntry%3BD352610028; Pseudo Package body
//## Source file: i:\Projects\GammaE\Misc\TAD\CLookupEntry.cpp

//## begin module%3BD352610028.additionalIncludes preserve=no
//## end module%3BD352610028.additionalIncludes

//## begin module%3BD352610028.includes preserve=yes
#include <string.h>
#include "memory/gammae_mem.h"
//## end module%3BD352610028.includes

// CLookupEntry
#include "Misc\TAD\CLookupEntry.h"
//## begin module%3BD352610028.additionalDeclarations preserve=yes
//## end module%3BD352610028.additionalDeclarations


// Class CLookupEntry 




CLookupEntry::CLookupEntry()
  //## begin CLookupEntry::CLookupEntry%.hasinit preserve=no
      : szString(NULL), pValue(NULL)
  //## end CLookupEntry::CLookupEntry%.hasinit
  //## begin CLookupEntry::CLookupEntry%.initialization preserve=yes
  //## end CLookupEntry::CLookupEntry%.initialization
{
  //## begin CLookupEntry::CLookupEntry%.body preserve=yes
  //## end CLookupEntry::CLookupEntry%.body
}


CLookupEntry::~CLookupEntry()
{
  //## begin CLookupEntry::~CLookupEntry%.body preserve=yes
	if (szString) mDel []szString;
  //## end CLookupEntry::~CLookupEntry%.body
}



//## Other Operations (implementation)
void CLookupEntry::Init (char *_szString, void *_pValue)
{
  //## begin CLookupEntry::Init%1003698096.body preserve=yes
	if (szString) mDel []szString;

	szString = mNew char[ strlen(_szString) + 1 ];

	strcpy(szString,_szString);
	pValue = _pValue;
  //## end CLookupEntry::Init%1003698096.body
}

// Additional Declarations
  //## begin CLookupEntry%3BD352610028.declarations preserve=yes
  //## end CLookupEntry%3BD352610028.declarations

//## begin module%3BD352610028.epilog preserve=yes
//## end module%3BD352610028.epilog
