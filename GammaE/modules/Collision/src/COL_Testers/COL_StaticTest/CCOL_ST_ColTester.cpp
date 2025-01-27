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
#include "COL_Testers\COL_StaticTest\CCOL_ST_ColTester.h"
// -----------------------------------------------------------------------------
int CCOL_ST_ColTester::iTestCollision (CGGraphBV* _poSrcBV, CGGraphBV* _poDstBV)
{
    const CGBVSphere* SS,*DS;
    const CGBVAABB* SB,*DB;
    const CGBVPoint* SP,*DP;
    int iFlags = 0;

    // Get source Bounding Volume
    switch (_poSrcBV->eGetTypeID() )
    {
        case EGBoundingVolumeType::BVT_SPHERE:
        SS = &((CGGraphBVSphere*)_poSrcBV)->oGetSphere();
        iFlags += 0;
        break;

        case EGBoundingVolumeType::BVT_AABB:
        SB = &((CGGraphBVAABB*)_poSrcBV)->oGetBox();
        iFlags += 1;
        break;
        
        case EGBoundingVolumeType::BVT_POINT:
        SP = &((CGGraphBVPoint*)_poSrcBV)->oGetPoint();
        iFlags += 2;
        break;
    }

    // Get destination Bounding Volume
    switch (_poDstBV->eGetTypeID() )
    {
        case EGBoundingVolumeType::BVT_SPHERE:
        DS = &((CGGraphBVSphere*)_poDstBV)->oGetSphere();
        iFlags += 3 * 0;
        break;

        case EGBoundingVolumeType::BVT_AABB:
        DB = &((CGGraphBVAABB*)_poDstBV)->oGetBox();
        iFlags += 3 * 1;
        break;

        case EGBoundingVolumeType::BVT_POINT:
        DP = &((CGGraphBVPoint*)_poDstBV)->oGetPoint();
        iFlags += 3 * 2;
        break;
    }

    switch ( iFlags )
    {
        case 0:  // Sphere-Sphere test
        return ( CCOL_ST_Sphere::iTestSphere(SS->oGetCenter(), SS->fGetRadius(), DS->oGetCenter(), DS->fGetRadius()));
        break;

        case 1:  // Box-Sphere test
        return ( CCOL_ST_Box::iTestSphere(SB->oGetMax(), SB->oGetMin(), DS->oGetCenter(), DS->fGetRadius()));
        break;

        case 2:  // Point-Sphere test
        return ( CCOL_ST_Point::iTestSphere(SP->oGetCenter(), DS->oGetCenter(), DS->fGetRadius()));
        break;

        case 3:  // Sphere-Box test
        return ( CCOL_ST_Sphere::iTestBox(SS->oGetCenter(), SS->fGetRadius(), DB->oGetMax(), DB->oGetMin()));
        break;

        case 4:  // Box-Box test
        return ( CCOL_ST_Box::iTestBox(SB->oGetMax(),SB->oGetMin(),DB->oGetMax(),DB->oGetMin()) );
        break;

        case 5:  // Point-Box test
        return ( CCOL_ST_Point::iTestBox(SP->oGetCenter(), DB->oGetMax(), DB->oGetMin()));
        break;

        case 6:  // Sphere-Point
        return ( CCOL_ST_Sphere::iTestPoint(SS->oGetCenter(),SS->fGetRadius(),DP->oGetCenter()) );
        break;

        case 7:  // Box-Point
        return ( CCOL_ST_Box::iTestPoint(SB->oGetMax(),SB->oGetMin(),DP->oGetCenter()) );
        break;

        case 8:  // Point-Point
        return ( CCOL_ST_Point::iTestPoint(SP->oGetCenter(), DP->oGetCenter()) );
        break;
    }

    return (0);
}
// -----------------------------------------------------------------------------
int CCOL_ST_ColTester::iTestPlane(CGGraphBV* _poBV, const CGPlane& _oPlane)
{
    switch (_poBV->eGetTypeID() )
    {
        case EGBoundingVolumeType::BVT_SPHERE:
        {
            const CGBVSphere& SS = ((CGGraphBVSphere*)_poBV)->oGetSphere();
            return ( Math::iTestSpherePlane(SS.oGetCenter(), SS.fGetRadius(), _oPlane));
        }
        break;

        case EGBoundingVolumeType::BVT_AABB:
        {
            const CGBVAABB& SB = ((CGGraphBVAABB*)_poBV)->oGetBox();
            return ( Math::iTestBoxPlane(SB.oGetMax(), SB.oGetMin(), _oPlane));
        }
        break;

        case EGBoundingVolumeType::BVT_POINT:
        {
            const CGBVPoint& SP = ((CGGraphBVPoint*)_poBV)->oGetPoint();
            return (Math::iTestPointPlane(SP.oGetCenter(), _oPlane));
        }
        break;
    }

    return (0);
}
// -----------------------------------------------------------------------------