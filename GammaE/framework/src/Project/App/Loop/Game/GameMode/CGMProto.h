// -----------------------------------------------------------------------------
#ifndef CGMProtoH
#define CGMProtoH
// -----------------------------------------------------------------------------
#include "GammaE.h"
#include "App/Loop/Game/Entities/CPlayer.h"
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
class CGMProto : public CGGameMode
{
public:
	CGMProto();

	virtual void Init(uint _uiLevel,uint _uiSkill);
	virtual void Finish();
	virtual void Reset();

	virtual void Think(float _fDeltaT);
	virtual void Render();
	
	virtual void HandleMessageQueue();

	virtual void HandleCollisionMsg(CGGameMessage& _oMsg);
	virtual void HandleSpawnMsg(CGGameMessage& _oMsg);
	virtual void HandleDestructionMsg(CGGameMessage& _oMsg);

	void SetState(TGMPState _eState);	
	
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
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------