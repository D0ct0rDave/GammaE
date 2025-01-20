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
// ----------------------------------------------------------------------------
typedef struct TPlayerInput{

	float	m_fUp;
	float	m_fDown;
	float	m_fLeft;
	float	m_fRight;

	bool	m_bFire;
	
	// Other inputs

}TPlayerInput;
// ----------------------------------------------------------------------------
class CGameGlobals
{
	public:

		CObject3D_Camera			m_oCamera;	
		CE3D_Viewport		   		m_oViewport;

		CE3D_Camera			   		m_oOrthoCam;
		CE3D_Projector		   		m_oOrthoPrj;

		CE3D_Camera			   		m_oPerspCam;
		CE3D_Projector		   		m_oPerspPrj;
		
		TPlayerInput				m_oPlayerInputs;
};

extern CGameGlobals gameGlobals;
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------