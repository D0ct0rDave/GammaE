//---------------------------------------------------------------------------
#include "TexObjWH.h"
#include "Memory/GammaE_Mem.h"
//---------------------------------------------------------------------------
#ifndef NULL
#define NULL 0
#endif
//---------------------------------------------------------------------------

TTextureObj  *TTexObjWarehouse::Warehouse   [E3D_TEXOBJ_WAREHOUSE_MAX_TEXOBJS];
char          TTexObjWarehouse::ActiveTexObj[E3D_TEXOBJ_WAREHOUSE_MAX_TEXOBJS];
unsigned int  TTexObjWarehouse::NumTexObjs;
//---------------------------------------------------------------------------
TTexObjWarehouse::TTexObjWarehouse()
{
    unsigned int cTexObj;

    for(cTexObj=0;cTexObj<E3D_TEXOBJ_WAREHOUSE_MAX_TEXOBJS;cTexObj++)
    {
        Warehouse   [cTexObj] = mNew(TTextureObj);
        ActiveTexObj[cTexObj] = 0;
    }

    NumTexObjs = 0;
}

TTexObjWarehouse::~TTexObjWarehouse()
{
    unsigned int cTexObj;
    for(cTexObj=0;cTexObj<E3D_TEXOBJ_WAREHOUSE_MAX_TEXOBJS;cTexObj++)
	{
        mDel (Warehouse[cTexObj]);
	}
}

void TTexObjWarehouse::InvalidateWarehouse()
{
    unsigned int cTexObj;
    for(cTexObj=0;cTexObj<E3D_TEXOBJ_WAREHOUSE_MAX_TEXOBJS;cTexObj++)
        ActiveTexObj[cTexObj] = 0;

    NumTexObjs = 0;
}

void TTexObjWarehouse::FreeTexObj(TTextureObj *TexObj)
{
    unsigned int cTexObj;
    for(cTexObj=0;cTexObj<E3D_TEXOBJ_WAREHOUSE_MAX_TEXOBJS;cTexObj++)
        if (Warehouse[cTexObj] == TexObj)
        {
            NumTexObjs--;
            ActiveTexObj[cTexObj] = 0;
            return;
        }
}
//---------------------------------------------------------------------------
TTextureObj *TTexObjWarehouse::AllocateTexObj()
{
    unsigned int cTexObj;
    for(cTexObj=0;cTexObj<E3D_TEXOBJ_WAREHOUSE_MAX_TEXOBJS;cTexObj++)
        if (! ActiveTexObj[cTexObj])
        {
            NumTexObjs++;
            ActiveTexObj[cTexObj] = 1;
            return(Warehouse[cTexObj]);
        }

    return(NULL);
}
//---------------------------------------------------------------------------
// epilog: singleton initializer through static instantiation
//---------------------------------------------------------------------------
static TTexObjWarehouse oInstance;
//---------------------------------------------------------------------------


