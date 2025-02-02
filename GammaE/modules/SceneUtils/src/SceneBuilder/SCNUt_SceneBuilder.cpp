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
// -----------------------------------------------------------------------------
#include "GammaE_Mem.h"

// SCNUt_SceneBuilder
#include "SceneBuilder\SCNUt_SceneBuilder.h"

// -----------------------------------------------------------------------------
SCNUt_SceneBuilder::SCNUt_SceneBuilder()
{
}
// -----------------------------------------------------------------------------
SCNUt_SceneBuilder::~SCNUt_SceneBuilder()
{
}
// -----------------------------------------------------------------------------
CGSceneNode* SCNUt_SceneBuilder::poBuildScene (SCNUt_TriScene& _oScene, SCNUt_MaterialTable &_oMatTable)
{
    if ( !_oScene.NumTris ) return(NULL);
    if ( !_oScene.Tris ) return(NULL);

    CGSceneGroup* poNode;
    CGSceneLeaf* poLeaf;
    CGMesh* poMesh;
    int iMesh;

    SCNUt_MeshCompacter oMComp;

    SCNUt_TriSceneSeparator oTSep;
    oTSep.SeparateScene(_oScene);

    // Generate main node
    if ( oTSep.NumMeshes > 1 )
    {
        poNode = mNew CGSceneGroup;
        poNode->Init(oTSep.NumMeshes);

        // Add every subobject
        for ( iMesh = 0; iMesh < oTSep.NumMeshes; iMesh++ )
        {
            poMesh = oMComp.poCompactMesh( oTSep.Meshes[iMesh] );

            poLeaf = mNew CGSceneLeaf;
            poLeaf->SetMesh  (poMesh);
            poLeaf->SetShader( _oMatTable.poGet(oTSep.piMatIdx[iMesh]) );

            // Add the new compacted mesh
            poNode->iAddObject(poLeaf);
        }

        return(poNode);
    }
    else
    {
        poMesh = oMComp.poCompactMesh( oTSep.Meshes[0] );

        poLeaf = mNew CGSceneLeaf;
        poLeaf->SetMesh  (poMesh);

        CGShader* poShader = _oMatTable.poGet(oTSep.piMatIdx[0]);
        poLeaf->SetShader( poShader );

        return(poLeaf);
    }
}
// -----------------------------------------------------------------------------
