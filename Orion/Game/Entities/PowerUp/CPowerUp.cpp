#include "CPowerUp.h"

#include "Game/GameGlobals/GameGlobals.h"
#include "Game/Scene/Models/COrionObjBookmark.h"


CPowerUp::CPowerUp()
{
	CVect3 oOrigin(0,0,0);
	iEntTypeID = OETI_POWERUP;
	
	// Se crea un objecto grafico, que aunque no sea el modelo correcto,
	// luego se sustituye
	Setup(OETI_POWERUP,0,OOBE_POWERUP,oOrigin);
}

CPowerUp::~CPowerUp()
{
}

void CPowerUp::SetupPowerUp(int _iPWType,CVect3 &_roPos,COrionEnt *_poParent)
{
	iEntSubType = _iPWType;
	poParent    = _poParent;
	eState	    = OOST_ALIVE;
	bActive     = true;
	
	// Setup object and reference system
	iModelIdx = _iPWType + OOBE_POWERUP;
	poTransf->SetObject( COrionObjBookmark::gObjBookmark[iModelIdx]->poModel );
	poTransf->SetPos (_roPos);
	
	oCol.oPos.Assign(_roPos);
	oCol.oOldPos.Assign(_roPos);
}