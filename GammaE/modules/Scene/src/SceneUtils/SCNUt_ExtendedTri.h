//## begin module%3BE868D30047.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE868D30047.cm

//## begin module%3BE868D30047.cp preserve=no
//## end module%3BE868D30047.cp

//## Module: SCNUt_ExtendedTri%3BE868D30047; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SCNUt_ExtendedTri.h

#ifndef SCNUt_ExtendedTri_h
#define SCNUt_ExtendedTri_h 1

//## begin module%3BE868D30047.additionalIncludes preserve=no
//## end module%3BE868D30047.additionalIncludes

//## begin module%3BE868D30047.includes preserve=yes
//## end module%3BE868D30047.includes

// SCNUt_Triangle
#include "Scene\SceneUtils\SCNUt_Triangle.h"
//## begin module%3BE868D30047.additionalDeclarations preserve=yes
//## end module%3BE868D30047.additionalDeclarations


//## begin SCNUt_ExtendedTri%3BE868D30047.preface preserve=yes
//## end SCNUt_ExtendedTri%3BE868D30047.preface

//## Class: SCNUt_ExtendedTri%3BE868D30047
//## Category: Scene::SceneUtils%3AC22916003C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BE8692D01B9;SCNUt_Triangle { -> }

class SCNUt_ExtendedTri 
{
  //## begin SCNUt_ExtendedTri%3BE868D30047.initialDeclarations preserve=yes
  //## end SCNUt_ExtendedTri%3BE868D30047.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_ExtendedTri();

    //## Destructor (generated)
      ~SCNUt_ExtendedTri();

    // Data Members for Class Attributes

      //## Attribute: T%3BE868E60076
      //## begin SCNUt_ExtendedTri::T%3BE868E60076.attr preserve=no  public: SCNUt_Triangle {UA} 
      SCNUt_Triangle T;
      //## end SCNUt_ExtendedTri::T%3BE868E60076.attr

    // Additional Public Declarations
      //## begin SCNUt_ExtendedTri%3BE868D30047.public preserve=yes
      //## end SCNUt_ExtendedTri%3BE868D30047.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_ExtendedTri%3BE868D30047.protected preserve=yes
      //## end SCNUt_ExtendedTri%3BE868D30047.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_ExtendedTri%3BE868D30047.private preserve=yes
      //## end SCNUt_ExtendedTri%3BE868D30047.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_ExtendedTri%3BE868D30047.implementation preserve=yes
      //## end SCNUt_ExtendedTri%3BE868D30047.implementation

};

//## begin SCNUt_ExtendedTri%3BE868D30047.postscript preserve=yes
//## end SCNUt_ExtendedTri%3BE868D30047.postscript

// Class SCNUt_ExtendedTri 

//## begin module%3BE868D30047.epilog preserve=yes
//## end module%3BE868D30047.epilog


#endif
