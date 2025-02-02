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
#include "CGBVCylinder.h"

// ----------------------------------------------------------------------------
CGBVCylinder::CGBVCylinder() :
    m_fHeight(0.0f),
    m_fRadius(0.0f)
{
    m_eType = BVT_CYLINDER;
}
// ----------------------------------------------------------------------------
void CGBVCylinder::Init(const CGVect3& _oCenter, float _fRadius, float _fHeight)
{
    m_oCenter = _oCenter;
    m_fRadius = _fRadius;
    m_fHeight = _fHeight;
}
// ----------------------------------------------------------------------------
