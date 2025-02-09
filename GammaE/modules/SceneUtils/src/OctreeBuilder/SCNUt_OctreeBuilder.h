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
// %X% %Q% %Z% %W%

#ifndef SCNUt_OctreeBuilder_h
#define SCNUt_OctreeBuilder_h 1

// CGSceneNode
#include "GammaE_Scene.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_MaterialTable
#include "SCNUt_MaterialTable.h"
// SCNUt_MeshCompacter
#include "ScnMeshGen\SCNUt_MeshCompacter.h"
// SCNUt_TriSceneSplitter
#include "SplitTriScene\SCNUt_TriSceneSplitter.h"
// SCNUt_TriSceneSeparator
#include "SeparateTriScene\SCNUt_TriSceneSeparator.h"
// SCNUt_SceneBuilder
#include "SceneBuilder\SCNUt_SceneBuilder.h"
// SCNUt_ComputeBoundingBox
#include "ScnBBoxGen\SCNUt_ComputeBoundingBox.h"

class SCNUt_OctreeBuilder
{
    public:
        SCNUt_OctreeBuilder();

        ~SCNUt_OctreeBuilder();

        CGSceneNode* poBuildOctree(SCNUt_TriScene& _oScene, SCNUt_MaterialTable &_oMatTable);

        CGSceneNode* poBuildOctreeRec(SCNUt_TriScene& _oScene, int _iCurrentSubs, SCNUt_MaterialTable &_oMatTable);

        // Data Members for Class Attributes

        int iMaxSubdivisions;

        int iMinTrisPerNode;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_OctreeBuilder

#endif
