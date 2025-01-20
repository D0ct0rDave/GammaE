// -----------------------------------------------------------------------------
#ifndef CGMHLevelPruebasH
#define CGMHLevelPruebasH
// -----------------------------------------------------------------------------
#include "Loop/Game/GameMode/History/Levels/CGMHLevel.h"
// -----------------------------------------------------------------------------
#define MAX_E1 50
class CGMHLevelPruebas : public CGMHLevel
{
public:

	virtual void Init(int _iSkill);
	virtual void Finish();
	virtual void Reset();
	virtual void CreateLevelEntities();

	virtual void Think();

public:
	bool		m_bCreateEnemies;
	CVisEntity*	m_poE1[MAX_E1];
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------