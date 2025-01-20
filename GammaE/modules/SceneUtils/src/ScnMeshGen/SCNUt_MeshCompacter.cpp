// ----------------------------------------------------------------------------
// SCNUt_MeshCompacter
#include "ScnMeshGen\SCNUt_MeshCompacter.h"
#include <stdlib.h>
#include <string.h>
// ----------------------------------------------------------------------------
// Class SCNUt_MeshCompacter 
SCNUt_MeshCompacter::SCNUt_MeshCompacter()
{
}
// ----------------------------------------------------------------------------
SCNUt_MeshCompacter::~SCNUt_MeshCompacter()
{
}
// ----------------------------------------------------------------------------
CMesh* SCNUt_MeshCompacter::poCompactMesh(const SCNUt_TriScene& _oScene)
{
	CCompactMeshData oCompactData;
	CompactMesh(_oScene,&oCompactData);
	
	oCompactData.m_oInvTable.Clear();	
	return ( oCompactData.m_poMesh );
}
// ----------------------------------------------------------------------------
void SCNUt_MeshCompacter::CompactMesh(const SCNUt_TriScene& _oScene,CCompactMeshData* _poData)
{
  	CMesh *Mesh;
	CMesh *AuxMesh;

	int cIdx,cTri,cVert;
	int iOldNumVertexs;
	
	//----------------------------------
	// Create an auxiliary mesh
	//----------------------------------
	AuxMesh = mNew CMesh();
	AuxMesh->Init(_oScene.NumTris*3,_oScene.NumTris,E3D_MESH_TRIS,MESH_FIELD_ALL);

	//----------------------------------
	// Generate the new compact mesh
	//----------------------------------
	unsigned short usOldNumVertexs	= AuxMesh->usNumVerts;
	AuxMesh->usNumVerts				= 0;

	unsigned short* usIdx	 = AuxMesh->Idxs;
	unsigned short  usCurIdx = 0;

	for (cTri=0;cTri<_oScene.NumTris;cTri++)
	{
		for (cVert = 0;cVert<3;cVert++)
		{
		    uint uiOldNumVertexs = AuxMesh->usNumVerts;

			*usIdx = uiInsertVertex(AuxMesh,
									_oScene.Tris[cTri].VXs[cVert],
			                 		_oScene.Tris[cTri].UVs[cVert],
									_oScene.Tris[cTri].VCs[cVert],
									_oScene.Tris[cTri].VNs[cVert]);

			// In case a new vertex has been inserted, add the original index to the inverse table
			if (uiOldNumVertexs != AuxMesh->usNumVerts)
			{
			    TVertexRef oVR;
			    oVR.m_uiTri = cTri;
			    oVR.m_uiVX  = cVert;

				_poData->m_oInvTable.uiAdd(oVR);
            }

			usIdx++;
			usCurIdx++;
		}
	}
	//----------------------------------
	// Create and Setup the reduced mesh
	//----------------------------------
	Mesh = mNew CMesh();
	Mesh->Init(AuxMesh->usNumVerts,_oScene.NumTris,E3D_MESH_TRIS,MESH_FIELD_ALL);

	// Copy data
	memcpy(Mesh->VXs ,AuxMesh->VXs  ,AuxMesh->usNumVerts*sizeof(CVect3));
	memcpy(Mesh->UVs ,AuxMesh->UVs  ,AuxMesh->usNumVerts*sizeof(CVect2));
	memcpy(Mesh->VCs ,AuxMesh->VCs  ,AuxMesh->usNumVerts*sizeof(CVect4));
	memcpy(Mesh->VNs ,AuxMesh->VNs  ,AuxMesh->usNumVerts*sizeof(CVect3));
	memcpy(Mesh->Idxs,AuxMesh->Idxs	,AuxMesh->usNumIdxs *sizeof(unsigned short));

	AuxMesh->usNumVerts = usOldNumVertexs;
	mDel AuxMesh;

	//----------------------------------
	_poData->m_poMesh = Mesh;
}
// ----------------------------------------------------------------------------
uint SCNUt_MeshCompacter::uiInsertVertex(CMesh *Mesh, CVect3 &VX, CVect2& UV, CVect4 &VC, CVect3 &VN)
{
	// Search for the specified vertex tuplet <VX,VU>
	for (uint i=0;i<Mesh->usNumVerts;i++)
	{
		if (Mesh->VXs[i].bEqual(VX) && Mesh->UVs[i].bEqual(UV))
			return(i);
	}

	Mesh->VXs[Mesh->usNumVerts] = VX;
	Mesh->UVs[Mesh->usNumVerts] = UV;
	Mesh->VCs[Mesh->usNumVerts] = (CGColor&)VC;
	Mesh->VNs[Mesh->usNumVerts] = VN;
	Mesh->usNumVerts++;

	return(Mesh->usNumVerts - 1);
}
// ----------------------------------------------------------------------------