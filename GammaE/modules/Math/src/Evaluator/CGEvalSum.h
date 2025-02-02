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
#ifndef CGEvalSumH
#define CGEvalSumH
// ----------------------------------------------------------------------------
#include "CGEvalBinary.h"
// ----------------------------------------------------------------------------
class CGEvalSum : public CGEvalBinary
{
    public:
        virtual float fGetValue();
};
// ----------------------------------------------------------------------------
inline float CGEvalSum::fGetValue ()
{
    return ( m_poAOp->fGetValue() + m_poBOp->fGetValue() );
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
