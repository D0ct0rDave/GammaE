//## begin module%3C3082000041.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C3082000041.cm

//## begin module%3C3082000041.cp preserve=no
//## end module%3C3082000041.cp

//## Module: SCNUt_EdgeList%3C3082000041; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_EdgeList.cpp

//## begin module%3C3082000041.additionalIncludes preserve=no
//## end module%3C3082000041.additionalIncludes

//## begin module%3C3082000041.includes preserve=yes
#include <string.h>
#include "Memory/GammaE_mem.h"
//## end module%3C3082000041.includes

// SCNUt_EdgeList
#include "Scene\SceneUtils\ScnStripifier\SCNUt_EdgeList.h"
//## begin module%3C3082000041.additionalDeclarations preserve=yes
//## end module%3C3082000041.additionalDeclarations


// Class SCNUt_EdgeList 




SCNUt_EdgeList::SCNUt_EdgeList()
  //## begin SCNUt_EdgeList::SCNUt_EdgeList%.hasinit preserve=no
      : iNumEdges(0), iMaxEdges(0), Edge(NULL)
  //## end SCNUt_EdgeList::SCNUt_EdgeList%.hasinit
  //## begin SCNUt_EdgeList::SCNUt_EdgeList%.initialization preserve=yes
  //## end SCNUt_EdgeList::SCNUt_EdgeList%.initialization
{
  //## begin SCNUt_EdgeList::SCNUt_EdgeList%.body preserve=yes
  //## end SCNUt_EdgeList::SCNUt_EdgeList%.body
}


SCNUt_EdgeList::~SCNUt_EdgeList()
{
  //## begin SCNUt_EdgeList::~SCNUt_EdgeList%.body preserve=yes
	if (Edge) mDel[]Edge;
  //## end SCNUt_EdgeList::~SCNUt_EdgeList%.body
}



//## Other Operations (implementation)
int SCNUt_EdgeList::iAdd (SCNUt_Edge& _roEdge)
{
  //## begin SCNUt_EdgeList::iAdd%1009811894.body preserve=yes
	
	// first search whether the given edge exists or not
	int iEdge;
	for (iEdge=0;iEdge<iNumEdges;iEdge++)
	{
		if (
			((Edge[iEdge].A == _roEdge.A) && (Edge[iEdge].B == _roEdge.B)) ||
			((Edge[iEdge].A == _roEdge.B) && (Edge[iEdge].B == _roEdge.A))
			)
			return(iEdge);
	}
	
	// Need to realloc??
	if (iNumEdges==iMaxEdges)
	{		
		SCNUt_Edge *poEdges;
		
		iMaxEdges += 100;
		poEdges    = mNew SCNUt_Edge[iMaxEdges];
		memcpy(poEdges,Edge,iNumEdges*sizeof(SCNUt_Edge));
		mDel []Edge;
		Edge = poEdges;
	}

	Edge[iNumEdges].A = _roEdge.A;
	Edge[iNumEdges].B = _roEdge.B;

	iNumEdges++;

	return (iNumEdges-1);
  //## end SCNUt_EdgeList::iAdd%1009811894.body
}

void SCNUt_EdgeList::Clear ()
{
  //## begin SCNUt_EdgeList::Clear%1009811895.body preserve=yes
	iNumEdges = 0;
  //## end SCNUt_EdgeList::Clear%1009811895.body
}

// Additional Declarations
  //## begin SCNUt_EdgeList%3C3082000041.declarations preserve=yes
  //## end SCNUt_EdgeList%3C3082000041.declarations

//## begin module%3C3082000041.epilog preserve=yes
//## end module%3C3082000041.epilog
