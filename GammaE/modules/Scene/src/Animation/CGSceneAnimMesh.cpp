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
    for (uint uiState = 0; uiState < m_poStateBVs.uiNumElems(); uiState++)
    {
        delete m_poStateBVs[uiState];
    }
    m_poStateBVs.Clear();

    if ( m_poFrameVXs ) mDel [] m_poFrameVXs;
    if ( m_poFrameVNs ) mDel [] m_poFrameVNs;
}
// --------------------------------------------------------------------------------
void CGSceneAnimMesh::Setup(CGMesh* _poStartupMesh, uint _uiNumStates, uint _uiNumVerticesPerState)
{
    m_poMesh = _poStartupMesh;

    m_poFrameVXs = mNew CGVect3[_uiNumStates * _uiNumVerticesPerState];
    m_poFrameVNs = mNew CGVect3[_uiNumStates * _uiNumVerticesPerState];
    m_uiNumStates = _uiNumStates;
    m_uiNumVerticesPerState = _uiNumVerticesPerState;

    m_poStateBVs.Init(_uiNumStates);
    for (uint uiState = 0; uiState < _uiNumStates; uiState++)
    {
        m_poStateBVs[uiState] = CGGraphBVFactory::poCreate();
    }
}
// --------------------------------------------------------------------------------
uint CGSceneAnimMesh::uiGetNumStates() const
{
    return(m_uiNumStates);
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
CGVect3* CGSceneAnimMesh::poGetVertices()
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
    assert (m_poFrameVXs && "NULL Mesh state vertex array");
    assert (m_poFrameVNs && "NULL Mesh state normal array");
    // assert (Leaf && "NULL Leaf Mesh");

    CGGraphBV* poBV = NULL;
    if (m_uiNumStates == 1 )
    {
        memcpy(m_poMesh->m_poVX, m_poFrameVXs, m_uiNumVerticesPerState * sizeof(CGVect3) );
        memcpy(m_poMesh->m_poVN, m_poFrameVNs, m_uiNumVerticesPerState * sizeof(CGVect3) );

        poBV = m_poStateBVs[0];
    }
    else
    {
        if (_uiSrc >= m_uiNumStates) _uiSrc = m_uiNumStates - 1;
        if (_uiDst >= m_uiNumStates) _uiDst = m_uiNumStates - 1;
        if ( _fFactor == 1.0f ) _uiSrc = _uiDst;                     // Optimization

        if ( (_uiSrc != _uiDst) && (_fFactor > 0.0f) )
        {
            CGVect3* pSrcVX = m_poFrameVXs + m_uiNumVerticesPerState * _uiSrc;
            CGVect3* pDstVX = m_poFrameVXs + m_uiNumVerticesPerState * _uiDst;
            CGVect3* pMeshVX = m_poMesh->m_poVX;
            for (uint cVert = 0; cVert < m_uiNumVerticesPerState; cVert++ )
            {
                pMeshVX->Interpolate(*pSrcVX, *pDstVX,_fFactor);

                pSrcVX++;
                pDstVX++;
                pMeshVX++;
            }

            #if 0
            // Interpolate normals too ? It does not look so worth ...
            CGVect3			*pSrcVN  = pNMeshStates + iNumStateVXs*_iSrc;
            CGVect3			*pDstVN  = pNMeshStates + iNumStateVXs*_iDst;
            CGVect3			*pMeshVN = Leaf->poGetMesh()->VNs;
            for (uint cVert = 0; cVert < m_uiNumVerticesPerState; cVert++ )
            {
                pMeshVN->Interpolate(*pSrcVN,*pDstVN,_fFactor);

                pSrcVN ++;
                pDstVN ++;
                pMeshVN++;
            }
            #else
            memcpy(m_poMesh->m_poVN, m_poFrameVNs + m_uiNumVerticesPerState * _uiSrc, m_uiNumVerticesPerState * sizeof(CGVect3) );
            #endif

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

        poBV = m_poStateBVs[_uiSrc];
    }

    m_poMesh->poGetBV()->Copy(*poBV);
}
// --------------------------------------------------------------------------------
void CGSceneAnimMesh::ComputeStatesBVols()
{
    for (uint uiState = 0; uiState < m_poStateBVs.uiNumElems(); uiState++)
        m_poStateBVs[uiState]->Compute(m_poFrameVXs + (uiState * m_uiNumVerticesPerState), m_uiNumVerticesPerState);

    m_poMesh->poGetBV()->Copy(*m_poStateBVs[0]);
}
// --------------------------------------------------------------------------------
CGGraphBV* CGSceneAnimMesh::poGetStateBVol(int _iState)
{
    return m_poStateBVs[_iState];
}
// --------------------------------------------------------------------------------
void CGSceneAnimMesh::SetShader(CGShader* _poShader)
{
    m_poShader = _poShader;
}
// --------------------------------------------------------------------------------
CGShader* CGSceneAnimMesh::poGetShader()
{
    return(m_poShader);
}
// --------------------------------------------------------------------------------
CGGraphBV* CGSceneAnimMesh::poGetBV()
{
    return(m_poMesh->poGetBV());
}
// --------------------------------------------------------------------------------
