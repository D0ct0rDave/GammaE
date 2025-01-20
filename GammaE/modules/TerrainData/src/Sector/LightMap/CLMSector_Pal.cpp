



#include "GammaE_Mem.h"
#include <string.h>

// CLMSector_Pal
#include "Sector\LightMap\CLMSector_Pal.h"
unsigned char 	LMS_P_ucLight;
float           LMS_P_fLight[3];
CLightElem 		LMS_P_L;


// Class CLMSector_Pal 


CLMSector_Pal::CLMSector_Pal()
        {
  	ulID = MAKE_RIFF_ID('L','S','P','L');
}


CLMSector_Pal::~CLMSector_Pal()
{
}



CSectElem & CLMSector_Pal::GetValue (int _X, int _Y)
{
  	LMS_P_ucLight = ((unsigned char *)pData)[_Y*Resolution+_X];

	LMS_P_fLight[0] = Pal[ LMS_P_ucLight*3 + 0 ]/255.0f;
	LMS_P_fLight[1] = Pal[ LMS_P_ucLight*3 + 1 ]/255.0f;
	LMS_P_fLight[2] = Pal[ LMS_P_ucLight*3 + 2 ]/255.0f;

	LMS_P_L.Set(LMS_P_fLight);
	return LMS_P_L;
}

void CLMSector_Pal::SetValue (int _X, int _Y, CSectElem &_Value)
{
}

unsigned long CLMSector_Pal::DataSize ()
{
  	return( 768 + Resolution*Resolution );
}

CSector * CLMSector_Pal::CreateClass ()
{
  	return (mNew CLMSector_Pal());
}

void CLMSector_Pal::set_Pal (char *_Pal)
{
  	memcpy(Pal,_Pal,768);
}

unsigned long CLMSector_Pal::ElemArraySize (int _iResolution)
{
  	return(_iResolution*_iResolution );
}

// Additional Declarations
    
