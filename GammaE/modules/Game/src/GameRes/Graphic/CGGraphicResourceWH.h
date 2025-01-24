// ----------------------------------------------------------------------------
#ifndef CGGraphicResourceWHH
#define CGGraphicResourceWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGGraphicResource.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGGraphicResourceWH,CGDiskResourceWH,CGGraphicResource)
{	
	public:	
			virtual CGGraphicResource* poLoadResource(const CGString &_sFilename);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
