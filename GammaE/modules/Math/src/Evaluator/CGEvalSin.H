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
#ifndef CGEvalSinH
#define CGEvalSinH
// ----------------------------------------------------------------------------
// CGEvalPeriodic
#include <assert.h>
#include "CGEvalPeriodic.h"
#include "Other\GMathCommon.h"
// ----------------------------------------------------------------------------
class CGEvalSin : public CGEvalPeriodic
{
    public:
        virtual float fGetValue();
};
// ----------------------------------------------------------------------------
inline float CGEvalSin::fGetValue ()
{
    assert (m_poAmplitude && "Evaluator with NULL Amplitude param");
    assert (m_poFreqMult && "Evaluator with NULL Frequency param");
    assert (m_poPhase && "Evaluator with NULL Phase param");

    return( m_poAmplitude->fGetValue() * Math::fSin( m_poFreqMult->fGetValue() * m_poPhase->fGetValue() ) );
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
