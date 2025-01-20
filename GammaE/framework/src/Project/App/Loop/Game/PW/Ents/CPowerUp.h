// -----------------------------------------------------------------------------
#ifndef CPowerUpH
#define CPowerUpH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/CVisEntity.h"

class CPowerUp : public CVisEntity
{
public:
		 CPowerUp();
		~CPowerUp();

		// AI/Think
		virtual void Init(MTH_CPoint3& _oPos,int _iSubType);
		virtual void Think(float _fDeltaT);
		virtual void Spawn(MTH_CPoint3& _oPos);
		
		virtual void HideDisable();
public:
		unsigned int m_uiSFX;

private:
		float		 m_fDelay;
		MTH_CPoint3  m_oSpd;
};

#define ENTSTATE_SPAWNING		(TEntityState)10
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------