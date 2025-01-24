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
#ifndef CGEvalPeriodicH
#define CGEvalPeriodicH
// ----------------------------------------------------------------------------
#include "CGEvaluator.h"
// ----------------------------------------------------------------------------
class CGEvalPeriodic : public CGEvaluator
{
    public:
        CGEvalPeriodic();
        virtual ~CGEvalPeriodic();

        CGEvaluator* poGetAmplitude();
        void SetAmplitude(CGEvaluator* _poAmp);

        CGEvaluator* poGetPhase();
        void SetPhase(CGEvaluator* _poPhase);

        CGEvaluator* poGetFreqMult();
        void SetFreqMult(CGEvaluator* _poFreqMult);

        CGEvaluator* m_poAmplitude;
        CGEvaluator* m_poPhase;
        CGEvaluator* m_poFreqMult;
};
// ----------------------------------------------------------------------------
inline CGEvaluator* CGEvalPeriodic::poGetAmplitude ()
{
    return(m_poAmplitude);
}
// ----------------------------------------------------------------------------
inline void CGEvalPeriodic::SetAmplitude (CGEvaluator* _poAmplitude)
{
    m_poAmplitude = _poAmplitude;
}
// ----------------------------------------------------------------------------
inline CGEvaluator* CGEvalPeriodic::poGetPhase ()
{
    return(m_poPhase);
}
// ----------------------------------------------------------------------------
inline void CGEvalPeriodic::SetPhase (CGEvaluator* _poPhase)
{
    m_poPhase = _poPhase;
}
// ----------------------------------------------------------------------------
inline CGEvaluator* CGEvalPeriodic::poGetFreqMult ()
{
    return(m_poFreqMult);
}
// ----------------------------------------------------------------------------
inline void CGEvalPeriodic::SetFreqMult (CGEvaluator* _poFreqMult)
{
    m_poFreqMult = _poFreqMult;
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
