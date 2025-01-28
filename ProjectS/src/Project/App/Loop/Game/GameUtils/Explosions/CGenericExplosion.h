// -----------------------------------------------------------------------------
#ifndef CGeneriCGenericExplosionH
#define CGeneriCGenericExplosionH
// -----------------------------------------------------------------------------
#include "GammaE.h"
#include "CExplosion.h"
// -----------------------------------------------------------------------------
typedef struct
{
	CGVect3				m_oPos;

	// Behavioural parameters
	CGVect3				m_oDir;					// Random direction for this debris
	float				m_fSpiralRadius;		
	float				m_fSpiralAngleSpd;
	float				m_fLinearSpd;

	//
	CGSceneTransf*	m_poDebris;
	CGSceneTransf*	m_poSmoke;

}TGenericExplosionElem;
// -----------------------------------------------------------------------------
class CGenericExplosion : public CExplosion
{
	public:	
		CGenericExplosion();
		~CGenericExplosion();

		virtual void Init(const CGVect3& _oPos);
		virtual void Finish();
		virtual void Think(float _fDeltaT);
		virtual bool bAlive();
		virtual void Render();

	public:
		static const uint MAX_DEBRIS_ELEMS = 16;

		float					m_fTime;
		float					m_fOTime;
		CGVect3					m_oPos;
		CGVect3					m_oOPos;

		uint					m_uiNumElems;
		TGenericExplosionElem	m_oEl[MAX_DEBRIS_ELEMS];		
	};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
