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

#ifndef CLoaderMD3H
#define CLoaderMD3H

#include "MD3Model.h"

// CGSceneNode
#include "CGSceneNode.h"
// C3DLoader
#include "3D_Loaders\C3DLoader.h"
// CGSceneAnimGroup
#include "Animation\CGSceneAnimNode.h"
// CGSceneAnimTransf
#include "Animation\CGSceneAnimTransf.h"
// CGSceneAnimMesh
#include "Animation\CGSceneAnimMesh.h"
// CGSceneAnimCfg
#include "Animation\CGSceneAnimActionSet.h"

class CLoaderMD3 : public C3DLoader
{
    public:
        CLoaderMD3();

        ~CLoaderMD3();

        int iParseSkinSentence(char* _Buffer, char* SkinName, char* MeshName);

        void LoadSkinInfo(char* _Filename);

        CGShader* poGetShader(char* _szMeshName);

        CGSceneAnimTransf* CreateAnimTransfNode(tag_t* _pTags, int _iNumTags, int _iTagStep);

        CGSceneAnimMesh* pCreateAnimMesh(mesh_header_t& _Header, skin_t &_Skin, Q3triangle_t* _Tris, vertice_t* _VXs, tex_coord_t* _UVs);

        CGSceneNode* pLoadModel(char* Filename);

        CGSceneNode* pLoad(char* _ModelName, char* _SkinName);

        virtual CGSceneNode* pLoad(char* Filename);

        CGSceneAnimActionSet* pLoadQ3Player(char* _Path, char* _SkinName);

        CGSceneAnimActionSet* pLoadAnimation(char* _Filename, CGSceneAnimGroup* _pLegs, CGSceneAnimGroup* _pTorso);

        void SetupAnim(int _iAnimNum, anim_t* _MD3Anim, CGSceneAnimActionSet* _poAnimCfg);

    protected:

    private:

        skin_file_t SkinBookmark;

    private:
};

#endif
