// ----------------------------------------------------------------------------
#include "ClientCmdDispatcher.h"

// ----------------------------------------------------------------------------
TClientCmdDispatcher_DispatchCallbackFunc FuncTable[KCMD_NUMKEYCOMMANDS];

// ----------------------------------------------------------------------------
void ClientCmdDispatcher_SetDispatchCallback(KEYCommand_Type kCmd,TClientCmdDispatcher_DispatchCallbackFunc Func)
{
	FuncTable[kCmd] = Func;
}
// ----------------------------------------------------------------------------
void ClientCmdDispatcher_DispatchCommand(KEYCommand_Type kCmd,unsigned int kCmdPar0,unsigned int kCmdPar1,unsigned int kCmdPar2)
{
	if (FuncTable[kCmd]) FuncTable[kCmd](kCmdPar0,kCmdPar1,kCmdPar2);
/*
	switch (kCmd)
	{
			case KCMD_NONE:		

			case KCMD_FORWARD:	
			case KCMD_BACKWARD:								
			case KCMD_UP:								
			case KCMD_DOWN:									
			case KCMD_LEFT:								
			case KCMD_RIGHT:			

			case KCMD_CAMFORWARD:	
			case KCMD_CAMBACKWARD:								
			case KCMD_CAMUP:								
			case KCMD_CAMDOWN:									
			case KCMD_CAMLEFT:								
			case KCMD_CAMRIGHT:			
			
			case KCMD_TURNUP:
			case KCMD_TURNDOWN:
			case KCMD_TURNLEFT:
			case KCMD_TURNRIGHT:
								
			case KCMD_GENMOVE:									
			case KCMD_BUTTON0:								
			case KCMD_BUTTON1:								
			case KCMD_BUTTON2:								
			case KCMD_BUTTON3:
			case KCMD_BUTTON4:	
								break;

			case KCMD_EXIT:		// Process client finalization first.
								
								// Execute callback function code then.
								if (FuncTable[KCMD_EXIT]) FuncTable[KCMD_EXIT](kCmdPar0,kCmdPar1,kCmdPar2);
								break;

		default:
								break;
	}
*/
}
// ----------------------------------------------------------------------------