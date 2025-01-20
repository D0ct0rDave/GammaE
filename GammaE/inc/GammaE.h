//-----------------------------------------------------------------------------
/*! \class GammaE_Engine
 *  \brief GammaE Engine
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
//-----------------------------------------------------------------------------
#ifndef GammaE
#define GammaE
//-----------------------------------------------------------------------------

/** @defgroup GammaE_Mem GammaE engine Memory module */
#include "GammaE_Mem.h"
/** @} */

/** @defgroup GammaE_Misc GammaE engine General Purpose Functionality module */
#include "GammaE_Misc.h"
/** @} */

/** @defgroup GammaE_FileSys GammaE engine File System module */
#include "GammaE_FileSys.h"
/** @} */

/** @defgroup GammaE_Math GammaE engine Math module */
#include "GammaE_Math.h"
/** @} */

/** @defgroup GammaE_Input GammaE engine Input module */
#include "GammaE_Input.h"
/** @} */

#ifndef GAMMAE_DISABLE_3D
/** @defgroup GammaE_E3D GammaE engine 3D Rendering module */
#include "GammaE_E3D.h"
/** @} */

/** @defgroup GammaE_Scene GammaE engine Scene Management module */
#include "GammaE_Scene.h"
/** @} */

/** @defgroup GammaE_SceneUtils GammaE engine Scene Utils module */
#include "GammaE_SceneUtils.h"
/** @} */

/** @defgroup GammaE_SceneObjects GammaE engine Prefab Scene Objects module */
#include "GammaE_SceneObjects.h"
/** @} */

/** @defgroup GammaE_Sfx GammaE engine Special FX module */
#include "GammaE_Sfx.h"
/** @} */

/** @defgroup GammaE_Terrain GammaE engine Terrain Engine module */
#include "GammaE_Terrain.h"
/** @} */

/** @defgroup GammaE_TerrainData GammaE engine Terrain Engine Data module */
#include "GammaE_TerrainData.h"
/** @} */

/** @defgroup GammaE_Collision GammaE engine Collision Engine module */
#include "GammaE_Collision.h"
/** @} */

#endif

#ifndef GAMMAE_DISABLE_SOUND
/** @defgroup GammaE_SoundSystem GammaE engine Sound Rendering module */
#include "GammaE_SoundSystem.h"
/** @} */
#endif

#ifndef GAMMAE_DISABLE_NETWORK
/** @defgroup GammaE_Network GammaE engine Networking module */
#include "GammaE_Network.h"
/** @} */
#endif

/** @defgroup GammaE_AI GammaE engine Artificial Intelligence module */
#include "GammaE_AI.h"
/** @} */

/** @defgroup GammaE_Game GammaE engine Game Facilities module */
#include "GammaE_Game.h"
/** @} */

//---------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
           