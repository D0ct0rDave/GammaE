//	  %X% %Q% %Z% %W%



#ifndef CEval_Const_h
#define CEval_Const_h 1



// CEvaluator
#include "MATH_Evaluator\CEvaluator.h"




class CEval_Const : public CEvaluator  {
    
  public:
          CEval_Const();

          virtual ~CEval_Const();


                virtual float GetValue ();

    
            float GetConstant ();
      void SetConstant (float value);

    // Data Members for Class Attributes

            float Constant;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Const 


inline float CEval_Const::GetValue ()
{
  	return(Constant);
}


inline float CEval_Const::GetConstant ()
{
    return Constant;
}

inline void CEval_Const::SetConstant (float value)
{
    Constant = value;
}



#endif
