



#include "GammaE_Misc.h"

// CEval_Time
#include "MATH_Evaluator\CEval_Time.h"


// Class CEval_Time 


CEval_Time::CEval_Time()
        {
  	m_oChrono.Reset();
	m_oChrono.Start();
}


CEval_Time::~CEval_Time()
{
}



float CEval_Time::GetValue ()
{
  	return ( (float)m_oChrono.dElapsedTime() );
}

// Additional Declarations
    
