//## begin module%3C7F7DF20222.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7F7DF20222.cm

//## begin module%3C7F7DF20222.cp preserve=no
//## end module%3C7F7DF20222.cp

//## Module: CSoundMixer%3C7F7DF20222; Pseudo Package body
//## Source file: i:\Projects\GammaE\SoundSystem\SoundRender\SoundMixer\CSoundMixer.cpp

//## begin module%3C7F7DF20222.additionalIncludes preserve=no
//## end module%3C7F7DF20222.additionalIncludes

//## begin module%3C7F7DF20222.includes preserve=yes
#include <stdlib.h>
//## end module%3C7F7DF20222.includes

// CSoundMixer
#include "SoundSystem\SoundRender\SoundMixer\CSoundMixer.h"
//## begin module%3C7F7DF20222.additionalDeclarations preserve=yes
#include "memory/GammaE_mem.h"
#include <string.h>
//## end module%3C7F7DF20222.additionalDeclarations


// Class CSoundMixer 

//## begin CSoundMixer::pBuffer%3C7F7E0B0047.attr preserve=no  private: static void * {UA} NULL
void *CSoundMixer::pBuffer = NULL;
//## end CSoundMixer::pBuffer%3C7F7E0B0047.attr

//## begin CSoundMixer::pi32bBuffer%3D0CA81B005D.attr preserve=no  private: static int * {UA} NULL
int *CSoundMixer::pi32bBuffer = NULL;
//## end CSoundMixer::pi32bBuffer%3D0CA81B005D.attr

//## begin CSoundMixer::uiBuffSize%3C7F7E1B0307.attr preserve=no  private: static unsigned int {UA} 0
unsigned int CSoundMixer::uiBuffSize = 0;
//## end CSoundMixer::uiBuffSize%3C7F7E1B0307.attr

//## begin CSoundMixer::uiBuffSamples%3C82223001C4.attr preserve=no  private: static unsigned int {UA} 0
unsigned int CSoundMixer::uiBuffSamples = 0;
//## end CSoundMixer::uiBuffSamples%3C82223001C4.attr

//## begin CSoundMixer::iSRate%3C7F99A10179.attr preserve=no  private: static int {UA} 0
int CSoundMixer::iSRate = 0;
//## end CSoundMixer::iSRate%3C7F99A10179.attr

//## begin CSoundMixer::iBits%3C7F9A530160.attr preserve=no  private: static int {UA} 0
int CSoundMixer::iBits = 0;
//## end CSoundMixer::iBits%3C7F9A530160.attr

//## begin CSoundMixer::bPostProcess%3D0CA872027F.attr preserve=no  private: static bool {UA} false
bool CSoundMixer::bPostProcess = false;
//## end CSoundMixer::bPostProcess%3D0CA872027F.attr

//## begin CSoundMixer::poRec%3C7F8E4001FD.role preserve=no  public: static CSoundReceiver { -> RHAN}
CSoundReceiver *CSoundMixer::poRec;
//## end CSoundMixer::poRec%3C7F8E4001FD.role

CSoundMixer::CSoundMixer()
  //## begin CSoundMixer::CSoundMixer%.hasinit preserve=no
  //## end CSoundMixer::CSoundMixer%.hasinit
  //## begin CSoundMixer::CSoundMixer%.initialization preserve=yes
  //## end CSoundMixer::CSoundMixer%.initialization
{
  //## begin CSoundMixer::CSoundMixer%.body preserve=yes
  //## end CSoundMixer::CSoundMixer%.body
}


CSoundMixer::~CSoundMixer()
{
  //## begin CSoundMixer::~CSoundMixer%.body preserve=yes
	if (pBuffer) mDel []pBuffer;
	if (pi32bBuffer) mDel []pi32bBuffer;
  //## end CSoundMixer::~CSoundMixer%.body
}



//## Other Operations (implementation)
void CSoundMixer::Clear ()
{
  //## begin CSoundMixer::Clear%1014979369.body preserve=yes
	memset(pBuffer,0,uiBuffSize);
	memset(pi32bBuffer,0,uiBuffSamples*2*4);
  //## end CSoundMixer::Clear%1014979369.body
}

