// -----------------------------------------------------------------------------
#include "CGame.h"
#include "CGameGlobals.h"

#include "Game/Ents/CEntityMgr.h"
#include "Game/GameGraphics/CEntRend.h"
#include "Game/GameMode/Prototype/CGMProto.h"


// -----------------------------------------------------------------------------
int			CGame::m_iGMode;
int			CGame::m_iLevel;

int			CGame::m_iState;
float		CGame::m_fTime;
int			CGame::m_iFrame;
CGameMode*	CGame::m_poGM;
// -----------------------------------------------------------------------------

void CGame::Init()
{
	// Init the entity manager
	CEntityMgr::Reset();
}
// -----------------------------------------------------------------------------
void CGame::SetGameMode(int _iGMode,int _iLevel,int _iSkill)
{
	switch (_iGMode)
	{
		case GAMEMODE_HISTORY:
		{
			// Create prototype game
			m_poGM = pNew CGMProto;
			m_poGM->Init(_iLevel,_iSkill);
		}
		break;

		case GAMEMODE_CHALLENGE:
		{
			
		}
		break;
	}
}
// -----------------------------------------------------------------------------
void CGame::Finish()
{
	if (m_poGM != NULL)
	{
		m_poGM->Finish();

		vDelete m_poGM;
		m_poGM = NULL;
	}
}
// -----------------------------------------------------------------------------
void CGame::Think(float& _fDeltaT)
{
	bool bGamePaused = false;

	if (m_poGM)
		bGamePaused = (m_poGM->m_eState == GM_STATE_PAUSED) || (m_poGM->m_eState == GM_STATE_FINISH);

	if (! bGamePaused)
	{
		// Singletons
		CEntityMgr::Think(_fDeltaT);
		CEntRend::Update(_fDeltaT);
	}

	if (bGamePaused)
		_fDeltaT = 0.0f;

	if (m_poGM)
		m_poGM->Think(_fDeltaT);

	gfLastGlobalTime = gfGlobalTime;
	gfGlobalTime	+= _fDeltaT;
}
// -----------------------------------------------------------------------------
void CGame::Render()
{
	CEntRend::Render();

	if (m_poGM)
		m_poGM->Render();
}
// -----------------------------------------------------------------------------
void CGame::Reset()
{
}
// -----------------------------------------------------------------------------