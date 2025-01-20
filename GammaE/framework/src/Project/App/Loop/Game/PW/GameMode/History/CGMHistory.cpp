// ----------------------------------------------------------------------
#include "CGMHistory.h"
#include "Loop/Game/GameMode/History/Levels/Level0/CGMHLevel0.h"
#include "Loop/Game/GameMode/History/Levels/Level1/CGMHLevel1.h"
#include "Loop/Game/GameMode/History/Levels/Level2/CGMHLevel2.h"
#include "Loop/Game/GameMode/History/Levels/LevelPruebas/CGMHLevelPruebas.h"

#include "Loop/Cinematic/CCINManager.h"
#include "Loop/EntRend/CEntRend.h"
#include "Loop/Game/Ents/CEntityMgr.h"
#include "Loop/Game/Ents/CBulletMgr.h"
#include "Loop/Game/CGameGlobals.h"

#include "HUD/CHUDManager.h"
#include "HUD/CHUDLabel.h"

#include "sfx.h"
// ----------------------------------------------------------------------

#define GMHHUD_TIME_LABEL		0
#define GMHHUD_TIMEVAL_LABEL	1
#define GMHHUD_ENDGAME_LABEL	2
#define GMHHUD_ROCKS_LABEL		3
#define GMHHUD_ROCKNUM_LABEL	4
#define GMHHUD_MESSAGE_LABEL	5
#define GMHHUD_POWERUP1_ICON	6
#define GMHHUD_POWERUP2_ICON	7
#define GMHHUD_POWERUP3_ICON	8

// ----------------------------------------------------------------------
#define GMH_TIMEOVER_TIME		7.5
#define GMH_VICTORY_TIME		7.5

#define GMH_POWERUP_TIME		20.0f

