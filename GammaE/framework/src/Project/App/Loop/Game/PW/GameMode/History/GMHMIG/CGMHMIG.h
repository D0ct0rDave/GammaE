// -----------------------------------------------------------------------------
#ifndef CGMHMIGH
#define CGMHMIGH
// -----------------------------------------------------------------------------

#include "antares.h"
#include "HUD/CHUDScene.h"

typedef enum TMIGOrder{
	
	MIGO_Processing,
	MIGO_Exit,
	MIGO_Continue,
};

// -----------------------------------------------------------------------------
typedef enum TMIGState{
	MIGS_Enabling,
	MIGS_Ready,
	MIGS_Disabling,
};
// -----------------------------------------------------------------------------
class CGMHMIG
{
public:
	CGMHMIG();

	void Init();
	void Finish();
	void Reset();

	void Enable();
	void Disable();
	void Think(float _fDeltaT);
	TMIGState eState();
	TMIGOrder eGetOrder();
	
public:
	CHUDScene*  m_poMIGScn;

private:
	//
	CHUDScene*  m_poOldScn;
	TMIGOrder	m_eOrder;
	TMIGState	m_eState;
	int			m_iScr;
	int			m_iOpt;
	
};
// --------------------------------------------------------
inline TMIGOrder CGMHMIG::eGetOrder()
{
	return(m_eOrder);
}
// --------------------------------------------------------
inline TMIGState CGMHMIG::eState()
{
	return (m_eState);	
}
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------