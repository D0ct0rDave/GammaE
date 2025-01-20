//-----------------------------------------------------------------------------
#ifndef CGCommandBinderH
#define CGCommandBinderH
//-----------------------------------------------------------------------------
#include "GammaE_Misc.h"
/*
#define			CmdBinder_KEY_BUTTON_OFFSET	128
#define			CmdBinder_MOUSE_BUTTON0		(CmdBinder_KEY_BUTTON_OFFSET  )
#define			CmdBinder_MOUSE_BUTTON1		(CmdBinder_KEY_BUTTON_OFFSET+1)
#define			CmdBinder_MOUSE_BUTTON2		(CmdBinder_KEY_BUTTON_OFFSET+2)
#define			CmdBinder_MOUSE_BUTTON3		(CmdBinder_KEY_BUTTON_OFFSET+3)
#define			CmdBinder_MOUSE_BUTTON4		(CmdBinder_KEY_BUTTON_OFFSET+4)
*/
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const int CMDBINDER_MAX_BINDABLE_KEYS = 256;

DECLARE_SINGLETON(CGCommandBinder)
{
	public:
		CGCommandBinder();

		void Bind(uint _uiKey,uint _uiCmd,const CGString& _sParameters = "");
		void UnBind(uint _uiKey);		
		int iBindedCommand(uint _uiKey);
		const CGString& sBindedParameters(uint _uiKey);
		
		void UnBindAll();

	private:
		typedef struct TCmdPair
		{
			uint		m_uiCommand;
			CGString	m_sParameters;
		}TCmdPair;
		
		CGStArray <TCmdPair> m_oCBTable;
};

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------