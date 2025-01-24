// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "CGLight.h"
// ----------------------------------------------------------------------------
CGLight::CGLight()
{
    m_oLitAmb = CGColor(1,1,1,1);
    m_oLitDiff = CGColor(1,1,1,1);
    m_oLitSpec = CGColor(1,1,1,1);

    m_oPos.Set(0.0f,0.0f,0.0f);
    m_oDir.Set(0.0f,0.0f,1.0f);

    // For spot lights
    m_fSpCutOff = 180.0f;
    m_fSpExp = 0.0f;

    m_fCAtt = 1.0f;
    m_fLAtt = 0.0f;
    m_fQAtt = 0.0f;

    m_eType = LT_Point;
}

CGLight::~CGLight()
{
}
// ----------------------------------------------------------------------------
