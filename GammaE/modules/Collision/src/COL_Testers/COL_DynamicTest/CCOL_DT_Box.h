//## begin module%3C1FBD52007E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1FBD52007E.cm

//## begin module%3C1FBD52007E.cp preserve=no
//## end module%3C1FBD52007E.cp

//## Module: CCOL_DT_Box%3C1FBD52007E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Box.h

#ifndef CCOL_DT_Box_h
#define CCOL_DT_Box_h 1

//## begin module%3C1FBD52007E.additionalIncludes preserve=no
//## end module%3C1FBD52007E.additionalIncludes

//## begin module%3C1FBD52007E.includes preserve=yes
//## end module%3C1FBD52007E.includes

// CCOL_ColState
#include "Collision\CollisionSystem\CCOL_ColState.h"
// CCOL_ST_Box
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_Box.h"
//## begin module%3C1FBD52007E.additionalDeclarations preserve=yes
//## end module%3C1FBD52007E.additionalDeclarations


//## begin CCOL_DT_Box%3C1FBD52007E.preface preserve=yes
//## end CCOL_DT_Box%3C1FBD52007E.preface

//## Class: CCOL_DT_Box%3C1FBD52007E
//## Category: Collision::COL_Testers::COL_DynamicTest%3C1FBE860262
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1FD1710223;CCOL_ST_Box { -> }
//## Uses: <unnamed>%3C2936E300E6;CCOL_ColState { -> }

class CCOL_DT_Box 
{
  //## begin CCOL_DT_Box%3C1FBD52007E.initialDeclarations preserve=yes
  //## end CCOL_DT_Box%3C1FBD52007E.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_DT_Box();

    //## Destructor (generated)
      ~CCOL_DT_Box();


    //## Other Operations (specified)
      //## Operation: fTestSphere%1008711893
      static float fTestSphere (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDCenter, float _fDRadius);

      //## Operation: fTestBox%1008711894
      static float fTestBox (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDMaxs, CVect3& _roDMins);

      //## Operation: fTestPoint%1008711895
      static float fTestPoint (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDPoint);

    // Additional Public Declarations
      //## begin CCOL_DT_Box%3C1FBD52007E.public preserve=yes
      //## end CCOL_DT_Box%3C1FBD52007E.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_DT_Box%3C1FBD52007E.protected preserve=yes
      //## end CCOL_DT_Box%3C1FBD52007E.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_DT_Box%3C1FBD52007E.private preserve=yes
      //## end CCOL_DT_Box%3C1FBD52007E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_DT_Box%3C1FBD52007E.implementation preserve=yes
      //## end CCOL_DT_Box%3C1FBD52007E.implementation

};

//## begin CCOL_DT_Box%3C1FBD52007E.postscript preserve=yes
//## end CCOL_DT_Box%3C1FBD52007E.postscript

// Class CCOL_DT_Box 

//## begin module%3C1FBD52007E.epilog preserve=yes
//## end module%3C1FBD52007E.epilog


#endif
