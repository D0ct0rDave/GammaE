//	  %X% %Q% %Z% %W%

#ifndef CLoaderGEM_h
#define CLoaderGEM_h 1

// GammaE_FileSys
#include "GammaE_FileSys.h"
// CMesh
#include "GammaE_E3D.h"

#include "..\C3DLoader.h"
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

class CLoaderGEM : public C3DLoader
{

public: CLoaderGEM();

    ~CLoaderGEM();

    virtual CObject3D *pLoad (char *Filename);

    CObject3D *pLoad (CFile & _oFile);

    CObject3D *pLoad3DObject (CFile & _oFile);

    CMesh *pLoadMesh (CFile & _oFile);

    CObject3D_Leaf *pLoad3DObj_Leaf (CFile & _oFile);

    CObject3D_Node *pLoad3DObj_Node (CFile & _oFile);

    CObject3D_Transf *pLoad3DObj_Transf (CFile & _oFile);

    CObject3D_AnimNode *pLoad3DObj_AnimNode (CFile & _oFile);

    CObject3D_AnimMesh *pLoad3DObj_AnimMesh (CFile & _oFile);

    CObject3D_AnimTransf *pLoad3DObj_AnimTransf (CFile & _oFile);

    CObject3D_AnimCfg *pLoad3DObj_AnimCfg (CFile & _oFile);

    CObject3D_AnimCfgMgr *pLoad3DObj_AnimCfgMgr (CFile & _oFile);

    CObject3D_BSPNode *pLoad3DObj_BSPNode (CFile & _oFile);

    CObject3D_Mux *pLoad3DObj_Mux (CFile & _oFile);

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CLoaderGEM

#endif // ifndef CLoaderGEM_h
