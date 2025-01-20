//## begin module%3C1FBCC302E6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1FBCC302E6.cm

//## begin module%3C1FBCC302E6.cp preserve=no
//## end module%3C1FBCC302E6.cp

//## Module: CCOL_DT_Sphere%3C1FBCC302E6; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Sphere.h

#ifndef CCOL_DT_Sphere_h
#define CCOL_DT_Sphere_h 1

//## begin module%3C1FBCC302E6.additionalIncludes preserve=no
//## end module%3C1FBCC302E6.additionalIncludes

//## begin module%3C1FBCC302E6.includes preserve=yes
//## end module%3C1FBCC302E6.includes

// CCOL_ColState
#include "Collision\CollisionSystem\CCOL_ColState.h"
// CCOL_DT_Box
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Box.h"
//## begin module%3C1FBCC302E6.additionalDeclarations preserve=yes
//## end module%3C1FBCC302E6.additionalDeclarations


//## begin CCOL_DT_Sphere%3C1FBCC302E6.preface preserve=yes
//## end CCOL_DT_Sphere%3C1FBCC302E6.preface

//## Class: CCOL_DT_Sphere%3C1FBCC302E6
//## Category: Collision::COL_Testers::COL_DynamicTest%3C1FBE860262
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1FBFD101F0;CCOL_DT_Box { -> }
//## Uses: <unnamed>%3C2936E10223;CCOL_ColState { -> }

class CCOL_DT_Sphere 
{
  //## begin CCOL_DT_Sphere%3C1FBCC302E6.initialDeclarations preserve=yes
  //## end CCOL_DT_Sphere%3C1FBCC302E6.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_DT_Sphere();

    //## Destructor (generated)
      ~CCOL_DT_Sphere();


    //## Other Operations (specified)
      //## Operation: fTestSphere%1008711896
      static float fTestSphere (CVect3& _roSCenter, float _fSRadius, CVect3& _roDCenter, float _fDRadius);

      //## Operation: fTestBox%1008711897
      static float fTestBox (CVect3& _roSCenter, float _fSRadius, CVect3& _roDMaxs, CVect3& _roDMins);

      //## Operation: fTestPoint%1008711898
      static float fTestPoint (CVect3& _roSCenter, float _fSRadius, CVect3& _roDPoint);

    // Additional Public Declarations
      //## begin CCOL_DT_Sphere%3C1FBCC302E6.public preserve=yes
      //## end CCOL_DT_Sphere%3C1FBCC302E6.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_DT_Sphere%3C1FBCC302E6.protected preserve=yes
      //## end CCOL_DT_Sphere%3C1FBCC302E6.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_DT_Sphere%3C1FBCC302E6.private preserve=yes
      //## end CCOL_DT_Sphere%3C1FBCC302E6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_DT_Sphere%3C1FBCC302E6.implementation preserve=yes
      //## end CCOL_DT_Sphere%3C1FBCC302E6.implementation

};

//## begin CCOL_DT_Sphere%3C1FBCC302E6.postscript preserve=yes
//## end CCOL_DT_Sphere%3C1FBCC302E6.postscript

// Class CCOL_DT_Sphere 

//## begin module%3C1FBCC302E6.epilog preserve=yes
//## end module%3C1FBCC302E6.epilog


#endif
