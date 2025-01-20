//## begin module%3B7FD0D90349.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D90349.cm

//## begin module%3B7FD0D90349.cp preserve=no
//## end module%3B7FD0D90349.cp

//## Module: CEval_Dist%3B7FD0D90349; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Dist.h

#ifndef CEval_Dist_h
#define CEval_Dist_h 1

//## begin module%3B7FD0D90349.additionalIncludes preserve=no
//## end module%3B7FD0D90349.additionalIncludes

//## begin module%3B7FD0D90349.includes preserve=yes
//## end module%3B7FD0D90349.includes

// CEvaluator
#include "Math\MATH_Evaluator\CEvaluator.h"
// CVect3
#include "Math\MATH_Vector\CVect3.h"
//## begin module%3B7FD0D90349.additionalDeclarations preserve=yes
//## end module%3B7FD0D90349.additionalDeclarations


//## begin CEval_Dist%3B7FD0D90349.preface preserve=yes
//## end CEval_Dist%3B7FD0D90349.preface

//## Class: CEval_Dist%3B7FD0D90349
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B7FD25200F3;CVect3 { -> }

class CEval_Dist : public CEvaluator  //## Inherits: <unnamed>%3B7FD0D90348
{
  //## begin CEval_Dist%3B7FD0D90349.initialDeclarations preserve=yes
  //## end CEval_Dist%3B7FD0D90349.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Dist();

    //## Destructor (generated)
      ~CEval_Dist();


    //## Other Operations (specified)
      //## Operation: GetValue%998231896
      virtual float GetValue ();

      //## Operation: SetPoint%998231897
      void SetPoint (CVect3* Point);

    // Additional Public Declarations
      //## begin CEval_Dist%3B7FD0D90349.public preserve=yes
      //## end CEval_Dist%3B7FD0D90349.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Dist%3B7FD0D90349.protected preserve=yes
      //## end CEval_Dist%3B7FD0D90349.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Pos%3B7FD24A000C
      //## begin CEval_Dist::Pos%3B7FD24A000C.attr preserve=no  private: CVect3 * {UA} 
      CVect3 *Pos;
      //## end CEval_Dist::Pos%3B7FD24A000C.attr

    // Additional Private Declarations
      //## begin CEval_Dist%3B7FD0D90349.private preserve=yes
      //## end CEval_Dist%3B7FD0D90349.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Dist%3B7FD0D90349.implementation preserve=yes
      //## end CEval_Dist%3B7FD0D90349.implementation

};

//## begin CEval_Dist%3B7FD0D90349.postscript preserve=yes
//## end CEval_Dist%3B7FD0D90349.postscript

// Class CEval_Dist 

//## begin module%3B7FD0D90349.epilog preserve=yes
//## end module%3B7FD0D90349.epilog


#endif
