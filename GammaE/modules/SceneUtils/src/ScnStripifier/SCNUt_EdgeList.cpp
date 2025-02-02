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
#include <string.h>
#include "GammaE_Mem.h"

// SCNUt_EdgeList
#include "ScnStripifier\SCNUt_EdgeList.h"

// Class SCNUt_EdgeList

SCNUt_EdgeList::SCNUt_EdgeList()
    : iNumEdges(0), iMaxEdges(0), Edge(NULL)
{
}

SCNUt_EdgeList::~SCNUt_EdgeList()
{
    if ( Edge ) mDel[] Edge;
}

int SCNUt_EdgeList::iAdd (SCNUt_Edge& _oEdge)
{
    // first search whether the given edge exists or not
    int iEdge;
    for ( iEdge = 0; iEdge < iNumEdges; iEdge++ )
    {
        if (
            ( (Edge[iEdge].A == _oEdge.A) && (Edge[iEdge].B == _oEdge.B) ) ||
            ( (Edge[iEdge].A == _oEdge.B) && (Edge[iEdge].B == _oEdge.A) )
            )
            return(iEdge);
    }

    // Need to realloc??
    if ( iNumEdges == iMaxEdges )
    {
        SCNUt_Edge* poEdges;

        iMaxEdges += 100;
        poEdges = mNew SCNUt_Edge[iMaxEdges];
        memcpy( poEdges,Edge,iNumEdges * sizeof(SCNUt_Edge) );
        mDel [] Edge;
        Edge = poEdges;
    }

    Edge[iNumEdges].A = _oEdge.A;
    Edge[iNumEdges].B = _oEdge.B;

    iNumEdges++;

    return (iNumEdges - 1);
}

void SCNUt_EdgeList::Clear ()
{
    iNumEdges = 0;
}

// Additional Declarations
