//---------------------------------------------------------------------------
#ifdef WIN32
	#include <windows.h>
#else
	#ifdef __BORLANDC__
		#include <vcl.h>
	#endif
#endif

#include "Chronos.h"
//---------------------------------------------------------------------------
LARGE_INTEGER liChronoFrequency;
double		   dChronoFrequency;

LARGE_INTEGER liChronoStartTime;
double		   dChronoStartTime;

LARGE_INTEGER liChronoCurrentTime;
double		   dChronoCurrentTime;

double		   dChronoEllapsedTime;
//---------------------------------------------------------------------------
void Chrono_StartChrono()
{
#ifdef WIN32
	QueryPerformanceFrequency(&liChronoFrequency);
	QueryPerformanceCounter  (&liChronoStartTime);
	
	dChronoFrequency = (double)liChronoFrequency.QuadPart;
	dChronoStartTime = (double)liChronoStartTime.QuadPart;
#endif
}
//---------------------------------------------------------------------------
double Chrono_EllapsedTime()
{
#ifdef WIN32
	if (QueryPerformanceCounter(&liChronoCurrentTime))
	{	
		dChronoCurrentTime  = (double)liChronoCurrentTime.QuadPart;
		dChronoEllapsedTime = (dChronoCurrentTime - dChronoStartTime) / dChronoFrequency;
		
		return(dChronoEllapsedTime);
	}
#else
	return 0.0;
#endif
}
//---------------------------------------------------------------------------
double Chrono_GetCurrentTime()
{
#ifdef WIN32	
	QueryPerformanceFrequency(&liChronoFrequency);
	QueryPerformanceCounter  (&liChronoStartTime);
	
	dChronoFrequency = (double)liChronoFrequency.QuadPart;
	dChronoStartTime = (double)liChronoStartTime.QuadPart;
		
	return(dChronoStartTime/dChronoFrequency);
#else
	return 0.0;
#endif
}
//---------------------------------------------------------------------------
