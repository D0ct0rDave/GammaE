// -----------------------------------------------------------------
#include "ConsoleIO.h"
// -----------------------------------------------------------------

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// -----------------------------------------------------------------
#define MAX_CON_CARS 65535
char szConsoleBuff[MAX_CON_CARS];
// -----------------------------------------------------------------
void CONPrintf(char *fmt,...)
{
	char szLocalBuff[MAX_CON_CARS];
	
	va_list argptr;
	va_start(argptr,fmt);
	vsprintf(szLocalBuff,fmt,argptr);
	va_end  (argptr);

	if (strlen(szLocalBuff) + strlen(szConsoleBuff) <MAX_CON_CARS)
		// Concat
		strcat(szConsoleBuff,szLocalBuff);
	else
		// copy
		strcpy(szConsoleBuff,szLocalBuff);
}
// -----------------------------------------------------------------
char *CONGetBuffer()
{
	return(szConsoleBuff);
}
// -----------------------------------------------------------------




