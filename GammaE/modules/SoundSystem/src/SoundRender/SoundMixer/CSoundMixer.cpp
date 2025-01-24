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
// El mixer trabaja internamente con 32 bits stereo
// El buffer de prefetch de samples es de 16 bit, stereo
// La mezcla final se puede hacer mono o estereo, 8 o 16 bit

// CSoundMixer
#include "SoundRender\SoundMixer\CSoundMixer.h"
#include "GammaE_Mem.h"
#include <string.h>

void* CSoundMixer::pSampleBuffer = NULL;

// Class CSoundMixer

void* CSoundMixer::pBuffer = NULL;

int* CSoundMixer::pi32bBuffer = NULL;

unsigned int CSoundMixer::uiBuffSize = 0;

unsigned int CSoundMixer::uiBuffSamples = 0;

int CSoundMixer::iSRate = 0;

int CSoundMixer::iBits = 0;

CSoundMixer::CSoundMixer()
{
}

CSoundMixer::~CSoundMixer()
{
}

void CSoundMixer::Clear ()
{
    memset(pBuffer,0,uiBuffSize);
    memset(pSampleBuffer,0,uiBuffSamples * 2 * 2);
    memset(pi32bBuffer,0,uiBuffSamples * 2 * 4);
}

void CSoundMixer::SetupBuffer (unsigned int _uiSamples, unsigned int _iSRate, int _iBits)
{
    iSRate = _iSRate;
    iBits = _iBits;
    uiBuffSamples = _uiSamples;
    uiBuffSize = uiBuffSamples * (iBits >> 3) * 2;
    pBuffer = mAlloc(uiBuffSize);
    pi32bBuffer = (int*)mAlloc(uiBuffSamples * 2 * 4);
    pSampleBuffer = (int*)mAlloc(uiBuffSamples * 2 * 2);

    Clear();                    // Erase buffer contents previously to it's use

    assert (pBuffer && "Unable to allocate sound buffer");
}

void CSoundMixer::Mix (CSoundMixPars& _oSMP, unsigned int _uiSamples,unsigned int _uiCurDSmpPos)
{
    // Current buffer position
    if ( (_uiSamples + _uiCurDSmpPos) > uiBuffSamples ) _uiSamples = uiBuffSamples;

    CSoundLayer* poSLayer = &_oSMP.poSound->poSLayer[_oSMP.iCLayer];
    CSample* poSample = poSLayer->poSample;

    int iFlags = (poSample->iBits << 8) | poSample->iChannels;
    int iProcSamples = 0;

    switch ( iFlags )
    {
        // 16 bit, mono
        case 0x0801:    iProcSamples = iMix8M (_oSMP,poSample,_uiSamples,_uiCurDSmpPos);
        break;

        case 0x0802:    iProcSamples = iMix8S (_oSMP,poSample,_uiSamples,_uiCurDSmpPos);
        break;

        case 0x1001:    iProcSamples = iMix16M(_oSMP,poSample,_uiSamples,_uiCurDSmpPos);
        break;

        case 0x1002:    iProcSamples = iMix16S(_oSMP,poSample,_uiSamples,_uiCurDSmpPos);
        break;
    }

    _uiCurDSmpPos += iProcSamples;
    _uiSamples -= iProcSamples;
    _oSMP.iSPos += iProcSamples;

    // Have we fullfilled all the need info?
    if ( _uiSamples > 0 )
    {
        // Nooooo:

        // Look if sample is looping
        if ( (poSLayer->bLoop) && (!_oSMP.bLUnlock) )
        {
            // Start at the beginning of the same sample
            _oSMP.iSPos = 0;

            // Continue mixing ...
            Mix(_oSMP,_uiSamples,_uiCurDSmpPos);
        }
        else
        {
            // Auto update this
            _oSMP.bLUnlock = false;

            // Next layer
            if ( (_oSMP.iCLayer + 1) < _oSMP.poSound->iNumLayers )
            {
                // Update current sound layer
                _oSMP.iSPos = 0;
                _oSMP.iCLayer++;

                // Continue mixing ...
                Mix(_oSMP,_uiSamples,_uiCurDSmpPos);
            }
            else
            {
                // No more process on this sound
                _oSMP.bEnd = true;
            }
        }
    }
}

int CSoundMixer::iMix16M(CSoundMixPars& _oSMP, CSample* _poSample, unsigned int _uiSamples, unsigned int _uiCurDSmpPos)
{
    // Mix a 16 bit mono sample with the contents of the mix buffer

    // Fetch sample data
    int iMaxSamples = _poSample->iGetData(_oSMP.iSPos,pSampleBuffer,_uiSamples);

    // Get volume multipliers
    int iLV = _oSMP.fLVol * 32768.0f;
    int iRV = _oSMP.fRVol * 32768.0f;

    // Get buffer pointers
    short* psSrc = (short*)pSampleBuffer;
    int* piDst = (int*)pi32bBuffer + _uiCurDSmpPos * 2;

    // Mix samples
    for ( unsigned int s = 0; s < iMaxSamples; s++ )
    {
        // Process sample
        int iL = psSrc[0] * iLV;
        iL >>= 15;
        int iR = psSrc[0] * iRV;
        iR >>= 15;
        psSrc += 1;

        // Store sample
        piDst[0] += iL;
        piDst[1] += iR;
        piDst += 2;
    }

    return (iMaxSamples);
}

