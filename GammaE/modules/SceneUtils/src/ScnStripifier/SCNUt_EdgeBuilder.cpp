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

// SCNUt_EdgeBuilder
#include "ScnStripifier\SCNUt_EdgeBuilder.h"

// Class SCNUt_EdgeBuilder

SCNUt_EdgeBuilder::SCNUt_EdgeBuilder()
{
}

SCNUt_EdgeBuilder::~SCNUt_EdgeBuilder()
{
}

SCNUt_EdgeList* SCNUt_EdgeBuilder::poBuild (CGMesh* _poMesh, CGMesh*&_poOutMesh)
{
    if ( !_poMesh ) return(NULL);

    SCNUt_TriScene* poTS;
    SCNUt_Mesh2TriScene oM2TS;
    SCNUt_MeshCompacter oMComp;
    SCNUt_EdgeList* poEdgeList;

    // Generate a raw triangle scene
    poTS = oM2TS.Generate(*_poMesh,0);

    // Generate a compact mesh
    _poOutMesh = oMComp.poCompactMesh(*poTS);

    // Build the edge adjacency list
    poEdgeList = poBuild_FromIndexedTriMesh (_poOutMesh);

    // Delete triangle scene & compact mesh
    mDel poTS;

    return (poEdgeList);
}

SCNUt_EdgeList* SCNUt_EdgeBuilder::poBuild_FromIndexedTriMesh (CGMesh* _poMesh)
{
    SCNUt_EdgeList* poEdgeList;
    int iTri;
    SCNUt_Edge oEdge;

    poEdgeList = mNew SCNUt_EdgeList;

    for ( iTri = 0; iTri < _poMesh->m_uiNumPrims; iTri++ )
    {
        // Vertex 0
        oEdge.A = _poMesh->m_pusIdx[iTri * 3 + 0];
        oEdge.B = _poMesh->m_pusIdx[iTri * 3 + 1];

        poEdgeList->iAdd(oEdge);

        // Vertex 1
        oEdge.A = _poMesh->m_pusIdx[iTri * 3 + 1];
        oEdge.B = _poMesh->m_pusIdx[iTri * 3 + 2];

        poEdgeList->iAdd(oEdge);

        // Vertex 2
        oEdge.A = _poMesh->m_pusIdx[iTri * 3 + 2];
        oEdge.B = _poMesh->m_pusIdx[iTri * 3 + 0];

        poEdgeList->iAdd(oEdge);
    }

    return(poEdgeList);
}

// Additional Declarations
