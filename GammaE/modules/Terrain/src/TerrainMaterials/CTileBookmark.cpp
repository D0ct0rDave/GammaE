// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// %X% %Q% %Z% %W%

#include <assert.h>
#include <string.h>
#include "GammaE_Mem.h"

// CTileBookmark
#include "TerrainMaterials\CTileBookmark.h"

// Class CTileBookmark

CTileBookmark::CTileBookmark()
    : Tiles(NULL), MaxTiles(0), MaxLODs(0), TileLODs(NULL)
{
}

CTileBookmark::~CTileBookmark()
{
    if ( Tiles ) Invalidate();
}

void CTileBookmark::Init (int _MaxTiles, int _MaxLODs)
{
    Tiles = mNew CGShader *[_MaxTiles * _MaxLODs];

    TileLODs = mNew int[_MaxTiles];
    memset(TileLODs,0,sizeof(int) * _MaxTiles);

    MaxTiles = _MaxTiles;
    MaxLODs = _MaxLODs;
}

void CTileBookmark::SetTileMaterial (int _iTile, int _iLOD, CGShader* _Mat)
{
    assert(Tiles && "NULL Tile material array");
    assert( (_iTile < MaxTiles) && "Invalid tile material index" );
    assert( (_iLOD < MaxLODs) && "Invalid tile LOD" );

    Tiles[_iTile * MaxLODs + _iLOD] = _Mat;
    if ( TileLODs[_iTile] < _iLOD ) TileLODs[_iTile] = _iLOD;
}

CGShader* CTileBookmark::poGetTileMaterial (int _iTile, int _iLOD)
{
    assert(Tiles && "NULL Tile material array");
    assert( (_iTile < MaxTiles) && "Invalid tile material index" );
    assert( (_iLOD < MaxLODs) && "Invalid tile LOD" );

    return (Tiles[_iTile * MaxLODs + _iLOD]);
}

int CTileBookmark::GetTileLODs (int _iTile)
{
    return (TileLODs[_iTile] + 1);
}

void CTileBookmark::Invalidate ()
{
    if ( Tiles ) mDel [] Tiles;
    if ( TileLODs ) mDel [] TileLODs;

    Tiles = NULL;
    TileLODs = NULL;
    MaxTiles = 0;
    MaxLODs = 0;
}

// Additional Declarations
