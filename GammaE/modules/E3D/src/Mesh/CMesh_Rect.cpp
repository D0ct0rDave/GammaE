//-----------------------------------------------------------------------------
#include "Mesh\CMesh_Rect.h"
//-----------------------------------------------------------------------------
CMesh_Rect::CMesh_Rect()
{
  	CMesh::Init(4,1,E3D_MESH_NIQUADS,MESH_FIELD_ALL);	

    // Setup vertex data
	VXs[0].V3(-1, 1, 0);
	VXs[1].V3( 1, 1, 0);
	VXs[2].V3( 1,-1, 0);
	VXs[3].V3(-1,-1, 0);

    // Setup Normal data  
    VNs[0].V3(-1,-1, 0);
	VNs[1].V3(-1, 1, 0);
	VNs[2].V3( 1, 1, 0);
	VNs[3].V3( 1,-1, 0);
	for (int cNorm = 0;cNorm < usNumVerts;cNorm++) VNs[cNorm].Normalize();

	// Setup color data
	VCs[0].Set(1,1,1,1);
	VCs[1].Set(1,1,1,1);
	VCs[2].Set(1,1,1,1);
	VCs[3].Set(1,1,1,1);

    // Setup UV data
	UVs[0].V2(0,1);
	UVs[1].V2(1,1);
	UVs[2].V2(1,0);
	UVs[3].V2(0,0);
}
//-----------------------------------------------------------------------------
CMesh_Rect::~CMesh_Rect()
{
}
//-----------------------------------------------------------------------------
