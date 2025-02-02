// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#include "SoundRender\SoundDrivers\SndDrv_DirectSound\CSR_DS_Channel.h"

// -----------------------------------------------------------------------------

CSR_DS_Channel::CSR_DS_Channel()

    : lpDSBuff(NULL), lpDS3DBuff(NULL)
{
}

CSR_DS_Channel::~CSR_DS_Channel()
{
    if ( lpDSBuff ) lpDSBuff->Release();
}

int CSR_DS_Channel::CreateChannel (LPDIRECTSOUND _lpDS, CSoundEmiter* _pEmiter, CSample* _pSample)
{
    if ( !_lpDS ) return(0);

    DSBUFFERDESC DSBuffDesc;
    WAVEFORMATEX DSWaveFmt;

    // Setup desired sample format for secondary buffer
    memset( &DSWaveFmt,0,sizeof(WAVEFORMATEX) );
    DSWaveFmt.wFormatTag = WAVE_FORMAT_PCM;
    DSWaveFmt.nChannels = _pSample->iChannels;
    DSWaveFmt.nSamplesPerSec = _pSample->iSRate;
    DSWaveFmt.wBitsPerSample = _pSample->iBits;
    DSWaveFmt.nBlockAlign = _pSample->iBits >> 3;
    DSWaveFmt.nAvgBytesPerSec = _pSample->iSRate * (_pSample->iBits >> 3) * 1;   // *1 -> 1 Channels in DSound 3D

    // Set Secondary Sound Buffer features
    memset( &DSBuffDesc,0,sizeof(DSBUFFERDESC) );
    DSBuffDesc.dwSize = sizeof(DSBUFFERDESC);
    DSBuffDesc.dwFlags = DSBCAPS_STATIC | DSBCAPS_CTRL3D;
    DSBuffDesc.dwBufferBytes = _pSample->iSamples * (_pSample->iBits >> 3);
    DSBuffDesc.lpwfxFormat = &DSWaveFmt;

    // Create the primary buffer
    if ( _lpDS->CreateSoundBuffer(&DSBuffDesc,&lpDSBuff,NULL) != DS_OK ) return(0);

    // Query interface for 3D
    if ( lpDSBuff->QueryInterface(IID_IDirectSound3DBuffer,(LPVOID*)&lpDS3DBuff) != DS_OK )
    {
        lpDSBuff->Release();
        lpDSBuff = NULL;
        return (0);
    }

    lpDS3DBuff->SetPosition(_pEmiter->Pos.x,_pEmiter->Pos.y,_pEmiter->Pos.z,DS3D_DEFERRED);
    lpDS3DBuff->SetVelocity(_pEmiter->Speed.y,_pEmiter->Speed.y,_pEmiter->Speed.z,DS3D_DEFERRED);

    LPVOID lpBuff1,lpBuff2;
    DWORD iSize1,iSize2;

    // Copy sample data
    lpDSBuff->Lock(0,DSBuffDesc.dwBufferBytes,&lpBuff1,&iSize1,NULL,NULL,DSBLOCK_ENTIREBUFFER);
    memcpy(lpBuff1,_pSample->pData,iSize1);
    lpDSBuff->Unlock(lpBuff1,iSize1,NULL,NULL);

    // Start playing the sound
    lpDSBuff->Play(0,0,DSBPLAY_LOOPING);
    return(1);
}

void CSR_DS_Channel::UpdateChannel (CSoundEmiter* _pEmiter)
{
    if ( lpDSBuff )
    {
        lpDS3DBuff->SetPosition(_pEmiter->Pos.x,_pEmiter->Pos.y,_pEmiter->Pos.z,DS3D_DEFERRED);
        lpDS3DBuff->SetVelocity(_pEmiter->Speed.y,_pEmiter->Speed.y,_pEmiter->Speed.z,DS3D_DEFERRED);
    }
}

// -----------------------------------------------------------------------------
