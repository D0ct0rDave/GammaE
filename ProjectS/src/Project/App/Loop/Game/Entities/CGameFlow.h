//-----------------------------------------------------------------------------
/*! \class CGameFlow
 *  \brief A game entity that handles the flow of the game play by scripting
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
//-----------------------------------------------------------------------------
#ifndef CGameFlowH
#define CGameFlowH
//-----------------------------------------------------------------------------
#include "GammaE.h"
//-----------------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGameFlow,public,CGGameEntity)
{
	public:

		PUBLISH_GAMEENTITY_CLASSNAME;
		
		/// Initializes the game flow entity
		void Init();
		
		/// Reinits the game flow entity and clears all the created entities
		void Reinit();

	public:

		CGStArray<CGGameEntity*> m_poEntities;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
