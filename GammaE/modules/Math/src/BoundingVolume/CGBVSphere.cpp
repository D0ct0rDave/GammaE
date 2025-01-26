// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "BoundingVolume\CGBVSphere.h"
// ----------------------------------------------------------------------------
CGBVSphere::CGBVSphere()
{
    m_eType = BVT_SPHERE;
}
// ----------------------------------------------------------------------------
CGBVSphere::CGBVSphere(CGBVSphere& _oSphere)
{
    CGBVSphere();
    Init(_oSphere.oGetCenter(), _oSphere.fGetRadius());
}
// ----------------------------------------------------------------------------
void CGBVSphere::Init (const CGVect3& _oCenter, float _fRadius)
{
    m_oCenter.Assign(_oCenter);
    m_fRadius = _fRadius;
}
// ----------------------------------------------------------------------------
