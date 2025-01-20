



#include "GammaE_Mem.h"

// CLMSector_RGB24
#include "Sector\LightMap\CLMSector_RGB24.h"
CLightElem 		LMS_24_L;

unsigned char * LMS_24_pucLight = NULL;
float           LMS_24_fLight[3];
float		   *LMS_24_pfLight = NULL;


// Class CLMSector_RGB24 

CLMSector_RGB24::CLMSector_RGB24()
        {
  	ulID = MAKE_RIFF_ID('L','S','2','4');
}


CLMSector_RGB24::~CLMSector_RGB24()
{
}



CSectElem & CLMSector_RGB24::GetValue (int _X, int _Y)
{
  	LMS_24_pucLight = &((unsigned char *)pData)[(_Y*Resolution+_X)*3];

	LMS_24_fLight[0] = LMS_24_pucLight[0]/255.0f;
	LMS_24_fLight[1] = LMS_24_pucLight[1]/255.0f;
	LMS_24_fLight[2] = LMS_24_pucLight[2]/255.0f;

	LMS_24_L.Set(LMS_24_fLight);
	return LMS_24_L;
}

void CLMSector_RGB24::SetValue (int _X, int _Y, CSectElem &_Value)
{
  	LMS_24_pfLight  = (float *)(_Value.Get());
	LMS_24_pucLight = &((unsigned char *)pData)[(_Y*Resolution+_X)*3];

	LMS_24_pucLight[0] = (unsigned char)(LMS_24_pfLight[0]*255.0f);
	LMS_24_pucLight[1] = (unsigned char)(LMS_24_pfLight[1]*255.0f);
	LMS_24_pucLight[2] = (unsigned char)(LMS_24_pfLight[2]*255.0f);
}

CSector * CLMSector_RGB24::CreateClass ()
{
  	return( mNew CLMSector_RGB24() );
}

unsigned long CLMSector_RGB24::ElemArraySize (int _iResolution)
{
  	return( _iResolution*_iResolution*3 );
}

void CLMSector_RGB24::GetLODData (int _iLOD, void *_pData)
{
  /*
  #ifndef _1_OVER_255
  #define _1_OVER_255	0.00392156862745098039215686274509804
  #endif

  	int iNewResolution = ((Resolution & 0xfffffffe) >> _iLOD);
	if (b21) iNewResolution++;

	int			   iStep = 1 << _iLOD;
	int			   cI,cJ,cX,cY;
	float		  *pDst;
	unsigned char *pSrc;
	
	pDst = (float *)_pData;
	pSrc = (unsigned char *) pData;
	cY = 0;
	for (cJ=0;cJ<iNewResolution;cJ++)
	{
		cX = 0;
		for (cI=0;cI<iNewResolution;cI++)
		{		
			pDst[0] = (float)pSrc[(cY*Resolution+cX)*3 + 0]*_1_OVER_255;
			pDst[1] = (float)pSrc[(cY*Resolution+cX)*3 + 1]*_1_OVER_255;
			pDst[2] = (float)pSrc[(cY*Resolution+cX)*3 + 2]*_1_OVER_255;
					
			pDst += 3;
			
			cX   += iStep;
		}
		cY += iStep;
	}
*/

  #ifndef _1_OVER_255
  #define _1_OVER_255	0.00392156862745098039215686274509804
  #endif
	
	float		  *pDst = (float *)_pData;
	unsigned char *pSrc = (unsigned char *) pData;

	if (_iLOD == 0)
	{	
		int iBlockSize = Resolution*Resolution*3;
		register int cPos;

		for (cPos=0;cPos<iBlockSize;cPos++)
		{
			*pDst++ = (float)(*pSrc) * _1_OVER_255;
			pSrc++;
		}
	}
	else
	{
	  	int iNewResolution = ((Resolution & 0xfffffffe) >> _iLOD);
		if (b21) iNewResolution++;

		int			   iStep   =  ((1 << _iLOD)*3) - 3;
		int			   iStride = (((1 << _iLOD)-1)*Resolution)*3 - iStep;
		register int   cI,cJ;
	
		for (cJ=0;cJ<iNewResolution;cJ++)
		{
			for (cI=0;cI<iNewResolution;cI++)
			{		
				*pDst++ = ((float)(*pSrc) *_1_OVER_255);	pSrc++;
				*pDst++ = ((float)(*pSrc) *_1_OVER_255);	pSrc++;
				*pDst++ = ((float)(*pSrc) *_1_OVER_255);	pSrc++;
					
				pSrc += iStep;
			}
		
			pSrc += iStride;
		}
	}
}

// Additional Declarations
    
