// -----------------------------------------------------------------------------
#ifndef CExplosionMgrH
#define CExplosionMgrH

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "antares.h"
class CExplosion;

// -----------------------------------------------------------------------------
typedef enum EExplosionType {
	ET_NONE,
	ET_PLASMA,
	ET_LASER,
	ET_PLAYER,
	ET_ENEMYGENERIC,
	ET_ENEMY1,
	ET_NUMEXPLOSIONS
};
// -----------------------------------------------------------------------------

// Function prototypes
// -----------------------------------------------------------------------------
class CExplosionMgr
{
	public:
		
		// Initialize 
		static void Init();
		
		// Add a new explosion
		static void AddExplosion(EExplosionType _eExplosionType,MTH_CPoint3& _oPos);

		// Update the active explosions
		static void Update(float _fDeltaT);
		
		// Rendering process for any of the 
		static void Render();

	protected:

		//
		static MEM_DynamicArray <CExplosion*> m_oExp;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
