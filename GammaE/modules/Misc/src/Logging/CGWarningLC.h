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
#ifndef CGWarningLCH
#define CGWarningLCH
// ----------------------------------------------------------------------------
#include "CGLogChannel.h"
#include "TAD/CGSingleton.h"
// ----------------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGWarningLC,public,CGLogChannel)
{
    public:
        virtual void Write(char* fmt,...);
};

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
