// ----------------------------------------------------------------------------
#include "CmdDispatcher.h"
#include "ClientCmdDispatcher.h"
#include "ServerCmdDispatcher.h"
// ----------------------------------------------------------------------------
void CmdDispatcher_DispatchCommand(KEYCommand_Type kCmd,unsigned int kCmdPar0,unsigned int kCmdPar1,unsigned int kCmdPar2)
{
	if (kCmd == KCMD_EXIT)
	{
		ServerCmdDispatcher_DispatchCommand(kCmd,kCmdPar0,kCmdPar1,kCmdPar2);
		ClientCmdDispatcher_DispatchCommand(kCmd,kCmdPar0,kCmdPar1,kCmdPar2);
		return;
	}
	else
		ClientCmdDispatcher_DispatchCommand(kCmd,kCmdPar0,kCmdPar1,kCmdPar2);
}
// ----------------------------------------------------------------------------