// ----------------------------------------------------------------------------
#ifndef CGPathDefinitionFileWHH
#define CGPathDefinitionFileWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGPathDefinitionFileWH,CGDiskResourceWH,CGTextResource)
{	
	public:	
			virtual CGTextResource* poLoadResource(const CGString &_sFilename);
	
	protected:
			void ProcessPathDefFile(const CGString& _sPathDefFilename);	
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
