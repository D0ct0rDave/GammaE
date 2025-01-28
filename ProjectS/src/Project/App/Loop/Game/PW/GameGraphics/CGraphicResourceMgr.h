// -----------------------------------------------------------------------------
#ifndef CGraphicResourceMgrH
#define CGraphicResourceMgrH
// -----------------------------------------------------------------------------
#include "CGraphicResource.h"
#include "antares.h"
// -----------------------------------------------------------------------------

class CGraphicResourceMgr
{
public:
	static void Register(char* _szResourceName,CGraphicResource* _poGRes);
	static CGraphicResource* poGetResource(char* _szResourceName);
	static void Invalidate();

	static MEM_HashTable <CGraphicResource*> m_aoGraphicResources;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------