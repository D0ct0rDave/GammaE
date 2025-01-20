//## begin module%3B76DF1100F6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76DF1100F6.cm

//## begin module%3B76DF1100F6.cp preserve=no
//## end module%3B76DF1100F6.cp

//## Module: CSampleWH%3B76DF1100F6; Pseudo Package body
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CSampleWH.cpp

//## begin module%3B76DF1100F6.additionalIncludes preserve=no
//## end module%3B76DF1100F6.additionalIncludes

//## begin module%3B76DF1100F6.includes preserve=yes
#include <assert.h>
#include <string.h>
#include "memory/GammaE_mem.h"
#include "SampleUtils/SampleUtils.h"

//## end module%3B76DF1100F6.includes

// CSampleWH
#include "SoundSystem\Sound\CSampleWH.h"
//## begin module%3B76DF1100F6.additionalDeclarations preserve=yes
//## end module%3B76DF1100F6.additionalDeclarations


// Class CSampleWH 

//## begin CSampleWH::iNumSamples%3BB645B60236.attr preserve=no  private: static int {UA} 0
int CSampleWH::iNumSamples = 0;
//## end CSampleWH::iNumSamples%3BB645B60236.attr

//## begin CSampleWH::iMaxSamples%3BB645BB00DE.attr preserve=no  private: static int {UA} 0
int CSampleWH::iMaxSamples = 0;
//## end CSampleWH::iMaxSamples%3BB645BB00DE.attr

//## begin CSampleWH::poSample%3BB654A503D7.attr preserve=no  private: static CSample* * {UA} NULL
CSample* *CSampleWH::poSample = NULL;
//## end CSampleWH::poSample%3BB654A503D7.attr

//## begin CSampleWH::iForcedSRate%3C7F7F07032E.attr preserve=no  private: static int {UA} 22050
int CSampleWH::iForcedSRate = 22050;
//## end CSampleWH::iForcedSRate%3C7F7F07032E.attr

//## begin CSampleWH::iForcedBits%3C7F7F100038.attr preserve=no  private: static int {UA} 16
int CSampleWH::iForcedBits = 16;
//## end CSampleWH::iForcedBits%3C7F7F100038.attr

CSampleWH::CSampleWH()
  //## begin CSampleWH::CSampleWH%.hasinit preserve=no
  //## end CSampleWH::CSampleWH%.hasinit
  //## begin CSampleWH::CSampleWH%.initialization preserve=yes
  //## end CSampleWH::CSampleWH%.initialization
{
  //## begin CSampleWH::CSampleWH%.body preserve=yes
  //## end CSampleWH::CSampleWH%.body
}


CSampleWH::~CSampleWH()
{
  //## begin CSampleWH::~CSampleWH%.body preserve=yes
  //## end CSampleWH::~CSampleWH%.body
}



//## Other Operations (implementation)
void CSampleWH::Init (int _iMaxSamples)
{
  //## begin CSampleWH::Init%1001802581.body preserve=yes
    iMaxSamples = _iMaxSamples;
	iNumSamples = 0;
	poSample    = mNew CSample *[iMaxSamples];
	memset(poSample,0,iMaxSamples*sizeof(CSample*));
  //## end CSampleWH::Init%1001802581.body
}

void CSampleWH::Invalidate ()
{
  //## begin CSampleWH::Invalidate%1001802582.body preserve=yes
	if ( ! poSample) return;

	for (int cSample=0;cSample<iNumSamples;cSample++)
		mDel ( poSample[cSample] );

	iNumSamples = 0;
  //## end CSampleWH::Invalidate%1001802582.body
}

int CSampleWH::iAddSample (CSample *_poSample)
{
  //## begin CSampleWH::iAddSample%1001802583.body preserve=yes
	assert( (poSample) && ("NULL Sample Warehouse"));
	assert( (iNumSamples<iMaxSamples) && ("Sample Warehouse full"));	

	poSample[iNumSamples++]= _poSample;
	return ( iNumSamples-1 );
  //## end CSampleWH::iAddSample%1001802583.body
}

CSample * CSampleWH::poGetSample (int _iIdx)
{
  //## begin CSampleWH::poGetSample%1001802584.body preserve=yes
	assert( (poSample) && ("NULL Sample Warehouse") );
	assert( (_iIdx<iNumSamples) && ("Sample idx out of Warehousebounds"));	

	return( poSample[_iIdx] );
  //## end CSampleWH::poGetSample%1001802584.body
}

int CSampleWH::iLoadSample (char *_szFilename)
{
  //## begin CSampleWH::iLoadSample%1001881740.body preserve=yes
	CSample *poSam = SampleUtils_LoadSample(_szFilename);	
	if (! poSam) return (-1);

	// Reformat sample according to sound system specification
	SampleUtils_ConvertSample(poSam,poSam->iChannels,iForcedBits,iForcedSRate);

	return ( iAddSample(poSam) );
  //## end CSampleWH::iLoadSample%1001881740.body
}

void CSampleWH::SetForcedParams (int _iForcedSRate, int _iForcedBits)
{
  //## begin CSampleWH::SetForcedParams%1014979368.body preserve=yes
	iForcedSRate= _iForcedSRate;
	iForcedBits = _iForcedBits;
  //## end CSampleWH::SetForcedParams%1014979368.body
}

// Additional Declarations
  //## begin CSampleWH%3B76DF1100F6.declarations preserve=yes
//---------------------------------------------------------------------------
// epilog: singleton initializer through static instantiation
//---------------------------------------------------------------------------
static CSampleWH oInstance;
  //## end CSampleWH%3B76DF1100F6.declarations
//## begin module%3B76DF1100F6.epilog preserve=yes
//## end module%3B76DF1100F6.epilog
