//-----------------------------------------------------------------------------
/*! \class CGameCamera
 *  \brief A game entity that handles the flow of the game play by scripting
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
//-----------------------------------------------------------------------------
#ifndef CGameCameraH
#define CGameCameraH
//-----------------------------------------------------------------------------
#include "GammaE.h"
//-----------------------------------------------------------------------------
class CGameCamera : public CGGameEntity
{
	public:
		PUBLISH_GAMEENTITY_CLASSNAME;
	
		CGameCamera();
		~CGameCamera();

		void Init();
		virtual void Think(float _fDeltaT);
		virtual void UpdatePos(const CGVect3& _oNewPos);
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
