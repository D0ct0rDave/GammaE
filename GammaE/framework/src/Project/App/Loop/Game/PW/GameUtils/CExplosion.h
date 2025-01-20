// -----------------------------------------------------------------------------
#ifndef CExplosionH
#define CExplosionH
// -----------------------------------------------------------------------------

class CExplosion
{
public:	
		 CExplosion();
		~CExplosion();

		virtual void Init(MTH_CPoint3& _oPos);
		virtual void Think(float _fDeltaT);
		virtual bool bAlive();

		virtual void Render();

public:
		float				m_fTime;
		float				m_fOTime;
		MTH_CPoint3			m_oPos;
		MTH_CPoint3			m_oOPos;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
