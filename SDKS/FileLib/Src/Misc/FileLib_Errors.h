//---------------------------------------------------------------------------
#ifndef ErrorH
#define ErrorH
//---------------------------------------------------------------------------

#define     RES_OP_OK          1
#define     RES_OP_ERROR       0
#define     RES_OP_WARNING     -1

//---------------------------------------------------------------------------

char * ERROR_GetError();
char * ERROR_GetErrorCode();
char * ERROR_GetErrorMessage();

//---------------------------------------------------------------------------
void ERROR_SetErrorCode(char *ErrorCode);
void ERROR_SetErrorMessage(char *ErrorMessage);

void ERROR_SetError(char *ErrorCode,char *ErrorMessage);
void ERROR_SetError(char *ErrorCode,char *Arg0,char *Arg1);
void ERROR_SetError(char *ErrorCode,char *Arg0,char *Arg1,char *Arg2);
void ERROR_SetError(char *ErrorCode,char *Arg0,char *Arg1,char *Arg2,char *Arg3);
//---------------------------------------------------------------------------
#endif
