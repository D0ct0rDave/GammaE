
// ----------------------------------------------------------------------
#include "CGameGlobals.h"

// ----------------------------------------------------------------------
int giDisableAI;

/*
char *gszResources[] =
{	
	"data/sprites/Untitled-2.tga",
	"data/sprites/Untitled-4.tga",
	"data/models/enemies/boss/antiglobox/antiglobox.geo",	
	"data/models/enemies/boss/pollo/pollo.geo",
	"data/models/players/Narci/Narciso.geo",
	""
};
*/
char *gszResources[] =
{	
	// "data/Models/Players/cockpit/cockpit.g",
	// "data/Models/Enemies/Brain Slug/BrainSlug.g",
	"data/Models/Players/MarvinPig/MarvinPig.g",
	
	
	
	"data/Models/enemies/moggle/moggle.g",
	"data/Models/Enemies/Egg/Egg.g",
	"data/Models/enemies/foot/foot.g",
	// "data/Models/Players/sfighter/SFighter.g",	
	"data/Models/enemies/SimpleEnemy1/enemy1.g",
	"data/Models/enemies/MrEye/MrEye.g",
	
	"data/models/enemies/antiglobox/antiglobox.geo",	
	"data/models/enemies/pollo/pollo.geo",
	"data/models/players/Narci/Narciso.geo",
	""
};

char *gszPlayerModel[] =
{	
	"data/sprites/Untitled-2.tga",
	"data/Models/objects/porteria.geo",
	"data/models/enemies/boss/antiglobox/antiglobox.geo",	
	"data/models/enemies/boss/pollo/pollo.geo",
	"data/models/players/Narci/Narciso.geo",
	""
};

CPlayer*	gpoPlayer[MAX_PLAYERS] = {NULL,NULL,NULL,NULL};
CCamera*	gpoCamera[MAX_PLAYERS] = {NULL,NULL,NULL,NULL};

int			giCurPlayer  = 0;
float		gfGlobalTime = 0.0f;
float		gfLastGlobalTime = 0.0f;

float		gfMapCursor = 0.0f;
float		gfMapCursorDelta = 0.0f;
// ----------------------------------------------------------------------
MTH_CPoint3 oWorldPos(float _fCursor,float _fHeight)
{
	// Collision
	/*
	MTH_CMat4x4 oMat = gpoMap->m_oPath.oGetRefSys(_fCursor);
	MTH_CPoint3 oPos,oUp;
	oMat.GetCol3(&oPos);
	oMat.GetCol1(&oUp);

	oPos += oUp * _fHeight;

	return(oPos);
	*/
	MTH_CPoint3 oPos (_fCursor,_fHeight,0.0f);
	
	return ( oPos );
}
// ----------------------------------------------------------------------