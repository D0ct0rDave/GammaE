//## begin module%3C294D5D01F8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C294D5D01F8.cm

//## begin module%3C294D5D01F8.cp preserve=no
//## end module%3C294D5D01F8.cp

//## Module: CCOL_MeshTester%3C294D5D01F8; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MeshTester.h

#ifndef CCOL_MeshTester_h
#define CCOL_MeshTester_h 1

//## begin module%3C294D5D01F8.additionalIncludes preserve=no
//## end module%3C294D5D01F8.additionalIncludes

//## begin module%3C294D5D01F8.includes preserve=yes
//## end module%3C294D5D01F8.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// CCOL_TriList
#include "Collision\COL_TriList\CCOL_TriList.h"
//## begin module%3C294D5D01F8.additionalDeclarations preserve=yes
//## end module%3C294D5D01F8.additionalDeclarations


//## begin CCOL_MeshTester%3C294D5D01F8.preface preserve=yes
//## end CCOL_MeshTester%3C294D5D01F8.preface

//## Class: CCOL_MeshTester%3C294D5D01F8
//## Category: Collision::COL_Testers::COL_SceneTest::COL_MeshTest%3C294D4B0315
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C294F2901BE;GammaE_E3D { -> }
//## Uses: <unnamed>%3C294DAA02F3;CCOL_TriList { -> }

class CCOL_MeshTester 
{
  //## begin CCOL_MeshTester%3C294D5D01F8.initialDeclarations preserve=yes
  //## end CCOL_MeshTester%3C294D5D01F8.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_MeshTester();

    //## Destructor (generated)
      ~CCOL_MeshTester();


    //## Other Operations (specified)
      //## Operation: iTestCollision%1009321163
      virtual int iTestCollision (CMesh* _poMesh, int _iMat, CGraphBV* _poBVol, CCOL_TriList& _roTriList);

    // Additional Public Declarations
      //## begin CCOL_MeshTester%3C294D5D01F8.public preserve=yes
      //## end CCOL_MeshTester%3C294D5D01F8.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_MeshTester%3C294D5D01F8.protected preserve=yes
      //## end CCOL_MeshTester%3C294D5D01F8.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_MeshTester%3C294D5D01F8.private preserve=yes
      //## end CCOL_MeshTester%3C294D5D01F8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_MeshTester%3C294D5D01F8.implementation preserve=yes
      //## end CCOL_MeshTester%3C294D5D01F8.implementation

};

//## begin CCOL_MeshTester%3C294D5D01F8.postscript preserve=yes
//## end CCOL_MeshTester%3C294D5D01F8.postscript

// Class CCOL_MeshTester 

//## begin module%3C294D5D01F8.epilog preserve=yes
//## end module%3C294D5D01F8.epilog


#endif
