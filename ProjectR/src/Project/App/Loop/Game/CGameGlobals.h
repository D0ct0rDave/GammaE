// ----------------------------------------------------------------------------
#ifndef CGameGlobalsH
#define CGameGlobalsH
// ----------------------------------------------------------------------------
#include "GammaE.h"
// ----------------------------------------------------------------------------
// Game Messages: Application dependent protocol between game / game entities
// ----------------------------------------------------------------------------
#define GMSG_NONE			0
#define GMSG_SPAWN			1
#define GMSG_DESTRUCTION	2
#define GMSG_COLLISION		3
#define GMSG_UPDATEHUD		4
// ----------------------------------------------------------------------------
const CGString SCRIPT_PATH = "data/scripts";


// ----------------------------------------------------------------------------
class CGameGlobals
{
	public:

		CObject3D_Camera			m_oCamera;	
		CE3D_Viewport		   		m_oViewport;

		// CE3D_Camera			   		m_oOrthoCam;
		// CE3D_Projector		   		m_oOrthoPrj;

		CE3D_Camera			   		m_oPerspCam;
		CE3D_Projector		   		m_oPerspPrj;
		
		CGGameEntity*				m_poPlayer;
};

extern CGameGlobals gameGlobals;
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------