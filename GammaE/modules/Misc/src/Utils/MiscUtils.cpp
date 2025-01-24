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
#include "MiscUtils.h"
// ----------------------------------------------------------------------------
namespace Utils {
// ----------------------------------------------------------------------------
CGString ExtractFileDir(const CGString& _sFullFilename)
{
    const char* _szBase = _sFullFilename.szString();

    int i = _sFullFilename.uiLen();
    int l = i;

    char* _szEnd = (char*)_szBase + l;
    while ( (_szEnd != _szBase) && (*_szEnd != '/') && (*_szEnd != '\\') )
    {
        _szEnd--;
        i--;
    }

    if ( i != 0 )
    {
        CGString sDir = _sFullFilename.SubString(0,i);
        return(sDir);
    }

    return( CGString("") );
}
// ----------------------------------------------------------------------------
CGString ExtractFileName(const CGString& _sFullFilename)
{
    const char* _szBase = _sFullFilename.szString();

    int i = _sFullFilename.uiLen();
    int l = i;

    char* _szEnd = (char*)_szBase + l;
    while ( (_szEnd != _szBase) && (*_szEnd != '/') && (*_szEnd != '\\') )
    {
        _szEnd--;
        i--;
    }

    if ( i != 0 )
    {
        CGString sFileName = _sFullFilename.SubString(i + 1,l - i);
        return(sFileName);
    }

    return(_sFullFilename);
}
// ----------------------------------------------------------------------------
CGString ExtractShortFileName(const CGString& _sFullFilename)
{
    CGString sFilename = ExtractFileName(_sFullFilename);
    uint iExtPos = sFilename.iPos('.');

    if ( iExtPos == -1 ) return(_sFullFilename);

    return( sFilename.SubString(0,iExtPos) );
}
// ----------------------------------------------------------------------------
};
// ----------------------------------------------------------------------------
