// ----------------------------------------------------------------------------
#ifndef CGColliderDefinitionFileWHH
#define CGColliderDefinitionFileWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGColliderPrimitive.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGColliderDefinitionFileWH,CGDiskResourceWH,CGTextResource)
{	
	public:	
			virtual CGTextResource* poLoadResource(const CGString &_sFilename);
	
	protected:
			void ProcessColliderDefFile(const CGString& _sColliderDefFilename);	
			CGColliderPrimitive* poRetrieveCollider(const CGConfigFile& _oCfg,const CGString& _sSection);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
