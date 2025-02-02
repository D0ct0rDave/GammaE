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
#include "SoundRender\SoundMixer\CSoundMixPars.h"

// -----------------------------------------------------------------------------

CSoundMixPars::CSoundMixPars()

    : fLVol(1.0f), fRVol(1.0f), iSPos(0), iCLayer(0), bLUnlock(false), bEnd(false)
{
}

CSoundMixPars::~CSoundMixPars()
{
}
