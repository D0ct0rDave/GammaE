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
#ifndef CGSingletonH
#define CGSingletonH
// ----------------------------------------------------------------------------
#include "GammaE_Mem.h"
// ----------------------------------------------------------------------------
#define DECLARE_SINGLETON(CLASSNAME) \
    class CLASSNAME : public CGSingleton < CLASSNAME >

#define DECLARE_INHERITANT_SINGLETON(CLASSNAME,BASECLASSVISIBILITY,BASECLASS) \
    class CLASSNAME : public CGSingleton < CLASSNAME >,BASECLASSVISIBILITY BASECLASS
// ----------------------------------------------------------------------------
template <class T>
class CGSingleton
{
    protected:

        CGSingleton()
        {
        }

    public:
        static T* I()
        {
            static T* soInstance = mNew T;
            return(soInstance);
        }
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
