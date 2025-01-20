// ----------------------------------------------------------------------
#include "CGMHLevel.h"
#include "Loop/3DObjWH/C3DObjWH.h"
#include "Loop/Game/Ents/CRock.h"
#include "Loop/Game/Ents/CGoal.h"
#include "Loop/Game/Ents/CMovBlock.h"
#include "Loop/EntRend/CEntRend.h"
#include "Loop/Game/Ents/CEntityMgr.h"
#include "Loop/Map/CMapRenderer.h"
#include "Loop/Map/CRMapRenderer.h"
#include "Loop/Game/CGameGlobals.h"
// ----------------------------------------------------------------------
CGMHLevel::CGMHLevel()
{
	m_iType  = ENT_WORLD;
	m_eState = ENTSTATE_ALIVE;
}
// ----------------------------------------------------------------------
void CGMHLevel::Init(char *_szLevelName,int _iSkill)
{
	m_iSkill = _iSkill;

	CINIFile oCfg(_szLevelName);

	if (! oCfg.bIsInitialized())
		error("Unable to load level data");

	char *szMapName = oCfg.szGetString("General","Name",NULL);
	if (! szMapName)
		strcpy(m_szLevelName,"Nonamed Level");
	else
		strcpy(m_szLevelName,szMapName);

	szMapName = oCfg.szGetString("General","Map",NULL);
	if (! szMapName)
		error("Bad map filename");

	m_poMap = pNew CMap;
	if (! m_poMap->iLoad(szMapName))
		error("Unable to load map definition file");
	gpoMap = m_poMap;

	CMapRenderer ::Init( m_poMap );
	CRMapRenderer::Init( m_poMap->m_poRMap );
	
	CEntCollision::Init();

	// ---
	char *szCINFile;
 	szCINFile = oCfg.szGetString("General","Intro",NULL);
	if (szCINFile)
		strcpy(m_szIntroCIN,szCINFile);
	else
		m_szIntroCIN[0] = 0;

	szCINFile = oCfg.szGetString("General","Outro",NULL);
	if (szCINFile)
		strcpy(m_szOutroCIN,szCINFile);
	else
		m_szOutroCIN[0] = 0;


	// ----
	char* szMiniMapFile = oCfg.szGetString("General","MiniMap",NULL);
	if (! szMiniMapFile)
		m_poMinimap = NULL; 
	else 
		m_poMinimap = CDMCTexMgr::poLoad(szMiniMapFile);

	MTH_CPoint3 oPos;
	
	// ----
	m_fIniPPos = oCfg.fGetFloat("General","PlayerPos",0.0f);
	oPos = m_poMap->m_oPath.oGetPos(m_fIniPPos);
			
	// ----
	m_fIniBPos = oCfg.fGetFloat("General","BossPos",1.0f);
			
	// ----
	m_bBossLevel = oCfg.bGetBool("General","BossLevel",false);
	
	m_iCamType = oCfg.iGetInteger("General","CameraType",4);
	
	// ----
	char *szSection[3] = {
		"SkillEasy",
		"SkillMedium",
		"SkillHard"
	};

	{
		m_oSV.m_fHandicap	= oCfg.fGetFloat  (szSection[m_iSkill],"Handicap" ,1.0f);
		m_oSV.m_fMaloMult	= oCfg.fGetFloat  (szSection[m_iSkill],"MaloMult" ,1.0f);
		m_oSV.m_fTime		= oCfg.fGetFloat  (szSection[m_iSkill],"Time"	  ,0.0f);
	}
}
// ----------------------------------------------------------------------
void CGMHLevel::CreateLevelEntities()
{
	/*
	int i,j,t;

	// Create entities
	{
		GEOM_Group* poG;

		// Create powerups
		
		{
			m_poPUps = pNew CPowerUp[m_oSV.m_uiTotalRocks];
			for (int iR=0;iR < m_oSV.m_uiTotalRocks;iR++)
			{
				int iIdx = fRand() * 3.0f;
				iIdx = iIdx % 3;

				char szStr[256];
				sprintf(szStr,"data/models/objects/PowerUp%d.geo",iIdx+1);

				poG = C3DObjWH::poGetObj(szStr);
				m_poPUps[iR].Init(m_oSV.m_oPos[iR],poG,iIdx);
				m_poPUps[iR].HideDisable();
			}
		}
	}
	*/
}
// ----------------------------------------------------------------------