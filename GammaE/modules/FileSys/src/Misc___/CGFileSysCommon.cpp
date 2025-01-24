// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include "FileSys_Common.h"
// -----------------------------------------------------------------------------
#ifndef NULL
    #define NULL 0
#endif
// -----------------------------------------------------------------------------
TMsgProcess MsgFunction = NULL;
TBeginProcess BeginFunction = NULL;
TEndProcess EndFunction = NULL;
TUpdateProcess UpdateFunction = NULL;
// -----------------------------------------------------------------------------
void CB_SetMsgFunction(void* MsgFunctionCallBack)
{
    MsgFunction = (TMsgProcess)MsgFunctionCallBack;
}

void CB_SetBeginFunction(void* BeginFunctionCallBack)
{
    BeginFunction = (TBeginProcess)BeginFunctionCallBack;
}

void CB_SetUpdateFunction(void* UpdateFunctionCallBack)
{
    UpdateFunction = (TUpdateProcess)UpdateFunctionCallBack;
}

void CB_SetEndFunction(void* EndFunctionCallBack)
{
    EndFunction = (TEndProcess)EndFunctionCallBack;
}
// -----------------------------------------------------------------------------
void CB_MsgProcess(char* Message)
{
    if ( MsgFunction )
        MsgFunction(Message);
}
// -----------------------------------------------------------------------------
void CB_BeginProcess(char* Title)
{
    if ( BeginFunction )
        BeginFunction(Title);
}
// -----------------------------------------------------------------------------
void CB_UpdateProcess(char* Message,unsigned int Percentage)
{
    if ( UpdateFunction )
        UpdateFunction(Message,Percentage);
}
// -----------------------------------------------------------------------------
void CB_EndProcess()
{
    // When the user calls this function the callback's
    // must be initializated
    if ( EndFunction )
        EndFunction();

    MsgFunction = NULL;
    BeginFunction = NULL;
    EndFunction = NULL;
    UpdateFunction = NULL;
}
// -----------------------------------------------------------------------------
#ifdef BCB
    #include <vcl.h>
#endif

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define  MAX_CARS_DATE           128

// -----------------------------------------------------------------------------
void GetDate(TDate* Date)
{
    // Changed to make compatible with MS Visual C++

    struct tm* TheTime;
    time_t tNow;

    time(&tNow);

    TheTime = localtime(&tNow);

    // GetLocalTime((LPSYSTEMTIME) &TheTime);

    Date->Year = TheTime->tm_year;   /* years since 1900 */
    Date->Month = TheTime->tm_mon;   /* months since January - [0,11] */
    Date->Day = TheTime->tm_mday;    /* day of the month - [1,31] */
    Date->Hour = TheTime->tm_hour;   /* hours since midnight - [0,23] */
    Date->Min = TheTime->tm_min;    /* minutes after the hour - [0,59] */
    Date->Sec = TheTime->tm_sec;    /* seconds after the minute - [0,59] */
}
// -----------------------------------------------------------------------------
void GetDateString(char* StrDate)
{
    TDate Date;

    GetDate(&Date);
    ConvertDateToString(&Date,StrDate);
}
// -----------------------------------------------------------------------------
void ConvertDateToString(TDate* Date, char* StrDate)
{
    sprintf(StrDate,
            "%d/%d/%d (%d:%d:%d)",
            Date->Day,
            Date->Month,
            Date->Year,
            Date->Hour,
            Date->Min,
            Date->Sec);
}
// -----------------------------------------------------------------------------

#include <string.h>

// -----------------------------------------------------------------------------
#define             MAX_CARS_ERROR_CODE             32
#define             MAX_CARS_ERROR_MESS             256
#define             MAX_CARS_ERROR_BUFFER           65536
// -----------------------------------------------------------------------------
char ERROR_BUFFER [MAX_CARS_ERROR_BUFFER];
char ERROR_MESSAGE[MAX_CARS_ERROR_MESS];
char ERROR_CODE   [MAX_CARS_ERROR_CODE];

bool InitializeBuffer = true;
// -----------------------------------------------------------------------------
char* ERROR_GetError()
{
    InitializeBuffer = true;
    return (ERROR_BUFFER);
}

char* ERROR_GetErrorCode()
{
    return(ERROR_CODE);
}
char* ERROR_GetErrorMessage()
{
    return(ERROR_MESSAGE);
}
// -----------------------------------------------------------------------------
void ERROR_SetErrorCode(char* ErrorCode)
{
    if ( strlen(ErrorCode) > MAX_CARS_ERROR_CODE ) return;

    strncpy(ERROR_CODE,ErrorCode,MAX_CARS_ERROR_CODE - 1);
    ERROR_CODE[MAX_CARS_ERROR_CODE - 1] = 0;
}

