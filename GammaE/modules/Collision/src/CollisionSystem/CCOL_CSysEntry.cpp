//## begin module%3C0C1B8A014B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0C1B8A014B.cm

//## begin module%3C0C1B8A014B.cp preserve=no
//## end module%3C0C1B8A014B.cp

//## Module: CCOL_CSysEntry%3C0C1B8A014B; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\CollisionSystem\CCOL_CSysEntry.cpp

//## begin module%3C0C1B8A014B.additionalIncludes preserve=no
//## end module%3C0C1B8A014B.additionalIncludes

//## begin module%3C0C1B8A014B.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include <string.h>
//## end module%3C0C1B8A014B.includes

// CCOL_CSysEntry
#include "Collision\CollisionSystem\CCOL_CSysEntry.h"
//## begin module%3C0C1B8A014B.additionalDeclarations preserve=yes
//## end module%3C0C1B8A014B.additionalDeclarations


// Class CCOL_CSysEntry 





CCOL_CSysEntry::CCOL_CSysEntry()
  //## begin CCOL_CSysEntry::CCOL_CSysEntry%.hasinit preserve=no
      : pbTested(NULL), iNumTests(0)
  //## end CCOL_CSysEntry::CCOL_CSysEntry%.hasinit
  //## begin CCOL_CSysEntry::CCOL_CSysEntry%.initialization preserve=yes
  //## end CCOL_CSysEntry::CCOL_CSysEntry%.initialization
{
  //## begin CCOL_CSysEntry::CCOL_CSysEntry%.body preserve=yes
  //## end CCOL_CSysEntry::CCOL_CSysEntry%.body
}


CCOL_CSysEntry::~CCOL_CSysEntry()
{
  //## begin CCOL_CSysEntry::~CCOL_CSysEntry%.body preserve=yes
  //## end CCOL_CSysEntry::~CCOL_CSysEntry%.body
}



//## Other Operations (implementation)
void CCOL_CSysEntry::Tested (int _iIdx)
{
  //## begin CCOL_CSysEntry::Tested%1007421149.body preserve=yes
	assert ( pbTested && "NULL Testing array");
	assert ((_iIdx < iNumTests) && "Test index out of bounds");
	pbTested[_iIdx] = true;
  //## end CCOL_CSysEntry::Tested%1007421149.body
}

bool CCOL_CSysEntry::bTested (int _iIdx)
{
  //## begin CCOL_CSysEntry::bTested%1007421150.body preserve=yes
	assert ( pbTested && "NULL Testing array");
	assert ((_iIdx < iNumTests) && "Test index out of bounds");
	return(pbTested[_iIdx]);
  //## end CCOL_CSysEntry::bTested%1007421150.body
}

void CCOL_CSysEntry::Init (int _iNumTests)
{
  //## begin CCOL_CSysEntry::Init%1007421151.body preserve=yes
	iNumTests = _iNumTests;
	pbTested = mNew bool[_iNumTests];
  //## end CCOL_CSysEntry::Init%1007421151.body
}

void CCOL_CSysEntry::Reset ()
{
  //## begin CCOL_CSysEntry::Reset%1007421152.body preserve=yes
	assert ( pbTested && "NULL Testing array");	
	memset(pbTested,0,iNumTests*sizeof(bool));
	
	ColObj->Reset();
  //## end CCOL_CSysEntry::Reset%1007421152.body
}

// Additional Declarations
  //## begin CCOL_CSysEntry%3C0C1B8A014B.declarations preserve=yes
  //## end CCOL_CSysEntry%3C0C1B8A014B.declarations

//## begin module%3C0C1B8A014B.epilog preserve=yes
//## end module%3C0C1B8A014B.epilog
