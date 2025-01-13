//## begin module%3B6F1A7F02E4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B6F1A7F02E4.cm

//## begin module%3B6F1A7F02E4.cp preserve=no
//## end module%3B6F1A7F02E4.cp

//## Module: CCOL_CollisionSystem%3B6F1A7F02E4; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\CollisionSystem\CCOL_CollisionSystem.h

#ifndef CCOL_CollisionSystem_h
#define CCOL_CollisionSystem_h 1

//## begin module%3B6F1A7F02E4.additionalIncludes preserve=no
//## end module%3B6F1A7F02E4.additionalIncludes

//## begin module%3B6F1A7F02E4.includes preserve=yes
//## end module%3B6F1A7F02E4.includes

// CCOL_Collider
#include "Collision\Collider\CCOL_Collider.h"
// CCOL_ColState
#include "Collision\CollisionSystem\CCOL_ColState.h"
// CCOL_DT_Tri
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Tri.h"
// CCOL_DT_ColTester
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_MT_CommonMesh
#include "Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MT_CommonMesh.h"
//## begin module%3B6F1A7F02E4.additionalDeclarations preserve=yes
//## end module%3B6F1A7F02E4.additionalDeclarations


//## begin CCOL_CollisionSystem%3B6F1A7F02E4.preface preserve=yes
//## end CCOL_CollisionSystem%3B6F1A7F02E4.preface

//## Class: CCOL_CollisionSystem%3B6F1A7F02E4
//## Category: Collision::CollisionSystem%3B6F1B480370
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C0A34E3026A;CCOL_Scn_ColTester { -> }
//## Uses: <unnamed>%3C1D2761020F;CCOL_ST_Tris { -> }
//## Uses: <unnamed>%3C292F2C0028;CCOL_DT_Tri { -> }
//## Uses: <unnamed>%3C292FB30343;CCOL_DT_ColTester { -> }
//## Uses: <unnamed>%3C2932FA00C9;CCOL_MT_CommonMesh { -> }
//## Uses: <unnamed>%3C2936440228;CCOL_ColState { -> }

class CCOL_CollisionSystem 
{
  //## begin CCOL_CollisionSystem%3B6F1A7F02E4.initialDeclarations preserve=yes
  //## end CCOL_CollisionSystem%3B6F1A7F02E4.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_CollisionSystem();

    //## Destructor (generated)
      ~CCOL_CollisionSystem();


    //## Other Operations (specified)
      //## Operation: Init%999639512
      void Init (int _iMaxColliders);

      //## Operation: Reset%1018461840
      void Reset ();

      //## Operation: iAddObject%1007074374
      int iAddObject (CCOL_Collider* _poColObj);

      //## Operation: CheckCollisions%999639513
      void CheckCollisions (float _fDelta);

      //## Operation: bCheckCollision%1007327354
      bool bCheckCollision (CCOL_Collider& _Src, float _fDelta);

    // Data Members for Associations

      //## Association: Collision::CollisionSystem::<unnamed>%3C0C1BD1017F
      //## Role: CCOL_CollisionSystem::poColliders%3C0C1BD102D4
      //## begin CCOL_CollisionSystem::poColliders%3C0C1BD102D4.role preserve=no  public: CCOL_Collider { -> RHAN}
      CCOL_Collider** poColliders;
      //## end CCOL_CollisionSystem::poColliders%3C0C1BD102D4.role

    // Additional Public Declarations
      //## begin CCOL_CollisionSystem%3B6F1A7F02E4.public preserve=yes
      //## end CCOL_CollisionSystem%3B6F1A7F02E4.public

  protected:

    //## Other Operations (specified)
      //## Operation: bTestBroadCD%1008711905
      bool bTestBroadCD (CCOL_Collider& _Src, CCOL_Collider& _Dst);

      //## Operation: bTestNarrowCD%1008463032
      bool bTestNarrowCD (CCOL_Collider& _Src, CCOL_Collider& _Dst);

    // Data Members for Class Attributes

      //## Attribute: iMaxColliders%3B6F1AD00064
      //## begin CCOL_CollisionSystem::iMaxColliders%3B6F1AD00064.attr preserve=no  protected: int {UA} 0
      int iMaxColliders;
      //## end CCOL_CollisionSystem::iMaxColliders%3B6F1AD00064.attr

      //## Attribute: iNumColliders%3B6F1AD60320
      //## begin CCOL_CollisionSystem::iNumColliders%3B6F1AD60320.attr preserve=no  protected: int {UA} 0
      int iNumColliders;
      //## end CCOL_CollisionSystem::iNumColliders%3B6F1AD60320.attr

    // Additional Protected Declarations
      //## begin CCOL_CollisionSystem%3B6F1A7F02E4.protected preserve=yes
      //## end CCOL_CollisionSystem%3B6F1A7F02E4.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_CollisionSystem%3B6F1A7F02E4.private preserve=yes
      //## end CCOL_CollisionSystem%3B6F1A7F02E4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_CollisionSystem%3B6F1A7F02E4.implementation preserve=yes
      //## end CCOL_CollisionSystem%3B6F1A7F02E4.implementation

};

//## begin CCOL_CollisionSystem%3B6F1A7F02E4.postscript preserve=yes
//## end CCOL_CollisionSystem%3B6F1A7F02E4.postscript

// Class CCOL_CollisionSystem 

//## begin module%3B6F1A7F02E4.epilog preserve=yes
//## end module%3B6F1A7F02E4.epilog


#endif
