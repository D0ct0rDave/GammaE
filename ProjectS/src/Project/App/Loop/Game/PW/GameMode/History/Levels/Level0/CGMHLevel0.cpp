// ----------------------------------------------------------------------
#include "CGMHLevel0.h"
#include "Loop/Map/CMap.h"
#include "Loop/Map/CMapRenderer.h"
#include "Loop/Game/Ents/Enemies/Boss/AntiGlobox/CAntiGlobox.h"
#include "Loop/Game/Ents/Enemies/Boss/Pollo/CPollo.h"
#include "Loop/Game/Ents/Enemies/Simple/MiniPollo/CMiniPollo.h"
#include "sfx.h"

#include "Loop/Game/CGame.h"
#include "Loop/Game/GameMode/History/CGMHistory.h"
#include "Loop/Cinematic/CCINManager.h"
#include "Loop/Game/CGameGlobals.h"
// ----------------------------------------------------------------------
#define MAP_FILENAME "data/GameMode/History/Level0/Level0.dat"

FLARETYPE goFT;
// ----------------------------------------------------------------------
#define LEVEL_STEPS 6

const int iCellOrder[LEVEL_STEPS][2] = {
	{15,15},
	{14, 5},
	{4,6},
	{5,14},
	{10,13},
	{9,2},
};
// ----------------------------------------------------------------------
void CGMHLevel0::Init(int _iSkill)
{
	CGMHLevel::Init(MAP_FILENAME,_iSkill);
	// CPSysMgr::iAddPSys(1,MTH_CPoint3(0,0,0),MTH_CPoint3(0,0,0));

	// Load all the textures
	int i;
	for (i=0;i<LEVEL_STEPS;i++)
	{
		char szStr[1024];
		sprintf(szStr,"data/textures/FL_%dicon.tga",i+1);
		CDMCTex *poTex = CDMCTexMgr::poLoad(szStr);
		SetFlareTex(FIRST_RESERVED_FLARE_TEX+i,poTex);
	}

	/*
	// Create level specific flares
	goFT.fColor[0]	= goFT.fColor[1] = goFT.fColor[2] = goFT.fColor[3] = goFT.fColor[4] = 1.0f;
	goFT.fDstTh		= 1000.0f;
	goFT.fSize		= 1.5f;
	goFT.iBlendMode	= E3D_BM_ALPHA;
	goFT.iProcType	= 0;
	goFT.cFlags		= FLAREFLAG_XROT;

	for (i=0;i<LEVEL_STEPS;i++)
	{
		sprintf(goFT.szName,"level0_fl%d",i);
		goFT.iTex = FIRST_RESERVED_FLARE_TEX + i;

		SetFlareType(FIRST_RESERVED_FLARE_TYPE+i,goFT);

		MTH_CPoint3 oPos;

		oPos.x = m_poMap->m_fXOfs + (iCellOrder[i][0]-1)*TILE_BLOCK_WIDTH;
		oPos.y = 3;
		oPos.z = m_poMap->m_fZOfs + (iCellOrder[i][1]-1)*TILE_BLOCK_HEIGHT;

		m_uiFL[i] = CFlareMgr::iAddFlare(FIRST_RESERVED_FLARE_TYPE+i,oPos,-1);
		CFlareMgr::Disable(m_uiFL[i]);
	}
	*/

	m_bWaitingPlayerToFinish = false;
}
// ----------------------------------------------------------------------
void CGMHLevel0::RespawnRock()
{
	// Spawn new rock
	m_poRocks[0].Restart();

	// Add SFX
	CPSysMgr::iAddSHPSys(2,m_poRocks[0].m_oPos,0.25f);
	CPSysMgr::iAddSHPSys(5,m_poRocks[0].m_oPos,0.35f);
}
// ----------------------------------------------------------------------
void CGMHLevel0::Finish()
{
	vDelete m_poMap;
	m_poMap = NULL;
}
// ----------------------------------------------------------------------
void CGMHLevel0::Reset()
{
}
// ----------------------------------------------------------------------
void CGMHLevel0::Think(float _fDeltaT)
{
	// Showing the intro
	switch ( ((CGMHistory*)CGame::m_poGM)->m_eSubState)
	{
		// ----------------------------------------
		case  GMHSTATE_INTRO:
		{
			if (((CGMHistory*)CGame::m_poGM)->m_poIntroCIN)
			{
				int iCurFID = CCINManager::m_iCurPlane - 7;

				switch (iCurFID)
				{
					// Planos 13-7
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					CFlareMgr::Disable(m_uiFL[ iCurFID-1]);

					case 0:
					CFlareMgr::Enable (m_uiFL[ iCurFID  ]);
					break;

					case 6:
					CFlareMgr::Disable(m_uiFL[ iCurFID-1]);
					break;
				}
			}
		}
		break;

		// ----------------------------------------
		case GMHSTATE_JUSTBEFORERUN:
		{
			// Reactivamos todos los flares para que el jugador no se lie
			for (int i=0;i<LEVEL_STEPS;i++)
			{
				CFlareMgr::Enable( m_uiFL[i] );

				// Make every flare more transparent
				goFT.fColor[3] = 0.75f;
				goFT.iTex      = FIRST_RESERVED_FLARE_TEX + i;
				goFT.iProcType = 12;
				goFT.fFreq     = 1.0f;
				updateflaretype(FIRST_RESERVED_FLARE_TYPE+i,&goFT);
			}

			gpoPlayer[0]->Restart();
		}
		break;
		// ----------------------------------------
		case GMHSTATE_RUN:
		{
			// Ha petado la roca?
			if (m_poRocks[0].m_iState == ENTSTATE_DEAD)
				RespawnRock();
			
			CHUDLabel * poLabel = (CHUDLabel*)((CGMHistory*)CGame::m_poGM)->m_poHScn->m_oHUDObj[5];
			
			if (((CGMHistory*)CGame::m_poGM)->m_iCurRocks == 1)
			{ 
				// GMHHUD_MESSAGE_LABEL
				poLabel->Enable();
				
				poLabel->m_fColor[0] = 1.0f;
				poLabel->m_fColor[1] = 1.0f;
				poLabel->m_fColor[2] = 0.0f;				
				poLabel->m_fColor[3] = 1.0f;				
				poLabel->m_fXPos	 = 0.0f;
				poLabel->m_fYPos	 = 0.0f;
				poLabel->SetText("Espavila!,\ny sal por la porteria!");
				m_bWaitingPlayerToFinish = true;
			}
			
			if (m_bWaitingPlayerToFinish)
			{
				poLabel->m_fScale = 0.8f + fSin(gfGlobalTime*1.0f*_2PI_)*0.01f;
			}
			
		}
		break;	
		
		default:
		{
				((CGMHistory*)CGame::m_poGM)->m_poHScn->m_oHUDObj[5]->Disable();
		}
		break;
	}
}
// ----------------------------------------------------------------------
