//## begin module%3B7707F7000C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7707F7000C.cm

//## begin module%3B7707F7000C.cp preserve=no
//## end module%3B7707F7000C.cp

//## Module: CBackgroundMgr%3B7707F7000C; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\CBackgroundMgr.cpp

//## begin module%3B7707F7000C.additionalIncludes preserve=no
//## end module%3B7707F7000C.additionalIncludes

//## begin module%3B7707F7000C.includes preserve=yes
#include "Game/Globals/Globals.h"
//## end module%3B7707F7000C.includes

// CBackgroundMgr
#include "Game\GameScene\CBackgroundMgr.h"
//## begin module%3B7707F7000C.additionalDeclarations preserve=yes
//## end module%3B7707F7000C.additionalDeclarations


// Class CBackgroundMgr 


CBackgroundMgr::CBackgroundMgr()
  //## begin CBackgroundMgr::CBackgroundMgr%.hasinit preserve=no
  //## end CBackgroundMgr::CBackgroundMgr%.hasinit
  //## begin CBackgroundMgr::CBackgroundMgr%.initialization preserve=yes
  //## end CBackgroundMgr::CBackgroundMgr%.initialization
{
  //## begin CBackgroundMgr::CBackgroundMgr%.body preserve=yes
	Init(1);
	Reference();
	bFrustumTest = false;
  //## end CBackgroundMgr::CBackgroundMgr%.body
}


CBackgroundMgr::~CBackgroundMgr()
{
  //## begin CBackgroundMgr::~CBackgroundMgr%.body preserve=yes
  //## end CBackgroundMgr::~CBackgroundMgr%.body
}



//## Other Operations (implementation)
void CBackgroundMgr::Render ()
{
  //## begin CBackgroundMgr::Render%997655857.body preserve=yes
	gpoE3DRenderer->SetFogPars(eE3D_FM_None,0,0,0,NULL);
	gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Disable);

	CObject3D_Node::Render();
	
	gpoE3DRenderer->SetFogPars(eE3D_FM_Last,0,0,0,NULL);
	gpoE3DRenderer->SetZPars(eE3D_ZTF_Last,eE3D_ZW_Last);
  //## end CBackgroundMgr::Render%997655857.body
}

void CBackgroundMgr::SetBackground (CObject3D* _poBG)
{
  //## begin CBackgroundMgr::SetBackground%997655859.body preserve=yes
	SetObject(_poBG,0);
  //## end CBackgroundMgr::SetBackground%997655859.body
}

// Additional Declarations
  //## begin CBackgroundMgr%3B7707F7000C.declarations preserve=yes
  //## end CBackgroundMgr%3B7707F7000C.declarations

//## begin module%3B7707F7000C.epilog preserve=yes
//## end module%3B7707F7000C.epilog
