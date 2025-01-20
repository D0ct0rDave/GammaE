// -----------------------------------------------------------------------------
#include "CGPSGGenericQuadOrbit.h"
#include "CGParticleSystemInstance.h"
// -----------------------------------------------------------------------------
void CGPSGGenericQuadOrbit::InitParticle (CGPSGGenericQuadParticle* _poPart)
{
	CGPSGGenericQuad::InitParticle(_poPart);
	
	int iIdx = (*(uint*)_poPart / sizeof(CGPSGGenericQuadParticle)) % 360;
	float fAngle =  _2PI_ * ((float)iIdx / 360.0f) * m_fOrbitFactor;

	_poPart->m_oDir.y = MATH_Common::fCos(fAngle);
	_poPart->m_oDir.z = MATH_Common::fSin(fAngle);
	_poPart->m_oDir.x = 0.0f;
	_poPart->m_oDir.Normalize();
}
// -----------------------------------------------------------------------------

