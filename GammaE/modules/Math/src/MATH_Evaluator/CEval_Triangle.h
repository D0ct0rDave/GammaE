//	  %X% %Q% %Z% %W%



#ifndef CEval_Triangle_h
#define CEval_Triangle_h 1


#include "MATH_Other\MATH_Common.h"

// CEval_Periodic
#include "MATH_Evaluator\CEval_Periodic.h"




class CEval_Triangle : public CEval_Periodic  {
    
  public:
          CEval_Triangle();

          virtual ~CEval_Triangle();


                virtual float GetValue ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Triangle 


inline float CEval_Triangle::GetValue ()
{
    	assert (Amplitude && "Evaluator with NULL Amplitude param");
	assert (FreqMult  && "Evaluator with NULL Frequency param");
	assert (Phase     && "Evaluator with NULL Phase param");

	float fPhase    = FreqMult->GetValue()*Phase->GetValue();
	float fIntPhase = ((int)(fPhase/_2PI_)) * _2PI_;
	fPhase -= fIntPhase;

	if (fPhase > _PI_)
		return( Amplitude->GetValue() * ((2.0f*fPhase/_PI_) -1.0f) );
	else
		return( Amplitude->GetValue() * (1.0f - (2.0f*fPhase/_PI_)) );

}



#endif
