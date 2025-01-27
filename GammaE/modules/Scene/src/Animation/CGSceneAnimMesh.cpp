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
#include <string.h>

// CGSceneAnimMesh
#include "Animation\CGSceneAnimMesh.h"

// --------------------------------------------------------------------------------
CGSceneAnimMesh::CGSceneAnimMesh() :
    m_poFrameVXs(NULL),
    m_poFrameVNs(NULL),
    m_poMesh(NULL)
{
    m_eNodeType = SNT_AnimMesh;
}
// --------------------------------------------------------------------------------
CGSceneAnimMesh::~CGSceneAnimMesh()
{
    for (uint uiState = 0; uiState < m_poBVolStates.uiNumElems(); uiState++)
    {
        delete m_poBVolStates[uiState];
    }
    m_poBVolStates.Clear();

    if ( m_poFrameVXs ) mDel [] m_poFrameVXs;
    if ( m_poFrameVNs ) mDel [] m_poFrameVNs;
}
// --------------------------------------------------------------------------------
void CGSceneAnimMesh::Setup(CGMesh* _poStartupMesh, CGVect3* _poVXs, CGVect3* _poVNs, uint _uiNumStates, uint _uiNumVerticesPerState)
{
    m_poMesh = _poStartupMesh;
    m_poFrameVXs = _poVXs;
    m_poFrameVNs = _poVNs;
    m_uiNumStates = _uiNumStates;
    m_uiNumVerticesPerState = _uiNumVerticesPerState;

    m_poBVolStates.Init(_uiNumStates);
    for (uint uiState = 0; uiState < _uiNumStates; uiState++)
    {
        m_poBVolStates[uiState] = CGGraphBVFactory::poCreate();
    }
}
// --------------------------------------------------------------------------------
uint CGSceneAnimMesh::uiGetNumFrameVXs()
{
    return (m_poMesh->uiGetNumVXs());
}
// --------------------------------------------------------------------------------
CGMesh* CGSceneAnimMesh::poGetMesh()
{
    return(m_poMesh);
}
// --------------------------------------------------------------------------------
CGVect3* CGSceneAnimMesh::poGetVertexs()
{
    return (m_poFrameVXs);
}
// --------------------------------------------------------------------------------
CGVect3* CGSceneAnimMesh::poGetNormals()
{
    return (m_poFrameVNs);
}
// --------------------------------------------------------------------------------
void CGSceneAnimMesh::SetAnimState (uint _uiSrc, uint _uiDst, float _fFactor)
{
    assert (m_poFrameVXs && "NULL Mesh state array");
    // assert (Leaf && "NULL Leaf Mesh");

    if (m_uiNumStates == 1 )
    {
        memcpy(m_poMesh->m_poVX, m_poFrameVXs, m_uiNumVerticesPerState * sizeof(CGVect3) );
        memcpy(m_poMesh->m_poVN, m_poFrameVNs, m_uiNumVerticesPerState * sizeof(CGVect3) );

        m_poBV = m_poBVolStates[0];
    }
    else
    {
        if (_uiSrc >= m_uiNumStates) _uiSrc = m_uiNumStates - 1;
        if (_uiDst >= m_uiNumStates) _uiDst = m_uiNumStates - 1;
        if ( _fFactor == 1.0f ) _uiSrc = _uiDst;                     // Optimization

        if ( (_uiSrc != _uiDst) && (_fFactor > 0.0f) )
        {
            int cVert;
            CGVect3* pSrcVX = m_poFrameVXs + m_uiNumVerticesPerState * _uiSrc;
            CGVect3* pDstVX = m_poFrameVXs + m_uiNumVerticesPerState * _uiDst;
            CGVect3* pMeshVX = m_poMesh->m_poVX;
            for ( cVert = 0; cVert < m_uiNumVerticesPerState; cVert++ )
            {
                pMeshVX->Interpolate(*pSrcVX,*pDstVX,_fFactor);

                pSrcVX++;
                pDstVX++;
                pMeshVX++;
            }

            /*
               // Interpolate normals too ? It does not look so worth ...
               CGVect3			*pSrcVN  = pNMeshStates + iNumStateVXs*_iSrc;
               CGVect3			*pDstVN  = pNMeshStates + iNumStateVXs*_iDst;
               CGVect3			*pMeshVN = Leaf->poGetMesh()->VNs;
               for (cVert=0;cVert<iNumStateVXs;cVert++)
               {

                pMeshVN->Interpolate(*pSrcVN,*pDstVN,_fFactor);

                pSrcVN ++;
                pDstVN ++;
                pMeshVN++;
               }
             */
            memcpy(m_poMesh->m_poVN, m_poFrameVNs + m_uiNumVerticesPerState * _uiSrc, m_uiNumVerticesPerState * sizeof(CGVect3) );

            /*
            // Interpolate bounding volumes
            CGVect3 oSMax, oSMin, oDMax, oDMin, oMax, oMin;
            CGVect3 oSCen = pBVolStates[_uiSrc]->oGetCenter();
            CGVect3 oDCen = pBVolStates[_uiDst]->oGetCenter();
            CGVect3 oSExt = pBVolStates[_uiSrc]->GetExtents();
            CGVect3 oDExt = pBVolStates[_uiDst]->GetExtents();
            oSMax.Assign(oSCen);
            oSMax.Add(oSExt);
            oSMin.Assign(oSCen);
            oSMin.Sub(oSExt);
            oDMax.Assign(oDCen);
            oDMax.Add(oDExt);
            oDMin.Assign(oDCen);
            oDMin.Sub(oDExt);

            oMax.Interpolate(oSMax,oDMax,_fFactor);
            oMin.Interpolate(oSMin,oDMin,_fFactor);
            */
        }
        else
        {
            // Copy of the vertexs
            memcpy(m_poMesh->m_poVX, m_poFrameVXs + m_uiNumVerticesPerState * _uiSrc, m_uiNumVerticesPerState * sizeof(CGVect3) );

            // Copy of the normals
            memcpy(m_poMesh->m_poVN, m_poFrameVNs + m_uiNumVerticesPerState * _uiSrc, m_uiNumVerticesPerState * sizeof(CGVect3) );
        }

        m_poBV = m_poBVolStates[_uiSrc];
    }
    
    // m_poMesh->poGetBV().
    // Leaf->poGetMesh()->BVol->Copy(BVol);
}
// --------------------------------------------------------------------------------
void CGSceneAnimMesh::ComputeBoundVols()
{
    for (uint uiState = 0; uiState < m_poBVolStates.uiNumElems(); uiState++)
        m_poBVolStates[uiState]->Compute(m_poFrameVXs + (uiState * m_uiNumVerticesPerState), m_uiNumVerticesPerState);

    m_poBV = m_poBVolStates[0]; 
}
// --------------------------------------------------------------------------------
CGGraphBV* CGSceneAnimMesh::poGetStateBVol(int _iState)
{
    return m_poBVolStates[_iState];
}
// --------------------------------------------------------------------------------
