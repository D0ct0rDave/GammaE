#include "CWorldEnt.h"
#include "Game/GameGlobals/GameGlobals.h"
#include "Game/Scene/Models/COrionObjBookmark.h"

CWorldEnt::CWorldEnt ()
{
	CVect3 oOrigin(0,0,0);

	Setup(OETI_WORLD,0,OOBE_MAP,oOrigin);

	poParent    = NULL;
	eState	    = OOST_ALIVE;
	bActive     = true;
}

CWorldEnt::~CWorldEnt ()
{
}