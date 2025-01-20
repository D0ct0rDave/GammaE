//## begin module%3AAD64EF0190.cm preserve=no
//## end module%3AAD64EF0190.cm

//## begin module%3AAD64EF0190.cp preserve=no
//## end module%3AAD64EF0190.cp

//## Module: CMesh_Rect%3AAD64EF0190; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Mesh\CMesh_Rect.cpp

//## begin module%3AAD64EF0190.additionalIncludes preserve=no
//## end module%3AAD64EF0190.additionalIncludes

//## begin module%3AAD64EF0190.includes preserve=yes
//## end module%3AAD64EF0190.includes

// CMesh_Rect
#include "E3D\Mesh\CMesh_Rect.h"
//## begin module%3AAD64EF0190.additionalDeclarations preserve=yes
//## end module%3AAD64EF0190.additionalDeclarations


// Class CMesh_Rect 

CMesh_Rect::CMesh_Rect()
  //## begin CMesh_Rect::CMesh_Rect%.hasinit preserve=no
  //## end CMesh_Rect::CMesh_Rect%.hasinit
  //## begin CMesh_Rect::CMesh_Rect%.initialization preserve=yes
  //## end CMesh_Rect::CMesh_Rect%.initialization
{
  //## begin CMesh_Rect::CMesh_Rect%.body preserve=yes
	CMesh::Init(4,1,E3D_MESH_NIQUADS,MESH_FIELD_ALL);	

    // Setup vertex data
	VXs[0].V3(-1,-1, 0);
	VXs[1].V3(-1, 1, 0);
	VXs[2].V3( 1, 1, 0);
	VXs[3].V3( 1,-1, 0);

    // Setup Normal data  
    VNs[0].V3(-1,-1, 0);
	VNs[1].V3(-1, 1, 0);
	VNs[2].V3( 1, 1, 0);
	VNs[3].V3( 1,-1, 0);
	
	VCs[0].V4(1,1,1,1);
	VCs[1].V4(1,1,1,1);
	VCs[2].V4(1,1,1,1);
	VCs[3].V4(1,1,1,1);
	
    for (int cNorm = 0;cNorm < usNumVerts;cNorm++) VNs[cNorm].Normalize();

    // Setup UV data	
	UVs[0].V2(0,0);
	UVs[1].V2(0,1);
	UVs[2].V2(1,1);
	UVs[3].V2(1,0);
  //## end CMesh_Rect::CMesh_Rect%.body
}


CMesh_Rect::~CMesh_Rect()
{
  //## begin CMesh_Rect::~CMesh_Rect%.body preserve=yes
  //## end CMesh_Rect::~CMesh_Rect%.body
}


// Additional Declarations
  //## begin CMesh_Rect%3AAD64EF0190.declarations preserve=yes
  //## end CMesh_Rect%3AAD64EF0190.declarations

//## begin module%3AAD64EF0190.epilog preserve=yes
//## end module%3AAD64EF0190.epilog
