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
// CGraphBV_Cylinder
#include "BoundingVolume\GraphBoundVol\CGraphBV_Cylinder.h"

// Class CGraphBV_Cylinder

CGraphBV_Cylinder::CGraphBV_Cylinder()
{
}

CGraphBV_Cylinder::~CGraphBV_Cylinder()
{
}

void CGraphBV_Cylinder::Transform (CMatrix4x4& M)
{
}

void CGraphBV_Cylinder::Compute (CGVect3* VXs, int iNumVXs)
{
}

float CGraphBV_Cylinder::GetRange (int iAxis)
{
    switch ( iAxis )
    {
        case 0: return (Vol.Radius);

        case 1: return (Vol.Radius);

        case 2: return (Vol.Height);
    }

    return(0);
}

CGVect3 & CGraphBV_Cylinder::GetCenter ()
{
    return(Vol.Center);
}

int CGraphBV_Cylinder::TestFrustum (CE3D_Frustum& _Frustum)
{
    return(1);
}

void CGraphBV_Cylinder::Init (CGVect3 Max, CGVect3 Min)
{
    Vol.Init(Max,Min);
}

CBoundingCylinder* CGraphBV_Cylinder::pGetCylinder ()
{
    return (&Vol);
}

int CGraphBV_Cylinder::TestInside (CGVect3& _Pos)
{
    return(0);
}

// Additional Declarations
