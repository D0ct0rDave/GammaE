// -----------------------------------------------------------------------------
#ifndef CPolloH
#define CPolloH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Loop/Game/Ents/CActor.h"
#include "CPolloBomb.h"

#define MAX_MISSILES	5

#define PST_BASE			10
#define PST_STAND			(PST_BASE+0)
#define PST_RUN				(PST_BASE+1)
#define PST_ATTACK			(PST_BASE+2)
#define PST_OTHER			(PST_BASE+3)
#define PST_HIT				(PST_BASE+4)
#define PST_DEAD			(PST_BASE+5)

// -----------------------------------------------------------------------------
class CPollo : public CActor
{
public:	
		 CPollo();
		~CPollo();

		// AI/Think
		virtual void Init(MTH_CPoint3& _oPos);
		virtual void Think(float _fDeltaT);

		virtual void CheckThrownRocks(float _fDeltaT);
		virtual void CheckNewPos(float _fDeltaT);
		virtual void PolloHit();

public:
		CPolloBomb*	m_poPB[MAX_MISSILES];
		float		m_fBombTime;
//
		float		m_fPolvilloTime;
		float		m_fSpeedMult;
		float		m_fTimeMult;
		unsigned int m_uiHits;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------