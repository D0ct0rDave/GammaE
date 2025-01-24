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
#ifndef CGEvalSawToothH
#define CGEvalSawToothH
// ----------------------------------------------------------------------------
#include <assert.h>
#include "Other\GMathCommon.h"
#include "CGEvalPeriodic.h"
// ----------------------------------------------------------------------------
class CGEvalSawTooth : public CGEvalPeriodic
{
    public:
        virtual float fGetValue();
};
// ----------------------------------------------------------------------------
inline float CGEvalSawTooth::fGetValue ()
{
    assert (m_poAmplitude && "Evaluator with NULL Amplitude param");
    assert (m_poFreqMult && "Evaluator with NULL Frequency param");
    assert (m_poPhase && "Evaluator with NULL Phase param");

    float fPhase = m_poFreqMult->fGetValue() * m_poPhase->fGetValue();
    float fIntPhase = ( (int)(fPhase / _2PI_) ) * _2PI_;
    fPhase -= fIntPhase;

    return( m_poAmplitude->fGetValue() * ( (fPhase / _PI_) - 1.0f ) );
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
