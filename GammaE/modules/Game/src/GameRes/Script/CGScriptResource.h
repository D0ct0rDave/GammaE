// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#ifndef CGScriptResourceH
#define CGScriptResourceH
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// -----------------------------------------------------------------------------
class CGScriptResource : public CGTextResource
{
    public:
        CGScriptResource();
        ~CGScriptResource();

        void Init();
        void Finish();
        void Think(float _fDeltaT,void* _pParams);

    protected:

        // / Last execution was succesful
        bool m_bLESuccessful;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
