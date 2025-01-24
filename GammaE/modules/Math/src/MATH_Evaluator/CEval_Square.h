//	  %X% %Q% %Z% %W%



#ifndef CEval_Square_h
#define CEval_Square_h 1


#include "MATH_Other\MATH_Common.h"

// CEval_Periodic
#include "MATH_Evaluator\CEval_Periodic.h"




class CEval_Square : public CEval_Periodic  {
    
  public:
          CEval_Square();

          virtual ~CEval_Square();


                virtual float GetValue ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Square 


inline float CEval_Square::GetValue ()
{
    	assert (Amplitude && "Evaluator with NULL Amplitude param");
	assert (FreqMult  && "Evaluator with NULL Frequency param");
	assert (Phase     && "Evaluator with NULL Phase param");

	float fPhase    = FreqMult->GetValue()*Phase->GetValue();
	float fIntPhase = ((int)(fPhase/_2PI_)) * _2PI_;
	fPhase -= fIntPhase;
		
	if (fPhase > _PI_)
		return( Amplitude->GetValue() );
	else
		return(-Amplitude->GetValue() );
}



#endif
