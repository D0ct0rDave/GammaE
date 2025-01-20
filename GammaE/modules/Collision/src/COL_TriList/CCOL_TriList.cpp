//	  %X% %Q% %Z% %W%




#include "GammaE_Mem.h"

// CCOL_TriList
#include "COL_TriList\CCOL_TriList.h"


// Class CCOL_TriList 








CCOL_TriList::CCOL_TriList()
        : iMaxTris(0), iNumTris(0), poVXs(NULL), poVNs(NULL), piMats(NULL), pfFrameFacts(NULL)
      {
}


CCOL_TriList::~CCOL_TriList()
{
  	if (poVXs)	mDel []poVXs;
	if (poVNs)	mDel []poVNs;
	if (piMats)	mDel []piMats;
	if (pfFrameFacts) mDel []pfFrameFacts;
}



void CCOL_TriList::Init (int _iMaxTris)
{
    	iMaxTris = _iMaxTris;
	iNumTris = 0;

	poVXs  = mNew CVect3[iMaxTris*3];
	poVNs  = mNew CVect3[iMaxTris];
	piMats = mNew int[iMaxTris];
	pfFrameFacts = mNew float[iMaxTris];
}

// Additional Declarations
    
