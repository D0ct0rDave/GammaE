// ----------------------------------------------------------------------
#include "CGMHLevel2.h"
#include "Loop/Game/CGameGlobals.h"
#include "Loop/Map/CMap.h"
#include "Loop/Map/CMapRenderer.h"
#include "Loop/Game/GameMode/History/CGMHistory.h"

#include "Loop/Game/Ents/Enemies/Boss/AntiGlobox/CAntiGlobox.h"
#include "Loop/Game/Ents/Enemies/Boss/Pollo/CPollo.h"
#include "Loop/Game/Ents/Enemies/Simple/MiniPollo/CMiniPollo.h"

#include "Loop/3DObjWH/C3DObjWH.h"
#include "Loop/Game/Ents/CRock.h"
#include "Loop/EntRend/CEntRend.h"

#include "Loop/Game/CGame.h"

#include "sfx.h"
// ----------------------------------------------------------------------
#define LEVELSTATE_FIRSTTIME	10
#define LEVELSTATE_RUNNING 		11
#define LEVELSTATE_ENDGAME		12

// ----------------------------------------------------------------------
#define MAP_FILENAME "data/GameMode/History/Level2/Level2.dat"
// ----------------------------------------------------------------------
void CGMHLevel2::Init(int _iSkill)
{
	CGMHLevel::Init(MAP_FILENAME,_iSkill);

	// De momento
	m_poPollo = pNew CPollo();
	((CPollo*)m_poPollo)->Init(m_oIniBPos);

	// Correct position boss position	
	MTH_CPoint3 oGoodPos = m_oIniBPos;
	oGoodPos.z = (m_oIniBPos.z - (TILE_BLOCK_HEIGHT/2.0f)) + (-m_poPollo->m_poGI->m_poModel->m_fBBZMin);

	((CPollo*)m_poPollo)->m_oIniPos = oGoodPos;
	((CPollo*)m_poPollo)->SetPos(oGoodPos);

	// Create entities
	GEOM_Group* poG= C3DObjWH::poGetObj("data/models/objects/huevo.geo");

	// Create rock
	m_iState = LEVELSTATE_FIRSTTIME;
}
// ----------------------------------------------------------------------
void CGMHLevel2::Finish()
{
	vDelete m_poMap;
	m_poMap = NULL;
}
// ----------------------------------------------------------------------
void CGMHLevel2::Reset()
{
}
// ----------------------------------------------------------------------
void CGMHLevel2::RespawnRock()
{
	// Spawn new rock
	m_poRocks[0].SetPos( m_poMap->oMapToWorld(m_oSV.m_oPos[0].x,m_oSV.m_oPos[0].z) );
	m_poRocks[0].Restart();

	// Add SFX
	CPSysMgr::iAddSHPSys(2,m_poRocks[0].m_oPos,0.25f);
	CPSysMgr::iAddSHPSys(5,m_poRocks[0].m_oPos,0.35f);
}
// ----------------------------------------------------------------------
void CGMHLevel2::Think(float _fDeltaT)
{ 
	// Rock Position (12,5)
	switch (m_iState)		
	{
		case LEVELSTATE_FIRSTTIME:
		{
			if ( ((CGMHistory*)CGame::m_poGM)->m_eSubState == GMHSTATE_JUSTBEFORERUN)
			{
				m_uiPrevScoredRocks = 0;
			
				// Set player position.
				gpoPlayer[0]->Restart();

				// Set boss position.
				if (m_poPollo)
					m_poPollo->Restart();

				RespawnRock();

				//
				m_iState = LEVELSTATE_RUNNING;				
			}
		}
		break;

		case LEVELSTATE_RUNNING:
		{
			bool bRockScored = ((CGMHistory*)CGame::m_poGM)->m_iCurRocks > m_uiPrevScoredRocks;
			m_uiPrevScoredRocks = ((CGMHistory*)CGame::m_poGM)->m_iCurRocks;
			
			if ((m_poRocks[0].m_iState == ENTSTATE_INACTIVE) || (m_poRocks[0].m_iState == ENTSTATE_DEAD))
				RespawnRock();

			if (bRockScored)
			{
				// Scored one rock, spawn one more
				((CPollo*)m_poPollo)->PolloHit();
			}

			if ((! bRockScored) && (m_poRocks[0].m_iState == ENTSTATE_INACTIVE))
			{
				// El pollo se nos ha cargado la roca
				// ((CPollo*)m_poPollo)->PolloTrionfant();
			}

			if ( ((CGMHistory*)CGame::m_poGM)->m_eSubState == GMHSTATE_STARTTIMEOVER)
			{
				

				m_poPollo->m_iState = ENTSTATE_INACTIVE;
				m_iState = LEVELSTATE_ENDGAME;
			}

			// Notificar al modo de juego que se ha acabado y que hemos vencido!
			if (m_poPollo->m_iState == PST_DEAD)
			{
				((CGMHistory*)CGame::m_poGM)->m_eSubState = GMHSTATE_STARTVICTORY;
				m_iState = LEVELSTATE_ENDGAME;
			}
		}
		break;

		case LEVELSTATE_ENDGAME:
		{
		}
		break;
	}
}
// ----------------------------------------------------------------------