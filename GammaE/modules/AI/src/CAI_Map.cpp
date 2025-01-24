// Map.cpp: implementation of the Map class.
//
//////////////////////////////////////////////////////////////////////

#ifndef NULL
#define NULL 0
#endif

#include "CAI_Map.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAI_Map::CAI_Map()
{
	m_Width = 0;
	m_Height = 0;
	lTiles = NULL;
}

CAI_Map::~CAI_Map()
{
	if (lTiles != NULL)
	{
		delete [] lTiles;
	}
}

long CAI_Map::GetTile(long x, long y)
{
	if (lTiles == NULL)
	{
		return 0;
	}

	if ((x + m_Width * y) > (m_Width * m_Height))
	{
		return 0;
	}

	return lTiles[x + m_Width * y];
}

void CAI_Map::SetTile(long x, long y, long t)
{
	if (lTiles == NULL)
	{
		return;
	}

	if ((x + m_Width * y) > (m_Width * m_Height))
	{
		return;
	}

	lTiles[x + m_Width * y] = t;

}

void CAI_Map::NewMap(long width, long height)
{
	if (lTiles != NULL)
	{
		delete [] lTiles;
	}
	
	m_Width = 0;
	m_Height = 0;
	lTiles = NULL;

	lTiles = new long[width * height+1];

	if (lTiles == NULL)
	{
		return;
	}

	m_Width = width;
	m_Height = height;

	for (long i = 0; i <= (width * height); i++)
	{
		lTiles[i] = 0;
	}
}
