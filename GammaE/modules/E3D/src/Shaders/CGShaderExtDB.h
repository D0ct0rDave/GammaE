// ----------------------------------------------------------------------------
/*! \class CGShaderExtDB
 *  \brief This class manages application registered shader extensions.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGShaderExtDBH
#define CGShaderExtDBH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGShaderExtDB
{
    public:
        CGShaderExtDB();

        ~CGShaderExtDB();

        static void AddExtension(char* _szExtensionName, void* _pExtensionFunc);

        static void* pGetExtension(char* _szExtensionName);

        static void Invalidate();

    private:

        static CGHashTable <void*> oExtDB;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
