// ----------------------------------------------------------------------------
#ifndef CGCoronaGenDefFileWHH
#define CGCoronaGenDefFileWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGCoronaGenDefFileWH,CGDiskResourceWH,CGTextResource)
{
	public:
		virtual CGTextResource* poLoadResource(const CGString& _sFilename);
		virtual void Reload();

	private:

		void ProcessCoronaGenDefFile(const CGString& _sPSGDefFilename);	
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
