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
// CGParticleSystem_Sparks
#include "ParticleSystems\CGParticleSystem_Sparks.h"

// Class CGParticleSystem_Sparks

CGParticleSystem_Sparks::CGParticleSystem_Sparks()
{
    fPInitialEnergyFact = 1.0f;
    fPInitialSpeedFact = 500.0f;

    fPEnergyFact = 0.05f;
    fPInitialSizeFact = 2.0f;
    RGBAInitialValue.Set(1.0f,1.0f,0.0f,1.0f);
    RGBAFact.Set(0.1f,0.25f,0.0f,0.1f);
}

CGParticleSystem_Sparks::~CGParticleSystem_Sparks()
{
}

// Additional Declarations
