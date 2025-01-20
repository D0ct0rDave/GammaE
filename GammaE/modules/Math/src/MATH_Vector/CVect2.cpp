//-----------------------------------------------------------------------------
#include "MATH_Vector\CVect2.h"
//-----------------------------------------------------------------------------
#include "MATH_Other\MATH_Common.h"

//-----------------------------------------------------------------------------

float CVect2::Module ()
{ 
	return (MATH_Common::fSqrt(_SQ_(x) + _SQ_(y))); 
}

float CVect2::SqModule ()
{
  return ( _SQ_(x) + _SQ_(y) ); 
}

void CVect2::Normalize ()
{
	float fM = Module();
	if (fM)
	{
		float f1_OVER_M = 1.0f / fM;
		x *= f1_OVER_M;
		y *= f1_OVER_M;
	}
}

float CVect2::Distance (const CVect2& _oV)
{  
	return (MATH_Common::fSqrt(_SQ_(_oV.x-x) + _SQ_(_oV.y-y))); 
}

float CVect2::SqDistance (const CVect2& _oV)
{
	return( _SQ_(_oV.x-x) + _SQ_(_oV.y-y) ); 
}

bool CVect2::Inside (const CVect2& _oMax,const CVect2& _oMin)
{
  	return(
    	  (x >= _oMin.x) && (y >= _oMin.y) &&
          (x <= _oMax.x) && (y <= _oMax.y)
          ); 
}

bool CVect2::bEqual (const CVect2& _oV)
{
	return( (x == _oV.x) && (y == _oV.y) );
}
//-----------------------------------------------------------------------------
  
  



