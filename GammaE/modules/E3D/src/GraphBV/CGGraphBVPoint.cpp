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
// CGGraphBVPoint
#include "CGGraphBVPoint.h"
// -----------------------------------------------------------------------------
void CGGraphBVPoint::Init(const CGVect3& _oCenter)
{
    m_oVol.Init(_oCenter);
}
// -----------------------------------------------------------------------------
void CGGraphBVPoint::Copy(const CGGraphBV& _oSrc)
{
    Init(_oSrc.oGetCenter());
}
// -----------------------------------------------------------------------------
void CGGraphBVPoint::Transform(const CGMatrix4x4& _oM)
{
    CGVect3 oCenter = m_oVol.oGetCenter();
    _oM.TransformPoint(&oCenter);
    m_oVol.Init(oCenter);
}
// -----------------------------------------------------------------------------
void CGGraphBVPoint::Compute(CGVect3* _poVXs, uint _uiNumVXs)
{
    if (_uiNumVXs == 0 ) return;

    CGVect3 oCenter;
    
    oCenter.Set(0.0f, 0.0f, 0.0f);
    for (uint iVX = 0; iVX < _uiNumVXs; iVX++ )
        oCenter.Add(_poVXs[iVX]);

    oCenter.Scale(1.0f / (float)_uiNumVXs);

    m_oVol.Init(oCenter);
}
// -----------------------------------------------------------------------------
const CGVect3 & CGGraphBVPoint::oGetCenter () const
{
    return (m_oVol.oGetCenter());
}
// -----------------------------------------------------------------------------
float CGGraphBVPoint::GetRange(char _cAxis) const
{
    return(0.0f);
}
// -----------------------------------------------------------------------------
int CGGraphBVPoint::TestFrustum(const CGBVFrustum& _oFrustum) const
{
    // / Test the intersection of a given bounding volume against a given frustum
    bool bIntersect = Math::bBVIntersectFrustum(m_oVol, _oFrustum);
    return bIntersect ? 1 : 0;
}
// -----------------------------------------------------------------------------
int CGGraphBVPoint::TestInside(const CGVect3& _oPos) const
{
    return (_oPos.bEqual(m_oVol.oGetCenter()) );
}
// -----------------------------------------------------------------------------
const CGBoundingVolume& CGGraphBVPoint::oGetBV() const
{
    return m_oVol;
}
// -----------------------------------------------------------------------------
const CGBVPoint& CGGraphBVPoint::oGetPoint() const
{
    return (m_oVol);
}
// -----------------------------------------------------------------------------
EGBoundingVolumeType CGGraphBVPoint::eGetTypeID() const
{
    return EGBoundingVolumeType::BVT_POINT;
}

// -----------------------------------------------------------------------------
// Additional Declarations
