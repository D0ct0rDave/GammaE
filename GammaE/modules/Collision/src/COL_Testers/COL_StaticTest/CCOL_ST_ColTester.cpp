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

// CCOL_ST_ColTester
#include "COL_Testers\COL_StaticTest\CCOL_ST_ColTester.h"

// Class CCOL_ST_ColTester

CCOL_ST_ColTester::CCOL_ST_ColTester()
{
}

CCOL_ST_ColTester::~CCOL_ST_ColTester()
{
}

int CCOL_ST_ColTester::iTestCollision (CGraphBV* SrcObj, CGraphBV* DstObj)
{
    CBoundingSphere* SS,* DS;
    CBoundingBox* SB,* DB;
    CGVect3* SP,* DP;
    int iFlags = 0;

    // Get source Bounding Volume
    switch ( SrcObj->eGetTypeID() )
    {
        case eGraphBV_Sphere:   SS = ( (CGraphBV_Sphere*)SrcObj )->pGetSphere();
        iFlags += 0;
        break;

        case eGraphBV_Box:      SB = ( (CGraphBV_Box*)SrcObj )->pGetBox();
        iFlags += 1;
        break;

        case eGraphBV_Point:    SP = ( (CGraphBV_Point*)SrcObj )->pGetPoint();
        iFlags += 2;
        break;
    }

    // Get destination Bounding Volume
    switch ( DstObj->eGetTypeID() )
    {
        case eGraphBV_Sphere:   DS = ( (CGraphBV_Sphere*)DstObj )->pGetSphere();
        iFlags += 3 * 0;
        break;

        case eGraphBV_Box:      DB = ( (CGraphBV_Box*)DstObj )->pGetBox();
        iFlags += 3 * 1;
        break;

        case eGraphBV_Point:    DP = ( (CGraphBV_Point*)DstObj )->pGetPoint();
        iFlags += 3 * 2;
        break;
    }

    switch ( iFlags )
    {
        case 0:  // Sphere-Sphere test
        return ( CCOL_ST_Sphere::iTestSphere(SS->m_oCenter,SS->m_fRadius,DS->m_oCenter,DS->m_fRadius) );
        break;

        case 1:  // Box-Sphere test
        return ( CCOL_ST_Box::iTestSphere(SB->m_oMaxs,SB->m_oMins,DS->m_oCenter,DS->m_fRadius) );
        break;

        case 2:  // Point-Sphere test
        return ( CCOL_ST_Point::iTestSphere(*SP,DS->m_oCenter,DS->m_fRadius) );
        break;

        case 3:  // Sphere-Box test
        return ( CCOL_ST_Sphere::iTestBox(SS->m_oCenter,SS->m_fRadius,DB->m_oMaxs,DB->m_oMins) );
        break;

        case 4:  // Box-Box test
        return ( CCOL_ST_Box::iTestSphere(SB->m_oMaxs,SB->m_oMins,DS->m_oCenter,DS->m_fRadius) );
        break;

        case 5:  // Point-Box test
        return ( CCOL_ST_Point::iTestBox(*SP,DB->m_oMaxs,DB->m_oMins) );
        break;

        case 6:  // Sphere-Point
        return ( CCOL_ST_Sphere::iTestPoint(SS->m_oCenter,SS->m_fRadius,*DP) );
        break;

        case 7:  // Box-Point
        return ( CCOL_ST_Box::iTestPoint(SB->m_oMaxs,SB->m_oMins,*DP) );
        break;

        case 8:  // Point-Point
        return ( CCOL_ST_Point::iTestPoint(*SP,*DP) );
        break;
    }

    return (0);
}

int CCOL_ST_ColTester::iTestPlane (CGraphBV* _SrcObj, CPlane& Plane)
{
    CBoundingSphere* SS;
    CBoundingBox* SB;
    CGVect3* SP;

    switch ( _SrcObj->eGetTypeID() )
    {
        case eGraphBV_Sphere:   SS = ( (CGraphBV_Sphere*)_SrcObj )->pGetSphere();
        return ( MATH_Utils::iTestSpherePlane(SS->m_oCenter,SS->m_fRadius,Plane) );
        break;

        case eGraphBV_Box:      SB = ( (CGraphBV_Box*)_SrcObj )->pGetBox();
        return ( MATH_Utils::iTestBoxPlane(SB->m_oMaxs,SB->m_oMaxs,Plane) );
        break;

        case eGraphBV_Point:    SP = ( (CGraphBV_Point*)_SrcObj )->pGetPoint();
        return ( MATH_Utils::iTestPointPlane(*SP,Plane) );
        break;
    }

    return (0);
}

// Additional Declarations
