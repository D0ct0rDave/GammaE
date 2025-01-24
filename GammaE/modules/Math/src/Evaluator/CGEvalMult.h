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
#ifndef CGEvalMultH
#define CGEvalMultH
// ----------------------------------------------------------------------------
#include "CGEvalBinary.h"
// ----------------------------------------------------------------------------
class CGEvalMult : public CGEvalBinary
{
    public:
        virtual float fGetValue();
};
// ----------------------------------------------------------------------------
inline float CGEvalMult::fGetValue ()
{
    return ( m_poAOp->fGetValue() * m_poBOp->fGetValue() );
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
