//## begin module%3C1FBC350287.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1FBC350287.cm

//## begin module%3C1FBC350287.cp preserve=no
//## end module%3C1FBC350287.cp

//## Module: CCOL_DT_ColTester%3C1FBC350287; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h

#ifndef CCOL_DT_ColTester_h
#define CCOL_DT_ColTester_h 1

//## begin module%3C1FBC350287.additionalIncludes preserve=no
//## end module%3C1FBC350287.additionalIncludes

//## begin module%3C1FBC350287.includes preserve=yes
//## end module%3C1FBC350287.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// CCOL_ColState
#include "Collision\CollisionSystem\CCOL_ColState.h"
// CCOL_DT_Box
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Box.h"
// CCOL_DT_Point
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Point.h"
// CCOL_DT_Tri
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Tri.h"
// CCOL_DT_Sphere
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Sphere.h"
//## begin module%3C1FBC350287.additionalDeclarations preserve=yes
//## end module%3C1FBC350287.additionalDeclarations


//## begin CCOL_DT_ColTester%3C1FBC350287.preface preserve=yes
//## end CCOL_DT_ColTester%3C1FBC350287.preface

//## Class: CCOL_DT_ColTester%3C1FBC350287
//## Category: Collision::COL_Testers::COL_DynamicTest%3C1FBE860262
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1FBDAD0148;CCOL_DT_Sphere { -> }
//## Uses: <unnamed>%3C1FBDAF01C3;CCOL_DT_Box { -> }
//## Uses: <unnamed>%3C291CFD009C;CCOL_DT_Tri { -> }
//## Uses: <unnamed>%3C2936D80307;CCOL_ColState { -> }
//## Uses: <unnamed>%3C4DB16002E4;CCOL_DT_Point { -> }
//## Uses: <unnamed>%3C1FBE420322;GammaE_E3D { -> }

class CCOL_DT_ColTester 
{
  //## begin CCOL_DT_ColTester%3C1FBC350287.initialDeclarations preserve=yes
  //## end CCOL_DT_ColTester%3C1FBC350287.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_DT_ColTester();

    //## Destructor (generated)
      ~CCOL_DT_ColTester();


    //## Other Operations (specified)
      //## Operation: fTestCollision%1008711899
      static float fTestCollision (CGraphBV *SrcObj, CGraphBV *DstObj);

      //## Operation: fTestPlane%1008711900
      static float fTestPlane (CGraphBV *_SrcObj, CPlane& Plane);

      //## Operation: fTestTriangle%1009321156
      static float fTestTriangle (CGraphBV *_SrcObj, CTriangle& _Tri);

    // Additional Public Declarations
      //## begin CCOL_DT_ColTester%3C1FBC350287.public preserve=yes
      //## end CCOL_DT_ColTester%3C1FBC350287.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_DT_ColTester%3C1FBC350287.protected preserve=yes
      //## end CCOL_DT_ColTester%3C1FBC350287.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_DT_ColTester%3C1FBC350287.private preserve=yes
      //## end CCOL_DT_ColTester%3C1FBC350287.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_DT_ColTester%3C1FBC350287.implementation preserve=yes
      //## end CCOL_DT_ColTester%3C1FBC350287.implementation

};

//## begin CCOL_DT_ColTester%3C1FBC350287.postscript preserve=yes
//## end CCOL_DT_ColTester%3C1FBC350287.postscript

// Class CCOL_DT_ColTester 

//## begin module%3C1FBC350287.epilog preserve=yes
//## end module%3C1FBC350287.epilog


#endif
