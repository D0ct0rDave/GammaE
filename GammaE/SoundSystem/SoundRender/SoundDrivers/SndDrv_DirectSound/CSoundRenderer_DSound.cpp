//## begin module%3BB700C50336.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BB700C50336.cm

//## begin module%3BB700C50336.cp preserve=no
//## end module%3BB700C50336.cp

//## Module: CSoundRenderer_DSound%3BB700C50336; Pseudo Package body
//## Source file: i:\Projects\GammaE\SoundSystem\SoundRender\SoundDrivers\SndDrv_DirectSound\CSoundRenderer_DSound.cpp

//## begin module%3BB700C50336.additionalIncludes preserve=no
//## end module%3BB700C50336.additionalIncludes

//## begin module%3BB700C50336.includes preserve=yes
#include <DSound.h>	
#include "memory/GammaE_mem.h"
#include "Misc/GammaE_Misc.h"

#include "FileSys/GammaE_FileSys.h"

#ifdef __cplusplus
#endif
//## end module%3BB700C50336.includes

// CSoundRenderer_DSound
#include "SoundSystem\SoundRender\SoundDrivers\SndDrv_DirectSound\CSoundRenderer_DSound.h"
//## begin module%3BB700C50336.additionalDeclarations preserve=yes
HINSTANCE			hDSInstance;
//HRESULT (WINAPI *poDirectSoundCreate)(GUID FAR *lpGUID, LPDIRECTSOUND FAR *lplpDS, IUnknown FAR *pUnkOuter);
HRESULT (WINAPI *poDirectSoundCreate)(LPGUID, LPDIRECTSOUND *, LPUNKNOWN);
//void *poDirectSoundCreate;

DSCAPS				DSCaps;
HPSTR				lpData, lpData2;
MMTIME				mmstarttime;
LPDIRECTSOUND		lpDS		= NULL;
LPDIRECTSOUNDBUFFER lpDSPBuff	= NULL;
LPDIRECTSOUNDBUFFER lpDSSBuff	= NULL;
LPDIRECTSOUNDBUFFER lpDSBuff	= NULL;

DSBUFFERDESC		DSBuffDesc;
DSBUFFERDESC		DSBuffDesc2;
WAVEFORMATEX		DSWaveFmt;
DSBCAPS				DSBuffCaps;
DWORD				dwWritePos;

HWND__				*hWnd;
unsigned int		uiSndBuffSize = 0;
unsigned int		uiSndOfs      = 0;

const float			fBUFFERTIME	  = 0.1f;

//## end module%3BB700C50336.additionalDeclarations


// Class CSoundRenderer_DSound 




CSoundRenderer_DSound::CSoundRenderer_DSound()
  //## begin CSoundRenderer_DSound::CSoundRenderer_DSound%.hasinit preserve=no
  //## end CSoundRenderer_DSound::CSoundRenderer_DSound%.hasinit
  //## begin CSoundRenderer_DSound::CSoundRenderer_DSound%.initialization preserve=yes
  //## end CSoundRenderer_DSound::CSoundRenderer_DSound%.initialization
{
  //## begin CSoundRenderer_DSound::CSoundRenderer_DSound%.body preserve=yes
  //## end CSoundRenderer_DSound::CSoundRenderer_DSound%.body
}


CSoundRenderer_DSound::~CSoundRenderer_DSound()
{
  //## begin CSoundRenderer_DSound::~CSoundRenderer_DSound%.body preserve=yes
	Finish();
  //## end CSoundRenderer_DSound::~CSoundRenderer_DSound%.body
}



//## Other Operations (implementation)
int CSoundRenderer_DSound::Init (void *_HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters)
{
  //## begin CSoundRenderer_DSound::Init%1001849070.body preserve=yes
	hWnd = (HWND__*)_HndDeviceContext;

	// Init the emiter array	
	iMaxEmiters = _iMaxEmiters;
	oEmiters.Init(_iMaxEmiters);
	
	// --------------------------------------------------------------
	// Setup correctly sound parameters
	// --------------------------------------------------------------
	 if (_iSndBits == 16) iSndBits = 16; else iSndBits = 8;

	 if (_iSndSRate == 44100) iSndRate = 44100;
else if (_iSndSRate == 22050) iSndRate = 22050;
else iSndRate = 11025;

	// Load direct sound dynamic library
	if (! hDSInstance)
		if(! iLoadDirectSound()) 
			return(0);

	// --------------------------------------------------------------
	// Init direct sound
	// --------------------------------------------------------------
	CONPrintf("Init direct sound... ");
	if(poDirectSoundCreate(NULL,&lpDS,NULL) != DS_OK)
	{
		CONPrintf("Failed\n");
		Finish();		
		return(0);
	}
	CONPrintf("ok\n");

	// --------------------------------------------------------------
	CONPrintf("Getting direct sound capabilities... ");
	DSCaps.dwSize = sizeof(DSCAPS);
	// if ( IDirectSound_GetCaps(lpDS,&DSCaps ) != DS_OK)
	if ( lpDS->GetCaps(&DSCaps ) != DS_OK)
	{
		CONPrintf("Failed\n");		
		Finish();
		return(0);
	}
	CONPrintf("ok\n");

	// --------------------------------------------------------------	
	CONPrintf("Testing for hardware accelerated sound... ");
	if (DSCaps.dwFlags & DSCAPS_EMULDRIVER )
	{		
		CONPrintf("Failed\n");
		Finish();
		return(0);
	}
	CONPrintf("ok\n");

	return (iCreateBuffers());
  //## end CSoundRenderer_DSound::Init%1001849070.body
}

