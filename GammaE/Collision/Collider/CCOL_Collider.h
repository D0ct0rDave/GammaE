//## begin module%3C06B92E0385.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C06B92E0385.cm

//## begin module%3C06B92E0385.cp preserve=no
//## end module%3C06B92E0385.cp

//## Module: CCOL_Collider%3C06B92E0385; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\Collider\CCOL_Collider.h

#ifndef CCOL_Collider_h
#define CCOL_Collider_h 1

//## begin module%3C06B92E0385.additionalIncludes preserve=no
//## end module%3C06B92E0385.additionalIncludes

//## begin module%3C06B92E0385.includes preserve=yes
#include "Scene/GammaE_Scene.h"
//## end module%3C06B92E0385.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
// eCOL_TestType
#include "Collision\Collider\eCOL_TestType.h"
// CCOL_Stack
#include "Collision\Collider\CCOL_Stack.h"
// eCOL_ColliderType
#include "Collision\Collider\eCOL_ColliderType.h"
// CCOL_TriListGen
#include "Collision\COL_TriList\CCOL_TriListGen.h"
// CCOL_TriList
#include "Collision\COL_TriList\CCOL_TriList.h"
// CCOL_MeshTester
#include "Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MeshTester.h"
//## begin module%3C06B92E0385.additionalDeclarations preserve=yes
//## end module%3C06B92E0385.additionalDeclarations


//## begin CCOL_Collider%3C06B92E0385.preface preserve=yes
//## end CCOL_Collider%3C06B92E0385.preface

//## Class: CCOL_Collider%3C06B92E0385
//## Category: Collision::Collider%3B686E2401AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C06C11E02AB;GammaE_Math { -> }

class CCOL_Collider 
{
  //## begin CCOL_Collider%3C06B92E0385.initialDeclarations preserve=yes
  //## end CCOL_Collider%3C06B92E0385.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_Collider();

    //## Destructor (generated)
      ~CCOL_Collider();


    //## Other Operations (specified)
      //## Operation: Init%1008463031
      void Init (int _iUserID, CCOL_TriListGen* _poTLGen, CCOL_MeshTester* _poMTester, eCOL_ColliderType _eCType, eCOL_TestType _eStTest, eCOL_TestType _eDynTest, CObject3D* _poGrObj, int _iMaxTris, int _iColStackSize);

      //## Operation: Reset%1008534192
      void Reset ();

    //## Get and Set Operations for Associations (generated)

      //## Association: Collision::Collider::<unnamed>%3C0C19AD0181
      //## Role: CCOL_Collider::ColStack%3C0C19AD0285
      CCOL_Stack& GetColStack ();

      //## Association: Collision::Collider::<unnamed>%3C1B129401B3
      //## Role: CCOL_Collider::ColType%3C1B129402AE
      eCOL_ColliderType GetColType ();
      void SetColType (eCOL_ColliderType value);

      //## Association: Collision::Collider::<unnamed>%3C1B1295038B
      //## Role: CCOL_Collider::StTest%3C1B1296006C
      eCOL_TestType GetStTest ();

      //## Association: Collision::Collider::<unnamed>%3C294E5C0064
      //## Role: CCOL_Collider::MeshTester%3C294E5C014B
      CCOL_MeshTester * GetMeshTester ();

      //## Association: Collision::Collider::<unnamed>%3CCA944700F0
      //## Role: CCOL_Collider::DynTest%3CCA9447035C
      eCOL_TestType GetDynTest ();

      //## Association: Collision::Collider::<unnamed>%3C1D022802A3
      //## Role: CCOL_Collider::TriList%3C1D02280375
      CCOL_TriList& GetTriList ();

      //## Association: Collision::Collider::<unnamed>%3C1BEE4B02EB
      //## Role: CCOL_Collider::TriListGen%3C1BEE4B03C8
      CCOL_TriListGen * GetTriListGen ();

    // Data Members for Class Attributes

      //## Attribute: OldPos%3C0D590C02E1
      //## begin CCOL_Collider::OldPos%3C0D590C02E1.attr preserve=no  public: CVect3 {UA} 
      CVect3 OldPos;
      //## end CCOL_Collider::OldPos%3C0D590C02E1.attr

      //## Attribute: Pos%3C06B93A0210
      //## begin CCOL_Collider::Pos%3C06B93A0210.attr preserve=no  public: CVect3 {UA} 
      CVect3 Pos;
      //## end CCOL_Collider::Pos%3C06B93A0210.attr

      //## Attribute: Speed%3C06B93E025C
      //## begin CCOL_Collider::Speed%3C06B93E025C.attr preserve=no  public: CVect3 {UA} 
      CVect3 Speed;
      //## end CCOL_Collider::Speed%3C06B93E025C.attr

      //## Attribute: UserID%3C06B94B03CD
      //## begin CCOL_Collider::UserID%3C06B94B03CD.attr preserve=no  public: int {UA} -1
      int UserID;
      //## end CCOL_Collider::UserID%3C06B94B03CD.attr

      //## Attribute: ColID%3C06B95100D2
      //## begin CCOL_Collider::ColID%3C06B95100D2.attr preserve=no  public: int {UA} -1
      int ColID;
      //## end CCOL_Collider::ColID%3C06B95100D2.attr

      //## Attribute: GrObj%3C06B98F0335
      //## begin CCOL_Collider::GrObj%3C06B98F0335.attr preserve=no  public: CObject3D * {UA} NULL
      CObject3D *GrObj;
      //## end CCOL_Collider::GrObj%3C06B98F0335.attr

