// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef NULL
    #define NULL 0
#endif
// ----------------------------------------------------------------------------
#include "CGMap.h"
// ----------------------------------------------------------------------------
// ////////////////////////////////////////////////////////////////////
// Construction/Destruction
// ////////////////////////////////////////////////////////////////////

CGMap::CGMap()
{
    m_Width = 0;
    m_Height = 0;
    lTiles = NULL;
}

CGMap::~CGMap()
{
    if ( lTiles != NULL )
    {
        delete [] lTiles;
    }
}

long CGMap::GetTile(long x, long y)
{
    if ( lTiles == NULL )
    {
        return(0);
    }

    if ( (x + m_Width * y) > (m_Width * m_Height) )
    {
        return(0);
    }

    return(lTiles[x + m_Width * y]);
}

void CGMap::SetTile(long x, long y, long t)
{
    if ( lTiles == NULL )
    {
        return;
    }

    if ( (x + m_Width * y) > (m_Width * m_Height) )
    {
        return;
    }

    lTiles[x + m_Width * y] = t;
}

void CGMap::NewMap(long width, long height)
{
    if ( lTiles != NULL )
    {
        delete [] lTiles;
    }

    m_Width = 0;
    m_Height = 0;
    lTiles = NULL;

    lTiles = new long[width * height + 1];

    if ( lTiles == NULL )
    {
        return;
    }

    m_Width = width;
    m_Height = height;

    for ( long i = 0; i <= (width * height); i++ )
    {
        lTiles[i] = 0;
    }
}
// ----------------------------------------------------------------------------