void CSoundRenderer_DSound::Finish ()
{
  //## begin CSoundRenderer_DSound::Finish%1014979367.body preserve=yes
	if (lpDSBuff)	lpDSBuff->Release();
	if (lpDS)		lpDS->Release();
	
	iUnloadDirectSound();
	
	lpDS     = NULL;
	lpDSBuff = NULL;
  //## end CSoundRenderer_DSound::Finish%1014979367.body
}

int CSoundRenderer_DSound::iLoadDirectSound ()
{
  //## begin CSoundRenderer_DSound::iLoadDirectSound%1015076948.body preserve=yes
  	if (! hDSInstance)
	{
		CONPrintf( "Loading DSound.DLL: ");
		hDSInstance = LoadLibrary("dsound.dll");
		if (! hDSInstance)
		{
			CONPrintf( "Failed loading library.\n" );
			return(0);
		}

		*((FARPROC *)&poDirectSoundCreate) = GetProcAddress(hDSInstance,"DirectSoundCreate");
		// ((FARPROC)poDirectSoundCreate) = GetProcAddress(hDSInstance,"DirectSoundCreate");
		if (!poDirectSoundCreate)
		{
			CONPrintf( "Failed getting proc address.\n" );
			return(0);
		}
		CONPrintf( "OK\n" );
	}

	return(1);
  //## end CSoundRenderer_DSound::iLoadDirectSound%1015076948.body
}

int CSoundRenderer_DSound::iUnloadDirectSound ()
{
  //## begin CSoundRenderer_DSound::iUnloadDirectSound%1015076949.body preserve=yes
	CONPrintf("Unloading DSound.dll.\n");
  	if ( hDSInstance )
	{
		FreeLibrary( hDSInstance );
		hDSInstance = NULL;
	}

	return(1);
  //## end CSoundRenderer_DSound::iUnloadDirectSound%1015076949.body
}

