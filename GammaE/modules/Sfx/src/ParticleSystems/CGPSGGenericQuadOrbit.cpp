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
// -----------------------------------------------------------------------------
#include "CGPSGGenericQuadOrbit.h"
#include "CGParticleSystemInstance.h"
// -----------------------------------------------------------------------------
void CGPSGGenericQuadOrbit::InitParticle (CGPSGGenericQuadParticle* _poPart)
{
    CGPSGGenericQuad::InitParticle(_poPart);

    int iIdx = ( *(uint*)_poPart / sizeof(CGPSGGenericQuadParticle) ) % 360;
    float fAngle = _2PI_ * ( (float)iIdx / 360.0f ) * m_fOrbitFactor;

    _poPart->m_oDir.y = Math::fCos(fAngle);
    _poPart->m_oDir.z = Math::fSin(fAngle);
    _poPart->m_oDir.x = 0.0f;
    _poPart->m_oDir.Normalize();
}
// -----------------------------------------------------------------------------
