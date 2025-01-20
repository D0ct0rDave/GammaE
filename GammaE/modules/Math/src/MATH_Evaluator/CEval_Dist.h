//	  %X% %Q% %Z% %W%



#ifndef CEval_Dist_h
#define CEval_Dist_h 1



// CEvaluator
#include "Math\MATH_Evaluator\CEvaluator.h"
// CVect3
#include "Math\MATH_Vector\CVect3.h"





class CEval_Dist : public CEvaluator  {
    
  public:
          CEval_Dist();

          ~CEval_Dist();


                virtual float GetValue ();

            void SetPoint (CVect3* Point);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  CVect3 *Pos;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Dist 



#endif
