// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */

#include "CGAIAStar.h"
// ----------------------------------------------------------------------------

// ///////////////////////////////////////////////////////////////////////////
// CAStar

void CGAIAStar::Allow8Directions(bool bAllowed)
{
    bAllow8Directions = bAllowed;
}

long CGAIAStar::lNodeGetY()
{
    if ( map.lTiles == NULL ) return(-1);
    if ( pAStar == NULL ) return(-1);

    return ( pAStar->NodeGetY() );
}

long CGAIAStar::lNodeGetX()
{
    if ( map.lTiles == NULL ) return(-1);
    if ( pAStar == NULL ) return(-1);

    return ( pAStar->NodeGetX() );
}

void CGAIAStar::NextPathNode()
{
    if ( map.lTiles == NULL ) return;
    if ( pAStar == NULL ) return;

    pAStar->PathNextNode();
}

bool CGAIAStar::bGoalReached()
{
    if ( map.lTiles == NULL ) return(false);
    if ( pAStar == NULL ) return(false);

    return ( pAStar->ReachedGoal() );
}

bool CGAIAStar::bFindAPath(long x1, long y1, long x2, long y2)
{
    if ( map.lTiles == NULL ) return(false);

    if ( pAStar != NULL ) delete pAStar;
    pAStar = NULL;
    pAStar = new CGAIDXAStar(&map, 1);
    if ( pAStar == NULL ) return(false);

    pAStar->is8Directions = this->bAllow8Directions;

    pAStar->Width = this->Width;
    pAStar->Height = this->Height;

    if ( !pAStar->NewPath(x1, y1, x2, y2) )
    {
        delete pAStar;
        pAStar = NULL;
        return(false);
    }
    else
        return(true);
}

long CGAIAStar::lGetTile(long x, long y)
{
    return ( map.GetTile(x, y) );
}

void CGAIAStar::SetTile(long x, long y, long t)
{
    map.SetTile(x, y, t);
}

void CGAIAStar::NewMap(long width, long height)
{
    map.NewMap(width, height);
}

void CGAIAStar::SetWidth(long lWidth)
{
    Width = lWidth;
}

void CGAIAStar::SetHeight(long lHeight)
{
    Height = lHeight;
}

// ----------------------------------------------------------------------------