int CSoundRenderer_DSound::iCreateBuffers ()
{
  //## begin CSoundRenderer_DSound::iCreateBuffers%1015076950.body preserve=yes
	HRESULT Res;

	// --------------------------------------------------------------
	// Set cooperative level to write into buffer
	// --------------------------------------------------------------
	CONPrintf("Setting EXCLUSIVE cooperative level ... ");
	if (lpDS->SetCooperativeLevel(hWnd,DSSCL_EXCLUSIVE) != DS_OK)
	{
		CONPrintf("Failed\n");
		Finish();
		return(0);
	}
	CONPrintf("ok\n");


	// --------------------------------------------------------------
	// Set DSound Primary buffer features
	// --------------------------------------------------------------
	memset(&DSBuffDesc,0,sizeof(DSBUFFERDESC));
	DSBuffDesc.dwSize		 = sizeof(DSBUFFERDESC);
	DSBuffDesc.dwFlags		 = DSBCAPS_PRIMARYBUFFER;
	DSBuffDesc.dwBufferBytes = 0;
	DSBuffDesc.lpwfxFormat   = NULL;
		
	// Create the primary buffer
	CONPrintf("Create the primary buffer... ");
	if( (Res = lpDS->CreateSoundBuffer(&DSBuffDesc,&lpDSPBuff,NULL)) != DS_OK)
	{		
		CONPrintf("Failed\n");
		Finish();
		return(0);
	}	
	CONPrintf("ok\n");


	// --------------------------------------------------------------
	// Setup desired sample format for primary buffer
	// --------------------------------------------------------------
	CONPrintf("Setup desired sample format for primary buffer... ");

	memset(&DSWaveFmt,0,sizeof(WAVEFORMATEX));
	DSWaveFmt.cbSize		 = 0;
	DSWaveFmt.wFormatTag	 = WAVE_FORMAT_PCM;
	DSWaveFmt.nChannels		 = 2;	
	DSWaveFmt.nSamplesPerSec = iSndRate;
	DSWaveFmt.wBitsPerSample = iSndBits;
	DSWaveFmt.nBlockAlign    = (DSWaveFmt.wBitsPerSample >> 3)*2;	//*2 -> 2 Channels
	DSWaveFmt.nAvgBytesPerSec= iSndRate*DSWaveFmt.nBlockAlign;

	if ((Res = lpDSPBuff->SetFormat(&DSWaveFmt)) != DS_OK)
	// if ( (Res = IDirectSoundBuffer_SetFormat(lpDSPBuff,&DSWaveFmt)) != DS_OK)
	{
		CONPrintf("Failed\n");
		Finish();
		return(0);		
	}
	CONPrintf("ok\n");
	

	// --------------------------------------------------------------
	// Set cooperative level to write into buffer
	// --------------------------------------------------------------
	CONPrintf("Setting WRITEPRIMARY cooperative level ... ");
	if (lpDS->SetCooperativeLevel(hWnd,DSSCL_WRITEPRIMARY) != DS_OK)
	{
		CONPrintf("Failed\n");
		CONPrintf("Using secondary buffer for writting ... ");		
		// --------------------------------------------------------------
		// Set DSound Primary buffer features
		// --------------------------------------------------------------
		memset(&DSBuffDesc,0,sizeof(DSBUFFERDESC));
		DSBuffDesc2.dwSize		 = sizeof(DSBUFFERDESC);
		DSBuffDesc2.dwFlags		 = DSBCAPS_CTRLFREQUENCY | DSBCAPS_LOCSOFTWARE;
		DSBuffDesc2.dwBufferBytes= (unsigned int)(fBUFFERTIME*(float)DSWaveFmt.nAvgBytesPerSec);
		DSBuffDesc2.lpwfxFormat  = &DSWaveFmt;
				if (DS_OK != lpDS->CreateSoundBuffer(&DSBuffDesc2, &lpDSSBuff, NULL))
		{
			CONPrintf("Failed\n");
			Finish();
			return(0);
		}
		
		// Setup main buffer to secondary buffer
		lpDSBuff = lpDSSBuff;
	}
	else
	{
		// Setup main buffer to primary buffer
		lpDSBuff = lpDSPBuff;
	}
	CONPrintf("ok\n");


	// --------------------------------------------------------------
	// Getting buffer capabilities
	// --------------------------------------------------------------
	CONPrintf("Getting buffer capabilities...");
	
	DSBuffCaps.dwSize = sizeof(DSBCAPS);
	if ((Res = lpDSBuff->GetCaps (&DSBuffCaps)) != DS_OK)
	{		
		CONPrintf("Failed\n");
		Finish();
		return(0);
	}
	CONPrintf("ok\n");

	
	uiSndBuffSize = DSBuffCaps.dwBufferBytes;

	// Start output
	lpDSPBuff->Play(0,0,DSBPLAY_LOOPING);
	if (lpDSSBuff) lpDSSBuff->Play (0,0,DSBPLAY_LOOPING);
	
	// Create a mixing buffer of maximum of 1 second
	CSoundMixer::SetupBuffer(fBUFFERTIME,iSndRate,iSndBits);

	return(1);
  //## end CSoundRenderer_DSound::iCreateBuffers%1015076950.body
}

void CSoundRenderer_DSound::Render (float _fDelta)
{
  //## begin CSoundRenderer_DSound::Render%1001849071.body preserve=yes
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
	unsigned int uiSamples  = (unsigned int)(_fDelta*(float)iSndRate);
	CSoundEmiter *poEm;

	for (int iElem=0;iElem<oEmiters.iMaxElems();iElem++)
	{
		poEm = oEmiters.poElem(iElem);
		if ( poEm )
		{
			if (! poEm->oSMP.bEnd)
			{
				if (bComputeVolumeFactors(poEm))
				{
					CSoundMixer::Mix(poEm->oSMP,uiSamples);
					uiProcEmit++;
				}
			}
			else
			{
				// Remove emiter from the list
				oEmiters.Del(iElem);
			}
		}
	}

	if (! uiProcEmit)
	{
		CSoundMixer::Clear();
	}

	TransferData(uiSamples);
  //## end CSoundRenderer_DSound::Render%1001849071.body
}

