// ----------------------------------------------------------------------------
/*! \class CSaverGEM
 *  \brief Class to save a scene graphi in GEM format.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CSaverGEMH
#define CSaverGEMH
// ----------------------------------------------------------------------------
#include "..\C3DSaver.h"

class CGFile;
class CGMesh;

// ----------------------------------------------------------------------------

class CSaverGEM : public C3DSaver
{
    public:
        CSaverGEM();
        ~CSaverGEM();

        virtual void Visit(CGSceneNode* _poNode);

        virtual void Visit(CGSceneBSPNode* _poNode);

        virtual void Visit(CGSceneCamera* _poNode);

        virtual void Visit(CGSceneCompiledLeaf* _poNode);

        virtual void Visit(CGSceneInstance* _poNode);

        virtual void Visit(CGSceneLeaf* _poNode);

        virtual void Visit(CGSceneMux* _poNode);

        virtual void Visit(CGSceneGroup* _poNode);

        virtual void Visit(CGSceneScreenRect* _poNode);

        virtual void Visit(CGSceneSwitch* _poNode);

        virtual void Visit(CGSceneTransf* _poNode);

        virtual void Visit(CGSceneAnimCfg* _poNode);

        virtual void Visit(CGSceneAnimObject* _poNode);

        virtual void Visit(CGSceneAnimMesh* _poNode);

        virtual void Visit(CGSceneAnimInstance* _poNode);

        virtual void Visit(CGSceneAnimNode* _poNode);

        virtual void Visit(CGSceneAnimTransf* _poNode);

        // / Override main saving function.
        virtual bool bSave(const CGString& _sFilename, CGSceneNode* _poObj);

        // / Perform saving over an already opened file.
        virtual bool bSave(const CGFile& _oFile, CGSceneNode* _poObj);

    protected:

        bool bSaveMesh(CGMesh* Mesh);

        /*
           int iSave(CFile& _oFile, CGSceneNode* _pObj);

           int iSave3DObject(CFile& _oFile, CGSceneNode* _pObj);

           int iSaveSNT_Leaf(CFile& _oFile, CGSceneLeaf* _pObj);

           int iSaveSNT_Node(CFile& _oFile, CGSceneGroup* _pObj);

           int iSaveSNT_Transf(CFile& _oFile, CGSceneTransf* _pObj);

           int iSaveMesh(CFile& _oFile, CGMesh* Mesh);

           int iSaveSNT_AnimNode(CFile& _oFile, CGSceneAnimNode* _pObj);

           int iSaveSNT_AnimMesh(CFile& _oFile, CGSceneAnimMesh* _pObj);

           int iSaveSNT_AnimTransf(CFile& _oFile, CGSceneAnimTransf* _pObj);

           int iSaveSNT_AnimCfg(CFile& _oFile, CGSceneAnimCfg* _pObj);

           int iSaveSNT_AnimInstance(CFile& _oFile, CGSceneAnimCfgMgr* _pObj);

           int iSaveSNT_BSPNode(CFile& _oFile, CGSceneBSPNode* _pObj);

           int iSaveSNT_Mux(CFile& _oFile, CGSceneMux* _pObj);

           virtual int iSave(char* _Filename, CGSceneNode* _pObj);
         */

    protected:

        //
        int iSaveAnimObject(CGFile& _oFile,CGSceneAnimObject* _poObj);

        // Svaes a mesh
        void SaveMesh(CGBaseMesh* _poMesh);

        // Saves a bounding volume
        void SaveBoundingVolume(CGBoundingVolume* _poBV);

        // to store the current file being saved
        CGFile* m_poFile;
        bool m_bResult;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------