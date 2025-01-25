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

#include <stdio.h>
#include <string.h>
#include "GammaE_Mem.h"

// CLoaderBSP2
#include "3D_Loaders\BSP2Loader\CLoaderBSP2.h"

// Quake2 engine uses FRONT as cull face
#define _EVERSE_WINDING_

CLoaderBSP2::CLoaderBSP2()
    : pVXs(NULL), iNumVXs(0), pEdges(NULL), iNumEdges(0), pFaces(NULL), iNumFaces(0), pLFaces(NULL), iNumLFaces(0), pFEdges(NULL), iNumFEdges(0), pPlanes(NULL), iNumPlanes(0), pNodes(NULL), iNumNodes(0), pLeaves(NULL), iNumLeaves(0), pTexInfo(NULL), pExtTexInfo(NULL), iNumTexs(0), pVIS(NULL), iNumVis(0), poScnLeaves(NULL)
{
}

CLoaderBSP2::~CLoaderBSP2()
{
    if ( pVXs ) mDel [] pVXs;
    if ( pPlanes ) mDel [] pPlanes;
    if ( pNodes ) mDel [] pNodes;
    if ( pLeaves ) mDel [] pLeaves;
    if ( pLFaces ) mDel [] pLFaces;
    if ( pFaces ) mDel [] pFaces;
    if ( pEdges ) mDel [] pEdges;
    if ( pFEdges ) mDel [] pFEdges;
    if ( pTexInfo ) mDel [] pTexInfo;
    if ( pExtTexInfo ) mDel [] pExtTexInfo;
}

CGSceneNode* CLoaderBSP2::pLoad (char* Filename)
{
    FILE* fd;

    // open file
    fd = fopen(Filename,"rb");
    if ( !fd )
    {
        return (NULL);
    }

    // read header
    fread(&oBSPhdr, 1, sizeof(bsp_header), fd);

    if ( strncmp( (char*)&oBSPhdr.magic,"IBSP",4 ) || oBSPhdr.version != 38 )
    {
        fclose(fd);
        return (NULL);
    }

    // ----------------------------------------------------------------------------
    bsp_lump* pLump;

#define READ_LUMP(LumpID,uiNumElems,pBuffer,st_type)                \
                                                                    \
    pLump = &oBSPhdr.lump[ LumpID ];            \
    uiNumElems = pLump->lenght / sizeof(st_type);   \
    pBuffer = mNew st_type[uiNumElems];           \
                                                                    \
    fseek(fd,pLump->offset,SEEK_SET);               \
    fread(pBuffer,pLump->lenght,1,fd);

    // ----------------------------------------------------------------------------

    // read Vertex lump
    READ_LUMP(BSP_VERTEXS_LUMP,iNumVXs,pVXs,bsp_point3f);

    // read plane lump
    READ_LUMP(BSP_PLANES_LUMP,iNumPlanes,pPlanes,bsp_plane);

    // read nodes lump
    READ_LUMP(BSP_NODES_LUMP,iNumNodes,pNodes,bsp_node);

    // read leaves lump
    READ_LUMP(BSP_LEAVES_LUMP,iNumLeaves,pLeaves,bsp_leaf);

    // read leaf face table lump
    READ_LUMP(BSP_LFT_LUMP,iNumLFaces,pLFaces,bsp_leaf_face);

    // read faces lump
    READ_LUMP(BSP_FACES_LUMP,iNumFaces,pFaces,bsp_face);

    // read edges lump
    READ_LUMP(BSP_EDGES_LUMP,iNumEdges,pEdges,bsp_edge);

    // read face edge table lump
    READ_LUMP(BSP_FET_LUMP,iNumFEdges,pFEdges,bsp_face_edge);

    // read tex info lump
    READ_LUMP(BSP_TEXINFO_LUMP,iNumTexs,pTexInfo,bsp_texinfo);
    pExtTexInfo = mNew ext_texinfo[iNumTexs];
    SetExtendedTexInfo();

    CGSceneNode* poObj = poProcessBSP();

    fclose(fd);

    return (poObj);
}

