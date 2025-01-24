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
// %X% %Q% %Z% %W%

#include <bass.h>

// CSoundRenderer_Bass
#include "SoundRender\SoundDrivers\SndDrv_BASS\CSoundRenderer_Bass.h"

// Class CSoundRenderer_Bass

CSoundRenderer_Bass::CSoundRenderer_Bass()
    : pBassEmiter(NULL), iMaxChannels(0), iNumChannels(0)
{
}

CSoundRenderer_Bass::~CSoundRenderer_Bass()
{
    BASS_Stop();
    BASS_Free();

    if ( pBassEmiter ) mDel [] pEmiter;
}

int CSoundRenderer_Bass::Init (void* _HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters)
{
    // Init the emiter array
    iMaxEmiters = _iMaxEmiters;
    pBassEmiter = mNew CSR_Bass_Emiter[iMaxEmiters];
    memset( pBassEmiter,0,iMaxEmiters * sizeof(CSR_Bass_Emiter) );

    // Init bass library
    /* Initialize the output device with A3D (syncs not used) */
    if ( !BASS_Init(0,_iSndSRate,BASS_DEVICE_NOSYNC | BASS_DEVICE_A3D,(HWND__*)_HndDeviceContext) )
    {
        /* no A3D, so try without... */
        if ( !BASS_Init(0,_iSndSRate,BASS_DEVICE_NOSYNC | BASS_DEVICE_3D,(HWND__*)_HndDeviceContext) )
        {
            return(0);
        }
    }
    else
    {
        /* enable A3D HF absorbtion option */
        BASS_SetA3DHFAbsorbtion(0.0);
    }

    /* Use meters as distance unit, real world rolloff, real doppler effect */
    BASS_Set3DFactors(1.0,1.0f,1.0);

    /* Turn EAX off (volume=0.0), if error then EAX is not supported */
    BASS_SetEAXParameters(-1,0.0,-1.0,-1.0);

    BASS_Start();   /* Start digital output */

    return(1);
}

void CSoundRenderer_Bass::Render (float _fDelta)
{
    ProcessEmiters();

    // Apply possible changes
    BASS_Apply3D();
}

void CSoundRenderer_Bass::ProcessEmiters ()
{
    CSoundEmiter* pEmit;
    CSR_Bass_Emiter* pBEmit;

    for ( int cEnt = 0; cEnt < iMaxEmiters; cEnt++ )
    {
        pBEmit = &pBassEmiter[cEnt];
        pEmit = pBEmit->pEmiter;

        if ( pEmit )
        {
            /*
               if (! BASS_ChannelIsActive( pBEmit->iCurCh ))
               {
                pBEmit->iCurSmpLayer++;

                if (pBEmit->iCurSmpLayer == pEmit->GetSound()->iNumLayers)
                {
                    // The sound has finished, then we must remove the emiter
                    pBEmit->pEmiter = NULL;
                }
                else
                    UpdateBassEmiter_Layers(pBEmit);
               }
               else
               {
             */
            // The sound is currently looping and the user want to exit the
            // loop ?
            if (
                (pEmit->GetSound()->poSLayer[ pBEmit->iCurSmpLayer ].bLoop)
                &&
                (pBEmit->bUnlock)
                )
            {
                pBEmit->bUnlock = false;

                pBEmit->iCurSmpLayer++;
                if ( pBEmit->iCurSmpLayer == pEmit->GetSound()->iNumLayers )
                {
                    // The sound has finished so free its channel
                    pBEmit->pEmiter = NULL;
                    BASS_ChannelStop(pBEmit->iCurCh);
                }
                else
                    UpdateBassEmiter_Layers(pBEmit);
            }
            else
                UpdateBassEmiter_3D(pBEmit);
            // }
        }
    }
}

