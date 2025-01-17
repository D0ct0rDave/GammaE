#ifndef CShRoller_h
#define CShRoller_h 1

#include "Game/Entities/CShip.h"

class CShRoller : public CShip
{  
	public:
		 CShRoller();
		~CShRoller();

		virtual void Fire ();
		virtual void Think(float _fDelta);

		COrionEnt	*poTarget;
		float		fShotTime;
		int			iSpawnFlags;
};

#endif
