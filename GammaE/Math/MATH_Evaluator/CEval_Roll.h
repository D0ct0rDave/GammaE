//## begin module%3B7FD0D9035B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D9035B.cm

//## begin module%3B7FD0D9035B.cp preserve=no
//## end module%3B7FD0D9035B.cp

//## Module: CEval_Roll%3B7FD0D9035B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Roll.h

#ifndef CEval_Roll_h
#define CEval_Roll_h 1

//## begin module%3B7FD0D9035B.additionalIncludes preserve=no
//## end module%3B7FD0D9035B.additionalIncludes

//## begin module%3B7FD0D9035B.includes preserve=yes
//## end module%3B7FD0D9035B.includes

// CEvaluator
#include "Math\MATH_Evaluator\CEvaluator.h"
//## begin module%3B7FD0D9035B.additionalDeclarations preserve=yes
//## end module%3B7FD0D9035B.additionalDeclarations


//## begin CEval_Roll%3B7FD0D9035B.preface preserve=yes
//## end CEval_Roll%3B7FD0D9035B.preface

//## Class: CEval_Roll%3B7FD0D9035B
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Roll : public CEvaluator  //## Inherits: <unnamed>%3B7FD0D9035A
{
  //## begin CEval_Roll%3B7FD0D9035B.initialDeclarations preserve=yes
  //## end CEval_Roll%3B7FD0D9035B.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Roll();

    //## Destructor (generated)
      ~CEval_Roll();


    //## Other Operations (specified)
      //## Operation: GetValue%998231891
      virtual float GetValue ();

    // Additional Public Declarations
      //## begin CEval_Roll%3B7FD0D9035B.public preserve=yes
      //## end CEval_Roll%3B7FD0D9035B.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Roll%3B7FD0D9035B.protected preserve=yes
      //## end CEval_Roll%3B7FD0D9035B.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Roll%3B7FD0D9035B.private preserve=yes
      //## end CEval_Roll%3B7FD0D9035B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Roll%3B7FD0D9035B.implementation preserve=yes
      //## end CEval_Roll%3B7FD0D9035B.implementation

};

//## begin CEval_Roll%3B7FD0D9035B.postscript preserve=yes
//## end CEval_Roll%3B7FD0D9035B.postscript

// Class CEval_Roll 

//## begin module%3B7FD0D9035B.epilog preserve=yes
//## end module%3B7FD0D9035B.epilog


#endif
