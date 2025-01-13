//## begin module%3C321C5F038F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C321C5F038F.cm

//## begin module%3C321C5F038F.cp preserve=no
//## end module%3C321C5F038F.cp

//## Module: SCNUt_AdjTri%3C321C5F038F; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_AdjTri.cpp

//## begin module%3C321C5F038F.additionalIncludes preserve=no
//## end module%3C321C5F038F.additionalIncludes

//## begin module%3C321C5F038F.includes preserve=yes
//## end module%3C321C5F038F.includes

// SCNUt_AdjTri
#include "Scene\SceneUtils\ScnStripifier\SCNUt_AdjTri.h"
//## begin module%3C321C5F038F.additionalDeclarations preserve=yes
#include <string.h>
#include "Memory/GammaE_Mem.h"
//## end module%3C321C5F038F.additionalDeclarations


// Class SCNUt_AdjTri 





SCNUt_AdjTri::SCNUt_AdjTri()
  //## begin SCNUt_AdjTri::SCNUt_AdjTri%.hasinit preserve=no
      : iNumNeighs(0), Neigh(NULL), Visited(false)
  //## end SCNUt_AdjTri::SCNUt_AdjTri%.hasinit
  //## begin SCNUt_AdjTri::SCNUt_AdjTri%.initialization preserve=yes
  //## end SCNUt_AdjTri::SCNUt_AdjTri%.initialization
{
  //## begin SCNUt_AdjTri::SCNUt_AdjTri%.body preserve=yes
  //## end SCNUt_AdjTri::SCNUt_AdjTri%.body
}


SCNUt_AdjTri::~SCNUt_AdjTri()
{
  //## begin SCNUt_AdjTri::~SCNUt_AdjTri%.body preserve=yes
  //## end SCNUt_AdjTri::~SCNUt_AdjTri%.body
}



//## Other Operations (implementation)
void SCNUt_AdjTri::AddNeigh (int _iIdx)
{
  //## begin SCNUt_AdjTri::AddNeigh%1009917117.body preserve=yes
	
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
  //## end SCNUt_AdjTri::AddNeigh%1009917117.body
}

// Additional Declarations
  //## begin SCNUt_AdjTri%3C321C5F038F.declarations preserve=yes
  //## end SCNUt_AdjTri%3C321C5F038F.declarations

//## begin module%3C321C5F038F.epilog preserve=yes
//## end module%3C321C5F038F.epilog
