//## begin module%3AFD246C0316.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFD246C0316.cm

//## begin module%3AFD246C0316.cp preserve=no
//## end module%3AFD246C0316.cp

//## Module: CLMSector_Pal%3AFD246C0316; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\Sector\LightMap\CLMSector_Pal.cpp

//## begin module%3AFD246C0316.additionalIncludes preserve=no
//## end module%3AFD246C0316.additionalIncludes

//## begin module%3AFD246C0316.includes preserve=yes
#include <string.h>
//## end module%3AFD246C0316.includes

// CLMSector_Pal
#include "TerrainData\Sector\LightMap\CLMSector_Pal.h"
//## begin module%3AFD246C0316.additionalDeclarations preserve=yes
unsigned char 	LMS_P_ucLight;
float           LMS_P_fLight[3];
CLightElem 		LMS_P_L;
//## end module%3AFD246C0316.additionalDeclarations


// Class CLMSector_Pal


CLMSector_Pal::CLMSector_Pal()
  //## begin CLMSector_Pal::CLMSector_Pal%.hasinit preserve=no
  //## end CLMSector_Pal::CLMSector_Pal%.hasinit
  //## begin CLMSector_Pal::CLMSector_Pal%.initialization preserve=yes
  //## end CLMSector_Pal::CLMSector_Pal%.initialization
{
  //## begin CLMSector_Pal::CLMSector_Pal%.body preserve=yes
	ulID = MAKE_RIFF_ID('L','S','P','L');
  //## end CLMSector_Pal::CLMSector_Pal%.body
}


CLMSector_Pal::~CLMSector_Pal()
{
  //## begin CLMSector_Pal::~CLMSector_Pal%.body preserve=yes
  //## end CLMSector_Pal::~CLMSector_Pal%.body
}



//## Other Operations (implementation)
CSectElem & CLMSector_Pal::GetValue (int _X, int _Y)
{
  //## begin CLMSector_Pal::GetValue%989667589.body preserve=yes
	LMS_P_ucLight = ((unsigned char *)pData)[_Y*Resolution+_X];

	LMS_P_fLight[0] = Pal[ LMS_P_ucLight*3 + 0 ]/255.0f;
	LMS_P_fLight[1] = Pal[ LMS_P_ucLight*3 + 1 ]/255.0f;
	LMS_P_fLight[2] = Pal[ LMS_P_ucLight*3 + 2 ]/255.0f;

	LMS_P_L.Set(LMS_P_fLight);
	return LMS_P_L;
  //## end CLMSector_Pal::GetValue%989667589.body
}

void CLMSector_Pal::SetValue (int _X, int _Y, CSectElem &_Value)
{
  //## begin CLMSector_Pal::SetValue%989667590.body preserve=yes
  //## end CLMSector_Pal::SetValue%989667590.body
}

unsigned long CLMSector_Pal::DataSize ()
{
  //## begin CLMSector_Pal::DataSize%989667591.body preserve=yes
	return( 768 + Resolution*Resolution );
  //## end CLMSector_Pal::DataSize%989667591.body
}

CSector * CLMSector_Pal::CreateClass ()
{
  //## begin CLMSector_Pal::CreateClass%989667592.body preserve=yes
	return (new CLMSector_Pal());
  //## end CLMSector_Pal::CreateClass%989667592.body
}

void CLMSector_Pal::set_Pal (char *_Pal)
{
  //## begin CLMSector_Pal::set_Pal%989667598.body preserve=yes
	memcpy(Pal,_Pal,768);
  //## end CLMSector_Pal::set_Pal%989667598.body
}

unsigned long CLMSector_Pal::ElemArraySize (int _iResolution)
{
  //## begin CLMSector_Pal::ElemArraySize%989667599.body preserve=yes
	return(_iResolution*_iResolution );
  //## end CLMSector_Pal::ElemArraySize%989667599.body
}

// Additional Declarations
  //## begin CLMSector_Pal%3AFD246C0316.declarations preserve=yes
  //## end CLMSector_Pal%3AFD246C0316.declarations

//## begin module%3AFD246C0316.epilog preserve=yes
//## end module%3AFD246C0316.epilog
