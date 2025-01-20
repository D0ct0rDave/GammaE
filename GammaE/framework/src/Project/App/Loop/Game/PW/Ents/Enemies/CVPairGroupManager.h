// -----------------------------------------------------------------------------
#ifndef CVPairGroupManagerH
#define CVPairGroupManagerH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Loop/Special/Game/Ents/Enemies/CGroupManager.h"

class CVPairGroupManager : public CGroupManager
{
public:
		 CVPairGroupManager();
		~CVPairGroupManager();

		// AI/Think
		virtual void Init(MTH_CPoint3& _oPos,int _iSubType);
		virtual void Think(float _fDeltaT);

protected:

};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------