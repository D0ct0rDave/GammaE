//-----------------------------------------------------------------------------
#include "CGCommandRegistry.h"
//-----------------------------------------------------------------------------
void CGCommandRegistry::DispatchCommand(uint _uiCmdIdx,uint _uiCmdPar0,uint _uiCmdPar1,uint _uiCmdPar2,const CGString& _sCmdPars)
{
	if (_uiCmdIdx >= m_oDCCTable.uiNumElems())
	{
			CGWarningLC::I()->Write("Unable to dispatch command callback.\n"
							       "Command index out of bounds");
			return;
	}

	if ( m_oDCCTable[_uiCmdIdx] )
		m_oDCCTable[_uiCmdIdx](_uiCmdPar0,_uiCmdPar1,_uiCmdPar2,_sCmdPars);
}
//-----------------------------------------------------------------------------