// -----------------------------------------------------------------------------
#ifndef CExplosionH
#define CExplosionH
// -----------------------------------------------------------------------------
#include "GammaE.h"
// -----------------------------------------------------------------------------
class CExplosion
{
public:	
		 CExplosion();
		~CExplosion();

		virtual void Init(const CVect3& _oPos);
		virtual void Think(float _fDeltaT);
		virtual bool bAlive();

		virtual void Render();

public:
		float			m_fTime;
		float			m_fOTime;
		CVect3			m_oPos;
		CVect3			m_oOPos;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
