//## begin module%3CDED98200C6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDED98200C6.cm

//## begin module%3CDED98200C6.cp preserve=no
//## end module%3CDED98200C6.cp

//## Module: CRTME_Light%3CDED98200C6; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\RTMapEntities\CRTME_Light.cpp

//## begin module%3CDED98200C6.additionalIncludes preserve=no
//## end module%3CDED98200C6.additionalIncludes

//## begin module%3CDED98200C6.includes preserve=yes
//## end module%3CDED98200C6.includes

// CRTME_Light
#include "Game\Entities\RTMapEntities\CRTME_Light.h"
//## begin module%3CDED98200C6.additionalDeclarations preserve=yes
//## end module%3CDED98200C6.additionalDeclarations


// Class CRTME_Light 



CRTME_Light::CRTME_Light()
  //## begin CRTME_Light::CRTME_Light%.hasinit preserve=no
      : poSwitch(NULL), poLightInfo(NULL)
  //## end CRTME_Light::CRTME_Light%.hasinit
  //## begin CRTME_Light::CRTME_Light%.initialization preserve=yes
  //## end CRTME_Light::CRTME_Light%.initialization
{
  //## begin CRTME_Light::CRTME_Light%.body preserve=yes
  //## end CRTME_Light::CRTME_Light%.body
}


CRTME_Light::~CRTME_Light()
{
  //## begin CRTME_Light::~CRTME_Light%.body preserve=yes
  //## end CRTME_Light::~CRTME_Light%.body
}



//## Other Operations (implementation)
void CRTME_Light::Think (float _fDelta)
{
  //## begin CRTME_Light::Think%1021237865.body preserve=yes
	if (bTriggered())
	{
		poSwitch->Select(0);
	}
	else
		poSwitch->Unselect(0);
  //## end CRTME_Light::Think%1021237865.body
}

void CRTME_Light::Init (CMapEnt_Light* _poLInfo)
{
  //## begin CRTME_Light::Init%1021237872.body preserve=yes
  //## end CRTME_Light::Init%1021237872.body
}

// Additional Declarations
  //## begin CRTME_Light%3CDED98200C6.declarations preserve=yes
  //## end CRTME_Light%3CDED98200C6.declarations

//## begin module%3CDED98200C6.epilog preserve=yes
//## end module%3CDED98200C6.epilog
