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
#include "Mesh\CGMeshBox.h"

// ----------------------------------------------------------------------------
CGMeshBox::CGMeshBox()
{
    CGMesh::Init(8,12,E3D_PT_TRIS,MESH_FIELD_ALL);

    // Setup vertex data
    m_poVX[0].Set(-1,-1, 1);
    m_poVX[1].Set(-1, 1, 1);
    m_poVX[2].Set( 1, 1, 1);
    m_poVX[3].Set( 1,-1, 1);
    m_poVX[4].Set(-1,-1,-1);
    m_poVX[5].Set(-1, 1,-1);
    m_poVX[6].Set( 1, 1,-1);
    m_poVX[7].Set( 1,-1,-1);

    // Setup Normal data
    m_poVN[0].Set(-1,-1, 1);
    m_poVN[1].Set(-1, 1, 1);
    m_poVN[2].Set( 1, 1, 1);
    m_poVN[3].Set( 1,-1, 1);
    m_poVN[4].Set(-1,-1,-1);
    m_poVN[5].Set(-1, 1,-1);
    m_poVN[6].Set( 1, 1,-1);
    m_poVN[7].Set( 1,-1,-1);

    // Setup colors
    m_poVC[0].Set(1,1,1,1);
    m_poVC[1].Set(1,1,1,1);
    m_poVC[2].Set(1,1,1,1);
    m_poVC[3].Set(1,1,1,1);
    m_poVC[4].Set(1,1,1,1);
    m_poVC[5].Set(1,1,1,1);
    m_poVC[6].Set(1,1,1,1);
    m_poVC[7].Set(1,1,1,1);

    for ( uint cNorm = 0; cNorm < m_uiNumVXs; cNorm++ ) m_poVN[cNorm].Normalize();

    // Setup UV data
    m_poUV[ 0].Set(1,0);
    m_poUV[ 1].Set(1,1);
    m_poUV[ 2].Set(0,1);
    m_poUV[ 3].Set(0,0);
    m_poUV[ 4].Set(1,0);
    m_poUV[ 5].Set(1,1);
    m_poUV[ 6].Set(0,1);
    m_poUV[ 7].Set(0,0);

    // Setup triangle data

    // Cara posterior
    m_pusIdx[ 0 * 3 + 0] = 1;
    m_pusIdx[ 0 * 3 + 1] = 0;
    m_pusIdx[ 0 * 3 + 2] = 3;
    m_pusIdx[ 1 * 3 + 0] = 1;
    m_pusIdx[ 1 * 3 + 1] = 3;
    m_pusIdx[ 1 * 3 + 2] = 2;

    // Cara anterior
    m_pusIdx[ 2 * 3 + 0] = 6;
    m_pusIdx[ 2 * 3 + 1] = 7;
    m_pusIdx[ 2 * 3 + 2] = 4;
    m_pusIdx[ 3 * 3 + 0] = 6;
    m_pusIdx[ 3 * 3 + 1] = 4;
    m_pusIdx[ 3 * 3 + 2] = 5;

    // Cara derecha
    m_pusIdx[ 4 * 3 + 0] = 2;
    m_pusIdx[ 4 * 3 + 1] = 3;
    m_pusIdx[ 4 * 3 + 2] = 7;
    m_pusIdx[ 5 * 3 + 0] = 2;
    m_pusIdx[ 5 * 3 + 1] = 7;
    m_pusIdx[ 5 * 3 + 2] = 6;

    // Cara izquierda
    m_pusIdx[ 6 * 3 + 0] = 5;
    m_pusIdx[ 6 * 3 + 1] = 4;
    m_pusIdx[ 6 * 3 + 2] = 0;
    m_pusIdx[ 7 * 3 + 0] = 5;
    m_pusIdx[ 7 * 3 + 1] = 0;
    m_pusIdx[ 7 * 3 + 2] = 1;

    // Cara superior
    m_pusIdx[ 8 * 3 + 0] = 5;
    m_pusIdx[ 8 * 3 + 1] = 1;
    m_pusIdx[ 8 * 3 + 2] = 2;
    m_pusIdx[ 9 * 3 + 0] = 5;
    m_pusIdx[ 9 * 3 + 1] = 5;
    m_pusIdx[ 9 * 3 + 2] = 6;

    // Cara inferior
    m_pusIdx[10 * 3 + 0] = 0;
    m_pusIdx[10 * 3 + 1] = 4;
    m_pusIdx[10 * 3 + 2] = 7;
    m_pusIdx[11 * 3 + 0] = 0;
    m_pusIdx[11 * 3 + 1] = 7;
    m_pusIdx[11 * 3 + 2] = 3;
}
// ----------------------------------------------------------------------------
CGMeshBox::~CGMeshBox()
{
}
// ----------------------------------------------------------------------------
