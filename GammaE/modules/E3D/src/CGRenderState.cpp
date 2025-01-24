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
#include "CGRenderState.h"
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
CGRenderState::CGRenderState()
    : m_bDefferredMode(false), m_bFrustumCulling(false), m_bBVRender(false), m_bNormalRender(false), m_bFlatRender(false)
{
}
// -----------------------------------------------------------------------------
CGRenderState::~CGRenderState()
{
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
