// -----------------------------------------------------------------------------
#ifndef CEntityMgrH
#define CEntityMgrH
// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "CEntity.h"
#include "EntityIDs.h"
#include "Game/cgameglobals.h"

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
class CEntityMgr
{
	public:
		static void Reset();
		static void Think(float _fDeltaT);
		static int  iAddEntity(CEntity *_poEnt);
		static void DeleteEntity(CEntity *_poEnt);
		static CEntity *poGetEntity(int _iEntID);

	public:
		// Circular queue
		static CEntity* m_poList[MAX_ENTITIES];
		static int 		m_iNumEnt;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
