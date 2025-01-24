// ----------------------------------------------------------------------------
#ifndef CLoopGlobalsH
#define CLoopGlobalsH
// ----------------------------------------------------------------------------
#include <windows.h>
#include "GammaE.h"
// ----------------------------------------------------------------------------
class CLoopGlobals
{
public:
	CLoopGlobals();

	CGChrono 					m_oChrono;

	CGGameExtendedCI			m_oCI;

	CSoundReceiver				m_oSndRcv;
	bool						m_bFinnishApplication;
	float						m_fTimeMult;

};

extern CLoopGlobals loopGlobals;
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------