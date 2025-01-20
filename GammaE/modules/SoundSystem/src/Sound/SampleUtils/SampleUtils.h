//-----------------------------------------------------------------------------
#ifndef SampleUtilsH
#define SampleUtilsH
//-----------------------------------------------------------------------------
#include "../CSample.h"
CSample *SampleUtils_LoadSample(char *_szFilename,bool _bStream);
void SampleUtils_ConvertSample(CSample *_pSample,int _iChannels,int _iBits,int _iSampleRate);
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
