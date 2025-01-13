//## begin module%3B7FD0D90367.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D90367.cm

//## begin module%3B7FD0D90367.cp preserve=no
//## end module%3B7FD0D90367.cp

//## Module: CEval_Binary%3B7FD0D90367; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Binary.h

#ifndef CEval_Binary_h
#define CEval_Binary_h 1

//## begin module%3B7FD0D90367.additionalIncludes preserve=no
//## end module%3B7FD0D90367.additionalIncludes

//## begin module%3B7FD0D90367.includes preserve=yes
//## end module%3B7FD0D90367.includes

// CEvaluator
#include "Math\MATH_Evaluator\CEvaluator.h"
//## begin module%3B7FD0D90367.additionalDeclarations preserve=yes
//## end module%3B7FD0D90367.additionalDeclarations


//## begin CEval_Binary%3B7FD0D90367.preface preserve=yes
//## end CEval_Binary%3B7FD0D90367.preface

//## Class: CEval_Binary%3B7FD0D90367
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Binary : public CEvaluator  //## Inherits: <unnamed>%3B7FD0D90366
{
  //## begin CEval_Binary%3B7FD0D90367.initialDeclarations preserve=yes
  //## end CEval_Binary%3B7FD0D90367.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Binary();

    //## Destructor (generated)
      ~CEval_Binary();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: OperandA%3B7FD0D9036C
      CEvaluator * GetOperandA ();
      void SetOperandA (CEvaluator * value);

      //## Attribute: OperandB%3B7FD0D9036D
      CEvaluator * GetOperandB ();
      void SetOperandB (CEvaluator * value);

    // Data Members for Class Attributes

      //## begin CEval_Binary::OperandA%3B7FD0D9036C.attr preserve=no  public: CEvaluator * {UA} NULL
      CEvaluator *OperandA;
      //## end CEval_Binary::OperandA%3B7FD0D9036C.attr

      //## begin CEval_Binary::OperandB%3B7FD0D9036D.attr preserve=no  public: CEvaluator * {UA} NULL
      CEvaluator *OperandB;
      //## end CEval_Binary::OperandB%3B7FD0D9036D.attr

    // Additional Public Declarations
      //## begin CEval_Binary%3B7FD0D90367.public preserve=yes
      //## end CEval_Binary%3B7FD0D90367.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Binary%3B7FD0D90367.protected preserve=yes
      //## end CEval_Binary%3B7FD0D90367.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Binary%3B7FD0D90367.private preserve=yes
      //## end CEval_Binary%3B7FD0D90367.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Binary%3B7FD0D90367.implementation preserve=yes
      //## end CEval_Binary%3B7FD0D90367.implementation

};

//## begin CEval_Binary%3B7FD0D90367.postscript preserve=yes
//## end CEval_Binary%3B7FD0D90367.postscript

// Class CEval_Binary 

//## Get and Set Operations for Class Attributes (inline)

inline CEvaluator * CEval_Binary::GetOperandA ()
{
  //## begin CEval_Binary::GetOperandA%3B7FD0D9036C.get preserve=no
  return OperandA;
  //## end CEval_Binary::GetOperandA%3B7FD0D9036C.get
}

inline void CEval_Binary::SetOperandA (CEvaluator * value)
{
  //## begin CEval_Binary::SetOperandA%3B7FD0D9036C.set preserve=no
  OperandA = value;
  //## end CEval_Binary::SetOperandA%3B7FD0D9036C.set
}

inline CEvaluator * CEval_Binary::GetOperandB ()
{
  //## begin CEval_Binary::GetOperandB%3B7FD0D9036D.get preserve=no
  return OperandB;
  //## end CEval_Binary::GetOperandB%3B7FD0D9036D.get
}

inline void CEval_Binary::SetOperandB (CEvaluator * value)
{
  //## begin CEval_Binary::SetOperandB%3B7FD0D9036D.set preserve=no
  OperandB = value;
  //## end CEval_Binary::SetOperandB%3B7FD0D9036D.set
}

//## begin module%3B7FD0D90367.epilog preserve=yes
//## end module%3B7FD0D90367.epilog


#endif
