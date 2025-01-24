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
#ifndef CGEvalTimeH
#define CGEvalTimeH
// ----------------------------------------------------------------------------CGEvaluator
#include "CGEvaluator.h"
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGEvalTime : public CGEvaluator
{
    public:

        CGEvalTime();
        virtual ~CGEvalTime();

        virtual float fGetValue();

    protected:

        CGChrono m_oChrono;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
