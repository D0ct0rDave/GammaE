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
#include <DSound.h>
#include "GammaE_Mem.h"
#include "GammaE_Misc.h"
#include "GammaE_FileSys.h"
// -----------------------------------------------------------------------------
#ifdef __cplusplus
#endif

// CSoundRenderer_DSound
#include "SoundRender\SoundDrivers\SndDrv_DirectSound\CSoundRenderer_DSound.h"
HINSTANCE hDSInstance;
// HRESULT (WINAPI *poDirectSoundCreate)(GUID FAR *lpGUID, LPDIRECTSOUND FAR *lplpDS, IUnknown FAR *pUnkOuter);
HRESULT (WINAPI* poDirectSoundCreate)(LPGUID, LPDIRECTSOUND*, LPUNKNOWN);
// void *poDirectSoundCreate;

DSCAPS DSCaps;
HPSTR lpData, lpData2;
MMTIME mmstarttime;
LPDIRECTSOUND lpDS = NULL;
LPDIRECTSOUNDBUFFER lpDSPBuff = NULL;
LPDIRECTSOUNDBUFFER lpDSSBuff = NULL;
LPDIRECTSOUNDBUFFER lpDSBuff = NULL;

DSBUFFERDESC DSBuffDesc;
DSBUFFERDESC DSBuffDesc2;
WAVEFORMATEX DSWaveFmt;
DSBCAPS DSBuffCaps;
DWORD dwWritePos;

HWND__* hWnd;
unsigned int uiSndOfs = 0;

// Be careful since (buffertime*srate / ibuffersblocks) must be INTEGER !!!!
const int iBUFFERSAMPLES = 8192;
const int iBUFFERBLOCKS = 4;
int iBLOCKSIZE;
int iBUFFERSIZE;
int iWRITEBLOCK = 1;
int iREADBLOCK = 0;
// -----------------------------------------------------------------------------
CSoundRenderer_DSound::CSoundRenderer_DSound()
{
}
// -----------------------------------------------------------------------------
CSoundRenderer_DSound::~CSoundRenderer_DSound()
{
    Finish();
}

