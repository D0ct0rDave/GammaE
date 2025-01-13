//## begin module%3B7FD0D9036F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D9036F.cm

//## begin module%3B7FD0D9036F.cp preserve=no
//## end module%3B7FD0D9036F.cp

//## Module: CEval_Mult%3B7FD0D9036F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Mult.h

#ifndef CEval_Mult_h
#define CEval_Mult_h 1

//## begin module%3B7FD0D9036F.additionalIncludes preserve=no
//## end module%3B7FD0D9036F.additionalIncludes

//## begin module%3B7FD0D9036F.includes preserve=yes
//## end module%3B7FD0D9036F.includes

// CEval_Binary
#include "Math\MATH_Evaluator\CEval_Binary.h"
//## begin module%3B7FD0D9036F.additionalDeclarations preserve=yes
//## end module%3B7FD0D9036F.additionalDeclarations


//## begin CEval_Mult%3B7FD0D9036F.preface preserve=yes
//## end CEval_Mult%3B7FD0D9036F.preface

//## Class: CEval_Mult%3B7FD0D9036F
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Mult : public CEval_Binary  //## Inherits: <unnamed>%3B7FD0D9036E
{
  //## begin CEval_Mult%3B7FD0D9036F.initialDeclarations preserve=yes
  //## end CEval_Mult%3B7FD0D9036F.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Mult();

    //## Destructor (generated)
      ~CEval_Mult();


    //## Other Operations (specified)
      //## Operation: GetValue%998231905
      virtual float GetValue ();

    // Additional Public Declarations
      //## begin CEval_Mult%3B7FD0D9036F.public preserve=yes
      //## end CEval_Mult%3B7FD0D9036F.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Mult%3B7FD0D9036F.protected preserve=yes
      //## end CEval_Mult%3B7FD0D9036F.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Mult%3B7FD0D9036F.private preserve=yes
      //## end CEval_Mult%3B7FD0D9036F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Mult%3B7FD0D9036F.implementation preserve=yes
      //## end CEval_Mult%3B7FD0D9036F.implementation

};

//## begin CEval_Mult%3B7FD0D9036F.postscript preserve=yes
//## end CEval_Mult%3B7FD0D9036F.postscript

// Class CEval_Mult 


//## Other Operations (inline)
inline float CEval_Mult::GetValue ()
{
  //## begin CEval_Mult::GetValue%998231905.body preserve=yes
	return (OperandA->GetValue() * OperandB->GetValue() );
  //## end CEval_Mult::GetValue%998231905.body
}

//## begin module%3B7FD0D9036F.epilog preserve=yes
//## end module%3B7FD0D9036F.epilog


#endif
