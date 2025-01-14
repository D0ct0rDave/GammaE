//## begin module%3CB4A85F029E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB4A85F029E.cm

//## begin module%3CB4A85F029E.cp preserve=no
//## end module%3CB4A85F029E.cp

//## Module: CGameMapLoader%3CB4A85F029E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\CGameMapLoader.cpp

//## begin module%3CB4A85F029E.additionalIncludes preserve=no
//## end module%3CB4A85F029E.additionalIncludes

//## begin module%3CB4A85F029E.includes preserve=yes
#include "Terrain/GammaE_Terrain.h"
#include "Game/Entities/CGPEntityType.h"

#ifdef _BORLANDC_
	#include <dir.h>
#else
	#ifdef _MBCS
	#include <direct.h>
	#endif
#endif

#include "game/globals/globals.h"
//## end module%3CB4A85F029E.includes

// CGameMapLoader
#include "Game\GameScene\GameMap\CGameMapLoader.h"
// CGEMap
#include "Game\GameScene\GameMap\GEMap\CGEMap.h"
// CGEMapInterpreter
#include "Game\GameScene\GameMap\GEMap\GEMapInterpreter\CGEMapInterpreter.h"
// CGEMapLoader
#include "Game\GameScene\GameMap\GEMap\CGEMapLoader.h"
//## begin module%3CB4A85F029E.additionalDeclarations preserve=yes
//## end module%3CB4A85F029E.additionalDeclarations


// Class CGameMapLoader 

//## begin CGameMapLoader::aoRoomColliders%3CB4AC3F0269.role preserve=no  public: static CGMRoomCOLInfo { -> VHAN}
CDynArray <CGMRoomCOLInfo*> CGameMapLoader::aoRoomColliders;
//## end CGameMapLoader::aoRoomColliders%3CB4AC3F0269.role

CGameMapLoader::CGameMapLoader()
  //## begin CGameMapLoader::CGameMapLoader%.hasinit preserve=no
  //## end CGameMapLoader::CGameMapLoader%.hasinit
  //## begin CGameMapLoader::CGameMapLoader%.initialization preserve=yes
  //## end CGameMapLoader::CGameMapLoader%.initialization
{
  //## begin CGameMapLoader::CGameMapLoader%.body preserve=yes
  //## end CGameMapLoader::CGameMapLoader%.body
}


CGameMapLoader::~CGameMapLoader()
{
  //## begin CGameMapLoader::~CGameMapLoader%.body preserve=yes
  //## end CGameMapLoader::~CGameMapLoader%.body
}



//## Other Operations (implementation)
void CGameMapLoader::iLoad (char *_szMap)
{
  //## begin CGameMapLoader::iLoad%1018461830.body preserve=yes
  	char szCurDir[1024];
	getcwd(szCurDir,1024);
	chdir("base/maps/GameMap");

	// -- Creating / Loading
	gpGameMap = CGEMapLoader::poLoad( _szMap);
	CGEMapInterpreter::Interpret( *gpGameMap );

	// -- Loading terrain if required
	if (gpGameMap->oWEnt.szWorldFile[0])
	{
		CObject3D *poWorldScn;
		poWorldScn = poLoadWorldScene(gpGameMap->oWEnt.szWorldFile);
	}

	// -- Adding to scene
	// gCamera.iAddObject(gpGameMap);

	// -- Setting collisions
	SetupRoomColliders();

	chdir(szCurDir);
  //## end CGameMapLoader::iLoad%1018461830.body
}

void CGameMapLoader::SetupRoomColliders ()
{
  //## begin CGameMapLoader::SetupRoomColliders%1018461831.body preserve=yes
	int				iRoom;
	int				iEnt;
	CGMRoomCOLInfo	*poRoomColInfo;
	CCOL_Collider	oCollider;

	gaoPlatforms.Clear();

	for (iRoom=0;iRoom<gpGameMap->aoRooms.iNumElems();iRoom++)
	{	
		// Initialize static part of the room 		
		poRoomColInfo = mNew CGMRoomCOLInfo;
		poRoomColInfo->oStaticObj.Init(
					CGPET_Map, //0xff000000 | iRoom,
					&gCOLScn_TLG,
					&gCOLScn_MCT,
					eCOL_CT_Static,eCOL_TT_None,eCOL_TT_None,
					gpGameMap->aoRooms[iRoom]->poScn,0,0 );
		
		// Add dynamic objects
		CGEMapRoom *poRoom;
		for (iEnt=0;iEnt<gpGameMap->aoRooms[iRoom]->iNumEnts;iEnt++)
		{
			poRoom = gpGameMap->aoRooms[iRoom];

			if (poRoom->poEnts[iEnt]->eClass == eMapEnt_Platform)
			{
				oCollider.Init( CGPET_Platform,//(0xff000000 | iRoom) | (iEnt << 8),
								NULL,
								NULL,
								eCOL_CT_Dynamic,
								eCOL_TT_None,
								eCOL_TT_None,
								((CRTME_Platform*)poRoom->poRTEnts[iEnt])->poGrObj,
								0,
								0);

				int iCObj= poRoomColInfo->aoDynObjs.iAdd(oCollider);	

				// Link run time entity to collion info
				((CRTME_Platform*)poRoom->poRTEnts[iEnt])->poColObj = &poRoomColInfo->aoDynObjs[iCObj];
				
				// Add to the global platform list
				gaoPlatforms.iAdd( (CRTME_Platform*)poRoom->poRTEnts[iEnt] );
			}
		}

		// Add this room to collision scene
		aoRoomColliders.iAdd(poRoomColInfo);
	}
  //## end CGameMapLoader::SetupRoomColliders%1018461831.body
}

