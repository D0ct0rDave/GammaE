//## begin module%3AC229230384.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC229230384.cm

//## begin module%3AC229230384.cp preserve=no
//## end module%3AC229230384.cp

//## Module: SCNUt_MeshCompacter%3AC229230384; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnMeshGen\SCNUt_MeshCompacter.cpp

//## begin module%3AC229230384.additionalIncludes preserve=no
//## end module%3AC229230384.additionalIncludes

//## begin module%3AC229230384.includes preserve=yes
//## end module%3AC229230384.includes

// SCNUt_MeshCompacter
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MeshCompacter.h"
//## begin module%3AC229230384.additionalDeclarations preserve=yes
#include <stdlib.h>
#include <string.h>
//## end module%3AC229230384.additionalDeclarations


// Class SCNUt_MeshCompacter 

SCNUt_MeshCompacter::SCNUt_MeshCompacter()
  //## begin SCNUt_MeshCompacter::SCNUt_MeshCompacter%.hasinit preserve=no
  //## end SCNUt_MeshCompacter::SCNUt_MeshCompacter%.hasinit
  //## begin SCNUt_MeshCompacter::SCNUt_MeshCompacter%.initialization preserve=yes
  //## end SCNUt_MeshCompacter::SCNUt_MeshCompacter%.initialization
{
  //## begin SCNUt_MeshCompacter::SCNUt_MeshCompacter%.body preserve=yes
  //## end SCNUt_MeshCompacter::SCNUt_MeshCompacter%.body
}


SCNUt_MeshCompacter::~SCNUt_MeshCompacter()
{
  //## begin SCNUt_MeshCompacter::~SCNUt_MeshCompacter%.body preserve=yes
  //## end SCNUt_MeshCompacter::~SCNUt_MeshCompacter%.body
}



//## Other Operations (implementation)
CMesh * SCNUt_MeshCompacter::CompactMesh (SCNUt_TriScene &Scene)
{
  //## begin SCNUt_MeshCompacter::CompactMesh%985803488.body preserve=yes
	CMesh *Mesh;
	CMesh *AuxMesh;

	int cIdx,cTri,cVert;
	int iOldNumVertexs;
	
	//----------------------------------
	// Create an auxiliary mesh
	//----------------------------------
	AuxMesh = new CMesh();
	AuxMesh->Init(Scene.NumTris*3,Scene.NumTris,E3D_MESH_TRIS,MESH_FIELD_ALL);
	
	//----------------------------------
	// Generate the new compact mesh
	//----------------------------------
	iOldNumVertexs      = AuxMesh->usNumVerts;
	AuxMesh->usNumVerts = 0;

	unsigned short *Idx = AuxMesh->Idxs;
	cIdx = 0;
	for (cTri=0;cTri<Scene.NumTris;cTri++)
	{
		for (cVert = 0;cVert<3;cVert++)
		{
			*Idx = InsertVertex(AuxMesh,
								Scene.Tris[cTri].VXs[cVert],
			                 	Scene.Tris[cTri].UVs[cVert],
								Scene.Tris[cTri].VCs[cVert],
								Scene.Tris[cTri].VNs[cVert]);
			// AuxMesh->Idxs[cIdx] = 
			Idx++;
			cIdx++;
		}
	}
	//----------------------------------
	// Create and Setup the reduced mesh
	//----------------------------------
	Mesh = new CMesh();
	Mesh->Init(AuxMesh->usNumVerts,Scene.NumTris,E3D_MESH_TRIS,MESH_FIELD_ALL);

	// Copy data
	memcpy(Mesh->VXs ,AuxMesh->VXs  ,AuxMesh->usNumVerts*sizeof(CVect3));
	memcpy(Mesh->UVs ,AuxMesh->UVs  ,AuxMesh->usNumVerts*sizeof(CVect2));
	memcpy(Mesh->VCs ,AuxMesh->VCs  ,AuxMesh->usNumVerts*sizeof(CVect4));
	memcpy(Mesh->VNs ,AuxMesh->VNs  ,AuxMesh->usNumVerts*sizeof(CVect3));
	memcpy(Mesh->Idxs,AuxMesh->Idxs	,AuxMesh->usNumIdxs *sizeof(unsigned short));
	
	AuxMesh->usNumVerts = iOldNumVertexs;
	delete AuxMesh;
	//----------------------------------
	return(Mesh);
  //## end SCNUt_MeshCompacter::CompactMesh%985803488.body
}

int SCNUt_MeshCompacter::InsertVertex (CMesh *Mesh, CVect3 &VX, CVect2& UV, CVect4 &VC, CVect3 &VN)
{
  //## begin SCNUt_MeshCompacter::InsertVertex%985803490.body preserve=yes
	int cI;
		
	// Search for the specified vertex tuplet <VX,VU>
	for (cI=0;cI<Mesh->usNumVerts;cI++)
	{
		if (Mesh->VXs[cI].Equal(VX) && Mesh->UVs[cI].Equal(UV))
			return(cI);
	}
	
	Mesh->VXs[Mesh->usNumVerts] = VX;
	Mesh->UVs[Mesh->usNumVerts] = UV;
	Mesh->VCs[Mesh->usNumVerts] = VC;
	Mesh->VNs[Mesh->usNumVerts] = VN;
	Mesh->usNumVerts++;

	return(Mesh->usNumVerts - 1);
  //## end SCNUt_MeshCompacter::InsertVertex%985803490.body
}

// Additional Declarations
  //## begin SCNUt_MeshCompacter%3AC229230384.declarations preserve=yes
  //## end SCNUt_MeshCompacter%3AC229230384.declarations

//## begin module%3AC229230384.epilog preserve=yes
//## end module%3AC229230384.epilog
