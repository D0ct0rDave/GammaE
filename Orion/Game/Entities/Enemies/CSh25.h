#ifndef CSh25_h
#define CSh25_h 1

#include "Game/Entities/CShip.h"

class CSh25 : public CShip
{  
	public:
		 CSh25();
		~CSh25();

		void HandleHeight (float _fDelta);

		void NavigateAlert(float _fDelta);
		void NavigateAttacking(float _fDelta);

		virtual void Fire ();
		virtual void Think(float _fDelta);

		float fMinHeight;
		float fMaxHeight;

		CGameEntity *poTarget;
};

#endif
