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
// CGGraphBVSphere
#include "CGGraphBVSphere.h"
// -----------------------------------------------------------------------------

EGBoundingVolumeType CGGraphBVSphere::eGetTypeID() const
{
    return EGBoundingVolumeType::BVT_SPHERE;
}

void CGGraphBVSphere::Transform (const CGMatrix4x4& _oM)
{
    CGVect3 center = m_oVol.oGetCenter();
    _oM.TransformPoint(&center);
    m_oVol.Init(center, m_oVol.fGetRadius());
}

void CGGraphBVSphere::Compute (CGVect3* _poVXs, uint _uiNumVXs)
{
    if ( _uiNumVXs == 0) return;

    uint cV;
    float fSqRad;
    CGVect3 oCenter;
    float fRadius;

    // Compute center as the average of the input points
    oCenter.Set(0.0f,0.0f,0.0f);

    for (cV = 0; cV < _uiNumVXs; cV++ )
        oCenter.Add(_poVXs[cV]);

    oCenter.Scale(1.0f / (float)_uiNumVXs);

    // Compute sphere radius
    fRadius = 0.0f;
    for ( cV = 0; cV < _uiNumVXs; cV++ )
    {
        fSqRad = oCenter.fSqDistance(_poVXs[cV]);
        if ( fSqRad > fRadius )
            fRadius = fSqRad;
    }

    fRadius = Math::fSqrt(fRadius);

    // Initialize bounding volume
    m_oVol.Init(oCenter,fRadius);
}

float CGGraphBVSphere::GetRange(char _cAxis) const
{
    return( m_oVol.fGetRadius() * 2);
}

const CGVect3& CGGraphBVSphere::GetCenter() const
{
    return (m_oVol.oGetCenter());
}

int CGGraphBVSphere::TestFrustum(const CGBVFrustum& _oFrustum)
{
    // / Test the intersection of a given bounding volume against a given frustum
    bool bIntersect = Math::bBVIntersectFrustum(m_oVol, _oFrustum);
    return bIntersect ? 1 : 0;
}

void CGGraphBVSphere::Init(const CGVect3& _oMax, const CGVect3& _oMin)
{
    // Compute extents
    CGVect3 oExtents;
    oExtents.Assign(_oMax);
    oExtents.Sub(_oMin);
    oExtents.Scale(0.5f);

    // Compute Center
    CGVect3 oCenter;
    oCenter.Assign(_oMax);
    oCenter.Add(_oMax);
    oCenter.Scale(0.5f);

    m_oVol.Init(oCenter, oExtents.fModule());
}

CGBVSphere* CGGraphBVSphere::poGetSphere ()
{
    return (&m_oVol);
}

int CGGraphBVSphere::TestInside(const CGVect3& _oPos)
{
    CGVect3 oRelSphPos;

    oRelSphPos.Assign(_oPos);
    oRelSphPos.Sub   (m_oVol.oGetCenter());
    
    const float radius = m_oVol.fGetRadius();
    const float sqRadius = radius * radius;

    return (oRelSphPos.fSqDistance(m_oVol.oGetCenter()) <= sqRadius);
}

void CGGraphBVSphere::Copy(const CGGraphBV& _oSrc)
{
    m_oVol.Init(_oSrc.GetCenter(), _oSrc.GetExtents().fModule());
}

