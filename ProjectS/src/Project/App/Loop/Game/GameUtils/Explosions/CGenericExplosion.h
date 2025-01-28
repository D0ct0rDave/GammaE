// -----------------------------------------------------------------------------
#ifndef CGeneriCGenericExplosionH
#define CGeneriCGenericExplosionH
// -----------------------------------------------------------------------------
#include "GammaE.h"
#include "CExplosion.h"
// -----------------------------------------------------------------------------
typedef struct
{
	CVect3				m_oPos;

	// Behavioural parameters
	CVect3				m_oDir;					// Random direction for this debris
	float				m_fSpiralRadius;		
	float				m_fSpiralAngleSpd;
	float				m_fLinearSpd;

	//
	CObject3D_Transf*	m_poDebris;
	CObject3D_Transf*	m_poSmoke;

}TGenericExplosionElem;
// -----------------------------------------------------------------------------
class CGenericExplosion : public CExplosion
{
	public:	
		CGenericExplosion();
		~CGenericExplosion();

		virtual void Init(const CVect3& _oPos);
		virtual void Finish();
		virtual void Think(float _fDeltaT);
		virtual bool bAlive();
		virtual void Render();

	public:
		static const uint MAX_DEBRIS_ELEMS = 16;

		float					m_fTime;
		float					m_fOTime;
		CVect3					m_oPos;
		CVect3					m_oOPos;

		uint					m_uiNumElems;
		TGenericExplosionElem	m_oEl[MAX_DEBRIS_ELEMS];		
	};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
