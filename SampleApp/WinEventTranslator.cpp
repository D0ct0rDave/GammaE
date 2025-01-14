// ----------------------------------------------------------------------------

#include "WinEventTranslator.h"
#include "Input/CommandBinder/CommandBinder.h"
#include "Input/CommandDispatcher/CmdDispatcher.h"

// ----------------------------------------------------------------------------
void WinEvent_KeyDown  (int Key)
{
	KEYCommand_Type kCmd;

	kCmd = CmdBinder_iKeyBindedCommand(Key);

	if (kCmd == KCMD_NONE) return;

	CmdDispatcher_DispatchCommand(kCmd,1,0,0);
}
// ----------------------------------------------------------------------------
void WinEvent_KeyUp    (int Key)
{
	KEYCommand_Type kCmd;

	kCmd = CmdBinder_iKeyBindedCommand(Key);

	if (kCmd == KCMD_NONE) return;

	CmdDispatcher_DispatchCommand(kCmd,0,0,0);
}
// ----------------------------------------------------------------------------
void WinEvent_KeyPress (int Key)
{
	/*
	KEYCommand_Type kCmd;

	kCmd = CmdBinder_iKeyBindedCommand(Key);

	if (kCmd != KCMD_NONE)
	{
		CmdDispatcher_DispatchCommand(kCmd,1,0,0);
	}
	*/
}
// ----------------------------------------------------------------------------
void WinEvent_MouseDown(unsigned int x,unsigned int y,unsigned int button)
{
	KEYCommand_Type kCmd;

	kCmd = CmdBinder_iKeyBindedCommand(CmdBinder_KEY_BUTTON_OFFSET+button);
	if (kCmd == KCMD_NONE) return;

	CmdDispatcher_DispatchCommand(kCmd,1,x,y);
	//CmdDispatcher_DispatchCommand(KCMD_GENMOVE,1,x,y);
}
// ----------------------------------------------------------------------------
void WinEvent_MouseUp  (unsigned int x,unsigned int y,unsigned int button)
{
	KEYCommand_Type kCmd;

	kCmd = CmdBinder_iKeyBindedCommand(CmdBinder_KEY_BUTTON_OFFSET+button);
	if (kCmd == KCMD_NONE) return;

	CmdDispatcher_DispatchCommand(kCmd,0,x,y);
	//CmdDispatcher_DispatchCommand(KCMD_GENMOVE,0,x,y);
}
// ----------------------------------------------------------------------------
void WinEvent_MouseMove(unsigned int x,unsigned int y,bool PushedButtons)
{		
	CmdDispatcher_DispatchCommand(KCMD_GENMOVE,(PushedButtons?1:0),x,y);
}
// ----------------------------------------------------------------------------