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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ParseUtils.h"
#include "GammaE_Mem.h"
#include "gammae_filesys.h"

// ----------------------------------------------------------------------------
char* ParseUtils_CreateString(const char* String)
{
    char* NewStr = (char*)mAlloc(strlen(String) + 1);
    strcpy(NewStr,String);
    return(NewStr);
}
// ----------------------------------------------------------------------------
char* ParseUtils_ReadFile(const char* Filename)
{
    char* String;
    uint Len;

    CGFile oFile;

    if ( !oFile.bOpen(CGString(Filename),FOM_READ) )
        return(NULL);

    Len = oFile.uiLength();
    String = (char*)mAlloc(Len + 1);
    if ( !String )
    {
        oFile.Close();
        return(NULL);
    }

    oFile.ReadArray(String,Len);
    String[Len] = 0;
    oFile.Close();

    return(String);
}
// ----------------------------------------------------------------------------
bool ParseUtils_EndOfLine(char a)
{
    return ( (a == '\n') || (a == '\r') );
}
// ----------------------------------------------------------------------------
static char gscCustomDelimiter = ' ';

void ParseUtils_SetCustomDelimiter(char _cDelimiter)
{
    gscCustomDelimiter = _cDelimiter;
}
// ----------------------------------------------------------------------------
bool ParseUtils_Delimiter(char a)
{
    return ( (a == gscCustomDelimiter) || (a == '\n') || (a == '\r') || (a == '\t') );
}
// ----------------------------------------------------------------------------
void ParseUtils_PreprocessString(char* String)
{
    char* szStrPos = String;
    do {
        if ( *szStrPos == '\t' )
        {
            *szStrPos = ' ';
            szStrPos++;
        }
/*
   else if (*szStrPos == '\r')
            szStrPos++;

   else if (*szStrPos == '\n')
            szStrPos++;
 */
        // Skip line comments
        else if ( (szStrPos[0] == '/') && (szStrPos[1] == '/') )
        {
            char* szNextPos = ParseUtils_SkipLine(szStrPos);
            memset(szStrPos,' ',szNextPos - szStrPos);
            szStrPos = szNextPos;
        }
        // Skip multiline comments
        else if ( (szStrPos[0] == '/') && (szStrPos[1] == '*') )
        {
            char* szNextPos = szStrPos;

            // Search for corresponding closing multiline comments
            while ( (*szNextPos) && !( (szNextPos[0] == '*') && (szNextPos[1] == '/') ) )
            {
                *szNextPos = ' ';
                szNextPos++;
            }

            if ( *szNextPos != 0 )
            {
                // we've found an ending multiline comment token
                szStrPos = szNextPos + 2;
            }
        }
        // Skip char
        else
            szStrPos++;
    } while ( *szStrPos != 0 );
}
// ----------------------------------------------------------------------------
char* ParseUtils_ParseToken(char*&String)
{
    // if string is empty return no token
    if ( !String ) return(NULL);

    char* pszToken;
    bool bExitLoop;

    do {
        pszToken = String;
        bExitLoop = true;

        // Skip non white space '\t' '\r' '\n' chars
        while (
            ( !ParseUtils_Delimiter(*String) )
            &&
            (*String)
            )
            String++;

        // if string is empty return no token
        if ( *String == 0 ) return(pszToken);

        // Delimit token
        if ( ParseUtils_Delimiter(*String) ) *String++ = 0;

        // ----------------------------------------------------------------------------
        // Skip line comments
        if ( !strcmp("//",pszToken) )
        {
            String = ParseUtils_SkipLine(String);
            bExitLoop = false;
        }
        // Skip multiline comments
        else if ( !strcmp("/*",pszToken) )
        {
            // Search for corresponding closing multiline comments
            while ( (*String) && !( (String[0] == '*') && (String[1] == '/') ) )
                String++;

            // We haven't found any token
            if ( !String ) return(NULL);
        }
        // ----------------------------------------------------------------------------
    } while ( !bExitLoop );

    // Skip possible white spaces & '\r' & '\n' & '\t' after token
    while (
        ( ParseUtils_Delimiter(*String) )
        &&
        (*String)
        )
        String++;

    return(pszToken);
}
// ----------------------------------------------------------------------------
char* ParseUtils_SkipLine(char* String)
{
    if ( !String ) return(NULL);
    if ( *String ) String++;

    // Go to the first end of line delimiter
    while ( !ParseUtils_EndOfLine(*String) && (*String) ) String++;

    // Skip possible delimiters tokens
    while ( ParseUtils_Delimiter(*String) && (*String) ) String++;

    return (String);
}
// ----------------------------------------------------------------------------
char* ParseUtils_ParseLine(char*&String)
{
    if ( !String ) return(NULL);
    if ( *String ) String++;  // ??

    ParseUtils_SetCustomDelimiter(0);

    // Go to the first end of line delimiter
    while ( !ParseUtils_EndOfLine(*String) && (*String) ) String++;
    *String = 0;
    String++;

    // Skip possible delimiters tokens
    while ( ParseUtils_Delimiter(*String) && (*String) ) String++;

    ParseUtils_SetCustomDelimiter(' ');

    return (String);
}
// ----------------------------------------------------------------------------
void NextQuotedToken(char* &Token,char* &ShStr)
{
    if ( ShStr == NULL )
    {
        Token = NULL;
        return;
    }

    if ( !*ShStr )
    {
        Token = NULL;
        return;
    }

    if ( *ShStr == '"' )
    {
        ShStr++;
        Token = ShStr;
        while ( (*ShStr) && (*ShStr != '"') ) ShStr++;

        if ( *ShStr == '"' )
        {
            *ShStr = 0;
            ShStr++;
        }

        // Skip possible white spaces & '\r' & '\n' & '\t' after token
        while ( ( ParseUtils_Delimiter(*ShStr) ) && (*ShStr) )
            ShStr++;

        if ( !*ShStr )
            ShStr = NULL;
    }
    else
    {
        Token = ParseUtils_ParseToken(ShStr);
    }
}
// ----------------------------------------------------------------------------
uint ParseUtils_ParseParameters(const CGString& _sSentence,CGDynArray <CGString>* _poWordList,char _cSeparator)
{
    if ( _poWordList == NULL ) return(0);

    // Create a copy of the input string
    char* szSentence = ParseUtils_CreateString( _sSentence.szString() );
    char* szNextWord = szSentence;

    ParseUtils_SetCustomDelimiter(_cSeparator);

    _poWordList->Clear();
    while ( *szNextWord )
    {
        char* szCurrentWord = ParseUtils_ParseToken(szNextWord);
        _poWordList->uiAdd(szCurrentWord);
    }

    ParseUtils_SetCustomDelimiter(' ');

    // Free resources
    if ( szSentence != NULL ) mFree(szSentence);
    return( _poWordList->uiNumElems() );
}
// ----------------------------------------------------------------------------
uint ParseUtils_ParseSentence(const CGString& _sSentence,CGDynArray <CGString>* _poWordList)
{
    return( ParseUtils_ParseParameters(_sSentence,_poWordList,' ') );
}
// ----------------------------------------------------------------------------
//

// ----------------------------------------------------------------------------
