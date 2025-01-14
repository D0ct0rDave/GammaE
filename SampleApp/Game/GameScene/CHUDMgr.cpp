//## begin module%3B770E250350.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B770E250350.cm

//## begin module%3B770E250350.cp preserve=no
//## end module%3B770E250350.cp

//## Module: CHUDMgr%3B770E250350; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\CHUDMgr.cpp

//## begin module%3B770E250350.additionalIncludes preserve=no
//## end module%3B770E250350.additionalIncludes

//## begin module%3B770E250350.includes preserve=yes
#include "Game/Globals/Globals.h"
//## end module%3B770E250350.includes

// CHUDMgr
#include "Game\GameScene\CHUDMgr.h"
//## begin module%3B770E250350.additionalDeclarations preserve=yes
//## end module%3B770E250350.additionalDeclarations


// Class CHUDMgr 


CHUDMgr::CHUDMgr()
  //## begin CHUDMgr::CHUDMgr%.hasinit preserve=no
  //## end CHUDMgr::CHUDMgr%.hasinit
  //## begin CHUDMgr::CHUDMgr%.initialization preserve=yes
  //## end CHUDMgr::CHUDMgr%.initialization
{
  //## begin CHUDMgr::CHUDMgr%.body preserve=yes
	Init(1);
	Reference();
	bFrustumTest = false;
  //## end CHUDMgr::CHUDMgr%.body
}


CHUDMgr::~CHUDMgr()
{
  //## begin CHUDMgr::~CHUDMgr%.body preserve=yes
  //## end CHUDMgr::~CHUDMgr%.body
}



//## Other Operations (implementation)
void CHUDMgr::Render ()
{
  //## begin CHUDMgr::Render%997655862.body preserve=yes
	gpoE3DRenderer->SetFogPars(eE3D_FM_None,0,0,0,NULL);
	gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Disable);

	CObject3D_Node::Render();
	
	gpoE3DRenderer->SetFogPars(eE3D_FM_Last,0,0,0,NULL);
	gpoE3DRenderer->SetZPars(eE3D_ZTF_Last,eE3D_ZW_Last);
  //## end CHUDMgr::Render%997655862.body
}

void CHUDMgr::SetHUD (CObject3D* _pHUD)
{
  //## begin CHUDMgr::SetHUD%997655863.body preserve=yes
	iAddObject(_pHUD);	
  //## end CHUDMgr::SetHUD%997655863.body
}

// Additional Declarations
  //## begin CHUDMgr%3B770E250350.declarations preserve=yes
  //## end CHUDMgr%3B770E250350.declarations

//## begin module%3B770E250350.epilog preserve=yes
//## end module%3B770E250350.epilog
