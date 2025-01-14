//---------------------------------------------------------------------------
// For key bindings
//---------------------------------------------------------------------------
#include "CommandBinder.h"

//---------------------------------------------------------------------------
// Local module constants
//---------------------------------------------------------------------------
#define CMDBINDER_MAX_BINDABLE_KEYS 256

//---------------------------------------------------------------------------
// Local module variables
//---------------------------------------------------------------------------
KEYCommand_Type iBindTable[CMDBINDER_MAX_BINDABLE_KEYS];

//---------------------------------------------------------------------------
// Function implementation
//---------------------------------------------------------------------------
void CmdBinder_BindKey(int iKey,KEYCommand_Type iCommand)
{
	iBindTable[iKey] = iCommand;
}
//---------------------------------------------------------------------------
void CmdBinder_UnbindKey(int iKey)
{
	iBindTable[iKey] = KCMD_NONE;
}
//---------------------------------------------------------------------------
KEYCommand_Type CmdBinder_iKeyBindedCommand(int iKey)
{
	return(iBindTable[iKey]);
}
//---------------------------------------------------------------------------
void CmdBinder_InitBindTable()
{
	unsigned int cKey;

	for (cKey=0;cKey<CMDBINDER_MAX_BINDABLE_KEYS;cKey++)	
		iBindTable[cKey] = KCMD_NONE;
}
//---------------------------------------------------------------------------