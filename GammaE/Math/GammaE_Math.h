//## begin module%3BD8A07F039B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD8A07F039B.cm

//## begin module%3BD8A07F039B.cp preserve=no
//## end module%3BD8A07F039B.cp

//## Module: GammaE_Math%3BD8A07F039B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\GammaE_Math.h

#ifndef GammaE_Math_h
#define GammaE_Math_h 1

//## begin module%3BD8A07F039B.additionalIncludes preserve=no
//## end module%3BD8A07F039B.additionalIncludes

//## begin module%3BD8A07F039B.includes preserve=yes
#include "MMath.h"
//## end module%3BD8A07F039B.includes

// GammaE_Math_Evaluators
#include "Math\MATH_Evaluator\GammaE_Math_Evaluators.h"
// CPlane
#include "Math\MATH_Plane\CPlane.h"
// CVect2
#include "Math\MATH_Vector\CVect2.h"
// CVect3
#include "Math\MATH_Vector\CVect3.h"
// CVect4
#include "Math\MATH_Vector\CVect4.h"
// CRay
#include "Math\MATH_Ray\CRay.h"
// CMatrix4x4
#include "Math\MATH_Matrix\CMatrix4x4.h"
// CTriangle
#include "Math\MATH_Triangle\CTriangle.h"
// CQuaternion
#include "Math\MATH_Quaternion\CQuaternion.h"
// MATH_Utils
#include "Math\MATH_Other\MATH_Utils.h"
// MATH_Common
#include "Math\MATH_Other\MATH_Common.h"
// CSegment
#include "Math\MATH_Segment\CSegment.h"
//## begin module%3BD8A07F039B.additionalDeclarations preserve=yes
//## end module%3BD8A07F039B.additionalDeclarations


//## begin GammaE_Math%3BD8A07F039B.preface preserve=yes
//## end GammaE_Math%3BD8A07F039B.preface

//## Class: GammaE_Math%3BD8A07F039B
//## Category: Math%3A9AD9290262
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BD8A0A00280;GammaE_Math_Evaluators { -> }
//## Uses: <unnamed>%3BD8A0A20283;CQuaternion { -> }
//## Uses: <unnamed>%3BD8A0A403DA;CVect2 { -> }
//## Uses: <unnamed>%3BD8A0A602ED;CVect4 { -> }
//## Uses: <unnamed>%3BD8A0A900A2;CMatrix4x4 { -> }
//## Uses: <unnamed>%3BD8A0AB0005;CVect3 { -> }
//## Uses: <unnamed>%3BD8A0AD0275;CPlane { -> }
//## Uses: <unnamed>%3BD8A0B002AB;CRay { -> }
//## Uses: <unnamed>%3C080D81010D;MATH_Utils { -> }
//## Uses: <unnamed>%3C275F07031C;CTriangle { -> }
//## Uses: <unnamed>%3C275F20008D;MATH_Common { -> }
//## Uses: <unnamed>%3CC5D5E70255;CSegment { -> }

class GammaE_Math 
{
  //## begin GammaE_Math%3BD8A07F039B.initialDeclarations preserve=yes
  //## end GammaE_Math%3BD8A07F039B.initialDeclarations

  public:
    //## Constructors (generated)
      GammaE_Math();

    //## Destructor (generated)
      ~GammaE_Math();

    // Additional Public Declarations
      //## begin GammaE_Math%3BD8A07F039B.public preserve=yes
      //## end GammaE_Math%3BD8A07F039B.public

  protected:
    // Additional Protected Declarations
      //## begin GammaE_Math%3BD8A07F039B.protected preserve=yes
      //## end GammaE_Math%3BD8A07F039B.protected

  private:
    // Additional Private Declarations
      //## begin GammaE_Math%3BD8A07F039B.private preserve=yes
      //## end GammaE_Math%3BD8A07F039B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin GammaE_Math%3BD8A07F039B.implementation preserve=yes
      //## end GammaE_Math%3BD8A07F039B.implementation

};

//## begin GammaE_Math%3BD8A07F039B.postscript preserve=yes
//## end GammaE_Math%3BD8A07F039B.postscript

// Class GammaE_Math 

//## begin module%3BD8A07F039B.epilog preserve=yes
//## end module%3BD8A07F039B.epilog


#endif
