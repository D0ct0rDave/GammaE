// ----------------------------------------------------------------------
#include "CGMHLevel1.h"
#include "Loop/Map/CMap.h"
#include "Loop/Map/CMapRenderer.h"

#include "Loop/Game/Ents/Enemies/Boss/AntiGlobox/CAntiGlobox.h"
#include "Loop/Game/Ents/Enemies/Boss/Pollo/CPollo.h"
#include "Loop/Game/Ents/Enemies/Simple/MiniPollo/CMiniPollo.h"


// ----------------------------------------------------------------------
#include "Loop/Game/CGame.h"
#include "Loop/Game/GameMode/History/CGMHistory.h"
#include "Loop/Game/CGameGlobals.h"
// ----------------------------------------------------------------------
#define MAP_FILENAME "data/GameMode/History/Level1/Level1.dat"
// ----------------------------------------------------------------------
void CGMHLevel1::Init(int _iSkill)
{
	CGMHLevel::Init(MAP_FILENAME,_iSkill);
	
	CEntity* poEnt;
	MTH_CPoint3 oPos;
	
	poEnt = pNew CMiniPollo();
	oPos.Set(12,0,10);
	((CMiniPollo*)poEnt)->Init(oPos,0);
	
	poEnt = pNew CMiniPollo();
	oPos.Set(-2.5,0,1.4);
	((CMiniPollo*)poEnt)->Init(oPos,1);
	
	poEnt = pNew CMiniPollo();
	oPos.Set(-10,0,-12.5);
	((CMiniPollo*)poEnt)->Init(oPos,2);
}
// ----------------------------------------------------------------------
void CGMHLevel1::CreateLevelEntities()
{
	CGMHLevel::CreateLevelEntities();

	for(int i=0;i<m_oSV.m_uiTotalRocks;i++)
		m_poRocks[i].m_bSpawnPU = true;
}
// ----------------------------------------------------------------------
void CGMHLevel1::Finish()
{
	vDelete m_poMap;
	m_poMap = NULL;
}
// ----------------------------------------------------------------------
void CGMHLevel1::Reset()
{
}
// ----------------------------------------------------------------------
void CGMHLevel1::Think(float _fDeltaT)
{
	// Showing the intro
	switch ( ((CGMHistory*)CGame::m_poGM)->m_eSubState)
	{
		// ----------------------------------------
		case  GMHSTATE_INTRO:
		{
		}
		break;

		// ----------------------------------------
		case GMHSTATE_JUSTBEFORERUN:
		{
			gpoPlayer[0]->Restart();
		}
		break;
		// ----------------------------------------
		case GMHSTATE_RUN:
		{
		}
		break;
	}
}
// ----------------------------------------------------------------------
