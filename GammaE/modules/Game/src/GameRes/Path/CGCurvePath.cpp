// -----------------------------------------------------------------------------
#include "CGCurvePath.h"
// -----------------------------------------------------------------------------
void CGCurvePath::Init(CCurve* _poCurve)
{
	m_poCurve = _poCurve;
	
	m_fPathTime = 0.0f;

	for (uint i=0;i<m_poCurve->uiNumControlPoints();i++)
		m_fPathTime += m_poCurve->poControlPoints()[i].z;	
}
// -----------------------------------------------------------------------------
const CVect3& CGCurvePath::oPos(float _fFact)
{
	return ( m_poCurve->oPos(_fFact) );
}
// -----------------------------------------------------------------------------