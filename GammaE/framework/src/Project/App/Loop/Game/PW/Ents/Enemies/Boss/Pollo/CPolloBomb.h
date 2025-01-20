// -----------------------------------------------------------------------------
#ifndef CPolloBombH
#define CPolloBombH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Loop/Game/Ents/CActor.h"

class CPolloBomb : public CEntity
{
public:	
		 CPolloBomb();
		~CPolloBomb();

		// AI/Think
		virtual void Init(MTH_CPoint3& _oPos);
		virtual void Think(float _fDeltaT);
		virtual void CheckNewPos(float _fDeltaT);
		virtual void Init(MTH_CPoint3& _oPos,MTH_CPoint3& _oSpd);
public:
		unsigned int m_uiSFX;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------