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

#ifndef CCOL_Scn_ColTester_h
#define CCOL_Scn_ColTester_h 1

#include "GammaE_Scene.h"

// CBoundingSphere
#include "GammaE_E3D.h"
// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"
// CCOL_ST_ColTester
#include "COL_Testers\COL_StaticTest\CCOL_ST_ColTester.h"
// CCOL_DT_ColTester
#include "COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_Mesh
#include "COL_Testers\COL_SceneTest\CCOL_Mesh.h"

class CCOL_Scn_ColTester
{
    public:
        ~CCOL_Scn_ColTester();

        static int iTestObjects();

        static int iTest3DObj_Rec(CGSceneNode* _poObj);

        static int iTest3DObj(CGSceneNode* _poObj);

        static int iTest3DObj_Node(CGSceneGroup* _poObj);

        static int iTest3DObj_Transf(CGSceneTransf* _poObj);

        static int iTest3DObj_Leaf(CGSceneLeaf* _poObj);

        static int iTest3DObj_BSPNode(CGSceneBSPNode* _poObj);

        // Data Members for Class Attributes

        static CGSceneNode* SGrObj;

        static CGSceneNode* DGrObj;

        static int iNumColMeshes;

        // Data Members for Associations

        static CCOL_Mesh ColMeshes[64];

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_Scn_ColTester

#endif
