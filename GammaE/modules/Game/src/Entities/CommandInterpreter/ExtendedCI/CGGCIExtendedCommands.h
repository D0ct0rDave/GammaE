//-----------------------------------------------------------------------------
#ifndef CGGCIExtendedCommands_h
#define CGGCIExtendedCommands_h 1
//-----------------------------------------------------------------------------
#include "../CGGCICommand.h"
//-----------------------------------------------------------------------------
class CGGameCommandInterpreter;

class CGGCICommandSystemLog : public CGGCICommand
{
	public: CGGCICommandSystemLog(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};

class CGGCICommandErrorLog : public CGGCICommand
{
	public: CGGCICommandErrorLog(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();
};

class CGGCICommandListEntities : public CGGCICommand
{
	public: CGGCICommandListEntities(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};

class CGGCICommandSwitchEntityState : public CGGCICommand
{
	public:	CGGCICommandSwitchEntityState(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};

class CGGCICommandClearErrorLog : public CGGCICommand
{
	public:	CGGCICommandClearErrorLog(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};

class CGGCICommandClearSysLog : public CGGCICommand
{
	public: CGGCICommandClearSysLog(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
