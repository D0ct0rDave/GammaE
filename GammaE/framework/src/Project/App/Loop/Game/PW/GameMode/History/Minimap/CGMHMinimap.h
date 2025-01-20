// -----------------------------------------------------------------------------
#ifndef CGMHMinimapH
#define CGMHMinimapH
// -----------------------------------------------------------------------------

#include "antares.h"
#include "Loop/Game/GameMode/History/Levels/CGMHLevel.h"
#include "HUD/CHUDScene.h"
#include "HUD/CHUDIcon.h"

// -----------------------------------------------------------------------------
class CGMHMinimap
{
public:
	CGMHMinimap();

	void Init(CGMHLevel* _poLevel,CHUDScene*  _poHScn);
	void Finish();
	void Reset();

	void Think(float _fDeltaT);

	MTH_CPoint3 oGetMiniMapPos(MTH_CPoint3& _oWorldPos);
	void EnableGoal();
	
public:
	CGMHLevel*	m_poLevel;
	CHUDScene*  m_poHScn;

	CHUDIcon*	m_poMiniMap;	// Minimap
	CHUDIcon*	m_poPIco;		// Player icon

private:	
	//
	bool		m_bEnableGoal;
};

inline void CGMHMinimap::EnableGoal()
{
	m_bEnableGoal = true;
}
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------