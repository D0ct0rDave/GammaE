//## begin module%3B65CB11028A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B65CB11028A.cm

//## begin module%3B65CB11028A.cp preserve=no
//## end module%3B65CB11028A.cp

//## Module: CGameScene%3B65CB11028A; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\CGameScene.cpp

//## begin module%3B65CB11028A.additionalIncludes preserve=no
//## end module%3B65CB11028A.additionalIncludes

//## begin module%3B65CB11028A.includes preserve=yes
//## end module%3B65CB11028A.includes

// CGameScene
#include "Game\CGameScene.h"
//## begin module%3B65CB11028A.additionalDeclarations preserve=yes
CGameScene GameScene;
//## end module%3B65CB11028A.additionalDeclarations


// Class CGameScene 


CGameScene::CGameScene()
  //## begin CGameScene::CGameScene%.hasinit preserve=no
  //## end CGameScene::CGameScene%.hasinit
  //## begin CGameScene::CGameScene%.initialization preserve=yes
  //## end CGameScene::CGameScene%.initialization
{
  //## begin CGameScene::CGameScene%.body preserve=yes
	Init(3);
	
	iAddObject(BackgroundMgr);
	iAddObject(ParticleSystemMgr);
	
	Scene = new CObject3D_Node;
  //## end CGameScene::CGameScene%.body
}


CGameScene::~CGameScene()
{
  //## begin CGameScene::~CGameScene%.body preserve=yes
  //## end CGameScene::~CGameScene%.body
}



//## Other Operations (implementation)
void CGameScene::InitScene (int iMaxObjs)
{
  //## begin CGameScene::InitScene%997655858.body preserve=yes
	Scene->Init(iMaxObjs);
  //## end CGameScene::InitScene%997655858.body
}

// Additional Declarations
  //## begin CGameScene%3B65CB11028A.declarations preserve=yes
  //## end CGameScene%3B65CB11028A.declarations

//## begin module%3B65CB11028A.epilog preserve=yes
//## end module%3B65CB11028A.epilog
