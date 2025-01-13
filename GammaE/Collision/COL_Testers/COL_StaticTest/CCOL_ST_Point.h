//## begin module%3C4DE4F802B6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C4DE4F802B6.cm

//## begin module%3C4DE4F802B6.cp preserve=no
//## end module%3C4DE4F802B6.cp

//## Module: CCOL_ST_Point%3C4DE4F802B6; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_StaticTest\CCOL_ST_Point.h

#ifndef CCOL_ST_Point_h
#define CCOL_ST_Point_h 1

//## begin module%3C4DE4F802B6.additionalIncludes preserve=no
//## end module%3C4DE4F802B6.additionalIncludes

//## begin module%3C4DE4F802B6.includes preserve=yes
//## end module%3C4DE4F802B6.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C4DE4F802B6.additionalDeclarations preserve=yes
//## end module%3C4DE4F802B6.additionalDeclarations


//## begin CCOL_ST_Point%3C4DE4F802B6.preface preserve=yes
//## end CCOL_ST_Point%3C4DE4F802B6.preface

//## Class: CCOL_ST_Point%3C4DE4F802B6
//## Category: Collision::COL_Testers::COL_StaticTest%3C1FBE770329
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C4DE594018D;GammaE_Math { -> }

class CCOL_ST_Point 
{
  //## begin CCOL_ST_Point%3C4DE4F802B6.initialDeclarations preserve=yes
  //## end CCOL_ST_Point%3C4DE4F802B6.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_ST_Point();

    //## Destructor (generated)
      ~CCOL_ST_Point();


    //## Other Operations (specified)
      //## Operation: iTestSphere%1011738050
      static int iTestSphere (CVect3& _roSPoint, CVect3& _roDCenter, float _fDRadius);

      //## Operation: iTestBox%1011738051
      static int iTestBox (CVect3& _roSPoint, CVect3& _roDMaxs, CVect3& _roDMins);

      //## Operation: iTestPoint%1011738052
      static int iTestPoint (CVect3& _roSPoint, CVect3& _roDPoint);

    // Additional Public Declarations
      //## begin CCOL_ST_Point%3C4DE4F802B6.public preserve=yes
      //## end CCOL_ST_Point%3C4DE4F802B6.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_ST_Point%3C4DE4F802B6.protected preserve=yes
      //## end CCOL_ST_Point%3C4DE4F802B6.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_ST_Point%3C4DE4F802B6.private preserve=yes
      //## end CCOL_ST_Point%3C4DE4F802B6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_ST_Point%3C4DE4F802B6.implementation preserve=yes
      //## end CCOL_ST_Point%3C4DE4F802B6.implementation

};

//## begin CCOL_ST_Point%3C4DE4F802B6.postscript preserve=yes
//## end CCOL_ST_Point%3C4DE4F802B6.postscript

// Class CCOL_ST_Point 

//## begin module%3C4DE4F802B6.epilog preserve=yes
//## end module%3C4DE4F802B6.epilog


#endif