void CSoundMixer::SetupBuffer (float _fSeconds, unsigned int _iSRate, int _iBits)
{
  //## begin CSoundMixer::SetupBuffer%1014979371.body preserve=yes
	iSRate       = _iSRate;
	iBits        = _iBits;
	uiBuffSamples= (unsigned int)(_fSeconds*iSRate);
	uiBuffSize   = uiBuffSamples*(iBits>>3)*2;
	pBuffer      = mAlloc(uiBuffSize);
	pi32bBuffer  = (int*)mAlloc(uiBuffSamples*2*4);

	Clear();	// Erase buffer contents previously to it's use

	assert (pBuffer && "Unable to allocate sound buffer");
  //## end CSoundMixer::SetupBuffer%1014979371.body
}

void CSoundMixer::Mix (CSoundMixPars& _roSMP, unsigned int _uiSamples)
{
  //## begin CSoundMixer::Mix%1014979370.body preserve=yes
	bPostProcess = true;

	// Current buffer position
	if (_uiSamples>uiBuffSamples) _uiSamples = uiBuffSamples;

	if(iBits==16)
	{
		if (_roSMP.poSound->poSLayer[_roSMP.iCLayer].poSample->iChannels==2)
			Mix16S(_roSMP,_uiSamples,0);
		else
			Mix16M(_roSMP,_uiSamples,0);
	}
else if (iBits == 8)
	{
		if (_roSMP.poSound->poSLayer[_roSMP.iCLayer].poSample->iChannels==2)
			Mix8S(_roSMP,_uiSamples,0);
		else
			Mix8M(_roSMP,_uiSamples,0);
	}
  //## end CSoundMixer::Mix%1014979370.body
}

void CSoundMixer::Mix16M (CSoundMixPars& _roSMP, unsigned int uiSamples, unsigned int _uiCurDSmpPos)
{
  //## begin CSoundMixer::Mix16M%1014979372.body preserve=yes
	if (_roSMP.bEnd) return;

	unsigned int	uiDSmp;
	unsigned int	uiSSmp;
	unsigned int	uiMax;
	int				iCount;
	int				iS;
	int				iL;
	int				iR;
	
	// Get volume multipliers
	int				iLV = _roSMP.fLVol*32768.0f;
	int				iRV = _roSMP.fRVol*32768.0f;

	CSoundLayer		*poSLayer = &_roSMP.poSound->poSLayer[_roSMP.iCLayer];
	CSample			*poSamp   = poSLayer->poSample;
	short			*psSrc   = (short*)poSamp->pData;	
	int				*piDst   = (int  *)pi32bBuffer + _uiCurDSmpPos*2;

	uiMax  = poSamp->iSamples;
	uiSSmp = _roSMP.iSPos;
	uiDSmp = 0;

	for (uiDSmp=0;uiDSmp<uiSamples;uiDSmp++)
	{
		// Get sample
		iS = psSrc[uiSSmp];
		
		// Process sample
		iL = iS * iLV;	iL >>= 15;	// Sample*Vol/32768
		iR = iS * iRV;	iR >>= 15;
		
		// Store sample
		piDst[0] += iL;
		piDst[1] += iR;
		piDst    += 2;

		// Update pointers
		uiSSmp++;
		if (uiSSmp==uiMax)
		{
			// Look if sample is looping
			if ((poSLayer->bLoop) && (! _roSMP.bLUnlock))
				// Start at the beginning of this sample
				uiSSmp = 0;
			else
			{
				// Auto update this
				_roSMP.bLUnlock = false;

				// Next layer								
				if (_roSMP.iCLayer+1<_roSMP.poSound->iNumLayers)
				{						
					// Update current sound layer
					_roSMP.iCLayer++;			

					// Pointers			
					poSLayer++;
					poSamp = poSLayer->poSample;
					
					// What if the next sample is stereo???
					if (poSamp->iChannels == 2)
					{
						Mix16S(_roSMP,uiSamples-(uiDSmp-1),uiDSmp);
						return;
					}

					psSrc = (short*)poSamp->pData;

					uiSSmp = 0;
					uiMax  = poSamp->iSamples;
				}
				else
				{
					// No more process on this sound
					_roSMP.bEnd = true;
					return;
				}
			}
		}
	}
	
	// Update sample position
	_roSMP.iSPos = uiSSmp;
  //## end CSoundMixer::Mix16M%1014979372.body
}

