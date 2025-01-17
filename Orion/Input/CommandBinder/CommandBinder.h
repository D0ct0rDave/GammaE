//---------------------------------------------------------------------------
#ifndef CommandBinderH
#define CommandBinderH
//---------------------------------------------------------------------------
#include "../Commands/Orion_Commands.h"
//---------------------------------------------------------------------------
#define			CmdBinder_KEY_BUTTON_OFFSET	128

#define			CmdBinder_MOUSE_BUTTON0		(CmdBinder_KEY_BUTTON_OFFSET  )
#define			CmdBinder_MOUSE_BUTTON1		(CmdBinder_KEY_BUTTON_OFFSET+1)
#define			CmdBinder_MOUSE_BUTTON2		(CmdBinder_KEY_BUTTON_OFFSET+2)
#define			CmdBinder_MOUSE_BUTTON3		(CmdBinder_KEY_BUTTON_OFFSET+3)
#define			CmdBinder_MOUSE_BUTTON4		(CmdBinder_KEY_BUTTON_OFFSET+4)

void			CmdBinder_InitBindTable();

void			CmdBinder_BindKey		   (int iKey,KEYCommand_Type iCommand);
void			CmdBinder_UnbindKey		   (int iKey);
KEYCommand_Type CmdBinder_iKeyBindedCommand(int iKey);

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------