//-----------------------------------------------------------------------------
/*! \class CLavadora
 *  \brief A game entity that handles the flow of the game play by scripting
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
//-----------------------------------------------------------------------------
#ifndef CLavadoraH
#define CLavadoraH
//-----------------------------------------------------------------------------
#include "GammaE.h"
//-----------------------------------------------------------------------------
class CLavadora : public CGGameEntity
{
	public:
		PUBLISH_GAMEENTITY_CLASSNAME();
	
		CLavadora();
		~CLavadora();

		void Init();
		virtual void Think(float _fDeltaT);
		virtual void UpdatePos(const CVect3& _oNewPos);
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
