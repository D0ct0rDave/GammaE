// ----------------------------------------------------------------------
#include "CGMHMIG.h"
#include "Loop/Game/CGameGlobals.h"
#include "HUD/CHUDManager.h"
// ----------------------------------------------------------------------

#define GMHHUD_FRAME_ICON		0
#define GMHHUD_CONT_EXIT_ICON	1
#define GMHHUD_YES_NO_ICON		2
#define GMHHUD_CURSOR_ICON		3

float gafCursorPos[2][2][2] = 
{
	// (Continue / Exit) Screen
	{
		{-0.32f,0.1f},	// Cont
		{-0.225f,-0.15f},	// Exit
		
	},
	
	// (Yes / No) Screen
	{		
		{-0.32f,-0.15f},	// Yes
		{0.33f,-0.15f},	// No
	},
};

// ----------------------------------------------------------------------
CGMHMIG::CGMHMIG()
{
}
// -----------------------------------------------------------------------------
void CGMHMIG::Init()
{
	m_poMIGScn = pNew CHUDScene;
	m_poMIGScn->bLoadScene("data/GameMode/History/MIG/GMHMIG.cfg");

	m_eState  = MIGS_Ready;

}
// --------------------------------------------------------
void CGMHMIG::Finish()
{
	vDelete m_poMIGScn;
	m_poMIGScn = NULL;
}
// --------------------------------------------------------
void CGMHMIG::Reset()
{
}
// --------------------------------------------------------
void CGMHMIG::Think(float _fDeltaT)
{
	switch (m_eState)
	{
		// ------------------------------------
		case MIGS_Enabling:
		m_eState = MIGS_Ready;
		break;

		// ------------------------------------
		case MIGS_Disabling:
		m_eState = MIGS_Ready;
		break;
		
		// ------------------------------------
		case MIGS_Ready:
		{
			m_eOrder = MIGO_Processing;

			if (gaInput[0].justpressed.start)
			{
				m_eState = MIGS_Disabling;
				m_eOrder = MIGO_Continue;
			}
			else
			{
				// ------------------------------------
				switch (m_iScr)
				{
					// ------------------------------------
					// Continue/Exit screen
					case 0:
					{
						if (gaInput[0].justpressed.up)
						{
							m_iOpt = m_iOpt - 1; 
							if (m_iOpt<0) m_iOpt = 1;
						}

						if (gaInput[0].justpressed.down)
						{
							m_iOpt = m_iOpt + 1; 
							if (m_iOpt >= 2) m_iOpt = 0;
						}
						
						if (gaInput[0].justpressed.A)
						{
							if (m_iOpt == 1)
							{
								m_iScr ++;
								m_poMIGScn->m_oHUDObj[GMHHUD_CONT_EXIT_ICON]->Disable();
								m_poMIGScn->m_oHUDObj[GMHHUD_YES_NO_ICON   ]->Enable();
							}
							else
							{
								//
								m_eOrder = MIGO_Continue;
							}
						}
					}
					break;

					// ------------------------------------
					// Yes/No Screen
					case 1:
					{
						if (gaInput[0].justpressed.left)
						{
							m_iOpt = m_iOpt - 1; 
							if (m_iOpt<0) m_iOpt = 1;
						}

						if (gaInput[0].justpressed.right)
						{
							m_iOpt = m_iOpt + 1; 
							if (m_iOpt >= 2) m_iOpt = 0;
						}
						
						if (gaInput[0].justpressed.A)
						{
							if (m_iOpt == 0)
							{
								//
								m_eOrder = MIGO_Exit;
							}
							else
							{
								m_poMIGScn->m_oHUDObj[GMHHUD_CONT_EXIT_ICON]->Enable();
								m_poMIGScn->m_oHUDObj[GMHHUD_YES_NO_ICON   ]->Disable();
								m_iScr --;
							}
						}
					}
					break;
				}
			}

			m_poMIGScn->m_oHUDObj[GMHHUD_CURSOR_ICON]->m_fXPos = gafCursorPos[m_iScr][m_iOpt][0];
			m_poMIGScn->m_oHUDObj[GMHHUD_CURSOR_ICON]->m_fYPos = gafCursorPos[m_iScr][m_iOpt][1];
		}
		break;
	}
}
// --------------------------------------------------------
void CGMHMIG::Enable()
{
	m_poOldScn = CHUDManager::poGetCurrent();
	CHUDManager::SetAsCurrent(m_poMIGScn);


	// Reinit Menu In Game Components
	m_iScr = 0;
	m_iOpt = 0;
	
	m_poMIGScn->m_oHUDObj[GMHHUD_CONT_EXIT_ICON]->Enable();
	m_poMIGScn->m_oHUDObj[GMHHUD_YES_NO_ICON   ]->Disable();

	m_eState = MIGS_Enabling;
}
// --------------------------------------------------------
void CGMHMIG::Disable()
{
	CHUDManager::SetAsCurrent(m_poOldScn);
	m_eState = MIGS_Disabling;
}
// --------------------------------------------------------