void CLoaderBSP2::SetExtendedTexInfo ()
{
    char szMat[512];
    int iTex;

    for ( iTex = 0; iTex < iNumTexs; iTex++ )
    {
        sprintf(szMat,"%s/%s.wal",szQ2BaseDir,pTexInfo[ iTex ].texture_name);
        int iMipMap = CMipMapWH::I()->iLoad(szMat);

        if ( iMipMap > -1 )
        {
            CGMipMap* poMipMap = CMipMapWH::I()->poGet(iMipMap);

            pExtTexInfo[iTex].iWidth = poMipMap->m_uiTX;
            pExtTexInfo[iTex].iHeight = poMipMap->m_uiTY;
            pExtTexInfo[iTex].pBTI = &pTexInfo[iTex];

            CMipMapWH::I()->Del(iMipMap);
        }
    }
}

CGSceneNode* CLoaderBSP2::poProcessBSP ()
{
    CGSceneNode* poObj;

    poObj = poGenerateNode(&pNodes[0]);
    poObj->ComputeBoundVol();

    return (poObj);
}

CGSceneNode* CLoaderBSP2::poGenerateLeaf (bsp_leaf* _pLeaf)
{
    if ( !_pLeaf->num_leaf_faces ) return(NULL);

    SCNUt_TriSceneAccumulator oTScn;
    SCNUt_TriSceneSeparator oTSep;
    SCNUt_MeshGenerator oMGen;
    CE3D_Shader* poShader;

    int iFace;
    int iRealFace;
    char szMat[512];

    for ( iFace = 0; iFace < _pLeaf->num_leaf_faces; iFace++ )
    {
        iRealFace = pLFaces[_pLeaf->first_leaf_face + iFace].index;

        assert( ( (iRealFace >= 0) && (iRealFace < iNumFaces) ) &&
               "BSP face index out bounds" );

        AddFace(&pFaces[iRealFace],&oTScn);
    }

    // Now we have processed all the faces from this leaf node, convert q2 leaf into
    // a GammaE node
    CGSceneNode* poObj;
    oTSep.SeparateScene(oTScn);

    if ( oTSep.NumMeshes > 1 )
    {
        CGSceneGroup* poNode = mNew CGSceneGroup;
        CGSceneLeaf* poLeaf;
        CGMesh* poMesh;

        poNode->Init(oTSep.NumMeshes);

        for ( int iObj = 0; iObj < oTSep.NumMeshes; iObj++ )
        {
            sprintf(szMat,"%s/%s.wal",szQ2BaseDir,pTexInfo[ oTSep.piMatIdx[iObj] ].texture_name);

            poShader = CGShaderWH::I()->poCreateShader(szMat);

            poLeaf = mNew CGSceneLeaf;

            poMesh = oMGen.GenerateMesh(oTSep.Meshes[iObj]);
            poLeaf->SetMesh  (poMesh);
            poLeaf->SetShader(poShader);                    // que coño pasa con el material !!!!!

            poNode->iAddObject(poLeaf);
        }

        poObj = poNode;
    }
    else
    {
        sprintf(szMat,"%s/%s.wal",szQ2BaseDir,pTexInfo[ oTSep.piMatIdx[0] ].texture_name);

        CE3D_Shader* poShader = CGShaderWH::I()->poCreateShader(pTexInfo[ oTSep.piMatIdx[0] ].texture_name);

        CGSceneLeaf* poLeaf = mNew CGSceneLeaf;
        CGMesh* poMesh = oMGen.GenerateMesh(oTSep.Meshes[0]);

        poLeaf->SetMesh  (poMesh);
        poLeaf->SetShader(poShader);                    // que coño pasa con el material !!!!!

        poObj = poLeaf;
    }

    return (poObj);
}

