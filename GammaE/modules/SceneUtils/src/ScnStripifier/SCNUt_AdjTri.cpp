




// SCNUt_AdjTri
#include "ScnStripifier\SCNUt_AdjTri.h"
#include <string.h>
#include "GammaE_Mem.h"


// Class SCNUt_AdjTri 





SCNUt_AdjTri::SCNUt_AdjTri()
        : iNumNeighs(0), Neigh(NULL), Visited(false)
      {
}


SCNUt_AdjTri::~SCNUt_AdjTri()
{
}



void SCNUt_AdjTri::AddNeigh (int _iIdx)
{
  	
	if (Neigh)
	{
		// first search whether the given edge exists or not
		int iNeigh;
		for (iNeigh=0;iNeigh<iNumNeighs;iNeigh++)
			if ( Neigh[iNeigh] == _iIdx) return;			
	}

	// Realloc
	int		*piNeighs;
	piNeighs = mNew int[iNumNeighs+1];
	memcpy(piNeighs,Neigh,iNumNeighs*sizeof(int));
	mDel []Neigh;
	
	// Update info
	Neigh = piNeighs;
	Neigh[iNumNeighs] = _iIdx;	// Setup new neigh
	iNumNeighs++;	
}

// Additional Declarations
    
