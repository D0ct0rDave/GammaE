//-----------------------------------------------------------------------------
#ifndef CGameH
#define CGameH
// -----------------------------------------------------------------------------
#include "GammaE.h"
// -----------------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGame,public,CGGameBase)
{
	public:
		/// Initialize the game object
		virtual void Init(uint _uiGMode,uint _uiLevel,uint _uiSkill);
		virtual void Render();
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------