//## begin module%3B7FD0D9033C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D9033C.cm

//## begin module%3B7FD0D9033C.cp preserve=no
//## end module%3B7FD0D9033C.cp

//## Module: CEvaluator%3B7FD0D9033C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEvaluator.h

#ifndef CEvaluator_h
#define CEvaluator_h 1

//## begin module%3B7FD0D9033C.additionalIncludes preserve=no
//## end module%3B7FD0D9033C.additionalIncludes

//## begin module%3B7FD0D9033C.includes preserve=yes
#include <math.h>
#include <assert.h>
//## end module%3B7FD0D9033C.includes

//## begin module%3B7FD0D9033C.additionalDeclarations preserve=yes
//## end module%3B7FD0D9033C.additionalDeclarations


//## begin CEvaluator%3B7FD0D9033C.preface preserve=yes
//## end CEvaluator%3B7FD0D9033C.preface

//## Class: CEvaluator%3B7FD0D9033C
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEvaluator 
{
  //## begin CEvaluator%3B7FD0D9033C.initialDeclarations preserve=yes
  //## end CEvaluator%3B7FD0D9033C.initialDeclarations

  public:
    //## Constructors (generated)
      CEvaluator();

    //## Destructor (generated)
      ~CEvaluator();


    //## Other Operations (specified)
      //## Operation: GetValue%998231887
      virtual float GetValue () = 0;

    // Additional Public Declarations
      //## begin CEvaluator%3B7FD0D9033C.public preserve=yes
      //## end CEvaluator%3B7FD0D9033C.public

  protected:
    // Additional Protected Declarations
      //## begin CEvaluator%3B7FD0D9033C.protected preserve=yes
      //## end CEvaluator%3B7FD0D9033C.protected

  private:
    // Additional Private Declarations
      //## begin CEvaluator%3B7FD0D9033C.private preserve=yes
      //## end CEvaluator%3B7FD0D9033C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEvaluator%3B7FD0D9033C.implementation preserve=yes
      //## end CEvaluator%3B7FD0D9033C.implementation

};

//## begin CEvaluator%3B7FD0D9033C.postscript preserve=yes
//## end CEvaluator%3B7FD0D9033C.postscript

// Class CEvaluator 

//## begin module%3B7FD0D9033C.epilog preserve=yes
//## end module%3B7FD0D9033C.epilog


#endif
