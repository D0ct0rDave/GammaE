#include "CGCommandBinder.h"
//-----------------------------------------------------------------------------
CGCommandBinder::CGCommandBinder()
{
	m_oCBTable.Init(CMDBINDER_MAX_BINDABLE_KEYS);

	//-----------------------------------------------------------------------------
	UnBindAll();
}
//-----------------------------------------------------------------------------
void CGCommandBinder::Bind(uint _uiKey,uint _uiCmd,const CGString& _sParameters)
{
	if (_uiKey >= CMDBINDER_MAX_BINDABLE_KEYS)
	{
		CGWarningLC::I()->Write("Unable to bind key %d."
								"Key Index out of bounds.",_uiKey);
		return;
	}

	m_oCBTable[_uiKey].m_uiCommand   = _uiCmd;
	m_oCBTable[_uiKey].m_sParameters = _sParameters;
}
//-----------------------------------------------------------------------------
void CGCommandBinder::UnBind(uint _uiKey)
{
	if (_uiKey >= CMDBINDER_MAX_BINDABLE_KEYS)
	{
		CGWarningLC::I()->Write("Unable to unbind key %d."
								"Key Index out of bounds.",_uiKey);
		return;
	}

	m_oCBTable[_uiKey].m_uiCommand  = 0xffffffff;
	m_oCBTable[_uiKey].m_sParameters = "";
}
//-----------------------------------------------------------------------------
int CGCommandBinder::iBindedCommand(uint _uiKey)
{
	if (_uiKey >= CMDBINDER_MAX_BINDABLE_KEYS)
	{
		CGWarningLC::I()->Write("Unable to retrieve command for key %d."
								"Key Index out of bounds.", _uiKey);
		return(-1);
	}

	return(m_oCBTable[_uiKey].m_uiCommand);
}
//-----------------------------------------------------------------------------
const CGString& CGCommandBinder::sBindedParameters(uint _uiKey)
{
	if (_uiKey >= CMDBINDER_MAX_BINDABLE_KEYS)
	{
		CGWarningLC::I()->Write("Unable to retrieve command for key %d."
								"Key Index out of bounds.", _uiKey);
		return(-1);
	}

	return(m_oCBTable[_uiKey].m_sParameters);
}
//-----------------------------------------------------------------------------
void CGCommandBinder::UnBindAll()
{
	m_oCBTable.Clear();
	
	for (uint i=0;i<CMDBINDER_MAX_BINDABLE_KEYS;i++)
	{
		TCmdPair oCmd;
		oCmd.m_uiCommand   = 0xffffffff;
		oCmd.m_sParameters = "";
		
		m_oCBTable.iAdd(oCmd);
	}
}
//-----------------------------------------------------------------------------