CObject3D* CGameMapLoader::poLoadWorldScene (char* _szWFilename)
{
  //## begin CGameMapLoader::poLoadWorldScene%1023005985.body preserve=yes
	return(NULL);
  //## end CGameMapLoader::poLoadWorldScene%1023005985.body
}

CObject3D * CGameMapLoader::poLoadTerrainScene (char* _szTrnFile)
{
  //## begin CGameMapLoader::poLoadTerrainScene%1023005986.body preserve=yes
	// ----------------------------------------------------------------------------
	TERSceneLoader		TL;
	CObject3D			*poTerrain;

		// -- Creating / Loading		
		poTerrain = TL.Load(_szTrnFile);
		poTerrain->ComputeBoundVol();
		
		// Setup terrain collision object	
		int iNumSectors = TL.HF->iGetSecsPerRow() * TL.HF->iGetSecsPerCol();

		// Terrain triangle list generator
		gCOLTrn_TLG.Init(TL.HF->iGetSecsPerRow(),
						 TL.HF->iGetSecsPerCol(),
						 TL.iSectorRes,
						 TL.fSectorSize);

		for (int i=0;i<iNumSectors;i++)
			gCOLTrn_TLG.SetSector(i,(CHFSector*)TL.HF->GetSector(i));

		// Setup terrain collision tester
		gCOLScn_TCT.Init(TL.HF,TL.iSectorRes,TL.fSectorSize);

		// ------------------
		// Get Skybox
		// ------------------
		// CObject3D_Node *poSkyBox  = TL.SkyBox;
		CObject3D_Leaf *poSkyDome = TL.SkyDome;
		
		// ------------------
		// Setup fog
		// ------------------
		CVect3 FogColor(TL.EnvPars.fFogColor[0],		
						TL.EnvPars.fFogColor[1],
						TL.EnvPars.fFogColor[2]);

		//	TL.EnvPars.iFogType = 0;
		gpoE3DRenderer->SetFogPars(eE3D_FM_Linear,
						TL.EnvPars.fFogNear,
						TL.EnvPars.fFogFar,
						TL.EnvPars.fFogDens,
						(TFColor*)TL.EnvPars.fFogColor);

		// DEBUG_CODE
		// PerspPrj.fFar = TL.EnvPars.fCamFar;

		// -- Adding to scene
		// gameScene.AddSceneObject(SkyDome);
		
		CObject3D_Transf	*poTransf = mNew CObject3D_Transf;
		CObject3D_Node		*poNode   = mNew CObject3D_Node;
		
		CVect3 oPos(TL.EnvPars.fXOfs,TL.EnvPars.fYOfs,0.0f);
		
		poTransf->SetPos   (oPos);		
		poTransf->SetObject(poTerrain);		
		poTransf->ComputeBoundVol();

		poNode->Init(2);
		poNode->iAddObject(poSkyDome);
		poNode->iAddObject(poTransf);

		return(poNode);
		// gameBackgroundMgr->SetBackground(SkyDome);
		
		/*
		// -- Collisions
		CCOL_Collider *TerrainCollider = new CCOL_Collider;
		TerrainCollider->Init(	CGame_ePET_Terrain,
								&gCOLTrn_TLG,
								&gCOLScn_TCT,
								eCOL_CT_GraphicStatic,
								eCOL_TT_NgbTri,
								Terrain,0);
		gCollisionSystem.iAddObject( *TerrainCollider );
		*/
  //## end CGameMapLoader::poLoadTerrainScene%1023005986.body
}

void CGameMapLoader::LinkWorldRooms (CObject3D *_poWorldScn)
{
  //## begin CGameMapLoader::LinkWorldRooms%1023005984.body preserve=yes
  //## end CGameMapLoader::LinkWorldRooms%1023005984.body
}

// Additional Declarations
  //## begin CGameMapLoader%3CB4A85F029E.declarations preserve=yes
  //## end CGameMapLoader%3CB4A85F029E.declarations

//## begin module%3CB4A85F029E.epilog preserve=yes
//## end module%3CB4A85F029E.epilog
