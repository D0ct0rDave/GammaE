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
#include "SoundRender\SoundDrivers\SndDrv_OpenAL\CSoundEmiter_OpenAL.h"

// -----------------------------------------------------------------------------

CSoundEmiter_OpenAL::CSoundEmiter_OpenAL()
{
    uiSourceHandler = 0;
    bPlaying = false;
}

CSoundEmiter_OpenAL::~CSoundEmiter_OpenAL()
{
}

// -----------------------------------------------------------------------------
