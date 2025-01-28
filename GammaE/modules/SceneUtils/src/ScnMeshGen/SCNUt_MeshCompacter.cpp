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
// ----------------------------------------------------------------------------
// SCNUt_MeshCompacter
#include "ScnMeshGen\SCNUt_MeshCompacter.h"
#include <stdlib.h>
#include <string.h>
// ----------------------------------------------------------------------------
// Class SCNUt_MeshCompacter
SCNUt_MeshCompacter::SCNUt_MeshCompacter()
{
}
// ----------------------------------------------------------------------------
SCNUt_MeshCompacter::~SCNUt_MeshCompacter()
{
}
// ----------------------------------------------------------------------------
CGMesh* SCNUt_MeshCompacter::poCompactMesh(const SCNUt_TriScene& _oScene)
{
    CCompactMeshData oCompactData;
    CompactMesh(_oScene,&oCompactData);

    oCompactData.m_oInvTable.Clear();
    return (oCompactData.m_poMesh);
}
// ----------------------------------------------------------------------------
void SCNUt_MeshCompacter::CompactMesh(const SCNUt_TriScene& _oScene,CCompactMeshData* _poData)
{
    int cIdx,cTri,cVert;
    int iOldNumVertexs;

    // ----------------------------------
    // Create an auxiliary mesh
    // ----------------------------------
    CGMesh* m_poGeometryMesh = mNew CGMesh();
    m_poGeometryMesh->Init(_oScene.NumTris * 3,_oScene.NumTris, E3D_PrimitiveType::E3D_PT_TRIS,MESH_FIELD_ALL);
    
    CGUnmanagedMesh* poAuxMesh = mNew CGUnmanagedMesh();
    poAuxMesh->Link(m_poGeometryMesh);

    // ----------------------------------
    // Generate the new compact mesh
    // ----------------------------------
    unsigned short usOldNumVertexs = poAuxMesh->uiGetNumVXs();
    poAuxMesh->SetNumVXs(0);

    unsigned short* usIdx = poAuxMesh->m_pusIdx;
    unsigned short usCurIdx = 0;

    for ( cTri = 0; cTri < _oScene.NumTris; cTri++ )
    {
        for ( cVert = 0; cVert < 3; cVert++ )
        {
            uint uiPreviousNumVertices = poAuxMesh->uiGetNumVXs();

            *usIdx = uiInsertVertex(poAuxMesh,
                                    _oScene.Tris[cTri].VXs[cVert],
                                    _oScene.Tris[cTri].UVs[cVert],
                                    _oScene.Tris[cTri].VCs[cVert],
                                    _oScene.Tris[cTri].VNs[cVert]);

            // In case a new vertex has been inserted, add the original index to the inverse table
            if (uiPreviousNumVertices != poAuxMesh->uiGetNumVXs() )
            {
                TVertexRef oVR;
                oVR.m_uiTri = cTri;
                oVR.m_uiVX = cVert;

                _poData->m_oInvTable.uiAdd(oVR);
            }

            usIdx++;
            usCurIdx++;
        }
    }

    // ----------------------------------
    // Create and Setup the reduced mesh
    // ----------------------------------
    CGMesh* Mesh = mNew CGMesh();
    Mesh->Init(poAuxMesh->uiGetNumVXs(),_oScene.NumTris,E3D_PrimitiveType::E3D_PT_TRIS,MESH_FIELD_ALL);

    // Copy data
    memcpy( Mesh->m_poVX,poAuxMesh->m_poVX,poAuxMesh->uiGetNumVXs() * sizeof(CGVect3) );
    memcpy( Mesh->m_poUV,poAuxMesh->m_poUV,poAuxMesh->uiGetNumVXs() * sizeof(CGVect2) );
    memcpy( Mesh->m_poVC,poAuxMesh->m_poVC,poAuxMesh->uiGetNumVXs() * sizeof(CGVect4) );
    memcpy( Mesh->m_poVN,poAuxMesh->m_poVN,poAuxMesh->uiGetNumVXs() * sizeof(CGVect3) );
    memcpy( Mesh->m_pusIdx,poAuxMesh->m_pusIdx,poAuxMesh->uiGetNumIndices() * sizeof(unsigned short) );

    mDel poAuxMesh;
    mDel m_poGeometryMesh;
    // ----------------------------------
    _poData->m_poMesh = Mesh;
}
// ----------------------------------------------------------------------------
uint SCNUt_MeshCompacter::uiInsertVertex(CGUnmanagedMesh* Mesh, CGVect3 &VX, CGVect2& UV, CGVect4 &VC, CGVect3 &VN)
{
    // Search for the specified vertex tuplet <VX,VU>
    for ( uint i = 0; i < Mesh->uiGetNumVXs(); i++ )
    {
        if ( Mesh->m_poVX[i].bEqual(VX) && Mesh->m_poUV[i].bEqual(UV) )
            return(i);
    }

    Mesh->m_poVX[Mesh->uiGetNumVXs()] = VX;
    Mesh->m_poUV[Mesh->uiGetNumVXs()] = UV;
    Mesh->m_poVC[Mesh->uiGetNumVXs()] = (CGColor &)VC;
    Mesh->m_poVN[Mesh->uiGetNumVXs()] = VN;
    Mesh->SetNumVXs(Mesh->uiGetNumVXs() + 1);

    return(Mesh->uiGetNumVXs() - 1);
}
// ----------------------------------------------------------------------------
