#ifdef PROFILE
#pragma optimize ("",off)
#endif
// -----------------------------------------------------------------------------
#include "CEntity.h"

// -----------------------------------------------------------------------------
CEntity::CEntity()
{
	m_iType    = 0;
	m_iSubType = 0;
	m_eState   = ENTSTATE_NONE;

	m_fTime     = 0.0f;
	m_fOTime    = 0.0f;
	m_fTimeMult = 1.0f;
}
// -----------------------------------------------------------------------------
CEntity::~CEntity()
{
}
// -----------------------------------------------------------------------------
void CEntity::PreThink(float _fDeltaT)
{
	// Update vars
	m_fOTime   = m_fTime;
	m_fDeltaT  = _fDeltaT * m_fTimeMult;
	m_fTime   += m_fDeltaT;
}
// -----------------------------------------------------------------------------
void CEntity::Think(float _fDeltaT)
{
}
// -----------------------------------------------------------------------------
void CEntity::Kill()
{
	SwitchToState(ENTSTATE_DEAD);
}
// -----------------------------------------------------------------------------
void CEntity::Enable()
{
	SwitchToState(ENTSTATE_ALIVE);
}
// -----------------------------------------------------------------------------
void CEntity::Disable()
{
	SwitchToState(ENTSTATE_INACTIVE);
}
// -----------------------------------------------------------------------------
void CEntity::SwitchToState(TEntityState _eNewState)
{
	OnExitState(m_eState);
	OnEnterState(_eNewState);

	m_eState = _eNewState;
}
// -----------------------------------------------------------------------------
void CEntity::OnEnterState(TEntityState _eState)
{

}
// -----------------------------------------------------------------------------
void CEntity::OnExitState(TEntityState _eState)
{

}
// -----------------------------------------------------------------------------

#ifdef PROFILE
#pragma optimize ("",on)
#endif