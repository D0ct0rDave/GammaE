//---------------------------------------------------------------------------
#ifndef SampleUtilsH
#define SampleUtilsH
//---------------------------------------------------------------------------
#include "../CSample.h"
CSample *SampleUtils_LoadSample(char *_Filename);
void SampleUtils_ConvertSample(CSample *_pSample,int _iChannels,int _iBits,int _iSampleRate);
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------