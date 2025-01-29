// ----------------------------------------------------------------------------
#ifndef CGameGlobalsH
#define CGameGlobalsH
// ----------------------------------------------------------------------------
#include "GammaE.h"
#include "App/Loop/Game/GameScene/CGameMap.h"
// ----------------------------------------------------------------------------
// Game Messages: Application dependent protocol between game / game entities
// ----------------------------------------------------------------------------
#define GMSG_NONE			0
#define GMSG_SPAWN			1
#define GMSG_DESTRUCTION	2
#define GMSG_COLLISION		3
#define GMSG_UPDATEHUD		4
const float GROUND_HEIGHT	= -8.0f;
// ----------------------------------------------------------------------------
const CGString SCRIPT_PATH = "data/scripts";
// ----------------------------------------------------------------------------
// const CGString PLAYER_MODEL = "data/actors/BrainSlug/BrainSlug.gem";
// const CGString PLAYER_MODEL = "data/actors/MarvinPig/MarvinPig.gem";
const CGString PLAYER_MODEL = "data/actors/legs_robot_walk.gem";
// const CGString PLAYER_MODEL = "data/actors/egg/egg.gem";


// ----------------------------------------------------------------------------
class CGameGlobals
{
	public:

		CGSceneCamera			m_oCamera;	
		CGViewport		   		m_oViewport;

		// CE3D_Camera			   		m_oOrthoCam;
		// CE3D_Projector		   		m_oOrthoPrj;

		CGCamera			   		m_oPerspCam;
		CGProjector		   			m_oPerspPrj;
		
		CGGameEntity*				m_poPlayer;
		CGameMap*					m_poMap;
		CGSceneAnimActionSet*		m_poLavadora;
};

extern CGameGlobals gameGlobals;
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------