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
void CGParticleSystem_Generic::SetColorsPars(CGColor _oInitialColor, CGColor _oFinalColor, float _fRandomness)
{
  	RGBAInitialValue = _oInitialColor;

    RGBAFact.r = (_oFinalColor.r - _oInitialColor.r) / fPEnergyFact;
    RGBAFact.g = (_oFinalColor.g - _oInitialColor.g) / fPEnergyFact;
    RGBAFact.b = (_oFinalColor.b - _oInitialColor.b) / fPEnergyFact;
    RGBAFact.a = (_oFinalColor.a - _oInitialColor.a) / fPEnergyFact;
}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic::SetSizePars(float _fInitialSize, float _fFinalSize, float _fRandomness)
{
  	fPInitialSizeFact = _fInitialSize;
}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic::SetAnglePars(float _fInitialAngle, float _fFinalAngle, float _fRandomness)
{

}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic::SetEnergyFact (float _fInitialEnergy, float _fEnergyFact, float _fRandomness)
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
