//	  %X% %Q% %Z% %W%



#ifndef CEval_Sin_h
#define CEval_Sin_h 1



// CEval_Periodic
#include "MATH_Evaluator\CEval_Periodic.h"
#ifndef cosf
#define cosf cos
#endif

#ifndef sinf
#define sinf sin
#endif




class CEval_Sin : public CEval_Periodic  {
    
  public:
          CEval_Sin();

          virtual ~CEval_Sin();


                virtual float GetValue ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Sin 


inline float CEval_Sin::GetValue ()
{
    	assert (Amplitude && "Evaluator with NULL Amplitude param");
	assert (FreqMult  && "Evaluator with NULL Frequency param");
	assert (Phase     && "Evaluator with NULL Phase param");

	return( Amplitude->GetValue()*(float)sinf(FreqMult->GetValue()*Phase->GetValue()) );
}



#endif
