//## begin module%3B7467DC00C6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7467DC00C6.cm

//## begin module%3B7467DC00C6.cp preserve=no
//## end module%3B7467DC00C6.cp

//## Module: CParticleSystem_Coolant%3B7467DC00C6; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\ParticleSystems\CParticleSystem_Coolant.cpp

//## begin module%3B7467DC00C6.additionalIncludes preserve=no
//## end module%3B7467DC00C6.additionalIncludes

//## begin module%3B7467DC00C6.includes preserve=yes
//## end module%3B7467DC00C6.includes

// CParticleSystem_Coolant
#include "Scene\ParticleSystems\CParticleSystem_Coolant.h"
//## begin module%3B7467DC00C6.additionalDeclarations preserve=yes
//## end module%3B7467DC00C6.additionalDeclarations


// Class CParticleSystem_Coolant 

CParticleSystem_Coolant::CParticleSystem_Coolant()
  //## begin CParticleSystem_Coolant::CParticleSystem_Coolant%.hasinit preserve=no
  //## end CParticleSystem_Coolant::CParticleSystem_Coolant%.hasinit
  //## begin CParticleSystem_Coolant::CParticleSystem_Coolant%.initialization preserve=yes
  //## end CParticleSystem_Coolant::CParticleSystem_Coolant%.initialization
{
  //## begin CParticleSystem_Coolant::CParticleSystem_Coolant%.body preserve=yes
	fPInitialEnergyFact = 1.0f;
	fPInitialSpeedFact  = 2.0f;

	fPEnergyFact		= 0.005f;
	fPInitialSizeFact	= 2.0f;
	
	// Initially the particle is cian
	RGBAInitialValue.V4(0.0f,1.0f,1.0f,1.0f);	
	RGBAFact.V4(0.0f,0.05f,0.01f,0.01f);	
  //## end CParticleSystem_Coolant::CParticleSystem_Coolant%.body
}


CParticleSystem_Coolant::~CParticleSystem_Coolant()
{
  //## begin CParticleSystem_Coolant::~CParticleSystem_Coolant%.body preserve=yes
  //## end CParticleSystem_Coolant::~CParticleSystem_Coolant%.body
}


// Additional Declarations
  //## begin CParticleSystem_Coolant%3B7467DC00C6.declarations preserve=yes
  //## end CParticleSystem_Coolant%3B7467DC00C6.declarations

//## begin module%3B7467DC00C6.epilog preserve=yes
//## end module%3B7467DC00C6.epilog
