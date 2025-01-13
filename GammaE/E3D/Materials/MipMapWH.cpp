//---------------------------------------------------------------------------
#include <string.h>
//---------------------------------------------------------------------------
#include "tex.h"
#include "MipMapWH.h"
#include <assert.h>

//---------------------------------------------------------------------------
#ifndef NULL
#define NULL 0
#endif

//---------------------------------------------------------------------------

TMMWH_MipMapEntry TMipMapWarehouse::MMs[E3D_MIPMAP_WAREHOUSE_MAX_MIPMAPS];
unsigned int TMipMapWarehouse::NumMMEntries;

//---------------------------------------------------------------------------
TMipMapWarehouse::TMipMapWarehouse()
{
    memset(MMs,0,sizeof(TMMWH_MipMapEntry)*E3D_MIPMAP_WAREHOUSE_MAX_MIPMAPS);
    NumMMEntries = 0;
}
//---------------------------------------------------------------------------
TMipMapWarehouse::~TMipMapWarehouse()
{
    InvalidateWarehouse();
}
//---------------------------------------------------------------------------
void TMipMapWarehouse::InvalidateWarehouse()
{
    unsigned int cMMEntry;
    for (cMMEntry=0;cMMEntry<E3D_MIPMAP_WAREHOUSE_MAX_MIPMAPS;cMMEntry++)
        if (MMs[cMMEntry].Valid)
        {
            DestroyMipMap(MMs[cMMEntry].MMData.mipMap);
            MMs[cMMEntry].Valid = false;
        }

    NumMMEntries=0;
}
//---------------------------------------------------------------------------
TMMWH_MipMapEntry *TMipMapWarehouse::FindMipMapEntry(char *MipMapName)
{
    unsigned int cMMEntry;
    for (cMMEntry=0;cMMEntry<E3D_MIPMAP_WAREHOUSE_MAX_MIPMAPS;cMMEntry++)
        if (MMs[cMMEntry].Valid)
        {
            if (! strcmp(MMs[cMMEntry].MipMapName,MipMapName))
                return(&MMs[cMMEntry]);
        }

    // MipMap not found
    return(NULL);
}
//---------------------------------------------------------------------------
TMMWH_MipMapEntry *TMipMapWarehouse::FindFreeMipMapEntry()
{
    unsigned int cMMEntry;
    for (cMMEntry=0;cMMEntry<E3D_MIPMAP_WAREHOUSE_MAX_MIPMAPS;cMMEntry++)
        if (! MMs[cMMEntry].Valid) return(&MMs[cMMEntry]);

    // Not free entries
    return(NULL);
}
//---------------------------------------------------------------------------
TMMWH_MipMapEntry *TMipMapWarehouse::FindMipMap(TMipMapObj *MipMap)
{
    unsigned int cMMEntry;
    for (cMMEntry=0;cMMEntry<E3D_MIPMAP_WAREHOUSE_MAX_MIPMAPS;cMMEntry++)
        if (! (&MMs[cMMEntry].MMData == MipMap)) return(&MMs[cMMEntry]);

    // MipMap not found
    return(NULL);
}
//---------------------------------------------------------------------------
/*
TMipMapObj *TMipMapWarehouse::AllocMipMap(char *MipMapName,unsigned int TX,unsigned int TY,PixelFormat PixelFormat,unsigned int NumLODS)
{
    assert(false, "AllocMipMap method called!");

    TMMWH_MipMapEntry* MMEntry;

    MMEntry = FindMipMapEntry(MipMapName);
    if (MMEntry) return(&MMEntry->MMData);

    MMEntry = FindFreeMipMapEntry();
    if (! MMEntry) return(NULL);

    if (! MipMap_fn_iAllocateMipMap(&MMEntry->MMData.MipMap,TX,TY,PixelFormat,NumLODS))
        return(NULL);

    strcpy(MMEntry->MipMapName,MipMapName);
    MMEntry->MMData.Update = true;
    MMEntry->Valid     = true;

    return(&MMEntry->MMData);

    return NULL;
}
*/
//---------------------------------------------------------------------------

void TMipMapWarehouse::FreeMipMapEntry(TMipMapObj* MipMap)
{
    TMMWH_MipMapEntry* MMEntry;

    MMEntry = FindMipMap(MipMap);
    if (! MMEntry) return;

    if (MMEntry->Valid)
    {
        DestroyMipMap(MMEntry->MMData.mipMap);
        MMEntry->Valid = false;

        NumMMEntries--;
    }
}

//---------------------------------------------------------------------------
// If mipmap texture not found, please implement the return of a null texture.
//---------------------------------------------------------------------------
TMipMapObj *TMipMapWarehouse::LoadMipMap(char *Filename,unsigned int NumLODS)
{
    TMMWH_MipMapEntry* MMEntry;

    MMEntry = FindMipMapEntry(Filename);
    if (MMEntry) return(&MMEntry->MMData);

    MMEntry = FindFreeMipMapEntry();
    if (! MMEntry) return(NULL);
    
    Texture* _poTex = poLoadTexture(Filename);
    if (_poTex == NULL)
    {
        return(NULL);
    }

    MMEntry->MMData.mipMap = poCreateMipMapFromTexture(_poTex);

    DestroyTexture(_poTex);

	strcpy(MMEntry->MipMapName, Filename);
    MMEntry->MMData.Update = true;
    MMEntry->Valid  = true;

    return(&MMEntry->MMData);
}
//---------------------------------------------------------------------------
// epilog: singleton initializer through static instantiation
//---------------------------------------------------------------------------
static TMipMapWarehouse oInstance;
//---------------------------------------------------------------------------

