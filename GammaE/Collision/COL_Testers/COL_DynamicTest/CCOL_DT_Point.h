//## begin module%3C4DB0B60195.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C4DB0B60195.cm

//## begin module%3C4DB0B60195.cp preserve=no
//## end module%3C4DB0B60195.cp

//## Module: CCOL_DT_Point%3C4DB0B60195; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Point.h

#ifndef CCOL_DT_Point_h
#define CCOL_DT_Point_h 1

//## begin module%3C4DB0B60195.additionalIncludes preserve=no
//## end module%3C4DB0B60195.additionalIncludes

//## begin module%3C4DB0B60195.includes preserve=yes
//## end module%3C4DB0B60195.includes

// CCOL_ColState
#include "Collision\CollisionSystem\CCOL_ColState.h"
// CCOL_DT_Box
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Box.h"
// CCOL_DT_Sphere
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Sphere.h"
//## begin module%3C4DB0B60195.additionalDeclarations preserve=yes
//## end module%3C4DB0B60195.additionalDeclarations


//## begin CCOL_DT_Point%3C4DB0B60195.preface preserve=yes
//## end CCOL_DT_Point%3C4DB0B60195.preface

//## Class: CCOL_DT_Point%3C4DB0B60195
//## Category: Collision::COL_Testers::COL_DynamicTest%3C1FBE860262
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C4DB25100CD;CCOL_ColState { -> }
//## Uses: <unnamed>%3C4E0A100161;CCOL_DT_Sphere { -> }
//## Uses: <unnamed>%3C4E0A130011;CCOL_DT_Box { -> }

class CCOL_DT_Point 
{
  //## begin CCOL_DT_Point%3C4DB0B60195.initialDeclarations preserve=yes
  //## end CCOL_DT_Point%3C4DB0B60195.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_DT_Point();

    //## Destructor (generated)
      ~CCOL_DT_Point();


    //## Other Operations (specified)
      //## Operation: fTestSphere%1011722644
      static float fTestSphere (CVect3& _roSPoint, CVect3& _roDCenter, float _fDRadius);

      //## Operation: fTestBox%1011722645
      static float fTestBox (CVect3& _roSPoint, CVect3& _roDMaxs, CVect3& _roDMins);

      //## Operation: fTestPoint%1011722646
      static float fTestPoint (CVect3& _roSPoint, float _fDRadius, CVect3& _roDCenter);

    // Additional Public Declarations
      //## begin CCOL_DT_Point%3C4DB0B60195.public preserve=yes
      //## end CCOL_DT_Point%3C4DB0B60195.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_DT_Point%3C4DB0B60195.protected preserve=yes
      //## end CCOL_DT_Point%3C4DB0B60195.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_DT_Point%3C4DB0B60195.private preserve=yes
      //## end CCOL_DT_Point%3C4DB0B60195.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_DT_Point%3C4DB0B60195.implementation preserve=yes
      //## end CCOL_DT_Point%3C4DB0B60195.implementation

};

//## begin CCOL_DT_Point%3C4DB0B60195.postscript preserve=yes
//## end CCOL_DT_Point%3C4DB0B60195.postscript

// Class CCOL_DT_Point 

//## begin module%3C4DB0B60195.epilog preserve=yes
//## end module%3C4DB0B60195.epilog


#endif
