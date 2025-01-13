//## begin module%3B7AF1BC01C2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7AF1BC01C2.cm

//## begin module%3B7AF1BC01C2.cp preserve=no
//## end module%3B7AF1BC01C2.cp

//## Module: CCOL_ST_ColTester%3B7AF1BC01C2; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_StaticTest\CCOL_ST_ColTester.h

#ifndef CCOL_ST_ColTester_h
#define CCOL_ST_ColTester_h 1

//## begin module%3B7AF1BC01C2.additionalIncludes preserve=no
//## end module%3B7AF1BC01C2.additionalIncludes

//## begin module%3B7AF1BC01C2.includes preserve=yes
//## end module%3B7AF1BC01C2.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// CCOL_ST_Point
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_Point.h"
// CCOL_ST_Sphere
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_Sphere.h"
// CCOL_ST_Box
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_Box.h"
//## begin module%3B7AF1BC01C2.additionalDeclarations preserve=yes
//## end module%3B7AF1BC01C2.additionalDeclarations


//## begin CCOL_ST_ColTester%3B7AF1BC01C2.preface preserve=yes
//## end CCOL_ST_ColTester%3B7AF1BC01C2.preface

//## Class: CCOL_ST_ColTester%3B7AF1BC01C2
//## Category: Collision::COL_Testers::COL_StaticTest%3C1FBE770329
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C082533011A;CCOL_ST_Sphere { -> }
//## Uses: <unnamed>%3C0825390317;CCOL_ST_Box { -> }
//## Uses: <unnamed>%3C4DE5A00072;CCOL_ST_Point { -> }
//## Uses: <unnamed>%3C1D26EB02AF;GammaE_E3D { -> }

class CCOL_ST_ColTester 
{
  //## begin CCOL_ST_ColTester%3B7AF1BC01C2.initialDeclarations preserve=yes
  //## end CCOL_ST_ColTester%3B7AF1BC01C2.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_ST_ColTester();

    //## Destructor (generated)
      ~CCOL_ST_ColTester();


    //## Other Operations (specified)
      //## Operation: iTestCollision%997912317
      static int iTestCollision (CGraphBV *SrcObj, CGraphBV *DstObj);

      //## Operation: iTestPlane%1007160414
      static int iTestPlane (CGraphBV *_SrcObj, CPlane& Plane);

    // Additional Public Declarations
      //## begin CCOL_ST_ColTester%3B7AF1BC01C2.public preserve=yes
      //## end CCOL_ST_ColTester%3B7AF1BC01C2.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_ST_ColTester%3B7AF1BC01C2.protected preserve=yes
      //## end CCOL_ST_ColTester%3B7AF1BC01C2.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_ST_ColTester%3B7AF1BC01C2.private preserve=yes
      //## end CCOL_ST_ColTester%3B7AF1BC01C2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_ST_ColTester%3B7AF1BC01C2.implementation preserve=yes
      //## end CCOL_ST_ColTester%3B7AF1BC01C2.implementation

};

//## begin CCOL_ST_ColTester%3B7AF1BC01C2.postscript preserve=yes
//## end CCOL_ST_ColTester%3B7AF1BC01C2.postscript

// Class CCOL_ST_ColTester 

//## begin module%3B7AF1BC01C2.epilog preserve=yes
//## end module%3B7AF1BC01C2.epilog


#endif
