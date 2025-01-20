// ----------------------------------------------------------------------------
#ifndef CGPSGDefFileWHH
#define CGPSGDefFileWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGPSGDefFileWH,CGDiskResourceWH,CGTextResource)
{
	public:
		virtual CGTextResource* poLoadResource(const CGString& _sFilename);
		virtual void Reload();

	private:

		void ProcessPSGDefFile(const CGString& _sPSGDefFilename);	
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
