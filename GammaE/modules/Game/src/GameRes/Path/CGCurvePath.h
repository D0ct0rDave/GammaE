// -----------------------------------------------------------------------------
#ifndef CGCurvePathH
#define CGCurvePathH
// -----------------------------------------------------------------------------
#include "GammaE_Math.h"
#include "CGPath.h"
// -----------------------------------------------------------------------------
class CGCurvePath : public CGPath
{
	public:	
		/// Retrieves the position of the path for a given factor between  (0..1)
		virtual const CVect3& oPos(float _fFact);

		/// Initializes the path with the given curve
		void Init(CCurve* _poCurve);
		
		/// Retrieves the time of the path
		float fTime() { return(m_fPathTime); };

	protected:
		CCurve*		m_poCurve;
		float		m_fPathTime;
		
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
