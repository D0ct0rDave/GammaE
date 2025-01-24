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
// CGraphBV_Sphere
#include "BoundingVolume\GraphBoundVol\CGraphBV_Sphere.h"

// Class CGraphBV_Sphere

CGraphBV_Sphere::CGraphBV_Sphere()
{
    eTypeID = eGraphBV_Sphere;
}

CGraphBV_Sphere::~CGraphBV_Sphere()
{
}

void CGraphBV_Sphere::Transform (CMatrix4x4& M)
{
    M.TransformPoint(Vol.m_oCenter);
}

void CGraphBV_Sphere::Compute (CVect3* VXs, int iNumVXs)
{
    if ( !iNumVXs ) return;

    int cV;
    float fSqRad;
    CVect3 oCenter;
    float fRadius;

    // Compute center as the average of the input points
    oCenter.V3(0.0f,0.0f,0.0f);

    for ( cV = 0; cV < iNumVXs; cV++ )
        oCenter.Add(VXs[cV]);

    oCenter.Scale(1.0f / (float)iNumVXs);

    // Compute sphere radius
    fRadius = 0.0f;
    for ( cV = 0; cV < iNumVXs; cV++ )
    {
        fSqRad = oCenter.fSqDistance(VXs[cV]);
        if ( fSqRad > fRadius )
            fRadius = fSqRad;
    }

    fRadius = MATH_fSqrt(fRadius);

    // Initialize bounding volume
    Vol.Init(oCenter,fRadius);
}

float CGraphBV_Sphere::GetRange (int iAxis)
{
    return(Vol.m_fRadius * 2);
}

CVect3 & CGraphBV_Sphere::GetCenter ()
{
    return (Vol.m_oCenter);
}

int CGraphBV_Sphere::TestFrustum (CE3D_Frustum& _Frustum)
{
    return ( _Frustum.TestSphere(Vol.m_fRadius,Vol.m_oCenter) );
}

void CGraphBV_Sphere::Init (CVect3 Max, CVect3 Min)
{
    Vol.Init(Max,Min);
}

CBoundingSphere* CGraphBV_Sphere::pGetSphere ()
{
    return (&Vol);
}

int CGraphBV_Sphere::TestInside (CVect3& _Pos)
{
    CVect3 RelSphPos;

    RelSphPos.Assign(_Pos);
    RelSphPos.Sub   (Vol.m_oCenter);

    return (RelSphPos.fSqDistance(Vol.m_oCenter) <= Vol.m_fRadius * Vol.m_fRadius);
}

void CGraphBV_Sphere::Copy (CGraphBV* Src)
{
    Vol.Init( Src->GetCenter(),Src->GetExtents().fModule() );
}

// Additional Declarations
