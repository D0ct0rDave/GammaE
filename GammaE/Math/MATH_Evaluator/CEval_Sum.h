//## begin module%3B7FD0D90377.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D90377.cm

//## begin module%3B7FD0D90377.cp preserve=no
//## end module%3B7FD0D90377.cp

//## Module: CEval_Sum%3B7FD0D90377; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Sum.h

#ifndef CEval_Sum_h
#define CEval_Sum_h 1

//## begin module%3B7FD0D90377.additionalIncludes preserve=no
//## end module%3B7FD0D90377.additionalIncludes

//## begin module%3B7FD0D90377.includes preserve=yes
//## end module%3B7FD0D90377.includes

// CEval_Binary
#include "Math\MATH_Evaluator\CEval_Binary.h"
//## begin module%3B7FD0D90377.additionalDeclarations preserve=yes
//## end module%3B7FD0D90377.additionalDeclarations


//## begin CEval_Sum%3B7FD0D90377.preface preserve=yes
//## end CEval_Sum%3B7FD0D90377.preface

//## Class: CEval_Sum%3B7FD0D90377
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Sum : public CEval_Binary  //## Inherits: <unnamed>%3B7FD0D90376
{
  //## begin CEval_Sum%3B7FD0D90377.initialDeclarations preserve=yes
  //## end CEval_Sum%3B7FD0D90377.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Sum();

    //## Destructor (generated)
      ~CEval_Sum();


    //## Other Operations (specified)
      //## Operation: GetValue%998231902
      virtual float GetValue ();

    // Additional Public Declarations
      //## begin CEval_Sum%3B7FD0D90377.public preserve=yes
      //## end CEval_Sum%3B7FD0D90377.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Sum%3B7FD0D90377.protected preserve=yes
      //## end CEval_Sum%3B7FD0D90377.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Sum%3B7FD0D90377.private preserve=yes
      //## end CEval_Sum%3B7FD0D90377.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Sum%3B7FD0D90377.implementation preserve=yes
      //## end CEval_Sum%3B7FD0D90377.implementation

};

//## begin CEval_Sum%3B7FD0D90377.postscript preserve=yes
//## end CEval_Sum%3B7FD0D90377.postscript

// Class CEval_Sum 


//## Other Operations (inline)
inline float CEval_Sum::GetValue ()
{
  //## begin CEval_Sum::GetValue%998231902.body preserve=yes
	return (OperandA->GetValue() + OperandB->GetValue() );
  //## end CEval_Sum::GetValue%998231902.body
}

//## begin module%3B7FD0D90377.epilog preserve=yes
//## end module%3B7FD0D90377.epilog


#endif
