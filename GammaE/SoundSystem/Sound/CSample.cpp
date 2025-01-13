//## begin module%3B76DE5D02B0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76DE5D02B0.cm

//## begin module%3B76DE5D02B0.cp preserve=no
//## end module%3B76DE5D02B0.cp

//## Module: CSample%3B76DE5D02B0; Pseudo Package body
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CSample.cpp

//## begin module%3B76DE5D02B0.additionalIncludes preserve=no
//## end module%3B76DE5D02B0.additionalIncludes

//## begin module%3B76DE5D02B0.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include <stdlib.h>
//## end module%3B76DE5D02B0.includes

// CSample
#include "SoundSystem\Sound\CSample.h"
//## begin module%3B76DE5D02B0.additionalDeclarations preserve=yes
//## end module%3B76DE5D02B0.additionalDeclarations


// Class CSample 








CSample::CSample()
  //## begin CSample::CSample%.hasinit preserve=no
      : pData(NULL), iChannels(0), iBits(0), iSRate(0), iSamples(0), iHandle(-1)
  //## end CSample::CSample%.hasinit
  //## begin CSample::CSample%.initialization preserve=yes
  //## end CSample::CSample%.initialization
{
  //## begin CSample::CSample%.body preserve=yes
  //## end CSample::CSample%.body
}


CSample::~CSample()
{
  //## begin CSample::~CSample%.body preserve=yes
	if (pData) mDel[]pData;
  //## end CSample::~CSample%.body
}



//## Other Operations (implementation)
void CSample::Init (int _iChannels, int _iBits, int _iSRate, float _fTime)
{
  //## begin CSample::Init%1002050842.body preserve=yes
	iChannels =	_iChannels;
	iBits     =	_iBits;
	iSRate    =	_iSRate;
	iSamples  = (int)(_fTime*(float)iSRate)+1;	

	pData = (void *)mNew char[ (iBits>>3)*iChannels*iSamples ];
  //## end CSample::Init%1002050842.body
}

void CSample::Init (int _iChannels, int _iBits, int _iSRate, int _iSamples)
{
  //## begin CSample::Init%1015160466.body preserve=yes
	iChannels =	_iChannels;
	iBits     =	_iBits;
	iSRate    =	_iSRate;
	iSamples  = _iSamples;

	pData = (void *)mNew char[ (iBits>>3)*iChannels*iSamples ];
  //## end CSample::Init%1015160466.body
}

// Additional Declarations
  //## begin CSample%3B76DE5D02B0.declarations preserve=yes
  //## end CSample%3B76DE5D02B0.declarations

//## begin module%3B76DE5D02B0.epilog preserve=yes
//## end module%3B76DE5D02B0.epilog
