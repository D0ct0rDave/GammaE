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
#include "GammaE_Mem.h"

// SCNUt_MeshGenerator
#include "ScnMeshGen\SCNUt_MeshGenerator.h"

// Class SCNUt_MeshGenerator

SCNUt_MeshGenerator::SCNUt_MeshGenerator()
{
}

SCNUt_MeshGenerator::~SCNUt_MeshGenerator()
{
}

CGMesh* SCNUt_MeshGenerator::GenerateMesh (SCNUt_TriScene &Scene)
{
    CGMesh* Mesh;
    int cTri,cVert;
    unsigned short usIdx;

    // -----------------------------------------------------------------------------
    // Create a mesh
    // ----------------------------------
    Mesh = mNew CGMesh();
    Mesh->Init(Scene.NumTris * 3,Scene.NumTris,E3D_PrimitiveType::E3D_PT_NITRIS,MESH_FIELD_ALL);

    // ----------------------------------
    // Generate the new mesh
    // ----------------------------------

    usIdx = 0;
    for ( cTri = 0; cTri < Scene.NumTris; cTri++ )
    {
        for ( cVert = 0; cVert < 3; cVert++ )
        {
            Mesh->m_poVX[usIdx] = Scene.Tris[cTri].VXs[cVert];
            Mesh->m_poUV[usIdx] = Scene.Tris[cTri].UVs[cVert];
            Mesh->m_poVC[usIdx] = *(CGColor*)&Scene.Tris[cTri].VCs[cVert];
            Mesh->m_poVN[usIdx] = Scene.Tris[cTri].VNs[cVert];

            usIdx++;
        }
    }

    return(Mesh);
}

// Additional Declarations
