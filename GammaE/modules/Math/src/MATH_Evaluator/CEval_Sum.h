//	  %X% %Q% %Z% %W%



#ifndef CEval_Sum_h
#define CEval_Sum_h 1



// CEval_Binary
#include "MATH_Evaluator\CEval_Binary.h"




class CEval_Sum : public CEval_Binary  {
    
  public:
          CEval_Sum();

          virtual ~CEval_Sum();


                virtual float GetValue ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Sum 


inline float CEval_Sum::GetValue ()
{
  	return (OperandA->GetValue() + OperandB->GetValue() );
}



#endif
