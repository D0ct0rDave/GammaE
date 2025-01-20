// -----------------------------------------------------------------------------
#ifndef CGMProtoH
#define CGMProtoH
// -----------------------------------------------------------------------------

#include "antares.h"
#include "Game/GameMode/CGameMode.h"
#include "Game/Ents/CEntity.h"
#include "Game/Ents/CPlayer.h"
#include "Game/Ents/CCamera.h"
// -----------------------------------------------------------------------------
// Forward declarations
// -----------------------------------------------------------------------------
typedef struct TEntityMessage;

// -----------------------------------------------------------------------------
typedef enum TGMPState
{
	GMPSTATE_NONE   = GM_STATE_NONE,
	GMPSTATE_INIT   = GM_STATE_INIT,
	GMPSTATE_FINISH = GM_STATE_FINISH,
	
	GMPSTATE_BLOCKINGFINISH,

	GMPSTATE_READY,
	GMPSTATE_READYMESSAGE,

	GMPSTATE_JUSTBEFORERUN,	
	GMPSTATE_RUN,
	
	GMPSTATE_DEAD,
	
	GMPSTATE_STARTTIMEOVER,
	GMPSTATE_TIMEOVER,
	GMPSTATE_ENDTIMEOVER,

	GMPSTATE_STARTVICTORY,
	GMPSTATE_VICTORY,
	GMPSTATE_ENDVICTORY,
	
	GMPSTATE_GAMEOVER,
	
	GMPSTATE_INTROSTART,
	GMPSTATE_INTRO,
	GMPSTATE_INTROEND,
	
	GMPSTATE_OUTROSTART,
	GMPSTATE_OUTRO,
	GMPSTATE_OUTROEND,
	
	GMPSTATE_MENUINGAMESTART,	
	GMPSTATE_MENUINGAME,
	GMPSTATE_MENUINGAMEEND,
};
// -----------------------------------------------------------------------------
extern unsigned int     guiLevel;
extern unsigned int		guiGameFrame;
extern unsigned int		guiGameTime;
extern unsigned int		guiGameRocks;
extern unsigned int		guiGameNeedRocks;
extern unsigned int		guiGameMaxTime;
// -----------------------------------------------------------------------------
class CGMProto : public CGameMode
{
public:
	CGMProto();

	virtual void Init(int _iLevel,int _iSkill);
	virtual void Finish();
	virtual void Reset();

	virtual void Think(float _fDeltaT);
	virtual void Render();
	
	virtual void HandleMessageQueue();
	
	virtual void HandleCollisionMsg(TEntityMessage& _oMsg);
	virtual void HandleSpawnMsg(TEntityMessage& _oMsg);
	virtual void HandleDestructionMsg(TEntityMessage& _oMsg);

	void SetState(TGMPState _eState);	
	
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
	TGMPState	m_eSubState;
	
	CPlayer*	m_poPlayer;
	CCamera*	m_poCam;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------