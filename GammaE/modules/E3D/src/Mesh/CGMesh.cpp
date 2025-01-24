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
#include "GammaE_Mem.h"
#include "Mesh\CGMesh.h"
// ----------------------------------------------------------------------------
CGMesh::CGMesh() :
    m_poVX(NULL),
    m_poUV(NULL),
    m_poVN(NULL),
    m_poVC(NULL),
    m_poTN(NULL),
    m_poUV2(NULL),
    m_pusIdx(NULL),
    m_uiNumIdxs(0)
{
    m_eMeshType = E3D_MT_Mesh;
}
// ----------------------------------------------------------------------------
CGMesh::~CGMesh()
{
    if ( m_poVX ) mDel[] m_poVX;
    if ( m_poUV ) mDel[] m_poUV;
    if ( m_poVN ) mDel[] m_poVN;
    if ( m_poVC ) mDel[] m_poVC;
    if ( m_poTN ) mDel[] m_poTN;
    if ( m_poUV2 ) mDel[] m_poUV2;

    if ( m_pusIdx ) mDel[] m_pusIdx;
    if ( m_poBV ) mDel m_poBV;
}
// ----------------------------------------------------------------------------
void CGMesh::Init(uint _uiNumVXs, uint _uiNumPrims, E3D_PrimitiveType _eMeshType, uint _uiFieldCreationMask)
{
    m_uiNumVXs = _uiNumVXs;
    m_uiNumPrims = _uiNumPrims;
    m_ePrimitiveType = _eMeshType;

    switch ( m_ePrimitiveType )
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

    if ( _uiFieldCreationMask & MESH_FIELD_VERTEXS ) m_poVX = mNew CGVect3[m_uiNumVXs];
    if ( _uiFieldCreationMask & MESH_FIELD_UVCOORDS ) m_poUV = mNew CGVect2[m_uiNumVXs];
    if ( _uiFieldCreationMask & MESH_FIELD_VNORMALS ) m_poVN = mNew CGVect3[m_uiNumVXs];
    if ( _uiFieldCreationMask & MESH_FIELD_COLORS ) m_poVC = mNew CGColor[m_uiNumVXs];
    if ( _uiFieldCreationMask & MESH_FIELD_INDEXES ) m_pusIdx = mNew unsigned short[m_uiNumIdxs];
    if ( _uiFieldCreationMask & MESH_FIELD_TNORMALS ) m_poTN = mNew CGVect3[uiGetNumPrims()];
    if ( _uiFieldCreationMask & MESH_FIELD_UVCOORD2 ) m_poUV2 = mNew CGVect2[m_uiNumVXs];
}
// ----------------------------------------------------------------------------
void CGMesh::ComputeBoundVol ()
{
// m_poBV->Compute(m_poVX,m_uiNumVXs);
}
// ----------------------------------------------------------------------------
/*
   CGVect3 CGMesh::oMeshCenter ()
   {
    unsigned short cV;
    CGVect3 Center = GetCenter();

    for (cV=0; cV<m_uiNumVXs; cV++) m_poVX[cV].Sub(Center);

    return(Center);
   }
 */
// ----------------------------------------------------------------------------
