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

#ifndef SCNUt_BSPBuilder_h
#define SCNUt_BSPBuilder_h 1

// CGSceneNode
#include "GammaE_Scene.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_MaterialTable
#include "SCNUt_MaterialTable.h"
// SCNUt_MeshCompacter
#include "ScnMeshGen\SCNUt_MeshCompacter.h"
// SCNUt_TriSceneClassifier
#include "SplitTriScene\SCNUt_TriSceneClassifier.h"
// SCNUt_TriSceneSplitter
#include "SplitTriScene\SCNUt_TriSceneSplitter.h"
// SCNUt_TriSceneSeparator
#include "SeparateTriScene\SCNUt_TriSceneSeparator.h"

class SCNUt_BSPBuilder
{
    public:
        SCNUt_BSPBuilder();

        ~SCNUt_BSPBuilder();

        CGSceneNode* poBuildBSP(SCNUt_TriScene& _oScene, SCNUt_MaterialTable& _oMatTable);

        // Data Members for Class Attributes

        int iMaxSubdivisions;

        int iMinTrisPerNode;

        // Additional Public Declarations

    protected:

        CGPlane GetPartitionPlane(SCNUt_TriScene& _oScene);

        int SelectPlaneCandidates(SCNUt_TriScene& _oScene, int* _piTriIdxs, int _iNumTris);

        int iGetNumSplits(SCNUt_TriScene& _oScene, CGPlane& _oPlane, int &_iBackTris, int& _iFrontTris);

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_BSPBuilder

#endif
