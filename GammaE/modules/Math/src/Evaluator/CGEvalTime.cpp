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
#include "GammaE_Misc.h"
// CGEvalTime
#include "CGEvalTime.h"

// ----------------------------------------------------------------------------
CGEvalTime::CGEvalTime()
{
    m_oChrono.Reset();
    m_oChrono.Start();
}

CGEvalTime::~CGEvalTime()
{
}

float CGEvalTime::fGetValue ()
{
    return ( (float)m_oChrono.dElapsedTime() );
}
// ----------------------------------------------------------------------------
