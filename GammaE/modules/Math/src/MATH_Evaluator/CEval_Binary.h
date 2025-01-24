//	  %X% %Q% %Z% %W%



#ifndef CEval_Binary_h
#define CEval_Binary_h 1



// CEvaluator
#include "MATH_Evaluator\CEvaluator.h"




class CEval_Binary : public CEvaluator  {
    
  public:
          CEval_Binary();

          virtual ~CEval_Binary();

    
            CEvaluator * GetOperandA ();
      void SetOperandA (CEvaluator * value);

            CEvaluator * GetOperandB ();
      void SetOperandB (CEvaluator * value);

    // Data Members for Class Attributes

            CEvaluator *OperandA;
      
            CEvaluator *OperandB;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Binary 


inline CEvaluator * CEval_Binary::GetOperandA ()
{
    return OperandA;
}

inline void CEval_Binary::SetOperandA (CEvaluator * value)
{
    OperandA = value;
}

inline CEvaluator * CEval_Binary::GetOperandB ()
{
    return OperandB;
}

inline void CEval_Binary::SetOperandB (CEvaluator * value)
{
    OperandB = value;
}



#endif
