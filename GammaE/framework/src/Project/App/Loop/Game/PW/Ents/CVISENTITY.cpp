#ifdef PROFILE
#pragma optimize ("",off)
#endif

// -----------------------------------------------------------------------------
#include "CVisEntity.h"
// -----------------------------------------------------------------------------
CVisEntity::CVisEntity()
{
	m_poGI		= NULL;
	m_iRI		= -1;
	m_bVisible	= false;	
}
// -----------------------------------------------------------------------------
CVisEntity::~CVisEntity()
{
}
// -----------------------------------------------------------------------------
// Forces the position of a given entity to the given position. Erases previous
// positon state thus avoiding discontinuity
// -----------------------------------------------------------------------------
void CVisEntity::Pos(MTH_CPoint3& _oPos)
{
	m_oOPos = _oPos;
	m_oPos  = _oPos;

	// Set new goal position
	m_poGI->Pos(_oPos);
}
// -----------------------------------------------------------------------------
void CVisEntity::Kill()
{
	Visible(false);
	
	CCollEntity::Kill();
}
// -----------------------------------------------------------------------------
void CVisEntity::Restart()
{
	// Set player position.
	m_oPos    = m_oIniPos;
	m_oOPos	  = m_oIniPos;

	m_eState  = ENTSTATE_ALIVE;
}
// -----------------------------------------------------------------------------
void CVisEntity::Enable()
{
	if(m_poGI)
		m_poGI->Enable(true);
	
	CCollEntity::Enable();
}
// -----------------------------------------------------------------------------
void CVisEntity::Disable()
{
	if(m_poGI)
		m_poGI->Enable(false);

	CCollEntity::Disable();
}
// -----------------------------------------------------------------------------
void CVisEntity::Visible(bool _bVisible)
{
	if(m_poGI)
		m_poGI->Visible(_bVisible);

	m_bVisible = _bVisible;
}
// -----------------------------------------------------------------------------
void CVisEntity::HideDisable()
{
	Disable();
	Visible(false);
}
// -----------------------------------------------------------------------------
void CVisEntity::ShowEnable()
{
	Enable();
	Visible(true);
}
// -----------------------------------------------------------------------------
void CVisEntity::BuildBV()
{
	// Get radius
	m_poBV = pNew CBVSphere;
	MTH_CPoint3 oExtents ((m_poGI->poGraphicResource()->oMaxs().x - m_poGI->poGraphicResource()->oMins().x)*0.5f,
						  (m_poGI->poGraphicResource()->oMaxs().y - m_poGI->poGraphicResource()->oMins().y)*0.5f,
						  (m_poGI->poGraphicResource()->oMaxs().z - m_poGI->poGraphicResource()->oMins().z)*0.5f);

	((CBVSphere*)m_poBV)->m_fRadius = fMin(fMin(oExtents.x,oExtents.y),oExtents.z) * m_poGI->fScale();
}
// -----------------------------------------------------------------------------
#ifdef PROFILE
#pragma optimize ("",on)
#endif