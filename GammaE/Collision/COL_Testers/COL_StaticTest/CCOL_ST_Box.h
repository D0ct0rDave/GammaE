//## begin module%3C0824C801D4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0824C801D4.cm

//## begin module%3C0824C801D4.cp preserve=no
//## end module%3C0824C801D4.cp

//## Module: CCOL_ST_Box%3C0824C801D4; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_StaticTest\CCOL_ST_Box.h

#ifndef CCOL_ST_Box_h
#define CCOL_ST_Box_h 1

//## begin module%3C0824C801D4.additionalIncludes preserve=no
//## end module%3C0824C801D4.additionalIncludes

//## begin module%3C0824C801D4.includes preserve=yes
//## end module%3C0824C801D4.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C0824C801D4.additionalDeclarations preserve=yes
//## end module%3C0824C801D4.additionalDeclarations


//## begin CCOL_ST_Box%3C0824C801D4.preface preserve=yes
//## end CCOL_ST_Box%3C0824C801D4.preface

//## Class: CCOL_ST_Box%3C0824C801D4
//## Category: Collision::COL_Testers::COL_StaticTest%3C1FBE770329
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C0828E50337;GammaE_Math { -> }

class CCOL_ST_Box 
{
  //## begin CCOL_ST_Box%3C0824C801D4.initialDeclarations preserve=yes
  //## end CCOL_ST_Box%3C0824C801D4.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_ST_Box();

    //## Destructor (generated)
      ~CCOL_ST_Box();


    //## Other Operations (specified)
      //## Operation: iTestSphere%1007160421
      static int iTestSphere (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDCenter, float _fDRadius);

      //## Operation: iTestBox%1007160422
      static int iTestBox (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDMaxs, CVect3& _roDMins);

      //## Operation: iTestPoint%1007160423
      static int iTestPoint (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDPoint);

    // Additional Public Declarations
      //## begin CCOL_ST_Box%3C0824C801D4.public preserve=yes
      //## end CCOL_ST_Box%3C0824C801D4.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_ST_Box%3C0824C801D4.protected preserve=yes
      //## end CCOL_ST_Box%3C0824C801D4.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_ST_Box%3C0824C801D4.private preserve=yes
      //## end CCOL_ST_Box%3C0824C801D4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_ST_Box%3C0824C801D4.implementation preserve=yes
      //## end CCOL_ST_Box%3C0824C801D4.implementation

};

//## begin CCOL_ST_Box%3C0824C801D4.postscript preserve=yes
//## end CCOL_ST_Box%3C0824C801D4.postscript

// Class CCOL_ST_Box 

//## begin module%3C0824C801D4.epilog preserve=yes
//## end module%3C0824C801D4.epilog


#endif
