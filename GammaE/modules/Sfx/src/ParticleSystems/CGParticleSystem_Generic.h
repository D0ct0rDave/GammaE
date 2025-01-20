// -----------------------------------------------------------------------------
#ifndef CGParticleSystem_Generic_h
#define CGParticleSystem_Generic_h 1
// -----------------------------------------------------------------------------

#include "ParticleSystems\CGParticleSystem.h"

// -----------------------------------------------------------------------------
class CGParticleSystem_Generic : public CGParticleSystem
{   
	public:
		
		CGParticleSystem_Generic();

		virtual ~CGParticleSystem_Generic();

        void SetColorsPars(CGColor _oInitialColor, CGColor _oFinalColor,float _fRandomness);

        void SetSizePars(float _fInitialSize,float _fFinalSize,float _fRandomness);

        void SetAnglePars(float _fInitialAngle,float _fFinalAngle,float _fRandomness);

        void SetEnergyFact(float _fInitialEnergy, float _fEnergyFact,float _fRandomness);

        void SetSpeedFact(float _fSpeedFact);
        

  protected:

		CVect4 RGBAFact;

		CVect4 RGBAInitialValue;

		CVect3 InitialSpeedFact;

		float fPEnergyFact;

		float fPInitialEnergyFact;

		float fPInitialSpeedFact;

		float fPInitialSizeFact;
           
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------

