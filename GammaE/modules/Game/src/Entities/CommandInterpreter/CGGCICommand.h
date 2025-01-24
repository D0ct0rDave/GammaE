//-----------------------------------------------------------------------------
#ifndef CGGCICommands_h
#define CGGCICommands_h 1
//-----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGGCIState.h"
//-----------------------------------------------------------------------------
class CGGameCommandInterpreter;

class CGGCICommand
{
	public:
			CGGCICommand(CGGameCommandInterpreter* _poCI) : m_poCI(_poCI) {};

			virtual ECIState Exec(CGString& _sPars) { return(CIS_Running); };
			virtual const CGString& sCommand() { return( (CGString&)""); };
			virtual const CGString& sHelpString() { return((CGString&)""); };

	protected:
			CGGameCommandInterpreter* m_poCI;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
