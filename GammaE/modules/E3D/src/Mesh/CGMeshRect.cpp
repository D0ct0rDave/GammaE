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
#include "Mesh\CGMeshRect.h"
// ----------------------------------------------------------------------------
CGMeshRect::CGMeshRect()
{
    CGMesh::Init(4,1,E3D_PT_NIQUADS,MESH_FIELD_ALL);

    // Setup vertex data
    m_poVX[0].Set(-1, 1, 0);
    m_poVX[1].Set( 1, 1, 0);
    m_poVX[2].Set( 1,-1, 0);
    m_poVX[3].Set(-1,-1, 0);

    // Setup Normal data
    m_poVN[0].Set(-1,-1, 0);
    m_poVN[1].Set(-1, 1, 0);
    m_poVN[2].Set( 1, 1, 0);
    m_poVN[3].Set( 1,-1, 0);
    for ( uint cNorm = 0; cNorm < m_uiNumVXs; cNorm++ ) m_poVN[cNorm].Normalize();

    // Setup color data
    m_poVC[0].Set(1,1,1,1);
    m_poVC[1].Set(1,1,1,1);
    m_poVC[2].Set(1,1,1,1);
    m_poVC[3].Set(1,1,1,1);

    // Setup UV data
    m_poUV[0].Set(0,1);
    m_poUV[1].Set(1,1);
    m_poUV[2].Set(1,0);
    m_poUV[3].Set(0,0);
}
// ----------------------------------------------------------------------------
CGMeshRect::~CGMeshRect()
{
}
// ----------------------------------------------------------------------------
