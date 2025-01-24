/*! \mainpage GammaE Engine Documentation.
 * \section intro_sec GammaE
 * Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *
 * 1999-2009
 *
 * GammaE License.
 * \htmlonly
 * <center><img src="GammaE_Logo.png"></center>
 * <a href="todo.html">TODO List for the project.</a>
 * \endhtmlonly
 */

// \ image html GammaE_Logo.png // otra manera de poner imágenes en la documentación
// ----------------------------------------------------------------------------
#ifndef GammaEH
#define GammaEH
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

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

#ifndef GAMMAE_NO_3D
/** @defgroup GammaE_E3D GammaE engine 3D Rendering module */
    #include "GammaE_E3D.h"
/** @} */

    #ifndef GAMMAE_NO_SCENE
/** @defgroup GammaE_Scene GammaE engine Scene Management module */
// #include "GammaE_Scene.h"
/** @} */

/** @defgroup GammaE_SceneUtils GammaE engine Scene Utils module */
// #include "GammaE_SceneUtils.h"
/** @} */

/** @defgroup GammaE_SceneObjects GammaE engine Prefab Scene Objects module */
// #include "GammaE_SceneObjects.h"
/** @} */
    #endif

    #ifndef GAMMAE_NO_SFX
/** @defgroup GammaE_Sfx GammaE engine Special FX module */
// #include "GammaE_Sfx.h"
/** @} */
    #endif

    #ifndef GAMMAE_NO_TERRAIN
/** @defgroup GammaE_Terrain GammaE engine Terrain Engine module */
// #include "GammaE_Terrain.h"
/** @} */

/** @defgroup GammaE_TerrainData GammaE engine Terrain Engine Data module */
// #include "GammaE_TerrainData.h"
/** @} */
    #endif

#endif

#ifndef GAMMAE_NO_COLLISION
/** @defgroup GammaE_Collision GammaE engine Collision Engine module */
// #include "GammaE_Collision.h"
/** @} */
#endif

#ifndef GAMMAE_NO_SOUND
/** @defgroup GammaE_SoundSystem GammaE engine Sound Rendering module */
// #include "GammaE_SoundSystem.h"
/** @} */
#endif

#ifndef GAMMAE_NO_NETWORK
/** @defgroup GammaE_Network GammaE engine Networking module */
    #include "GammaE_Network.h"
/** @} */
#endif

#ifndef GAMMAE_NO_AI
/** @defgroup GammaE_AI GammaE engine Artificial Intelligence module */
    #include "GammaE_AI.h"
/** @} */
#endif

#ifndef GAMMAE_NO_GAME
/** @defgroup GammaE_Game GammaE engine Game Facilities module */
// #include "GammaE_Game.h"
/** @} */
#endif
// ----------------------------------------------------------------------------
// };
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
