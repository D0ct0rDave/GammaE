//	  %X% %Q% %Z% %W%



#ifndef CEval_Time_h
#define CEval_Time_h 1



// CEvaluator
#include "MATH_Evaluator\CEvaluator.h"
#include "GammaE_Misc.h"




class CEval_Time : public CEvaluator  {
    
  public:
          CEval_Time();

          virtual ~CEval_Time();


                float GetValue ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  CGChrono m_oChrono;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Time 



#endif
