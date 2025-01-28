//## begin module%3B65CB11028A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B65CB11028A.cm

//## begin module%3B65CB11028A.cp preserve=no
//## end module%3B65CB11028A.cp

//## Module: CGameScene%3B65CB11028A; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\CGameScene.cpp

//## begin module%3B65CB11028A.additionalIncludes preserve=no
//## end module%3B65CB11028A.additionalIncludes

//## begin module%3B65CB11028A.includes preserve=yes
#include "GammaE.h"
#include "App/Loop/Game/CGameGlobals.h"
#include "Video/CVideo.h"
//## end module%3B65CB11028A.includes

// CGameScene
#include "CGameScene.h"
//## begin module%3B65CB11028A.additionalDeclarations preserve=yes
CObject3D_Node CGameScene::m_oList(1000);
//## end module%3B65CB11028A.additionalDeclarations


// Class CGameScene 




CGameScene::CGameScene()
  //## begin CGameScene::CGameScene%.hasinit preserve=no
  //## end CGameScene::CGameScene%.hasinit
  //## begin CGameScene::CGameScene%.initialization preserve=yes
  //## end CGameScene::CGameScene%.initialization
{
  //## begin CGameScene::CGameScene%.body preserve=yes
  //## end CGameScene::CGameScene%.body
}


CGameScene::~CGameScene()
{
  //## begin CGameScene::~CGameScene%.body preserve=yes
  //## end CGameScene::~CGameScene%.body
}



//## Other Operations (implementation)
void CGameScene::Render ()
{
  //## begin CGameScene::Render%997655866.body preserve=yes
	CGRenderer::I()->BeginRender();

		// Camera viewpoint
		gameGlobals.m_oCamera.PreRender();

			CGRenderer::I()->DisableFrustumCulling();

				// CGRenderer::I()->EnableDefferredMode();

					// Render Scene Objects
					m_oList.Render();

					// Render the entities
					CGGEntityRenderMgr::I()->Render();

				// CGRenderer::I()->DisableDefferredMode();

			CGRenderer::I()->EnableFrustumCulling();

		gameGlobals.m_oCamera.PostRender();

	CGRenderer::I()->EndRender();
  //## end CGameScene::Render%997655866.body
}

// Additional Declarations
  //## begin CGameScene%3B65CB11028A.declarations preserve=yes
  //## end CGameScene%3B65CB11028A.declarations

//## begin module%3B65CB11028A.epilog preserve=yes
//## end module%3B65CB11028A.epilog
