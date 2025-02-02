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

// SCNUt_AdjTriListBuilder
#include "ScnStripifier\SCNUt_AdjTriListBuilder.h"

// Class SCNUt_AdjTriListBuilder

SCNUt_AdjTriListBuilder::SCNUt_AdjTriListBuilder()
{
}

SCNUt_AdjTriListBuilder::~SCNUt_AdjTriListBuilder()
{
}

SCNUt_AdjTriList* SCNUt_AdjTriListBuilder::poBuild (CGMesh* _poMesh, CGMesh*&_poOutMesh)
{
    if ( !_poMesh ) return(NULL);

    SCNUt_TriScene* poTS;
    SCNUt_Mesh2TriScene oM2TS;
    SCNUt_MeshCompacter oMComp;
    SCNUt_AdjTriList* poATL;

    // Generate a raw triangle scene
    poTS = oM2TS.Generate(*_poMesh,0);

    // Generate a compact mesh
    _poOutMesh = oMComp.poCompactMesh(*poTS);

    // Build the triangle adjacency list
    poATL = poBuild_FromIndexedTriMesh (_poOutMesh);

    // Delete triangle scene
    mDel poTS;

    return (poATL);
}

SCNUt_AdjTriList* SCNUt_AdjTriListBuilder::poBuild_FromIndexedTriMesh (CGMesh* _poMesh)
{
    SCNUt_AdjTriList* poATL;
    int iTri;
    int iA,iB;

    // Create and init Adjacent Triangle List
    poATL = mNew SCNUt_AdjTriList;
    poATL->Init(_poMesh->uiGetNumPrims());

    for ( iTri = 0; iTri < _poMesh->uiGetNumPrims(); iTri++ )
    {
        poATL->Tri[iTri].Visited = false;
        poATL->Tri[iTri].iNumNeighs = 0;
        poATL->Tri[iTri].Neigh = NULL;

        // Vertex 0
        iA = _poMesh->m_pusIdx[iTri * 3 + 0];
        iB = _poMesh->m_pusIdx[iTri * 3 + 1];
        AddEdgeNeighs(_poMesh,poATL,iTri,iA,iB);

        // Vertex 1
        iA = _poMesh->m_pusIdx[iTri * 3 + 1];
        iB = _poMesh->m_pusIdx[iTri * 3 + 2];
        AddEdgeNeighs(_poMesh,poATL,iTri,iA,iB);

        // Vertex 2
        iA = _poMesh->m_pusIdx[iTri * 3 + 2];
        iB = _poMesh->m_pusIdx[iTri * 3 + 0];
        AddEdgeNeighs(_poMesh,poATL,iTri,iA,iB);
    }

    return(poATL);
}

void SCNUt_AdjTriListBuilder::AddEdgeNeighs (CGMesh* _poMesh, SCNUt_AdjTriList* _poATL, int _iTri, int _iA, int _iB)
{
    int iTri;
    int iA,iB;

    for ( iTri = 0; iTri < _poMesh->uiGetNumPrims(); iTri++ )
    {
        if ( iTri != _iTri )
        {
            // Vertex 0
            iA = _poMesh->m_pusIdx[iTri * 3 + 0];
            iB = _poMesh->m_pusIdx[iTri * 3 + 1];
            if ( ( (iA == _iA) && (iB == _iB) ) || ( (iA == _iB) && (iB == _iA) ) )
                _poATL->Tri[_iTri].AddNeigh(iTri);

            // Vertex 1
            iA = _poMesh->m_pusIdx[iTri * 3 + 1];
            iB = _poMesh->m_pusIdx[iTri * 3 + 2];
            if ( ( (iA == _iA) && (iB == _iB) ) || ( (iA == _iB) && (iB == _iA) ) )
                _poATL->Tri[_iTri].AddNeigh(iTri);

            // Vertex 2
            iA = _poMesh->m_pusIdx[iTri * 3 + 2];
            iB = _poMesh->m_pusIdx[iTri * 3 + 0];
            if ( ( (iA == _iA) && (iB == _iB) ) || ( (iA == _iB) && (iB == _iA) ) )
                _poATL->Tri[_iTri].AddNeigh(iTri);
        }
    }
}

// Additional Declarations
