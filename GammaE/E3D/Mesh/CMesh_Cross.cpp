//## begin module%3AAD65040302.cm preserve=no
//## end module%3AAD65040302.cm

//## begin module%3AAD65040302.cp preserve=no
//## end module%3AAD65040302.cp

//## Module: CMesh_Cross%3AAD65040302; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Mesh\CMesh_Cross.cpp

//## begin module%3AAD65040302.additionalIncludes preserve=no
//## end module%3AAD65040302.additionalIncludes

//## begin module%3AAD65040302.includes preserve=yes
//## end module%3AAD65040302.includes

// CMesh_Cross
#include "E3D\Mesh\CMesh_Cross.h"
//## begin module%3AAD65040302.additionalDeclarations preserve=yes
//## end module%3AAD65040302.additionalDeclarations


// Class CMesh_Cross 

CMesh_Cross::CMesh_Cross()
  //## begin CMesh_Cross::CMesh_Cross%.hasinit preserve=no
  //## end CMesh_Cross::CMesh_Cross%.hasinit
  //## begin CMesh_Cross::CMesh_Cross%.initialization preserve=yes
  //## end CMesh_Cross::CMesh_Cross%.initialization
{
  //## begin CMesh_Cross::CMesh_Cross%.body preserve=yes
	CMesh::Init(4,1,E3D_MESH_QUADS,MESH_FIELD_ALL);	

    // Setup vertex data
	VXs[0].V3(-1, 1, 0);
	VXs[1].V3( 1, 1, 0);
	VXs[2].V3( 1,-1, 0);
	VXs[3].V3(-1,-1, 0);

    // Setup Normal data  
    VNs[0].V3(-1, 1, 0);
	VNs[1].V3( 1, 1, 0);
	VNs[2].V3( 1,-1, 0);
	VNs[3].V3(-1,-1, 0);

	VCs[0].V4(1,1,1,0);
	VCs[1].V4(1,1,1,0);
	VCs[2].V4(1,1,1,0);
	VCs[3].V4(1,1,1,0);

    for (int cNorm = 0;cNorm < usNumVerts;cNorm++) VNs[cNorm].Normalize();

    // Setup UV data	
	UVs[ 0].V2(0,0);
	UVs[ 1].V2(1,0);
	UVs[ 2].V2(1,1);
	UVs[ 3].V2(0,1);

	// Setup indexes
    Idxs[0] = 0;
	Idxs[1] = 1;
	Idxs[2] = 2;
	Idxs[3] = 3;

  //## end CMesh_Cross::CMesh_Cross%.body
}


CMesh_Cross::~CMesh_Cross()
{
  //## begin CMesh_Cross::~CMesh_Cross%.body preserve=yes
  //## end CMesh_Cross::~CMesh_Cross%.body
}


// Additional Declarations
  //## begin CMesh_Cross%3AAD65040302.declarations preserve=yes
  //## end CMesh_Cross%3AAD65040302.declarations

//## begin module%3AAD65040302.epilog preserve=yes
//## end module%3AAD65040302.epilog
