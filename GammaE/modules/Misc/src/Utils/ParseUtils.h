//-----------------------------------------------------------------------------
#ifndef ParseUtilsH
#define ParseUtilsH
//-----------------------------------------------------------------------------
/// Utility functions for C strings and CGStrings
//-----------------------------------------------------------------------------

#include "TAD/CGDynArray.h"
#include "Types/CGString.h"

#ifndef NULL
#define NULL 0
#endif

//-----------------------------------------------------------------------------

char *ParseUtils_CreateString(const char *String);
char *ParseUtils_ReadFile    (const char *Filename);
char *ParseUtils_SkipLine    (char *String);
char *ParseUtils_ParseToken  (char *&String);
char *ParseUtils_ParseLine   (char *&String);

inline void NextToken(char* &Token,char* &ShStr)
{
	Token = ParseUtils_ParseToken(ShStr);
}

void NextQuotedToken(char* &Token,char* &ShStr);

inline void NextLine(char* &Line,char* &ShStr)
{
	Line  = ShStr;
	ShStr = ParseUtils_ParseLine(ShStr);
}

uint ParseUtils_ParseSentence(const CGString& _sSentence,CGDynArray<CGString>* _poWordList);
uint ParseUtils_ParseParameters(const CGString& _sSentence,CGDynArray<CGString>* _poWordList,char _cSeparator=',');

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
 