//## begin module%3B8B8D1A011C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8B8D1A011C.cm

//## begin module%3B8B8D1A011C.cp preserve=no
//## end module%3B8B8D1A011C.cp

//## Module: CLoaderGEM%3B8B8D1A011C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\3D_Loaders\GEMLoader\CLoaderGEM.h

#ifndef CLoaderGEM_h
#define CLoaderGEM_h 1

//## begin module%3B8B8D1A011C.additionalIncludes preserve=no
//## end module%3B8B8D1A011C.additionalIncludes

//## begin module%3B8B8D1A011C.includes preserve=yes
//## end module%3B8B8D1A011C.includes

// GammaE_FileSys
#include "FileSys\GammaE_FileSys.h"
// CMesh
#include "E3D\Mesh\CMesh.h"
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
// C3DLoader
#include "Scene\3D_Loaders\C3DLoader.h"
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
//## begin module%3B8B8D1A011C.additionalDeclarations preserve=yes
//## end module%3B8B8D1A011C.additionalDeclarations


//## begin CLoaderGEM%3B8B8D1A011C.preface preserve=yes
//## end CLoaderGEM%3B8B8D1A011C.preface

//## Class: CLoaderGEM%3B8B8D1A011C
//## Category: Scene::3D_Loaders::GEMLoader%3B8B8CD70210
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B8BB770034B;CObject3D_Node { -> }
//## Uses: <unnamed>%3B8BB7720113;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3B90D52302F7;CMesh { -> }
//## Uses: <unnamed>%3BAA5173020C;CObject3D_AnimCfg { -> }
//## Uses: <unnamed>%3BAA51750382;CObject3D_AnimCfgMgr { -> }
//## Uses: <unnamed>%3BAA517702B2;CObject3D_AnimTransf { -> }
//## Uses: <unnamed>%3BAA5178030E;CObject3D_AnimMesh { -> }
//## Uses: <unnamed>%3BAA517A018A;CObject3D_AnimNode { -> }
//## Uses: <unnamed>%3BFFBB890066;CObject3D_Mux { -> }
//## Uses: <unnamed>%3BFFBB8A00E9;CObject3D_BSPNode { -> }
//## Uses: <unnamed>%3C7E61A10226;GammaE_FileSys { -> }
//## Uses: <unnamed>%3CC2851201F3;CObject3D_Transf { -> }

class CLoaderGEM : public C3DLoader  //## Inherits: <unnamed>%3B8B8D330118
{
  //## begin CLoaderGEM%3B8B8D1A011C.initialDeclarations preserve=yes
  //## end CLoaderGEM%3B8B8D1A011C.initialDeclarations

  public:
    //## Constructors (generated)
      CLoaderGEM();

    //## Destructor (generated)
      ~CLoaderGEM();


    //## Other Operations (specified)
      //## Operation: pLoad%999007939
      virtual CObject3D * pLoad (char* Filename);

      //## Operation: pLoad%999007940
      CObject3D * pLoad (CFile& _roFile);

      //## Operation: pLoad3DObject%999007941
      CObject3D * pLoad3DObject (CFile& _roFile);

      //## Operation: pLoadMesh%999339038
      CMesh * pLoadMesh (CFile& _roFile);

      //## Operation: pLoad3DObj_Leaf%999639507
      CObject3D_Leaf * pLoad3DObj_Leaf (CFile& _roFile);

      //## Operation: pLoad3DObj_Node%999639508
      CObject3D_Node * pLoad3DObj_Node (CFile& _roFile);

      //## Operation: pLoad3DObj_Transf%1019380667
      CObject3D_Transf * pLoad3DObj_Transf (CFile& _roFile);

      //## Operation: pLoad3DObj_AnimNode%1001017621
      CObject3D_AnimNode * pLoad3DObj_AnimNode (CFile& _roFile);

      //## Operation: pLoad3DObj_AnimMesh%1001017622
      CObject3D_AnimMesh * pLoad3DObj_AnimMesh (CFile& _roFile);

      //## Operation: pLoad3DObj_AnimTransf%1001017623
      CObject3D_AnimTransf * pLoad3DObj_AnimTransf (CFile& _roFile);

      //## Operation: pLoad3DObj_AnimCfg%1001017624
      CObject3D_AnimCfg * pLoad3DObj_AnimCfg (CFile& _roFile);

      //## Operation: pLoad3DObj_AnimCfgMgr%1001017625
      CObject3D_AnimCfgMgr * pLoad3DObj_AnimCfgMgr (CFile& _roFile);

      //## Operation: pLoad3DObj_BSPNode%1006615362
      CObject3D_BSPNode * pLoad3DObj_BSPNode (CFile& _roFile);

      //## Operation: pLoad3DObj_Mux%1006615363
      CObject3D_Mux * pLoad3DObj_Mux (CFile& _roFile);

    // Additional Public Declarations
      //## begin CLoaderGEM%3B8B8D1A011C.public preserve=yes
      //## end CLoaderGEM%3B8B8D1A011C.public

  protected:
    // Additional Protected Declarations
      //## begin CLoaderGEM%3B8B8D1A011C.protected preserve=yes
      //## end CLoaderGEM%3B8B8D1A011C.protected

  private:
    // Additional Private Declarations
      //## begin CLoaderGEM%3B8B8D1A011C.private preserve=yes
      //## end CLoaderGEM%3B8B8D1A011C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLoaderGEM%3B8B8D1A011C.implementation preserve=yes
      //## end CLoaderGEM%3B8B8D1A011C.implementation

};

//## begin CLoaderGEM%3B8B8D1A011C.postscript preserve=yes
//## end CLoaderGEM%3B8B8D1A011C.postscript

// Class CLoaderGEM 

//## begin module%3B8B8D1A011C.epilog preserve=yes
//## end module%3B8B8D1A011C.epilog


#endif
