#include "AppGlobals.h"

bool bFinishApp = false;
// --------------------------------------------------------
// Engine 3D
// --------------------------------------------------------
#include "E3D/Drivers/OGL/CE3D_OGL_Win_Renderer.h"
CE3D_OGL_Win_Renderer			goRenderer;
float							gfDeltaT;

unsigned int					guiScrWidth;
unsigned int					guiScrHeight;

// --------------------------------------------------------
// Sound System
// --------------------------------------------------------
#include "SoundSystem/SoundRender/SoundDrivers/SndDrv_DirectSound/CSoundRenderer_DSound.h"

CSoundRenderer_DSound		goSndRenderer;
CSoundReceiver				goSndRcv;

// --------------------------------------------------------
// Other variables
// --------------------------------------------------------
char gszMapFileName[MAX_CHARS];
