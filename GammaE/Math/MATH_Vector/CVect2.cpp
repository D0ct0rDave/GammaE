//## begin module%3A9AD9B10118.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AD9B10118.cm

//## begin module%3A9AD9B10118.cp preserve=no
//## end module%3A9AD9B10118.cp

//## Module: CVect2%3A9AD9B10118; Pseudo Package body
//## Source file: i:\Projects\GammaE\Math\MATH_Vector\CVect2.cpp

//## begin module%3A9AD9B10118.additionalIncludes preserve=no
//## end module%3A9AD9B10118.additionalIncludes

//## begin module%3A9AD9B10118.includes preserve=yes
//## end module%3A9AD9B10118.includes

// CVect2
#include "Math\MATH_Vector\CVect2.h"
// MATH_Common
#include "Math\MATH_Other\MATH_Common.h"
//## begin module%3A9AD9B10118.additionalDeclarations preserve=yes
//## end module%3A9AD9B10118.additionalDeclarations


// Class CVect2 


CVect2::CVect2()
  //## begin CVect2::CVect2%.hasinit preserve=no
  //## end CVect2::CVect2%.hasinit
  //## begin CVect2::CVect2%.initialization preserve=yes
  //## end CVect2::CVect2%.initialization
{
  //## begin CVect2::CVect2%.body preserve=yes
  //## end CVect2::CVect2%.body
}



//## Other Operations (implementation)
float CVect2::Module ()
{
  //## begin CVect2::Module%1009552685.body preserve=yes
	return (MATH_Common::fSqrt(_SQ_(v[0]) + _SQ_(v[1])));
  //## end CVect2::Module%1009552685.body
}

float CVect2::SqModule ()
{
  //## begin CVect2::SqModule%1009552686.body preserve=yes
  return ( _SQ_(v[0]) + _SQ_(v[1]) );
  //## end CVect2::SqModule%1009552686.body
}

void CVect2::Normalize ()
{
  //## begin CVect2::Normalize%1009552687.body preserve=yes
	float fM = Module();
	if (fM)
	{
		float f1_OVER_M = 1.0f / fM;
		v[0] *= f1_OVER_M;
		v[1] *= f1_OVER_M;
	}
	
  //## end CVect2::Normalize%1009552687.body
}

float CVect2::Distance (CVect2& _roV)
{
  //## begin CVect2::Distance%1009552689.body preserve=yes
	return (MATH_Common::fSqrt(_SQ_(_roV.v[0]-v[0]) + _SQ_(_roV.v[1]-v[1])));
  //## end CVect2::Distance%1009552689.body
}

float CVect2::SqDistance (CVect2& _roV)
{
  //## begin CVect2::SqDistance%1009552690.body preserve=yes
	return( _SQ_(_roV.v[0]-v[0]) + _SQ_(_roV.v[1]-v[1]) );
  //## end CVect2::SqDistance%1009552690.body
}

bool CVect2::Inside (CVect2& _roMax, CVect2& _roMin)
{
  //## begin CVect2::Inside%1009552691.body preserve=yes
  	return(
    	  (v[0] >= _roMin.v[0]) && (v[1] >= _roMin.v[1]) &&
          (v[0] <= _roMax.v[0]) && (v[1] <= _roMax.v[1])
          );
  //## end CVect2::Inside%1009552691.body
}

bool CVect2::Equal (CVect2& _roV)
{
  //## begin CVect2::Equal%1009552692.body preserve=yes
	return( (v[0] == _roV.v[0]) && (v[1] == _roV.v[1]) );
  //## end CVect2::Equal%1009552692.body
}

// Additional Declarations
  //## begin CVect2%3A9AD9B10118.declarations preserve=yes
  //## end CVect2%3A9AD9B10118.declarations

//## begin module%3A9AD9B10118.epilog preserve=yes
//## end module%3A9AD9B10118.epilog
