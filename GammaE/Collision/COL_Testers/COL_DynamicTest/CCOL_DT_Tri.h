//## begin module%3C291C7D0387.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C291C7D0387.cm

//## begin module%3C291C7D0387.cp preserve=no
//## end module%3C291C7D0387.cp

//## Module: CCOL_DT_Tri%3C291C7D0387; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Tri.h

#ifndef CCOL_DT_Tri_h
#define CCOL_DT_Tri_h 1

//## begin module%3C291C7D0387.additionalIncludes preserve=no
//## end module%3C291C7D0387.additionalIncludes

//## begin module%3C291C7D0387.includes preserve=yes
//## end module%3C291C7D0387.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// CCOL_ColState
#include "Collision\CollisionSystem\CCOL_ColState.h"
//## begin module%3C291C7D0387.additionalDeclarations preserve=yes
//## end module%3C291C7D0387.additionalDeclarations


//## begin CCOL_DT_Tri%3C291C7D0387.preface preserve=yes
//## end CCOL_DT_Tri%3C291C7D0387.preface

//## Class: CCOL_DT_Tri%3C291C7D0387
//## Category: Collision::COL_Testers::COL_DynamicTest%3C1FBE860262
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C2936F5020E;CCOL_ColState { -> }
//## Uses: <unnamed>%3C2921C6013E;GammaE_E3D { -> }

class CCOL_DT_Tri 
{
  //## begin CCOL_DT_Tri%3C291C7D0387.initialDeclarations preserve=yes
  //## end CCOL_DT_Tri%3C291C7D0387.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_DT_Tri();

    //## Destructor (generated)
      ~CCOL_DT_Tri();


    //## Other Operations (specified)
      //## Operation: fTestSphere%1009321154
      static float fTestSphere (CGraphBV_Sphere& _Sphere, CTriangle& _Tri);

      //## Operation: fTestBox%1009321155
      static float fTestBox (CGraphBV_Box& _Box, CTriangle& _Tri);

      //## Operation: fTestPoint%1011748897
      static float fTestPoint (CVect3& _roPoint, CTriangle& _Tri);

    // Additional Public Declarations
      //## begin CCOL_DT_Tri%3C291C7D0387.public preserve=yes
      //## end CCOL_DT_Tri%3C291C7D0387.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_DT_Tri%3C291C7D0387.protected preserve=yes
      //## end CCOL_DT_Tri%3C291C7D0387.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_DT_Tri%3C291C7D0387.private preserve=yes
      //## end CCOL_DT_Tri%3C291C7D0387.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_DT_Tri%3C291C7D0387.implementation preserve=yes
      //## end CCOL_DT_Tri%3C291C7D0387.implementation

};

//## begin CCOL_DT_Tri%3C291C7D0387.postscript preserve=yes
//## end CCOL_DT_Tri%3C291C7D0387.postscript

// Class CCOL_DT_Tri 

//## begin module%3C291C7D0387.epilog preserve=yes
//## end module%3C291C7D0387.epilog


#endif
