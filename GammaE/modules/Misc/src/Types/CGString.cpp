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
#include "CGString.h"

#include "GammaE_Mem.h"
#include <stdarg.h>
#include <stdio.h>
// ----------------------------------------------------------------------------
inline char TOUPPER(char c)
{
    if ( (c >= 'a') && (c <= 'z') )
        return (c - 32);
    else
        return(c);
}
// ----------------------------------------------------------------------------
inline char TOLOWER(char c)
{
    if ( (c >= 'A') && (c <= 'Z') )
        return (c + 32);
    else
        return(c);
}
// ----------------------------------------------------------------------------
CGString::~CGString()
{
    if ( m_szData != NULL )
        Free();
}
// ----------------------------------------------------------------------------
void CGString::Alloc(uint _uiSize)
{
    if ( m_szData != NULL )
        Free();

    if ( _uiSize == 0 ) return;
    m_szData = (char*)MEMAlloc(_uiSize);
}
// ----------------------------------------------------------------------------
void CGString::Free()
{
    if ( m_szData != NULL )
    {
        mFree(m_szData);
        m_szData = NULL;
    }
}
// ----------------------------------------------------------------------------
// / Copy the formatted string to the string object
void CGString::Format(char* fmt,...)
{
    if ( fmt == NULL ) return;

    char szLocalBuff[8192];

    va_list argptr;
    va_start(argptr,fmt);
    vsprintf(szLocalBuff,fmt,argptr);
    va_end  (argptr);

    // -----------------------------
    Assign( szLocalBuff );
}
// ----------------------------------------------------------------------------
// / Copy the string contents to the current
void CGString::Assign(const char* _szStr)
{
    if ( m_szData ) Free();
    if ( _szStr == NULL ) return;

    uint uiLen = strlen(_szStr);
    if ( uiLen == 0 ) return;

    m_szData = (char*)mAlloc(uiLen + 1);
    memcpy(m_szData,_szStr,uiLen + 1);
}
// ----------------------------------------------------------------------------
// / Returns the length of the string
const uint CGString::uiLen() const
{
    if ( m_szData == NULL )
        return(0);
    else
        return ( strlen(m_szData) );
}
// ----------------------------------------------------------------------------
// / Returns the position of a substring inside the string, -1 if not found
int CGString::iPos(const CGString& _oSubStr) const
{
    const char* szStr = _oSubStr.szString();
    if ( szStr == NULL ) return(-1);

    return ( iPos(szStr) );
}
// ----------------------------------------------------------------------------
int CGString::iPos(const char* _szStr) const
{
    if ( _szStr == NULL ) return(-1);
    if ( m_szData == NULL ) return(-1);

    char* ptr = strstr( m_szData,_szStr );

    if ( ptr == NULL )
        return(-1);
    else
        return(ptr - m_szData);
}
// ----------------------------------------------------------------------------
CGString CGString::SubString(uint _uiPos,uint _uiLen) const
{
    CGString oRes;

    uint uiLen = this->uiLen();
    if ( _uiPos >= uiLen )
        return(oRes);

    if ( (_uiPos + _uiLen) > uiLen )
        _uiLen = uiLen - _uiPos;

    oRes.Alloc(_uiLen + 1);
    memcpy( (void*)oRes.szString(),m_szData + _uiPos,_uiLen );
    ( (char*)oRes.szString() )[_uiLen] = 0;

    return(oRes);
}
// ----------------------------------------------------------------------------
// / Returns the string in upper case
CGString CGString::UpperCase() const
{
    CGString asRes(*this);
    asRes.ToUpperCase();
    return (asRes);
}
// ----------------------------------------------------------------------------
// / Converts the string to upper case
void CGString::ToUpperCase()
{
    char* szBase = (char*)szString();
    uint uiLen = this->uiLen();

    for ( uint i = 0; i < uiLen; i++ )
        szBase[i] = TOUPPER( szBase[i] );
}
// ----------------------------------------------------------------------------
// / Returns a copy of the string in lower case
CGString CGString::LowerCase() const
{
    CGString asRes(*this);
    asRes.ToLowerCase();
    return (asRes);
}
// ----------------------------------------------------------------------------
// / Converts to lower case
void CGString::ToLowerCase()
{
    char* szBase = (char*)szString();
    uint uiLen = this->uiLen();

    for ( uint i = 0; i < uiLen; i++ )
        szBase[i] = TOLOWER( szBase[i] );
}
// ----------------------------------------------------------------------------
void CGString::Concat(const CGString& _oStr)
{
    uint uiDLen = _oStr.uiLen();
    if ( uiDLen == 0 ) return;      // Nothing to concat

    uint uiSLen = this->uiLen();
    uint uiTLen = uiSLen + uiDLen;

    char* szNewStr = (char*)mAlloc(uiTLen + 1);
    if ( uiSLen > 0 )
        memcpy( (void*)szNewStr,m_szData,uiSLen );

    memcpy( (void*)(szNewStr + uiSLen),_oStr.szString(),uiDLen );
    szNewStr[uiTLen] = 0;

    Free();
    m_szData = szNewStr;
}
// ----------------------------------------------------------------------------
bool CGString::operator == (const CGString& _oStr) const
{
    if ( m_szData == NULL ) return(_oStr.m_szData == NULL);
    if ( _oStr.m_szData == NULL ) return(false);

    return (strcmp( m_szData,_oStr.szString() ) == 0);
}
// ----------------------------------------------------------------------------
bool CGString::operator |= (const CGString& _oStr) const
{
    if ( m_szData == NULL ) return(_oStr.m_szData == NULL);
    if ( _oStr.m_szData == NULL ) return(false);

    return (stricmp( m_szData,_oStr.szString() ) == 0);
}
// ----------------------------------------------------------------------------
bool CGString::operator != (const CGString& _oStr) const
{
    if ( m_szData == NULL ) return(_oStr.m_szData != NULL);
    if ( _oStr.m_szData == NULL ) return(true);

    return (strcmp( m_szData,_oStr.szString() ) != 0);
}
// ----------------------------------------------------------------------------
