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

#ifndef CLoaderBSP2H
#define CLoaderBSP2H 1

#include "BSP2types.h"

// CGSceneNode
#include "CGSceneNode.h"
// CGSceneBSPNode
#include "CGSceneBSPNode.h"
// CGSceneNode
#include "CGSceneNode.h"
// CGSceneLeaf
#include "CGSceneLeaf.h"
// C3DLoader
#include "3D_Loaders\C3DLoader.h"
// SCNUt_TriSceneAccumulator
#include "GammaE_SceneUtils.h"

struct ext_texinfo
{
    int iWidth;
    int iHeight;
    bsp_texinfo* pBTI;
};

class CLoaderBSP2 : public C3DLoader
{
    public:
        CLoaderBSP2();

        ~CLoaderBSP2();

        virtual CGSceneNode* pLoad(char* Filename);

        void SetExtendedTexInfo();

        CGSceneNode* poProcessBSP();

        CGSceneNode* poGenerateLeaf(bsp_leaf* _pLeaf);

        CGSceneNode* poGenerateNode(bsp_node* _pNode);

        CGSceneNode* poGenerateNodeMesh(bsp_node* _pNode);

        void AddFace(bsp_face* pFace, SCNUt_TriSceneAccumulator* _pTScn);

        void SetQ2BaseDir(char* _szDirectory);

    protected:

    private:

        bsp_header oBSPhdr;

        bsp_point3f* pVXs;

        int iNumVXs;

        bsp_edge* pEdges;

        int iNumEdges;

        bsp_face* pFaces;

        int iNumFaces;

        bsp_leaf_face* pLFaces;

        int iNumLFaces;

        bsp_face_edge* pFEdges;

        int iNumFEdges;

        bsp_plane* pPlanes;

        int iNumPlanes;

        bsp_node* pNodes;

        int iNumNodes;

        bsp_leaf* pLeaves;

        int iNumLeaves;

        bsp_texinfo* pTexInfo;

        ext_texinfo* pExtTexInfo;

        int iNumTexs;

        bsp_vis_offset* pVIS;

        int iNumVis;

        CGSceneNode* * poScnLeaves;

        char szQ2BaseDir[256];

    private:
};

#endif