void CSoundRenderer_Bass::UploadSample (CSample* _pSample)
{
    DWORD Flags;

    _pSample->iHandle = BASS_SampleLoad(true,
                                        _pSample->pData,
                                        0,
                                        _pSample->iSamples,
                                        64,
                                        Flags |
                                        BASS_SAMPLE_LOOP |
                                        BASS_SAMPLE_3D |
                                        BASS_SAMPLE_OVER_DIST |
                                        BASS_SAMPLE_OVER_VOL |
                                        BASS_SAMPLE_MUTEMAX);
}

void CSoundRenderer_Bass::UpdateBassEmiter_Layers (CSR_Bass_Emiter* _pBEmiter)
{
    CSample* pSample;

    // look if this sample layer has been registered
    pSample = _pBEmiter->pEmiter->GetSound()->poSLayer[ _pBEmiter->iCurSmpLayer ].poSample;
    if ( !pSample ) return;

    // Register sample?
    if ( pSample->iHandle == -1 ) UploadSample(pSample);

    _pBEmiter->iCurCh = pSample->iHandle;

    // Start playing the sample
    BASS_SamplePlay3DEx(_pBEmiter->iCurCh,
                        NULL,
                        NULL,
                        NULL,
                        0,
                        -1,
                        (int)_pBEmiter->pEmiter->fVol,
                        true);

    UpdateBassEmiter_3D(_pBEmiter);
}

void CSoundRenderer_Bass::UpdateBassEmiter_3D (CSR_Bass_Emiter* _pBEmiter)
{
    CVect3 RelPos;
    CVect3 RelSpeed;

    // The receiver is in the action radius of the emiter
    /*
       if ( _pBEmiter->pEmiter->Pos.SqDistance( pReceiver->Pos ) < pBassEmiter[cEnt].pEmiter->fRadius)
       {
     */
    RelPos.Assign( _pBEmiter->pEmiter->Pos);
    RelPos.Sub   ( pReceiver->Pos);

    RelSpeed.Assign( _pBEmiter->pEmiter->Speed);
    RelSpeed.Sub   ( pReceiver->Speed);

    BASS_ChannelSet3DPosition(  _pBEmiter->iCurCh,
                                (BASS_3DVECTOR*)&RelPos.v,
                                NULL,
                                (BASS_3DVECTOR*)&RelSpeed.v);
    /*
       }
       else
       {

        BASS_ChannelSet3DPosition(	_pBEmiter->iCurCh,
                                (BASS_3DVECTOR *)_pBEmiter->pEmiter->Pos.v,
                                NULL,
                                (BASS_3DVECTOR *)_pBEmiter->pEmiter->Speed.v);
       }
     */
}

int CSoundRenderer_Bass::iAddEmiter (CSoundEmiter* _pEmiter)
{
    assert (pBassEmiter && "NULL BASS sound emiter table");

    for ( int cEmiter = 0; cEmiter < iMaxEmiters; cEmiter++ )
    {
        if ( !pBassEmiter[cEmiter].pEmiter )
        {
            pBassEmiter[cEmiter].bUnlock = false;
            pBassEmiter[cEmiter].iCurCh = -1;
            pBassEmiter[cEmiter].iCurSmpLayer = 0;
            pBassEmiter[cEmiter].pEmiter = _pEmiter;

            UpdateBassEmiter_Layers(&pBassEmiter[cEmiter]);

            return(cEmiter);
        }
    }
    return (-1);
}

void CSoundRenderer_Bass::RemoveEmiter (int _iIdx)
{
    assert (pBassEmiter && "NULL BASS sound emiter table");
    assert ( (_iIdx < iMaxEmiters) && "BASS Emiter index out of emiter table bounds" );

    pBassEmiter[_iIdx].pEmiter = NULL;
}

void CSoundRenderer_Bass::UnlockEmiter (int _iIdx)
{
    assert (pBassEmiter && "NULL BASS sound emiter table");
    assert ( (_iIdx < iMaxEmiters) && "BASS Emiter index out of emiter table bounds" );

    pBassEmiter[_iIdx].bUnlock = true;
}

// Additional Declarations
