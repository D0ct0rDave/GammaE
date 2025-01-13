//---------------------------------------------------------------------------
#include "FileLib_Callback.h"
//---------------------------------------------------------------------------
#ifndef NULL
#define NULL 0
#endif
//---------------------------------------------------------------------------
TMsgProcess    MsgFunction    = NULL;
TBeginProcess  BeginFunction  = NULL;
TEndProcess    EndFunction    = NULL;
TUpdateProcess UpdateFunction = NULL;
//---------------------------------------------------------------------------
void CB_SetMsgFunction(void *MsgFunctionCallBack)
{
    MsgFunction = (TMsgProcess)MsgFunctionCallBack;
}

void CB_SetBeginFunction(void *BeginFunctionCallBack)
{
    BeginFunction = (TBeginProcess)BeginFunctionCallBack;
}

void CB_SetUpdateFunction(void *UpdateFunctionCallBack)
{
    UpdateFunction = (TUpdateProcess)UpdateFunctionCallBack;
}

void CB_SetEndFunction(void *EndFunctionCallBack)
{
    EndFunction = (TEndProcess)EndFunctionCallBack;
}
//---------------------------------------------------------------------------
void CB_MsgProcess(char * Message)
{
    if (MsgFunction)
        MsgFunction(Message);
}
//---------------------------------------------------------------------------
void CB_BeginProcess(char *Title)
{
    if (BeginFunction)
        BeginFunction(Title);
}
//---------------------------------------------------------------------------
void CB_UpdateProcess(char *Message,unsigned int Percentage)
{
    if (UpdateFunction)
        UpdateFunction(Message,Percentage);
}
//---------------------------------------------------------------------------
void CB_EndProcess()
{
    // When the user calls this function the callback's
    // must be initializated
    if (EndFunction)
        EndFunction();

    MsgFunction     = NULL;
    BeginFunction   = NULL;
    EndFunction     = NULL;
    UpdateFunction  = NULL;
}
//---------------------------------------------------------------------------

