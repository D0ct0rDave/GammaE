



#include <assert.h>
#include <string.h>
#include "GammaE_Mem.h"

// SCNUt_TriSceneSeparator
#include "SeparateTriScene\SCNUt_TriSceneSeparator.h"


// Class SCNUt_TriSceneSeparator 






SCNUt_TriSceneSeparator::SCNUt_TriSceneSeparator()
        : NumMeshes(0), Meshes(NULL), piTriMat(NULL), piMatIdx(NULL), iMaxMats(0)
      {
}


SCNUt_TriSceneSeparator::~SCNUt_TriSceneSeparator()
{
  	if (piTriMat) mDel []piTriMat;
	if (piMatIdx) mDel []piMatIdx;
	if (Meshes)   mDel []Meshes;
}



int SCNUt_TriSceneSeparator::SeparateScene (SCNUt_TriScene &Scene)
{
  	int				iMesh;
	int				iTri,iDstTri;
	
	SCNUt_Triangle *pSrcTri;
	SCNUt_Triangle *pDstTri;

	NumMeshes = iProcessTriScene(Scene);
	if (NumMeshes<=0) return(NumMeshes);

	Meshes = mNew SCNUt_TriScene[NumMeshes];
	
	for (iMesh=0;iMesh<NumMeshes;iMesh++)
	{
		iDstTri = 0;
		Meshes[iMesh].Init( piTriMat[iMesh] );
		
		pSrcTri = Scene.Tris;
		pDstTri = Meshes[iMesh].Tris;

		for (iTri=0;iTri<Scene.NumTris;iTri++)		
		{	
			if (pSrcTri->Material == piMatIdx[iMesh])
			{
				// --------------------------
				// Add triangle to this mesh
				// --------------------------
				
				// Material
				pDstTri->Material = pSrcTri->Material;
				
				// Vertexs
				pDstTri->VXs[0]   = pSrcTri->VXs[0];
				pDstTri->VXs[1]   = pSrcTri->VXs[1];
				pDstTri->VXs[2]   = pSrcTri->VXs[2];
				
				// Vertexs colors
				pDstTri->VCs[0]   = pSrcTri->VCs[0];
				pDstTri->VCs[1]   = pSrcTri->VCs[1];
				pDstTri->VCs[2]   = pSrcTri->VCs[2];
				
				// Texture coordinates
				pDstTri->UVs[0]   = pSrcTri->UVs[0];
				pDstTri->UVs[1]   = pSrcTri->UVs[1];
				pDstTri->UVs[2]   = pSrcTri->UVs[2];
				
				// Vertex normals
				pDstTri->VNs[0]   = pSrcTri->VNs[0];
				pDstTri->VNs[1]   = pSrcTri->VNs[1];
				pDstTri->VNs[2]   = pSrcTri->VNs[2];				

				// Next destination triangle
				pDstTri++;
			}
			// Next source triangle to test
			pSrcTri++;
		}
	}
	
	return(NumMeshes);
}

int SCNUt_TriSceneSeparator::iProcessTriScene (SCNUt_TriScene &Scene)
{
  	int iTri;
	int iLastMat;
	int iMat,iNumDiffMats,iCurMat;
	int *piMats;

	// Compute the maximum number of materials
	iLastMat = -1;
	for (iTri=0;iTri<Scene.NumTris;iTri++)
		if (Scene.Tris[iTri].Material > iLastMat) iLastMat = Scene.Tris[iTri].Material;

	if (iLastMat>65535) return (-1);
	piMats = mNew int[iLastMat+1];
	
	memset(piMats,0,(iLastMat+1)*sizeof(int));

	// Count the number of triangles that uses every material
	for (iTri=0;iTri<Scene.NumTris;iTri++)
		piMats[Scene.Tris[iTri].Material]++;	
	
	// Get the correct number of materials, the number of different materials
	iNumDiffMats = 0;
	for (iMat=0;iMat<iLastMat+1;iMat++)
		if (piMats[iMat]) iNumDiffMats++;

	// Setup material list
	piTriMat = mNew int[iNumDiffMats];
	piMatIdx = mNew int[iNumDiffMats];
	iCurMat  = 0;

	for (iMat=0;iMat<iLastMat+1;iMat++)
		if (piMats[iMat])
		{
			piTriMat[iCurMat] = piMats[iMat];	// Num tris per mat \ _ This mesh uses this mat and has this tris
			piMatIdx[iCurMat] = iMat;			// Mat id			/
			iCurMat++;
		}

	return(iNumDiffMats);	
}

int SCNUt_TriSceneSeparator::iGetTrisWithMat (int _iMat)
{
  	assert (piTriMat && "NULL Triangle material list");

	return (piTriMat[_iMat]);
}

// Additional Declarations
    
