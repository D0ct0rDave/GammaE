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
#ifndef CGSystemLCH
#define CGSystemLCH
// ----------------------------------------------------------------------------
#include "CGLogChannel.h"
#include "TAD/CGSingleton.h"
// ----------------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGSystemLC,public,CGLogChannel)
{
    public:
        virtual void Write(char* fmt,...);
        virtual void Error(char* fmt,...);
        virtual void Warning(char* fmt,...);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
