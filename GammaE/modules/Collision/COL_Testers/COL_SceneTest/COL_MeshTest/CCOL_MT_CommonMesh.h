//## begin module%3C29310E01C5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C29310E01C5.cm

//## begin module%3C29310E01C5.cp preserve=no
//## end module%3C29310E01C5.cp

//## Module: CCOL_MT_CommonMesh%3C29310E01C5; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MT_CommonMesh.h

#ifndef CCOL_MT_CommonMesh_h
#define CCOL_MT_CommonMesh_h 1

//## begin module%3C29310E01C5.additionalIncludes preserve=no
//## end module%3C29310E01C5.additionalIncludes

//## begin module%3C29310E01C5.includes preserve=yes
//## end module%3C29310E01C5.includes

// CCOL_DT_ColTester
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_MeshTester
#include "Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MeshTester.h"
//## begin module%3C29310E01C5.additionalDeclarations preserve=yes
//## end module%3C29310E01C5.additionalDeclarations


//## begin CCOL_MT_CommonMesh%3C29310E01C5.preface preserve=yes
//## end CCOL_MT_CommonMesh%3C29310E01C5.preface

//## Class: CCOL_MT_CommonMesh%3C29310E01C5
//## Category: Collision::COL_Testers::COL_SceneTest::COL_MeshTest%3C294D4B0315
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C2931E00236;CCOL_DT_ColTester { -> }
//## Uses: <unnamed>%3C2A543D00D7;CCOL_ColState { -> }

class CCOL_MT_CommonMesh : public CCOL_MeshTester  //## Inherits: <unnamed>%3C294D9203CB
{
  //## begin CCOL_MT_CommonMesh%3C29310E01C5.initialDeclarations preserve=yes
  //## end CCOL_MT_CommonMesh%3C29310E01C5.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_MT_CommonMesh();

    //## Destructor (generated)
      ~CCOL_MT_CommonMesh();


    //## Other Operations (specified)
      //## Operation: iTestCollision%1009321162
      virtual int iTestCollision (CMesh* _poMesh, int _iMat, CGraphBV* _poBVol, CCOL_TriList& _roTriList);

    // Additional Public Declarations
      //## begin CCOL_MT_CommonMesh%3C29310E01C5.public preserve=yes
      //## end CCOL_MT_CommonMesh%3C29310E01C5.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_MT_CommonMesh%3C29310E01C5.protected preserve=yes
      //## end CCOL_MT_CommonMesh%3C29310E01C5.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_MT_CommonMesh%3C29310E01C5.private preserve=yes
      //## end CCOL_MT_CommonMesh%3C29310E01C5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_MT_CommonMesh%3C29310E01C5.implementation preserve=yes
      //## end CCOL_MT_CommonMesh%3C29310E01C5.implementation

};

//## begin CCOL_MT_CommonMesh%3C29310E01C5.postscript preserve=yes
//## end CCOL_MT_CommonMesh%3C29310E01C5.postscript

// Class CCOL_MT_CommonMesh 

//## begin module%3C29310E01C5.epilog preserve=yes
//## end module%3C29310E01C5.epilog


#endif
