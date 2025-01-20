//## begin module%3B7FD0D9038B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D9038B.cm

//## begin module%3B7FD0D9038B.cp preserve=no
//## end module%3B7FD0D9038B.cp

//## Module: CEval_Sin%3B7FD0D9038B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Sin.h

#ifndef CEval_Sin_h
#define CEval_Sin_h 1

//## begin module%3B7FD0D9038B.additionalIncludes preserve=no
//## end module%3B7FD0D9038B.additionalIncludes

//## begin module%3B7FD0D9038B.includes preserve=yes
//## end module%3B7FD0D9038B.includes

// CEval_Periodic
#include "Math\MATH_Evaluator\CEval_Periodic.h"
//## begin module%3B7FD0D9038B.additionalDeclarations preserve=yes
#ifndef cosf
#define cosf cos
#endif

#ifndef sinf
#define sinf sin
#endif
//## end module%3B7FD0D9038B.additionalDeclarations


//## begin CEval_Sin%3B7FD0D9038B.preface preserve=yes
//## end CEval_Sin%3B7FD0D9038B.preface

//## Class: CEval_Sin%3B7FD0D9038B
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Sin : public CEval_Periodic  //## Inherits: <unnamed>%3B7FD0D9038A
{
  //## begin CEval_Sin%3B7FD0D9038B.initialDeclarations preserve=yes
  //## end CEval_Sin%3B7FD0D9038B.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Sin();

    //## Destructor (generated)
      ~CEval_Sin();


    //## Other Operations (specified)
      //## Operation: GetValue%998231927
      virtual float GetValue ();

    // Additional Public Declarations
      //## begin CEval_Sin%3B7FD0D9038B.public preserve=yes
      //## end CEval_Sin%3B7FD0D9038B.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Sin%3B7FD0D9038B.protected preserve=yes
      //## end CEval_Sin%3B7FD0D9038B.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Sin%3B7FD0D9038B.private preserve=yes
      //## end CEval_Sin%3B7FD0D9038B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Sin%3B7FD0D9038B.implementation preserve=yes
      //## end CEval_Sin%3B7FD0D9038B.implementation

};

//## begin CEval_Sin%3B7FD0D9038B.postscript preserve=yes
//## end CEval_Sin%3B7FD0D9038B.postscript

// Class CEval_Sin 


//## Other Operations (inline)
inline float CEval_Sin::GetValue ()
{
  //## begin CEval_Sin::GetValue%998231927.body preserve=yes
  	assert (Amplitude && "Evaluator with NULL Amplitude param");
	assert (FreqMult  && "Evaluator with NULL Frequency param");
	assert (Phase     && "Evaluator with NULL Phase param");

	return( Amplitude->GetValue()*(float)sinf(FreqMult->GetValue()*Phase->GetValue()) );
  //## end CEval_Sin::GetValue%998231927.body
}

//## begin module%3B7FD0D9038B.epilog preserve=yes
//## end module%3B7FD0D9038B.epilog


#endif
