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
#include "ParticleSystems\CGParticleSystem_Coolant.h"
// -----------------------------------------------------------------------------
CGParticleSystem_Coolant::CGParticleSystem_Coolant()
{
    fPInitialEnergyFact = 1.0f;
    fPInitialSpeedFact = 2.0f;

    fPEnergyFact = 0.005f;
    fPInitialSizeFact = 2.0f;

    // Initially the particle is cian
    RGBAInitialValue.Set(0.0f,1.0f,1.0f,1.0f);
    RGBAFact.Set(0.0f,0.05f,0.01f,0.01f);
}
// -----------------------------------------------------------------------------
CGParticleSystem_Coolant::~CGParticleSystem_Coolant()
{
}
// -----------------------------------------------------------------------------
