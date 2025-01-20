//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ParseUtils.h"
#include "memory/gammae_mem.h"
//---------------------------------------------------------------------------
char *ParseUtils_CreateString(char *String)
{
	char *NewStr = (char *)mAlloc(strlen(String)+1);
    strcpy(NewStr,String);
    return(NewStr);
}
//---------------------------------------------------------------------------
unsigned int ParseUtils_FileSize(FILE *fd)
{
    unsigned int FileLength;
    unsigned int FilePos = ftell(fd);

    fseek(fd, 0L, SEEK_END);
    FileLength = ftell(fd);
    fseek(fd,FilePos,SEEK_SET);

    return(FileLength);
}

char *ParseUtils_ReadFile(char *Filename)
{
	char *String;
    char *Stream;
    unsigned int Len;

	FILE *fd = fopen(Filename,"rb");
    if (! fd) return(NULL);

    Len = ParseUtils_FileSize(fd);
	String = (char *)mAlloc(Len+1);
    if (! String)
    {
		fclose(fd);
    	return(NULL);
    }
    fread(String,Len,1,fd);
    String[Len] = 0;
    fclose(fd);
    return(String);
}
//---------------------------------------------------------------------------
bool ParseUtils_EndOfLine(char a)
{
    return ((a=='\n')||(a=='\r'));
}
//---------------------------------------------------------------------------
bool ParseUtils_Delimiter(char a)
{
    return ((a==' ')||(a=='\n')||(a=='\r')||(a=='\t'));
}
//---------------------------------------------------------------------------
char *ParseUtils_ParseToken(char *&String)
{
	char	*pszToken;
	bool	bExitLoop;


	do{
		pszToken  = String;
		bExitLoop = true;

		// Skip non white space '\t' '\r' '\n' chars
		while (
    			(! ParseUtils_Delimiter(*String))
				&&
				(*String)
    		)
			String++;

		// if string is empty return no token
		if (! String) return(NULL);

		// Delimite token
		if (ParseUtils_Delimiter(*String)) *String++ = 0;

		//-----------------------------------------------------------------
		// Skip line comments
		if (! strcmp("//",pszToken))
		{
			String = ParseUtils_SkipLine(String);	
			bExitLoop = false;
		}
		// Skip multiline comments
	else if (! strcmp("/*",pszToken))
		{
			// Search for corresponding closing multiline comments
			while ( (*String) && !((String[0]=='*') && (String[1]=='/')) )
				String++;

			// We haven't found any token
			if (! String) return(NULL);						
		}
		//-----------------------------------------------------------------

	}while (! bExitLoop);
	
	//-----------------------------------------------------------------
    // Skip possible white spaces & '\r' & '\n' & '\t' after token
    while (
    	   ( ParseUtils_Delimiter(*String) )
           &&
           (*String)
    	  )
          String++;

	if (! *String) String = NULL;

	return(pszToken);
	//-----------------------------------------------------------------
}
//---------------------------------------------------------------------------
char *ParseUtils_SkipLine(char *String)
{
	if (! String) return(NULL);	
	if (*String) String++;
	
	// Go to the first end of line delimiter
	while (! ParseUtils_EndOfLine(*String) && (*String)) String++;
	
	// Skip possible delimiters tokens
	while (ParseUtils_Delimiter(*String) && (*String)) String++;

	return (String);
}
//---------------------------------------------------------------------------
char *ParseUtils_ParseLine(char *&String)
{
	char *szRes = ParseUtils_SkipLine(String);
	szRes[-1] = 0;
	return(szRes);
}
//---------------------------------------------------------------------------
void NextQuotedToken(char* &Token,char* &ShStr)
{
	if (ShStr == NULL)
	{
		Token = NULL;
		return;
	}

	if (! *ShStr)
	{
		Token = NULL;
		return;
	}

	if (*ShStr == '"')
	{
		ShStr++;
		Token = ShStr;
		while ((*ShStr) && (*ShStr != '"')) ShStr++;
		
		if (*ShStr == '"')
		{
			*ShStr = 0;
			ShStr++;
		}


		//-----------------------------------------------------------------
		// Skip possible white spaces & '\r' & '\n' & '\t' after token
		while ((ParseUtils_Delimiter(*ShStr)) && (*ShStr))
			  ShStr++;

		if (! *ShStr)
			ShStr = NULL;
	}
	else
	{
		Token = ParseUtils_ParseToken(ShStr);
	}
}
//---------------------------------------------------------------------------