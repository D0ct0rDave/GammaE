//-----------------------------------------------------------------------------
#ifndef CGGCIStdCommands_h
#define CGGCIStdCommands_h 1
//-----------------------------------------------------------------------------
#include "CGGCICommand.h"
//-----------------------------------------------------------------------------
class CGGameCommandInterpreter;

class CGGCICommandHelp : public CGGCICommand
{
	public: CGGCICommandHelp(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};
//-----------------------------------------------------------------------------
class CGGCICommandExec : public CGGCICommand
{
	public:	CGGCICommandExec(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};
//-----------------------------------------------------------------------------
class CGGCICommandNop : public CGGCICommand
{
	public: CGGCICommandNop(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};
//-----------------------------------------------------------------------------
class CGGCICommandEcho : public CGGCICommand
{
	public: CGGCICommandEcho(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};
//-----------------------------------------------------------------------------
class CGGCICommandDelay : public CGGCICommand
{
	public: CGGCICommandDelay(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};
//-----------------------------------------------------------------------------
class CGGCICommandCls : public CGGCICommand
{
	public: CGGCICommandCls(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};
//-----------------------------------------------------------------------------
class CGGCICommandBind : public CGGCICommand
{
	public: CGGCICommandBind(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};
//-----------------------------------------------------------------------------
class CGGCICommandSet : public CGGCICommand
{
	public: CGGCICommandSet(CGGameCommandInterpreter* _poCI) : CGGCICommand(_poCI) {};
			virtual ECIState Exec(CGString& _sPars);
			virtual const CGString& sCommand();
			virtual const CGString& sHelpString();	
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
