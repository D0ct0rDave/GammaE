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
#include "GammaE_Mem.h"
#include "GammaE_misc.h"

#include "SampleUtils.h"

#include "Sound/SampleFormats/CPCMStreamSample.h"
#include "Sound/SampleFormats/CPCMSample.h"
// ----------------------------------------------------------------------------------
inline int SampleUtils_GetSampleOffset(int _iSampleNum,int _iChannels,int _iBits)
{
    return (_iSampleNum * (_iBits >> 3) * _iChannels);
}
// ----------------------------------------------------------------------------------
// Convert any sample type to 16 bit Stereo
// ----------------------------------------------------------------------------------
void SampleUtils_ConvertTo16BitStereo(void* _pIn,void* _pOut,int _iInCh,int _iInBits)
{
    unsigned char* pucI = (unsigned char*)_pIn;
    unsigned char* pucOSt = (unsigned char*)_pOut;

    switch ( _iInBits )
    {
        case 8: switch ( _iInCh )
        {
            case 1:
            {
                short sS = pucI[0] * 255;
                char* pcS = (char*)&sS;

                pucOSt[0] = pcS[0];
                pucOSt[1] = pcS[1];
                pucOSt[2] = pcS[0];
                pucOSt[3] = pcS[1];
            }
            break;

            case 2:
            {
                short sSL = pucI[0] * 255;
                short sSR = pucI[1] * 255;
                char* pcSL = (char*)&sSL;
                char* pcSR = (char*)&sSR;

                pucOSt[0] = pcSL[0];
                pucOSt[1] = pcSL[1];
                pucOSt[2] = pcSR[0];
                pucOSt[3] = pcSR[1];
            }
            break;
        }
        break;

        case 16: switch ( _iInCh )
        {
            case 1: pucOSt[0] = pucI[0];
            pucOSt[1] = pucI[1];
            pucOSt[2] = pucI[0];
            pucOSt[3] = pucI[1];
            break;

            case 2: pucOSt[0] = pucI[0];
            pucOSt[1] = pucI[1];
            pucOSt[2] = pucI[2];
            pucOSt[3] = pucI[3];
            break;
        }
        break;
    }
}

// ----------------------------------------------------------------------------------
// Convert from 16 bit Stereo to any sample type
// ----------------------------------------------------------------------------------
void SampleUtils_ConvertFrom16BitStereo(void* _pIn,void* _pOut,int _iOutCh,int _iOutBits)
{
    unsigned char* pucISt = (unsigned char*)_pIn;
    unsigned char* pucO = (unsigned char*)_pOut;

    switch ( _iOutBits )
    {
        case 8: switch ( _iOutCh )
        {
            case 1:                    // Get the left sample the high byte
            pucO[0] = pucISt[1];
            break;

            case 2: pucO[0] = pucISt[1];
            pucO[1] = pucISt[3];
            break;
        }
        break;

        case 16: switch ( _iOutCh )
        {
            case 1: pucO[0] = pucISt[0];
            pucO[1] = pucISt[1];
            break;

            case 2: pucO[0] = pucISt[0];
            pucO[1] = pucISt[1];
            pucO[2] = pucISt[2];
            pucO[3] = pucISt[3];
            break;
        }
        break;
    }
}

// ----------------------------------------------------------------------------------
// Convert from Any sample Type to Any sample type
// ----------------------------------------------------------------------------------
void SampleUtils_ConvertSample(CSample* _pSample,int _iChannels,int _iBits,int _iSampleRate)
{
    /*
       // Create a sample of the desired format
       CSample			pOutSmp;
       unsigned char	*pucOutData;
       unsigned char	*pucInData;

       // Setup variables
       float			fSmpStep;

       char			OutSample[32];
       float			fActSmp  = 0.0f;

       int				iOffset;
       int				iSample;
       int				iNumSamples;

       if ((_iChannels==-1) && (_iBits==-1) && (_iSampleRate == -1)) return;

       if (_iChannels   == -1) _iChannels   = _pSample->iChannels;
       if (_iBits       == -1) _iBits       = _pSample->iBits;
       if (_iSampleRate == -1) _iSampleRate = _pSample->iSRate;

       pOutSmp.Init(_iChannels,_iBits,_iSampleRate,_pSample->iSamples);
       pucInData   = (unsigned char *)_pSample->pData;
       pucOutData  = (unsigned char *) pOutSmp.pData;
       iNumSamples = pOutSmp.iSamples;

        // Convert sample
       fSmpStep = (float)_pSample->iSRate / (float)_iSampleRate;
       fActSmp  = 0;

       for (iSample=0;iSample<iNumSamples;iSample++)
       {
        // Get the proper sample from the input buffer
        iOffset = SampleUtils_GetSampleOffset((int)fActSmp,_pSample->iChannels,_pSample->iBits);
        SampleUtils_ConvertTo16BitStereo(pucInData + iOffset,(void *)OutSample,_pSample->iChannels,_pSample->iBits);

        // Set the proper sample of the output buffer
        iOffset = SampleUtils_GetSampleOffset(iSample,_iChannels,_iBits);
        SampleUtils_ConvertFrom16BitStereo((void *)OutSample,pucOutData + iOffset,_iChannels,_iBits);

        // Update pointers
        fActSmp += fSmpStep;
       }

       // free unneeded data
       mDel _pSample->pData;

       // Setup properties of the recently converted sample
       _pSample->iBits     = pOutSmp.iBits;
       _pSample->iChannels = pOutSmp.iChannels;
       _pSample->iSamples  = pOutSmp.iSamples;
       _pSample->iSRate    = pOutSmp.iSRate;
       _pSample->pData     = pOutSmp.pData;

       // remove the buffer link
       pOutSmp.pData = NULL;
     */
}
// ----------------------------------------------------------------------------------
// Load a sample from a supported format
// ----------------------------------------------------------------------------------
CSample* SampleUtils_LoadSample(char* _szFilename,bool _bStream)
{
    // Suponemos que directamente es un WAV file
    if ( !_bStream )
    {
        CPCMSample* poSample = mNew CPCMSample;
        poSample->Init(_szFilename);

        return(poSample);
    }
    else
    {
        CPCMStreamSample* poSample = mNew CPCMStreamSample;
        poSample->Init(_szFilename);

        return(poSample);
    }
}
// ----------------------------------------------------------------------------------
