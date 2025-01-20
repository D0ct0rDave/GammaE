// -----------------------------------------------------------------------------
#ifndef CGInputHandlerH
#define CGInputHandlerH
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// -----------------------------------------------------------------------------
class CGInputHandler
{
public:
		CGInputHandler() {};
		
		/// Register a usable command on the input handler
		void Register(const CGString& _rsCommand);
		
		/// Retrieves the value of a registered command
		void SetValue(const CGString& _rsCommand,float _fValue);

		/// Retrieves the value of a registered command
		float fGetValue(const CGString& _rsCommand) const;

		/// Erases all the commands registered on the command handler
		void Clear();

protected:
		CGLookupArray <float> m_oCommandList;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
