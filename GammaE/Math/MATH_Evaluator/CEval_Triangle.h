//## begin module%3B7FD0D903A9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D903A9.cm

//## begin module%3B7FD0D903A9.cp preserve=no
//## end module%3B7FD0D903A9.cp

//## Module: CEval_Triangle%3B7FD0D903A9; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Triangle.h

#ifndef CEval_Triangle_h
#define CEval_Triangle_h 1

//## begin module%3B7FD0D903A9.additionalIncludes preserve=no
//## end module%3B7FD0D903A9.additionalIncludes

//## begin module%3B7FD0D903A9.includes preserve=yes
//## end module%3B7FD0D903A9.includes

// CEval_Periodic
#include "Math\MATH_Evaluator\CEval_Periodic.h"
//## begin module%3B7FD0D903A9.additionalDeclarations preserve=yes
//## end module%3B7FD0D903A9.additionalDeclarations


//## begin CEval_Triangle%3B7FD0D903A9.preface preserve=yes
//## end CEval_Triangle%3B7FD0D903A9.preface

//## Class: CEval_Triangle%3B7FD0D903A9
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Triangle : public CEval_Periodic  //## Inherits: <unnamed>%3B7FD0D903A8
{
  //## begin CEval_Triangle%3B7FD0D903A9.initialDeclarations preserve=yes
  //## end CEval_Triangle%3B7FD0D903A9.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Triangle();

    //## Destructor (generated)
      ~CEval_Triangle();


    //## Other Operations (specified)
      //## Operation: GetValue%998231915
      virtual float GetValue ();

    // Additional Public Declarations
      //## begin CEval_Triangle%3B7FD0D903A9.public preserve=yes
      //## end CEval_Triangle%3B7FD0D903A9.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Triangle%3B7FD0D903A9.protected preserve=yes
      //## end CEval_Triangle%3B7FD0D903A9.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Triangle%3B7FD0D903A9.private preserve=yes
      //## end CEval_Triangle%3B7FD0D903A9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Triangle%3B7FD0D903A9.implementation preserve=yes
      //## end CEval_Triangle%3B7FD0D903A9.implementation

};

//## begin CEval_Triangle%3B7FD0D903A9.postscript preserve=yes
//## end CEval_Triangle%3B7FD0D903A9.postscript

// Class CEval_Triangle 


//## Other Operations (inline)
inline float CEval_Triangle::GetValue ()
{
  //## begin CEval_Triangle::GetValue%998231915.body preserve=yes
	return (0);	
  //## end CEval_Triangle::GetValue%998231915.body
}

//## begin module%3B7FD0D903A9.epilog preserve=yes
//## end module%3B7FD0D903A9.epilog


#endif
