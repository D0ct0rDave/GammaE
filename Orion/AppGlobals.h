// ----------------------------------------------------
#ifndef AppGlobalsH
#define AppGlobalsH
// ----------------------------------------------------
#include "GammaE.h"

extern bool bFinishApp;
// --------------------------------------------------------
// Engine3D
// --------------------------------------------------------
extern CE3D_OGL_Win_Renderer		goRenderer;
extern float						gfDeltaT;
extern unsigned int					guiScrWidth;
extern unsigned int					guiScrHeight;

// --------------------------------------------------------
// Sound System
// --------------------------------------------------------
extern CSoundRenderer_DSound		goSndRenderer;

// --------------------------------------------------------
// Other variables
// --------------------------------------------------------
#ifndef MAX_CHARS
#define MAX_CHARS 256
#endif

extern char gszMapFileName[MAX_CHARS];

// ----------------------------------------------------
#endif
// ----------------------------------------------------