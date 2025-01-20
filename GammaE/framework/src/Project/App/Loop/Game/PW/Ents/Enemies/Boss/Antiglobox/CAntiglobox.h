// -----------------------------------------------------------------------------
#ifndef CAntiGloboxH
#define CAntiGloboxH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Loop/Game/Ents/CEntity.h"
// -----------------------------------------------------------------------------
class CAntiGlobox : public CEntity
{
public:	
		 CAntiGlobox();
		~CAntiGlobox();

		// AI/Think
		virtual void Init(MTH_CPoint3& _oPos);
		virtual void Think(float _fDeltaT);
		
		virtual void CheckNewPos(float _fDeltaT);

public:
		GEOM_Frame*	m_poFrame;
		int			m_iRI;
};
// -----------------------------------------------------------------------------
#define ENTSTATE_STARTMOVING	11	// START MOVEMENT
#define ENTSTATE_RETMOVING		12  // RETAINING MOVEMENT
#define ENTSTATE_MOVING			13  // MOVING
#define ENTSTATE_OUT			14
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------