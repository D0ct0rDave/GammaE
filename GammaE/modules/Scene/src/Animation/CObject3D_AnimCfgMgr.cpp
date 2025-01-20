//## begin module%3BA2966A028A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA2966A028A.cm

//## begin module%3BA2966A028A.cp preserve=no
//## end module%3BA2966A028A.cp

//## Module: CObject3D_AnimCfgMgr%3BA2966A028A; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimCfgMgr.cpp

//## begin module%3BA2966A028A.additionalIncludes preserve=no
//## end module%3BA2966A028A.additionalIncludes

//## begin module%3BA2966A028A.includes preserve=yes
//## end module%3BA2966A028A.includes

// CObject3D_AnimCfgMgr
#include "Scene\Animation\CObject3D_AnimCfgMgr.h"
//## begin module%3BA2966A028A.additionalDeclarations preserve=yes
#include <string.h>
//## end module%3BA2966A028A.additionalDeclarations


// Class CObject3D_AnimCfgMgr 





CObject3D_AnimCfgMgr::CObject3D_AnimCfgMgr()
  //## begin CObject3D_AnimCfgMgr::CObject3D_AnimCfgMgr%.hasinit preserve=no
      : iNumAnimObjs(0), iMaxAnimObjs(0), pAnimObjs(NULL), iCurrentFrame(0)
  //## end CObject3D_AnimCfgMgr::CObject3D_AnimCfgMgr%.hasinit
  //## begin CObject3D_AnimCfgMgr::CObject3D_AnimCfgMgr%.initialization preserve=yes
  //## end CObject3D_AnimCfgMgr::CObject3D_AnimCfgMgr%.initialization
{
  //## begin CObject3D_AnimCfgMgr::CObject3D_AnimCfgMgr%.body preserve=yes
	TypeID = e3DObj_AnimCfgMgr;
  //## end CObject3D_AnimCfgMgr::CObject3D_AnimCfgMgr%.body
}


CObject3D_AnimCfgMgr::~CObject3D_AnimCfgMgr()
{
  //## begin CObject3D_AnimCfgMgr::~CObject3D_AnimCfgMgr%.body preserve=yes
  //## end CObject3D_AnimCfgMgr::~CObject3D_AnimCfgMgr%.body
}



//## Other Operations (implementation)
void CObject3D_AnimCfgMgr::Init (int _iMaxAnimObjs)
{
  //## begin CObject3D_AnimCfgMgr::Init%1000511359.body preserve=yes
	iMaxAnimObjs = _iMaxAnimObjs;
	iNumAnimObjs = 0;
	pAnimObjs = new CObject3D_AnimCfg *[iMaxAnimObjs];
	memset(pAnimObjs,0,4*iMaxAnimObjs);
  //## end CObject3D_AnimCfgMgr::Init%1000511359.body
}

void CObject3D_AnimCfgMgr::SetFrameAnim (int _iFrameAnim)
{
  //## begin CObject3D_AnimCfgMgr::SetFrameAnim%1000511360.body preserve=yes
	assert (pAnimObjs && "NULL Animation object array");
	
	iCurrentFrame = _iFrameAnim;

	for(int iObj=0;iObj<iNumAnimObjs;iObj++)
		pAnimObjs[iObj]->SetFrameAnim(_iFrameAnim);
  //## end CObject3D_AnimCfgMgr::SetFrameAnim%1000511360.body
}

CGraphBV* CObject3D_AnimCfgMgr::poGetBoundVol ()
{
  //## begin CObject3D_AnimCfgMgr::poGetBoundVol%1000511361.body preserve=yes
	assert (pAnimObjs && "NULL Animation object array");
	
	// WARNING!: Esto no es correcto!
	return ( pAnimObjs[iCurrentFrame]->poGetBoundVol() );

  //## end CObject3D_AnimCfgMgr::poGetBoundVol%1000511361.body
}

void CObject3D_AnimCfgMgr::ComputeBoundVol ()
{
  //## begin CObject3D_AnimCfgMgr::ComputeBoundVol%1000511362.body preserve=yes
	assert (pAnimObjs && "NULL Animation object array");

	for(int iObj=0;iObj<iNumAnimObjs;iObj++)
		pAnimObjs[iObj]->ComputeBoundVol();
  //## end CObject3D_AnimCfgMgr::ComputeBoundVol%1000511362.body
}

void CObject3D_AnimCfgMgr::Render ()
{
  //## begin CObject3D_AnimCfgMgr::Render%1000511363.body preserve=yes
	assert (pAnimObjs && "NULL Animation object array");

	for(int iObj=0;iObj<iNumAnimObjs;iObj++)
		pAnimObjs[iObj]->Render();
  //## end CObject3D_AnimCfgMgr::Render%1000511363.body
}

int CObject3D_AnimCfgMgr::AddAnimObj (CObject3D_AnimCfg *_pAnimObj)
{
  //## begin CObject3D_AnimCfgMgr::AddAnimObj%1000511364.body preserve=yes
	assert (pAnimObjs && "NULL Animation object array");
	
	pAnimObjs[iNumAnimObjs++] = _pAnimObj;
	_pAnimObj->Reference();

	return (iNumAnimObjs-1);
  //## end CObject3D_AnimCfgMgr::AddAnimObj%1000511364.body
}

// Additional Declarations
  //## begin CObject3D_AnimCfgMgr%3BA2966A028A.declarations preserve=yes
  //## end CObject3D_AnimCfgMgr%3BA2966A028A.declarations

//## begin module%3BA2966A028A.epilog preserve=yes
//## end module%3BA2966A028A.epilog
