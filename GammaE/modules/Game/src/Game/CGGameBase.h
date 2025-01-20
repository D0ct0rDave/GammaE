//-----------------------------------------------------------------------------
/*! \class CGGameBase
 *  \brief Base class for game logic management. Typically derive it in the form of a singleton for the specific game
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
//-----------------------------------------------------------------------------
#ifndef CGGameBaseH
#define CGGameBaseH
//-----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGGameMode.h"
//-----------------------------------------------------------------------------
class CGGameBase
{
	public:
		CGGameBase();
		
		/// Initialize the game object. 
		virtual void Init(uint _uiGMode,uint _uiLevel,uint _uiSkill);
		
		/// Finishes the game and frees resources. 
		virtual void Finish();
		
		/// Performs a game logic step. 
		virtual void Think(float& _fDeltaT);
		
		/// Renders anything related to the game. 
		virtual void Render();
		
		/// Restarts the game to the initial state. 
		virtual void Reset();

	protected:

		uint			m_uiGMode;
		uint			m_uiLevel;
		uint			m_uiSkill;
		uint			m_uiState;

		uint			m_uiFrame;
		float			m_fTime;

		CGGameMode*		m_poGM;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
