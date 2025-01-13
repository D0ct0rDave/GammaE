//## begin module%3B7FD0D9033F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D9033F.cm

//## begin module%3B7FD0D9033F.cp preserve=no
//## end module%3B7FD0D9033F.cp

//## Module: CEval_Dst_X%3B7FD0D9033F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Dst_X.h

#ifndef CEval_Dst_X_h
#define CEval_Dst_X_h 1

//## begin module%3B7FD0D9033F.additionalIncludes preserve=no
//## end module%3B7FD0D9033F.additionalIncludes

//## begin module%3B7FD0D9033F.includes preserve=yes
//## end module%3B7FD0D9033F.includes

// CEvaluator
#include "Math\MATH_Evaluator\CEvaluator.h"
//## begin module%3B7FD0D9033F.additionalDeclarations preserve=yes
//## end module%3B7FD0D9033F.additionalDeclarations


//## begin CEval_Dst_X%3B7FD0D9033F.preface preserve=yes
//## end CEval_Dst_X%3B7FD0D9033F.preface

//## Class: CEval_Dst_X%3B7FD0D9033F
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Dst_X : public CEvaluator  //## Inherits: <unnamed>%3B7FD0D9033E
{
  //## begin CEval_Dst_X%3B7FD0D9033F.initialDeclarations preserve=yes
  //## end CEval_Dst_X%3B7FD0D9033F.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Dst_X();

    //## Destructor (generated)
      ~CEval_Dst_X();


    //## Other Operations (specified)
      //## Operation: GetValue%998231885
      virtual float GetValue ();

      //## Operation: SetX%998231886
      void SetX (float X);

    // Additional Public Declarations
      //## begin CEval_Dst_X%3B7FD0D9033F.public preserve=yes
      //## end CEval_Dst_X%3B7FD0D9033F.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Dst_X%3B7FD0D9033F.protected preserve=yes
      //## end CEval_Dst_X%3B7FD0D9033F.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Dst_X%3B7FD0D9033F.private preserve=yes
      //## end CEval_Dst_X%3B7FD0D9033F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Dst_X%3B7FD0D9033F.implementation preserve=yes
      //## end CEval_Dst_X%3B7FD0D9033F.implementation

};

//## begin CEval_Dst_X%3B7FD0D9033F.postscript preserve=yes
//## end CEval_Dst_X%3B7FD0D9033F.postscript

// Class CEval_Dst_X 

//## begin module%3B7FD0D9033F.epilog preserve=yes
//## end module%3B7FD0D9033F.epilog


#endif
