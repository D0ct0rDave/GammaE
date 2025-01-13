//## begin module%3C321D0D033F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C321D0D033F.cm

//## begin module%3C321D0D033F.cp preserve=no
//## end module%3C321D0D033F.cp

//## Module: SCNUt_AdjTriList%3C321D0D033F; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_AdjTriList.cpp

//## begin module%3C321D0D033F.additionalIncludes preserve=no
//## end module%3C321D0D033F.additionalIncludes

//## begin module%3C321D0D033F.includes preserve=yes
#include "Memory/GammaE_mem.h"
#include "stdlib.h"
//## end module%3C321D0D033F.includes

// SCNUt_AdjTriList
#include "Scene\SceneUtils\ScnStripifier\SCNUt_AdjTriList.h"
//## begin module%3C321D0D033F.additionalDeclarations preserve=yes
//## end module%3C321D0D033F.additionalDeclarations


// Class SCNUt_AdjTriList 



SCNUt_AdjTriList::SCNUt_AdjTriList()
  //## begin SCNUt_AdjTriList::SCNUt_AdjTriList%.hasinit preserve=no
      : iNumTris(0), Tri(NULL)
  //## end SCNUt_AdjTriList::SCNUt_AdjTriList%.hasinit
  //## begin SCNUt_AdjTriList::SCNUt_AdjTriList%.initialization preserve=yes
  //## end SCNUt_AdjTriList::SCNUt_AdjTriList%.initialization
{
  //## begin SCNUt_AdjTriList::SCNUt_AdjTriList%.body preserve=yes
  //## end SCNUt_AdjTriList::SCNUt_AdjTriList%.body
}


SCNUt_AdjTriList::~SCNUt_AdjTriList()
{
  //## begin SCNUt_AdjTriList::~SCNUt_AdjTriList%.body preserve=yes
	if (Tri) mDel[]Tri;
  //## end SCNUt_AdjTriList::~SCNUt_AdjTriList%.body
}



//## Other Operations (implementation)
void SCNUt_AdjTriList::Init (int _iNumTris)
{
  //## begin SCNUt_AdjTriList::Init%1009917118.body preserve=yes
	iNumTris = _iNumTris;
	Tri      = mNew SCNUt_AdjTri[iNumTris];	
  //## end SCNUt_AdjTriList::Init%1009917118.body
}

// Additional Declarations
  //## begin SCNUt_AdjTriList%3C321D0D033F.declarations preserve=yes
  //## end SCNUt_AdjTriList%3C321D0D033F.declarations

//## begin module%3C321D0D033F.epilog preserve=yes
//## end module%3C321D0D033F.epilog
