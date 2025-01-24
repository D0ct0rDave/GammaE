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

void CGraphBV_Point::Compute (CVect3* VXs, int iNumVXs)
{
    if ( iNumVXs <= 0 ) return;

    Point.V3(0.0f,0.0f,0.0f);
    for ( int iVX = 0; iVX < iNumVXs; iVX++ )
        Point.Add(VXs[iVX]);

    Point.Scale(1.0f / (float)iNumVXs);
}

CVect3 & CGraphBV_Point::GetCenter ()
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

void CGraphBV_Point::Init (CVect3 Max, CVect3 Min)
{
    Point.Assign(Max);
    Point.Add(Min);
    Point.Scale(0.5f);
}

int CGraphBV_Point::TestInside (CVect3& _Pos)
{
    return ( _Pos.bEqual(Point) );
}

CVect3* CGraphBV_Point::pGetPoint ()
{
    return(&Point);
}

// Additional Declarations