CGSceneNode* CLoaderBSP2::poGenerateNode (bsp_node* _pNode)
{
    CGSceneBSPNode* poBSPNode = NULL;
    CGSceneNode* poBackScn = NULL;
    CGSceneNode* poFrontScn = NULL;
    CGSceneNode* poNodeScn = NULL;

    // Set the back node
    if ( _pNode->back_child >= 0 )
        // A node
        poBackScn = poGenerateNode(&pNodes[_pNode->back_child]);
    else
        // A Leaf
        poBackScn = poGenerateLeaf(&pLeaves[-1 * _pNode->back_child]);

    // Set the front node
    if ( _pNode->front_child >= 0 )
        // A node
        poFrontScn = poGenerateNode(&pNodes[_pNode->front_child]);
    else
        // A Leaf
        poFrontScn = poGenerateLeaf(&pLeaves[-1 * _pNode->front_child]);

    // DO NOT Load intermediate geometry (only leaf geometry)
    // poNodeScn = poGenerateNodeMesh(_pNode,_MatWH);

    if ( (!poBackScn) && (!poFrontScn) && (!poNodeScn) )
        return(NULL);                     // NULL Node ???

    if ( (poBackScn) || (poFrontScn) )
    {
        // Get the partition plane
        CGPlane oPlane;
        CGVect3 oOrigin;
        CGVect3 oPNormal;

        bsp_plane* pPlane = &pPlanes[ _pNode->plane ];
        oPNormal.Set(pPlane->normal.x,
                    pPlane->normal.y,
                    pPlane->normal.z);
        oOrigin.Assign(oPNormal);
        oOrigin.Scale (pPlane->distance);
        oPlane.GeneratePlaneFromFields(oOrigin,oPNormal);

        // Create & Setup BSP
        poBSPNode = mNew CGSceneBSPNode;
        poBSPNode->SetBackNode (poBackScn );
        poBSPNode->SetFrontNode(poFrontScn);
        poBSPNode->SetPartitionPlane(oPlane);
    }

    if ( poNodeScn )
    {
        if ( poBSPNode )
        {
            CGSceneGroup* poNode;
            poNode = mNew CGSceneGroup;

            poNode->Init(poBSPNode?2:1);
            poNode->iAddObject(poNodeScn);
            poNode->iAddObject(poBSPNode);

            return (poNode);
        }
        else
            return (poNodeScn);
    }
    else
        return (poBSPNode);
}

CGSceneNode* CLoaderBSP2::poGenerateNodeMesh (bsp_node* _pNode)
{
    if ( !_pNode->num_faces ) return(NULL);

    SCNUt_TriSceneAccumulator oTScn;
    SCNUt_TriSceneSeparator oTSep;
    SCNUt_MeshGenerator oMGen;
    CE3D_Shader* poShader;

    int iFace;
    int iRealFace;
    char szMat[512];

    for ( iFace = 0; iFace < _pNode->num_faces; iFace++ )
    {
        iRealFace = pLFaces[_pNode->num_faces + iFace].index;

        assert( ( (iRealFace >= 0) && (iRealFace < iNumFaces) ) &&
               "BSP face index out bounds" );

        AddFace(&pFaces[iRealFace],&oTScn);
    }

    // Now we have processed all the faces from this leaf node, convert q2 leaf into
    // a GammaE node
    CGSceneNode* poObj;
    oTSep.SeparateScene(oTScn);

    if ( oTSep.NumMeshes > 1 )
    {
        CGSceneGroup* poNode = mNew CGSceneGroup;
        CGSceneLeaf* poLeaf;
        CGMesh* poMesh;

        poNode->Init(oTSep.NumMeshes);

        for ( int iObj = 0; iObj < oTSep.NumMeshes; iObj++ )
        {
            sprintf(szMat,"%s/%s.wal",szQ2BaseDir,pTexInfo[ oTSep.piMatIdx[iObj] ].texture_name);

            poShader = CGShaderWH::I()->poCreateShader(szMat);

            poLeaf = mNew CGSceneLeaf;

            poMesh = oMGen.GenerateMesh(oTSep.Meshes[iObj]);
            poLeaf->SetMesh(poMesh);
            poLeaf->SetShader(poShader);                    // que coño pasa con el material !!!!!

            poNode->iAddObject(poLeaf);
        }

        poObj = poNode;
    }
    else
    {
        sprintf(szMat,"%s/%s.wal",szQ2BaseDir,pTexInfo[ oTSep.piMatIdx[0] ].texture_name);

        poShader = CGShaderWH::I()->poCreateShader(szMat);

        CGSceneLeaf* poLeaf = mNew CGSceneLeaf;
        CGMesh* poMesh = oMGen.GenerateMesh(oTSep.Meshes[0]);

        poLeaf->SetMesh(poMesh);
        poLeaf->SetShader(poShader);                    // que coño pasa con el material !!!!!

        poObj = poLeaf;
    }

    return (poObj);
}

