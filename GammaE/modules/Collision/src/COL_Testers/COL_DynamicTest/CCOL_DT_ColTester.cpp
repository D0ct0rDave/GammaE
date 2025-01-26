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

// CCOL_DT_ColTester
#include "COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
#include <string.h>

float CCOL_DT_ColTester::fTestCollision (CGGraphBV* SrcObj, CGGraphBV* DstObj)
{
    const CGBVSphere* SS,* DS;
    const CGBVAABB* SB,* DB;
    const CGBVPoint* SP,* DP;
    int iFlags;

    float fRes;

    // Initialize flags
    iFlags = 0;

    // --------------------------------------------------------------------------
    // Assume Bounding Volumes are in world space coordinate system
    // --------------------------------------------------------------------------

    // Get source Bounding Volume
    switch ( SrcObj->eGetTypeID() )
    {
        case EGBoundingVolumeType::BVT_SPHERE:
            SS = &((CGGraphBVSphere*)SrcObj)->oGetSphere();
            iFlags += 0;
        break;

        case EGBoundingVolumeType::BVT_AABB:
            SB = &((CGGraphBVAABB*)SrcObj)->oGetBox();
            iFlags += 1;
        break;

        case EGBoundingVolumeType::BVT_POINT:
            SP = &((CGGraphBVPoint*)SrcObj)->oGetPoint();
            iFlags += 2;
        break;
    }

    // Get destination Bounding Volume
    switch ( DstObj->eGetTypeID() )
    {
        case EGBoundingVolumeType::BVT_SPHERE:
            DS = &((CGGraphBVSphere*)DstObj )->oGetSphere();
            iFlags += 3 * 0;
        break;

        case EGBoundingVolumeType::BVT_AABB:
            DB = &((CGGraphBVAABB*)DstObj )->oGetBox();
            iFlags += 3 * 1;
        break;

        case EGBoundingVolumeType::BVT_POINT:
            DP = &((CGGraphBVPoint*)DstObj )->oGetPoint();
            iFlags += 3 * 2;
        break;
    }

    // Perform intersection test
    switch ( iFlags )
    {
        case 0:  // Sphere-Sphere test
        fRes = CCOL_DT_Sphere::fTestSphere( SS->oGetCenter(), SS->fGetRadius(),
                                            DS->oGetCenter(), DS->fGetRadius());
        break;

        case 1:  // Box-Sphere test
        fRes = CCOL_DT_Box::fTestSphere(SB->oGetMax(), SB->oGetMin(), DS->oGetCenter(), DS->fGetRadius());
        break;

        case 2:  // Point-Sphere test
        fRes = CCOL_DT_Point::fTestSphere(SP->oGetCenter(), DS->oGetCenter(), DS->fGetRadius());
        break;

        case 3:  // Sphere-Box test
        fRes = CCOL_DT_Sphere::fTestBox(SS->oGetCenter(), SS->fGetRadius(), DB->oGetMax(), DB->oGetMin());
        break;

        case 4:  // Box-Box test
        fRes = CCOL_DT_Box::fTestBox(SB->oGetMax(),SB->oGetMin(),DB->oGetMax(),DB->oGetMin());
        break;

        case 5:  // Point-Box test
        fRes = CCOL_DT_Point::fTestBox(SS->oGetCenter(),DB->oGetMax(),DB->oGetMin());
        break;

        case 6:  // Sphere-Point
        fRes = CCOL_DT_Sphere::fTestPoint(SS->oGetCenter(),SS->fGetRadius(), DP->oGetCenter());
        break;

        case 7:  // Box-Point
        fRes = CCOL_DT_Box::fTestPoint(SB->oGetMax(),SB->oGetMin(), DP->oGetCenter());
        break;

        case 8:  // Point-Point
        break;
    }

    if ( (fRes < CCOL_ColState::fMinColTime) && (fRes >= 0.0f) )
        CCOL_ColState::fMinColTime = fRes;

    return (fRes);
}

float CCOL_DT_ColTester::fTestPlane (CGGraphBV* _SrcObj, const CGPlane& Plane)
{
    return(-1.0f);
}

float CCOL_DT_ColTester::fTestTriangle (CGGraphBV* _SrcObj, const CGTriangle& _Tri)
{
    float fRes;

    // --------------------------------------------------------------------------
    // Assume Triangles and Bounding Volumes are in world space coordinate system
    // --------------------------------------------------------------------------

    switch ( _SrcObj->eGetTypeID() )
    {
        case EGBoundingVolumeType::BVT_SPHERE:
        {
            fRes = CCOL_DT_Tri::fTestSphere( (CGGraphBVSphere &)*_SrcObj,_Tri );
        }
        break;

        case EGBoundingVolumeType::BVT_AABB:
        {
            fRes = CCOL_DT_Tri::fTestBox( (CGGraphBVAABB &) * _SrcObj,_Tri );
        }
        break;

        case EGBoundingVolumeType::BVT_POINT:
        {
            fRes = CCOL_DT_Tri::fTestPoint(_SrcObj->oGetCenter(),_Tri);
        }
        break;
    }

    // Control result
    if ( (fRes < CCOL_ColState::fMinColTime) && (fRes >= 0.0f) )
        CCOL_ColState::fMinColTime = fRes;

    return(fRes);
}

// Additional Declarations
