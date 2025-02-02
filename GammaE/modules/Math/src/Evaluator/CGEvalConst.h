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
#ifndef CGEvalConstH
#define CGEvalConstH
// ----------------------------------------------------------------------------
#include "CGEvaluator.h"
// ----------------------------------------------------------------------------
class CGEvalConst : public CGEvaluator
{
    public:
        CGEvalConst();
        virtual ~CGEvalConst();

        virtual float fGetValue();

        float fGetConstant();
        void SetConstant(float _fValue);

    protected:
        float m_fConstant;
};
// ----------------------------------------------------------------------------
inline float CGEvalConst::fGetValue ()
{
    return(m_fConstant);
}
// ----------------------------------------------------------------------------
inline float CGEvalConst::fGetConstant ()
{
    return(m_fConstant);
}
// ----------------------------------------------------------------------------
inline void CGEvalConst::SetConstant (float _fValue)
{
    m_fConstant = _fValue;
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
