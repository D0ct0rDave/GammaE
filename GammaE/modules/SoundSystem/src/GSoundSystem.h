//-----------------------------------------------------------------------------
#ifndef GSoundSystemH
#define GSoundSystemH
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Sound Rendering drivers
//-----------------------------------------------------------------------------
#include "SoundRender/CSoundRenderer.h"
#include "SoundRender/CSoundEmiter.h"
#include "SoundRender/CSoundReceiver.h"

// #include "SoundSystem/SoundRender/SoundDrivers/SndDrv_Bass/CSoundRenderer_Bass.h"

#ifdef DIRECT_SOUND
#include "SoundRender/SoundDrivers/SndDrv_DirectSound/CSoundRenderer_DSound.h"
#endif

#ifdef _OPENAL_
#include "SoundRender/SoundDrivers/SndDrv_OpenAL/CSoundRenderer_OpenAL.h"
#endif

//-----------------------------------------------------------------------------
// Sound objects
//-----------------------------------------------------------------------------
#include "Sound/CSample.h"
#include "Sound/CSampleWH.h"
#include "Sound/CSound.h"
#include "Sound/CSoundWH.h"

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
