// -----------------------------------------------------------------------------
#ifndef CGPathResourceH
#define CGPathResourceH
// -----------------------------------------------------------------------------
#include "CGPath.h"
// -----------------------------------------------------------------------------
class CGPathResource : public CGResource
{
	public:

		void SetPath(CGPath* _poPath) { m_poPath = _poPath; };
		CGPath* poGetPath() { return(m_poPath); };

	protected:

		/// Stores the path resource
		CGPath* m_poPath;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
