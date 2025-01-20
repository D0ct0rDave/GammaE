// -----------------------------------------------------------------------------
#ifndef CGameH
#define CGameH
// -----------------------------------------------------------------------------

#include "antares.h"
#include "Game/GameMode/CGameMode.h"

// -----------------------------------------------------------------------------
#define GAMEMODE_HISTORY	0
#define GAMEMODE_CHALLENGE	1
// -----------------------------------------------------------------------------
class CGame
{
public:
	static void Init();
	static void SetGameMode(int _iGMode,int _iLevel,int _iSkill);
	
	static void Finish();
	static void Think(float& _fDeltaT);
	static void Render();
	static void Reset();

public:
	static int			m_iGMode;
	static int			m_iLevel;
	static int			m_iState;
	static int			m_iFrame;
	static float		m_fTime;
	static CGameMode*	m_poGM;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------