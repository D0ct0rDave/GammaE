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
#ifndef ParseUtilsH
#define ParseUtilsH
// ----------------------------------------------------------------------------
// / Utility functions for C strings and CGStrings
// ----------------------------------------------------------------------------

#include "TAD/CGDynArray.h"
#include "Types/CGString.h"

#ifndef NULL
    #define NULL 0
#endif

// ----------------------------------------------------------------------------
namespace Utils {
namespace Parse {
// ----------------------------------------------------------------------------
char* CreateString(const char* String);
char* ReadFile(const char* Filename);
char* SkipLine(char* String);
char* ParseToken(char*&String);
char* ParseLine(char*&String);
void PreprocessString(char* String);

inline void NextToken(char* &Token,char* &ShStr)
{
    Token = ParseToken(ShStr);
}

void NextQuotedToken(char* &Token,char* &ShStr);

inline void NextLine(char* &Line,char* &ShStr)
{
    Line = ShStr;
    ShStr = ParseLine(ShStr);
}

uint ParseSentence(const CGString& _sSentence,CGDynArray <CGString>* _poWordList);
uint ParseParameters(const CGString& _sSentence,CGDynArray <CGString>* _poWordList,char _cSeparator = ',');

// ----------------------------------------------------------------------------
}} // namespace Utils
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
