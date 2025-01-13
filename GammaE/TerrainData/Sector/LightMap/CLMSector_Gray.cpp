//## begin module%3AFD2499003C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFD2499003C.cm

//## begin module%3AFD2499003C.cp preserve=no
//## end module%3AFD2499003C.cp

//## Module: CLMSector_Gray%3AFD2499003C; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\Sector\LightMap\CLMSector_Gray.cpp

//## begin module%3AFD2499003C.additionalIncludes preserve=no
//## end module%3AFD2499003C.additionalIncludes

//## begin module%3AFD2499003C.includes preserve=yes
//## end module%3AFD2499003C.includes

// CLMSector_Gray
#include "TerrainData\Sector\LightMap\CLMSector_Gray.h"
//## begin module%3AFD2499003C.additionalDeclarations preserve=yes

CLightElem 		LMS_G_L;

unsigned char  *LMS_G_pucLight = NULL;
float		  	LMS_G_fLight[3];
float          *LMS_G_pfLight  = NULL;

//## end module%3AFD2499003C.additionalDeclarations


// Class CLMSector_Gray 

CLMSector_Gray::CLMSector_Gray()
  //## begin CLMSector_Gray::CLMSector_Gray%.hasinit preserve=no
  //## end CLMSector_Gray::CLMSector_Gray%.hasinit
  //## begin CLMSector_Gray::CLMSector_Gray%.initialization preserve=yes
  //## end CLMSector_Gray::CLMSector_Gray%.initialization
{
  //## begin CLMSector_Gray::CLMSector_Gray%.body preserve=yes
     ulID = MAKE_RIFF_ID('L','S','G','R');
  //## end CLMSector_Gray::CLMSector_Gray%.body
}


CLMSector_Gray::~CLMSector_Gray()
{
  //## begin CLMSector_Gray::~CLMSector_Gray%.body preserve=yes
  //## end CLMSector_Gray::~CLMSector_Gray%.body
}



//## Other Operations (implementation)
CSectElem & CLMSector_Gray::GetValue (int _X, int _Y)
{
  //## begin CLMSector_Gray::GetValue%989667583.body preserve=yes
	LMS_G_pucLight = ((unsigned char *)pData) + (_Y*Resolution+_X);

	LMS_G_fLight[0] = *LMS_G_pucLight / 255.0f;
	LMS_G_fLight[1] = *LMS_G_pucLight / 255.0f;
	LMS_G_fLight[2] = *LMS_G_pucLight / 255.0f;

	LMS_G_L.Set(LMS_G_fLight);
	return LMS_G_L;
  //## end CLMSector_Gray::GetValue%989667583.body
}

void CLMSector_Gray::SetValue (int _X, int _Y, CSectElem &_Value)
{
  //## begin CLMSector_Gray::SetValue%989667584.body preserve=yes
	LMS_G_pfLight  = (float *)(_Value.Get());
	LMS_G_pucLight = ((unsigned char *)pData) + (_Y*Resolution+_X);

	LMS_G_pucLight[0] = (unsigned char)(*LMS_G_pfLight * 255.0f);
  //## end CLMSector_Gray::SetValue%989667584.body
}

CSector * CLMSector_Gray::CreateClass ()
{
  //## begin CLMSector_Gray::CreateClass%989667586.body preserve=yes
	return (new CLMSector_Gray());
  //## end CLMSector_Gray::CreateClass%989667586.body
}

unsigned long CLMSector_Gray::ElemArraySize (int _iResolution)
{
  //## begin CLMSector_Gray::ElemArraySize%989667596.body preserve=yes
	return(	_iResolution*_iResolution );
  //## end CLMSector_Gray::ElemArraySize%989667596.body
}

// Additional Declarations
  //## begin CLMSector_Gray%3AFD2499003C.declarations preserve=yes
  //## end CLMSector_Gray%3AFD2499003C.declarations

//## begin module%3AFD2499003C.epilog preserve=yes
//## end module%3AFD2499003C.epilog
