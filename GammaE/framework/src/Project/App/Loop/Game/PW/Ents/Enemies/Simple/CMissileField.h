// -----------------------------------------------------------------------------
#ifndef CMissileFieldH
#define CMissileFieldH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Loop/Special/Game/Ents/Enemies/CGroupManager.h"

class CMissileField : public CGroupManager
{
public:
		 CMissileField();
		~CMissileField();

		// AI/Think
		virtual void Init(float _fPos,float _fTime,float _fDensity);
		virtual void Think(float _fDeltaT);

protected:

	float m_fMaxTime;
	uint  m_uiMaxMissiles;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------