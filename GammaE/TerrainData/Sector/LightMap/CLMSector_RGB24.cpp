//## begin module%3AFC0D7200D2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFC0D7200D2.cm

//## begin module%3AFC0D7200D2.cp preserve=no
//## end module%3AFC0D7200D2.cp

//## Module: CLMSector_RGB24%3AFC0D7200D2; Pseudo Package body
//## Source file: E:\Projects\GammaE\TerrainData\Sector\LightMap\CLMSector_RGB24.cpp

//## begin module%3AFC0D7200D2.additionalIncludes preserve=no
//## end module%3AFC0D7200D2.additionalIncludes

//## begin module%3AFC0D7200D2.includes preserve=yes
//## end module%3AFC0D7200D2.includes

// CLMSector_RGB24
#include "TerrainData\Sector\LightMap\CLMSector_RGB24.h"
//## begin module%3AFC0D7200D2.additionalDeclarations preserve=yes
CLightElem 		LMS_24_L;

unsigned char * LMS_24_pucLight = NULL;
float           LMS_24_fLight[3];
float		   *LMS_24_pfLight = NULL;
//## end module%3AFC0D7200D2.additionalDeclarations


// Class CLMSector_RGB24 

CLMSector_RGB24::CLMSector_RGB24()
  //## begin CLMSector_RGB24::CLMSector_RGB24%.hasinit preserve=no
  //## end CLMSector_RGB24::CLMSector_RGB24%.hasinit
  //## begin CLMSector_RGB24::CLMSector_RGB24%.initialization preserve=yes
  //## end CLMSector_RGB24::CLMSector_RGB24%.initialization
{
  //## begin CLMSector_RGB24::CLMSector_RGB24%.body preserve=yes
	ulID = MAKE_RIFF_ID('L','S','2','4');
  //## end CLMSector_RGB24::CLMSector_RGB24%.body
}


CLMSector_RGB24::~CLMSector_RGB24()
{
  //## begin CLMSector_RGB24::~CLMSector_RGB24%.body preserve=yes
  //## end CLMSector_RGB24::~CLMSector_RGB24%.body
}



//## Other Operations (implementation)
CSectElem & CLMSector_RGB24::GetValue (int _X, int _Y)
{
  //## begin CLMSector_RGB24::GetValue%989597151.body preserve=yes
	LMS_24_pucLight = &((unsigned char *)pData)[(_Y*Resolution+_X)*3];

	LMS_24_fLight[0] = LMS_24_pucLight[0]/255.0f;
	LMS_24_fLight[1] = LMS_24_pucLight[1]/255.0f;
	LMS_24_fLight[2] = LMS_24_pucLight[2]/255.0f;

	LMS_24_L.Set(LMS_24_fLight);
	return LMS_24_L;
  //## end CLMSector_RGB24::GetValue%989597151.body
}

void CLMSector_RGB24::SetValue (int _X, int _Y, CSectElem &_Value)
{
  //## begin CLMSector_RGB24::SetValue%989597152.body preserve=yes
	LMS_24_pfLight  = (float *)(_Value.Get());
	LMS_24_pucLight = &((unsigned char *)pData)[(_Y*Resolution+_X)*3];

	LMS_24_pucLight[0] = (unsigned char)(LMS_24_pfLight[0]*255.0f);
	LMS_24_pucLight[1] = (unsigned char)(LMS_24_pfLight[1]*255.0f);
	LMS_24_pucLight[2] = (unsigned char)(LMS_24_pfLight[2]*255.0f);
  //## end CLMSector_RGB24::SetValue%989597152.body
}

CSector * CLMSector_RGB24::CreateClass ()
{
  //## begin CLMSector_RGB24::CreateClass%989597154.body preserve=yes
	return( new CLMSector_RGB24() );
  //## end CLMSector_RGB24::CreateClass%989597154.body
}

unsigned long CLMSector_RGB24::ElemArraySize (int _iResolution)
{
  //## begin CLMSector_RGB24::ElemArraySize%989667595.body preserve=yes
	return( _iResolution*_iResolution*3 );
  //## end CLMSector_RGB24::ElemArraySize%989667595.body
}

void CLMSector_RGB24::GetLODData (int _iLOD, void *_pData)
{
  //## begin CLMSector_RGB24::GetLODData%995233498.body preserve=yes
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
  //## end CLMSector_RGB24::GetLODData%995233498.body
}

// Additional Declarations
  //## begin CLMSector_RGB24%3AFC0D7200D2.declarations preserve=yes
  //## end CLMSector_RGB24%3AFC0D7200D2.declarations

//## begin module%3AFC0D7200D2.epilog preserve=yes
//## end module%3AFC0D7200D2.epilog
