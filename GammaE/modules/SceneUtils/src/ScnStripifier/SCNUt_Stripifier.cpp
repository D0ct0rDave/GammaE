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

// SCNUt_Stripifier
#include "ScnStripifier\SCNUt_Stripifier.h"

// Class SCNUt_Stripifier

SCNUt_Stripifier::SCNUt_Stripifier()
{
}

SCNUt_Stripifier::~SCNUt_Stripifier()
{
}

CGMesh* SCNUt_Stripifier::poStripifyMesh (CGMesh* _poMesh)
{
    if ( !_poMesh ) return(NULL);

    /*
       SCNUt_EdgeBuilder		oEB;
       SCNUt_EdgeList			*poEList;
       poEList = oEB.poBuild(_poMesh,poOMesh);
     */

    CGMesh* poOMesh;
    CGMesh* poFMesh;
    SCNUt_AdjTriListBuilder oATLBuilder;
    SCNUt_AdjTriList* poATL;

    poATL = oATLBuilder.poBuild(_poMesh,poOMesh);
    poFMesh = poStripify(poOMesh,poATL);

    // Delete auxiliary mesh
    mDel poOMesh;

    // Delete Adjacent Triangle List
    mDel poATL;

    // Return result mesh
    return(poFMesh);
}

CGMesh* SCNUt_Stripifier::poStripifyTriScene (SCNUt_TriScene* _poTS)
{
    return(NULL);
}

CGMesh* SCNUt_Stripifier::poStripify (CGMesh* _poMesh, SCNUt_AdjTriList* _poATL)
{
    CGMesh* PMesh;
    int iNumTris;
    int iCurrentTri;
    int iNeigh;
    int iNeighTri;
    int iStripIdx;
    int iNumStrips;
    int iNeighVX;

    // Create a mesh only to store strip indexes
    PMesh = mNew CGMesh;
    PMesh->Init(0,_poMesh->m_uiNumPrims * 5,E3D_MESH_TRISTRIPS,MESH_FIELD_INDEXES);

    // Initialize counters
    iNumStrips = 0;
    iStripIdx = 0;
    iNumTris = _poMesh->m_uiNumPrims;

    while ( iNumTris )
    {
        // Select the starting triangle
        iCurrentTri = iSelectStartingTri(_poATL);
        if ( iCurrentTri == -1 )
            return(PMesh);

        // Linking with previous strips???
        if ( iStripIdx > 0 )
            PMesh->m_pusIdx[iStripIdx++] = _poMesh->m_pusIdx[ iCurrentTri * 3 + 0];                     // repeat first strip index

        // setup strip vertexs
        PMesh->m_pusIdx[ iStripIdx++ ] = _poMesh->m_pusIdx[ iCurrentTri * 3 + 0 ];
        PMesh->m_pusIdx[ iStripIdx++ ] = _poMesh->m_pusIdx[ iCurrentTri * 3 + 1 ];
        PMesh->m_pusIdx[ iStripIdx++ ] = _poMesh->m_pusIdx[ iCurrentTri * 3 + 2 ];

        // This triangle has been visited
        _poATL->Tri[iCurrentTri].Visited = true;
        iNumTris--;

        // ---------------------------------------------------------------------
        // BEGIN: Generate a full strip
        // ---------------------------------------------------------------------

        // Select direction
        // iCurrentTri = -1; // Force 1 strip per triangle
        while ( iCurrentTri != -1 )
        {
            iNeigh = iSelectBestNeigh(_poATL,iCurrentTri);

            if ( iNeigh != -1 )
            {
                // Get the neighbour triangle
                iNeighTri = _poATL->Tri[iCurrentTri].Neigh[iNeigh];
                iNeighVX = iGetNonCommonVertex (_poMesh,iCurrentTri,iNeighTri);

                if ( iNeighVX != -1 )
                    PMesh->m_pusIdx[iStripIdx++] = _poMesh->m_pusIdx[ iNeighTri * 3 + iNeighVX ];
                else
                    iNeighVX = 0;

                // This triangle has been visited
                _poATL->Tri[iNeighTri].Visited = true;
                iCurrentTri = iNeighTri;
                iNumTris--;
            }
            else
                iCurrentTri = -1;
        }

        iNumStrips++;
        // ---------------------------------------------------------------------
        // END: Generate a full strip
        // ---------------------------------------------------------------------

        // Are there more strips?
        if ( iNumTris )
        {
            PMesh->m_pusIdx[iStripIdx] = PMesh->m_pusIdx[iStripIdx - 1];                    // repeat last strip index
            iStripIdx++;
        }
    }

    // ---------------------------------------------------------------------
    // Generate the final mesh
    // ---------------------------------------------------------------------
    CGMesh* poResMesh;
    int iIdx;

    poResMesh = mNew CGMesh;
    poResMesh->Init(_poMesh->m_usNumVXs,iStripIdx - 2,E3D_MESH_TRISTRIPS,MESH_FIELD_ALL);

    memcpy( poResMesh->m_poVX,_poMesh->m_poVX,_poMesh->m_usNumVXs * sizeof(CVect3) );
    memcpy( poResMesh->m_poVN,_poMesh->m_poVN,_poMesh->m_usNumVXs * sizeof(CVect3) );
    memcpy( poResMesh->m_poVC,_poMesh->m_poVC,_poMesh->m_usNumVXs * sizeof(CVect4) );
    memcpy( poResMesh->m_poUV,_poMesh->m_poUV,_poMesh->m_usNumVXs * sizeof(CVect2) );
    memcpy( poResMesh->m_pusIdx,PMesh->m_pusIdx,iStripIdx * sizeof(short) );
    poResMesh->ComputeBoundVol();

    // Free auxiliary mesh
    mDel PMesh;

    return (poResMesh);
}

