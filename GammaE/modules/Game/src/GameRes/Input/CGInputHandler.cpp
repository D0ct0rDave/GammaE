// -----------------------------------------------------------------------------
#include "CGInputHandler.h"
// -----------------------------------------------------------------------------
void CGInputHandler::Register(const CGString& _rsCommand)
{
	m_oCommandList.uiAddVar(_rsCommand,0.0f);
}
// -----------------------------------------------------------------------------		
float CGInputHandler::fGetValue(const CGString& _rsCommand)	const
{
	return( m_oCommandList.oGetVar(_rsCommand) );
}
// -----------------------------------------------------------------------------
void CGInputHandler::SetValue(const CGString& _rsCommand,float _fValue)
{
	m_oCommandList.SetVar(_rsCommand,_fValue);
}
// -----------------------------------------------------------------------------
void CGInputHandler::Clear()
{
	m_oCommandList.Clear();
}
// -----------------------------------------------------------------------------
