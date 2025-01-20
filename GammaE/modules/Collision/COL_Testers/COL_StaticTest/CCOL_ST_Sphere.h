//## begin module%3C0822A10055.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0822A10055.cm

//## begin module%3C0822A10055.cp preserve=no
//## end module%3C0822A10055.cp

//## Module: CCOL_ST_Sphere%3C0822A10055; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_StaticTest\CCOL_ST_Sphere.h

#ifndef CCOL_ST_Sphere_h
#define CCOL_ST_Sphere_h 1

//## begin module%3C0822A10055.additionalIncludes preserve=no
//## end module%3C0822A10055.additionalIncludes

//## begin module%3C0822A10055.includes preserve=yes
//## end module%3C0822A10055.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
// CCOL_ST_Box
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_Box.h"
//## begin module%3C0822A10055.additionalDeclarations preserve=yes
//## end module%3C0822A10055.additionalDeclarations


//## begin CCOL_ST_Sphere%3C0822A10055.preface preserve=yes
//## end CCOL_ST_Sphere%3C0822A10055.preface

//## Class: CCOL_ST_Sphere%3C0822A10055
//## Category: Collision::COL_Testers::COL_StaticTest%3C1FBE770329
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C0AA52F0136;CCOL_ST_Box { -> }
//## Uses: <unnamed>%3C0828D0008D;GammaE_Math { -> }

class CCOL_ST_Sphere 
{
  //## begin CCOL_ST_Sphere%3C0822A10055.initialDeclarations preserve=yes
  //## end CCOL_ST_Sphere%3C0822A10055.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_ST_Sphere();

    //## Destructor (generated)
      ~CCOL_ST_Sphere();


    //## Other Operations (specified)
      //## Operation: iTestSphere%1007160418
      static int iTestSphere (CVect3& _roSCenter, float _fSRadius, CVect3& _roDCenter, float _fDRadius);

      //## Operation: iTestBox%1007160419
      static int iTestBox (CVect3& _roSCenter, float _fSRadius, CVect3& _roDMaxs, CVect3& _roDMins);

      //## Operation: iTestPoint%1007160420
      static int iTestPoint (CVect3& _roSCenter, float _fSRadius, CVect3& _roDPoint);

    // Additional Public Declarations
      //## begin CCOL_ST_Sphere%3C0822A10055.public preserve=yes
      //## end CCOL_ST_Sphere%3C0822A10055.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_ST_Sphere%3C0822A10055.protected preserve=yes
      //## end CCOL_ST_Sphere%3C0822A10055.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_ST_Sphere%3C0822A10055.private preserve=yes
      //## end CCOL_ST_Sphere%3C0822A10055.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_ST_Sphere%3C0822A10055.implementation preserve=yes
      //## end CCOL_ST_Sphere%3C0822A10055.implementation

};

//## begin CCOL_ST_Sphere%3C0822A10055.postscript preserve=yes
//## end CCOL_ST_Sphere%3C0822A10055.postscript

// Class CCOL_ST_Sphere 

//## begin module%3C0822A10055.epilog preserve=yes
//## end module%3C0822A10055.epilog


#endif
