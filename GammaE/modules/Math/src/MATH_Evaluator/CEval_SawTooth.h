//	  %X% %Q% %Z% %W%



#ifndef CEval_SawTooth_h
#define CEval_SawTooth_h 1


#include "MATH_Other\MATH_Common.h"

// CEval_Periodic
#include "MATH_Evaluator\CEval_Periodic.h"




class CEval_SawTooth : public CEval_Periodic  {
    
  public:
          CEval_SawTooth();

          virtual ~CEval_SawTooth();


                virtual float GetValue ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_SawTooth 


inline float CEval_SawTooth::GetValue ()
{
    	assert (Amplitude && "Evaluator with NULL Amplitude param");
	assert (FreqMult  && "Evaluator with NULL Frequency param");
	assert (Phase     && "Evaluator with NULL Phase param");

	float fPhase    = FreqMult->GetValue()*Phase->GetValue();
	float fIntPhase = ((int)(fPhase/_2PI_)) * _2PI_;
	fPhase -= fIntPhase;
	
	return( Amplitude->GetValue()* ((fPhase/_PI_) - 1.0f) );
}



#endif
