//## begin module%3B7FD0D90336.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D90336.cm

//## begin module%3B7FD0D90336.cp preserve=no
//## end module%3B7FD0D90336.cp

//## Module: CEval_Const%3B7FD0D90336; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Const.h

#ifndef CEval_Const_h
#define CEval_Const_h 1

//## begin module%3B7FD0D90336.additionalIncludes preserve=no
//## end module%3B7FD0D90336.additionalIncludes

//## begin module%3B7FD0D90336.includes preserve=yes
//## end module%3B7FD0D90336.includes

// CEvaluator
#include "Math\MATH_Evaluator\CEvaluator.h"
//## begin module%3B7FD0D90336.additionalDeclarations preserve=yes
//## end module%3B7FD0D90336.additionalDeclarations


//## begin CEval_Const%3B7FD0D90336.preface preserve=yes
//## end CEval_Const%3B7FD0D90336.preface

//## Class: CEval_Const%3B7FD0D90336
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Const : public CEvaluator  //## Inherits: <unnamed>%3B7FD0D90337
{
  //## begin CEval_Const%3B7FD0D90336.initialDeclarations preserve=yes
  //## end CEval_Const%3B7FD0D90336.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Const();

    //## Destructor (generated)
      ~CEval_Const();


    //## Other Operations (specified)
      //## Operation: GetValue%998231888
      virtual float GetValue ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: Constant%3B7FD0D9033B
      float GetConstant ();
      void SetConstant (float value);

    // Data Members for Class Attributes

      //## begin CEval_Const::Constant%3B7FD0D9033B.attr preserve=no  public: float {UA} 0
      float Constant;
      //## end CEval_Const::Constant%3B7FD0D9033B.attr

    // Additional Public Declarations
      //## begin CEval_Const%3B7FD0D90336.public preserve=yes
      //## end CEval_Const%3B7FD0D90336.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Const%3B7FD0D90336.protected preserve=yes
      //## end CEval_Const%3B7FD0D90336.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Const%3B7FD0D90336.private preserve=yes
      //## end CEval_Const%3B7FD0D90336.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Const%3B7FD0D90336.implementation preserve=yes
      //## end CEval_Const%3B7FD0D90336.implementation

};

//## begin CEval_Const%3B7FD0D90336.postscript preserve=yes
//## end CEval_Const%3B7FD0D90336.postscript

// Class CEval_Const 


//## Other Operations (inline)
inline float CEval_Const::GetValue ()
{
  //## begin CEval_Const::GetValue%998231888.body preserve=yes
	return(Constant);
  //## end CEval_Const::GetValue%998231888.body
}

//## Get and Set Operations for Class Attributes (inline)

inline float CEval_Const::GetConstant ()
{
  //## begin CEval_Const::GetConstant%3B7FD0D9033B.get preserve=no
  return Constant;
  //## end CEval_Const::GetConstant%3B7FD0D9033B.get
}

inline void CEval_Const::SetConstant (float value)
{
  //## begin CEval_Const::SetConstant%3B7FD0D9033B.set preserve=no
  Constant = value;
  //## end CEval_Const::SetConstant%3B7FD0D9033B.set
}

//## begin module%3B7FD0D90336.epilog preserve=yes
//## end module%3B7FD0D90336.epilog


#endif