int CSoundMixer::iMix16S(CSoundMixPars& _oSMP, CSample* _poSample, unsigned int _uiSamples, unsigned int _uiCurDSmpPos)
{
    // Mix a 16 bit stereo sample with the contents of the mix buffer

    // Fetch sample data
    int iMaxSamples = _poSample->iGetData(_oSMP.iSPos,pSampleBuffer,_uiSamples);

    // Get volume multipliers
    int iLV = _oSMP.fLVol * 32768.0f;
    int iRV = _oSMP.fRVol * 32768.0f;

    // Get buffer pointers
    short* psSrc = (short*)pSampleBuffer;
    int* piDst = (int*)pi32bBuffer + _uiCurDSmpPos * 2;

    // Mix samples
    for ( unsigned int s = 0; s < iMaxSamples; s++ )
    {
        // Process sample
        int iL = psSrc[0] * iLV;
        iL >>= 15;
        int iR = psSrc[1] * iRV;
        iR >>= 15;
        psSrc += 2;

        // Store sample
        piDst[0] += iL;
        piDst[1] += iR;
        piDst += 2;
    }

    return (iMaxSamples);
}

int CSoundMixer::iMix8M (CSoundMixPars& _oSMP, CSample* _poSample, unsigned int _uiSamples, unsigned int _uiCurDSmpPos)
{
    // Mix a 8 bit mono sample with the contents of the mix buffer

    // Fetch sample data
    int iMaxSamples = _poSample->iGetData(_oSMP.iSPos,pSampleBuffer,_uiSamples);

    // Get volume multipliers
    int iLV = _oSMP.fLVol * 32768.0f;
    int iRV = _oSMP.fRVol * 32768.0f;

    // Get buffer pointers
    char* pcSrc = (char*)pSampleBuffer;
    int* piDst = (int*)pi32bBuffer + _uiCurDSmpPos * 2;

    // Mix samples
    for ( unsigned int s = 0; s < iMaxSamples; s++ )
    {
        // Process sample
        int iL = pcSrc[0] * iLV;
        iL >>= 7;
        int iR = pcSrc[0] * iRV;
        iR >>= 7;
        pcSrc += 1;

        // Store sample
        piDst[0] += iL;
        piDst[1] += iR;
        piDst += 2;
    }

    return (iMaxSamples);
}

int CSoundMixer::iMix8S (CSoundMixPars& _oSMP, CSample* _poSample, unsigned int _uiSamples, unsigned int _uiCurDSmpPos)
{
    // Mix a 8 bit stereo sample with the contents of the mix buffer

    // Fetch sample data
    int iMaxSamples = _poSample->iGetData(_oSMP.iSPos,pSampleBuffer,_uiSamples);

    // Get volume multipliers
    int iLV = _oSMP.fLVol * 32768.0f;
    int iRV = _oSMP.fRVol * 32768.0f;

    // Get buffer pointers
    char* pcSrc = (char*)pSampleBuffer;
    int* piDst = (int*)pi32bBuffer + _uiCurDSmpPos * 2;

    // Mix samples
    for ( unsigned int s = 0; s < iMaxSamples; s++ )
    {
        // Process sample
        int iL = pcSrc[0] * iLV;
        iL >>= 7;
        int iR = pcSrc[1] * iRV;
        iR >>= 7;
        pcSrc += 2;

        // Store sample
        piDst[0] += iL;
        piDst[1] += iR;
        piDst += 2;
    }

    return (iMaxSamples);
}

void* CSoundMixer::pGetBuffer ()
{
    return(pBuffer);
}

unsigned int CSoundMixer::uiGetBufferSize ()
{
    return(uiBuffSize);
}

void CSoundMixer::Finish ()
{
    if ( pBuffer ) mFree(pBuffer);
    if ( pSampleBuffer ) mFree(pSampleBuffer);
    if ( pi32bBuffer ) mFree(pi32bBuffer);
}

// Additional Declarations
void CSoundMixer::PostProcess()
{
    // Clamp all the buffer values
    int iSmp;
    int iMaxSmp = uiBuffSamples << 1;                    // uiBuffSamples shorts
    int* piSSmp = pi32bBuffer;
    short* psDSmp = (short*)pBuffer;

    for ( iSmp = 0; iSmp < iMaxSmp; iSmp++ )
    {
        if ( *piSSmp < -32768 ) *psDSmp = -32768;
        else
        if ( *piSSmp > 32767 ) *psDSmp = 32767;
        else
            *psDSmp = *piSSmp;

        *psDSmp++;
        *piSSmp++;
    }

    // Clear the auxiliary buffer
    memset(pi32bBuffer,0,uiBuffSamples * 2 * 4);
}
