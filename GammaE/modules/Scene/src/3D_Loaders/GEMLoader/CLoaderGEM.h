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
#ifndef CLoaderGEMH
#define CLoaderGEMH
// --------------------------------------------------------------------------------
#include "GammaE_FileSys.h"
// CGMesh
#include "GammaE_E3D.h"

#include "3D_Loaders/C3DLoader.h"
#include "CGSceneNode.h"
#include "CGSceneLeaf.h"
#include "CGSceneNode.h"
#include "CGSceneTransf.h"
/*
 #include "Animation\CGSceneAnimNode.h"
 #include "Animation\CGSceneAnimMesh.h"
 #include "Animation\CGSceneAnimTransf.h"
 #include "Animation\CGSceneAnimCfg.h"
 #include "Animation\CGSceneAnimInstance.h"
 */
// #include "Animation\CGSceneAnimCfgMgr.h"
#include "CGSceneBSPNode.h"
#include "CGSceneMux.h"

class CLoaderGEM : public C3DLoader
{
    public:
        CLoaderGEM();
        ~CLoaderGEM();

        virtual CGSceneNode* poLoad(const CGString& _sFilename);
        virtual CGSceneNode* poLoad(const CGFile& _oFile);

    protected:

        CGSceneNode* poLoad();

        CGSceneNode* poLoad3DObject();

        CGMesh* poLoadMesh();

        CGSceneLeaf* poLoad3DObj_Leaf();

        CGSceneGroup* poLoad3DObj_Node();

        CGSceneTransf* poLoad3DObj_Transf();

        CGSceneAnimNode* poLoad3DObj_AnimNode();

        CGSceneAnimMesh* poLoad3DObj_AnimMesh();

        CGSceneAnimTransf* poLoad3DObj_AnimTransf();

        CGSceneAnimCfg* poLoad3DObj_AnimCfg();

        CGSceneAnimCfgMgr* poLoad3DObj_AnimCfgMgr();

        CGSceneBSPNode* poLoad3DObj_BSPNode();

        CGSceneMux* poLoad3DObj_Mux();

        CGSceneAnimObject* poLoad3DObj_AnimObject();

    protected:

        CGFile* m_poFile;
};
// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
