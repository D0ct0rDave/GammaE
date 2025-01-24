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
// ---------------------------------------------------------------------------
#ifndef CLoaderGEM_h
#define CLoaderGEM_h 1
// ---------------------------------------------------------------------------
// GammaE_FileSys
#include "CGSceneVisitor.h"

class CGVLoaderGEM : public CGSceneVisitor
{
    public:
        CObject3D* poLoad(CFile* _poFile);

        virtual void Visit(CObject3D* _poNode);

        virtual void Visit(CGSceneBSPNode* _poNode);

        virtual void Visit(CGSceneCamera* _poNode);

        virtual void Visit(CGSceneCompiledLeaf* _poNode);

        virtual void Visit(CGSceneInstance* _poNode);

        virtual void Visit(CGSceneLeaf* _poNode);

        virtual void Visit(CGSceneMux* _poNode);

        virtual void Visit(CGSceneNode* _poNode);

        virtual void Visit(CGSceneScreenRect* _poNode);

        virtual void Visit(CGSceneSwitch* _poNode);

        virtual void Visit(CGSceneTransf* _poNode);

        virtual void Visit(CGSceneAnimCfg* _poNode);

        virtual void Visit(CGSceneAnimCfgGen* _poNode);

        virtual void Visit(CGSceneAnimCfgMgr* _poNode);

        virtual void Visit(CGSceneAnimObject* _poNode);

        virtual void Visit(CGSceneAnimMesh* _poNode);

        virtual void Visit(CGSceneAnimMeshInstance* _poNode);

        virtual void Visit(CGSceneAnimNode* _poNode);

        virtual void Visit(CGSceneAnimTransf* _poNode);

        CMesh* poLoadMesh();

    protected:

        CFile* m_poFile;
        void* m_poReturnValue;
};

// Class CLoaderGEM
// ---------------------------------------------------------------------------
#endif
// ---------------------------------------------------------------------------
