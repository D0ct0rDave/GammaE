//	  %X% %Q% %Z% %W%



#ifndef CEval_Periodic_h
#define CEval_Periodic_h 1



// CEvaluator
#include "MATH_Evaluator\CEvaluator.h"




class CEval_Periodic : public CEvaluator  {
    
  public:
          CEval_Periodic();

          virtual ~CEval_Periodic();

    
            CEvaluator * GetAmplitude ();
      void SetAmplitude (CEvaluator * value);

            CEvaluator * GetPhase ();
      void SetPhase (CEvaluator * value);

            CEvaluator * GetFreqMult ();
      void SetFreqMult (CEvaluator * value);

    // Data Members for Class Attributes

            CEvaluator *Amplitude;
      
            CEvaluator *Phase;
      
            CEvaluator *FreqMult;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CEval_Periodic 


inline CEvaluator * CEval_Periodic::GetAmplitude ()
{
    return Amplitude;
}

inline void CEval_Periodic::SetAmplitude (CEvaluator * value)
{
    Amplitude = value;
}

inline CEvaluator * CEval_Periodic::GetPhase ()
{
    return Phase;
}

inline void CEval_Periodic::SetPhase (CEvaluator * value)
{
    Phase = value;
}

inline CEvaluator * CEval_Periodic::GetFreqMult ()
{
    return FreqMult;
}

inline void CEval_Periodic::SetFreqMult (CEvaluator * value)
{
    FreqMult = value;
}



#endif