void ERROR_SetErrorMessage(char* ErrorMessage)
{
    if ( strlen(ErrorMessage) > MAX_CARS_ERROR_MESS ) return;

    strncpy(ERROR_MESSAGE,ErrorMessage,MAX_CARS_ERROR_MESS - 1);
    ERROR_MESSAGE[MAX_CARS_ERROR_MESS - 1] = 0;
}
// -----------------------------------------------------------------------------
// Set error variante 0
// -----------------------------------------------------------------------------
void ERROR_SetError(char* ErrorCode,char* ErrorMessage)
{
    // New list of warnings and errors
    if ( InitializeBuffer )
    {
        ERROR_BUFFER[0] = 0;
        InitializeBuffer = false;
    }

    ERROR_SetErrorCode   (ErrorCode);
    ERROR_SetErrorMessage(ErrorMessage);

    if ( strlen(ERROR_BUFFER) >=
        MAX_CARS_ERROR_BUFFER - (MAX_CARS_ERROR_CODE + MAX_CARS_ERROR_MESS + 2) ) return;

    strcat(ERROR_BUFFER,ErrorCode);
    strcat(ERROR_BUFFER,": ");
    strcat(ERROR_BUFFER,ErrorMessage);
    strcat(ERROR_BUFFER,"\n");
}
// -----------------------------------------------------------------------------
// Set error variante 1
// -----------------------------------------------------------------------------
void ERROR_SetError(char* ErrorCode,char* Arg0,char* Arg1)
{
    // New list of warnings and errors
    if ( InitializeBuffer )
    {
        ERROR_BUFFER[0] = 0;
        InitializeBuffer = false;
    }

    if ( strlen(ERROR_BUFFER) >=
        MAX_CARS_ERROR_BUFFER - (MAX_CARS_ERROR_CODE + MAX_CARS_ERROR_MESS + 2) ) return;

    if ( ErrorCode )
    {
        strcat(ERROR_BUFFER,ErrorCode);
        strcat(ERROR_BUFFER,": ");
        strcat(ERROR_BUFFER,Arg0);
        if ( Arg1 )
        {
            strcat(ERROR_BUFFER," ");
            strcat(ERROR_BUFFER,Arg1);
        }
    }
}
// -----------------------------------------------------------------------------
// Set error variante 2
// -----------------------------------------------------------------------------
void ERROR_SetError(char* ErrorCode,char* Arg0,char* Arg1,char* Arg2)
{
    // New list of warnings and errors
    if ( InitializeBuffer )
    {
        ERROR_BUFFER[0] = 0;
        InitializeBuffer = false;
    }

    if ( strlen(ERROR_BUFFER) >=
        MAX_CARS_ERROR_BUFFER - (MAX_CARS_ERROR_CODE + MAX_CARS_ERROR_MESS + 2) ) return;

    if ( ErrorCode )
    {
        ERROR_SetErrorCode(ErrorCode);

        strcat(ERROR_BUFFER,ErrorCode);
        strcat(ERROR_BUFFER,": ");

        if ( Arg0 )
        {
            strcat(ERROR_BUFFER,Arg0);
            strcat(ERROR_BUFFER," ");
        }

        if ( Arg1 )
        {
            strcat(ERROR_BUFFER,Arg1);
            strcat(ERROR_BUFFER," ");
        }

        if ( Arg2 )
            strcat(ERROR_BUFFER,Arg2);
    }
}
// -----------------------------------------------------------------------------
// Set error variante 3
// -----------------------------------------------------------------------------
void ERROR_SetError(char* ErrorCode,char* Arg0,char* Arg1,char* Arg2,char* Arg3)
{
    // New list of warnings and errors
    if ( InitializeBuffer )
    {
        ERROR_BUFFER[0] = 0;
        InitializeBuffer = false;
    }

    if ( strlen(ERROR_BUFFER) >=
        MAX_CARS_ERROR_BUFFER - (MAX_CARS_ERROR_CODE + MAX_CARS_ERROR_MESS + 2) ) return;

    if ( ErrorCode )
    {
        ERROR_SetErrorCode(ErrorCode);

        strcat(ERROR_BUFFER,ErrorCode);
        strcat(ERROR_BUFFER,": ");

        if ( Arg0 )
        {
            strcat(ERROR_BUFFER,Arg0);
            strcat(ERROR_BUFFER," ");
        }

        if ( Arg1 )
        {
            strcat(ERROR_BUFFER,Arg1);
            strcat(ERROR_BUFFER," ");
        }

        if ( Arg2 )
        {
            strcat(ERROR_BUFFER,Arg2);
            strcat(ERROR_BUFFER," ");
        }

        if ( Arg3 )
            strcat(ERROR_BUFFER,Arg2);
    }
}
// -----------------------------------------------------------------------------
#include <stdio.h>

unsigned int uiBlockLenPos[256];
unsigned int uiBLIdx = -1;

void FILE_BeginRIFFBlock(unsigned int uiRIFFId,FILE* fd)
{
    if ( uiBLIdx == 255 ) return;

    uiBLIdx++;

    // Write RIFF identifier
    fwrite(&uiRIFFId,4,1,fd);

    uiBlockLenPos[uiBLIdx] = ftell(fd);

    // Write invalid RIFF BlockLenght
    fwrite(&uiBlockLenPos[uiBLIdx],4,1,fd);
}

void FILE_EndRIFFBlock(FILE* fd)
{
    unsigned int uiBlockLenght = ftell(fd) - (uiBlockLenPos[uiBLIdx] + 4);

    // set file position pointing to RIFF BlockLenght
    fseek(fd,uiBlockLenPos[uiBLIdx],SEEK_SET);

    // write BlockLenght
    fwrite(&uiBlockLenght,4,1,fd);

    // skip RIFF block data
    fseek(fd,uiBlockLenght,SEEK_CUR);

    uiBLIdx--;
}
// -----------------------------------------------------------------------------
