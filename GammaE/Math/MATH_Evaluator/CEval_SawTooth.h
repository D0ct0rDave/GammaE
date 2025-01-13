//## begin module%3B7FD0D903B3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D903B3.cm

//## begin module%3B7FD0D903B3.cp preserve=no
//## end module%3B7FD0D903B3.cp

//## Module: CEval_SawTooth%3B7FD0D903B3; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_SawTooth.h

#ifndef CEval_SawTooth_h
#define CEval_SawTooth_h 1

//## begin module%3B7FD0D903B3.additionalIncludes preserve=no
//## end module%3B7FD0D903B3.additionalIncludes

//## begin module%3B7FD0D903B3.includes preserve=yes
//## end module%3B7FD0D903B3.includes

// CEval_Periodic
#include "Math\MATH_Evaluator\CEval_Periodic.h"
//## begin module%3B7FD0D903B3.additionalDeclarations preserve=yes
//## end module%3B7FD0D903B3.additionalDeclarations


//## begin CEval_SawTooth%3B7FD0D903B3.preface preserve=yes
//## end CEval_SawTooth%3B7FD0D903B3.preface

//## Class: CEval_SawTooth%3B7FD0D903B3
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_SawTooth : public CEval_Periodic  //## Inherits: <unnamed>%3B7FD0D903B2
{
  //## begin CEval_SawTooth%3B7FD0D903B3.initialDeclarations preserve=yes
  //## end CEval_SawTooth%3B7FD0D903B3.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_SawTooth();

    //## Destructor (generated)
      ~CEval_SawTooth();


    //## Other Operations (specified)
      //## Operation: GetValue%998231911
      virtual float GetValue ();

    // Additional Public Declarations
      //## begin CEval_SawTooth%3B7FD0D903B3.public preserve=yes
      //## end CEval_SawTooth%3B7FD0D903B3.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_SawTooth%3B7FD0D903B3.protected preserve=yes
      //## end CEval_SawTooth%3B7FD0D903B3.protected

  private:
    // Additional Private Declarations
      //## begin CEval_SawTooth%3B7FD0D903B3.private preserve=yes
      //## end CEval_SawTooth%3B7FD0D903B3.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_SawTooth%3B7FD0D903B3.implementation preserve=yes
      //## end CEval_SawTooth%3B7FD0D903B3.implementation

};

//## begin CEval_SawTooth%3B7FD0D903B3.postscript preserve=yes
//## end CEval_SawTooth%3B7FD0D903B3.postscript

// Class CEval_SawTooth 


//## Other Operations (inline)
inline float CEval_SawTooth::GetValue ()
{
  //## begin CEval_SawTooth::GetValue%998231911.body preserve=yes
  	assert (Amplitude && "Evaluator with NULL Amplitude param");
	assert (FreqMult  && "Evaluator with NULL Frequency param");
	assert (Phase     && "Evaluator with NULL Phase param");

	//if (FreqMult->GetValue()*
	return (0);
  //## end CEval_SawTooth::GetValue%998231911.body
}

//## begin module%3B7FD0D903B3.epilog preserve=yes
//## end module%3B7FD0D903B3.epilog


#endif
