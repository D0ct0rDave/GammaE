#include "CGLiveGameEntity.h"

// -----------------------------------------------------------------------------
void CGLiveGameEntity::InflictDamage(float _fEnergy)
{
	m_fEnergy -= _fEnergy;	
	if (m_fEnergy<0.0f)
	{
		m_fEnergy = 0.0f;
		Kill();
		Reset();
	}
	else
		Damage();
}
//-----------------------------------------------------------------------------
