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
#ifndef CHUDFontWHH
#define CHUDFontWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CHUDFont.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CHUDFontWH,CGDiskResourceWH,CHUDFont)
{
    public:
        CHUDFontWH(){
        }

    public:

        virtual CHUDFont* poLoadResource(const CGString &_sFilename);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
