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
#include "CHUDFontWH.h"
// -----------------------------------------------------------------------------
CHUDFont* CHUDFontWH::poLoadResource(const CGString &_sFilename)
{
    // Try top initialize the font
    CHUDFont* poFont = mNew CHUDFont;
    if ( !poFont->bInit( _sFilename.szString() ) )
    {
        mDel poFont;
        return (NULL);
    }

    return(poFont);
}
// -----------------------------------------------------------------------------
