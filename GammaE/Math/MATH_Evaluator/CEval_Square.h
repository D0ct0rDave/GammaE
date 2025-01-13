//## begin module%3B7FD0D90395.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D90395.cm

//## begin module%3B7FD0D90395.cp preserve=no
//## end module%3B7FD0D90395.cp

//## Module: CEval_Square%3B7FD0D90395; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Square.h

#ifndef CEval_Square_h
#define CEval_Square_h 1

//## begin module%3B7FD0D90395.additionalIncludes preserve=no
//## end module%3B7FD0D90395.additionalIncludes

//## begin module%3B7FD0D90395.includes preserve=yes
//## end module%3B7FD0D90395.includes

// CEval_Periodic
#include "Math\MATH_Evaluator\CEval_Periodic.h"
//## begin module%3B7FD0D90395.additionalDeclarations preserve=yes
//## end module%3B7FD0D90395.additionalDeclarations


//## begin CEval_Square%3B7FD0D90395.preface preserve=yes
//## end CEval_Square%3B7FD0D90395.preface

//## Class: CEval_Square%3B7FD0D90395
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Square : public CEval_Periodic  //## Inherits: <unnamed>%3B7FD0D90394
{
  //## begin CEval_Square%3B7FD0D90395.initialDeclarations preserve=yes
  //## end CEval_Square%3B7FD0D90395.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Square();

    //## Destructor (generated)
      ~CEval_Square();


    //## Other Operations (specified)
      //## Operation: GetValue%998231923
      virtual float GetValue ();

    // Additional Public Declarations
      //## begin CEval_Square%3B7FD0D90395.public preserve=yes
      //## end CEval_Square%3B7FD0D90395.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Square%3B7FD0D90395.protected preserve=yes
      //## end CEval_Square%3B7FD0D90395.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Square%3B7FD0D90395.private preserve=yes
      //## end CEval_Square%3B7FD0D90395.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Square%3B7FD0D90395.implementation preserve=yes
      //## end CEval_Square%3B7FD0D90395.implementation

};

//## begin CEval_Square%3B7FD0D90395.postscript preserve=yes
//## end CEval_Square%3B7FD0D90395.postscript

// Class CEval_Square 


//## Other Operations (inline)
inline float CEval_Square::GetValue ()
{
  //## begin CEval_Square::GetValue%998231923.body preserve=yes
  	assert (Amplitude && "Evaluator with NULL Amplitude param");
	assert (FreqMult  && "Evaluator with NULL Frequency param");
	assert (Phase     && "Evaluator with NULL Phase param");
	
	return (0);
  //## end CEval_Square::GetValue%998231923.body
}

//## begin module%3B7FD0D90395.epilog preserve=yes
//## end module%3B7FD0D90395.epilog


#endif
