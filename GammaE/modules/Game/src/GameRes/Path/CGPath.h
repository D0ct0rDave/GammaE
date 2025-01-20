// -----------------------------------------------------------------------------
#ifndef CGPathH
#define CGPathH
// -----------------------------------------------------------------------------
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
class CGPath
{
	public:	
		/// Retrieves the position of the path for a given factor between  (0..1)
		virtual const CVect3& oPos(float _fFact) = 0;
		
		/// Time to traverse the full path
		virtual float fTime() = 0;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
