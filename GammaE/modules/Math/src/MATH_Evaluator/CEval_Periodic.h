//## begin module%3B7FD0D90380.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D90380.cm

//## begin module%3B7FD0D90380.cp preserve=no
//## end module%3B7FD0D90380.cp

//## Module: CEval_Periodic%3B7FD0D90380; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Periodic.h

#ifndef CEval_Periodic_h
#define CEval_Periodic_h 1

//## begin module%3B7FD0D90380.additionalIncludes preserve=no
//## end module%3B7FD0D90380.additionalIncludes

//## begin module%3B7FD0D90380.includes preserve=yes
//## end module%3B7FD0D90380.includes

// CEvaluator
#include "Math\MATH_Evaluator\CEvaluator.h"
//## begin module%3B7FD0D90380.additionalDeclarations preserve=yes
//## end module%3B7FD0D90380.additionalDeclarations


//## begin CEval_Periodic%3B7FD0D90380.preface preserve=yes
//## end CEval_Periodic%3B7FD0D90380.preface

//## Class: CEval_Periodic%3B7FD0D90380
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Periodic : public CEvaluator  //## Inherits: <unnamed>%3B7FD0D9037F
{
  //## begin CEval_Periodic%3B7FD0D90380.initialDeclarations preserve=yes
  //## end CEval_Periodic%3B7FD0D90380.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Periodic();

    //## Destructor (generated)
      ~CEval_Periodic();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: Amplitude%3B7FD0D90387
      CEvaluator * GetAmplitude ();
      void SetAmplitude (CEvaluator * value);

      //## Attribute: Phase%3B7FD0D90388
      CEvaluator * GetPhase ();
      void SetPhase (CEvaluator * value);

      //## Attribute: FreqMult%3B7FD0D90389
      CEvaluator * GetFreqMult ();
      void SetFreqMult (CEvaluator * value);

    // Data Members for Class Attributes

      //## begin CEval_Periodic::Amplitude%3B7FD0D90387.attr preserve=no  public: CEvaluator * {UA} NULL
      CEvaluator *Amplitude;
      //## end CEval_Periodic::Amplitude%3B7FD0D90387.attr

      //## begin CEval_Periodic::Phase%3B7FD0D90388.attr preserve=no  public: CEvaluator * {UA} NULL
      CEvaluator *Phase;
      //## end CEval_Periodic::Phase%3B7FD0D90388.attr

      //## begin CEval_Periodic::FreqMult%3B7FD0D90389.attr preserve=no  public: CEvaluator * {UA} NULL
      CEvaluator *FreqMult;
      //## end CEval_Periodic::FreqMult%3B7FD0D90389.attr

    // Additional Public Declarations
      //## begin CEval_Periodic%3B7FD0D90380.public preserve=yes
      //## end CEval_Periodic%3B7FD0D90380.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Periodic%3B7FD0D90380.protected preserve=yes
      //## end CEval_Periodic%3B7FD0D90380.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Periodic%3B7FD0D90380.private preserve=yes
      //## end CEval_Periodic%3B7FD0D90380.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Periodic%3B7FD0D90380.implementation preserve=yes
      //## end CEval_Periodic%3B7FD0D90380.implementation

};

//## begin CEval_Periodic%3B7FD0D90380.postscript preserve=yes
//## end CEval_Periodic%3B7FD0D90380.postscript

// Class CEval_Periodic 

//## Get and Set Operations for Class Attributes (inline)

inline CEvaluator * CEval_Periodic::GetAmplitude ()
{
  //## begin CEval_Periodic::GetAmplitude%3B7FD0D90387.get preserve=no
  return Amplitude;
  //## end CEval_Periodic::GetAmplitude%3B7FD0D90387.get
}

inline void CEval_Periodic::SetAmplitude (CEvaluator * value)
{
  //## begin CEval_Periodic::SetAmplitude%3B7FD0D90387.set preserve=no
  Amplitude = value;
  //## end CEval_Periodic::SetAmplitude%3B7FD0D90387.set
}

inline CEvaluator * CEval_Periodic::GetPhase ()
{
  //## begin CEval_Periodic::GetPhase%3B7FD0D90388.get preserve=no
  return Phase;
  //## end CEval_Periodic::GetPhase%3B7FD0D90388.get
}

inline void CEval_Periodic::SetPhase (CEvaluator * value)
{
  //## begin CEval_Periodic::SetPhase%3B7FD0D90388.set preserve=no
  Phase = value;
  //## end CEval_Periodic::SetPhase%3B7FD0D90388.set
}

inline CEvaluator * CEval_Periodic::GetFreqMult ()
{
  //## begin CEval_Periodic::GetFreqMult%3B7FD0D90389.get preserve=no
  return FreqMult;
  //## end CEval_Periodic::GetFreqMult%3B7FD0D90389.get
}

inline void CEval_Periodic::SetFreqMult (CEvaluator * value)
{
  //## begin CEval_Periodic::SetFreqMult%3B7FD0D90389.set preserve=no
  FreqMult = value;
  //## end CEval_Periodic::SetFreqMult%3B7FD0D90389.set
}

//## begin module%3B7FD0D90380.epilog preserve=yes
//## end module%3B7FD0D90380.epilog


#endif
