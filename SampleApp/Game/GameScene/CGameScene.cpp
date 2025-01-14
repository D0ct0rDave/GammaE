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
#include "Memory/GammaE_Mem.h"
#include "Game/Globals/Globals.h"
#include "Game/Entities/RTMapEntities/CRTMapEntities.h"
//## end module%3B65CB11028A.includes

// CGameScene
#include "Game\GameScene\CGameScene.h"
//## begin module%3B65CB11028A.additionalDeclarations preserve=yes
#define _USE_SHADOWMAP_
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
	gpoE3DRenderer->BeginRender();

		#ifdef _USE_SHADOWMAP_
		CMesh *poMeshes[3];
		CVect3 oLPos;
		CGEMapRoom *poGMRoom;
		if (gpGameMap) // DEBUG
		{
			static int iEnt = 0;
			
			poGMRoom = gpGameMap->aoRooms[gpGameMap->iCurrentRoom];

			CObject3D_Node *poRoom = (CObject3D_Node*)poGMRoom->poScn;

			poMeshes[0] = ((CObject3D_Leaf *)poRoom->poGetObject(0))->poGetMesh();
			poMeshes[1] = ((CObject3D_Leaf *)poRoom->poGetObject(1))->poGetMesh();
			poMeshes[2] = ((CObject3D_Leaf *)poRoom->poGetObject(2))->poGetMesh();

			if (poGMRoom->iNumEnts)
			{				
				// int iLoop = 0;
				// iEnt = (iEnt+1) % gpGameMap->aoRooms[0]->iNumEnts;
				//while ((poGMRoom->poEnts[iEnt]->eClass != eMapEnt_Light) && (iLoop <poGMRoom->iNumEnts))
				// {					
				//	iEnt = (iEnt+1) % gpGameMap->aoRooms[0]->iNumEnts;	
				// }

				if (poGMRoom->poEnts[iEnt]->eClass == eMapEnt_Light)
					oLPos = ((CMapEnt_Light *)poGMRoom->poEnts[iEnt])->oPos;
				else
					oLPos.V3(0.0f,0.0f,0.0f);
			}
		}
		#endif

		// Camera viewpoint
		gCamera.PreRender();

			#ifdef _USE_SHADOWMAP_
			if ((gpGameMap) && (gPlayerNode))// DEBUG
				gShadowCaster.Setup(oLPos,gPlayerNode,(CMesh**)&poMeshes,3);			 
			#endif

			gRenderer.EnableFrustumCulling();
				
				// Render map
				gRenderer.EnableDefferredMode();
				
				if (gpGameMap) // DEBUG
					gpGameMap->Render();
				
				gRenderer.DisableDefferredMode();
				
				// Render dynamic objects
				gDynObjs.Render();

			gRenderer.DisableFrustumCulling();
			
			#ifdef _USE_SHADOWMAP_
			gShadowCaster.Render();
			#endif
			

			if (gPlayerNode) // DEBUG
				gPlayerNode->Render();			

			gPSysMgr.Render();

		gCamera.PostRender();
		gHUDMgr.Render();

	gpoE3DRenderer->EndRender();
  //## end CGameScene::Render%997655866.body
}

// Additional Declarations
  //## begin CGameScene%3B65CB11028A.declarations preserve=yes
  //## end CGameScene%3B65CB11028A.declarations

//## begin module%3B65CB11028A.epilog preserve=yes
//## end module%3B65CB11028A.epilog
