//## begin module%3BE875B9026B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE875B9026B.cm

//## begin module%3BE875B9026B.cp preserve=no
//## end module%3BE875B9026B.cp

//## Module: SCNUt_BSPBuilder%3BE875B9026B; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\BSPBuilder\SCNUt_BSPBuilder.cpp

//## begin module%3BE875B9026B.additionalIncludes preserve=no
//## end module%3BE875B9026B.additionalIncludes

//## begin module%3BE875B9026B.includes preserve=yes
#include <stdlib.h>
//## end module%3BE875B9026B.includes

// SCNUt_BSPBuilder
#include "Scene\SceneUtils\BSPBuilder\SCNUt_BSPBuilder.h"
//## begin module%3BE875B9026B.additionalDeclarations preserve=yes
int iRecursionLevels;
//## end module%3BE875B9026B.additionalDeclarations


// Class SCNUt_BSPBuilder 



SCNUt_BSPBuilder::SCNUt_BSPBuilder()
  //## begin SCNUt_BSPBuilder::SCNUt_BSPBuilder%.hasinit preserve=no
      : iMaxSubdivisions(0), iMinTrisPerNode(0)
  //## end SCNUt_BSPBuilder::SCNUt_BSPBuilder%.hasinit
  //## begin SCNUt_BSPBuilder::SCNUt_BSPBuilder%.initialization preserve=yes
  //## end SCNUt_BSPBuilder::SCNUt_BSPBuilder%.initialization
{
  //## begin SCNUt_BSPBuilder::SCNUt_BSPBuilder%.body preserve=yes
  iRecursionLevels = 0;
  //## end SCNUt_BSPBuilder::SCNUt_BSPBuilder%.body
}


SCNUt_BSPBuilder::~SCNUt_BSPBuilder()
{
  //## begin SCNUt_BSPBuilder::~SCNUt_BSPBuilder%.body preserve=yes
  //## end SCNUt_BSPBuilder::~SCNUt_BSPBuilder%.body
}



//## Other Operations (implementation)
CObject3D * SCNUt_BSPBuilder::poBuildBSP (SCNUt_TriScene& _roScene, SCNUt_MaterialTable& _roMatTable)
{
  //## begin SCNUt_BSPBuilder::poBuildBSP%1005085995.body preserve=yes
    if (iRecursionLevels > 100)
        iRecursionLevels = iRecursionLevels;
    else
        iRecursionLevels++;

	// Recursion condition
	if (_roScene.NumTris>iMinTrisPerNode)
	{	
		CPlane					Plane;
		SCNUt_TriSceneSplitter	oScnSplitter;
		CObject3D_BSPNode		*poBSPNode;


		// Get the partition plane	
		Plane = GetPartitionPlane(_roScene);

		// Split the scene using the selected plane
		oScnSplitter.ClassifyAndSplitScene(_roScene,Plane);
		
		// Setup BSP node
		poBSPNode = new CObject3D_BSPNode;
		poBSPNode->Setup(	poBuildBSP(*oScnSplitter.poBackScene ,_roMatTable),
							poBuildBSP(*oScnSplitter.poFrontScene,_roMatTable),
							Plane);
		// The oScnSplitter nodes will be erased on return from this function
		
		return( poBSPNode );
	}
	else
	{
		// Create a node to store every one of the meshes
		CObject3D_Node			*poMeshes;
		CObject3D_Leaf			*poLeafMesh;
		CMesh					*poMesh;
		SCNUt_MeshCompacter		oScnComp;
		SCNUt_TriSceneSeparator oScnSep;
		int						iMesh;

		// Separate the scene meshes by material		
		oScnSep.SeparateScene(_roScene);
		
		// Create a node to store every one of the meshes
		poMeshes =  new CObject3D_Node;
        poMeshes->Init(oScnSep.NumMeshes);
		
		// Generate meshes
        for (iMesh=0;iMesh<oScnSep.NumMeshes ;iMesh++)
        {
			// Generate a mesh
			poMesh = oScnComp.CompactMesh( oScnSep.Meshes[iMesh] );
			
			// Create and setup a leaf node
            poLeafMesh = new CObject3D_Leaf;
            poLeafMesh->SetMesh(poMesh);
            poLeafMesh->SetShader( _roMatTable.poGetShader(oScnSep.piMatIdx[iMesh]) );

            // Add the new compacted mesh
            poMeshes->iAddObject(poLeafMesh);
		}

		return (poMeshes);
	}
  //## end SCNUt_BSPBuilder::poBuildBSP%1005085995.body
}

