#ifndef CShSkipper_h
#define CShSkipper_h 1

#include "Game/Entities/CShip.h"

class CShSkipper : public CShip
{  
	public:
		 CShSkipper();
		~CShSkipper();

		virtual void Fire ();
		virtual void Think(float _fDelta);

		COrionEnt	*poTarget;
		float		fShotTime;
		int			iSpawnFlags;
};

#endif
