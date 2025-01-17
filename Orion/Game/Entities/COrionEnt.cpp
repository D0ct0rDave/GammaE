#include "COrionEnt.h"
#include "Game/Scene/Models/COrionObjBookmark.h"
// --------------------------------------------------------------
COrionEnt::COrionEnt()
{
	poParent    = NULL;
	poInflictor = NULL;
	bActive		= false;
	eState		= OOST_NONE;
}

COrionEnt::~COrionEnt()
{
}
// --------------------------------------------------------------	
void COrionEnt::Setup(int _iEntTypeID,int _iEntSubType,int _iModelIdx,CVect3 &_roPos)
{
	iEntTypeID = _iEntTypeID;
	iEntSubType= _iEntSubType;
	iModelIdx  = _iModelIdx;

	// Setup graphically the player		
	poTransf = mNew CObject3D_Transf;
	poTransf->SetObject( COrionObjBookmark::gObjBookmark[_iModelIdx]->poModel );
	poTransf->SetPos  (_roPos);
	poTransf->roDir().V3 (0.0f,1.0f,0.0f);
	poTransf->roSide().V3(1.0f,0.0f,0.0f);
	poTransf->roUp().V3(0.0f,0.0f,1.0f);
	poTransf->ComputeBoundVol();

	oCol.poBV = poTransf->poGetBoundVol();
	oCol.oPos.Assign(poTransf->roPos());
	oCol.oOldPos.Assign(oCol.oPos);	
	
	eState = OOST_SPAWN;
}
// --------------------------------------------------------------
void COrionEnt::ProcessCmds(float _fDelta){}
void COrionEnt::Interact	(float _fDelta){}
// --------------------------------------------------------------