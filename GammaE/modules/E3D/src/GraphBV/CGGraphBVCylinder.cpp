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
#include "CGGraphBVCylinder.h"

// -----------------------------------------------------------------------------
void CGGraphBVCylinder::Init(const CGVect3& _oCenter, float _fRadius, float _fHeight)
{
    m_oVol.Init(_oCenter, _fRadius, _fHeight);
}
// -----------------------------------------------------------------------------
void CGGraphBVCylinder::Transform(const CGMatrix4x4& _oM)
{
}
// -----------------------------------------------------------------------------
void CGGraphBVCylinder::Copy(const CGGraphBV& _oSrc)
{
}
// -----------------------------------------------------------------------------
void CGGraphBVCylinder::Compute (CGVect3* _poVXs, uint _uiNumVXs)
{
}
// -----------------------------------------------------------------------------
float CGGraphBVCylinder::GetRange(char _cAxis) const
{
    assert(((_cAxis >= 0) && (_cAxis <= 2)) && "Incorrect axis");

    switch (_cAxis)
    {
        case 0: 
        case 'x':   return (m_oVol.fGetRadius());

        case 1: 
        case 'y':   return (m_oVol.fGetRadius());

        case 2: 
        case 'z':   return (m_oVol.fGetHeight());
    }

    return(0);
}
// -----------------------------------------------------------------------------
const CGVect3 & CGGraphBVCylinder::oGetCenter () const
{
    return(m_oVol.oGetCenter());
}
// -----------------------------------------------------------------------------
int CGGraphBVCylinder::TestFrustum(const CGBVFrustum& _oFrustum) const
{
    return(1);
}
// -----------------------------------------------------------------------------
int CGGraphBVCylinder::TestInside(const CGVect3& _Pos) const
{
    return(0);
}
// -----------------------------------------------------------------------------
const CGBVCylinder& CGGraphBVCylinder::GetCylinder() const
{
    return (m_oVol);
}
// -----------------------------------------------------------------------------
const CGBoundingVolume& CGGraphBVCylinder::oGetBV() const
{
    return (m_oVol);
}
// -----------------------------------------------------------------------------
EGBoundingVolumeType CGGraphBVCylinder::eGetTypeID() const
{
    return EGBoundingVolumeType::BVT_CYLINDER;
}
// -----------------------------------------------------------------------------
