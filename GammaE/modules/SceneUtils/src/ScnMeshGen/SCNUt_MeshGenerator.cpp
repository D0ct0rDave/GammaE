



#include "GammaE_Mem.h"

// SCNUt_MeshGenerator
#include "ScnMeshGen\SCNUt_MeshGenerator.h"


// Class SCNUt_MeshGenerator 

SCNUt_MeshGenerator::SCNUt_MeshGenerator()
        {
}


SCNUt_MeshGenerator::~SCNUt_MeshGenerator()
{
}



CMesh * SCNUt_MeshGenerator::GenerateMesh (SCNUt_TriScene &Scene)
{
    	CMesh			*Mesh;	
	int				cTri,cVert;	
	unsigned short	usIdx;
	
	//-----------------------------------------------------------------------------
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
			Mesh->VCs[usIdx] = *(CGColor*)&Scene.Tris[cTri].VCs[cVert];
			Mesh->VNs[usIdx] = Scene.Tris[cTri].VNs[cVert];
			
			usIdx++;
		}
	}

	return(Mesh);
}

// Additional Declarations
    
