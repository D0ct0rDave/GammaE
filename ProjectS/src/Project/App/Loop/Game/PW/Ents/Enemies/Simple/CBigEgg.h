// -----------------------------------------------------------------------------
#ifndef CBigEggH
#define CBigEggH
// -----------------------------------------------------------------------------
#include "Game/Ents/Enemies/CEnemy.h"
// -----------------------------------------------------------------------------
class CBigEgg : public CEnemy
{
public:
	CBigEgg();
	virtual void Init(MTH_CPoint3& _oPos,float _fScale);

	virtual bool bDamage(float _fEnergy);
	virtual void Think(float _fDeltaT);
	
private:
	float	m_fAngle;
	float   m_fPhase;
	
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------