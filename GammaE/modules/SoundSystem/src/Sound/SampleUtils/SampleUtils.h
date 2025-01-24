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
#ifndef SampleUtilsH
#define SampleUtilsH
// -----------------------------------------------------------------------------
#include "../CSample.h"
CSample* SampleUtils_LoadSample(char* _szFilename,bool _bStream);
void SampleUtils_ConvertSample(CSample* _pSample,int _iChannels,int _iBits,int _iSampleRate);
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
