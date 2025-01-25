// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include "CGCurvePath.h"
// -----------------------------------------------------------------------------
void CGCurvePath::Init(CCurve* _poCurve)
{
    m_poCurve = _poCurve;

    m_fPathTime = 0.0f;

    for ( uint i = 0; i < m_poCurve->uiNumControlPoints(); i++ )
        m_fPathTime += m_poCurve->poControlPoints()[i].z;
}
// -----------------------------------------------------------------------------
const CGVect3& CGCurvePath::oPos(float _fFact)
{
    return ( m_poCurve->oPos(_fFact) );
}
// -----------------------------------------------------------------------------