int CSoundRenderer_DSound::Init (void* _HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters)
{
    hWnd = (HWND__*)_HndDeviceContext;

    // --------------------------------------------------------------
    // Init the emiter array
    // --------------------------------------------------------------
    iMaxEmiters = _iMaxEmiters;
    oEmiters.Init(_iMaxEmiters);

    // --------------------------------------------------------------
    // Setup correctly sound parameters
    // --------------------------------------------------------------
    if ( _iSndBits == 16 ) iSndBits = 16;
    else iSndBits = 8;

    if ( _iSndSRate == 44100 ) iSndRate = 44100;
    else
    if ( _iSndSRate == 22050 ) iSndRate = 22050;
    else iSndRate = 11025;

    // Load direct sound dynamic library
    if ( !hDSInstance )
        if ( !iLoadDirectSound() )
            return(0);

    // --------------------------------------------------------------
    // Init direct sound
    // --------------------------------------------------------------
    CGSystemLC::I()->Write("Init direct sound... ");
    if ( poDirectSoundCreate(NULL,&lpDS,NULL) != DS_OK )
    {
        CGSystemLC::I()->Error("Failed initializing Direct Sound\n");
        Finish();
        return(0);
    }
    CGSystemLC::I()->Write("ok\n");

    // --------------------------------------------------------------
    CGSystemLC::I()->Write("Getting direct sound capabilities... ");
    DSCaps.dwSize = sizeof(DSCAPS);
    // if ( IDirectSound_GetCaps(lpDS,&DSCaps ) != DS_OK)
    if ( lpDS->GetCaps(&DSCaps ) != DS_OK )
    {
        CGSystemLC::I()->Error("Failed getting sound capabilities\n");
        Finish();
        return(0);
    }
    CGSystemLC::I()->Write("ok\n");

    // --------------------------------------------------------------
    CGSystemLC::I()->Write("Testing for hardware accelerated sound... ");
    if ( DSCaps.dwFlags & DSCAPS_EMULDRIVER )
    {
        CGSystemLC::I()->Error("Failed test of hardware acceleration\n");
        Finish();
        return(0);
    }
    CGSystemLC::I()->Write("ok\n");

    return ( iCreateBuffers() );
}
// -----------------------------------------------------------------------------
void CSoundRenderer_DSound::Finish ()
{
    if ( lpDSBuff ) lpDSBuff->Release();
    if ( lpDS ) lpDS->Release();

    iUnloadDirectSound();

    CSoundMixer::Finish();

    lpDS = NULL;
    lpDSBuff = NULL;
}
// -----------------------------------------------------------------------------
int CSoundRenderer_DSound::iLoadDirectSound ()
{
    if ( !hDSInstance )
    {
        CGSystemLC::I()->Write( "Loading DSound.DLL: ");
        hDSInstance = LoadLibrary("dsound.dll");
        if ( !hDSInstance )
        {
            CGSystemLC::I()->Error( "Failed loading library.\n" );
            return(0);
        }

        *( (FARPROC*)&poDirectSoundCreate ) = GetProcAddress(hDSInstance,"DirectSoundCreate");
        // ((FARPROC)poDirectSoundCreate) = GetProcAddress(hDSInstance,"DirectSoundCreate");
        if ( !poDirectSoundCreate )
        {
            CGSystemLC::I()->Error( "Failed getting DirectSoundCreate proc address.\n" );
            return(0);
        }
        CGSystemLC::I()->Write( "OK\n" );
    }

    return(1);
}
// -----------------------------------------------------------------------------
int CSoundRenderer_DSound::iUnloadDirectSound ()
{
    CGSystemLC::I()->Write("Unloading DSound.dll.\n");
    if ( hDSInstance )
    {
        FreeLibrary( hDSInstance );
        hDSInstance = NULL;
    }

    return(1);
}
// -----------------------------------------------------------------------------
int CSoundRenderer_DSound::iCreateBuffers ()
{
    HRESULT Res;

    // --------------------------------------------------------------
    // Set cooperative level to write into buffer
    // --------------------------------------------------------------
    CGSystemLC::I()->Write("Setting EXCLUSIVE cooperative level ... ");
    if ( lpDS->SetCooperativeLevel(hWnd,DSSCL_EXCLUSIVE) != DS_OK )
    {
        CGSystemLC::I()->Error("Failed setting Executive Cooperative Level\n");
        Finish();
        return(0);
    }
    CGSystemLC::I()->Write("ok\n");

    // --------------------------------------------------------------
    // Set DSound Primary buffer features
    // --------------------------------------------------------------
    memset( &DSBuffDesc,0,sizeof(DSBUFFERDESC) );
    DSBuffDesc.dwSize = sizeof(DSBUFFERDESC);
    DSBuffDesc.dwFlags = DSBCAPS_PRIMARYBUFFER;
    DSBuffDesc.dwBufferBytes = 0;
    DSBuffDesc.lpwfxFormat = NULL;

    // Create the primary buffer
    CGSystemLC::I()->Write("Create the primary buffer... ");
    if ( ( Res = lpDS->CreateSoundBuffer(&DSBuffDesc,&lpDSPBuff,NULL) ) != DS_OK )
    {
        CGSystemLC::I()->Error("Failed creating direct sound primary buffer\n");
        Finish();
        return(0);
    }
    CGSystemLC::I()->Write("ok\n");

    // --------------------------------------------------------------
    // Setup desired sample format for primary buffer
    // --------------------------------------------------------------
    CGSystemLC::I()->Write("Setup desired sample format for primary buffer... ");

    memset( &DSWaveFmt,0,sizeof(WAVEFORMATEX) );
    DSWaveFmt.cbSize = 0;
    DSWaveFmt.wFormatTag = WAVE_FORMAT_PCM;
    DSWaveFmt.nChannels = 2;
    DSWaveFmt.nSamplesPerSec = iSndRate;
    DSWaveFmt.wBitsPerSample = iSndBits;
    DSWaveFmt.nBlockAlign = (DSWaveFmt.wBitsPerSample >> 3) * 2;                    // *2 -> 2 Channels
    DSWaveFmt.nAvgBytesPerSec = iSndRate * DSWaveFmt.nBlockAlign;

    if ( ( Res = lpDSPBuff->SetFormat(&DSWaveFmt) ) != DS_OK )
    {
        // if ( (Res = IDirectSoundBuffer_SetFormat(lpDSPBuff,&DSWaveFmt)) != DS_OK)
        CGSystemLC::I()->Error("Failed setting Direct Sound sample format\n");
        Finish();
        return(0);
    }
    CGSystemLC::I()->Write("ok\n");

    // --------------------------------------------------------------
    // Set cooperative level to write into buffer
    // --------------------------------------------------------------
    CGSystemLC::I()->Write("Setting WRITEPRIMARY cooperative level ... ");
    if ( lpDS->SetCooperativeLevel(hWnd,DSSCL_WRITEPRIMARY) != DS_OK )
    {
        CGSystemLC::I()->Error("Failed setting WritePrimary Cooperative Level\n");
        CGSystemLC::I()->Write("Using secondary buffer for writting ... ");
        // --------------------------------------------------------------
        // Set DSound Primary buffer features
        // --------------------------------------------------------------
        memset( &DSBuffDesc,0,sizeof(DSBUFFERDESC) );
        DSBuffDesc2.dwSize = sizeof(DSBUFFERDESC);
        DSBuffDesc2.dwFlags = DSBCAPS_CTRLFREQUENCY | DSBCAPS_LOCSOFTWARE;
        DSBuffDesc2.dwBufferBytes = iBUFFERSAMPLES * DSWaveFmt.nBlockAlign;
        DSBuffDesc2.lpwfxFormat = &DSWaveFmt;

        if ( DS_OK != lpDS->CreateSoundBuffer(&DSBuffDesc2, &lpDSSBuff, NULL) )
        {
            CGSystemLC::I()->Error("Failed creating DirectSound secondary buffer for writting\n");
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
    CGSystemLC::I()->Write("ok\n");

    // --------------------------------------------------------------
    // Getting buffer capabilities
    // --------------------------------------------------------------
    CGSystemLC::I()->Write("Getting buffer capabilities...");

    DSBuffCaps.dwSize = sizeof(DSBCAPS);
    if ( ( Res = lpDSBuff->GetCaps (&DSBuffCaps) ) != DS_OK )
    {
        CGSystemLC::I()->Error("Failed getting DirectSound buffer capabilities\n");
        Finish();
        return(0);
    }
    CGSystemLC::I()->Write("ok\n");

    iBUFFERSIZE = iBUFFERSAMPLES * DSWaveFmt.nBlockAlign;
    iBLOCKSIZE = iBUFFERSIZE / iBUFFERBLOCKS;

    // Create a mixing buffer of maximum of 1 second
    CSoundMixer::SetupBuffer(iBUFFERSAMPLES,iSndRate,iSndBits);

    // Set Direct Sound Buffer Notify Position
    /*
       DSBPOSITIONNOTIFY pPosNotify[2];
       pPosNotify[0].dwOffset     = 0;
       pPosNotify[1].dwOffset     = uiSndBuffSize;
       pPosNotify[0].hEventNotify = m_pHEvent[0];
       pPosNotify[1].hEventNotify = m_pHEvent[1];

       if ( FAILED(lpDSBuff->SetNotificationPositions(2, pPosNotify)) )
       {
        CONPrintf("Failed\n");
        Finish();
        return;
       }
     */

    // Start output
    if ( lpDSSBuff ) lpDSSBuff->Play (0,0,DSBPLAY_LOOPING);

    return(1);
}
// -----------------------------------------------------------------------------
void CSoundRenderer_DSound::Render (float _fDelta)
{
    if ( _fDelta == 0.0f ) return;

    // Retrieve current cursor positions
    HRESULT hRes;
    DWORD dwReadCursor;
    DWORD dwWriteCursor;

    if ( ( hRes = lpDSBuff->GetCurrentPosition(&dwReadCursor,&dwWriteCursor) ) != DS_OK )
        return;

    iREADBLOCK = dwReadCursor / iBLOCKSIZE;
    if ( iREADBLOCK != iWRITEBLOCK )
        return;

    iWRITEBLOCK = (iWRITEBLOCK + 1) % iBUFFERBLOCKS;

    // unsigned int uiSamples  = (unsigned int)(_fDelta*(float)iSndRate);
    unsigned int uiSamples = iBLOCKSIZE / DSWaveFmt.nBlockAlign;

    // ------------------------------------------
    // Proceed with the mix
    // ------------------------------------------

    // Process all emiters:
    // Compute distance to receiver
    // Compute angle of incidence
    // Process emiter parameters, volume, falloff, etc.
    // Add to a local emiter list,
    // Order by average volume between left and right channel
    // Send to mixers those entities whose priorities are higher
    // or send all entities in the best case
    unsigned int uiProcEmit = 0;

    CSoundMixer::Clear();

    for ( int iElem = 0; iElem < oEmiters.uiMaxElems(); iElem++ )
    {
        CSoundEmiter_DSound* poEm = oEmiters.poElem(iElem);
        if ( poEm != NULL )
        {
            if ( !poEm->oSMP.bEnd )
            {
                if ( bComputeVolumeFactors(poEm) )
                {
                    poEm->oSMP.poSound = poEm->poSound;

                    CSoundMixer::Mix(poEm->oSMP,uiSamples);
                    uiProcEmit++;
                }
            }
            else
            {
                // Remove emiter from the list
                oEmiters.Release( poEm );
            }
        }
    }

    CSoundMixer::PostProcess();

    TransferData();
}
// -----------------------------------------------------------------------------
void CSoundRenderer_DSound::TransferData ()
{
    // Get current play position
    HRESULT hRes;

    void* pData1;
    void* pData2;
    DWORD dwWriteBytes1;
    DWORD dwWriteBytes2;
    int iRepeat;
    DWORD dwFlags = 0;                    // DSBLOCK_ENTIREBUFFER;

    iRepeat = 0;

    do {
        hRes = lpDSBuff->Lock(iWRITEBLOCK * iBLOCKSIZE,
                              iBLOCKSIZE,
                              &pData1,&dwWriteBytes1,
                              &pData2,&dwWriteBytes2,
                              dwFlags);

        if ( hRes == DSERR_BUFFERLOST )
        {
            // If DSERR_BUFFERLOST is returned, restore and retry lock.
            lpDSBuff->Restore();
            if ( iRepeat == 1 ) return;
            iRepeat = 1;
        }
    } while ( iRepeat );

    if ( dwWriteBytes2 != 0 )
    {
        // Copy first part
        memcpy(pData1,CSoundMixer::pGetBuffer(),dwWriteBytes1);

        // Copy second part
        memcpy(pData2,( (unsigned char*)CSoundMixer::pGetBuffer() ) + dwWriteBytes1,dwWriteBytes2);
        uiSndOfs = dwWriteBytes2;
    }
    else
    {
        memcpy(pData1,CSoundMixer::pGetBuffer(),dwWriteBytes1);
        uiSndOfs += dwWriteBytes1;
    }

    // Unlock buffer
    hRes = lpDSBuff->Unlock(pData1,dwWriteBytes1,pData2,dwWriteBytes2);
}
// -----------------------------------------------------------------------------
bool CSoundRenderer_DSound::bComputeVolumeFactors (CSoundEmiter_DSound* _poEmiter)
{
    if ( _poEmiter->iType == 0 )
    {
        // Global foreground emiters
        _poEmiter->oSMP.fLVol = _poEmiter->fVol * fGlbVol;
        _poEmiter->oSMP.fRVol = _poEmiter->fVol * fGlbVol;
        return(true);
    }

    // Distance factor
    float fDistFactor;
    fDistFactor = poReceiver->Pos.fSqDistance(_poEmiter->Pos);
    fDistFactor /= (_poEmiter->fRadius * _poEmiter->fRadius);

    if ( fDistFactor > _poEmiter->fVol )
    {
        _poEmiter->oSMP.fLVol = 0.0f;
        _poEmiter->oSMP.fRVol = 0.0f;
        return(true);                    // Cannot listen the emiter
        // return(false);		// Debería haber una funcion que simulase el mix del sample
        // y actualizase campos como bEnd, SamplePos, etc, de momento
        // este es el modo de hacer que se actualize un sonido que no suena
    }
    fDistFactor = 1.0f - fDistFactor;

    if ( _poEmiter->iType == 1 )
    {
        // Global background emiters
        _poEmiter->oSMP.fLVol = fDistFactor * _poEmiter->fVol * fGlbVol;
        _poEmiter->oSMP.fRVol = fDistFactor * _poEmiter->fVol * fGlbVol;
        return(true);
    }

    // Global angle factor
    const float fVolBias = 0.5f;
    const float fVolAtt = 0.5f;
    float fAngleFact;
    fAngleFact = fVolBias + (1.0f - ( 1.0f + poReceiver->Dir.fDotProd(_poEmiter->Dir) ) * 0.5f) * fVolAtt;

    // Panning factor
    CRay oRay;
    CVect3 oPerp;
    oRay.InitFromFields(poReceiver->Pos,poReceiver->Dir);
    oPerp = oRay.GetPerpendicular(_poEmiter->Pos);
    oPerp.Normalize();

    float fPanFact;
    fPanFact = ( ( 1.0f + oPerp.fDotProd(poReceiver->Side) ) * 0.5f );

    //
    float fVolFact = fDistFactor * fAngleFact * _poEmiter->fVol * fGlbVol;

    _poEmiter->oSMP.fLVol = fVolFact * fPanFact;
    _poEmiter->oSMP.fRVol = fVolFact * (1.0f - fPanFact);

    return(true);
}
// -----------------------------------------------------------------------------
CSoundEmiter* CSoundRenderer_DSound::poGetFreeEmiter()
{
    return( oEmiters.poGet() );
}
// -----------------------------------------------------------------------------
