//	  %X% %Q% %Z% %W%

#ifndef CLoaderMD3_h
#define CLoaderMD3_h 1

#include "MD3Model.h"

// CObject3D_Node
#include "CObject3D_Node.h"
// C3DLoader
#include "3D_Loaders\C3DLoader.h"
// CObject3D_AnimNode
#include "Animation\CObject3D_AnimNode.h"
// CObject3D_AnimCfgMgr
#include "Animation\CObject3D_AnimCfgMgr.h"
// CObject3D_AnimTransf
#include "Animation\CObject3D_AnimTransf.h"
// CObject3D_AnimMesh
#include "Animation\CObject3D_AnimMesh.h"
// CObject3D_AnimCfg
#include "Animation\CObject3D_AnimCfg.h"

class CLoaderMD3 : public C3DLoader
{

public: CLoaderMD3();

    ~CLoaderMD3();

    int iParseSkinSentence (char *_Buffer, char *SkinName, char *MeshName);

    void LoadSkinInfo (char *_Filename);

    CE3D_Shader *poGetShader (char *_szMeshName);

    CObject3D_AnimTransf *CreateAnimTransfNode (tag_t *_pTags, int _iNumTags, int _iTagStep);

    CObject3D_AnimMesh *pCreateAnimMesh (mesh_header_t & _Header, skin_t &_Skin, Q3triangle_t *_Tris, vertice_t *_VXs, tex_coord_t *_UVs);

    CObject3D *pLoadModel (char *Filename);

    CObject3D *pLoad (char *_ModelName, char *_SkinName);

    virtual CObject3D *pLoad (char *Filename);

    CObject3D_AnimCfgGen *pLoadQ3Player (char *_Path, char *_SkinName);

    CObject3D_AnimCfgMgr *pLoadAnimation (char *_Filename, CObject3D_AnimNode *_pLegs, CObject3D_AnimNode *_pTorso);

    void SetupAnim (int _iAnimNum, anim_t *_MD3Anim, CObject3D_AnimCfg *_pLegs, CObject3D_AnimCfg *_pTorso);

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
    // Data Members for Class Attributes

    skin_file_t SkinBookmark;

     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CLoaderMD3

#endif // ifndef CLoaderMD3_h
