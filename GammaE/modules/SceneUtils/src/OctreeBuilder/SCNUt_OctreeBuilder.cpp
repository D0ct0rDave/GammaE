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
#include "GammaE_Mem.h"

// SCNUt_OctreeBuilder
#include "OctreeBuilder\SCNUt_OctreeBuilder.h"

// Class SCNUt_OctreeBuilder

SCNUt_OctreeBuilder::SCNUt_OctreeBuilder()
    : iMaxSubdivisions(0), iMinTrisPerNode(0)
{
}

SCNUt_OctreeBuilder::~SCNUt_OctreeBuilder()
{
}

CGSceneNode* SCNUt_OctreeBuilder::poBuildOctree (SCNUt_TriScene& _oScene, SCNUt_MaterialTable &_oMatTable)
{
    if ( !iMaxSubdivisions )
    {
        SCNUt_SceneBuilder oSBld;
        return( oSBld.poBuildScene(_oScene,_oMatTable) );
    }
    else
        return ( poBuildOctreeRec(_oScene,1,_oMatTable) );
}

CGSceneNode* SCNUt_OctreeBuilder::poBuildOctreeRec (SCNUt_TriScene& _oScene, int _iCurrentSubs, SCNUt_MaterialTable &_oMatTable)
{
    // -----------------------------------------------------------
    // Split the node in height subspaces
    // -----------------------------------------------------------
    CGBVAABB* poBox;
    SCNUt_ComputeBoundingBox oCBBox;
    SCNUt_TriSceneSplitter oTScnSplitter;

    poBox = oCBBox.poComputeBoundingBox(&_oScene);

    CGVect3 oCenter;
    CGVect3 oHMP,oVMP,oDMP;                    // Horizontal middle point, Vertical Middle Point,Depth Middle Point

    // Get the center point of the BBox
    oCenter.Assign(poBox->m_oMaxs);
    oCenter.Add   (poBox->m_oMins);
    oCenter.Scale (0.5f);

    oHMP.Assign(oCenter);
    oHMP.x = poBox->m_oMaxs.x;

    oDMP.Assign(oCenter);
    oDMP.y = poBox->m_oMaxs.y;

    oVMP.Assign(oCenter);
    oVMP.y = poBox->m_oMaxs.z;

    // Compute separating planes
    CGPlane oHPlane,oVPlane,oDPlane;                    // Horizontal,Vertical,Depth plane
    oHPlane.GenerateFromPoints(oCenter,oHMP,oDMP);
    oVPlane.GenerateFromPoints(oCenter,oHMP,oVMP);
    oDPlane.GenerateFromPoints(oCenter,oVMP,oDMP);

    SCNUt_TriScene* poHChild[2];
    SCNUt_TriScene* poVChild[4];
    SCNUt_TriScene* poChildScenes[2 + 4 + 8];

    // Split in horizontal plane
    oTScnSplitter.ClassifyAndSplitScene(_oScene,oHPlane);
    poHChild[0] = oTScnSplitter.poBackScene;
    poHChild[1] = oTScnSplitter.poFrontScene;

    // Split in vertical plane
    oTScnSplitter.ClassifyAndSplitScene(*poHChild[0],oVPlane);
    poVChild[0] = oTScnSplitter.poBackScene;
    poVChild[1] = oTScnSplitter.poFrontScene;

    oTScnSplitter.ClassifyAndSplitScene(*poHChild[1],oVPlane);
    poVChild[2] = oTScnSplitter.poBackScene;
    poVChild[3] = oTScnSplitter.poFrontScene;
    mDel poHChild[0];
    mDel poHChild[1];

    // Split in depth plane
    oTScnSplitter.ClassifyAndSplitScene(*poVChild[0],oDPlane);
    poChildScenes[0] = oTScnSplitter.poBackScene;           // Child 0
    poChildScenes[1] = oTScnSplitter.poFrontScene;          // Child 1

    oTScnSplitter.ClassifyAndSplitScene(*poVChild[1],oDPlane);
    poChildScenes[2] = oTScnSplitter.poBackScene;           // Child 2
    poChildScenes[3] = oTScnSplitter.poFrontScene;          // Child 3

    oTScnSplitter.ClassifyAndSplitScene(*poVChild[2],oDPlane);
    poChildScenes[4] = oTScnSplitter.poBackScene;           // Child 4
    poChildScenes[5] = oTScnSplitter.poFrontScene;          // Child 5

    oTScnSplitter.ClassifyAndSplitScene(*poVChild[3],oDPlane);
    poChildScenes[6] = oTScnSplitter.poBackScene;           // Child 6
    poChildScenes[7] = oTScnSplitter.poFrontScene;          // Child 7
    mDel poVChild[0];
    mDel poVChild[1];
    mDel poVChild[2];
    mDel poVChild[3];

    // -----------------------------------------------------------
    // Generate a separate scene for every new subspace
    // -----------------------------------------------------------
    CGSceneGroup* poObj;
    int iChild;
    SCNUt_SceneBuilder oSBld;

    poObj = mNew CGSceneGroup;
    poObj->Init(8);

    for ( iChild = 0; iChild < 8; iChild++ )
    {
        if ( (poChildScenes[iChild]->NumTris < iMinTrisPerNode) ||
            (_iCurrentSubs == iMaxSubdivisions) )
        {
            /*
               poObj->SetObject(oSBld.poBuildScene(*poChildScenes[iChild],_oMatTable),
                            iChild);
             */
            poObj->iAddObject( oSBld.poBuildScene(*poChildScenes[iChild],_oMatTable) );
        }
        else
        {
            /*
               poObj->SetObject(poBuildOctreeRec(*poChildScenes[iChild],_iCurrentSubs+1,_oMatTable),
                            iChild);
             */
            poObj->iAddObject( oSBld.poBuildScene(*poChildScenes[iChild],_oMatTable) );
        }

        mDel(poChildScenes[iChild]);
    }

    return(poObj);
}

// Additional Declarations
