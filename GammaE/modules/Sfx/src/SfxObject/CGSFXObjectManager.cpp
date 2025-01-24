#include "CGSFXObjectManager.h"
#include "Coronas/CGCoronaGenWH.h"
#include "Coronas/CGCoronaInstance.h"

/*
#define DECLARE_WAREHOUSE(CLASSNAME, WAREHOUSETYPE, RESOURCETYPE )\
class CLASSNAME : public WAREHOUSETYPE<RESOURCETYPE,CLASSNAME>


template <typename T, typename B> 
class CGResourceWH: public CGSingleton<B>
...

*/

DECLARE_SFXOBJECTMANAGER(CGCoronaManager2,CGCoronaInstance,CGCoronaGenerator,CGCoronaGenWH)
// class CGCoronaManager2 : public CGSFXObjectManager<CGCoronaInstance,CGCoronaGenWH,CGCoronaManager2>
{

};

void caca()
{
	CGCoronaManager2::I()->uiCreatePool("caca",10);
	handler h = CGCoronaManager2::I()->hGet("caca");
	CGCoronaManager2::I()->Release(h);
	CGCoronaManager2::I()->bEnabled(h);
	CGCoronaManager2::I()->Enable(h,false);
	CGCoronaManager2::I()->SetPos(h,CVect3::oZero());
	CGCoronaManager2::I()->SetDir(h,CVect3::oZero());
	CGCoronaManager2::I()->poGetManagerNode();
	CGCoronaManager2::I()->Update(0.0f);
}