void CSoundMixer::Mix16S (CSoundMixPars& _roSMP, unsigned int uiSamples, unsigned int _uiCurDSmpPos)
{
  //## begin CSoundMixer::Mix16S%1014979373.body preserve=yes
  	if (_roSMP.bEnd) return;

	unsigned int	uiDSmp;
	unsigned int	uiSSmp;
	unsigned int	uiMax;
	int				iCount;
	int				iS;
	int				iL;
	int				iR;
	
	// Get volume multipliers
	int	iLV = _roSMP.fLVol*32768.0f;
	int	iRV = _roSMP.fRVol*32768.0f;

	CSoundLayer		*poSLayer = &_roSMP.poSound->poSLayer[_roSMP.iCLayer];
	CSample			*poSamp   = poSLayer->poSample;
	short  *psSrc   = (short*)poSamp->pData;
	short  *psDst   = (short*)pBuffer + _uiCurDSmpPos*2;

	uiMax  = poSamp->iSamples;
	uiSSmp = _roSMP.iSPos;
	uiDSmp = 0;

	for (uiDSmp=_uiCurDSmpPos;uiDSmp<uiSamples;uiDSmp++)			    
	{	
		// Process sample
		iL = psSrc[uiSSmp*2+0] * iLV;	iL >>= 15;
		iR = psSrc[uiSSmp*2+1] * iRV;	iR >>= 15;

		// Store sample
		psDst[0] = iL;
		psDst[1] = iR;
		psDst   +=2;

		// Update pointers
		uiSSmp++;
		if (uiSSmp==uiMax)
		{
			// Look if sample is looping
			if ((poSLayer->bLoop) && (! _roSMP.bLUnlock))
				// Start at the beginning of this sample
				uiSSmp = 0;
			else
			{
				// Auto update this
				_roSMP.bLUnlock = false;

				// Next layer								
				if (_roSMP.iCLayer+1<_roSMP.poSound->iNumLayers)
				{						
					// Update current sound layer
					_roSMP.iCLayer++;			

					// Pointers			
					poSLayer++;
					poSamp = poSLayer->poSample;
					
					// What if the next sample is mono???
					if (poSamp->iChannels == 1)
					{
						Mix16M(_roSMP,uiSamples-(uiDSmp-1),uiDSmp);
						return;
					}

					psSrc = (short*)poSamp->pData;

					uiSSmp = 0;
					uiMax  = poSamp->iSamples;
				}
				else
				{
					// No more process on this sound
					_roSMP.bEnd = true;
					return;
				}
			}
		}
	}
	
	// Update sample position
	_roSMP.iSPos = uiSSmp;
  //## end CSoundMixer::Mix16S%1014979373.body
}

void CSoundMixer::Mix8M (CSoundMixPars& _roSMP, unsigned int uiSamples, unsigned int _uiCurDSmpPos)
{
  //## begin CSoundMixer::Mix8M%1014979374.body preserve=yes
  //## end CSoundMixer::Mix8M%1014979374.body
}

void CSoundMixer::Mix8S (CSoundMixPars& _roSMP, unsigned int uiSamples, unsigned int _uiCurDSmpPos)
{
  //## begin CSoundMixer::Mix8S%1014979375.body preserve=yes
  //## end CSoundMixer::Mix8S%1014979375.body
}

void* CSoundMixer::pGetBuffer ()
{
  //## begin CSoundMixer::pGetBuffer%1015160464.body preserve=yes
	if (bPostProcess)
	{
		// Clamp all the buffer values
		int		iSmp;
		int		iMaxSmp = uiBuffSamples<<1;
		int		*piSSmp = pi32bBuffer;
		short	*psDSmp = (short*)pBuffer;
		
		for (iSmp=0;iSmp<iMaxSmp;iSmp++)
		{			
			if (*piSSmp < -32768)	*psDSmp = -32768;
	   else if (*piSSmp >  32767)	*psDSmp =  32767;
	   else	
				*psDSmp = *piSSmp;
			
			*psDSmp++;
			*piSSmp++;
		}
		
		// Clear the auxiliary buffer
		memset(pi32bBuffer,0,uiBuffSamples*2*4);

		// We do not need signal post processing
		bPostProcess = false;
	}

	return(pBuffer);
  //## end CSoundMixer::pGetBuffer%1015160464.body
}

unsigned int CSoundMixer::uiGetBufferSize ()
{
  //## begin CSoundMixer::uiGetBufferSize%1015168104.body preserve=yes
	return(uiBuffSize);
  //## end CSoundMixer::uiGetBufferSize%1015168104.body
}

// Additional Declarations
  //## begin CSoundMixer%3C7F7DF20222.declarations preserve=yes
  //## end CSoundMixer%3C7F7DF20222.declarations

//## begin module%3C7F7DF20222.epilog preserve=yes
//## end module%3C7F7DF20222.epilog
