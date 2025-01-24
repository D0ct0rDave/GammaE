// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#include <stdlib.h>

// SCNUt_BSPBuilder
#include "BSPBuilder\SCNUt_BSPBuilder.h"
int iRecursionLevels;

// Class SCNUt_BSPBuilder

SCNUt_BSPBuilder::SCNUt_BSPBuilder()
    : iMaxSubdivisions(0), iMinTrisPerNode(0)
{
    iRecursionLevels = 0;
}

SCNUt_BSPBuilder::~SCNUt_BSPBuilder()
{
}

CGSceneNode* SCNUt_BSPBuilder::poBuildBSP (SCNUt_TriScene& _oScene, SCNUt_MaterialTable& _oMatTable)
{
    if ( iRecursionLevels > 100 )
        iRecursionLevels = iRecursionLevels;
    else
        iRecursionLevels++;

    // Recursion condition
    if ( _oScene.NumTris > iMinTrisPerNode )
    {
        CGPlane Plane;
        SCNUt_TriSceneSplitter oScnSplitter;
        CGSceneBSPNode* poBSPNode;

        // Get the partition plane
        Plane = GetPartitionPlane(_oScene);

        // Split the scene using the selected plane
        oScnSplitter.ClassifyAndSplitScene(_oScene,Plane);

        // Setup BSP node
        poBSPNode = mNew CGSceneBSPNode;
        poBSPNode->Setup(   poBuildBSP(*oScnSplitter.poBackScene,_oMatTable),
                            poBuildBSP(*oScnSplitter.poFrontScene,_oMatTable),
                            Plane);
        // The oScnSplitter nodes will be erased on return from this function

        return(poBSPNode);
    }
    else
    {
        // Create a node to store every one of the meshes
        CGSceneGroup* poMeshes;
        CGSceneLeaf* poLeafMesh;
        CGMesh* poMesh;
        SCNUt_MeshCompacter oScnComp;
        SCNUt_TriSceneSeparator oScnSep;
        int iMesh;

        // Separate the scene meshes by material
        oScnSep.SeparateScene(_oScene);

        // Create a node to store every one of the meshes
        poMeshes = mNew CGSceneGroup;
        poMeshes->Init(oScnSep.NumMeshes);

        // Generate meshes
        for ( iMesh = 0; iMesh < oScnSep.NumMeshes; iMesh++ )
        {
            // Generate a mesh
            poMesh = oScnComp.poCompactMesh( oScnSep.Meshes[iMesh] );

            // Create and setup a leaf node
            poLeafMesh = mNew CGSceneLeaf;
            poLeafMesh->SetMesh(poMesh);
            poLeafMesh->SetShader( _oMatTable.poGet(oScnSep.piMatIdx[iMesh]) );

            // Add the new compacted mesh
            poMeshes->iAddObject(poLeafMesh);
        }

        return (poMeshes);
    }
}

CGPlane SCNUt_BSPBuilder::GetPartitionPlane (SCNUt_TriScene& _oScene)
{
    CGPlane Plane,MinFactorPlane;
    int iTriIdxs[10];
    int iNumSelTris;
    int iSelTri;
    SCNUt_Triangle* pTri;
    int iNumSplits,iMinFactor,iMinFactorIdx;
    int iBackTris,iFrontTris;
    int iFactor;
    // Get the plane candidates
    iNumSelTris = SelectPlaneCandidates(_oScene,iTriIdxs,10);

    // Get the better plane
    iMinFactorIdx = -1;
    iMinFactor = 0x7fffffff;

    for ( iSelTri = 0; iSelTri < iNumSelTris; iSelTri++ )
    {
        pTri = &_oScene.Tris[ iTriIdxs[iSelTri] ];
        Plane.GenerateFromPoints( pTri->VXs[0], pTri->VXs[1], pTri->VXs[2]);

        iNumSplits = iGetNumSplits(_oScene,Plane,iBackTris,iFrontTris);

        // Select the plane that leaves more or less the same amount of triangles
        // at each side, and generates the less splits
        iFactor = abs(iFrontTris - iBackTris) * (iNumSplits + 1);

        if ( (iFactor < iMinFactor) && (iNumSplits > 0) )
        {
            iMinFactor = iFactor;
            MinFactorPlane = Plane;
            iMinFactorIdx = iSelTri;
        }
    }

    return (MinFactorPlane);

    /*

       // It's not possible since, initially min splits has a value greater than
       // the number of possible split triangles

       if (! bComputed)
       {
        pTri = &_oScene.Tris[ iTriIdxs[0] ];
        MinSplitPlane.GenerateFromPoints( pTri->VXs[0], pTri->VXs[1], pTri->VXs[2]);
       }
     */
}

int SCNUt_BSPBuilder::SelectPlaneCandidates (SCNUt_TriScene& _oScene, int* _piTriIdxs, int _iNumTris)
{
    // In case the scene has fewer triangles than the required planes
    if ( _oScene.NumTris <= _iNumTris )
    {
        for ( int i = 0; i < _oScene.NumTris; i++ )
            _piTriIdxs[i] = i;
        return (_oScene.NumTris);
    }
    else
    {
        for ( int i = 0; i < _iNumTris; i++ )
            _piTriIdxs[i] = _oScene.NumTris * ( (float)rand() / (float)RAND_MAX );

        return (_iNumTris);
    }
}

int SCNUt_BSPBuilder::iGetNumSplits (SCNUt_TriScene& _oScene, CGPlane& _oPlane, int &_iBackTris, int& _iFrontTris)
{
    int iTri;
    int iNumSplits;
    SCNUt_TriSceneClassifier oScnClass;

    // First of all classify the scene
    oScnClass.ClassifyScene(_oScene,_oPlane);

    // Count the number of splits
    iNumSplits = 0;
    for ( iTri = 0; iTri < _oScene.NumTris; iTri++ )
    {
        if ( (_oScene.Tris[iTri].Side == POLYSTATE_CROSS1) ||
            (_oScene.Tris[iTri].Side == POLYSTATE_CROSS2) ) iNumSplits++;
    }

    _iBackTris = oScnClass.iBackTris;
    _iFrontTris = oScnClass.iFrontTris;
    return(iNumSplits);
}

// Additional Declarations