#define GMH_LAST_LEVEL			2
// ----------------------------------------------------------------------
void CGMHistory::SetState(TGMHState _eState)
{
	switch (_eState)
	{	
		case GMHSTATE_NONE: 
			m_eState = GM_STATE_NONE;
		break;

		case GMHSTATE_INIT:  
			m_eState = GM_STATE_INIT;
		break;

		case GMHSTATE_FINISH: 
		case GMHSTATE_BLOCKINGFINISH:
			m_eState = GM_STATE_FINISH;
		break;

		case GMHSTATE_READY:
		case GMHSTATE_READYMESSAGE:
		case GMHSTATE_JUSTBEFORERUN:
		case GMHSTATE_RUN:
		case GMHSTATE_DEAD:	
		case GMHSTATE_STARTTIMEOVER:
		case GMHSTATE_TIMEOVER:
		case GMHSTATE_ENDTIMEOVER:
		case GMHSTATE_STARTVICTORY:
		case GMHSTATE_VICTORY:
		case GMHSTATE_ENDVICTORY:
		case GMHSTATE_GAMEOVER:
		case GMHSTATE_INTROSTART:
		case GMHSTATE_INTRO:
		case GMHSTATE_INTROEND:
		case GMHSTATE_OUTROSTART:
		case GMHSTATE_OUTRO:
		case GMHSTATE_OUTROEND:
			m_eState = GM_STATE_RUN;
		break;

		case GMHSTATE_MENUINGAMESTART:
		case GMHSTATE_MENUINGAME:
		case GMHSTATE_MENUINGAMEEND:
			m_eState = GM_STATE_PAUSED;
		break;
	};
		
	m_eSubState = 	_eState;
}
// ----------------------------------------------------------------------
CGMHistory::CGMHistory()
{
	// Load the History GameMode HUD
	m_poHScn = pNew CHUDScene;
	m_poHScn->bLoadScene("data/GameMode/History/HUD/GMHHUD.cfg");
}
// ----------------------------------------------------------------------
void CGMHistory::Init(int _iLevel,int _iSkill)
{
	// Setup initial gamemode state
	SetState(GMHSTATE_NONE);

	// Create the level
	switch (_iLevel)
	{
		/*
		case 0:
		m_poLevel = pNew CGMHLevel0;
		break;

		case 1:
		m_poLevel = pNew CGMHLevel1;
		break;

		case 2:
		m_poLevel = pNew CGMHLevel2;
		break;
		*/

		default:
		m_poLevel = pNew CGMHLevelPruebas;
	}

	// Initialize level data
	m_poLevel->Init(_iSkill);

	// Add the level to the entity manager
	CEntityMgr::iAddEntity(m_poLevel);

	// Create the player
	MTH_CPoint3 oIniPos = gpoMap->m_oPath.oGetPos(m_poLevel->m_fIniPPos);
	m_poPlayer = pNew CPlayer;
	m_poPlayer->Init(oIniPos,0);	// Solo 1 player en modo historia

	// Add the player to the entity manager
	CEntityMgr::iAddEntity(m_poPlayer);	

	// Create the camera
	m_poCam = pNew CCamera;
	m_poCam->Init(oIniPos,0);

	// Add the camera to the entity manager
	CEntityMgr::iAddEntity(m_poCam);

	// Create Level Entities
	m_poLevel->CreateLevelEntities();

	// Load cinematics
	if (m_poLevel->m_szIntroCIN[0])
	{
		m_poIntroCIN = pNew CCINScene;
		m_poIntroCIN->bLoadScene(m_poLevel->m_szIntroCIN);
	}

	if (m_poLevel->m_szOutroCIN[0])
	{
		m_poOutroCIN = pNew CCINScene;
		m_poOutroCIN->bLoadScene(m_poLevel->m_szOutroCIN);
	}

	// Setup minimap	
	if (! m_poLevel->m_bBossLevel)
	{
		m_oMiniMap.Init(m_poLevel,m_poHScn);
	}

	// Setup MenuInGame
	m_oMIG.Init();

	// Create SFX for the Goal
	m_uiGoalSFX = -1; // CPSysMgr::iAddPSys(14,m_poLevel->m_poGoal->m_oPos,MTH_CPoint3(0,0,0));
	CPSysMgr::Disable(m_uiGoalSFX);
	
	m_iCurPUp	  = 0;
	
}
// ----------------------------------------------------------------------
void CGMHistory::Finish()
{
	// ---
	m_oMIG.Finish();

	// ---
	if (! m_poLevel->m_bBossLevel)
		m_oMiniMap.Finish();

	// ---
	if (m_poLevel)
	{
		m_poLevel->Finish();
		vDelete m_poLevel;
		m_poLevel = NULL;
	}

	// ---
	if (m_poPlayer)
	{
		vDelete m_poPlayer;
		m_poPlayer = NULL;
	}

	// ---
	if (m_poCam)
	{
		vDelete m_poCam;
		m_poCam = NULL;
	}
	
	// ---
	if (m_poIntroCIN)
	{
		vDelete m_poIntroCIN;
		m_poIntroCIN = NULL;
	}
	
	// ---
	if (m_poOutroCIN)
	{
		vDelete m_poOutroCIN;
		m_poOutroCIN = NULL;
	}
	
}
// ----------------------------------------------------------------------
void CGMHistory::Think(float _fDeltaT)
{
	switch (m_eSubState)
	{
		// ----------------------------------------------------------------------
		case GMHSTATE_NONE:
		{
			SetState(GMHSTATE_INIT);
		}
		break;
		// ----------------------------------------------------------------------		
		case GMHSTATE_INIT:
		{
			if (m_poIntroCIN)
				SetState(GMHSTATE_INTROSTART);
			else
				SetState(GMHSTATE_JUSTBEFORERUN);
		}
		break;
		// ----------------------------------------------------------------------
		case GMHSTATE_JUSTBEFORERUN:
		{
			SetState(GMHSTATE_RUN);

			// Set proper HUD
			{
				CHUDManager::SetAsCurrent(m_poHScn);
				/*
				// Disable non fix HUD objects
				m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->m_fScale = 1.0f;
				m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->m_fXPos  = 0.0f;
				m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->m_fYPos  = 0.0f;
				m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->Disable();
				
				// Disable/Enable objects not in boss level game type
				if (m_poLevel->m_bBossLevel)
				{
					m_poHScn->m_oHUDObj[GMHHUD_ROCKS_LABEL  ]->Disable();
					m_poHScn->m_oHUDObj[GMHHUD_ROCKNUM_LABEL]->Disable();
				}
				else
				{
					m_poHScn->m_oHUDObj[GMHHUD_ROCKS_LABEL  ]->Enable();
					m_poHScn->m_oHUDObj[GMHHUD_ROCKNUM_LABEL]->Enable();
				}				

				m_poHScn->m_oHUDObj[GMHHUD_MESSAGE_LABEL]->Disable();
				m_poHScn->m_oHUDObj[GMHHUD_MESSAGE_LABEL]->m_fScale = 1.0f;
			
				// Hide PowerUp Icons
				m_poHScn->m_oHUDObj[GMHHUD_POWERUP1_ICON]->Disable();
				m_poHScn->m_oHUDObj[GMHHUD_POWERUP2_ICON]->Disable();
				m_poHScn->m_oHUDObj[GMHHUD_POWERUP3_ICON]->Disable();
				*/
			}

			// Set camera type
			m_poCam->m_iSubType = m_poLevel->m_iCamType; // -1

			// Set Gamemode variables
			{
				m_fMaxTime = 10000.0f;
				m_fTime    = m_fMaxTime;
				m_fGTime   = 0.0f;
				m_fPUpTime = 0.0f;
				m_iCurPUp  = -1;
			}
		}
		break;
	
		// ----------------------------------------------------------------------
		case GMHSTATE_READYMESSAGE:
		{
		}
		break;
		
		// ----------------------------------------------------------------------
		case GMHSTATE_READY:
		{
		}
		break;	
		// ----------------------------------------------------------------------
		case GMHSTATE_RUN:
		{
			int i;

			#ifdef _DEBUG
				extern bool DEBUGPARTICLES;
				extern bool DEBUGFLARES;
				if (DEBUGPARTICLES || DEBUGFLARES)
					CHUDManager::SetAsCurrent(NULL);
				else
					CHUDManager::SetAsCurrent(m_poHScn);

				// DEBUG CODE
				if ((gaInput[0].pressed.A) && (gaInput[0].pressed.B))
				{
					giDisableAI = 1;
				}
			#endif

			m_fGTime += _fDeltaT;
			m_fTime  -= _fDeltaT;

			// Manage player powerups
			if (m_iCurPUp >= 0)
			{
				HandlePowerUp();
				
				// Disable powerups ???
				m_fPUpTime -= _fDeltaT;
				if (m_fPUpTime <= 0.0f)
				{
					DisablePowerUp();
					m_iCurPUp = -1;
				}
			}

			// Manage HUD
			{
				// Time
				if (m_poLevel->m_oSV.m_fTime >= 0.0)
				{
					if (m_fTime >= 0.0f)
					{
						// ((CHUDLabel*)m_poHScn->m_oHUDObj[GMHHUD_TIMEVAL_LABEL])->SetTime(m_fTime);
					}
					else
					{
						// ((CHUDLabel*)m_poHScn->m_oHUDObj[GMHHUD_TIMEVAL_LABEL])->SetTime(0.0f);
						SetState(GMHSTATE_STARTTIMEOVER);
					}
				}

				if (! m_poLevel->m_bBossLevel)
				{
					// Rocks
					// ((CHUDLabel*)m_poHScn->m_oHUDObj[GMHHUD_ROCKNUM_LABEL])->SetFraction(m_iCurRocks,m_iNeedRocks);

					// MiniMap
					m_oMiniMap.Think(_fDeltaT);
				}
			}
			
			if (gaInput[0].justpressed.start)
			{
				m_oMIG.Enable();
				SetState(GMHSTATE_MENUINGAMESTART);
			}

			/*
			float fF = fMin(m_fGTime / 25.0f,1.0f);

			MTH_CMat4x4 oM   =m_poLevel->m_poMap->m_oPath.oGetRefSys(fF);
			MTH_CPoint3 oPos =m_poLevel->m_poMap->m_oPath.oGetPos(fF);
			MTH_CPoint3 oDir,oUp;

			oM.GetCol2(&oDir);
			oM.GetCol1(&oUp);

			m_poCam->m_oCam.LookAt(oPos,oPos + oDir,oUp);
			*/
			
			gfMapCursorDelta = _fDeltaT / 250.0f;
			gfMapCursor      = fMin(m_poLevel->m_fIniPPos + m_fGTime / 250.0f,1.0f); /*0.01f; // */
			/*
			MTH_CMat4x4 oM   = m_poLevel->m_poMap->m_oPath.oGetRefSys(fF);
			MTH_CPoint3 oPos = m_poLevel->m_poMap->m_oPath.oGetPos(fF);

			MTH_CMat4x4 oPlayerMat = m_poPlayer->m_poGI->m_oMat;

			m_poPlayer->m_poGI->SetMatrix(oM);
			m_poPlayer->SetPos(oPos);
			*/
		}
		break;
		// ----------------------------------------------------------------------
		case GMHSTATE_MENUINGAMESTART:
		{
			m_oMIG.Think(_fDeltaT);

			if (m_oMIG.eState() == MIGS_Ready)
			{
				SetState(GMHSTATE_MENUINGAME);
			}
		}
		break;
		// ----------------------------------------------------------------------
		case GMHSTATE_MENUINGAME:
		{
			m_oMIG.Think(_fDeltaT);

			switch (m_oMIG.eGetOrder())
			{
				case MIGO_Processing:
				{
				}
				break;

				case MIGO_Exit:
				case MIGO_Continue:
				{
					m_oMIG.Disable();
					SetState(GMHSTATE_MENUINGAMEEND);
				}
				break;
			}
		}
		break;
		// ----------------------------------------------------------------------
		case GMHSTATE_MENUINGAMEEND:
		{
			m_oMIG.Think(_fDeltaT);

			if (m_oMIG.eState() == MIGS_Ready)
			{
				switch (m_oMIG.eGetOrder())
				{
					case MIGO_Processing:
					{
					}
					break;

					case MIGO_Exit:
					SetState(GMHSTATE_FINISH);
					break;

					case MIGO_Continue:
					SetState(GMHSTATE_RUN);
					break;
				}
			}
		}
		break;
		// ----------------------------------------------------------------------
		case GMHSTATE_STARTTIMEOVER:
		{			
			/*
			m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->Enable();
			((CHUDLabel*)m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL])->SetText("Time Over!");
			*/

			m_fTime  = GMH_TIMEOVER_TIME;
			SetState(GMHSTATE_TIMEOVER);
			
			gpoPlayer[0]->m_eState = ENTSTATE_INACTIVE;
		}
		break;

		case GMHSTATE_TIMEOVER:
		{
			/*
			m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->m_fXPos  = 0.01f * fSRand();
			m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->m_fYPos  = 0.01f * fSRand();
			*/

			m_fTime-= _fDeltaT;
			if (m_fTime <= 0.0f)
				SetState(GMHSTATE_ENDTIMEOVER);
		}
		break;

		case GMHSTATE_ENDTIMEOVER:
		{
			/*
			m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->Disable();			
			m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->m_fScale = 1.0f;
			*/
			SetState(GMHSTATE_FINISH);
		}
		break;
		
		// ----------------------------------------------------------------------
		case GMHSTATE_STARTVICTORY:
		{		
			/*
			m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->Enable();
			((CHUDLabel*)m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL])->SetText("Victory!");
			*/

			m_fTime  = GMH_VICTORY_TIME;
			SetState(GMHSTATE_VICTORY);
			
			gpoPlayer[0]->m_eState = ENTSTATE_INACTIVE;
		}
		break;

		case GMHSTATE_VICTORY:
		{
			/*
			m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->m_fScale = 1.0f + 0.5f*fSin(_2PI_ * m_fTime/5.0f);
			*/
			m_fTime-= _fDeltaT;

			if (m_fTime <= 0.0f)
				SetState(GMHSTATE_ENDVICTORY);
		}
		break;

		case GMHSTATE_ENDVICTORY:
		{
			/*
			m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->Disable();			
			*/

			// Load cinematics
			if (m_poOutroCIN)
			{
				SetState(GMHSTATE_OUTROSTART);
			}
			else
			{
				if (m_iLevel == GMH_LAST_LEVEL)
					SetState(GMHSTATE_BLOCKINGFINISH);
				else
					SetState(GMHSTATE_FINISH);
			}
		}
		break;
		// ----------------------------------------------------------------------
		case GMHSTATE_INTROSTART:
		{
			m_poCam->Disable();

			CCINManager::SetAsCurrent(m_poIntroCIN);
			SetState(GMHSTATE_INTRO);
		}
		break;
		
		// ----------------------------------------------------------------------
		case GMHSTATE_INTRO:
		{
			CCINManager::Update(_fDeltaT);
			
			// Reload cinematic
			#ifdef _DEBUG
			if (gaInput[0].justpressed.black)
			{
				m_poIntroCIN->bLoadScene(m_poLevel->m_szIntroCIN);
				CCINManager::SetAsCurrent(m_poIntroCIN);
				CCINManager::Restart();
			}
			#endif

			// Skip this plane
			if (gaInput[0].justpressed.white)
				CCINManager::NextPlane();
			
			// Skip cinematic
			if (CCINManager::bFinished() || (gaInput[0].justpressed.start))
				SetState(GMHSTATE_INTROEND);
		}
		break;

		// ----------------------------------------------------------------------
		case GMHSTATE_INTROEND:
		{
			SetState(GMHSTATE_JUSTBEFORERUN);
			m_poCam->Enable();
		}
		break;

		// ----------------------------------------------------------------------
		case GMHSTATE_OUTROSTART:
		{
			m_poCam->Disable();

			CCINManager::SetAsCurrent(m_poOutroCIN);
			SetState(GMHSTATE_OUTRO);
		}
		break;

		// ----------------------------------------------------------------------
		case GMHSTATE_OUTRO:
		{
			CCINManager::Update(_fDeltaT);

			// Reload cinematic
			#ifdef _DEBUG
			if (gaInput[0].justpressed.black)
			{
				m_poOutroCIN->bLoadScene(m_poLevel->m_szOutroCIN);
				CCINManager::SetAsCurrent(m_poOutroCIN);
				CCINManager::Restart();
			}
			#endif
			
			// Skip this plane
			if (gaInput[0].justpressed.white)
				CCINManager::NextPlane();

			// Skip cinematic
			if (CCINManager::bFinished() || (gaInput[0].justpressed.start))
				SetState(GMHSTATE_OUTROEND);
		}
		break;

		// ----------------------------------------------------------------------
		case GMHSTATE_OUTROEND:
		{
			m_poCam->Enable();
		
			if (m_iLevel == GMH_LAST_LEVEL)
				SetState(GMHSTATE_BLOCKINGFINISH);
			else
				SetState(GMHSTATE_FINISH);
		}
		break;
		// ----------------------------------------------------------------------
		case GMHSTATE_BLOCKINGFINISH:
		{
			CHUDManager::SetAsCurrent(m_poHScn);

			// Disable all HUD objects
			for (int i=0;i<m_poHScn->m_uiNumHUDObjs;i++)
				m_poHScn->m_oHUDObj[i]->Disable();

			// Enable HUD label
			/*
			m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->Enable();
			m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL]->m_fScale = 1.0f;
			((CHUDLabel*)m_poHScn->m_oHUDObj[GMHHUD_ENDGAME_LABEL])->SetText("The End");
			*/

			// Finish();
			CPostFX::PushFX(POSTFX_GAUSSIANBLUR);
			CPostFX::PushFX(POSTFX_BRIGHTCONTRAST,1.0f);
			gDC->SwapBuffers();
			
			// Blocking finish
			while (1);
		}
		break;

		// ----------------------------------------------------------------------
		case GMHSTATE_FINISH:
		{
		}
		break;
	}
}
// ----------------------------------------------------------------------	
void CGMHistory::EnablePowerUp()
{				
	m_fPUpTime = GMH_POWERUP_TIME;

	/*
	m_poHScn->m_oHUDObj[GMHHUD_POWERUP1_ICON + m_iCurPUp]->m_fColor[3] = 1.0f;
	m_poHScn->m_oHUDObj[GMHHUD_POWERUP1_ICON + m_iCurPUp]->Enable();
	*/
	
	switch (m_iCurPUp)
	{
		case 0:		
		{
		}
		break;
			
		// Para el tiempo			
		case 1:			
		{
			for (int i=0;i<CEntityMgr::m_iNumEnt;i++)
			{
				switch (CEntityMgr::m_poList[i]->m_iType)
				{
					case ENT_USER_00:
					case ENT_WORLD:
					{
						// CEntityMgr::m_poList[i]->Disable();
						CEntityMgr::m_poList[i]->m_fTimeMult = 0.0f;
					}
					break;
				}
			}
		}
		break;
		
		// Relentiza la accion
		case 2:
		{
			for (int i=0;i<CEntityMgr::m_iNumEnt;i++)
			{
				switch (CEntityMgr::m_poList[i]->m_iType)
				{
					case ENT_USER_00:
					case ENT_WORLD:
					{
						CEntityMgr::m_poList[i]->m_fTimeMult = 0.25f;
					}
					break;
				}
			}
		}
		break;
	}	
}
// ----------------------------------------------------------------------	
void CGMHistory::DisablePowerUp()
{
	m_fPUpTime = 0.0f;

	/*
	m_poHScn->m_oHUDObj[GMHHUD_POWERUP1_ICON + m_iCurPUp]->m_fColor[3] = 1.0f;
	m_poHScn->m_oHUDObj[GMHHUD_POWERUP1_ICON + m_iCurPUp]->Disable();
	*/
	
	switch (m_iCurPUp)
	{
		case 0:
		{	
		}
		break;

		// Para el tiempo
		case 1:			
		{
			for (int i=0;i<CEntityMgr::m_iNumEnt;i++)
			{
				switch (CEntityMgr::m_poList[i]->m_iType)
				{
					case ENT_USER_00:
					case ENT_WORLD:
					{
						CEntityMgr::m_poList[i]->m_fTimeMult = 1.0f;
						// CEntityMgr::m_poList[i]->Enable();
					}
					break;
				}
			}		
		}
		break;
		
		// Relentiza la accion
		case 2:
		{
			for (int i=0;i<CEntityMgr::m_iNumEnt;i++)
			{
				switch (CEntityMgr::m_poList[i]->m_iType)
				{
					case ENT_USER_00:
					case ENT_WORLD:
					{
						CEntityMgr::m_poList[i]->m_fTimeMult = 1.0f;
					}
					break;
				}
			}		
		}
		break;
	}	
}
// ----------------------------------------------------------------------	
void CGMHistory::HandlePowerUp()
{
	/*
	if (m_fPUpTime<5.0f)
		m_poHScn->m_oHUDObj[GMHHUD_POWERUP1_ICON + m_iCurPUp]->m_fColor[3] = 0.5f + 0.5f*fSin(gfGlobalTime*_2PI_);
	*/

	switch (m_iCurPUp)
	{
		// Desvela secretos
		case 0:
		{
			/*
			MTH_CPoint3 oP2DPos = m_poPlayer->m_oPos;
			oP2DPos.y = 0.0f;

			for (int i=0;i<m_poLevel->m_uiMovs;i++)
			{
				MTH_CPoint3 oM2DPos = m_poLevel->m_poMBs[i].m_oPos;
				oM2DPos.y = 0.0f;
				
				float fDist = oP2DPos.fDistance( oM2DPos );
			
				#define DIST_THRESH_NEAR 2.0f
				#define DIST_THRESH_FAR  4.0f
				if (fDist < DIST_THRESH_FAR)
				{
					float fFact;
					if (fDist < DIST_THRESH_NEAR) 
						fFact = 1.0f;
					else
						fFact = 1.0f - ((fDist - DIST_THRESH_NEAR) / (DIST_THRESH_FAR - DIST_THRESH_NEAR));

					// ----
					MTH_CPoint3 oPos = m_poLevel->m_poMBs[i].m_oPos;

					float fH = 1.0f*(m_poPlayer->m_poGI->m_poModel->m_fBBYMax -m_poPlayer->m_poGI->m_poModel->m_fBBYMin);
					oPos.y = fH * fFact;

					m_poLevel->m_poMBs[i].SetPos(oPos);
				}
			}
			*/
		}
		break;

		// 
		case 1:
		{
		}
		break;
		
		// 
		case 2:
		{
		}
		break;					
	}
}
// ----------------------------------------------------------------------	
void CGMHistory::Reset()
{
}
// ----------------------------------------------------------------------
bool CGMHistory::bInteractiveAction(TInteractiveAction _eAction,CEntity *_poSrc,CEntity* _poDst,void *_pParam)
{
	switch (_poSrc->m_iType)
	{
		// Player
		case ENT_PLAYER:
		{
			return ( bIA_Player(_eAction,_poSrc,_poDst,_pParam));
		}
		break;

		// Rock
		/*
		case ENT_ROCK:
		{
			return ( bIA_Rock(_eAction,_poSrc,_poDst,_pParam));
		}
		break;
		*/
	}
	
	return(false);
}
// ----------------------------------------------------------------------
bool CGMHistory::bIA_Player(TInteractiveAction _eAction,CEntity *_poSrc,CEntity* _poDst,void *_pParam)
{
	switch (_eAction)
	{
		case IA_Collision:
		{
			switch (_poDst->m_iType)
			{
				// Goal
				case ENT_WORLD:
				{
					
				}
				break;

				/*
				case ENT_GOAL:				
				{
					if (m_iCurRocks >= m_iNeedRocks)
					{
						// Add SFX
						CPSysMgr::iAddSHPSys(11,_poDst->m_oPos,0.5f);

						// Control if player has scored himself
						SetState(GMHSTATE_STARTVICTORY);

						// Hide the player
						_poSrc->HideDisable();
					}
				}
				break;
				*/

				// Powerup
				case ENT_POWERUP:
				{
					// Hide the powerup
					((CPowerUp*)_poDst)->HideDisable();

					m_iCurPUp = _poDst->m_iSubType;

					if (m_iCurPUp != -1)
					{
						/*
						m_poHScn->m_oHUDObj[GMHHUD_POWERUP1_ICON + m_iCurPUp]->m_fColor[3] = 1.0f;
						m_poHScn->m_oHUDObj[GMHHUD_POWERUP1_ICON + m_iCurPUp]->Disable();
						*/
					}
	
					EnablePowerUp();
				}
				break;

				// Other entities
				/*
				case ENT_USER_00:
				{
					((CPlayer*)_poSrc)->DisruptPlayer(50.0f);
				}
				break;
				*/
			}
		}
		break;

		case IA_Push:
		{
			switch (_poDst->m_iType)			
			{
				/*
				case  ENT_MOVABLE:
				{
					if (m_iCurPUp == 0)
					{
						((CMovBlock*)_poDst)->Raise();
					}
				}
				break;

				case  ENT_ROCK:
				{
					((CRock*)_poDst)->Push( (MTH_CPoint3&)(*(MTH_CPoint3*)_pParam),0.2f);
				}
				break;
				*/
			}
		}
		break;
		
		case IA_Pull:
		{
		}
		break;
	}
	
	return(true);
}
// ----------------------------------------------------------------------
bool CGMHistory::bIA_Rock  (TInteractiveAction _eAction,CEntity *_poSrc,CEntity* _poDst,void *_pParam)
{
	/*
	switch (_eAction)
	{
		// -------------------------
		case IA_Collision:		
		{
			switch (_poDst->m_iType)
			{
				// ----------
				case ENT_PLAYER:
				{
					((CPlayer*)_poDst)->DisruptPlayer(100.0f);
					((CRock  *)_poSrc)->Kill();
				}
				break;
				
				// ----------
				case ENT_GOAL:
				{
					// Desactivamos la entidad
					_poSrc->HideDisable();

					// Add SFX
					CPSysMgr::iAddSHPSys(11,_poSrc->m_oPos,0.125f);

					// Player scored a rock!!
					m_iCurRocks ++;

					// Control if required rock number is reached
					if (m_iCurRocks >= m_iNeedRocks)
					{
						// Activar FX para Goal: que es la señal de que el jugador puede salir ya del nivel
						CPSysMgr::Enable(m_uiGoalSFX);

						// Enable minimap
						m_oMiniMap.EnableGoal();
					}
				}
			}
		}
		break;
	}
	*/
	return(true);
}
// ----------------------------------------------------------------------