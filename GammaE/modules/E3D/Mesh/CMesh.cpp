//## begin module%3A9EC352005A.cm preserve=no
//## end module%3A9EC352005A.cm

//## begin module%3A9EC352005A.cp preserve=no
//## end module%3A9EC352005A.cp

//## Module: CMesh%3A9EC352005A; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Mesh\CMesh.cpp

//## begin module%3A9EC352005A.additionalIncludes preserve=no
//## end module%3A9EC352005A.additionalIncludes

//## begin module%3A9EC352005A.includes preserve=yes
#include "Memory/GammaE_Mem.h"
//## end module%3A9EC352005A.includes

// CMesh
#include "E3D\Mesh\CMesh.h"
//## begin module%3A9EC352005A.additionalDeclarations preserve=yes
//## end module%3A9EC352005A.additionalDeclarations


// Class CMesh 













CMesh::CMesh()
  //## begin CMesh::CMesh%.hasinit preserve=no
      : VXs(NULL), UVs(NULL), VNs(NULL), VCs(NULL), TNs(NULL), UVs2(NULL), Idxs(NULL), usNumVerts(0), usNumIdxs(0), usNumPrims(0), eMeshType(E3D_MESH_NONE)
  //## end CMesh::CMesh%.hasinit
  //## begin CMesh::CMesh%.initialization preserve=yes
  //## end CMesh::CMesh%.initialization
{
  //## begin CMesh::CMesh%.body preserve=yes
  //## end CMesh::CMesh%.body
}


CMesh::~CMesh()
{
  //## begin CMesh::~CMesh%.body preserve=yes
	if (VXs)   mDel[]VXs;
	if (UVs)   mDel[]UVs;
    if (VNs)   mDel[]VNs;
	if (VCs)   mDel[]VCs;
	if (TNs)   mDel[]TNs;	
    if (UVs2)  mDel[]UVs2;

	if (Idxs)  mDel[]Idxs;
  //## end CMesh::~CMesh%.body
}



//## Other Operations (implementation)
void CMesh::Init (int NumVerts, int NumPrims, EMeshType MeshType, unsigned int uiFieldCreationMask)
{
  //## begin CMesh::Init%995837635.body preserve=yes
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
	if (uiFieldCreationMask & MESH_FIELD_COLORS  )	VCs    = mNew CVect4[usNumVerts];
	if (uiFieldCreationMask & MESH_FIELD_INDEXES )	Idxs   = mNew unsigned short[usNumIdxs];
	if (uiFieldCreationMask & MESH_FIELD_TNORMALS)	TNs    = mNew CVect3[usNumPrims];
	if (uiFieldCreationMask & MESH_FIELD_UVCOORD2)	UVs2   = mNew CVect2[usNumVerts];
	
	BVol = CGraphBV_Manager::poCreate();
  //## end CMesh::Init%995837635.body
}

void CMesh::ComputeBoundVol ()
{
  //## begin CMesh::ComputeBoundVol%995837631.body preserve=yes
	BVol->Compute(VXs,usNumVerts);
  //## end CMesh::ComputeBoundVol%995837631.body
}

CGraphBV * CMesh::GetBoundVol ()
{
  //## begin CMesh::GetBoundVol%995837632.body preserve=yes
	return ( BVol);
  //## end CMesh::GetBoundVol%995837632.body
}

CVect3 CMesh::CenterMesh ()
{
  //## begin CMesh::CenterMesh%995837633.body preserve=yes
	unsigned short cV;
    CVect3 Center = GetCenter();
   
 	for (cV=0;cV<usNumVerts;cV++) VXs[cV].Sub(Center);

    return(Center);
  //## end CMesh::CenterMesh%995837633.body
}

CVect3 CMesh::GetCenter ()
{
  //## begin CMesh::GetCenter%995837634.body preserve=yes
	return ( BVol->GetCenter() ) ;
  //## end CMesh::GetCenter%995837634.body
}

EMeshType CMesh::GetMeshType ()
{
  //## begin CMesh::GetMeshType%995837636.body preserve=yes
	return( eMeshType );
  //## end CMesh::GetMeshType%995837636.body
}

// Additional Declarations
  //## begin CMesh%3A9EC352005A.declarations preserve=yes
  //## end CMesh%3A9EC352005A.declarations

//## begin module%3A9EC352005A.epilog preserve=yes
//## end module%3A9EC352005A.epilog