int SCNUt_Stripifier::iSelectStartingTri (SCNUt_AdjTriList* _poATL)
{
    int iTri;
    int iMaxNeighs;
    int iSelTri;

    int iDstNeighs;
    int iDNeigh;
    int iDTriNeigh;

    iMaxNeighs = 0;
    iSelTri = -1;
    for ( iTri = 0; iTri < _poATL->iNumTris; iTri++ )
    {
        if ( !_poATL->Tri[iTri].Visited )
        {
            // count the number of visitable neighbours from this triangle
            iDstNeighs = 0;
            for ( iDNeigh = 0; iDNeigh < _poATL->Tri[iTri].iNumNeighs; iDNeigh++ )
            {
                iDTriNeigh = _poATL->Tri[iTri].Neigh[iDNeigh];
                if ( !_poATL->Tri[iDTriNeigh].Visited ) iDstNeighs++;
            }

            // Update best neighbour
            if ( iDstNeighs >= iMaxNeighs )
            {
                iSelTri = iTri;
                iMaxNeighs = iDstNeighs;
            }
        }
    }

    return (iSelTri);
}

int SCNUt_Stripifier::iSelectBestNeigh (SCNUt_AdjTriList* _poATL, int _iSrcTri)
{
    // This function returns the best neighbour for a given source triangle
    // The best neighbour is the triangle neighbour that has the most visitable
    // neighbours

    int iNeigh;
    int iBestNeigh;
    int iMaxNeighs;
    int iTriNeigh;

    int iDstNeighs;
    int iDNeigh;
    int iDTriNeigh;

    iBestNeigh = -1;
    iMaxNeighs = 0;

    for ( iNeigh = 0; iNeigh < _poATL->Tri[_iSrcTri].iNumNeighs; iNeigh++ )
    {
        // Get the destination triangle neighbour
        iTriNeigh = _poATL->Tri[_iSrcTri].Neigh[iNeigh];

        // If this neighbourg has not been visited previously
        if ( !_poATL->Tri[iTriNeigh].Visited )
        {
            // count the number of visitable neighbours from this neighbour
            iDstNeighs = 0;
            for ( iDNeigh = 0; iDNeigh < _poATL->Tri[iTriNeigh].iNumNeighs; iDNeigh++ )
            {
                iDTriNeigh = _poATL->Tri[iTriNeigh].Neigh[iDNeigh];
                if ( !_poATL->Tri[iDTriNeigh].Visited ) iDstNeighs++;
            }

            // Update best neighbour
            if ( iDstNeighs >= iMaxNeighs )
            {
                iBestNeigh = iNeigh;
                iMaxNeighs = iDstNeighs;
            }
        }
    }

    return(iBestNeigh);
}

int SCNUt_Stripifier::iGetNonCommonVertex (CGMesh* _SrCGMesh, int _iSrcTri, int _iDstTri)
{
    int cI;

    for ( cI = 0; cI < 3; cI++ )
    {
        if (
            (_SrCGMesh->m_pusIdx[_iDstTri * 3 + cI] != _SrCGMesh->m_pusIdx[_iSrcTri * 3 + 0]) &&
            (_SrCGMesh->m_pusIdx[_iDstTri * 3 + cI] != _SrCGMesh->m_pusIdx[_iSrcTri * 3 + 1]) &&
            (_SrCGMesh->m_pusIdx[_iDstTri * 3 + cI] != _SrCGMesh->m_pusIdx[_iSrcTri * 3 + 2])
            )

            return (cI);
    }

    return (-1);
}

// Additional Declarations
