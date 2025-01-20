//	  %X% %Q% %Z% %W%



#ifndef CEval_Mult_h
#define CEval_Mult_h 1



// CEval_Binary
#include "MATH_Evaluator\CEval_Binary.h"




class CEval_Mult : public CEval_Binary  {
    
  public:
          CEval_Mult();

          virtual ~CEval_Mult();


                virtual float GetValue ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Mult 


inline float CEval_Mult::GetValue ()
{
  	return (OperandA->GetValue() * OperandB->GetValue() );
}



#endif
