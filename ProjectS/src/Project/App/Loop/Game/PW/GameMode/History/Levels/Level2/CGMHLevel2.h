// -----------------------------------------------------------------------------
#ifndef CGMHLevel2H
#define CGMHLevel2H
// -----------------------------------------------------------------------------
#include "Loop/Game/GameMode/History/Levels/CGMHLevel.h"
// -----------------------------------------------------------------------------
class CGMHLevel2 : public CGMHLevel
{
public:

	virtual void Init(int _iSkill);
	virtual void Finish();
	virtual void Reset();
	virtual void Think(float _fDeltaT);

	void RespawnRock();

	CActor*			m_poPollo;
	unsigned int	m_uiPrevScoredRocks;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------