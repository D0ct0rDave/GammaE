//------------------------------------------------------------------------------
#ifndef FileSys_CommonH
#define FileSys_CommonH
//------------------------------------------------------------------------------
#include <stdio.h>

//------------------------------------------------------------------------------
// RIFF management
//------------------------------------------------------------------------------
#ifndef     MAKE_RIFF_ID
#define     MAKE_RIFF_ID(a,b,c,d)  ((a) | (b << 8) | (c <<16) | (d << 24))
#endif
//---------------------------------------------------------------------------

void FILE_BeginRIFFBlock(unsigned int uiRIFFId,FILE *fd);
void FILE_EndRIFFBlock(FILE *fd);


//------------------------------------------------------------------------------
// Error management
//------------------------------------------------------------------------------

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
// Date management
//---------------------------------------------------------------------------

typedef struct{
    unsigned short  Year;
    unsigned char   Month;
    unsigned char   Day;
    unsigned char   Hour;
    unsigned char   Min;
    unsigned short  Sec;
}tdstDate;

void GetDate            (tdstDate *Date);
void GetDateString      (char *StrDate);
void ConvertDateToString(tdstDate *Date, char *StrDate);

//---------------------------------------------------------------------------
// Callback
//---------------------------------------------------------------------------
typedef void(* TMsgProcess )  (char *);
typedef void(* TBeginProcess) (char *);
typedef void(* TEndProcess)   (void);
typedef void(* TUpdateProcess)(char *Message,unsigned int Percentage);
//---------------------------------------------------------------------------
void CB_MsgProcess   (char * Message);
void CB_BeginProcess (char *Title);
void CB_EndProcess   ();
void CB_UpdateProcess(char *Message,unsigned int Percentage);
//---------------------------------------------------------------------------
void CB_SetMsgFunction   (void *MsgFunctionCallBack);
void CB_SetBeginFunction (void *BeginFuncionCallBack);
void CB_SetEndFunction   (void *BeginFuncionCallBack);
void CB_SetUpdateFunction(void *UpdateFunctionCallBack);

//---------------------------------------------------------------------------
#endif
