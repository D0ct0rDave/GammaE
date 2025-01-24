//	  %X% %Q% %Z% %W%

#ifndef CLoaderBSP2_h
#define CLoaderBSP2_h 1

#include "BSP2types.h"

// CObject3D
#include "CObject3D.h"
// CObject3D_BSPNode
#include "CObject3D_BSPNode.h"
// CObject3D_Node
#include "CObject3D_Node.h"
// CObject3D_Leaf
#include "CObject3D_Leaf.h"
// C3DLoader
#include "3D_Loaders\C3DLoader.h"
// SCNUt_TriSceneAccumulator
#include "GammaE_SceneUtils.h"

struct ext_texinfo
{
   int iWidth;
   int iHeight;
   bsp_texinfo *pBTI;
};

class CLoaderBSP2 : public C3DLoader
{

public: CLoaderBSP2();

    ~CLoaderBSP2();

    virtual CObject3D *pLoad (char *Filename);

    void SetExtendedTexInfo ();

    CObject3D *poProcessBSP ();

    CObject3D *poGenerateLeaf (bsp_leaf *_pLeaf);

    CObject3D *poGenerateNode (bsp_node *_pNode);

    CObject3D *poGenerateNodeMesh (bsp_node *_pNode);

    void AddFace (bsp_face *pFace, SCNUt_TriSceneAccumulator *_pTScn);

    void SetQ2BaseDir (char *_szDirectory);

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
    // Data Members for Class Attributes

    bsp_header oBSPhdr;

    bsp_point3f *pVXs;

    int iNumVXs;

    bsp_edge *pEdges;

    int iNumEdges;

    bsp_face *pFaces;

    int iNumFaces;

    bsp_leaf_face *pLFaces;

    int iNumLFaces;

    bsp_face_edge *pFEdges;

    int iNumFEdges;

    bsp_plane *pPlanes;

    int iNumPlanes;

    bsp_node *pNodes;

    int iNumNodes;

    bsp_leaf *pLeaves;

    int iNumLeaves;

    bsp_texinfo *pTexInfo;

    ext_texinfo *pExtTexInfo;

    int iNumTexs;

    bsp_vis_offset *pVIS;

    int iNumVis;

    CObject3D * *poScnLeaves;

    char szQ2BaseDir[256];

     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CLoaderBSP2

#endif // ifndef CLoaderBSP2_h
