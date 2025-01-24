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
#include "CGSmoother.h"
#include "other/GMathCommon.h"
// ----------------------------------------------------------------------------
void CGSmoother::Init(float _fSmoothFact)
{
    m_fAccum = 0.0f;
    m_fSmoothFact = Math::fClamp(0.0f,1.0f,_fSmoothFact);
}
// ----------------------------------------------------------------------------
float CGSmoother::fValue(float _fInputVal)
{
    if ( m_fSmoothFact > 100.0f )
    {
        int A = 0;
    }

    if ( m_fAccum > 100.0f )
    {
        int A = 0;
    }
    // float fNewVal = fClamp(0.0f,1.0f,_fInputVal);

    float fRet = Math::fLerp(m_fAccum,_fInputVal,m_fSmoothFact);
    m_fAccum = (m_fAccum + fRet) * 0.5f;

    return(fRet);
}
// ----------------------------------------------------------------------------
