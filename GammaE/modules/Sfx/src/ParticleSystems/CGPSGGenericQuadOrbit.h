// -----------------------------------------------------------------------------
#ifndef CGPSGGenericQuadOrbit_h
#define CGPSGGenericQuadOrbit_h 1
// -----------------------------------------------------------------------------
#include "CGParticle.h"
#include "CGPSGGenericQuad.h"
// -----------------------------------------------------------------------------
class CGPSGGenericQuadOrbit : public CGPSGGenericQuad
{
	public:
		virtual void InitParticle (CGPSGGenericQuadParticle* _poPart);
		void SetOrbitFactor(float _fOrbitFactor) { m_fOrbitFactor = _fOrbitFactor; };
	
	protected:
		float m_fOrbitFactor;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
