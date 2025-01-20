//## begin module%3B7FD0D90345.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D90345.cm

//## begin module%3B7FD0D90345.cp preserve=no
//## end module%3B7FD0D90345.cp

//## Module: CEval_Time%3B7FD0D90345; Pseudo Package body
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Time.cpp

//## begin module%3B7FD0D90345.additionalIncludes preserve=no
//## end module%3B7FD0D90345.additionalIncludes

//## begin module%3B7FD0D90345.includes preserve=yes
#include "../Misc/GammaE_Misc.h"
//## end module%3B7FD0D90345.includes

// CEval_Time
#include "Math\MATH_Evaluator\CEval_Time.h"
//## begin module%3B7FD0D90345.additionalDeclarations preserve=yes
//## end module%3B7FD0D90345.additionalDeclarations


// Class CEval_Time 


CEval_Time::CEval_Time()
  //## begin CEval_Time::CEval_Time%.hasinit preserve=no
  //## end CEval_Time::CEval_Time%.hasinit
  //## begin CEval_Time::CEval_Time%.initialization preserve=yes
  //## end CEval_Time::CEval_Time%.initialization
{
  //## begin CEval_Time::CEval_Time%.body preserve=yes
	dStartTime = Chrono_GetCurrentTime();
  //## end CEval_Time::CEval_Time%.body
}


CEval_Time::~CEval_Time()
{
  //## begin CEval_Time::~CEval_Time%.body preserve=yes
  //## end CEval_Time::~CEval_Time%.body
}



//## Other Operations (implementation)
float CEval_Time::GetValue ()
{
  //## begin CEval_Time::GetValue%998231898.body preserve=yes
	return (Chrono_GetCurrentTime() - dStartTime);
  //## end CEval_Time::GetValue%998231898.body
}

// Additional Declarations
  //## begin CEval_Time%3B7FD0D90345.declarations preserve=yes
  //## end CEval_Time%3B7FD0D90345.declarations

//## begin module%3B7FD0D90345.epilog preserve=yes
//## end module%3B7FD0D90345.epilog
