//## begin module%3BF19F09020E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BF19F09020E.cm

//## begin module%3BF19F09020E.cp preserve=no
//## end module%3BF19F09020E.cp

//## Module: SCNUt_MeshGenerator%3BF19F09020E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnMeshGen\SCNUt_MeshGenerator.cpp

//## begin module%3BF19F09020E.additionalIncludes preserve=no
//## end module%3BF19F09020E.additionalIncludes

//## begin module%3BF19F09020E.includes preserve=yes
#include "memory/gammae_mem.h"
//## end module%3BF19F09020E.includes

// SCNUt_MeshGenerator
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MeshGenerator.h"
//## begin module%3BF19F09020E.additionalDeclarations preserve=yes
//## end module%3BF19F09020E.additionalDeclarations


// Class SCNUt_MeshGenerator 

SCNUt_MeshGenerator::SCNUt_MeshGenerator()
  //## begin SCNUt_MeshGenerator::SCNUt_MeshGenerator%.hasinit preserve=no
  //## end SCNUt_MeshGenerator::SCNUt_MeshGenerator%.hasinit
  //## begin SCNUt_MeshGenerator::SCNUt_MeshGenerator%.initialization preserve=yes
  //## end SCNUt_MeshGenerator::SCNUt_MeshGenerator%.initialization
{
  //## begin SCNUt_MeshGenerator::SCNUt_MeshGenerator%.body preserve=yes
  //## end SCNUt_MeshGenerator::SCNUt_MeshGenerator%.body
}


SCNUt_MeshGenerator::~SCNUt_MeshGenerator()
{
  //## begin SCNUt_MeshGenerator::~SCNUt_MeshGenerator%.body preserve=yes
  //## end SCNUt_MeshGenerator::~SCNUt_MeshGenerator%.body
}



//## Other Operations (implementation)
CMesh * SCNUt_MeshGenerator::GenerateMesh (SCNUt_TriScene &Scene)
{
  //## begin SCNUt_MeshGenerator::GenerateMesh%1005690702.body preserve=yes
  	CMesh			*Mesh;	
	int				cTri,cVert;	
	unsigned short	usIdx;
	
	//----------------------------------
	// Create a mesh
	//----------------------------------
	Mesh = mNew CMesh();
	Mesh->Init(Scene.NumTris*3,Scene.NumTris,E3D_MESH_NITRIS,MESH_FIELD_ALL);
	
	//----------------------------------
	// Generate the new mesh
	//----------------------------------
	
	usIdx = 0;
	for (cTri=0;cTri<Scene.NumTris;cTri++)
	{
		for (cVert = 0;cVert<3;cVert++)
		{
			Mesh->VXs[usIdx] = Scene.Tris[cTri].VXs[cVert];
			Mesh->UVs[usIdx] = Scene.Tris[cTri].UVs[cVert];
			Mesh->VCs[usIdx] = Scene.Tris[cTri].VCs[cVert];
			Mesh->VNs[usIdx] = Scene.Tris[cTri].VNs[cVert];
			
			usIdx++;
		}
	}

	return(Mesh);
  //## end SCNUt_MeshGenerator::GenerateMesh%1005690702.body
}

// Additional Declarations
  //## begin SCNUt_MeshGenerator%3BF19F09020E.declarations preserve=yes
  //## end SCNUt_MeshGenerator%3BF19F09020E.declarations

//## begin module%3BF19F09020E.epilog preserve=yes
//## end module%3BF19F09020E.epilog
