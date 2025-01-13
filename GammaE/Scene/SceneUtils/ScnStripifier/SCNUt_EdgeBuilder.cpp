//## begin module%3C3082720118.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C3082720118.cm

//## begin module%3C3082720118.cp preserve=no
//## end module%3C3082720118.cp

//## Module: SCNUt_EdgeBuilder%3C3082720118; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_EdgeBuilder.cpp

//## begin module%3C3082720118.additionalIncludes preserve=no
//## end module%3C3082720118.additionalIncludes

//## begin module%3C3082720118.includes preserve=yes
#include <string.h>
#include "Memory/GammaE_mem.h"
//## end module%3C3082720118.includes

// SCNUt_EdgeBuilder
#include "Scene\SceneUtils\ScnStripifier\SCNUt_EdgeBuilder.h"
//## begin module%3C3082720118.additionalDeclarations preserve=yes
//## end module%3C3082720118.additionalDeclarations


// Class SCNUt_EdgeBuilder 

SCNUt_EdgeBuilder::SCNUt_EdgeBuilder()
  //## begin SCNUt_EdgeBuilder::SCNUt_EdgeBuilder%.hasinit preserve=no
  //## end SCNUt_EdgeBuilder::SCNUt_EdgeBuilder%.hasinit
  //## begin SCNUt_EdgeBuilder::SCNUt_EdgeBuilder%.initialization preserve=yes
  //## end SCNUt_EdgeBuilder::SCNUt_EdgeBuilder%.initialization
{
  //## begin SCNUt_EdgeBuilder::SCNUt_EdgeBuilder%.body preserve=yes
  //## end SCNUt_EdgeBuilder::SCNUt_EdgeBuilder%.body
}


SCNUt_EdgeBuilder::~SCNUt_EdgeBuilder()
{
  //## begin SCNUt_EdgeBuilder::~SCNUt_EdgeBuilder%.body preserve=yes
  //## end SCNUt_EdgeBuilder::~SCNUt_EdgeBuilder%.body
}



//## Other Operations (implementation)
SCNUt_EdgeList* SCNUt_EdgeBuilder::poBuild (CMesh* _poMesh, CMesh *&_rpoOutMesh)
{
  //## begin SCNUt_EdgeBuilder::poBuild%1009811893.body preserve=yes
	if (! _poMesh) return(NULL);
	
	SCNUt_TriScene		*poTS;
	SCNUt_Mesh2TriScene	oM2TS;
	SCNUt_MeshCompacter	oMComp;
	SCNUt_EdgeList		*poEdgeList;

	// Generate a raw triangle scene
	poTS = oM2TS.Generate(*_poMesh,0);

	// Generate a compact mesh
	_rpoOutMesh = oMComp.CompactMesh(*poTS);
	
	// Build the edge adjacency list
	poEdgeList = poBuild_FromIndexedTriMesh (_rpoOutMesh);

	// Delete triangle scene & compact mesh
	mDel poTS;

	return (poEdgeList);
  //## end SCNUt_EdgeBuilder::poBuild%1009811893.body
}

SCNUt_EdgeList* SCNUt_EdgeBuilder::poBuild_FromIndexedTriMesh (CMesh* _poMesh)
{
  //## begin SCNUt_EdgeBuilder::poBuild_FromIndexedTriMesh%1009811896.body preserve=yes
  	SCNUt_EdgeList *poEdgeList;
	int				iTri;
	SCNUt_Edge		oEdge;

	poEdgeList = mNew SCNUt_EdgeList;
	
	for (iTri=0;iTri<_poMesh->usNumPrims;iTri++)
	{
		// Vertex 0
		oEdge.A = _poMesh->Idxs[iTri*3+0];
		oEdge.B = _poMesh->Idxs[iTri*3+1];

		poEdgeList->iAdd(oEdge);
		
		// Vertex 1
		oEdge.A = _poMesh->Idxs[iTri*3+1];
		oEdge.B = _poMesh->Idxs[iTri*3+2];

		poEdgeList->iAdd(oEdge);

		// Vertex 2
		oEdge.A = _poMesh->Idxs[iTri*3+2];
		oEdge.B = _poMesh->Idxs[iTri*3+0];

		poEdgeList->iAdd(oEdge);
	}

	return(poEdgeList);
  //## end SCNUt_EdgeBuilder::poBuild_FromIndexedTriMesh%1009811896.body
}

// Additional Declarations
  //## begin SCNUt_EdgeBuilder%3C3082720118.declarations preserve=yes
  //## end SCNUt_EdgeBuilder%3C3082720118.declarations

//## begin module%3C3082720118.epilog preserve=yes
//## end module%3C3082720118.epilog
