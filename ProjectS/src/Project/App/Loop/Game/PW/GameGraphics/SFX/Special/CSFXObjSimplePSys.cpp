#include "CSFXObjSimplePSys.h"
#include "sfx.h"
// --------------------------------------------------------------------------------------------------------
#define		MAXPSYS				256
// --------------------------------------------------------------------------------------------------------
CSFXObjSimplePSys::CSFXObjSimplePSys()
{
	sID  = -1;
	sPID = -1;
}
// --------------------------------------------------------------------------------------------------------
CSFXObjSimplePSys::~CSFXObjSimplePSys()
{
}
// --------------------------------------------------------------------------------------------------------
void CSFXObjSimplePSys::Init(MTH_CPoint3 &_oPos,int _iType,bool _bPerturb,float _fLifeTime)
{
	CSFXObject::Init(_oPos);
	sID  = CPSysMgr::iAddPSys(_iType,_oPos,_fLifeTime,PSYSMGR_DEFVISDIST);	
//	sPID = _bPerturb?CPerturbMgr::iAdd(0,&oPos,0.5f,0.008f):-1;
}
// --------------------------------------------------------------------------------------------------------
void CSFXObjSimplePSys::Enable()
{
	CSFXObject::Enable();
	CPSysMgr::Enable(sID);
//	if (sPID>-1) CPerturbMgr::Enable(sPID);
}
// --------------------------------------------------------------------------------------------------------
void CSFXObjSimplePSys::Disable()
{
	CSFXObject::Disable();
	CPSysMgr::Disable(sID);
//	if (sPID>-1) CPerturbMgr::Disable(sPID);
}
// --------------------------------------------------------------------------------------------------------
void CSFXObjSimplePSys::Pos(MTH_CPoint3 &_oPos)
{
	CSFXObject::Pos(_oPos);
	CPSysMgr::UpdatePSys(sID,m_oPos );
//	if (sPID>-1) CPerturbMgr::Update(sID,oPos);
}
// --------------------------------------------------------------------------------------------------------