// -----------------------------------------------------------------------------
#include "ParticleSystems\CGParticleSystem_Generic.h"
// -----------------------------------------------------------------------------
CGParticleSystem_Generic::CGParticleSystem_Generic()
        : fPEnergyFact(0), fPInitialEnergyFact(0), fPInitialSpeedFact(0), fPInitialSizeFact(0)
{
}
// -----------------------------------------------------------------------------
CGParticleSystem_Generic::~CGParticleSystem_Generic()
{
}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic::SetColorsFact (CGColor _oInitialColor, CGColor _oFinalColor)
{
  	RGBAInitialValue.V4(_oInitialColor.r,
						_oInitialColor.g,
						_oInitialColor.b,
						_oInitialColor.a);

	RGBAFact.Assign(*(CVect4 *)&_oFinalColor);
	RGBAFact.Sub(*(CVect4 *)&_oInitialColor);
	RGBAFact.Scale(1.0f /this->fPEnergyFact);
}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic::SetSizeFact (float _fSizeFact)
{
  	fPInitialSizeFact = _fSizeFact;
}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic::SetEnergyFact (float _fInitialEnergy, float _fEnergyFact)
{
  	fPInitialEnergyFact = _fInitialEnergy;
	fPEnergyFact        = _fEnergyFact;
}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic::SetSpeedFact (float _fSpeedFact)
{
  	fPInitialSpeedFact = _fSpeedFact;
}
// -----------------------------------------------------------------------------
