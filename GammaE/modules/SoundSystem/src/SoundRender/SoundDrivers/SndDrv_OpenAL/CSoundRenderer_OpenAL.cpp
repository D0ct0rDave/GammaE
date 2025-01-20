//-----------------------------------------------------------------------------

#include <al/al.h>
#include <al/alc.h>

//-----------------------------------------------------------------------------
#include "SoundRender\SoundDrivers\SndDrv_OpenAL\CSoundRenderer_OpenAL.h"
#include "SoundRender\SoundDrivers\SndDrv_OpenAL\CSoundEmiter_OpenAL.h"

//-----------------------------------------------------------------------------

CSoundRenderer_OpenAL::CSoundRenderer_OpenAL()
{
}

CSoundRenderer_OpenAL::~CSoundRenderer_OpenAL()
{
  
/*
	alDeleteSources(NUM_SOURCES, source);
	alDeleteBuffers(NUM_BUFFERS, buffers);
*/
  
}




int CSoundRenderer_OpenAL::Init (void *_HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters)
{
  

	// Init openAL
	// alutInit(0, NULL);

	ALCcontext *Context;
	ALCdevice *Device;
	Device = alcOpenDevice((ALchar*)"DirectSound");
	Context=alcCreateContext(Device, NULL);
	alcMakeContextCurrent(Context);

	// Clear Error Code (so we can catch any new errors)
	alGetError();

	// Init the emiter array	
	if (_iMaxEmiters > 32) _iMaxEmiters = 32;
	iMaxEmiters = _iMaxEmiters;
	oEmiters.Init(_iMaxEmiters);

	// Create sources
	for (int i=0;i<iMaxEmiters;i++)
	{
		CSoundEmiter_OpenAL oEm;
		alGenSources(1,(ALuint*)&oEm.uiSourceHandler);

		ALuint error;
		if ((error = alGetError()) != AL_NO_ERROR)
		{
			CGSystemLC::I()->Error("alGenSources : %d", error);
			return(0);
		}

		oEmiters.iAdd(oEm);
	}

	// Setup initial listener props
	ALfloat fZero[3] = {0,0,0};
	ALfloat fOr[6]  = {0,0,1,0,1,0};
	alListenerfv(AL_POSITION,fZero);
	alListenerfv(AL_VELOCITY,fZero);
	alListenerfv(AL_ORIENTATION,fOr);

	return(0);
  
}

void CSoundRenderer_OpenAL::Render (float _fDelta)
{
  
  
	if (_fDelta == 0.0f) return;

	// Process all emiters:
	// Compute distance to receiver
	// Compute angle of incidence
	// Process emiter parameters, volume, falloff, etc.
	// Add to a local emiter list,
	// Order by average volume between left and right channel
	// Send to mixers those entities whose priorities are higher
	// or send all entities in the best case
	unsigned int uiProcEmit = 0;
	for (int i=0;i<oEmiters.uiNumElems();i++)
	{
		if ( oEmiters[i].bPlaying )
		{
			ALint iState;
			alGetSourceiv(oEmiters[i].uiSourceHandler,AL_SOURCE_STATE, &iState);
			
			if (iState == AL_PLAYING)
			{
				// Update emiter parameters
				alSourcefv (oEmiters[i].uiSourceHandler, AL_POSITION,  (ALfloat*)&oEmiters[i].Pos);
				alSourcefv (oEmiters[i].uiSourceHandler, AL_VELOCITY,  (ALfloat*)&oEmiters[i].Speed);
				alSourcefv (oEmiters[i].uiSourceHandler, AL_DIRECTION, (ALfloat*)&oEmiters[i].Dir);
			}
			else
			{
				oEmiters[i].bPlaying = false;
			}
		}
	}	

	// Update receiver parameters			
	CSoundReceiver* poReceiver = poGetReceiver();

	alListenerfv(AL_POSITION,(ALfloat*)&poReceiver->Pos);
	alListenerfv(AL_VELOCITY,(ALfloat*)&poReceiver->Speed);

	ALfloat fOr[6];
	fOr[0] = poReceiver->Dir.x;
	fOr[1] = poReceiver->Dir.y;
	fOr[2] = poReceiver->Dir.z;
	fOr[3] = poReceiver->Up.x;
	fOr[4] = poReceiver->Up.y;
	fOr[5] = poReceiver->Up.z;

	alListenerfv(AL_ORIENTATION,fOr);
  
}

