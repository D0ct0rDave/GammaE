// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGCommandRegistryH
#define CGCommandRegistryH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------Registers commands and the callbacks for these commands.
// ----------------------------------------------------------------------------
typedef void (*TDispatchCommandCallback)(uint _uiCmdPar0,uint _uiCmdPar1,uint _uiCmdPar2,const CGString& _sCmdPars);
// ----------------------------------------------------------------------------

DECLARE_SINGLETON(CGCommandRegistry)
{
    public:
        // / Registers a command and associates it to the given callback
        void RegisterCommand(const CGString& _sCmd,TDispatchCommandCallback _pDCCB)
        {
            CGString sCmd = _sCmd.UpperCase();
            m_oDCCTable.uiAddVar(sCmd,_pDCCB);
        }

        // / Retrieves the index for a given command, -1 if not found in the registry
        int iRetrieveCommand(const CGString& _sCmd)
        {
            CGString sCmd = _sCmd.UpperCase();
            return ( m_oDCCTable.iGetIdx(sCmd) );
        }

        // / Dispatches the callback associated to the given command index
        void DispatchCommand(uint _uiCmdIdx,uint _uiCmdPar0,uint _uiCmdPar1,uint _uiCmdPar2,const CGString &_sCmdPars);

    private:

        CGLookupArray <TDispatchCommandCallback> m_oDCCTable;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
