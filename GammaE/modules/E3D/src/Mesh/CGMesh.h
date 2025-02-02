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
#ifndef CGMeshH
#define CGMeshH
// ----------------------------------------------------------------------------
#include "Materials/CGColor.h"
#include "E3D_Enums.h"
#include "GammaE_Math.h"
#include "CGBaseMesh.h"
// ----------------------------------------------------------------------------
// Mesh creation flags
// ----------------------------------------------------------------------------
#define MESH_FIELD_VERTEXS  0x00000001
#define MESH_FIELD_UVCOORDS 0x00000002
#define MESH_FIELD_VNORMALS 0x00000004
#define MESH_FIELD_COLORS   0x00000010
#define MESH_FIELD_INDEXES  0x00000020
#define MESH_FIELD_TNORMALS 0x00000040
#define MESH_FIELD_UVCOORD2 0x00000080
#define MESH_FIELD_ALL      0x0000003f
#define MESH_FIELD_MULTITEX 0x000000bf
#define MESH_FIELD_COMPLETE 0x000000ff

class CGMesh : public CGBaseMesh
{
    public:
        CGMesh();

        ~CGMesh();

        void Init(uint _uiNumVXs, uint _uiNumPrims, E3D_PrimitiveType _eMeshType, uint _uiFieldCreationMask);

        CGVect3* m_poVX;

        CGVect2* m_poUV;

        CGVect3* m_poVN;

        CGColor* m_poVC;

        CGVect3* m_poTN;

        CGVect2* m_poUV2;

        unsigned short* m_pusIdx;

};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
