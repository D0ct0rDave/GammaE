//## begin module%3C321D3802F1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C321D3802F1.cm

//## begin module%3C321D3802F1.cp preserve=no
//## end module%3C321D3802F1.cp

//## Module: SCNUt_AdjTriListBuilder%3C321D3802F1; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_AdjTriListBuilder.cpp

//## begin module%3C321D3802F1.additionalIncludes preserve=no
//## end module%3C321D3802F1.additionalIncludes

//## begin module%3C321D3802F1.includes preserve=yes
#include <string.h>
#include "Memory/GammaE_mem.h"
//## end module%3C321D3802F1.includes

// SCNUt_AdjTriListBuilder
#include "Scene\SceneUtils\ScnStripifier\SCNUt_AdjTriListBuilder.h"
//## begin module%3C321D3802F1.additionalDeclarations preserve=yes
//## end module%3C321D3802F1.additionalDeclarations


// Class SCNUt_AdjTriListBuilder 

SCNUt_AdjTriListBuilder::SCNUt_AdjTriListBuilder()
  //## begin SCNUt_AdjTriListBuilder::SCNUt_AdjTriListBuilder%.hasinit preserve=no
  //## end SCNUt_AdjTriListBuilder::SCNUt_AdjTriListBuilder%.hasinit
  //## begin SCNUt_AdjTriListBuilder::SCNUt_AdjTriListBuilder%.initialization preserve=yes
  //## end SCNUt_AdjTriListBuilder::SCNUt_AdjTriListBuilder%.initialization
{
  //## begin SCNUt_AdjTriListBuilder::SCNUt_AdjTriListBuilder%.body preserve=yes
  //## end SCNUt_AdjTriListBuilder::SCNUt_AdjTriListBuilder%.body
}


SCNUt_AdjTriListBuilder::~SCNUt_AdjTriListBuilder()
{
  //## begin SCNUt_AdjTriListBuilder::~SCNUt_AdjTriListBuilder%.body preserve=yes
  //## end SCNUt_AdjTriListBuilder::~SCNUt_AdjTriListBuilder%.body
}



//## Other Operations (implementation)
SCNUt_AdjTriList* SCNUt_AdjTriListBuilder::poBuild (CMesh* _poMesh, CMesh *&_rpoOutMesh)
{
  //## begin SCNUt_AdjTriListBuilder::poBuild%1009917119.body preserve=yes
	if (! _poMesh) return(NULL);
	
	SCNUt_TriScene		*poTS;
	SCNUt_Mesh2TriScene	oM2TS;
	SCNUt_MeshCompacter	oMComp;
	SCNUt_AdjTriList	*poATL;

	// Generate a raw triangle scene
	poTS = oM2TS.Generate(*_poMesh,0);

	// Generate a compact mesh
	_rpoOutMesh = oMComp.CompactMesh(*poTS);
	
	// Build the triangle adjacency list
	poATL = poBuild_FromIndexedTriMesh (_rpoOutMesh);

	// Delete triangle scene
	mDel poTS;

	return (poATL);
  //## end SCNUt_AdjTriListBuilder::poBuild%1009917119.body
}

SCNUt_AdjTriList * SCNUt_AdjTriListBuilder::poBuild_FromIndexedTriMesh (CMesh* _poMesh)
{
  //## begin SCNUt_AdjTriListBuilder::poBuild_FromIndexedTriMesh%1009917121.body preserve=yes
	SCNUt_AdjTriList	*poATL;
	int					iTri;
	int					iA,iB;

	// Create and init Adjacent Triangle List
	poATL = mNew SCNUt_AdjTriList;
	poATL->Init(_poMesh->usNumPrims);

	for (iTri=0;iTri<_poMesh->usNumPrims;iTri++)
	{
		poATL->Tri[iTri].Visited    = false;
		poATL->Tri[iTri].iNumNeighs = 0;
		poATL->Tri[iTri].Neigh      = NULL;

		// Vertex 0		
		iA = _poMesh->Idxs[iTri*3+0];
		iB = _poMesh->Idxs[iTri*3+1];
		AddEdgeNeighs(_poMesh,poATL,iTri,iA,iB);
		
		// Vertex 1
		iA = _poMesh->Idxs[iTri*3+1];
		iB = _poMesh->Idxs[iTri*3+2];
		AddEdgeNeighs(_poMesh,poATL,iTri,iA,iB);

		// Vertex 2
		iA = _poMesh->Idxs[iTri*3+2];
		iB = _poMesh->Idxs[iTri*3+0];
		AddEdgeNeighs(_poMesh,poATL,iTri,iA,iB);
	}

	return(poATL);
  //## end SCNUt_AdjTriListBuilder::poBuild_FromIndexedTriMesh%1009917121.body
}

void SCNUt_AdjTriListBuilder::AddEdgeNeighs (CMesh* _poMesh, SCNUt_AdjTriList *_poATL, int _iTri, int _iA, int _iB)
{
  //## begin SCNUt_AdjTriListBuilder::AddEdgeNeighs%1009920806.body preserve=yes
	int	iTri;
	int	iA,iB;

	for (iTri=0;iTri<_poMesh->usNumPrims;iTri++)
	{
		if (iTri != _iTri)
		{
			// Vertex 0		
			iA = _poMesh->Idxs[iTri*3+0];
			iB = _poMesh->Idxs[iTri*3+1];
			if ( ((iA == _iA) && (iB == _iB)) || ((iA == _iB) && (iB == _iA)) )
				_poATL->Tri[_iTri].AddNeigh(iTri);
					
			// Vertex 1
			iA = _poMesh->Idxs[iTri*3+1];
			iB = _poMesh->Idxs[iTri*3+2];
			if ( ((iA == _iA) && (iB == _iB)) || ((iA == _iB) && (iB == _iA)) )
				_poATL->Tri[_iTri].AddNeigh(iTri);

			// Vertex 2
			iA = _poMesh->Idxs[iTri*3+2];
			iB = _poMesh->Idxs[iTri*3+0];
			if ( ((iA == _iA) && (iB == _iB)) || ((iA == _iB) && (iB == _iA)) )
				_poATL->Tri[_iTri].AddNeigh(iTri);
		}
	}
  //## end SCNUt_AdjTriListBuilder::AddEdgeNeighs%1009920806.body
}

// Additional Declarations
  //## begin SCNUt_AdjTriListBuilder%3C321D3802F1.declarations preserve=yes
  //## end SCNUt_AdjTriListBuilder%3C321D3802F1.declarations

//## begin module%3C321D3802F1.epilog preserve=yes
//## end module%3C321D3802F1.epilog
