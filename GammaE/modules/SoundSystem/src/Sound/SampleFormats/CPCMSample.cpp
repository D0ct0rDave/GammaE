
//-----------------------------------------------------------------------------












#include "GammaE_Mem.h"
#include "GammaE_Misc.h"
#include <string.h>

#include <sndfile.h>

#ifdef _OPENAL_
#include <al.h>
#endif


//-----------------------------------------------------------------------------
#include "Sound\SampleFormats\CPCMSample.h"




//-----------------------------------------------------------------------------








CPCMSample::CPCMSample()
  
  
  
  
{
  
  pData = NULL;
  
}


CPCMSample::~CPCMSample()
{
  
  
}




void CPCMSample::Init (int _iChannels, int _iBits, int _iSRate, float _fTime)
{
  
	iChannels =	_iChannels;
	iBits     =	_iBits;
	iSRate    =	_iSRate;
	iSamples  = (int)(_fTime*(float)iSRate)+1;	

	pData = (void *)mNew char[ (iBits>>3)*iChannels*iSamples ];
  
}

void CPCMSample::Init (int _iChannels, int _iBits, int _iSRate, int _iSamples)
{
  
	iChannels =	_iChannels;
	iBits     =	_iBits;
	iSRate    =	_iSRate;
	iSamples  = _iSamples;

	pData = (void *)mNew char[ (iBits>>3)*iChannels*iSamples ];
  
}

//-----------------------------------------------------------------------------
  
void CPCMSample::Init(char *_szFilename)
{
	SNDFILE*	Sfd;
	SF_INFO		SInfo;
	int			iSSize;
	CSample		*pSample;

	Sfd = sf_open	(_szFilename,SFM_READ, &SInfo) ;	
	if (! Sfd)
	{
		CGSystemLC::I()->Error("Unable to open sample file %s",_szFilename);
		return;
	}
	// 17-Feb-2012: DMC
	// iSSize = SInfo.channels*(SInfo.pcmbitwidth>>3)*SInfo.frames;
	// Init(SInfo.channels,SInfo.pcmbitwidth,SInfo.samplerate,(int)SInfo.frames);	
	iSSize = SInfo.channels*(16>>3)*SInfo.frames;
	Init(SInfo.channels,16,SInfo.samplerate,(int)SInfo.frames);	

	if ( (int)sf_read_raw(Sfd,pData,iSSize) != iSSize)
	{
		CGSystemLC::I()->Error("Unable to read from sample file %s",_szFilename);
		return;
	}
	
	iHandle = -1;
	sf_close(Sfd) ;
	
	/*
	#ifdef _OPENAL_

		ALenum     format;
		ALsizei    size;
		ALint	   error;

		int iFlags = (pSample->iBits << 8) | pSample->iChannels;
		switch(iFlags)
		{
			case 0x0801:
			{
				format = AL_FORMAT_MONO8;
				size = pSample->iSamples;
			}
			break; 
			case 0x0802:
			{
				format = AL_FORMAT_STEREO8;
				size = pSample->iSamples<<1;
			}
			break;
			case 0x1001:
			{
				format = AL_FORMAT_MONO16;
				size = pSample->iSamples<<1;
			}
			break;
			case 0x1002:
			{
				format = AL_FORMAT_STEREO16;
				size = pSample->iSamples<<2;
			}
			break; 
		}

		// Create "internal" buffer
		alGenBuffers(1, (ALuint*)&pSample->iHandle);
		if ((error = alGetError()) != AL_NO_ERROR)
		{
			CONPrintf("alGenBuffers : %d", error);
			return NULL;
		}

		// Setup "internal" data
		alBufferData((ALuint)pSample->iHandle,
					format,
					(ALvoid *)pSample->pData,
					size,
					(ALsizei)pSample->iSRate);

		if ((error = alGetError()) != AL_NO_ERROR)
		{
			CONPrintf("alBufferData : %d", error);
			alDeleteBuffers(1, (ALuint*)&pSample->iHandle);
			return NULL;
		}

		// Deallocate "external" data
		mFree( pSample->pData );
		pSample->pData = NULL;

	#endif
	*/	
}
 
int  CPCMSample::iGetData(int _iOfs,void *_pBuffer,int _iSize)
{
	int iSampleSize = iChannels*(iBits>>3);
	int iCopy = _iSize;

	if ((_iOfs + _iSize) > iSamples)
		// copiamos lo que podemos primero
		iCopy = iSamples - _iOfs;

	memcpy(_pBuffer,(char*)pData + _iOfs*iSampleSize,iCopy*iSampleSize);
	return ( iCopy );
}

void CPCMSample::Finish()
{
	if (pData)
	{
		mFree(pData);
		pData  = NULL;
	};	
}




