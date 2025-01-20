// -----------------------------------------------------------------------------
#ifndef CGameGlobalsH
#define CGameGlobalsH
// -----------------------------------------------------------------------------

#include "antares.h"

#include "Game/Ents/CPlayer.h"
#include "Game/Ents/CCamera.h"

// -----------------------------------------------------------------------------
#define 	MAX_ENTITIES	1024
#define		MAX_PLAYERS 4

extern CPlayer*	gpoPlayer[MAX_PLAYERS];
extern CCamera*	gpoCamera[MAX_PLAYERS];
extern char*	gszPlayerModel[];

// -----------------------------------------------------------------------------

typedef enum  {

	GR_PLAYER,
	GR_MOGGLE,
	GR_EGG,	
	GR_FOOT,

	GR_MREYE,

	GR_NUMRESOURCES

} EGraphicResources;

extern char*	gszResources[];

// -----------------------------------------------------------------------------

extern int		giCurPlayer;
extern int		giDisableAI;
extern float	gfGlobalTime;
extern float	gfLastGlobalTime;

extern float	gfMapCursor;
extern float	gfMapCursorDelta;
// -----------------------------------------------------------------------------
MTH_CPoint3 oWorldPos(float _fCursor,float _fHeight);

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------