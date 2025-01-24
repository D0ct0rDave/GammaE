
//-----------------------------------------------------------------------------












#ifdef WIN32
	#include <windows.h>
#else
	#ifdef _BCB_
		#include <vcl.h>
	#endif
#endif

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
#include "Timing\CGChrono.h"




//-----------------------------------------------------------------------------





CGChrono::CGChrono()
  
      : m_dStartTime(0), m_dChronoFrequency(1), m_dElapsedTime(0), m_bActive(false)
  
  
  
{
  
	#ifdef WIN32
		#ifdef CUTRIX_TIMMING
		
		#else
			LARGE_INTEGER liFrequency;

			QueryPerformanceFrequency(&liFrequency);
			m_dChronoFrequency = (double)liFrequency.QuadPart;
			dLastDelta       = 0.1;
		#endif
	#endif
  
}


CGChrono::~CGChrono()
{
  
  
}




void CGChrono::Reset ()
{
  
	m_bActive      = false;
	m_dElapsedTime = 0.0;
	m_dStartTime   = 0.0;	
  
}

void CGChrono::Start ()
{
  
	#ifdef WIN32
		#ifdef CUTRIX_TIMMING  		
		
			*((DWORD *)&m_dStartTime) = GetTickCount();
		#else		
			LARGE_INTEGER liStartTime;

			if (QueryPerformanceCounter(&liStartTime))
				m_dStartTime = (double)liStartTime.QuadPart;		
			else
				m_dStartTime = 0.0;
		#endif
	#endif	
  
}

void CGChrono::Stop ()
{
  
	m_bActive = false;

	#ifdef WIN32
		#ifdef CUTRIX_TIMMING			
			DWORD dCurrentTime = GetTickCount();
			m_dElapsedTime += 0.001f * (double)(dCurrentTime - *((DWORD *)&m_dStartTime));
	
		#else	
			LARGE_INTEGER	liCurrentTime;				

			if (QueryPerformanceCounter(&liCurrentTime))
			{
				double			dCurrentTime;
				double			dDelta;

				dCurrentTime  = (double)liCurrentTime.QuadPart;
				dDelta        = (dCurrentTime - m_dStartTime) / m_dChronoFrequency;

				//-----------------------------------------------------------------------------
				//-----------------------------------------------------------------------------

				if (dDelta >= 1.0f)
				{
					dDelta = dLastDelta;
					//-----------------------------------------------------------------------------
				}
				else
					dLastDelta = dDelta;

				m_dElapsedTime += dDelta;
			}
		#endif
	#endif
  
}

double CGChrono::dElapsedTime ()
{
  
	#ifdef WIN32
		#ifdef CUTRIX_TIMMING		
			
			if (m_bActive)
			{
				DWORD dCurrentTime = GetTickCount();	
				return ( m_dElapsedTime + 0.001f * (double)(dCurrentTime - *((DWORD *)&m_dStartTime)) );
			}
			else
				return(m_dElapsedTime);
		#else
			if (m_bActive)
			{
				LARGE_INTEGER	liCurrentTime;

				if (QueryPerformanceCounter(&liCurrentTime))
				{					
					double			dCurrentTime;
					double			dDelta;

					dCurrentTime  = (double)liCurrentTime.QuadPart;
					dDelta        = (dCurrentTime - m_dStartTime) / m_dChronoFrequency;

					//-----------------------------------------------------------------------------
					//-----------------------------------------------------------------------------

					if (dDelta >= 1.0f)
					{
						dDelta = dLastDelta;
						//-----------------------------------------------------------------------------
					}
					else
						dLastDelta = dDelta;

					return ( m_dElapsedTime + dDelta);
				}
			}
			else
				return(m_dElapsedTime);
		#endif
	#endif
	
	return(0.0f);
  
}

//-----------------------------------------------------------------------------
  
  



