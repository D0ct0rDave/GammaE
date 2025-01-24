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
#ifndef GSoundSystemH
#define GSoundSystemH
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Sound Rendering drivers
// -----------------------------------------------------------------------------
#include "SoundRender/CSoundRenderer.h"
#include "SoundRender/CSoundEmiter.h"
#include "SoundRender/CSoundReceiver.h"

// #include "SoundSystem/SoundRender/SoundDrivers/SndDrv_Bass/CSoundRenderer_Bass.h"
#include "SoundRender/SoundDrivers/SndDrv_DirectSound/CSoundRenderer_DSound.h"
#include "SoundRender/SoundDrivers/SndDrv_OpenAL/CSoundRenderer_OpenAL.h"

// -----------------------------------------------------------------------------
// Sound objects
// -----------------------------------------------------------------------------
#include "Sound/CSample.h"
#include "Sound/CSampleWH.h"
#include "Sound/CSound.h"
#include "Sound/CSoundWH.h"

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
