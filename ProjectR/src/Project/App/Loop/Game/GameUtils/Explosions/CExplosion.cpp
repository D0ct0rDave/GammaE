// -----------------------------------------------------------------------------
#include "CExplosion.h"
// -----------------------------------------------------------------------------
CExplosion::CExplosion()
{
	m_fTime = 0.0f;
	m_fOTime= 0.0f;
	m_oPos = CVect3::oZero();
	m_oOPos= CVect3::oZero();
}
// -----------------------------------------------------------------------------
CExplosion::~CExplosion()
{
}
// -----------------------------------------------------------------------------
void CExplosion::Init(const CVect3& _oPos)
{
	m_oPos = _oPos;
}
// -----------------------------------------------------------------------------
void CExplosion::Think(float _fDeltaT)
{
}
// -----------------------------------------------------------------------------
void CExplosion::Render()
{

}
// -----------------------------------------------------------------------------
bool CExplosion::bAlive()
{
	return(false);
}
// -----------------------------------------------------------------------------