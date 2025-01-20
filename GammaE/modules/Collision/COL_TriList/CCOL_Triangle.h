//## begin module%3CCCFF5E0391.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CCCFF5E0391.cm

//## begin module%3CCCFF5E0391.cp preserve=no
//## end module%3CCCFF5E0391.cp

//## Module: CCOL_Triangle%3CCCFF5E0391; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_TriList\CCOL_Triangle.h

#ifndef CCOL_Triangle_h
#define CCOL_Triangle_h 1

//## begin module%3CCCFF5E0391.additionalIncludes preserve=no
//## end module%3CCCFF5E0391.additionalIncludes

//## begin module%3CCCFF5E0391.includes preserve=yes
//## end module%3CCCFF5E0391.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3CCCFF5E0391.additionalDeclarations preserve=yes
//## end module%3CCCFF5E0391.additionalDeclarations


//## begin CCOL_Triangle%3CCCFF5E0391.preface preserve=yes
//## end CCOL_Triangle%3CCCFF5E0391.preface

//## Class: CCOL_Triangle%3CCCFF5E0391
//## Category: Collision::COL_TriList%3C1BEBCD00BD
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1D05B0000E;GammaE_Math { -> }

class CCOL_Triangle 
{
  //## begin CCOL_Triangle%3CCCFF5E0391.initialDeclarations preserve=yes
  //## end CCOL_Triangle%3CCCFF5E0391.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_Triangle();

    //## Destructor (generated)
      ~CCOL_Triangle();

    // Data Members for Class Attributes

      //## Attribute: oVXs%3CCCFF6A0317
      //## begin CCOL_Triangle::oVXs%3CCCFF6A0317.attr preserve=no  public: CVect3[3] {UA} 
      CVect3 oVXs[3];
      //## end CCOL_Triangle::oVXs%3CCCFF6A0317.attr

      //## Attribute: oVN%3CCCFF77012B
      //## begin CCOL_Triangle::oVN%3CCCFF77012B.attr preserve=no  public: CVect3 {UA} 
      CVect3 oVN;
      //## end CCOL_Triangle::oVN%3CCCFF77012B.attr

      //## Attribute: iMat%3CCCFF8B031E
      //## begin CCOL_Triangle::iMat%3CCCFF8B031E.attr preserve=no  public: int {UA} -1
      int iMat;
      //## end CCOL_Triangle::iMat%3CCCFF8B031E.attr

      //## Attribute: fDelta%3CCCFF8500B2
      //## begin CCOL_Triangle::fDelta%3CCCFF8500B2.attr preserve=no  public: float {UA} 0.0f
      float fDelta;
      //## end CCOL_Triangle::fDelta%3CCCFF8500B2.attr

    // Additional Public Declarations
      //## begin CCOL_Triangle%3CCCFF5E0391.public preserve=yes
      //## end CCOL_Triangle%3CCCFF5E0391.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_Triangle%3CCCFF5E0391.protected preserve=yes
      //## end CCOL_Triangle%3CCCFF5E0391.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_Triangle%3CCCFF5E0391.private preserve=yes
      //## end CCOL_Triangle%3CCCFF5E0391.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_Triangle%3CCCFF5E0391.implementation preserve=yes
      //## end CCOL_Triangle%3CCCFF5E0391.implementation

};

//## begin CCOL_Triangle%3CCCFF5E0391.postscript preserve=yes
//## end CCOL_Triangle%3CCCFF5E0391.postscript

// Class CCOL_Triangle 

//## begin module%3CCCFF5E0391.epilog preserve=yes
//## end module%3CCCFF5E0391.epilog


#endif
