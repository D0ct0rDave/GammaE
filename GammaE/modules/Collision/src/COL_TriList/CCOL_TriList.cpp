//## begin module%3C1D01EF00DE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1D01EF00DE.cm

//## begin module%3C1D01EF00DE.cp preserve=no
//## end module%3C1D01EF00DE.cp

//## Module: CCOL_TriList%3C1D01EF00DE; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_TriList\CCOL_TriList.cpp

//## begin module%3C1D01EF00DE.additionalIncludes preserve=no
//## end module%3C1D01EF00DE.additionalIncludes

//## begin module%3C1D01EF00DE.includes preserve=yes
#include "Memory/GammaE_Mem.h"
//## end module%3C1D01EF00DE.includes

// CCOL_TriList
#include "Collision\COL_TriList\CCOL_TriList.h"
//## begin module%3C1D01EF00DE.additionalDeclarations preserve=yes
//## end module%3C1D01EF00DE.additionalDeclarations


// Class CCOL_TriList 








CCOL_TriList::CCOL_TriList()
  //## begin CCOL_TriList::CCOL_TriList%.hasinit preserve=no
      : iMaxTris(0), iNumTris(0), poVXs(NULL), poVNs(NULL), piMats(NULL), pfFrameFacts(NULL)
  //## end CCOL_TriList::CCOL_TriList%.hasinit
  //## begin CCOL_TriList::CCOL_TriList%.initialization preserve=yes
  //## end CCOL_TriList::CCOL_TriList%.initialization
{
  //## begin CCOL_TriList::CCOL_TriList%.body preserve=yes
  //## end CCOL_TriList::CCOL_TriList%.body
}


CCOL_TriList::~CCOL_TriList()
{
  //## begin CCOL_TriList::~CCOL_TriList%.body preserve=yes
	if (poVXs)	mDel []poVXs;
	if (poVNs)	mDel []poVNs;
	if (piMats)	mDel []piMats;
	if (pfFrameFacts) mDel []pfFrameFacts;
  //## end CCOL_TriList::~CCOL_TriList%.body
}



//## Other Operations (implementation)
void CCOL_TriList::Init (int _iMaxTris)
{
  //## begin CCOL_TriList::Init%1008534184.body preserve=yes
  	iMaxTris = _iMaxTris;
	iNumTris = 0;

	poVXs  = mNew CVect3[iMaxTris*3];
	poVNs  = mNew CVect3[iMaxTris];
	piMats = mNew int[iMaxTris];
	pfFrameFacts = mNew float[iMaxTris];
  //## end CCOL_TriList::Init%1008534184.body
}

// Additional Declarations
  //## begin CCOL_TriList%3C1D01EF00DE.declarations preserve=yes
  //## end CCOL_TriList%3C1D01EF00DE.declarations

//## begin module%3C1D01EF00DE.epilog preserve=yes
//## end module%3C1D01EF00DE.epilog
