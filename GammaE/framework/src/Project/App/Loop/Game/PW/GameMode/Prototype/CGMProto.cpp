// ----------------------------------------------------------------------
#include "CGMProto.h"
#include "Common/Sound/CSndMixer.h"
#include "Common/Utility/CMFCSndMgr.h"

#include "Game/GameGraphics/CEntRend.h"
#include "Game/GameGraphics/CGraphicResourceMgr.h"

#include "Game/Ents/CEntityMgr.h"
#include "Game/CGameGlobals.h"

#include "Game/GameUtils/CExplosionMgr.h"
#include "Game/GameUtils/CBulletMgr.h"
#include "Game/GameUtils/CGameMsgMgr.h"
#include "Game/GameGraphics/sfx/CSFXLaserManager.h"

#include "Game/CGameGlobals.h"
#include "Game/GameMessages.h"
#include "Common/Graph/CMovie.h"

// DMC PROJECTQ #include "HUD/CHUDManager.h"
// DMC PROJECTQ #include "HUD/CHUDLabel.h"
#include "Cephei.h"
#include "sfx.h"
// ----------------------------------------------------------------------
const int GI_TX = 4;
const int GI_TY = 4;

CTex* m_poBackgroundTex = NULL;
GEOM_MatTexUnitManual oMT;
// ----------------------------------------------------------------------

#define GMPHUD_TIME_LABEL		0
#define GMPHUD_TIMEVAL_LABEL	1
#define GMPHUD_ENDGAME_LABEL	2
#define GMPHUD_ROCKS_LABEL		3
#define GMPHUD_ROCKNUM_LABEL	4
#define GMPHUD_MESSAGE_LABEL	5
#define GMPHUD_POWERUP1_ICON	6
#define GMPHUD_POWERUP2_ICON	7
#define GMPHUD_POWERUP3_ICON	8

// ----------------------------------------------------------------------
#define GMP_TIMEOVER_TIME		7.5
#define GMP_VICTORY_TIME		7.5

#define GMP_POWERUP_TIME		20.0f

#define GMP_LAST_LEVEL			2
// ----------------------------------------------------------------------
void CGMProto::SetState(TGMPState _eState)
{
	switch (_eState)
	{	
		case GMPSTATE_NONE: 
			m_eState = GM_STATE_NONE;
		break;

		case GMPSTATE_INIT:  
			m_eState = GM_STATE_INIT;
		break;

		case GMPSTATE_FINISH: 
		case GMPSTATE_BLOCKINGFINISH:
			m_eState = GM_STATE_FINISH;
		break;

		case GMPSTATE_READY:
		case GMPSTATE_READYMESSAGE:
		case GMPSTATE_JUSTBEFORERUN:
		case GMPSTATE_RUN:
		case GMPSTATE_DEAD:	
		case GMPSTATE_STARTTIMEOVER:
		case GMPSTATE_TIMEOVER:
		case GMPSTATE_ENDTIMEOVER:
		case GMPSTATE_STARTVICTORY:
		case GMPSTATE_VICTORY:
		case GMPSTATE_ENDVICTORY:
		case GMPSTATE_GAMEOVER:
		case GMPSTATE_INTROSTART:
		case GMPSTATE_INTRO:
		case GMPSTATE_INTROEND:
		case GMPSTATE_OUTROSTART:
		case GMPSTATE_OUTRO:
		case GMPSTATE_OUTROEND:
			m_eState = GM_STATE_RUN;
		break;

		case GMPSTATE_MENUINGAMESTART:
		case GMPSTATE_MENUINGAME:
		case GMPSTATE_MENUINGAMEEND:
			m_eState = GM_STATE_PAUSED;
		break;
	};
		
	m_eSubState = 	_eState;
}
// ----------------------------------------------------------------------
CGMProto::CGMProto()
{
	// Load the History GameMode HUD
	// DMC PROJECTQ m_poHScn = pNew CHUDScene;
	// DMC PROJECTQ m_poHScn->bLoadScene("data/GameMode/History/HUD/GMPHUD.cfg");
}
// ----------------------------------------------------------------------
void CGMProto::Init(int _iLevel,int _iSkill)
{
	// Init the bullet manager
	CBulletMgr::Reset();
	
	// Init the laser manager
	CSFXLaserManager::Init();
	oMT.bInit("(BackgroundFrame)",GI_TX,GI_TY,TEX_PF_ARGB32);	

	// Register resources
	CGraphicResourceMgr::Register("Player",	pNew CGraphicResource(gszResources[GR_PLAYER]));	
	CGraphicResourceMgr::Register("Moggle",	pNew CGraphicResource(gszResources[GR_MOGGLE]));
	CGraphicResourceMgr::Register("Egg",	pNew CGraphicResource(gszResources[GR_EGG]));
	CGraphicResourceMgr::Register("Foot",	pNew CGraphicResource(gszResources[GR_FOOT]));

	// Setup initial gamemode state
	SetState(GMPSTATE_NONE);
	
	// Low down music
	CSndMixer::SetUserVol(SL_MusicCh0,0.0f);
	
	// Camera
	CCamera* poCam = pNew CCamera;
	poCam->Init((MTH_CPoint3&)MTH_CPoint3::oZero,0);
	poCam->m_iSubType = 8;
	poCam->Visible(true);
}
// ----------------------------------------------------------------------
void CGMProto::Finish()
{
}
// ----------------------------------------------------------------------
// 
// ----------------------------------------------------------------------
const float fGaussianFilterKernel[5][5] =
{
	0.00078633, 	0.00655965, 	0.01330373, 	0.00655965, 	0.00078633,
	0.00655965, 	0.05472157, 	0.11098164, 	0.05472157, 	0.00655965,
	0.01330373, 	0.11098164, 	0.22508352, 	0.11098164, 	0.01330373,
	0.00655965, 	0.05472157, 	0.11098164, 	0.05472157, 	0.00655965,
	0.00078633, 	0.00655965, 	0.01330373, 	0.00655965, 	0.00078633
};

