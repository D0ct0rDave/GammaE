// -----------------------------------------------------------------------------
#ifndef CEntRendH
#define CEntRendH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/CVisEntity.h"
// -----------------------------------------------------------------------------
#define MAX_INSTANCES 1024

class CEntRend
{
public:
	 CEntRend();
	~CEntRend();

	static int iAdd(CVisEntity* _poEnt);
	static void Invalidate();

	static void Update(float _fDeltaT);
	static void Render();

public:
	static CVisEntity*	m_apoREI[MAX_INSTANCES];
	static int			m_iNumInsts;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------