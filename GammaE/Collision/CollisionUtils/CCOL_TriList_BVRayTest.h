//## begin module%3C16A0340259.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C16A0340259.cm

//## begin module%3C16A0340259.cp preserve=no
//## end module%3C16A0340259.cp

//## Module: CCOL_TriList_BVRayTest%3C16A0340259; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\CollisionUtils\CCOL_TriList_BVRayTest.h

#ifndef CCOL_TriList_BVRayTest_h
#define CCOL_TriList_BVRayTest_h 1

//## begin module%3C16A0340259.additionalIncludes preserve=no
//## end module%3C16A0340259.additionalIncludes

//## begin module%3C16A0340259.includes preserve=yes
//## end module%3C16A0340259.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
// CCOL_TriList
#include "Collision\COL_TriList\CCOL_TriList.h"
//## begin module%3C16A0340259.additionalDeclarations preserve=yes
//## end module%3C16A0340259.additionalDeclarations


//## begin CCOL_TriList_BVRayTest%3C16A0340259.preface preserve=yes
//## end CCOL_TriList_BVRayTest%3C16A0340259.preface

//## Class: CCOL_TriList_BVRayTest%3C16A0340259
//## Category: Collision::CollisionUtils%3B686EE501EA
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C2943820092;CCOL_TriList { -> }
//## Uses: <unnamed>%3C1D26EF002A;GammaE_E3D { -> }
//## Uses: <unnamed>%3C16A126022F;GammaE_Math { -> }

class CCOL_TriList_BVRayTest 
{
  //## begin CCOL_TriList_BVRayTest%3C16A0340259.initialDeclarations preserve=yes
  //## end CCOL_TriList_BVRayTest%3C16A0340259.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_TriList_BVRayTest();

    //## Destructor (generated)
      ~CCOL_TriList_BVRayTest();


    //## Other Operations (specified)
      //## Operation: Test%1008112117
      static void Test (CVect3& _Center, CCOL_TriList& _TriList, int _iRayMask, float* _pa6fDists, int* _pa6iTris);

    // Additional Public Declarations
      //## begin CCOL_TriList_BVRayTest%3C16A0340259.public preserve=yes
      //## end CCOL_TriList_BVRayTest%3C16A0340259.public

  protected:

    //## Other Operations (specified)
      //## Operation: fGetRayTriListMinDist%1008112120
      static float fGetRayTriListMinDist (CRay& _Ray, CCOL_TriList& _TriList, CVect3& _Point, int& _iIdx);

    // Additional Protected Declarations
      //## begin CCOL_TriList_BVRayTest%3C16A0340259.protected preserve=yes
      //## end CCOL_TriList_BVRayTest%3C16A0340259.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_TriList_BVRayTest%3C16A0340259.private preserve=yes
      //## end CCOL_TriList_BVRayTest%3C16A0340259.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_TriList_BVRayTest%3C16A0340259.implementation preserve=yes
      //## end CCOL_TriList_BVRayTest%3C16A0340259.implementation

};

//## begin CCOL_TriList_BVRayTest%3C16A0340259.postscript preserve=yes
//## end CCOL_TriList_BVRayTest%3C16A0340259.postscript

// Class CCOL_TriList_BVRayTest 

//## begin module%3C16A0340259.epilog preserve=yes
//## end module%3C16A0340259.epilog


#endif
