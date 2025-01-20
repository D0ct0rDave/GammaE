//## begin module%3B76DE5D02B0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76DE5D02B0.cm

//## begin module%3B76DE5D02B0.cp preserve=no
//## end module%3B76DE5D02B0.cp

//## Module: CStreamSample%3B76DE5D02B0; Pseudo Package body
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CStreamSample.cpp

//## begin module%3B76DE5D02B0.additionalIncludes preserve=no
//## end module%3B76DE5D02B0.additionalIncludes

//## begin module%3B76DE5D02B0.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include <string.h>
//## end module%3B76DE5D02B0.includes

// CStreamSample
#include "SoundSystem\Sound\CStreamSample.h"
//## begin module%3B76DE5D02B0.additionalDeclarations preserve=yes
//## end module%3B76DE5D02B0.additionalDeclarations


// Class CStreamSample 








CStreamSample::CStreamSample()
  //## begin CStreamSample::CStreamSample%.hasinit preserve=no
      : pData(NULL), iChannels(0), iBits(0), iSRate(0), iSamples(0), iHandle(-1)
  //## end CStreamSample::CStreamSample%.hasinit
  //## begin CStreamSample::CStreamSample%.initialization preserve=yes
  //## end CStreamSample::CStreamSample%.initialization
{
  //## begin CStreamSample::CStreamSample%.body preserve=yes
  //## end CStreamSample::CStreamSample%.body
}


CStreamSample::~CStreamSample()
{
  //## begin CStreamSample::~CStreamSample%.body preserve=yes
  //## end CStreamSample::~CStreamSample%.body
}



//## Other Operations (implementation)
void CStreamSample::Init(char *_szFilename)
{
  //## begin CStreamSample::Init%1002050842.body preserve=yes
	iChannels =	_iChannels;
	iBits     =	_iBits;
	iSRate    =	_iSRate;
	iSamples  = (int)(_fTime*(float)iSRate)+1;	

	pData = (void *)mNew char[ (iBits>>3)*iChannels*iSamples ];
  //## end CStreamSample::Init%1002050842.body
}

void CStreamSample::Init (int _iChannels, int _iBits, int _iSRate, int _iSamples)
{
  //## begin CStreamSample::Init%1015160466.body preserve=yes
	iChannels =	_iChannels;
	iBits     =	_iBits;
	iSRate    =	_iSRate;
	iSamples  = _iSamples;

	pData = (void *)mNew char[ (iBits>>3)*iChannels*iSamples ];
  //## end CStreamSample::Init%1015160466.body
}

// Additional Declarations
  //## begin CStreamSample%3B76DE5D02B0.declarations preserve=yes
int  CStreamSample::iGetData(int _iOfs,void *_pBuffer,int _iSize)
{
	int iSampleSize = iChannels*(iBits>>3);

	if ((_iOfs + _iSize) < iSamples)
	{
		memcpy(_pBuffer,(char*)pData + _iOfs*iSampleSize,_iSize*iSampleSize);
	}
	else
	{
		int iCopy = iSamples - _iOfs;

		// copiamos lo que podemos primero
		memcpy(_pBuffer,(char*)pData + _iOfs*iSampleSize,iCopy*iSampleSize);
		return ( iCopy );
	}
}
  //## end CStreamSample%3B76DE5D02B0.declarations

//## begin module%3B76DE5D02B0.epilog preserve=yes
//## end module%3B76DE5D02B0.epilog
