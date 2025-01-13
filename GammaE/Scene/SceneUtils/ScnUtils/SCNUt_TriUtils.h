//## begin module%3C76D5340057.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C76D5340057.cm

//## begin module%3C76D5340057.cp preserve=no
//## end module%3C76D5340057.cp

//## Module: SCNUt_TriUtils%3C76D5340057; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnUtils\SCNUt_TriUtils.h

#ifndef SCNUt_TriUtils_h
#define SCNUt_TriUtils_h 1

//## begin module%3C76D5340057.additionalIncludes preserve=no
//## end module%3C76D5340057.additionalIncludes

//## begin module%3C76D5340057.includes preserve=yes
//## end module%3C76D5340057.includes

// SCNUt_Triangle
#include "Scene\SceneUtils\SCNUt_Triangle.h"
//## begin module%3C76D5340057.additionalDeclarations preserve=yes
//## end module%3C76D5340057.additionalDeclarations


//## begin SCNUt_TriUtils%3C76D5340057.preface preserve=yes
//## end SCNUt_TriUtils%3C76D5340057.preface

//## Class: SCNUt_TriUtils%3C76D5340057
//## Category: Scene::SceneUtils::ScnUtils%3C76D529012E
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C76D57D0175;SCNUt_Triangle { -> }

class SCNUt_TriUtils 
{
  //## begin SCNUt_TriUtils%3C76D5340057.initialDeclarations preserve=yes
  //## end SCNUt_TriUtils%3C76D5340057.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_TriUtils();

    //## Destructor (generated)
      ~SCNUt_TriUtils();


    //## Other Operations (specified)
      //## Operation: MinimizeMappingOffset%1014421760
      static void MinimizeMappingOffset (SCNUt_Triangle& _roTri);

      //## Operation: ChangeWinding%1014421761
      static void ChangeWinding (SCNUt_Triangle& _roTri);

      //## Operation: GetQ2UVCoords%1014767413
      static void GetQ2UVCoords (CVect3& _roPnt, CVect3& _roXAxis, CVect3& _roYAxis, float _fUOfs, float _fVOfs, float _fUScl, float _fVScl, float* _pfU, float* _pfV);

    // Additional Public Declarations
      //## begin SCNUt_TriUtils%3C76D5340057.public preserve=yes
      //## end SCNUt_TriUtils%3C76D5340057.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_TriUtils%3C76D5340057.protected preserve=yes
      //## end SCNUt_TriUtils%3C76D5340057.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_TriUtils%3C76D5340057.private preserve=yes
      //## end SCNUt_TriUtils%3C76D5340057.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_TriUtils%3C76D5340057.implementation preserve=yes
      //## end SCNUt_TriUtils%3C76D5340057.implementation

};

//## begin SCNUt_TriUtils%3C76D5340057.postscript preserve=yes
//## end SCNUt_TriUtils%3C76D5340057.postscript

// Class SCNUt_TriUtils 

//## begin module%3C76D5340057.epilog preserve=yes
//## end module%3C76D5340057.epilog


#endif
