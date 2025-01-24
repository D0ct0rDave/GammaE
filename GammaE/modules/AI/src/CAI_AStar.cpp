// AStar.cpp : Implementation of CAStar
#include "CAI_AStar.h"

/////////////////////////////////////////////////////////////////////////////
// CAStar


void CAI_AStar::Allow8Directions(bool bAllowed)
{

	bAllow8Directions = bAllowed;
}

long CAI_AStar::lNodeGetY()
{
	if (map.lTiles	== NULL) return(-1);
	if (pAStar		== NULL) return(-1);

	return (pAStar->NodeGetY());
}

long CAI_AStar::lNodeGetX()
{
	if (map.lTiles	== NULL) return(-1);
	if (pAStar		== NULL) return(-1);

	return (pAStar->NodeGetX());
}

void CAI_AStar::NextPathNode()
{
	if (map.lTiles	== NULL) return;
	if (pAStar		== NULL) return;

	pAStar->PathNextNode();
}

bool CAI_AStar::bGoalReached()
{
	if (map.lTiles	== NULL) return(false);
	if (pAStar		== NULL) return(false);

	return (pAStar->ReachedGoal());
}

bool CAI_AStar::bFindAPath(long x1, long y1, long x2, long y2)
{
	if (map.lTiles == NULL) return(false);

	if (pAStar != NULL)	delete pAStar;
	pAStar = NULL;
	pAStar = new CDXAStar(&map, 1);
	if (pAStar == NULL) return(false);

	pAStar->is8Directions = this->bAllow8Directions;

	pAStar->Width  = this->Width;
	pAStar->Height = this->Height;

	if (! pAStar->NewPath(x1, y1, x2, y2))
	{
		delete pAStar;
		pAStar = NULL;
		return(false);
	}
	else
		return(true);
}

long CAI_AStar::lGetTile(long x, long y)
{
	return ( map.GetTile(x, y) );
}

void CAI_AStar::SetTile(long x, long y, long t)
{
	map.SetTile(x, y, t);
}

void CAI_AStar::NewMap(long width, long height)
{
	map.NewMap(width, height);
}

void CAI_AStar::SetWidth(long lWidth)
{
	Width = lWidth;
}

void CAI_AStar::SetHeight(long lHeight)
{
	Height = lHeight;
}