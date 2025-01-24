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

        CGColor RGBAFact;

        CGColor RGBAInitialValue;

        CVect3 InitialSpeedFact;

        float fPEnergyFact;

        float fPInitialEnergyFact;

        float fPInitialSpeedFact;

        float fPInitialSizeFact;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
