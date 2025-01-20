



#include "GammaE_Mem.h"

// SCNUt_AdjTriList
#include "ScnStripifier\SCNUt_AdjTriList.h"


// Class SCNUt_AdjTriList 



SCNUt_AdjTriList::SCNUt_AdjTriList()
        : iNumTris(0), Tri(NULL)
      {
}


SCNUt_AdjTriList::~SCNUt_AdjTriList()
{
  	if (Tri) mDel[]Tri;
}



void SCNUt_AdjTriList::Init (int _iNumTris)
{
  	iNumTris = _iNumTris;
	Tri      = mNew SCNUt_AdjTri[iNumTris];	
}

// Additional Declarations
    
