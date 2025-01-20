//## begin module%3B5DFBBE03CA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B5DFBBE03CA.cm

//## begin module%3B5DFBBE03CA.cp preserve=no
//## end module%3B5DFBBE03CA.cp

//## Module: GammaE_Collision%3B5DFBBE03CA; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\GammaE_Collision.h

#ifndef GammaE_Collision_h
#define GammaE_Collision_h 1

//## begin module%3B5DFBBE03CA.additionalIncludes preserve=no
//## end module%3B5DFBBE03CA.additionalIncludes

//## begin module%3B5DFBBE03CA.includes preserve=yes
#include "Collision/CollisionSystem/CCOL_CollisionSystem.h"
#include "Collision/CollisionUtils/CCOL_TriList_BVRayTest.h"
#include "Collision/COL_TriList/CCOL_TriListGen.h"
#include "Collision/COL_TriList/CCOL_Scn_TriListGen.h"
#include "Collision/COL_TriList/CCOL_TRN_TriListGen.h"
#include "Collision/COL_Testers/COL_SceneTest/COL_MeshTest/CCOL_MT_CommonMesh.h"
#include "Collision/COL_Testers/COL_SceneTest/COL_MeshTest/CCOL_MT_TerrainMesh.h"
#include "Collision/COL_Testers/COL_SceneTest/CCOL_Scn_ColTester.h"

#include "Collision/COL_Testers/COL_StaticTest/CCOL_ST_Box.h"
#include "Collision/COL_Testers/COL_StaticTest/CCOL_ST_Sphere.h"
#include "Collision/COL_Testers/COL_StaticTest/CCOL_ST_ColTester.h"
#include "Collision/COL_Testers/COL_StaticTest/CCOL_ST_Point.h"
#include "Collision/COL_Testers/COL_StaticTest/CCOL_ST_Sphere.h"
#include "Collision/COL_Testers/COL_StaticTest/CCOL_ST_Tris.h"

#include "Collision/COL_Testers/COL_DynamicTest/CCOL_DT_Box.h"
#include "Collision/COL_Testers/COL_DynamicTest/CCOL_DT_Sphere.h"
#include "Collision/COL_Testers/COL_DynamicTest/CCOL_DT_ColTester.h"
#include "Collision/COL_Testers/COL_DynamicTest/CCOL_DT_Point.h"
#include "Collision/COL_Testers/COL_DynamicTest/CCOL_DT_Sphere.h"
#include "Collision/COL_Testers/COL_DynamicTest/CCOL_DT_Tri.h"

//## end module%3B5DFBBE03CA.includes

//## begin module%3B5DFBBE03CA.additionalDeclarations preserve=yes
//## end module%3B5DFBBE03CA.additionalDeclarations


//## begin GammaE_Collision%3B5DFBBE03CA.preface preserve=yes
//## end GammaE_Collision%3B5DFBBE03CA.preface

//## Class: GammaE_Collision%3B5DFBBE03CA
//## Category: Collision%3B5DE9EC02B2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class GammaE_Collision 
{
  //## begin GammaE_Collision%3B5DFBBE03CA.initialDeclarations preserve=yes
  //## end GammaE_Collision%3B5DFBBE03CA.initialDeclarations

  public:
    //## Constructors (generated)
      GammaE_Collision();

    //## Destructor (generated)
      ~GammaE_Collision();

    // Additional Public Declarations
      //## begin GammaE_Collision%3B5DFBBE03CA.public preserve=yes
      //## end GammaE_Collision%3B5DFBBE03CA.public

  protected:
    // Additional Protected Declarations
      //## begin GammaE_Collision%3B5DFBBE03CA.protected preserve=yes
      //## end GammaE_Collision%3B5DFBBE03CA.protected

  private:
    // Additional Private Declarations
      //## begin GammaE_Collision%3B5DFBBE03CA.private preserve=yes
      //## end GammaE_Collision%3B5DFBBE03CA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin GammaE_Collision%3B5DFBBE03CA.implementation preserve=yes
      //## end GammaE_Collision%3B5DFBBE03CA.implementation

};

//## begin GammaE_Collision%3B5DFBBE03CA.postscript preserve=yes
//## end GammaE_Collision%3B5DFBBE03CA.postscript

// Class GammaE_Collision 

//## begin module%3B5DFBBE03CA.epilog preserve=yes
//## end module%3B5DFBBE03CA.epilog


#endif

