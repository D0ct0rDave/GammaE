



#include "GammaE_Mem.h"

// CLMSector_Gray
#include "Sector\LightMap\CLMSector_Gray.h"

CLightElem 		LMS_G_L;

unsigned char  *LMS_G_pucLight = NULL;
float		  	LMS_G_fLight[3];
float          *LMS_G_pfLight  = NULL;



// Class CLMSector_Gray 

CLMSector_Gray::CLMSector_Gray()
        {
       ulID = MAKE_RIFF_ID('L','S','G','R');
}


CLMSector_Gray::~CLMSector_Gray()
{
}



CSectElem & CLMSector_Gray::GetValue (int _X, int _Y)
{
  	LMS_G_pucLight = ((unsigned char *)pData) + (_Y*Resolution+_X);

	LMS_G_fLight[0] = *LMS_G_pucLight / 255.0f;
	LMS_G_fLight[1] = *LMS_G_pucLight / 255.0f;
	LMS_G_fLight[2] = *LMS_G_pucLight / 255.0f;

	LMS_G_L.Set(LMS_G_fLight);
	return LMS_G_L;
}

void CLMSector_Gray::SetValue (int _X, int _Y, CSectElem &_Value)
{
  	LMS_G_pfLight  = (float *)(_Value.Get());
	LMS_G_pucLight = ((unsigned char *)pData) + (_Y*Resolution+_X);

	LMS_G_pucLight[0] = (unsigned char)(*LMS_G_pfLight * 255.0f);
}

CSector * CLMSector_Gray::CreateClass ()
{
  	return (mNew CLMSector_Gray());
}

unsigned long CLMSector_Gray::ElemArraySize (int _iResolution)
{
  	return(	_iResolution*_iResolution );
}

// Additional Declarations
    
