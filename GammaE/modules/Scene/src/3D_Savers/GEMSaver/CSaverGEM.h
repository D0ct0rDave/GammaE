//## begin module%3B90D31E007D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B90D31E007D.cm

//## begin module%3B90D31E007D.cp preserve=no
//## end module%3B90D31E007D.cp

//## Module: CSaverGEM%3B90D31E007D; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\3D_Savers\GEMSaver\CSaverGEM.h

#ifndef CSaverGEM_h
#define CSaverGEM_h 1

//## begin module%3B90D31E007D.additionalIncludes preserve=no
//## end module%3B90D31E007D.additionalIncludes

//## begin module%3B90D31E007D.includes preserve=yes
//## end module%3B90D31E007D.includes

// GammaE_FileSys
#include "FileSys\GammaE_FileSys.h"
// CMesh
#include "E3D\Mesh\CMesh.h"
// CObject3D_Camera
#include "Scene\CObject3D_Camera.h"
// CObject3D
#include "Scene\CObject3D.h"
// CObject3D_Transf
#include "Scene\CObject3D_Transf.h"
// CObject3D_BSPNode
#include "Scene\CObject3D_BSPNode.h"
// CObject3D_Mux
#include "Scene\CObject3D_Mux.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
// C3DSaver
#include "Scene\3D_Savers\C3DSaver.h"
// CObject3D_AnimTransf
#include "Scene\Animation\CObject3D_AnimTransf.h"
// CObject3D_AnimMesh
#include "Scene\Animation\CObject3D_AnimMesh.h"
// CObject3D_AnimCfg
#include "Scene\Animation\CObject3D_AnimCfg.h"
// CObject3D_AnimNode
#include "Scene\Animation\CObject3D_AnimNode.h"
// CObject3D_AnimCfgMgr
#include "Scene\Animation\CObject3D_AnimCfgMgr.h"
//## begin module%3B90D31E007D.additionalDeclarations preserve=yes
//## end module%3B90D31E007D.additionalDeclarations


//## begin CSaverGEM%3B90D31E007D.preface preserve=yes
//## end CSaverGEM%3B90D31E007D.preface

//## Class: CSaverGEM%3B90D31E007D
//## Category: Scene::3D_Savers::GEMSaver%3B90D3A80310
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B90D79201D1;CObject3D_Camera { -> }
//## Uses: <unnamed>%3B90D7940152;CObject3D_Node { -> }
//## Uses: <unnamed>%3B90D7960046;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3B90D7990131;CObject3D { -> }
//## Uses: <unnamed>%3B90D8450142;CMesh { -> }
//## Uses: <unnamed>%3BA9063D002A;CObject3D_AnimNode { -> }
//## Uses: <unnamed>%3BA9063F0087;CObject3D_AnimMesh { -> }
//## Uses: <unnamed>%3BA90641017A;CObject3D_AnimTransf { -> }
//## Uses: <unnamed>%3BA9064301CD;CObject3D_AnimCfgMgr { -> }
//## Uses: <unnamed>%3BA9064500AD;CObject3D_AnimCfg { -> }
//## Uses: <unnamed>%3BFFBBB400CC;CObject3D_Mux { -> }
//## Uses: <unnamed>%3BFFBBB5029A;CObject3D_BSPNode { -> }
//## Uses: <unnamed>%3C7E61B2028E;GammaE_FileSys { -> }
//## Uses: <unnamed>%3CC284F80029;CObject3D_Transf { -> }

class CSaverGEM : public C3DSaver  //## Inherits: <unnamed>%3B90D6820071
{
  //## begin CSaverGEM%3B90D31E007D.initialDeclarations preserve=yes
  //## end CSaverGEM%3B90D31E007D.initialDeclarations

  public:
    //## Constructors (generated)
      CSaverGEM();

    //## Destructor (generated)
      ~CSaverGEM();


    //## Other Operations (specified)
      //## Operation: iSave%999339041
      int iSave (CFile& _roFile, CObject3D *_pObj);

      //## Operation: iSave3DObject%999339042
      int iSave3DObject (CFile& _roFile, CObject3D *_pObj);

      //## Operation: iSave3DObj_Leaf%999339043
      int iSave3DObj_Leaf (CFile& _roFile, CObject3D_Leaf *_pObj);

      //## Operation: iSave3DObj_Node%999339044
      int iSave3DObj_Node (CFile& _roFile, CObject3D_Node *_pObj);

      //## Operation: iSave3DObj_Transf%1019380668
      int iSave3DObj_Transf (CFile& _roFile, CObject3D_Transf *_pObj);

      //## Operation: iSaveMesh%999339045
      int iSaveMesh (CFile& _roFile, CMesh *Mesh);

      //## Operation: iSave3DObj_AnimNode%1000932997
      int iSave3DObj_AnimNode (CFile& _roFile, CObject3D_AnimNode *_pObj);

      //## Operation: iSave3DObj_AnimMesh%1000932998
      int iSave3DObj_AnimMesh (CFile& _roFile, CObject3D_AnimMesh *_pObj);

      //## Operation: iSave3DObj_AnimTransf%1000932999
      int iSave3DObj_AnimTransf (CFile& _roFile, CObject3D_AnimTransf *_pObj);

      //## Operation: iSave3DObj_AnimCfg%1000933000
      int iSave3DObj_AnimCfg (CFile& _roFile, CObject3D_AnimCfg *_pObj);

      //## Operation: iSave3DObj_AnimCfgMgr%1000933001
      int iSave3DObj_AnimCfgMgr (CFile& _roFile, CObject3D_AnimCfgMgr *_pObj);

      //## Operation: iSave3DObj_BSPNode%1006615360
      int iSave3DObj_BSPNode (CFile& _roFile, CObject3D_BSPNode *_pObj);

      //## Operation: iSave3DObj_Mux%1006615361
      int iSave3DObj_Mux (CFile& _roFile, CObject3D_Mux *_pObj);

      //## Operation: iSave%999339047
      virtual int iSave (char *_Filename, CObject3D* _pObj);

    // Additional Public Declarations
      //## begin CSaverGEM%3B90D31E007D.public preserve=yes
      //## end CSaverGEM%3B90D31E007D.public

  protected:
    // Additional Protected Declarations
      //## begin CSaverGEM%3B90D31E007D.protected preserve=yes
      //## end CSaverGEM%3B90D31E007D.protected

  private:
    // Additional Private Declarations
      //## begin CSaverGEM%3B90D31E007D.private preserve=yes
      //## end CSaverGEM%3B90D31E007D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSaverGEM%3B90D31E007D.implementation preserve=yes
      //## end CSaverGEM%3B90D31E007D.implementation

};

//## begin CSaverGEM%3B90D31E007D.postscript preserve=yes
//## end CSaverGEM%3B90D31E007D.postscript

// Class CSaverGEM 

//## begin module%3B90D31E007D.epilog preserve=yes
//## end module%3B90D31E007D.epilog


#endif
