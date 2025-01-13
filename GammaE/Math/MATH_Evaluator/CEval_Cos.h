//## begin module%3B7FD0D9039F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D9039F.cm

//## begin module%3B7FD0D9039F.cp preserve=no
//## end module%3B7FD0D9039F.cp

//## Module: CEval_Cos%3B7FD0D9039F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Cos.h

#ifndef CEval_Cos_h
#define CEval_Cos_h 1

//## begin module%3B7FD0D9039F.additionalIncludes preserve=no
//## end module%3B7FD0D9039F.additionalIncludes

//## begin module%3B7FD0D9039F.includes preserve=yes
//## end module%3B7FD0D9039F.includes

// CEval_Periodic
#include "Math\MATH_Evaluator\CEval_Periodic.h"
//## begin module%3B7FD0D9039F.additionalDeclarations preserve=yes
#ifndef cosf
#define cosf cos
#endif

#ifndef sinf
#define sinf sin
#endif
//## end module%3B7FD0D9039F.additionalDeclarations


//## begin CEval_Cos%3B7FD0D9039F.preface preserve=yes
//## end CEval_Cos%3B7FD0D9039F.preface

//## Class: CEval_Cos%3B7FD0D9039F
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Cos : public CEval_Periodic  //## Inherits: <unnamed>%3B7FD0D9039E
{
  //## begin CEval_Cos%3B7FD0D9039F.initialDeclarations preserve=yes
  //## end CEval_Cos%3B7FD0D9039F.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Cos();

    //## Destructor (generated)
      ~CEval_Cos();


    //## Other Operations (specified)
      //## Operation: GetValue%998231919
      virtual float GetValue ();

    // Additional Public Declarations
      //## begin CEval_Cos%3B7FD0D9039F.public preserve=yes
      //## end CEval_Cos%3B7FD0D9039F.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Cos%3B7FD0D9039F.protected preserve=yes
      //## end CEval_Cos%3B7FD0D9039F.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Cos%3B7FD0D9039F.private preserve=yes
      //## end CEval_Cos%3B7FD0D9039F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Cos%3B7FD0D9039F.implementation preserve=yes
      //## end CEval_Cos%3B7FD0D9039F.implementation

};

//## begin CEval_Cos%3B7FD0D9039F.postscript preserve=yes
//## end CEval_Cos%3B7FD0D9039F.postscript

// Class CEval_Cos 


//## Other Operations (inline)
inline float CEval_Cos::GetValue ()
{
  //## begin CEval_Cos::GetValue%998231919.body preserve=yes
	assert (Amplitude && "Evaluator with NULL Amplitude param");
	assert (FreqMult  && "Evaluator with NULL Frequency param");
	assert (Phase     && "Evaluator with NULL Phase param");

    return( Amplitude->GetValue()*(float)cosf(FreqMult->GetValue()*Phase->GetValue()) );

  //## end CEval_Cos::GetValue%998231919.body
}

//## begin module%3B7FD0D9039F.epilog preserve=yes
//## end module%3B7FD0D9039F.epilog


#endif
