//## begin module%3B7FD0D90345.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D90345.cm

//## begin module%3B7FD0D90345.cp preserve=no
//## end module%3B7FD0D90345.cp

//## Module: CEval_Time%3B7FD0D90345; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Time.h

#ifndef CEval_Time_h
#define CEval_Time_h 1

//## begin module%3B7FD0D90345.additionalIncludes preserve=no
//## end module%3B7FD0D90345.additionalIncludes

//## begin module%3B7FD0D90345.includes preserve=yes
//## end module%3B7FD0D90345.includes

// CEvaluator
#include "Math\MATH_Evaluator\CEvaluator.h"
//## begin module%3B7FD0D90345.additionalDeclarations preserve=yes
//## end module%3B7FD0D90345.additionalDeclarations


//## begin CEval_Time%3B7FD0D90345.preface preserve=yes
//## end CEval_Time%3B7FD0D90345.preface

//## Class: CEval_Time%3B7FD0D90345
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Time : public CEvaluator  //## Inherits: <unnamed>%3B7FD0D90344
{
  //## begin CEval_Time%3B7FD0D90345.initialDeclarations preserve=yes
  //## end CEval_Time%3B7FD0D90345.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Time();

    //## Destructor (generated)
      ~CEval_Time();


    //## Other Operations (specified)
      //## Operation: GetValue%998231898
      float GetValue ();

    // Additional Public Declarations
      //## begin CEval_Time%3B7FD0D90345.public preserve=yes
      //## end CEval_Time%3B7FD0D90345.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Time%3B7FD0D90345.protected preserve=yes
      //## end CEval_Time%3B7FD0D90345.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: dStartTime%3B7FD76E0018
      //## begin CEval_Time::dStartTime%3B7FD76E0018.attr preserve=no  private: double {UA} 
      double dStartTime;
      //## end CEval_Time::dStartTime%3B7FD76E0018.attr

    // Additional Private Declarations
      //## begin CEval_Time%3B7FD0D90345.private preserve=yes
      //## end CEval_Time%3B7FD0D90345.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Time%3B7FD0D90345.implementation preserve=yes
      //## end CEval_Time%3B7FD0D90345.implementation

};

//## begin CEval_Time%3B7FD0D90345.postscript preserve=yes
//## end CEval_Time%3B7FD0D90345.postscript

// Class CEval_Time 

//## begin module%3B7FD0D90345.epilog preserve=yes
//## end module%3B7FD0D90345.epilog


#endif
