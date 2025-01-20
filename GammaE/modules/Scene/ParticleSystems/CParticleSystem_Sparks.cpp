//## begin module%3B7463D401B2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7463D401B2.cm

//## begin module%3B7463D401B2.cp preserve=no
//## end module%3B7463D401B2.cp

//## Module: CParticleSystem_Sparks%3B7463D401B2; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\ParticleSystems\CParticleSystem_Sparks.cpp

//## begin module%3B7463D401B2.additionalIncludes preserve=no
//## end module%3B7463D401B2.additionalIncludes

//## begin module%3B7463D401B2.includes preserve=yes
//## end module%3B7463D401B2.includes

// CParticleSystem_Sparks
#include "Scene\ParticleSystems\CParticleSystem_Sparks.h"
//## begin module%3B7463D401B2.additionalDeclarations preserve=yes
//## end module%3B7463D401B2.additionalDeclarations


// Class CParticleSystem_Sparks 

CParticleSystem_Sparks::CParticleSystem_Sparks()
  //## begin CParticleSystem_Sparks::CParticleSystem_Sparks%.hasinit preserve=no
  //## end CParticleSystem_Sparks::CParticleSystem_Sparks%.hasinit
  //## begin CParticleSystem_Sparks::CParticleSystem_Sparks%.initialization preserve=yes
  //## end CParticleSystem_Sparks::CParticleSystem_Sparks%.initialization
{
  //## begin CParticleSystem_Sparks::CParticleSystem_Sparks%.body preserve=yes
	fPInitialEnergyFact = 1.0f;
	fPInitialSpeedFact  = 500.0f;

	fPEnergyFact		= 0.05f;
	fPInitialSizeFact	= 2.0f;
	RGBAInitialValue.V4(1.0f,1.0f,0.0f,1.0f);
	RGBAFact.V4(0.1f,0.25f,0.0f,0.1f);	
  //## end CParticleSystem_Sparks::CParticleSystem_Sparks%.body
}


CParticleSystem_Sparks::~CParticleSystem_Sparks()
{
  //## begin CParticleSystem_Sparks::~CParticleSystem_Sparks%.body preserve=yes
  //## end CParticleSystem_Sparks::~CParticleSystem_Sparks%.body
}


// Additional Declarations
  //## begin CParticleSystem_Sparks%3B7463D401B2.declarations preserve=yes
  //## end CParticleSystem_Sparks%3B7463D401B2.declarations

//## begin module%3B7463D401B2.epilog preserve=yes
//## end module%3B7463D401B2.epilog
