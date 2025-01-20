//---------------------------------------------------------------------------
#ifndef MipMapObjH
#define MipMapObjH
//---------------------------------------------------------------------------
#define E3D_MAX_MIPMAP_LODS                 4
//---------------------------------------------------------------------------
struct MipMap;
typedef struct{
    MipMap*      mipMap;
    unsigned int Handler;    // Mipmap handler for the driver
    bool         Update;
}TMipMapObj;
//---------------------------------------------------------------------------
#endif
