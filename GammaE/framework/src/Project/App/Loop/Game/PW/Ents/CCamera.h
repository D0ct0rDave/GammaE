// -----------------------------------------------------------------------------
#ifndef CCameraH
#define CCameraH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/CVisEntity.h"

class CCameraGraphicInstance : public CGraphicInstance 
{
	public:	
		virtual void Render() { m_poCam->PrepareDC(gDC); };
		Camera*	m_poCam;
};

class CCamera : public CVisEntity
{
public:	
		 CCamera();
		~CCamera();

		// AI/Think
		virtual void Init(MTH_CPoint3& _oPos,int _iPlayerID);
		virtual void Think(float _fDeltaT);

		virtual void CheckNewPos(float _fDeltaT);
		virtual void RadialCamera(float _fDeltaT,float _fH,float _fRad,float _fHAng,float _fVAng);
public:
		int				m_iPlayerID;
		Camera			m_oCam;
		GEOM_Frame		m_oFrame;

		MTH_CAverager	m_oVAAvg;
		MTH_CAverager	m_oHAAvg;
		MTH_CAverager	m_oRAvg;
		MTH_CAverager	m_oPitchAvg;
		MTH_CAverager	m_oYawAvg;
		MTH_CAverager	m_oRollAvg;

		float			m_fFact;
		
		float			m_fVAng;
		float			m_fHAng;
		float			m_fH;
		float			m_fRad;
		float			m_fMinDst;
		float			m_fRecoverAngle;
		float			m_fRecoverFact;
		
		int				m_iDir;
		int				m_iLastType;

		MTH_CPoint3		m_oTargetPos;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------