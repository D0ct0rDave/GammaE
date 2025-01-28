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
#include "Mesh\CGUnmanagedMesh.h"
// ----------------------------------------------------------------------------
CGUnmanagedMesh::~CGUnmanagedMesh()
{
    m_poVX = NULL;
    m_poUV = NULL;
    m_poVN = NULL;
    m_poVC = NULL;
    m_poTN = NULL;
    m_poUV2 = NULL;
    m_pusIdx = NULL;
}
// ----------------------------------------------------------------------------
void CGUnmanagedMesh::Link(CGMesh* _poMesh)
{
    m_poVX = _poMesh->m_poVX;
    m_poUV = _poMesh->m_poUV;
    m_poVC = _poMesh->m_poVC;
    m_poVN = _poMesh->m_poVN;
    m_pusIdx = _poMesh->m_pusIdx;
    m_poTN = _poMesh->m_poTN;
    m_poUV2 = _poMesh->m_poUV2;

    m_uiNumVXs = _poMesh->uiGetNumVXs();
    m_uiNumPrims = _poMesh->uiGetNumPrims();
    m_uiNumIdxs = _poMesh->uiGetNumIndices();

    m_uiMaxVXs = _poMesh->uiGetNumVXs();
    m_uiMaxPrims = _poMesh->uiGetNumPrims();

    m_ePrimitiveType = _poMesh->eGetPrimitiveType();
    m_eMeshType = _poMesh->eGetType();

    m_poBV = _poMesh->poGetBV();
}
// ----------------------------------------------------------------------------
void CGUnmanagedMesh::SetNumVXs(uint _uiNumVXs)
{
    if (m_uiNumVXs < m_uiMaxVXs)
    {
        m_uiNumVXs = _uiNumVXs;
    }
    m_uiNumVXs = _uiNumVXs;
}
// ----------------------------------------------------------------------------
void CGUnmanagedMesh::SetNumPrims(uint _uiNumPrims)
{
    if (_uiNumPrims < m_uiMaxPrims)
    {
        m_uiNumPrims = _uiNumPrims;
    }

    ComputeNumberOfIndices();
}
// ----------------------------------------------------------------------------
void CGUnmanagedMesh::SetPrimitiveType(E3D_PrimitiveType _eMeshType)
{
    m_ePrimitiveType = _eMeshType;
    ComputeNumberOfIndices();
}
// ----------------------------------------------------------------------------
void CGUnmanagedMesh::ComputeNumberOfIndices()
{
    switch (m_ePrimitiveType)
    {
    case E3D_PT_NONE:       m_uiNumIdxs = 0;
        break;

    case E3D_PT_TRIS:       m_uiNumIdxs = uiGetNumPrims() * 3;
        break;

    case E3D_PT_QUADS:      m_uiNumIdxs = uiGetNumPrims() * 4;
        break;

    case E3D_PT_TRIFANS:    m_uiNumIdxs = uiGetNumPrims() + 2;
        break;

    case E3D_PT_TRISTRIPS:  m_uiNumIdxs = uiGetNumPrims() + 2;
        break;

    case E3D_PT_QUADSTRIPS: m_uiNumIdxs = uiGetNumPrims() + 3;
        break;

    case E3D_PT_NITRIS:     m_uiNumIdxs = 0;
        break;

    case E3D_PT_NIQUADS:    m_uiNumIdxs = 0;
        break;

    case E3D_PT_NITRISTRIP: m_uiNumIdxs = 0;
        break;
    }
}
// ----------------------------------------------------------------------------