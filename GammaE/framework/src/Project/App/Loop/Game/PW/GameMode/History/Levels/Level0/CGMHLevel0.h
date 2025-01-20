// -----------------------------------------------------------------------------
#ifndef CGMHLevel0H
#define CGMHLevel0H
// -----------------------------------------------------------------------------
#include "Loop/Game/GameMode/History/Levels/CGMHLevel.h"
// -----------------------------------------------------------------------------
class CGMHLevel0 : public CGMHLevel
{
	
public:

	virtual void Init(int _iSkill);
	virtual void Finish();
	virtual void Reset();
		
	virtual void Think(float _fDeltaT);
	virtual void RespawnRock();	
public:
	unsigned int m_uiFL[8];
	bool		 m_bWaitingPlayerToFinish;	
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------