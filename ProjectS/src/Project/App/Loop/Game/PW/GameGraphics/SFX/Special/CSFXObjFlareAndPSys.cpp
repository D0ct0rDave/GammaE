#include "CSFXObjFlareAndPSys.h"
#include "sfx.h"
// --------------------------------------------------------------------------------------------------------
#define		MAXPSYS				256
// --------------------------------------------------------------------------------------------------------
CSFXObjFlareAndPSys::CSFXObjFlareAndPSys()
{
	sPSysID  = -1;
	sFlareID = -1;
}
// --------------------------------------------------------------------------------------------------------
CSFXObjFlareAndPSys::~CSFXObjFlareAndPSys()
{
}
// --------------------------------------------------------------------------------------------------------
void CSFXObjFlareAndPSys::Init(MTH_CPoint3 &_oPos,int _iFType,int _iPType,bool _bPerturb,float _fLifeTime)
{
	CSFXObject::Init(_oPos);
	sPSysID  = CPSysMgr::iAddPSys(_iPType,_oPos,_fLifeTime,PSYSMGR_DEFVISDIST);	
	sFlareID  = CFlareMgr::iAddFlare(_iFType,_oPos,_fLifeTime);
//	sPID = _bPerturb?CPerturbMgr::iAdd(0,&oPos,0.5f,0.008f):-1;
}
// --------------------------------------------------------------------------------------------------------
void CSFXObjFlareAndPSys::Enable()
{
	CSFXObject::Enable();
	CPSysMgr::Enable(sPSysID);
	CFlareMgr::Enable(sFlareID);
//	if (sPID>-1) CPerturbMgr::Enable(sPID);
}
// --------------------------------------------------------------------------------------------------------
void CSFXObjFlareAndPSys::Disable()
{
	CSFXObject::Disable();
	CPSysMgr::Disable(sPSysID);
	CFlareMgr::Disable(sFlareID);
//	if (sPID>-1) CPerturbMgr::Disable(sPID);
}
// --------------------------------------------------------------------------------------------------------
void CSFXObjFlareAndPSys::Pos(MTH_CPoint3 &_oPos)
{
	CSFXObject::Pos(_oPos);
	CPSysMgr::UpdatePSys(sPSysID,m_oPos );
	CFlareMgr::UpdateFlare(sFlareID,m_oPos );
//	if (sPID>-1) CPerturbMgr::Update(sID,oPos);
}
// --------------------------------------------------------------------------------------------------------