void GassianBlur(CTex* _poTex)
{
	uint* uiDstData = (uint*)_poTex->m_poTex->pucImage();

	uint uiData[GI_TY][GI_TX];
	_poTex->m_poTex->Download((uchar*)uiData,_poTex->m_poTex->uiGetSize());

	for (int j=0;j<GI_TY;j++)
		for (int i=0;i<GI_TX;i++)
		{
			E3D_Color oSum(0,0,0,0);

			for (int l=-2;l<=2;l++)
			{
				int y = j + l;
				y = iClamp(0,GI_TY,y);
				
				for (int k=-2;k<=2;k++)
				{
					int x = i+k;
					x = iClamp(0,GI_TX,x);
					
					// Here the value at this coords
					E3D_Color oPixel( uiData[y][x] );
					oSum += oPixel * fGaussianFilterKernel[l+2][k+2];
				}	
			}

			uiDstData[j*GI_TX+i] = oSum.uiRGBA();
		}

	_poTex->Invalidate();
}
// ----------------------------------------------------------------------
void CGMProto::Think(float _fDeltaT)
{
	CBulletMgr::Think(_fDeltaT);
	CExplosionMgr::Update(_fDeltaT);		
	CSFXLaserManager::Update(_fDeltaT);

	// Copy background to texture
	oMT.bStartBaking();
		
		gDC->ResetContext();
		gDC->Disable(E3D_S_DEPTHTEST);
		gDC->Enable(E3D_S_TEXTURE);
		gDC->BlendMode(E3D_BM_COPY);
		RenderQUAD(CMovie::poGetFrame(),0,0,STD_SCR_WIDTH,STD_SCR_HEIGHT,0,0,1,1,0xffffffff,0.0f);

	oMT.bEndBaking();
	
	// Smooth properly to achieve an spherical harmonix like result
	GassianBlur(oMT.poGetTex());

	// Copy background to background texture
	// memcpy(m_poBackgroundTex->m_poInfo->pucLODs[0],CMovie::poGetFrame()->m_poInfo->pucLODs[0],m_poBackgroundTex->m_poTex->uiGetSize());
	// m_poBackgroundTex->Invalidate();
	
	switch (m_eSubState)
	{
		// ----------------------------------------------------------------------
		case GMPSTATE_NONE:
		{
			SetState(GMPSTATE_INIT);
		}
		break;
		// ----------------------------------------------------------------------		
		case GMPSTATE_INIT:
		{
			SetState(GMPSTATE_JUSTBEFORERUN);
		}
		break;
		// ----------------------------------------------------------------------
		case GMPSTATE_JUSTBEFORERUN:
		{
			SetState(GMPSTATE_RUN);

			// Set proper HUD
			{
				#if 0
				// DMC PROJECTQ CHUDManager::SetAsCurrent(m_poHScn);
				#endif

				/*
				// Disable non fix HUD objects
				m_poHScn->m_oHUDObj[GMPHUD_ENDGAME_LABEL]->m_fScale = 1.0f;
				m_poHScn->m_oHUDObj[GMPHUD_ENDGAME_LABEL]->m_fXPos  = 0.0f;
				m_poHScn->m_oHUDObj[GMPHUD_ENDGAME_LABEL]->m_fYPos  = 0.0f;
				m_poHScn->m_oHUDObj[GMPHUD_ENDGAME_LABEL]->Disable();
				
				// Disable/Enable objects not in boss level game type
				if (m_poLevel->m_bBossLevel)
				{
					m_poHScn->m_oHUDObj[GMPHUD_ROCKS_LABEL  ]->Disable();
					m_poHScn->m_oHUDObj[GMPHUD_ROCKNUM_LABEL]->Disable();
				}
				else
				{
					m_poHScn->m_oHUDObj[GMPHUD_ROCKS_LABEL  ]->Enable();
					m_poHScn->m_oHUDObj[GMPHUD_ROCKNUM_LABEL]->Enable();
				}				

				m_poHScn->m_oHUDObj[GMPHUD_MESSAGE_LABEL]->Disable();
				m_poHScn->m_oHUDObj[GMPHUD_MESSAGE_LABEL]->m_fScale = 1.0f;
			
				// Hide PowerUp Icons
				m_poHScn->m_oHUDObj[GMPHUD_POWERUP1_ICON]->Disable();
				m_poHScn->m_oHUDObj[GMPHUD_POWERUP2_ICON]->Disable();
				m_poHScn->m_oHUDObj[GMPHUD_POWERUP3_ICON]->Disable();
				*/
			}

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
		case GMPSTATE_READYMESSAGE:
		{
		}
		break;
		
		// ----------------------------------------------------------------------
		case GMPSTATE_READY:
		{
		}
		break;
		// ----------------------------------------------------------------------
		case GMPSTATE_RUN:
		{
			#ifdef _DEBUG
				extern bool DEBUGPARTICLES;
				extern bool DEBUGFLARES;

				#if 0// DMC PROJECTQ 
				if (DEBUGPARTICLES || DEBUGFLARES)
					CHUDManager::SetAsCurrent(NULL);
				else
					CHUDManager::SetAsCurrent(m_poHScn);
				#endif

				// DEBUG CODE
				if ((gaInput[0].pressed.A) && (gaInput[0].pressed.B))
				{
					giDisableAI = 1;
				}
			#endif

			HandleMessageQueue();
			
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
			
			#if 0
			// DMC PROJECTQ 
			if (gaInput[0].justpressed.start)
			{
				m_oMIG.Enable();
				SetState(GMPSTATE_MENUINGAMESTART);
			}
			#endif

		}
		break;
		// ----------------------------------------------------------------------
		case GMPSTATE_MENUINGAMESTART:
		{
			#if 0
			// DMC PROJECTQ 
			m_oMIG.Think(_fDeltaT);

			if (m_oMIG.eState() == MIGS_Ready)
			{
				SetState(GMPSTATE_MENUINGAME);
			}
			#endif
		}
		break;
		// ----------------------------------------------------------------------
		case GMPSTATE_MENUINGAME:
		{	
			#if 0 
			// DMC PROJECTQ 
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
					SetState(GMPSTATE_MENUINGAMEEND);
				}
				break;
			}
			#endif
		}
		break;
		// ----------------------------------------------------------------------
		case GMPSTATE_MENUINGAMEEND:
		{
			#if 0
			// DMC PROJECTQ 
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
					SetState(GMPSTATE_FINISH);
					break;

					case MIGO_Continue:
					SetState(GMPSTATE_RUN);
					break;
				}
			}
			#endif
		}		
		break;
		// ----------------------------------------------------------------------
		case GMPSTATE_STARTTIMEOVER:
		{			
		}
		break;

		case GMPSTATE_TIMEOVER:
		{
		}
		break;

		case GMPSTATE_ENDTIMEOVER:
		{
		}
		break;
		
		// ----------------------------------------------------------------------
		case GMPSTATE_STARTVICTORY:
		{		
		}
		break;

		case GMPSTATE_VICTORY:
		{
		}
		break;

		case GMPSTATE_ENDVICTORY:
		{
		}
		break;
		// ----------------------------------------------------------------------
		case GMPSTATE_INTROSTART:
		{
		}
		break;
		
		// ----------------------------------------------------------------------
		case GMPSTATE_INTRO:
		{
		}
		break;

		// ----------------------------------------------------------------------
		case GMPSTATE_INTROEND:
		{
		}
		break;

		// ----------------------------------------------------------------------
		case GMPSTATE_OUTROSTART:
		{
		}
		break;

		// ----------------------------------------------------------------------
		case GMPSTATE_OUTRO:
		{
		}
		break;

		// ----------------------------------------------------------------------
		case GMPSTATE_OUTROEND:
		{
		}
		break;

		// ----------------------------------------------------------------------
		case GMPSTATE_BLOCKINGFINISH:
		{
		}
		break;

		// ----------------------------------------------------------------------
		case GMPSTATE_FINISH:
		{
		}
		break;
	}
}
// ----------------------------------------------------------------------	
void CGMProto::EnablePowerUp()
{				
	m_fPUpTime = GMP_POWERUP_TIME;

	/*
	m_poHScn->m_oHUDObj[GMPHUD_POWERUP1_ICON + m_iCurPUp]->m_fColor[3] = 1.0f;
	m_poHScn->m_oHUDObj[GMPHUD_POWERUP1_ICON + m_iCurPUp]->Enable();
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
void CGMProto::DisablePowerUp()
{
	m_fPUpTime = 0.0f;

	/*
	m_poHScn->m_oHUDObj[GMPHUD_POWERUP1_ICON + m_iCurPUp]->m_fColor[3] = 1.0f;
	m_poHScn->m_oHUDObj[GMPHUD_POWERUP1_ICON + m_iCurPUp]->Disable();
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
void CGMProto::HandlePowerUp()
{
	/*
	if (m_fPUpTime<5.0f)
		m_poHScn->m_oHUDObj[GMPHUD_POWERUP1_ICON + m_iCurPUp]->m_fColor[3] = 0.5f + 0.5f*fSin(gfGlobalTime*_2PI_);
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
void CGMProto::Reset()
{
}
// ----------------------------------------------------------------------
void CGMProto::HandleMessageQueue()
{
	while (CGameMsgMgr::bPendingMessages())
	{
		TEntityMessage oMsg = CGameMsgMgr::oPeekMessage();
		
		switch (oMsg.m_uiMsgID)
		{
			case GMSG_NONE:
			break;

			case GMSG_SPAWN:
				HandleSpawnMsg(oMsg);
			break;

			case GMSG_DESTRUCTION:
				HandleDestructionMsg(oMsg);
			break;
			
			case GMSG_COLLISION:
				HandleCollisionMsg(oMsg);
			break;
		}
	}
}
// ----------------------------------------------------------------------
void CGMProto::HandleCollisionMsg(TEntityMessage& _oMsg)
{
	switch (_oMsg.m_poEnt->m_iType)
	{
		case ENT_PLAYER:
		break;

		case ENT_BULLET:
		{
			// Most probably a bullet collided with the destination 
			TCollisionInfo* poCI = (TCollisionInfo*)_oMsg.m_pData;
		
			switch (_oMsg.m_poEnt->m_iSubType)
			{
				// Plasma
				case BULLET_PLASMA:
				{
					// Add special FX to denote bullet with world collision
					CExplosionMgr::AddExplosion(ET_ENEMYGENERIC,poCI->oP0);
					CMFCSndMgr::PlayEvent(CSndSys::GetEventID("LaserExplosion"),SL_SFX);
				}
				break;

				// Laser
				case BULLET_LASER:
				{
					// Add special FX to denote bullet with world collision
					CExplosionMgr::AddExplosion(ET_ENEMYGENERIC,poCI->oP0);
					CMFCSndMgr::PlayEvent(CSndSys::GetEventID("PlasmaExplosion"),SL_SFX);
				}
				break;
				
				// GenericExplosion
				default:
				{
					CExplosionMgr::AddExplosion(ET_ENEMYGENERIC,poCI->oP0);
					CMFCSndMgr::PlayEvent(CSndSys::GetEventID("GenericExplosion"),SL_SFX);
				}
				break;
			}

			// 
			if (poCI->poEnt->m_iType == ENT_USER_00)
			{
				// CEnemy* poEnemy = (CEnemy*)poCI->poEnt;

				// if (poEnemy->bDamage(1.0f))
					poCI->poEnt->Kill();
			}		
		}
		break;
	}
}
// ----------------------------------------------------------------------
void CGMProto::HandleSpawnMsg(TEntityMessage& _oMsg)
{
	switch (_oMsg.m_poEnt->m_iType)
	{
		case ENT_PLAYER:
		break;

		case ENT_BULLET:
		{
			switch (_oMsg.m_poEnt->m_iSubType)
			{
				// Plasma
				case BULLET_PLASMA:
				{
					CMFCSndMgr::PlayEvent(CSndSys::GetEventID("PlasmaShot"),SL_SFX);
				}
				break;

				// Laser
				case BULLET_LASER:
				{
					CMFCSndMgr::PlayEvent(CSndSys::GetEventID("LaserShot"),SL_SFX);
				}
				break;
			}
		}
		break;
	}
}
// ----------------------------------------------------------------------
void CGMProto::HandleDestructionMsg(TEntityMessage& _oMsg)
{

}
// ----------------------------------------------------------------------
// Gamemode specific rendering
// ----------------------------------------------------------------------
void CGMProto::Render()
{
	CSFXLaserManager::Render();
}
// ----------------------------------------------------------------------