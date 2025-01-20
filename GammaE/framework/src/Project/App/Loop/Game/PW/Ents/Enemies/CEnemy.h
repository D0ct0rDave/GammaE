// -----------------------------------------------------------------------------
#ifndef CEnemyH
#define CEnemyH

// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/CVisEntity.h"

class CEnemy : public CVisEntity
{
public:	
		 CEnemy();
		~CEnemy();
		virtual void Init();
		virtual bool bDamage(float _fEnergy);
		void Energy(float _fEnergy) { m_fEnergy = _fEnergy; };

public:
		float	m_fEnergy;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
