// -----------------------------------------------------------------------------
#ifndef CGMHLevel1H
#define CGMHLevel1H
// -----------------------------------------------------------------------------
#include "Loop/Game/GameMode/History/Levels/CGMHLevel.h"
// -----------------------------------------------------------------------------
class CGMHLevel1 : public CGMHLevel
{
public:

	virtual void Init(int _iSkill);
	virtual void Finish();
	virtual void Reset();
	virtual void CreateLevelEntities();

	virtual void Think(float _fDeltaT);
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------