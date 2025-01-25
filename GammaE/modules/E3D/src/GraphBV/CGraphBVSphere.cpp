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
// CGBVSphere
#include "BoundingVolume\GraphBoundVol\CGBVSphere.h"

// Class CGBVSphere

CGBVSphere::CGBVSphere()
{
    eTypeID = eGraphBV_Sphere;
}

CGBVSphere::~CGBVSphere()
{
}

void CGBVSphere::Transform (CGMatrix4x4& M)
{
    M.TransformPoint(Vol.m_oCenter);
}

void CGBVSphere::Compute (CGVect3* VXs, int iNumVXs)
{
    if ( !iNumVXs ) return;

    int cV;
    float fSqRad;
    CGVect3 oCenter;
    float fRadius;

    // Compute center as the average of the input points
    oCenter.Set(0.0f,0.0f,0.0f);

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

float CGBVSphere::GetRange (int iAxis)
{
    return(Vol.m_fRadius * 2);
}

CGVect3 & CGBVSphere::GetCenter ()
{
    return (Vol.m_oCenter);
}

int CGBVSphere::TestFrustum (CE3D_Frustum& _Frustum)
{
    return ( _Frustum.TestSphere(Vol.m_fRadius,Vol.m_oCenter) );
}

void CGBVSphere::Init (CGVect3 Max, CGVect3 Min)
{
    Vol.Init(Max,Min);
}

CBoundingSphere* CGBVSphere::pGetSphere ()
{
    return (&Vol);
}

int CGBVSphere::TestInside (CGVect3& _Pos)
{
    CGVect3 RelSphPos;

    RelSphPos.Assign(_Pos);
    RelSphPos.Sub   (Vol.m_oCenter);

    return (RelSphPos.fSqDistance(Vol.m_oCenter) <= Vol.m_fRadius * Vol.m_fRadius);
}

void CGBVSphere::Copy (CGBoundingVolume* Src)
{
    Vol.Init( Src->GetCenter(),Src->GetExtents().fModule() );
}

// Additional Declarations
