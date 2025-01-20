//-----------------------------------------------------------------------------
#include "CGGameExtendedCI.h"
#include "CGGCIExtendedCommands.h"
//-----------------------------------------------------------------------------
CGGameExtendedCI::CGGameExtendedCI()
{
	RegisterCommand(mNew CGGCICommandSystemLog ((CGGameCommandInterpreter*)this));
	RegisterCommand(mNew CGGCICommandErrorLog ((CGGameCommandInterpreter*)this));
	RegisterCommand(mNew CGGCICommandClearSysLog ((CGGameCommandInterpreter*)this));
	RegisterCommand(mNew CGGCICommandClearErrorLog ((CGGameCommandInterpreter*)this));
	RegisterCommand(mNew CGGCICommandListEntities ((CGGameCommandInterpreter*)this));
	RegisterCommand(mNew CGGCICommandSwitchEntityState ((CGGameCommandInterpreter*)this));
}
//-----------------------------------------------------------------------------
