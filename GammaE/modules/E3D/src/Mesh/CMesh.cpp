



#include "GammaE_Mem.h"

// CMesh
#include "Mesh\CMesh.h"


// Class CMesh 













CMesh::CMesh()
        : VXs(NULL), UVs(NULL), VNs(NULL), VCs(NULL), TNs(NULL), UVs2(NULL), Idxs(NULL), usNumVerts(0), usNumIdxs(0), usNumPrims(0), eMeshType(E3D_MESH_NONE)
      {
}


CMesh::~CMesh()
{
  	if (VXs)   mDel[]VXs;
	if (UVs)   mDel[]UVs;
    if (VNs)   mDel[]VNs;
	if (VCs)   mDel[]VCs;
	if (TNs)   mDel[]TNs;	
    if (UVs2)  mDel[]UVs2;

	if (Idxs)  mDel[]Idxs;
	if (BVol)  mDel BVol;
}



void CMesh::Init (int NumVerts, int NumPrims, EMeshType MeshType, unsigned int uiFieldCreationMask)
{
  	usNumVerts = NumVerts;
	usNumPrims = NumPrims;
	eMeshType  = MeshType;
		
	switch (eMeshType)
	{
		case E3D_MESH_NONE:		  usNumIdxs = 0;			 break;
		case E3D_MESH_TRIS:		  usNumIdxs = usNumPrims*3;	 break;
		case E3D_MESH_QUADS:	  usNumIdxs = usNumPrims*4;	 break;
		case E3D_MESH_TRIFANS:	  usNumIdxs = usNumPrims + 2;break;
		case E3D_MESH_TRISTRIPS:  usNumIdxs = usNumPrims + 2;break;
		case E3D_MESH_QUADSTRIPS: usNumIdxs = usNumPrims + 3;break;

		case E3D_MESH_NITRIS:	  usNumIdxs = 0;			 break;
		case E3D_MESH_NIQUADS:	  usNumIdxs = 0;			 break;
		case E3D_MESH_NITRISTRIP: usNumIdxs = 0;			 break;
	}

	if (uiFieldCreationMask & MESH_FIELD_VERTEXS )	VXs    = mNew CVect3[usNumVerts];
	if (uiFieldCreationMask & MESH_FIELD_UVCOORDS)	UVs    = mNew CVect2[usNumVerts];
	if (uiFieldCreationMask & MESH_FIELD_VNORMALS)	VNs    = mNew CVect3[usNumVerts];
	if (uiFieldCreationMask & MESH_FIELD_COLORS  )	VCs    = mNew CGColor[usNumVerts];
	if (uiFieldCreationMask & MESH_FIELD_INDEXES )	Idxs   = mNew unsigned short[usNumIdxs];
	if (uiFieldCreationMask & MESH_FIELD_TNORMALS)	TNs    = mNew CVect3[usNumPrims];
	if (uiFieldCreationMask & MESH_FIELD_UVCOORD2)	UVs2   = mNew CVect2[usNumVerts];
	
	BVol = CGraphBV_Manager::poCreate();
}

void CMesh::ComputeBoundVol ()
{
  	BVol->Compute(VXs,usNumVerts);
}

CGraphBV * CMesh::GetBoundVol ()
{
  	return ( BVol);
}

CVect3 CMesh::CenterMesh ()
{
  	unsigned short cV;
    CVect3 Center = GetCenter();
   
 	for (cV=0;cV<usNumVerts;cV++) VXs[cV].Sub(Center);

    return(Center);
}

CVect3 CMesh::GetCenter ()
{
  	return ( BVol->GetCenter() ) ;
}

EMeshType CMesh::GetMeshType ()
{
  	return( eMeshType );
}

// Additional Declarations
    