    // Data Members for Associations

      //## Association: Collision::Collider::<unnamed>%3C0C19AD0181
      //## begin CCOL_Collider::ColStack%3C0C19AD0285.role preserve=no  public: CCOL_Stack { -> VHAN}
      CCOL_Stack ColStack;
      //## end CCOL_Collider::ColStack%3C0C19AD0285.role

      //## Association: Collision::Collider::<unnamed>%3C1B129401B3
      //## begin CCOL_Collider::ColType%3C1B129402AE.role preserve=no  public: eCOL_ColliderType { -> VHAN}
      eCOL_ColliderType ColType;
      //## end CCOL_Collider::ColType%3C1B129402AE.role

      //## Association: Collision::Collider::<unnamed>%3C1B1295038B
      //## begin CCOL_Collider::StTest%3C1B1296006C.role preserve=no  public: eCOL_TestType { -> VHAN}
      eCOL_TestType StTest;
      //## end CCOL_Collider::StTest%3C1B1296006C.role

      //## Association: Collision::Collider::<unnamed>%3C294E5C0064
      //## begin CCOL_Collider::MeshTester%3C294E5C014B.role preserve=no  public: CCOL_MeshTester { -> RHAN}
      CCOL_MeshTester *MeshTester;
      //## end CCOL_Collider::MeshTester%3C294E5C014B.role

      //## Association: Collision::Collider::<unnamed>%3CCA944700F0
      //## begin CCOL_Collider::DynTest%3CCA9447035C.role preserve=no  public: eCOL_TestType { -> VHAN}
      eCOL_TestType DynTest;
      //## end CCOL_Collider::DynTest%3CCA9447035C.role

      //## Association: Collision::Collider::<unnamed>%3C1D022802A3
      //## begin CCOL_Collider::TriList%3C1D02280375.role preserve=no  public: CCOL_TriList { -> VHAN}
      CCOL_TriList TriList;
      //## end CCOL_Collider::TriList%3C1D02280375.role

      //## Association: Collision::Collider::<unnamed>%3C1BEE4B02EB
      //## begin CCOL_Collider::TriListGen%3C1BEE4B03C8.role preserve=no  public: CCOL_TriListGen { -> RHAN}
      CCOL_TriListGen *TriListGen;
      //## end CCOL_Collider::TriListGen%3C1BEE4B03C8.role

    // Additional Public Declarations
      //## begin CCOL_Collider%3C06B92E0385.public preserve=yes
      //## end CCOL_Collider%3C06B92E0385.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_Collider%3C06B92E0385.protected preserve=yes
      //## end CCOL_Collider%3C06B92E0385.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_Collider%3C06B92E0385.private preserve=yes
      //## end CCOL_Collider%3C06B92E0385.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_Collider%3C06B92E0385.implementation preserve=yes
      //## end CCOL_Collider%3C06B92E0385.implementation

};

//## begin CCOL_Collider%3C06B92E0385.postscript preserve=yes
//## end CCOL_Collider%3C06B92E0385.postscript

// Class CCOL_Collider 

//## Get and Set Operations for Associations (inline)

inline CCOL_Stack& CCOL_Collider::GetColStack ()
{
  //## begin CCOL_Collider::GetColStack%3C0C19AD0285.get preserve=no
  return ColStack;
  //## end CCOL_Collider::GetColStack%3C0C19AD0285.get
}

inline eCOL_ColliderType CCOL_Collider::GetColType ()
{
  //## begin CCOL_Collider::GetColType%3C1B129402AE.get preserve=no
  return ColType;
  //## end CCOL_Collider::GetColType%3C1B129402AE.get
}

inline void CCOL_Collider::SetColType (eCOL_ColliderType value)
{
  //## begin CCOL_Collider::SetColType%3C1B129402AE.set preserve=no
  ColType = value;
  //## end CCOL_Collider::SetColType%3C1B129402AE.set
}

inline eCOL_TestType CCOL_Collider::GetStTest ()
{
  //## begin CCOL_Collider::GetStTest%3C1B1296006C.get preserve=no
  return StTest;
  //## end CCOL_Collider::GetStTest%3C1B1296006C.get
}

inline CCOL_MeshTester * CCOL_Collider::GetMeshTester ()
{
  //## begin CCOL_Collider::GetMeshTester%3C294E5C014B.get preserve=no
  return MeshTester;
  //## end CCOL_Collider::GetMeshTester%3C294E5C014B.get
}

inline eCOL_TestType CCOL_Collider::GetDynTest ()
{
  //## begin CCOL_Collider::GetDynTest%3CCA9447035C.get preserve=no
  return DynTest;
  //## end CCOL_Collider::GetDynTest%3CCA9447035C.get
}

inline CCOL_TriList& CCOL_Collider::GetTriList ()
{
  //## begin CCOL_Collider::GetTriList%3C1D02280375.get preserve=no
  return TriList;
  //## end CCOL_Collider::GetTriList%3C1D02280375.get
}

inline CCOL_TriListGen * CCOL_Collider::GetTriListGen ()
{
  //## begin CCOL_Collider::GetTriListGen%3C1BEE4B03C8.get preserve=no
  return TriListGen;
  //## end CCOL_Collider::GetTriListGen%3C1BEE4B03C8.get
}

//## begin module%3C06B92E0385.epilog preserve=yes
//## end module%3C06B92E0385.epilog


#endif