CPlane SCNUt_BSPBuilder::GetPartitionPlane (SCNUt_TriScene& _roScene)
{
  //## begin SCNUt_BSPBuilder::GetPartitionPlane%1006556678.body preserve=yes
	CPlane				Plane,MinFactorPlane;
	int					iTriIdxs[10];
	int					iNumSelTris;
	int					iSelTri;
	SCNUt_Triangle		*pTri;
	int					iNumSplits,iMinFactor,iMinFactorIdx;
	int					iBackTris,iFrontTris;
	int					iFactor;
	// Get the plane candidates
	iNumSelTris = SelectPlaneCandidates(_roScene,iTriIdxs,10);

	// Get the better plane
    iMinFactorIdx = -1;
	iMinFactor    =	0x7fffffff;

	for (iSelTri=0;iSelTri<iNumSelTris;iSelTri++)
	{
		pTri = &_roScene.Tris[ iTriIdxs[iSelTri] ];
		Plane.GenerateFromPoints( pTri->VXs[0], pTri->VXs[1], pTri->VXs[2]);

		iNumSplits = iGetNumSplits(_roScene,Plane,iBackTris,iFrontTris);
		
		// Select the plane that leaves more or less the same amount of triangles
		// at each side, and generates the less splits
		iFactor = abs(iFrontTris-iBackTris)*(iNumSplits+1);

		if ((iFactor < iMinFactor) && (iNumSplits>0))
		{
			iMinFactor     = iFactor;
			MinFactorPlane = Plane;
			iMinFactorIdx  = iSelTri; 
		}
	}

	return (MinFactorPlane);

	/*

	// It's not possible since, initially min splits has a value greater than
	// the number of possible split triangles

	if (! bComputed)
	{
		pTri = &_roScene.Tris[ iTriIdxs[0] ];
		MinSplitPlane.GenerateFromPoints( pTri->VXs[0], pTri->VXs[1], pTri->VXs[2]);
	}
	*/
  //## end SCNUt_BSPBuilder::GetPartitionPlane%1006556678.body
}

int SCNUt_BSPBuilder::SelectPlaneCandidates (SCNUt_TriScene& _roScene, int *_piTriIdxs, int _iNumTris)
{
  //## begin SCNUt_BSPBuilder::SelectPlaneCandidates%1006556679.body preserve=yes
	
	// In case the scene has fewer triangles than the required planes
	if (_roScene.NumTris <= _iNumTris)
	{
		for (int i=0;i<_roScene.NumTris;i++)
			_piTriIdxs[i] = i;
		return (_roScene.NumTris);
	} 
	else
	{		
		for (int i=0;i<_iNumTris;i++)
			_piTriIdxs[i] = _roScene.NumTris*((float)rand()/(float)RAND_MAX);
		
		return (_iNumTris);
	}
  //## end SCNUt_BSPBuilder::SelectPlaneCandidates%1006556679.body
}

int SCNUt_BSPBuilder::iGetNumSplits (SCNUt_TriScene& _roScene, CPlane& _roPlane, int &_iBackTris, int& _iFrontTris)
{
  //## begin SCNUt_BSPBuilder::iGetNumSplits%1006556680.body preserve=yes
	int							iTri;
	int							iNumSplits;
	SCNUt_TriSceneClassifier	oScnClass;	

	// First of all classify the scene
	oScnClass.ClassifyScene(_roScene,_roPlane);

	// Count the number of splits
	iNumSplits = 0;
	for (iTri=0;iTri<_roScene.NumTris;iTri++)
	{
		if ((_roScene.Tris[iTri].Side == POLYSTATE_CROSS1) ||
			(_roScene.Tris[iTri].Side == POLYSTATE_CROSS2))  iNumSplits++;
	}
	
	_iBackTris  = oScnClass.iBackTris;
	_iFrontTris = oScnClass.iFrontTris;
	return(iNumSplits);
  //## end SCNUt_BSPBuilder::iGetNumSplits%1006556680.body
}

// Additional Declarations
  //## begin SCNUt_BSPBuilder%3BE875B9026B.declarations preserve=yes
  //## end SCNUt_BSPBuilder%3BE875B9026B.declarations

//## begin module%3BE875B9026B.epilog preserve=yes
//## end module%3BE875B9026B.epilog
