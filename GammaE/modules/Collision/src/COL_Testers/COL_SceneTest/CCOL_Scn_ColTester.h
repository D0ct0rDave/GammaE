//## begin module%3C081B0A0386.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C081B0A0386.cm

//## begin module%3C081B0A0386.cp preserve=no
//## end module%3C081B0A0386.cp

//## Module: CCOL_Scn_ColTester%3C081B0A0386; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_SceneTest\CCOL_Scn_ColTester.h

#ifndef CCOL_Scn_ColTester_h
#define CCOL_Scn_ColTester_h 1

//## begin module%3C081B0A0386.additionalIncludes preserve=no
//## end module%3C081B0A0386.additionalIncludes

//## begin module%3C081B0A0386.includes preserve=yes
#include "Scene/GammaE_Scene.h"
//## end module%3C081B0A0386.includes

// CBoundingSphere
#include "E3D\BoundingVolume\CBoundingSphere.h"
// CCOL_ColState
#include "Collision\CollisionSystem\CCOL_ColState.h"
// CCOL_ST_ColTester
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_ColTester.h"
// CCOL_DT_ColTester
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_Mesh
#include "Collision\COL_Testers\COL_SceneTest\CCOL_Mesh.h"
//## begin module%3C081B0A0386.additionalDeclarations preserve=yes
//## end module%3C081B0A0386.additionalDeclarations


//## begin CCOL_Scn_ColTester%3C081B0A0386.preface preserve=yes
//## end CCOL_Scn_ColTester%3C081B0A0386.preface

//## Class: CCOL_Scn_ColTester%3C081B0A0386
//## Category: Collision::COL_Testers::COL_SceneTest%3C1FC2BD0368
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C081D26033D;CBoundingSphere { -> }
//## Uses: <unnamed>%3C082CE30336;CCOL_ST_ColTester { -> }
//## Uses: <unnamed>%3C1FC418010E;CCOL_DT_ColTester { -> }
//## Uses: <unnamed>%3C29367F0273;CCOL_ColState { -> }

class CCOL_Scn_ColTester 
{
  //## begin CCOL_Scn_ColTester%3C081B0A0386.initialDeclarations preserve=yes
  //## end CCOL_Scn_ColTester%3C081B0A0386.initialDeclarations

  public:
    //## Destructor (generated)
      ~CCOL_Scn_ColTester();


    //## Other Operations (specified)
      //## Operation: iTestObjects%1007160409
      static int iTestObjects ();

      //## Operation: iTest3DObj_Rec%1007160413
      static int iTest3DObj_Rec (CObject3D *_poObj);

      //## Operation: iTest3DObj%1007327360
      static int iTest3DObj (CObject3D* _poObj);

      //## Operation: iTest3DObj_Node%1007160412
      static int iTest3DObj_Node (CObject3D_Node* _poObj);

      //## Operation: iTest3DObj_Transf%1018775601
      static int iTest3DObj_Transf (CObject3D_Transf* _poObj);

      //## Operation: iTest3DObj_CompiledLeaf%1012005359
      static int iTest3DObj_CompiledLeaf (CObject3D_CompiledLeaf* _poObj);

      //## Operation: iTest3DObj_Leaf%1007160411
      static int iTest3DObj_Leaf (CObject3D_Leaf* _poObj);

      //## Operation: iTest3DObj_BSPNode%1007160410
      static int iTest3DObj_BSPNode (CObject3D_BSPNode* _poObj);

    // Data Members for Class Attributes

      //## Attribute: SGrObj%3C0B94FD011B
      //## begin CCOL_Scn_ColTester::SGrObj%3C0B94FD011B.attr preserve=no  public: static CObject3D * {UA} NULL
      static CObject3D *SGrObj;
      //## end CCOL_Scn_ColTester::SGrObj%3C0B94FD011B.attr

      //## Attribute: DGrObj%3C0B95080262
      //## begin CCOL_Scn_ColTester::DGrObj%3C0B95080262.attr preserve=no  public: static CObject3D * {UA} NULL
      static CObject3D *DGrObj;
      //## end CCOL_Scn_ColTester::DGrObj%3C0B95080262.attr

      //## Attribute: iNumColMeshes%3C1BF0DC00AB
      //## begin CCOL_Scn_ColTester::iNumColMeshes%3C1BF0DC00AB.attr preserve=no  public: static int {UA} 0
      static int iNumColMeshes;
      //## end CCOL_Scn_ColTester::iNumColMeshes%3C1BF0DC00AB.attr

    // Data Members for Associations

      //## Association: Collision::COL_Testers::COL_SceneTest::<unnamed>%3C1FDD770374
      //## Role: CCOL_Scn_ColTester::ColMeshes%3C1FDD78002C
      //## begin CCOL_Scn_ColTester::ColMeshes%3C1FDD78002C.role preserve=no  public: static CCOL_Mesh {n -> 64UHAN}
      static CCOL_Mesh ColMeshes[64];
      //## end CCOL_Scn_ColTester::ColMeshes%3C1FDD78002C.role

    // Additional Public Declarations
      //## begin CCOL_Scn_ColTester%3C081B0A0386.public preserve=yes
      //## end CCOL_Scn_ColTester%3C081B0A0386.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_Scn_ColTester%3C081B0A0386.protected preserve=yes
      //## end CCOL_Scn_ColTester%3C081B0A0386.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_Scn_ColTester%3C081B0A0386.private preserve=yes
      //## end CCOL_Scn_ColTester%3C081B0A0386.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_Scn_ColTester%3C081B0A0386.implementation preserve=yes
      //## end CCOL_Scn_ColTester%3C081B0A0386.implementation

};

//## begin CCOL_Scn_ColTester%3C081B0A0386.postscript preserve=yes
//## end CCOL_Scn_ColTester%3C081B0A0386.postscript

// Class CCOL_Scn_ColTester 

//## begin module%3C081B0A0386.epilog preserve=yes
//## end module%3C081B0A0386.epilog


#endif
