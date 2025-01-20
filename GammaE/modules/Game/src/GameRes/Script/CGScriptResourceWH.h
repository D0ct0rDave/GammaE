// ----------------------------------------------------------------------------
#ifndef CGScriptResourceWHH
#define CGScriptResourceWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGScriptResource.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGScriptResourceWH,CGDiskResourceWH,CGScriptResource)
{	
	public:	
			virtual CGScriptResource* poLoadResource(const CGString &_sFilename);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
