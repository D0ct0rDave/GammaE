// -----------------------------------------------------------------------------
#ifndef CFollowerGroupEnemyH
#define CFollowerGroupEnemyH

// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/Enemies/CFollowerGroupEntity.h"

class CFollowerGroupEnemy : public CFollowerGroupEntity
{
public:	
		 CFollowerGroupEnemy();
		~CFollowerGroupEnemy();
		
		void Init(int _iSubType,char*_szFilename,float _fSpawnPeriod = 0.0f);
		virtual void Think(float _fDeltaT);

public:
		float	m_fSpawnPeriod;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
