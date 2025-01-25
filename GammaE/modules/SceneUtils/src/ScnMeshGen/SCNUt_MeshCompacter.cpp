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
    CGMesh* Mesh;
    CGMesh* AuxMesh;

    int cIdx,cTri,cVert;
    int iOldNumVertexs;

    // ----------------------------------
    // Create an auxiliary mesh
    // ----------------------------------
    AuxMesh = mNew CGMesh();
    AuxMesh->Init(_oScene.NumTris * 3,_oScene.NumTris,E3D_MESH_TRIS,MESH_FIELD_ALL);

    // ----------------------------------
    // Generate the new compact mesh
    // ----------------------------------
    unsigned short usOldNumVertexs = AuxMesh->m_usNumVXs;
    AuxMesh->m_usNumVXs = 0;

    unsigned short* usIdx = AuxMesh->m_pusIdx;
    unsigned short usCurIdx = 0;

    for ( cTri = 0; cTri < _oScene.NumTris; cTri++ )
    {
        for ( cVert = 0; cVert < 3; cVert++ )
        {
            uint uiOldNumVertexs = AuxMesh->m_usNumVXs;

            *usIdx = uiInsertVertex(AuxMesh,
                                    _oScene.Tris[cTri].VXs[cVert],
                                    _oScene.Tris[cTri].UVs[cVert],
                                    _oScene.Tris[cTri].VCs[cVert],
                                    _oScene.Tris[cTri].VNs[cVert]);

            // In case a new vertex has been inserted, add the original index to the inverse table
            if ( uiOldNumVertexs != AuxMesh->m_usNumVXs )
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
    Mesh = mNew CGMesh();
    Mesh->Init(AuxMesh->m_usNumVXs,_oScene.NumTris,E3D_MESH_TRIS,MESH_FIELD_ALL);

    // Copy data
    memcpy( Mesh->m_poVX,AuxMesh->m_poVX,AuxMesh->m_usNumVXs * sizeof(CGVect3) );
    memcpy( Mesh->m_poUV,AuxMesh->m_poUV,AuxMesh->m_usNumVXs * sizeof(CGVect2) );
    memcpy( Mesh->m_poVC,AuxMesh->m_poVC,AuxMesh->m_usNumVXs * sizeof(CGVect4) );
    memcpy( Mesh->m_poVN,AuxMesh->m_poVN,AuxMesh->m_usNumVXs * sizeof(CGVect3) );
    memcpy( Mesh->m_pusIdx,AuxMesh->m_pusIdx,AuxMesh->m_uiNumIdxs * sizeof(unsigned short) );

    AuxMesh->m_usNumVXs = usOldNumVertexs;
    mDel AuxMesh;

    // ----------------------------------
    _poData->m_poMesh = Mesh;
}
// ----------------------------------------------------------------------------
uint SCNUt_MeshCompacter::uiInsertVertex(CGMesh* Mesh, CGVect3 &VX, CGVect2& UV, CGVect4 &VC, CGVect3 &VN)
{
    // Search for the specified vertex tuplet <VX,VU>
    for ( uint i = 0; i < Mesh->m_usNumVXs; i++ )
    {
        if ( Mesh->m_poVX[i].bEqual(VX) && Mesh->m_poUV[i].bEqual(UV) )
            return(i);
    }

    Mesh->m_poVX[Mesh->m_usNumVXs] = VX;
    Mesh->m_poUV[Mesh->m_usNumVXs] = UV;
    Mesh->m_poVC[Mesh->m_usNumVXs] = (CGColor &)VC;
    Mesh->m_poVN[Mesh->m_usNumVXs] = VN;
    Mesh->m_usNumVXs++;

    return(Mesh->m_usNumVXs - 1);
}
// ----------------------------------------------------------------------------
