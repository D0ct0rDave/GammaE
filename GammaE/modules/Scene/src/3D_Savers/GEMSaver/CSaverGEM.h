//	  %X% %Q% %Z% %W%

#ifndef CSaverGEM_h
#define CSaverGEM_h 1

// GammaE_FileSys
#include "GammaE_FileSys.h"
// CMesh
#include "GammaE_E3D.h"
// CObject3D_Camera

#include "..\C3DSaver.h"
#include "..\..\CObject3D.h"
#include "..\..\CObject3D_Leaf.h"
#include "..\..\CObject3D_Node.h"
#include "..\..\CObject3D_Transf.h"
#include "..\..\Animation\CObject3D_AnimNode.h"
#include "..\..\Animation\CObject3D_AnimMesh.h"
#include "..\..\Animation\CObject3D_AnimTransf.h"
#include "..\..\Animation\CObject3D_AnimCfg.h"
#include "..\..\Animation\CObject3D_AnimCfgMgr.h"
#include "..\..\CObject3D_BSPNode.h"
#include "..\..\CObject3D_Mux.h"

// CObject3D

class CSaverGEM : public C3DSaver
{

public: CSaverGEM();

    ~CSaverGEM();

    int iSave (CFile & _oFile, CObject3D *_pObj);

    int iSave3DObject (CFile & _oFile, CObject3D *_pObj);

    int iSave3DObj_Leaf (CFile & _oFile, CObject3D_Leaf *_pObj);

    int iSave3DObj_Node (CFile & _oFile, CObject3D_Node *_pObj);

    int iSave3DObj_Transf (CFile & _oFile, CObject3D_Transf *_pObj);

    int iSaveMesh (CFile & _oFile, CMesh *Mesh);

    int iSave3DObj_AnimNode (CFile & _oFile, CObject3D_AnimNode *_pObj);

    int iSave3DObj_AnimMesh (CFile & _oFile, CObject3D_AnimMesh *_pObj);

    int iSave3DObj_AnimTransf (CFile & _oFile, CObject3D_AnimTransf *_pObj);

    int iSave3DObj_AnimCfg (CFile & _oFile, CObject3D_AnimCfg *_pObj);

    int iSave3DObj_AnimCfgMgr (CFile & _oFile, CObject3D_AnimCfgMgr *_pObj);

    int iSave3DObj_BSPNode (CFile & _oFile, CObject3D_BSPNode *_pObj);

    int iSave3DObj_Mux (CFile & _oFile, CObject3D_Mux *_pObj);

    virtual int iSave (char *_Filename, CObject3D *_pObj);

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CSaverGEM

#endif // ifndef CSaverGEM_h
