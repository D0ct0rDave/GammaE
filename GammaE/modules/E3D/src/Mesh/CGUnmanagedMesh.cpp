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
void CGUnmanagedMesh::SetNumVXs(uint _uiNumVXs)
{
    m_uiNumVXs = _uiNumVXs;
}
// ----------------------------------------------------------------------------
void CGUnmanagedMesh::SetNumPrims(uint _uiNumPrims)
{
    m_uiNumPrims = _uiNumPrims;
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
