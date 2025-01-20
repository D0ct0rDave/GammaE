// -----------------------------------------------------------------------------
#ifndef CGMHistoryH
#define CGMHistoryH
// -----------------------------------------------------------------------------

#include "antares.h"
#include "Loop/Game/GameMode/CGameMode.h"
#include "Loop/Game/Ents/CEntity.h"
#include "Loop/Game/Ents/CPlayer.h"
#include "Loop/Game/Ents/CCamera.h"
#include "Loop/Game/GameMode/History/Levels/CGMHLevel.h"
#include "Loop/Game/GameMode/History/Minimap/CGMHMiniMap.h"
#include "Loop/Game/GameMode/History/GMHMIG/CGMHMIG.h"
#include "HUD/CHUDScene.h"
#include "Loop/Cinematic/CCINScene.h"

// -----------------------------------------------------------------------------
typedef enum TGMHState
{
	GMHSTATE_NONE   = GM_STATE_NONE,
	GMHSTATE_INIT   = GM_STATE_INIT,
	GMHSTATE_FINISH = GM_STATE_FINISH,
	
	GMHSTATE_BLOCKINGFINISH,

	GMHSTATE_READY,
	GMHSTATE_READYMESSAGE,

	GMHSTATE_JUSTBEFORERUN,	
	GMHSTATE_RUN,
	
	GMHSTATE_DEAD,
	
	GMHSTATE_STARTTIMEOVER,
	GMHSTATE_TIMEOVER,
	GMHSTATE_ENDTIMEOVER,

	GMHSTATE_STARTVICTORY,
	GMHSTATE_VICTORY,
	GMHSTATE_ENDVICTORY,
	
	GMHSTATE_GAMEOVER,
	
	GMHSTATE_INTROSTART,
	GMHSTATE_INTRO,
	GMHSTATE_INTROEND,
	
	GMHSTATE_OUTROSTART,
	GMHSTATE_OUTRO,
	GMHSTATE_OUTROEND,
	
	GMHSTATE_MENUINGAMESTART,	
	GMHSTATE_MENUINGAME,
	GMHSTATE_MENUINGAMEEND,
};
// -----------------------------------------------------------------------------
extern unsigned int     guiLevel;

extern unsigned int		guiGameFrame;
extern unsigned int		guiGameTime;
extern unsigned int		guiGameRocks;
extern unsigned int		guiGameNeedRocks;
extern unsigned int		guiGameMaxTime;
// -----------------------------------------------------------------------------
class CGMHistory : public CGameMode
{
public:
	CGMHistory();

	virtual void Init(int _iLevel,int _iSkill);
	virtual void Finish();
	virtual void Reset();

	virtual void Think(float _fDeltaT);
	virtual bool bInteractiveAction(TInteractiveAction _eAction,CEntity *_poSrc,CEntity* _poDst,void *_pParam = NULL);
	
	bool bIA_Player(TInteractiveAction _eAction,CEntity *_poSrc,CEntity* _poDst,void *_pParam);
	bool bIA_Rock  (TInteractiveAction _eAction,CEntity *_poSrc,CEntity* _poDst,void *_pParam);
		
	void SetState(TGMHState _eState);	
	
	void EnablePowerUp();
	void DisablePowerUp();
	void HandlePowerUp();

public:

	int			m_iLevel;	
	int			m_iNextState;
	
	float		m_fTime;
	float		m_fGTime;
	float		m_fPUpTime;
	int			m_iTotalRocks;
	int			m_iNeedRocks;
	int			m_iCurRocks;
	
	int			m_iCurPUp;
	
	float		m_fMaxTime;
	TGMHState	m_eSubState;

	CGMHLevel*	m_poLevel;
	CPlayer*	m_poPlayer;
	CCamera*	m_poCam;
	
	CHUDScene*  m_poHScn;
	CCINScene*	m_poIntroCIN;
	CCINScene*	m_poOutroCIN;
	
	unsigned int m_uiGoalSFX;
	CGMHMinimap  m_oMiniMap;
	CGMHMIG		 m_oMIG;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------