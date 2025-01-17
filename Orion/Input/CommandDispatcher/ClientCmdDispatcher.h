// ----------------------------------------------------------------------------
#ifndef ClientCmdDispatcherH
#define ClientCmdDispatcherH
// ----------------------------------------------------------------------------
#include "../Commands/Orion_Commands.h"
// ----------------------------------------------------------------------------

typedef void (* TClientCmdDispatcher_DispatchCallbackFunc)(unsigned int kCmdPar0,unsigned int kCmdPar1,unsigned int kCmdPar2);
void ClientCmdDispatcher_SetDispatchCallback(KEYCommand_Type kCmd,TClientCmdDispatcher_DispatchCallbackFunc Func);

void ClientCmdDispatcher_DispatchCommand    (KEYCommand_Type kCmd,unsigned int kCmdPar0,unsigned int kCmdPar1,unsigned int kCmdPar2);

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------