//-----------------------------------------------------------------------------

CSoundEmiter * CSoundRenderer_OpenAL::poAddOmniEmiter (CSound* _poSound, float _fVol)
{
	CSoundEmiter_OpenAL* poEmiter = (CSoundEmiter_OpenAL*)CSoundRenderer::poAddOmniEmiter(_poSound,_fVol);
	AddEmiterCommon(poEmiter,_poSound,_fVol);

	return(poEmiter);
}

void CSoundRenderer_OpenAL::AddEmiterCommon(CSoundEmiter_OpenAL*_poEmiter,CSound* _poSound, float _fVol)
{
	// 
	if (_poSound->poSLayer[0].poSample->iHandle == -1)
		UploadSound(_poSound);

	// Stop posible
	alSourceStop(_poEmiter->uiSourceHandler);
	alSourceRewind(_poEmiter->uiSourceHandler);	

	// Link the buffer to the source
	alSourcei(_poEmiter->uiSourceHandler, AL_BUFFER, _poSound->poSLayer[0].poSample->iHandle);	

	// tell the sound to loop continuously
	alSourcei(_poEmiter->uiSourceHandler,AL_LOOPING,_poSound->poSLayer[0].bLoop?AL_TRUE:AL_FALSE);

	// Volume
	alSourcei(_poEmiter->uiSourceHandler, AL_GAIN, _fVol);	

	// Set properties	
	alSourcefv (_poEmiter->uiSourceHandler, AL_POSITION,  (ALfloat*)&_poEmiter->Pos);
	alSourcefv (_poEmiter->uiSourceHandler, AL_VELOCITY,  (ALfloat*)&_poEmiter->Speed);
	alSourcefv (_poEmiter->uiSourceHandler, AL_DIRECTION, (ALfloat*)&_poEmiter->Dir);

	// Play the sample
	alSourcePlay(_poEmiter->uiSourceHandler);
	
	alGetError();

	// Set the emiter as currently playing
	_poEmiter->bPlaying = true;
}

void CSoundRenderer_OpenAL::UploadSound(CSound* _poSound)
{
	// if the samples of the actual sound have not been created, then create it
	for (int i=0;i<_poSound->iNumLayers;i++)
	{
		CSample*poSample = _poSound->poSLayer[i].poSample;
		ALuint error;		

		if (poSample->iHandle == -1)
		{
			void *pSampleData = poSample->pGetInternalData();
			if( ! pSampleData ) return;
			
			alGenBuffers(1,(ALuint*)&poSample->iHandle);
			if ((error = alGetError()) != AL_NO_ERROR)
			{
				CGSystemLC::I()->Error("alGenBuffers : %d", error);
				return;
			}
			
			ALenum format;
			int iFlags = (poSample->iBits << 8) | poSample->iChannels;
			switch(iFlags)
			{
				case 0x0801: format = AL_FORMAT_MONO8; break; 
				case 0x0802: format = AL_FORMAT_STEREO8; break; 
				case 0x1001: format = AL_FORMAT_MONO16; break; 
				case 0x1002: format = AL_FORMAT_STEREO16; break; 
			}

			alBufferData((ALuint)poSample->iHandle,format,pSampleData,
								poSample->iSamples * (poSample->iBits>>3) * poSample->iChannels,
								poSample->iSRate);

			if ((error = alGetError()) != AL_NO_ERROR)
			{
				alDeleteBuffers(1,(ALuint*)&poSample->iHandle);
				CGSystemLC::I()->Error("alBufferData : %d", error);
				return;
			}
		}
	}
}

CSoundEmiter* CSoundRenderer_OpenAL::poGetFreeEmiter()
{
	for (int i=0;i<oEmiters.uiNumElems();i++)
	{
		if (! oEmiters[i].bPlaying)
			return( &oEmiters[i] );
	}

	return(NULL);
}

void CSoundRenderer_OpenAL::InvalidateEmiters ()
{
	for (int i=0;i<oEmiters.uiNumElems();i++)
	{
		if (oEmiters[i].bPlaying)
		{
			alSourceStop(oEmiters[i].uiSourceHandler);
			oEmiters[i].bPlaying = false;
		}
	}	
}
  