void CSoundRenderer_DSound::TransferData (unsigned int _uiSamples)
{
  //## begin CSoundRenderer_DSound::TransferData%1015160465.body preserve=yes
	unsigned int	uiSampleBytes = _uiSamples*DSWaveFmt.nBlockAlign;
	
	// Get current play position
	HRESULT			hRes;

	void*		pData1;
	void*		pData2;
	DWORD		dwWriteBytes1;
	DWORD		dwWriteBytes2;


	hRes = lpDSBuff->Lock(	uiSndOfs,uiSampleBytes,
							&pData1,&dwWriteBytes1,
							&pData2,&dwWriteBytes2,
							/*DSBLOCK_FROMWRITECURSOR */0);

	
	// If DSERR_BUFFERLOST is returned, restore and retry lock.
    if (hRes == DSERR_BUFFERLOST) 
    { 
        lpDSBuff->Restore(); 
		hRes = lpDSBuff->Lock(uiSndOfs,uiSampleBytes,
							  &pData1,&dwWriteBytes1,
							  &pData2,&dwWriteBytes2,
							  0 );
	} 

	if (dwWriteBytes1 < uiSampleBytes)
	{
		// Copy first part
		memcpy(pData1,CSoundMixer::pGetBuffer(),dwWriteBytes1);
		
		// Copy second part
		memcpy(pData2,((unsigned char*)CSoundMixer::pGetBuffer()) + dwWriteBytes1,dwWriteBytes2);
		uiSndOfs = dwWriteBytes2;
	}
	else
	{
		memcpy(pData1,CSoundMixer::pGetBuffer(),dwWriteBytes1);
		uiSndOfs += dwWriteBytes1;
	}

	// Unlock buffer
	hRes = lpDSBuff->Unlock(pData1,dwWriteBytes1,pData2,dwWriteBytes2);

  //## end CSoundRenderer_DSound::TransferData%1015160465.body
}

bool CSoundRenderer_DSound::bComputeVolumeFactors (CSoundEmiter* _poEmiter)
{
  //## begin CSoundRenderer_DSound::bComputeVolumeFactors%1015188291.body preserve=yes
	if (_poEmiter->iType == 0)
	{
		// Global foreground emiters
		_poEmiter->oSMP.fLVol = _poEmiter->fVol;
		_poEmiter->oSMP.fRVol = _poEmiter->fVol;		
		return(true);
	}

	// Distance factor
	float fDistFactor;
	fDistFactor  = poReceiver->Pos.SqDistance(_poEmiter->Pos);
	fDistFactor /= (_poEmiter->fRadius*_poEmiter->fRadius);

	if (fDistFactor > _poEmiter->fVol)
	{
		_poEmiter->oSMP.fLVol = 0.0f;
		_poEmiter->oSMP.fRVol = 0.0f;
		return(true);	// Cannot listen the emiter
		// return(false);		// Debería haber una funcion que simulase el mix del sample
								// y actualizase campos como bEnd, SamplePos, etc, de momento
								// este es el modo de hacer que se actualize un sonido que no suena
	}	
	fDistFactor = 1.0f - fDistFactor;
	
	if (_poEmiter->iType == 1)
	{
		// Global background emiters
		_poEmiter->oSMP.fLVol = fDistFactor*_poEmiter->fVol;
		_poEmiter->oSMP.fRVol = fDistFactor*_poEmiter->fVol;
		return(true);
	}

	// Global angle factor
	const float fVolBias = 0.5f;
	const float fVolAtt  = 0.5f;
	float       fAngleFact;
	fAngleFact = fVolBias + (1.0f - (1.0f+poReceiver->Dir.DotProd(_poEmiter->Dir))*0.5f)*fVolAtt;

	// Panning factor
	CRay	oRay;
	CVect3	oPerp;
	oRay.InitFromFields(poReceiver->Pos,poReceiver->Dir);
	oPerp = oRay.GetPerpendicular(_poEmiter->Pos);
	oPerp.Normalize();

	float		fPanFact;
	fPanFact = ((1.0f+oPerp.DotProd(poReceiver->Side))*0.5f);

	// 
	float fVolFact = fDistFactor*fAngleFact*_poEmiter->fVol;

	_poEmiter->oSMP.fLVol = fVolFact*fPanFact;
	_poEmiter->oSMP.fRVol = fVolFact*(1.0f-fPanFact);

	return(true);
  //## end CSoundRenderer_DSound::bComputeVolumeFactors%1015188291.body
}

// Additional Declarations
  //## begin CSoundRenderer_DSound%3BB700C50336.declarations preserve=yes
  //## end CSoundRenderer_DSound%3BB700C50336.declarations

//## begin module%3BB700C50336.epilog preserve=yes
//## end module%3BB700C50336.epilog
