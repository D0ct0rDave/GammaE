//---------------------------------------------------------------------------
#ifndef callbackH
#define callbackH
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
