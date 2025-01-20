//## begin module%3B74642B00BD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B74642B00BD.cm

//## begin module%3B74642B00BD.cp preserve=no
//## end module%3B74642B00BD.cp

//## Module: CChrono%3B74642B00BD; Pseudo Package body
//## Source file: i:\Projects\GammaE\Misc\Timing\CChrono.cpp

//## begin module%3B74642B00BD.additionalIncludes preserve=no
//## end module%3B74642B00BD.additionalIncludes

//## begin module%3B74642B00BD.includes preserve=yes
#ifdef WIN32
	#include <windows.h>
#else
	#ifdef _BCB_
		#include <vcl.h>
	#endif
#endif
//## end module%3B74642B00BD.includes

// CChrono
#include "Misc\Timing\CChrono.h"
//## begin module%3B74642B00BD.additionalDeclarations preserve=yes
//## end module%3B74642B00BD.additionalDeclarations


// Class CChrono 





CChrono::CChrono()
  //## begin CChrono::CChrono%.hasinit preserve=no
      : dStartTime(0), dChronoFrequency(1), dElapsedTime(0), bActive(false)
  //## end CChrono::CChrono%.hasinit
  //## begin CChrono::CChrono%.initialization preserve=yes
  //## end CChrono::CChrono%.initialization
{
  //## begin CChrono::CChrono%.body preserve=yes
#ifdef WIN32
	LARGE_INTEGER liFrequency;

	QueryPerformanceFrequency(&liFrequency);
	dChronoFrequency = (double)liFrequency.QuadPart;
#endif
  //## end CChrono::CChrono%.body
}


CChrono::~CChrono()
{
  //## begin CChrono::~CChrono%.body preserve=yes
  //## end CChrono::~CChrono%.body
}



//## Other Operations (implementation)
void CChrono::Reset ()
{
  //## begin CChrono::Reset%997612244.body preserve=yes
	bActive      = false;
	dElapsedTime = 0.0;
	dStartTime   = 0.0;	
  //## end CChrono::Reset%997612244.body
}

void CChrono::Start ()
{
  //## begin CChrono::Start%997612245.body preserve=yes
  #ifdef WIN32
	LARGE_INTEGER liStartTime;

	if (QueryPerformanceCounter(&liStartTime))
		dStartTime = (double)liStartTime.QuadPart;
	else
		dStartTime = 0.0;

  #endif
  //## end CChrono::Start%997612245.body
}

void CChrono::Stop ()
{
  //## begin CChrono::Stop%997612246.body preserve=yes
	#ifdef WIN32

		LARGE_INTEGER liCurrentTime;
		double		   dCurrentTime;
		
		if (QueryPerformanceCounter(&liCurrentTime))
		{	
			dCurrentTime  = (double)liCurrentTime.QuadPart;
			dElapsedTime += (dCurrentTime - dStartTime) / dChronoFrequency;
			
			#ifdef _DEBUG
			if (dElapsedTime > 1.0f)
			{
				dElapsedTime = 0.1f;
				// _asm {int 3};
			}
			#endif
		}

	#endif
  //## end CChrono::Stop%997612246.body
}

double CChrono::ElapsedTime ()
{
  //## begin CChrono::ElapsedTime%997612247.body preserve=yes
	#ifdef WIN32

		if (bActive)
		{
			LARGE_INTEGER liCurrentTime;
			double		   dCurrentTime;
		
			if (QueryPerformanceCounter(&liCurrentTime))
			{	
				dCurrentTime  = (double)liCurrentTime.QuadPart;
				return( dElapsedTime + ((dCurrentTime - dStartTime) / dChronoFrequency) );
			}		
		}
		else
		{
			#ifdef _DEBUG
			if (dElapsedTime > 1.0f)
			{
				dElapsedTime = 0.1f;
				// _asm {int 3};
			}
			#endif
			return(dElapsedTime);
		}

	#endif
    return(0.0);
  //## end CChrono::ElapsedTime%997612247.body
}

// Additional Declarations
  //## begin CChrono%3B74642B00BD.declarations preserve=yes
  //## end CChrono%3B74642B00BD.declarations

//## begin module%3B74642B00BD.epilog preserve=yes
//## end module%3B74642B00BD.epilog
