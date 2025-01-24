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

// CCOL_CollisionSystem
#include "CollisionSystem\CCOL_CollisionSystem.h"
// CCOL_ST_Tris
#include "COL_Testers\COL_StaticTest\CCOL_ST_Tris.h"
// CCOL_Scn_ColTester
#include "COL_Testers\COL_SceneTest\CCOL_Scn_ColTester.h"

// Class CCOL_CollisionSystem

CCOL_CollisionSystem::CCOL_CollisionSystem()
    : iMaxColliders(0), iNumColliders(0), poColliders(NULL)
{
}

CCOL_CollisionSystem::~CCOL_CollisionSystem()
{
    if ( poColliders )
        mDel [] poColliders;
}

void CCOL_CollisionSystem::Init (int _iMaxColliders)
{
    iMaxColliders = _iMaxColliders;
    iNumColliders = 0;

    // Create colliders
    poColliders = mNew CCOL_Collider *[iMaxColliders];
    assert (poColliders && "Unable to create collider array");
}

void CCOL_CollisionSystem::Reset ()
{
    iNumColliders = 0;
}

int CCOL_CollisionSystem::iAddObject (CCOL_Collider* _poColObj)
{
    assert ( (iNumColliders < iMaxColliders) && "No more colliders allowed" );

    // Not allowed
    if ( _poColObj->eGetColType() == COL_CT_None ) return(-1);

    // Collision object identifier
    _poColObj->ColID = iNumColliders;

    poColliders[iNumColliders++] = _poColObj;

    return (_poColObj->ColID);
}

void CCOL_CollisionSystem::CheckCollisions (float _fDelta)
{
    if ( !_fDelta ) return;  // There has been no movement in the current frame

    // Check for collisions	in all the system
    for ( int iObj = 0; iObj < iNumColliders; iObj++ )
        bCheckCollision(*poColliders[iObj],_fDelta);
}

bool CCOL_CollisionSystem::bCheckCollision (CCOL_Collider& _Src, float _fDelta)
{
    int iDst;
    CCOL_Collider* poDst;
    bool bCollided = false;
    bool bHasCollided = false;

    // Reset previous frame collisions
    _Src.Reset();

    // Perform the testing

    // Check collisions against all other static and non-static objects
    for ( iDst = 0; iDst < iNumColliders; iDst++ )
    {
        poDst = poColliders[iDst];

        // Check that the source and the destination are not the same object
        if ( _Src.ColID != poDst->ColID )
        {
            // If we could store a possible collision
            // if ( _Src.ColStack.GetNumCollisions() < iColStackSize)
            {
                // ------------------------------------------------------
                // BEGIN: CD Broad approach
                // ------------------------------------------------------
                CCOL_ColState::SrcIPos.Assign(_Src.OldPos);
                CCOL_ColState::SrcFPos.Assign(_Src.Pos);
                CCOL_ColState::SrcSp.Assign  (_Src.Speed);

                CCOL_ColState::DstIPos.Assign(poDst->OldPos);
                CCOL_ColState::DstFPos.Assign(poDst->Pos);
                CCOL_ColState::DstSp.Assign  (poDst->Speed);

                CCOL_ColState::DSSp.Assign   (CCOL_ColState::DstSp);
                CCOL_ColState::DSSp.Sub      (CCOL_ColState::SrcSp);
                CCOL_ColState::fDeltaT = _fDelta;
                CCOL_ColState::fMinColTime = 1e6;

                bHasCollided = bTestBroadCD(_Src,*poDst);
                // ------------------------------------------------------
                // END: CD Broad approach
                // ------------------------------------------------------

                // ------------------------------------------------------
                // BEGIN: CD Narrow approach
                // ------------------------------------------------------
                if ( bHasCollided )
                {
                    if (
                        ( (poDst->eGetColType() == COL_CT_Static) && (_Src.eGetStTest() == COL_TT_Tris) )
                        /*
                        ||
                           ((poDst->eGetColType() == COL_CT_Dynamic) && (_Src.GetDynTest() == COL_TT_Tris))
                        */
                        )
                    {
                        if ( bTestNarrowCD (_Src,*poDst) )
                            bCollided = true;
                    }
                    else
                    {
                        // This path is only valid for non static or no BV-Triangle
                        // collision test objects
                        _Src.poGetColStack()->AddCollision(poDst,CCOL_ColState::fMinColTime);
                        bCollided = true;
                    }
                }
                // ------------------------------------------------------
                // END: CD Narrow approach
                // ------------------------------------------------------

                // Setup both objects as tested
                /*
                   Colliders[_Src.ColID ].Tested(pDst->ColID);
                   Colliders[pDst->ColID].Tested(_Src.ColID );
                 */
            }
        }
    }

    // Recompute the minimum time and position a collision occurred
    return(bCollided);
}

bool CCOL_CollisionSystem::bTestBroadCD (CCOL_Collider& _Src, CCOL_Collider& _Dst)
{
    bool bCollided;

    CCOL_Scn_ColTester::SGrObj = _Src.GrObj;
    CCOL_Scn_ColTester::DGrObj = _Dst.GrObj;

    // Test if there is a collision
    bCollided = CCOL_Scn_ColTester::iTestObjects();

    return(bCollided);
}

bool CCOL_CollisionSystem::bTestNarrowCD (CCOL_Collider& _Src, CCOL_Collider& _Dst)
{
    if ( !_Dst.GetMeshTester() )
        return(false);

    int iNumTris;
    int iMesh;

    // Initialize minimum collision time so here we perform a finer test
    CCOL_ColState::fMinColTime = 1e6;

    // Compute collided triangles (if any)
    iNumTris = 0;
    for ( iMesh = 0; iMesh < CCOL_Scn_ColTester::iNumColMeshes; iMesh++ )
    {
        iNumTris += _Dst.GetMeshTester()->iTestCollision( CCOL_Scn_ColTester::ColMeshes[iMesh].poMesh,
                                                         CCOL_Scn_ColTester::ColMeshes[iMesh].iMat,
                                                         _Src.GrObj->poGetBV(),
                                                         _Src.GetTriList() );
    }

    return(iNumTris > 0);
}

// Additional Declarations
