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

// Class CCOL_DT_ColTester

CCOL_DT_ColTester::CCOL_DT_ColTester()
{
}

CCOL_DT_ColTester::~CCOL_DT_ColTester()
{
}

float CCOL_DT_ColTester::fTestCollision (CGraphBV* SrcObj, CGraphBV* DstObj)
{
    CBoundingSphere* SS,* DS;
    CBoundingBox* SB,* DB;
    CVect3* SP,* DP;
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

    // Perform intersection test
    switch ( iFlags )
    {
        case 0:  // Sphere-Sphere test
        fRes = CCOL_DT_Sphere::fTestSphere( SS->m_oCenter,SS->m_fRadius,
                                            DS->m_oCenter,DS->m_fRadius);
        break;

        case 1:  // Box-Sphere test
        fRes = CCOL_DT_Box::fTestSphere(SB->m_oMaxs,SB->m_oMins,DS->m_oCenter,DS->m_fRadius);
        break;

        case 2:  // Point-Sphere test
        fRes = CCOL_DT_Point::fTestSphere(*SP,DS->m_oCenter,DS->m_fRadius);
        break;

        case 3:  // Sphere-Box test
        fRes = CCOL_DT_Sphere::fTestBox(SS->m_oCenter,SS->m_fRadius,DB->m_oMaxs,DB->m_oMins);
        break;

        case 4:  // Box-Box test
        fRes = CCOL_DT_Box::fTestBox(SB->m_oMaxs,SB->m_oMins,DB->m_oMaxs,DB->m_oMins);
        break;

        case 5:  // Point-Box test
        fRes = CCOL_DT_Point::fTestBox(SS->m_oCenter,DB->m_oMaxs,DB->m_oMins);
        break;

        case 6:  // Sphere-Point
        fRes = CCOL_DT_Sphere::fTestPoint(SS->m_oCenter,SS->m_fRadius,*DP);
        break;

        case 7:  // Box-Point
        fRes = CCOL_DT_Box::fTestPoint(SB->m_oMaxs,SB->m_oMins,*DP);
        break;

        case 8:  // Point-Point
        break;
    }

    if ( (fRes < CCOL_ColState::fMinColTime) && (fRes >= 0.0f) )
        CCOL_ColState::fMinColTime = fRes;

    return (fRes);
}

float CCOL_DT_ColTester::fTestPlane (CGraphBV* _SrcObj, CPlane& Plane)
{
    return(-1.0f);
}

float CCOL_DT_ColTester::fTestTriangle (CGraphBV* _SrcObj, CTriangle& _Tri)
{
    float fRes;

    // --------------------------------------------------------------------------
    // Assume Triangles and Bounding Volumes are in world space coordinate system
    // --------------------------------------------------------------------------

    switch ( _SrcObj->eGetTypeID() )
    {
        case eGraphBV_Sphere:
        {
            fRes = CCOL_DT_Tri::fTestSphere( (CGraphBV_Sphere &) * _SrcObj,_Tri );
        }
        break;

        case eGraphBV_Box:
        {
            fRes = CCOL_DT_Tri::fTestBox( (CGraphBV_Box &) * _SrcObj,_Tri );
        }
        break;

        case eGraphBV_Point:
        {
            fRes = CCOL_DT_Tri::fTestPoint(_SrcObj->GetCenter(),_Tri);
        }
        break;
    }

    // Control result
    if ( (fRes < CCOL_ColState::fMinColTime) && (fRes >= 0.0f) )
        CCOL_ColState::fMinColTime = fRes;

    return(fRes);
}

// Additional Declarations
