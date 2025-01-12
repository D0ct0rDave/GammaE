//---------------------------------------------------------------------------
#ifndef MipMapWHH
#define MipMapWHH
//---------------------------------------------------------------------------
#include <Tex.h>
#include "MipMapObj.h"
//---------------------------------------------------------------------------
#define E3D_MIPMAP_WAREHOUSE_MAX_MIPMAPS    256
//---------------------------------------------------------------------------
#ifndef MAX_CARS
#define MAX_CARS 256
#endif
//---------------------------------------------------------------------------
typedef struct{
    char MipMapName[MAX_CARS];  // Possibly the filename
    TMipMapObj    MMData;
    bool          Valid;
}TMMWH_MipMapEntry;
//---------------------------------------------------------------------------
class TMipMapWarehouse
{
public:
        TMipMapWarehouse();
        ~TMipMapWarehouse();
                
        static void InvalidateWarehouse();

        // static TMipMapObj *AllocMipMap(char *MipMapName,unsigned int TX,unsigned int TY,PixelFormat PixelFormat,unsigned int NumLODS);
        // static void FreeMipMapEntry(TMipMapObj *MipMap);
        static TMipMapObj *LoadMipMap(char *Filename,unsigned int NumLODS);
private:
        static TMMWH_MipMapEntry *FindMipMapEntry(char *MipMapName);
        static TMMWH_MipMapEntry *FindMipMap(TMipMapObj *MipMap);
        static TMMWH_MipMapEntry *FindFreeMipMapEntry();

        static TMMWH_MipMapEntry MMs[E3D_MIPMAP_WAREHOUSE_MAX_MIPMAPS];

        static unsigned int NumMMEntries;
};
//---------------------------------------------------------------------------
#endif
