//---------------------------------------------------------------------------
#ifndef TexObjWHH
#define TexObjWHH
//---------------------------------------------------------------------------
#include "TexObj.h"
//---------------------------------------------------------------------------
#define E3D_TEXOBJ_WAREHOUSE_MAX_TEXOBJS    512
//---------------------------------------------------------------------------
class TTexObjWarehouse{
public:
             TTexObjWarehouse();
            ~TTexObjWarehouse();

            static void InvalidateWarehouse();
            static void FreeTexObj(TTextureObj *TexObj);
            static TTextureObj *AllocateTexObj();
private:
            static TTextureObj*  Warehouse   [E3D_TEXOBJ_WAREHOUSE_MAX_TEXOBJS];
            static char          ActiveTexObj[E3D_TEXOBJ_WAREHOUSE_MAX_TEXOBJS];
            static unsigned int  NumTexObjs;
};
//---------------------------------------------------------------------------
#endif
