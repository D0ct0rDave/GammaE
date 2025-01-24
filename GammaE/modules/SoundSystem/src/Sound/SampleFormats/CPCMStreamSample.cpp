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

#include "GammaE_Misc.h"
#include <sndfile.h>

// -----------------------------------------------------------------------------
#include "Sound\SampleFormats\CPCMStreamSample.h"

// -----------------------------------------------------------------------------

CPCMStreamSample::CPCMStreamSample()
{
}

CPCMStreamSample::~CPCMStreamSample()
{
}

// -----------------------------------------------------------------------------

int CPCMStreamSample::iGetData(int _iOfs,void* _pBuffer,int _iSize)
{
    off_t iOfs = sf_seek( (SNDFILE*)pFile,_iOfs,SEEK_SET );

    if ( iOfs != _iOfs )
    {
        int a = 0;
        // chungo
    }

    int iSampleSize = iChannels * (iBits >> 3);
    int iRead = sf_read_raw( (SNDFILE*)pFile,_pBuffer,_iSize * iSampleSize );

    return (iRead / iSampleSize);
}

void CPCMStreamSample::Init(char* _szFilename)
{
    SF_INFO SInfo;
    CSample* pSample;

    pFile = (void*)sf_open(_szFilename,SFM_READ, &SInfo);
    if ( !pFile )
    {
        CGSystemLC::I()->Error("Unable to open sample file %s",_szFilename);
        return;
    }
    // 17-Feb-2012: DMC
    // iBits	  = SInfo.pcmbitwidth;
    iBits = 16;
    iChannels = SInfo.channels;
    iSamples = (int)SInfo.frames;
    iSRate = SInfo.samplerate;

    iHandle = -1;
}

void CPCMStreamSample::Finish()
{
    if ( pFile )
        sf_close( (SNDFILE*)pFile );
}
