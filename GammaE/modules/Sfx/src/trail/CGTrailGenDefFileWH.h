// ----------------------------------------------------------------------------
#ifndef CGTrailGenDefFileWHH
#define CGTrailGenDefFileWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGTrailGenDefFileWH,CGDiskResourceWH,CGTextResource)
{
	public:
		virtual CGTextResource* poLoadResource(const CGString& _sFilename);
		virtual void Reload();

	private:

		void ProcessTrailGenDefFile(const CGString& _sPSGDefFilename);	
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
