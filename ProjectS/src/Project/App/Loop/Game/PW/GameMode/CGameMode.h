// -----------------------------------------------------------------------------
#ifndef CGameModeH
#define CGameModeH
// -----------------------------------------------------------------------------

#include "antares.h"
#include "Game/Ents/CEntity.h"
// -----------------------------------------------------------------------------
#define GM_SKILLHARD	2
#define GM_SKILLMEDIUM  1
#define GM_SKILLEASY	0

typedef enum TGMState
{
	GM_STATE_NONE,
	GM_STATE_INIT,
	GM_STATE_FINISH,
	GM_STATE_RUN,
	GM_STATE_PAUSED,
	GM_STATE_NUMGMSTATES
};

// Interactive Action
typedef enum TInteractiveAction{

	IA_Collision,
	
	IA_Push,
	IA_PushLeft,
	IA_PushRight,
	IA_PushUp,
	IA_PushDown,

	IA_Pull,
	IA_PullLeft,
	IA_PullRight,
	IA_PullTop,
	IA_PullUp,
	IA_PullDown,

	IA_NumActions,
};

// -----------------------------------------------------------------------------
class CGameMode
{
public:
	virtual void Init(int _iLevel,int _iSkill) = 0;
	virtual void Finish() = 0;
	virtual void Reset() = 0;

	virtual void Think(float _fDeltaT) = 0;
	virtual void Render() = 0;

	virtual void HandleMessageQueue() = 0;
		
	TGMState	m_eState;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------