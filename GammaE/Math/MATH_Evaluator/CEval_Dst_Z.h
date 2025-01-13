//## begin module%3B7FD0D90355.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D90355.cm

//## begin module%3B7FD0D90355.cp preserve=no
//## end module%3B7FD0D90355.cp

//## Module: CEval_Dst_Z%3B7FD0D90355; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Dst_Z.h

#ifndef CEval_Dst_Z_h
#define CEval_Dst_Z_h 1

//## begin module%3B7FD0D90355.additionalIncludes preserve=no
//## end module%3B7FD0D90355.additionalIncludes

//## begin module%3B7FD0D90355.includes preserve=yes
//## end module%3B7FD0D90355.includes

// CEvaluator
#include "Math\MATH_Evaluator\CEvaluator.h"
//## begin module%3B7FD0D90355.additionalDeclarations preserve=yes
//## end module%3B7FD0D90355.additionalDeclarations


//## begin CEval_Dst_Z%3B7FD0D90355.preface preserve=yes
//## end CEval_Dst_Z%3B7FD0D90355.preface

//## Class: CEval_Dst_Z%3B7FD0D90355
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Dst_Z : public CEvaluator  //## Inherits: <unnamed>%3B7FD0D90354
{
  //## begin CEval_Dst_Z%3B7FD0D90355.initialDeclarations preserve=yes
  //## end CEval_Dst_Z%3B7FD0D90355.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Dst_Z();

    //## Destructor (generated)
      ~CEval_Dst_Z();


    //## Other Operations (specified)
      //## Operation: GetValue%998231892
      virtual float GetValue ();

      //## Operation: SetZ%998231893
      void SetZ (float Z);

    // Additional Public Declarations
      //## begin CEval_Dst_Z%3B7FD0D90355.public preserve=yes
      //## end CEval_Dst_Z%3B7FD0D90355.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Dst_Z%3B7FD0D90355.protected preserve=yes
      //## end CEval_Dst_Z%3B7FD0D90355.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Dst_Z%3B7FD0D90355.private preserve=yes
      //## end CEval_Dst_Z%3B7FD0D90355.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Dst_Z%3B7FD0D90355.implementation preserve=yes
      //## end CEval_Dst_Z%3B7FD0D90355.implementation

};

//## begin CEval_Dst_Z%3B7FD0D90355.postscript preserve=yes
//## end CEval_Dst_Z%3B7FD0D90355.postscript

// Class CEval_Dst_Z 

//## begin module%3B7FD0D90355.epilog preserve=yes
//## end module%3B7FD0D90355.epilog


#endif
