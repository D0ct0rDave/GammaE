//## begin module%3AFEFAC30136.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFAC30136.cm

//## begin module%3AFEFAC30136.cp preserve=no
//## end module%3AFEFAC30136.cp

//## Module: CTileBookmark%3AFEFAC30136; Pseudo Package body
//## Source file: i:\Projects\GammaE\Terrain\TerrainMaterials\CTileBookmark.cpp

//## begin module%3AFEFAC30136.additionalIncludes preserve=no
//## end module%3AFEFAC30136.additionalIncludes

//## begin module%3AFEFAC30136.includes preserve=yes
#include <assert.h>
#include <string.h>
#include "Memory/GammaE_mem.h"
//## end module%3AFEFAC30136.includes

// CTileBookmark
#include "Terrain\TerrainMaterials\CTileBookmark.h"
//## begin module%3AFEFAC30136.additionalDeclarations preserve=yes
//## end module%3AFEFAC30136.additionalDeclarations


// Class CTileBookmark 





CTileBookmark::CTileBookmark()
  //## begin CTileBookmark::CTileBookmark%.hasinit preserve=no
      : Tiles(NULL), MaxTiles(0), MaxLODs(0), TileLODs(NULL)
  //## end CTileBookmark::CTileBookmark%.hasinit
  //## begin CTileBookmark::CTileBookmark%.initialization preserve=yes
  //## end CTileBookmark::CTileBookmark%.initialization
{
  //## begin CTileBookmark::CTileBookmark%.body preserve=yes
  //## end CTileBookmark::CTileBookmark%.body
}


CTileBookmark::~CTileBookmark()
{
  //## begin CTileBookmark::~CTileBookmark%.body preserve=yes
	if (Tiles) Invalidate();
  //## end CTileBookmark::~CTileBookmark%.body
}



//## Other Operations (implementation)
void CTileBookmark::Init (int _MaxTiles, int _MaxLODs)
{
  //## begin CTileBookmark::Init%989790238.body preserve=yes
	Tiles    = mNew CE3D_Shader *[_MaxTiles*_MaxLODs];
	
	TileLODs = mNew int[_MaxTiles];
	memset(TileLODs,0,sizeof(int)*_MaxTiles);

	MaxTiles = _MaxTiles;
	MaxLODs  = _MaxLODs;
  //## end CTileBookmark::Init%989790238.body
}

void CTileBookmark::SetTileMaterial (int _iTile, int _iLOD, CE3D_Shader* _Mat)
{
  //## begin CTileBookmark::SetTileMaterial%989790239.body preserve=yes
	assert(Tiles && "NULL Tile material array");
	assert((_iTile < MaxTiles) && "Invalid tile material index");
	assert((_iLOD  < MaxLODs ) && "Invalid tile LOD");

	Tiles[_iTile*MaxLODs + _iLOD] = _Mat;
	if (TileLODs[_iTile] < _iLOD) TileLODs[_iTile] = _iLOD;
  //## end CTileBookmark::SetTileMaterial%989790239.body
}

CE3D_Shader* CTileBookmark::poGetTileMaterial (int _iTile, int _iLOD)
{
  //## begin CTileBookmark::poGetTileMaterial%989958287.body preserve=yes
	assert(Tiles && "NULL Tile material array");
	assert((_iTile < MaxTiles) && "Invalid tile material index");
	assert((_iLOD  < MaxLODs ) && "Invalid tile LOD");

	return ( Tiles[_iTile*MaxLODs + _iLOD] );
  //## end CTileBookmark::poGetTileMaterial%989958287.body
}

int CTileBookmark::GetTileLODs (int _iTile)
{
  //## begin CTileBookmark::GetTileLODs%990048932.body preserve=yes
	return (TileLODs[_iTile]+1);
  //## end CTileBookmark::GetTileLODs%990048932.body
}

void CTileBookmark::Invalidate ()
{
  //## begin CTileBookmark::Invalidate%989790241.body preserve=yes
	if (Tiles)	  mDel []Tiles;
	if (TileLODs) mDel []TileLODs;
	
	Tiles    = NULL;
	TileLODs = NULL;
	MaxTiles = 0;
	MaxLODs  = 0;
  //## end CTileBookmark::Invalidate%989790241.body
}

// Additional Declarations
  //## begin CTileBookmark%3AFEFAC30136.declarations preserve=yes
  //## end CTileBookmark%3AFEFAC30136.declarations

//## begin module%3AFEFAC30136.epilog preserve=yes
//## end module%3AFEFAC30136.epilog
