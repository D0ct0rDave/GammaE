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
// CGraphBV_Point
#include "BoundingVolume\GraphBoundVol\CGraphBV_Point.h"

// Class CGraphBV_Point

CGraphBV_Point::CGraphBV_Point()
{
    eTypeID = eGraphBV_Point;
}

CGraphBV_Point::~CGraphBV_Point()
{
}

void CGraphBV_Point::Transform (CMatrix4x4& M)
{
    M.TransformPoint(Point);
}

void CGraphBV_Point::Compute (CGVect3* VXs, int iNumVXs)
{
    if ( iNumVXs <= 0 ) return;

    Point.Set(0.0f,0.0f,0.0f);
    for ( int iVX = 0; iVX < iNumVXs; iVX++ )
        Point.Add(VXs[iVX]);

    Point.Scale(1.0f / (float)iNumVXs);
}

CGVect3 & CGraphBV_Point::GetCenter ()
{
    return (Point);
}

float CGraphBV_Point::GetRange (int iAxis)
{
    return(0.0f);
}

int CGraphBV_Point::TestFrustum (CE3D_Frustum& _Frustum)
{
    return ( _Frustum.TestPoint(Point) );
}

void CGraphBV_Point::Init (CGVect3 Max, CGVect3 Min)
{
    Point.Assign(Max);
    Point.Add(Min);
    Point.Scale(0.5f);
}

int CGraphBV_Point::TestInside (CGVect3& _Pos)
{
    return ( _Pos.bEqual(Point) );
}

CGVect3* CGraphBV_Point::pGetPoint ()
{
    return(&Point);
}

// Additional Declarations
