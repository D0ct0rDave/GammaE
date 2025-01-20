//## begin module%3AC2295A0226.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC2295A0226.cm

//## begin module%3AC2295A0226.cp preserve=no
//## end module%3AC2295A0226.cp

//## Module: SCNUt_TriSceneSeparator%3AC2295A0226; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SeparateTriScene\SCNUt_TriSceneSeparator.cpp

//## begin module%3AC2295A0226.additionalIncludes preserve=no
//## end module%3AC2295A0226.additionalIncludes

//## begin module%3AC2295A0226.includes preserve=yes
#include <assert.h>
#include <string.h>
#include "memory/gammae_mem.h"
//## end module%3AC2295A0226.includes

// SCNUt_TriSceneSeparator
#include "Scene\SceneUtils\SeparateTriScene\SCNUt_TriSceneSeparator.h"
//## begin module%3AC2295A0226.additionalDeclarations preserve=yes
//## end module%3AC2295A0226.additionalDeclarations


// Class SCNUt_TriSceneSeparator 






SCNUt_TriSceneSeparator::SCNUt_TriSceneSeparator()
  //## begin SCNUt_TriSceneSeparator::SCNUt_TriSceneSeparator%.hasinit preserve=no
      : NumMeshes(0), Meshes(NULL), piTriMat(NULL), piMatIdx(NULL), iMaxMats(0)
  //## end SCNUt_TriSceneSeparator::SCNUt_TriSceneSeparator%.hasinit
  //## begin SCNUt_TriSceneSeparator::SCNUt_TriSceneSeparator%.initialization preserve=yes
  //## end SCNUt_TriSceneSeparator::SCNUt_TriSceneSeparator%.initialization
{
  //## begin SCNUt_TriSceneSeparator::SCNUt_TriSceneSeparator%.body preserve=yes
  //## end SCNUt_TriSceneSeparator::SCNUt_TriSceneSeparator%.body
}


SCNUt_TriSceneSeparator::~SCNUt_TriSceneSeparator()
{
  //## begin SCNUt_TriSceneSeparator::~SCNUt_TriSceneSeparator%.body preserve=yes
	if (piTriMat) mDel []piTriMat;
	if (piMatIdx) mDel []piMatIdx;
	if (Meshes)   mDel []Meshes;
  //## end SCNUt_TriSceneSeparator::~SCNUt_TriSceneSeparator%.body
}



//## Other Operations (implementation)
int SCNUt_TriSceneSeparator::SeparateScene (SCNUt_TriScene &Scene)
{
  //## begin SCNUt_TriSceneSeparator::SeparateScene%985807907.body preserve=yes
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
  //## end SCNUt_TriSceneSeparator::SeparateScene%985807907.body
}

int SCNUt_TriSceneSeparator::iProcessTriScene (SCNUt_TriScene &Scene)
{
  //## begin SCNUt_TriSceneSeparator::iProcessTriScene%1004401294.body preserve=yes
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
  //## end SCNUt_TriSceneSeparator::iProcessTriScene%1004401294.body
}

int SCNUt_TriSceneSeparator::iGetTrisWithMat (int _iMat)
{
  //## begin SCNUt_TriSceneSeparator::iGetTrisWithMat%1004401295.body preserve=yes
	assert (piTriMat && "NULL Triangle material list");

	return (piTriMat[_iMat]);
  //## end SCNUt_TriSceneSeparator::iGetTrisWithMat%1004401295.body
}

// Additional Declarations
  //## begin SCNUt_TriSceneSeparator%3AC2295A0226.declarations preserve=yes
  //## end SCNUt_TriSceneSeparator%3AC2295A0226.declarations

//## begin module%3AC2295A0226.epilog preserve=yes
//## end module%3AC2295A0226.epilog
