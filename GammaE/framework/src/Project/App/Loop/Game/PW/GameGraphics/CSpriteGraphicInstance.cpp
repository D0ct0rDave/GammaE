// -----------------------------------------------------------------------------
#include "CSpriteGraphicInstance.h"
#include "CGraphicResourceMgr.h"
// -----------------------------------------------------------------------------
CGraphicInstance::CGraphicInstance()
{
}
// -----------------------------------------------------------------------------
CGraphicInstance::CGraphicInstance(char* _szResource)
{
	m_bVisible = false;
	m_bEnabled = false;
	m_fScale   = 1.0f;

	m_oMat.Identity();	
	m_poResource = NULL;

	Init(_szResource);
}
// -----------------------------------------------------------------------------
CGraphicInstance::~CGraphicInstance()
{

}
// -----------------------------------------------------------------------------
void CGraphicInstance::Init(char* _szResource)
{
	m_poResource = CGraphicResourceMgr::poGetResource(_szResource);
}
// -----------------------------------------------------------------------------
void CGraphicInstance::Update(float _fDeltaT)
{

}
// -----------------------------------------------------------------------------
void CGraphicInstance::Render()
{
	if (m_poResource == NULL) return;

	MTH_CPoint3 oPosition;
	m_oMat.GetCol3(&oPosition);

	float fHWidth = m_poResource->m_poTex->m_poTex->uiWidth()  * 0.5f * m_fScale;
	float fHHeight= m_poResource->m_poTex->m_poTex->uiHeight() * 0.5f * m_fScale;
	
	gDC->Enable(E3D_S_BLEND);
	gDC->BlendMode(E3D_BM_ALPHA);
	
	RenderQUAD(m_poResource->m_poTex,
			   oPosition.x - fHWidth,
			   oPosition.y - fHHeight,
			   oPosition.x + fHWidth,
			   oPosition.y + fHHeight,0,0,1,1,0xffffffff,1.0f);
}
// -----------------------------------------------------------------------------
void CGraphicInstance::Pos(MTH_CPoint3& _oPos)
{
	m_oMat.SetCol3( _oPos );
}
// -----------------------------------------------------------------------------
MTH_CPoint3 CGraphicInstance::oPos()
{
	MTH_CPoint3 oP;
	m_oMat.GetCol3(&oP);

	return(oP);
}
// -----------------------------------------------------------------------------