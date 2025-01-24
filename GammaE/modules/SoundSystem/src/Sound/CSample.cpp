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

#include "GammaE_Mem.h"
#include <string.h>

// -----------------------------------------------------------------------------
#include "Sound\CSample.h"

// -----------------------------------------------------------------------------

CSample::CSample()

    : iChannels(0), iBits(0), iSRate(0), iSamples(0), iHandle(-1)
{
}

CSample::~CSample()
{
    Finish();
}

// -----------------------------------------------------------------------------

int CSample::iGetData(int _iOfs,void* _pBuffer,int _iSize)
{
    return(0);
}
