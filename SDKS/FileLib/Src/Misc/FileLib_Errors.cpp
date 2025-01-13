//---------------------------------------------------------------------------

#include <string.h>
#include "FileLib_Errors.h"

//---------------------------------------------------------------------------
#define             MAX_CARS_ERROR_CODE             32
#define             MAX_CARS_ERROR_MESS             256
#define             MAX_CARS_ERROR_BUFFER           65536
//---------------------------------------------------------------------------
char ERROR_BUFFER [MAX_CARS_ERROR_BUFFER];
char ERROR_MESSAGE[MAX_CARS_ERROR_MESS];
char ERROR_CODE   [MAX_CARS_ERROR_CODE];

bool InitializeBuffer = true;
//---------------------------------------------------------------------------
char * ERROR_GetError()
{
    InitializeBuffer = true;
    return (ERROR_BUFFER);
}

char * ERROR_GetErrorCode()
{
    return(ERROR_CODE);
}
char * ERROR_GetErrorMessage()
{
    return(ERROR_MESSAGE);
}
//---------------------------------------------------------------------------
void ERROR_SetErrorCode(char *ErrorCode)
{
    if ( strlen(ErrorCode)>MAX_CARS_ERROR_CODE ) return;

    strncpy(ERROR_CODE,ErrorCode,MAX_CARS_ERROR_CODE-1);
    ERROR_CODE[MAX_CARS_ERROR_CODE-1] = 0;
}

void ERROR_SetErrorMessage(char *ErrorMessage)
{
    if ( strlen(ErrorMessage)>MAX_CARS_ERROR_MESS ) return;

    strncpy(ERROR_MESSAGE,ErrorMessage,MAX_CARS_ERROR_MESS-1);
    ERROR_MESSAGE[MAX_CARS_ERROR_MESS-1] = 0;
}
//---------------------------------------------------------------------------
// Set error variante 0
//---------------------------------------------------------------------------
void ERROR_SetError(char *ErrorCode,char *ErrorMessage)
{
    // New list of warnings and errors
    if (InitializeBuffer)
    {
        ERROR_BUFFER[0] = 0;
        InitializeBuffer = false;
    }

    ERROR_SetErrorCode   (ErrorCode);
    ERROR_SetErrorMessage(ErrorMessage);

    if ( strlen(ERROR_BUFFER) >=
        MAX_CARS_ERROR_BUFFER - (MAX_CARS_ERROR_CODE + MAX_CARS_ERROR_MESS + 2)) return;

    strcat(ERROR_BUFFER,ErrorCode);
    strcat(ERROR_BUFFER,": ");
    strcat(ERROR_BUFFER,ErrorMessage);
    strcat(ERROR_BUFFER,"\n");
}
//---------------------------------------------------------------------------
// Set error variante 1
//---------------------------------------------------------------------------
void ERROR_SetError(char *ErrorCode,char *Arg0,char *Arg1)
{
    // New list of warnings and errors
    if (InitializeBuffer)
    {
        ERROR_BUFFER[0] = 0;
        InitializeBuffer = false;
    }

    if ( strlen(ERROR_BUFFER) >=
        MAX_CARS_ERROR_BUFFER - (MAX_CARS_ERROR_CODE + MAX_CARS_ERROR_MESS + 2)) return;

    if(ErrorCode)
    {
        strcat(ERROR_BUFFER,ErrorCode);
        strcat(ERROR_BUFFER,": ");
        strcat(ERROR_BUFFER,Arg0);
        if (Arg1)
        {
            strcat(ERROR_BUFFER," ");
            strcat(ERROR_BUFFER,Arg1);
        }
    }
}
//---------------------------------------------------------------------------
// Set error variante 2
//---------------------------------------------------------------------------
void ERROR_SetError(char *ErrorCode,char *Arg0,char *Arg1,char *Arg2)
{
    // New list of warnings and errors
    if (InitializeBuffer)
    {
        ERROR_BUFFER[0] = 0;
        InitializeBuffer = false;
    }

    if ( strlen(ERROR_BUFFER) >=
        MAX_CARS_ERROR_BUFFER - (MAX_CARS_ERROR_CODE + MAX_CARS_ERROR_MESS + 2)) return;

    if (ErrorCode)
    {
        ERROR_SetErrorCode(ErrorCode);

        strcat(ERROR_BUFFER,ErrorCode);
        strcat(ERROR_BUFFER,": ");

        if (Arg0)
        {
            strcat(ERROR_BUFFER,Arg0);
            strcat(ERROR_BUFFER," ");
        }

        if (Arg1)
        {
            strcat(ERROR_BUFFER,Arg1);
            strcat(ERROR_BUFFER," ");
        }

        if (Arg2)
            strcat(ERROR_BUFFER,Arg2);
    }
}
//---------------------------------------------------------------------------
// Set error variante 3
//---------------------------------------------------------------------------
void ERROR_SetError(char *ErrorCode,char *Arg0,char *Arg1,char *Arg2,char *Arg3)
{
    // New list of warnings and errors
    if (InitializeBuffer)
    {
        ERROR_BUFFER[0] = 0;
        InitializeBuffer = false;
    }

    if ( strlen(ERROR_BUFFER) >=
        MAX_CARS_ERROR_BUFFER - (MAX_CARS_ERROR_CODE + MAX_CARS_ERROR_MESS + 2)) return;


    if  (ErrorCode)
    {
        ERROR_SetErrorCode(ErrorCode);

        strcat(ERROR_BUFFER,ErrorCode);
        strcat(ERROR_BUFFER,": ");

        if (Arg0)
        {
            strcat(ERROR_BUFFER,Arg0);
            strcat(ERROR_BUFFER," ");
        }

        if (Arg1)
        {
            strcat(ERROR_BUFFER,Arg1);
            strcat(ERROR_BUFFER," ");
        }

        if (Arg2)
        {
            strcat(ERROR_BUFFER,Arg2);
            strcat(ERROR_BUFFER," ");
        }

        if (Arg3)
            strcat(ERROR_BUFFER,Arg2);
    }
}
//---------------------------------------------------------------------------
