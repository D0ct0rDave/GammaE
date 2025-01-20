// ----------------------------------------------------------------------
#include "CGMHLevelPruebas.h"
#include "Loop/Map/CMap.h"
#include "Loop/Map/CMapRenderer.h"
// ----------------------------------------------------------------------
#include "Loop/Game/CGame.h"
#include "Loop/Game/GameMode/History/CGMHistory.h"
#include "Loop/Game/CGameGlobals.h"
#include "Loop/Game/Ents/Enemies/Simple/CSimpleEnemy1.h"
// ----------------------------------------------------------------------
#define MAP_FILENAME "data/GameMode/History/LevelPruebas/LevelPruebas.dat"
// ----------------------------------------------------------------------
void CGMHLevelPruebas::Init(int _iSkill)
{
	CGMHLevel::Init(MAP_FILENAME,_iSkill);

	/*
	for (int i=0;i<MAX_E1;i++)
	{
		m_poE1[i] = pNew CSimpleEnemy1;
		
		MTH_CPoint3 oLP(fSRand(),fSRand(),0);
		oLP.Unit();
		oLP *= gpoMap->m_fRadius;
		
		((CSimpleEnemy1*)m_poE1[i])->Init(oLP,m_fIniPPos + 0.03f + 0.05f*fRand(),fSRand(),0);

		m_poE1[i]->ShowEnable();
	}
	*/
	m_bCreateEnemies = true;
}
// ----------------------------------------------------------------------
void CGMHLevelPruebas::CreateLevelEntities()
{
	CGMHLevel::CreateLevelEntities();
}
// ----------------------------------------------------------------------
void CGMHLevelPruebas::Finish()
{
	vDelete m_poMap;
	m_poMap = NULL;
}
// ----------------------------------------------------------------------
void CGMHLevelPruebas::Reset()
{
}
// ----------------------------------------------------------------------
void CGMHLevelPruebas::Think()
{
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
			/*
			for (int i=0;i<MAX_E1;i++)
			{
				if (m_poE1[i]->m_eState != ENTSTATE_ALIVE)					
				{
					MTH_CPoint3 oLP(0.0f,fSRand(),0.0f);
					oLP.Unit();
					oLP *= gpoMap->m_fRadius;
					((CSimpleEnemy1*)m_poE1[i])->Restart(oLP,gfMapCursor + 0.03f + 0.05f*fRand(),fSRand(),0);
				}
			}
			*/

			/*
			if (bBetween(0.1f,0.2f,gfMapCursor) && m_bCreateEnemies)
			{
				for (int i=0;i<10;i++)
					m_poE1[i]->ShowEnable();
				// ((CSimpleEnemy1*)m_poE1)->Init(MTH_CPoint3(0,0,0),gfMapCursor,0);
				m_bCreateEnemies = false;
			}

			if (bBetween(0.205f,0.21f,gfMapCursor))
			{
				m_bCreateEnemies = true;
			}
			*/
		}
		break;
	}
}
// ----------------------------------------------------------------------
