// -----------------------------------------------------------------------------
#ifndef CGeneriCGenericExplosionH
#define CGeneriCGenericExplosionH
// -----------------------------------------------------------------------------
#include "Game/GameUtils/CExplosion.h"
typedef struct {
	
	MTH_CPoint3 m_oPos;
	

	// Behavioural parameters
	MTH_CPoint3 m_oDir;					// Random direction for this debris
	float		m_fSpiralRadius;		
	float		m_fSpiralAngleSpd;
	float		m_fLinearSpd;

	//
	uint		m_uiDebris;
	uint		m_uiSmoke;
	
}TGenericExplosionElem;
// -----------------------------------------------------------------------------
class CGenericExplosion : public CExplosion
{
public:	
		 CGenericExplosion();
		~CGenericExplosion();

		virtual void Init(MTH_CPoint3& _oPos);
		virtual void Finish();
		virtual void Think(float _fDeltaT);
		virtual bool bAlive();
		virtual void Render();

public:
		static const uint MAX_DEBRIS_ELEMS = 16;
	
		float					m_fTime;
		float					m_fOTime;
		MTH_CPoint3				m_oPos;
		MTH_CPoint3				m_oOPos;
		
		uint					m_uiNumElems;
		TGenericExplosionElem	m_oEl[MAX_DEBRIS_ELEMS];		
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
