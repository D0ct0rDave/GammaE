#include "GammaE.h"
#include "App/Loop/Game/CGameGlobals.h"
#include "Video/CVideo.h"

#include "CGameScene.h"
// ----------------------------------------------------------------------------
CGSceneGroup CGameScene::m_oList(1000);
// ----------------------------------------------------------------------------
void CGameScene::Init()
{
	gameGlobals.m_oCamera.iAddObject(&m_oList);
}
// ----------------------------------------------------------------------------
void CGameScene::Render ()
{
	CGRenderer::I()->BeginRender();

		// Camera viewpoint

		// DMC: Refactor
		// gameGlobals.m_oCamera.PreRender();

			CGRenderer::I()->DisableFrustumCulling();

				// CGRenderer::I()->EnableDefferredMode();

					// Render Scene Objects
					CGSCNVRenderer::I()->Render(&gameGlobals.m_oCamera);

					// Render the entities
					CGGEntityRenderMgr::I()->Render();

				// CGRenderer::I()->DisableDefferredMode();

			CGRenderer::I()->EnableFrustumCulling();
		
		// DMC: Refactor
		// gameGlobals.m_oCamera.PostRender();

	CGRenderer::I()->EndRender();
}
// ----------------------------------------------------------------------------
