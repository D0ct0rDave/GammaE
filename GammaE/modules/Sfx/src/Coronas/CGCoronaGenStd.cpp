// ----------------------------------------------------------------------------
#include "CGCoronaGenStd.h"
#include "CGCoronaInstance.h"
// ----------------------------------------------------------------------------
class CGCoronaStd : public CGCorona
{
	public:
		virtual void SetPos(const CVect3& _oPos);

	public:
		float				m_fTime;
		CVect3				m_oPos;
		
		float				m_fSize;
		CGColor				m_oColor;		
};
// ----------------------------------------------------------------------------
void CGCoronaStd::SetPos(const CVect3& _oPos)
{
	m_oPos = _oPos;
}
// ----------------------------------------------------------------------------
CGCorona* CGCoronaGenStd::poCreateInstanceData()
{
	CGCoronaStd* poStd = mNew CGCoronaStd;
	return(poStd);
}
// ----------------------------------------------------------------------------
void CGCoronaGenStd::UpdateCorona(CGCorona* _poCorona,float _fDeltaT)
{
	CGCoronaStd* poCorona = (CGCoronaStd*)_poCorona;

	poCorona->m_fTime += _fDeltaT;

	// Get the factpr	
	float fFact = 0.0f;

	switch (m_eCF)
	{
		default:
			fFact = (MATH_Common::fSin(poCorona->m_fTime * _2PI_ * m_fFreq) + 1.0f) * 0.5f;
	};

	poCorona->m_fSize = MATH_Common::fLerp(m_fIniSize,m_fEndSize,fFact);
	poCorona->m_oColor.Lerp(m_oIniColor,m_oEndColor,fFact);
}
// ----------------------------------------------------------------------------
void CGCoronaGenStd::InitInstance(CGCoronaInstance* _poInst)
{
	CGCoronaStd* poCorona = (CGCoronaStd*)_poInst->poGetCoronaData();

	poCorona->m_fTime = 0.0f;
	poCorona->m_fSize = m_fIniSize;
	poCorona->m_oColor= m_oIniColor;
}
// ----------------------------------------------------------------------------
void CGCoronaGenStd::UpdateInstance(CGCoronaInstance* _poInst,float _fDeltaT)
{
	CGCoronaStd* poCorona = (CGCoronaStd*)_poInst->poGetCoronaData();
	UpdateCorona(poCorona,_fDeltaT);

	CMatrix4x4 oCameraMatrix;
	CGRenderer::I()->GetCameraMatrix(&oCameraMatrix);

	// Generate the geometry for this corona
	CVect3 oNewPos = poCorona->m_oPos;
	oCameraMatrix.TransformPoint(oNewPos);

	CVect3 oX = CVect3::oX();	oX.Scale(poCorona->m_fSize);
	CVect3 oY = CVect3::oY();	oY.Scale(poCorona->m_fSize);

	CVect3 oVX[4];
	CVect2 oUV[4];
	CGColor oVC[4];

	oVX[0] = oNewPos; oVX[0].Sub(oX);	oVX[0].Sub(oY);
	oVX[1] = oNewPos; oVX[1].Sub(oX);	oVX[1].Add(oY);
	oVX[2] = oNewPos; oVX[2].Add(oX);	oVX[2].Add(oY);
	oVX[3] = oNewPos; oVX[3].Add(oX);	oVX[3].Sub(oY);

	oVC[0] = poCorona->m_oColor;
	oVC[1] = poCorona->m_oColor;
	oVC[2] = poCorona->m_oColor;
	oVC[3] = poCorona->m_oColor;

	oUV[0].V2(0.0f,0.0f);
	oUV[1].V2(0.0f,1.0f);		
	oUV[2].V2(1.0f,1.0f);
	oUV[3].V2(0.0f,1.0f);

	m_poBBR->AddBillboards(oVX,oUV,oVC,1);
}
// ----------------------------------------------------------------------------
