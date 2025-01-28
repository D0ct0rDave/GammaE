// -----------------------------------------------------------------------------
#ifndef CEnemyH
#define CEnemyH
// -----------------------------------------------------------------------------
#include "GammaE.h"
// -----------------------------------------------------------------------------
class CEnemy : public CGGameEntity
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
