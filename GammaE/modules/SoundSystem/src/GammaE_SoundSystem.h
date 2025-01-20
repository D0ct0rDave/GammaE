//---------------------------------------------------------------------------
#ifndef GammaE_SoundSystemH
#define GammaE_SoundSystemH
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Sound Rendering drivers
//---------------------------------------------------------------------------
#include "SoundSystem/SoundRender/CSoundRenderer.h"
#include "SoundSystem/SoundRender/CSoundEmiter.h"
#include "SoundSystem/SoundRender/CSoundReceiver.h"

// BASS
#ifdef _BASS_12_
	#include "SoundSystem/SoundRender/SoundDrivers/SndDrv_Bass/CSoundRenderer_Bass.h"	
#else
	#ifdef _DSOUND_
		#include "SoundSystem/SoundRender/SoundDrivers/SndDrv_DirectSound/CSoundRenderer_DSound.h"
	#endif
#endif


//---------------------------------------------------------------------------
// Sound objects
//---------------------------------------------------------------------------
#include "SoundSystem/Sound/CSample.h"
#include "SoundSystem/Sound/CSampleWH.h"
#include "SoundSystem/Sound/CSound.h"
#include "SoundSystem/Sound/CSoundWH.h"
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------