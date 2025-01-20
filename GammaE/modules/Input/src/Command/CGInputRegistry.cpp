//-----------------------------------------------------------------------------
#include "CGInputRegistry.h"
//-----------------------------------------------------------------------------
CGInputRegistry::CGInputRegistry()
{
}
//-----------------------------------------------------------------------------
void CGInputRegistry::Register(const CGString& _sInputName,uint _uiInputValue)
{
	int iIdx = iInput(_sInputName);
	if (iIdx == -1)
	{
		//-----------------------------------------------------------------------------
		uint uiIdx = m_oInputs.uiAddVar(_sInputName.szString(),_uiInputValue);
	}
}
//-----------------------------------------------------------------------------
int CGInputRegistry::iInput(const CGString& _sInputName)
{
	int iIdx = m_oInputs.iGetIdx( _sInputName.szString() );

	if (iIdx == -1)
		return(-1);
	else
		return ( m_oInputs.oGetElem(iIdx) );
}
//-----------------------------------------------------------------------------

