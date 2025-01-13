//## begin module%3B754DC701DD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B754DC701DD.cm

//## begin module%3B754DC701DD.cp preserve=no
//## end module%3B754DC701DD.cp

//## Module: CParticleSystem_Generic%3B754DC701DD; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\ParticleSystems\CParticleSystem_Generic.cpp

//## begin module%3B754DC701DD.additionalIncludes preserve=no
//## end module%3B754DC701DD.additionalIncludes

//## begin module%3B754DC701DD.includes preserve=yes
//## end module%3B754DC701DD.includes

// CParticleSystem_Generic
#include "Scene\ParticleSystems\CParticleSystem_Generic.h"
//## begin module%3B754DC701DD.additionalDeclarations preserve=yes
//## end module%3B754DC701DD.additionalDeclarations


// Class CParticleSystem_Generic 








CParticleSystem_Generic::CParticleSystem_Generic()
  //## begin CParticleSystem_Generic::CParticleSystem_Generic%.hasinit preserve=no
      : fPEnergyFact(0), fPInitialEnergyFact(0), fPInitialSpeedFact(0), fPInitialSizeFact(0)
  //## end CParticleSystem_Generic::CParticleSystem_Generic%.hasinit
  //## begin CParticleSystem_Generic::CParticleSystem_Generic%.initialization preserve=yes
  //## end CParticleSystem_Generic::CParticleSystem_Generic%.initialization
{
  //## begin CParticleSystem_Generic::CParticleSystem_Generic%.body preserve=yes
  //## end CParticleSystem_Generic::CParticleSystem_Generic%.body
}


CParticleSystem_Generic::~CParticleSystem_Generic()
{
  //## begin CParticleSystem_Generic::~CParticleSystem_Generic%.body preserve=yes
  //## end CParticleSystem_Generic::~CParticleSystem_Generic%.body
}



//## Other Operations (implementation)
void CParticleSystem_Generic::SetColorsFact (TFColor _oInitialColor, TFColor _oFactColor)
{
  //## begin CParticleSystem_Generic::SetColorsFact%1020210460.body preserve=yes
	RGBAInitialValue.V4(_oInitialColor.r,
						_oInitialColor.g,
						_oInitialColor.b,
						_oInitialColor.a);

	RGBAFact.V4(_oFactColor.r,
				_oFactColor.g,
				_oFactColor.b,
				_oFactColor.a);
  //## end CParticleSystem_Generic::SetColorsFact%1020210460.body
}

void CParticleSystem_Generic::SetSizeFact (float _fSizeFact)
{
  //## begin CParticleSystem_Generic::SetSizeFact%1020210461.body preserve=yes
	fPInitialSizeFact = _fSizeFact;
  //## end CParticleSystem_Generic::SetSizeFact%1020210461.body
}

void CParticleSystem_Generic::SetEnergyFact (float _fInitialEnergy, float _fEnergyFact)
{
  //## begin CParticleSystem_Generic::SetEnergyFact%1020210462.body preserve=yes
	fPInitialEnergyFact = _fInitialEnergy;
	fPEnergyFact        = _fEnergyFact;
  //## end CParticleSystem_Generic::SetEnergyFact%1020210462.body
}

void CParticleSystem_Generic::SetSpeedFact (float _fSpeedFact)
{
  //## begin CParticleSystem_Generic::SetSpeedFact%1020210463.body preserve=yes
	fPInitialSpeedFact = _fSpeedFact;
  //## end CParticleSystem_Generic::SetSpeedFact%1020210463.body
}

// Additional Declarations
  //## begin CParticleSystem_Generic%3B754DC701DD.declarations preserve=yes
  //## end CParticleSystem_Generic%3B754DC701DD.declarations

//## begin module%3B754DC701DD.epilog preserve=yes
//## end module%3B754DC701DD.epilog