void CLoaderBSP2::AddFace (bsp_face* pFace, SCNUt_TriSceneAccumulator* _pTScn)
{
    SCNUt_TriScene oTScn;
    SCNUt_Triangle* pTri;

    int iEdge;
    int iRealEdge;
    int iVXs[32];

    // Create vertex and edge lists
    for ( iEdge = 0; iEdge < pFace->num_edges; iEdge++ )
    {
        iRealEdge = pFEdges[pFace->first_edge + iEdge].index;

        if ( iRealEdge > 0 )
        {
            iVXs[iEdge] = pEdges[iRealEdge].start;
        }
        else
        {
            iVXs[iEdge] = pEdges[-iRealEdge].end;
        }
    }

    // triangulate face
    ext_texinfo* pETI = &pExtTexInfo[pFace->texture_info];

    int i0,i1,i2;

    // ----------------------------------------------------------
#define COMPUTE_UCOORD(VX,ETI)      \
    ( (VX.x * ETI->pBTI->u_axis.x +  \
       VX.y * ETI->pBTI->u_axis.y +  \
       VX.z * ETI->pBTI->u_axis.z + ETI->pBTI->u_offset) / ETI->iWidth )

#define COMPUTE_VCOORD(VX,ETI)      \
    ( (VX.x * ETI->pBTI->v_axis.x +  \
       VX.y * ETI->pBTI->v_axis.y +  \
       VX.z * ETI->pBTI->v_axis.z + ETI->pBTI->v_offset) / ETI->iHeight )

    // En realidad se debe dividir por el Width y height de la
    // textura!!!->GL_BuildPolygonFromSurface del src de Q2
    // ----------------------------------------------------------

    oTScn.Init(pFace->num_edges - 2);
    pTri = oTScn.Tris;
    i0 = iVXs[0];

    // Setup other triangle data
    for ( iEdge = 2; iEdge < pFace->num_edges; iEdge++ )
    {
        i1 = iVXs[iEdge - 1];
        i2 = iVXs[iEdge   ];

        #ifdef _EVERSE_WINDING_
        pTri->VXs[2].Set(pVXs[i0].x,pVXs[i0].y,pVXs[i0].z);
        pTri->VXs[1].Set(pVXs[i1].x,pVXs[i1].y,pVXs[i1].z);
        pTri->VXs[0].Set(pVXs[i2].x,pVXs[i2].y,pVXs[i2].z);
        #else
        pTri->VXs[0].Set(pVXs[i0].x,pVXs[i0].y,pVXs[i0].z);
        pTri->VXs[1].Set(pVXs[i1].x,pVXs[i1].y,pVXs[i1].z);
        pTri->VXs[2].Set(pVXs[i2].x,pVXs[i2].y,pVXs[i2].z);
        #endif

        pTri->UVs[0].V2( COMPUTE_UCOORD(pTri->VXs[0],pETI),COMPUTE_VCOORD(pTri->VXs[0],pETI) );
        pTri->UVs[1].V2( COMPUTE_UCOORD(pTri->VXs[1],pETI),COMPUTE_VCOORD(pTri->VXs[1],pETI) );
        pTri->UVs[2].V2( COMPUTE_UCOORD(pTri->VXs[2],pETI),COMPUTE_VCOORD(pTri->VXs[2],pETI) );
        SCNUt_TriUtils::MinimizeMappingOffset(*pTri);

        pTri->VCs[0].V4(1.0f,1.0f,1.0f,1.0f);
        pTri->VCs[1].V4(1.0f,1.0f,1.0f,1.0f);
        pTri->VCs[2].V4(1.0f,1.0f,1.0f,1.0f);

        // VNs ???
        pTri->Material = pFace->texture_info;

        pTri++;
    }

    // Add the new triangles!
    _pTScn->AddTriScene(&oTScn);
}

void CLoaderBSP2::SetQ2BaseDir (char* _szDirectory)
{
    strcpy(szQ2BaseDir,_szDirectory);
}
