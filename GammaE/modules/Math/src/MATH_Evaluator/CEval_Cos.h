//	  %X% %Q% %Z% %W%



#ifndef CEval_Cos_h
#define CEval_Cos_h 1



// CEval_Periodic
#include "MATH_Evaluator\CEval_Periodic.h"
#ifndef cosf
#define cosf cos
#endif

#ifndef sinf
#define sinf sin
#endif




class CEval_Cos : public CEval_Periodic  {
    
  public:
          CEval_Cos();

          virtual ~CEval_Cos();


                virtual float GetValue ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Cos 


inline float CEval_Cos::GetValue ()
{
  	assert (Amplitude && "Evaluator with NULL Amplitude param");
	assert (FreqMult  && "Evaluator with NULL Frequency param");
	assert (Phase     && "Evaluator with NULL Phase param");

    return( Amplitude->GetValue()*(float)cosf(FreqMult->GetValue()*Phase->GetValue()) );

}



#endif
