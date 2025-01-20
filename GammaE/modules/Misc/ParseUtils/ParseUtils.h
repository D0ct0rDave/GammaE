//---------------------------------------------------------------------------
#ifndef ParseUtilsH
#define ParseUtilsH
//---------------------------------------------------------------------------
#include <string.h>

#ifndef NULL
#define NULL 0
#endif

char *ParseUtils_CreateString(char *String);
char *ParseUtils_ReadFile    (char *Filename);
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
//---------------------------------------------------------------------------
#endif
 