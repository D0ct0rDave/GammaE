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
#include "GammaE_Mem.h"
#include "CGEvalPeriodic.h"
// ----------------------------------------------------------------------------
CGEvalPeriodic::CGEvalPeriodic() : m_poAmplitude(NULL), m_poPhase(NULL), m_poFreqMult(NULL)
{
}
// ----------------------------------------------------------------------------
CGEvalPeriodic::~CGEvalPeriodic()
{
    if ( m_poAmplitude ) mDel m_poAmplitude;
    if ( m_poPhase ) mDel m_poPhase;
    if ( m_poFreqMult ) mDel m_poFreqMult;
}
// ----------------------------------------------------------------------------
