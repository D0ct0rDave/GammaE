



#include "GammaE_Mem.h"

// CEval_Periodic
#include "MATH_Evaluator\CEval_Periodic.h"


// Class CEval_Periodic 




CEval_Periodic::CEval_Periodic()
        : Amplitude(NULL), Phase(NULL), FreqMult(NULL)
      {
}


CEval_Periodic::~CEval_Periodic()
{
  	if (Amplitude) mDel Amplitude;
	if (Phase) mDel Phase;
	if (FreqMult) mDel FreqMult;
}


// Additional Declarations
    
