#ifndef CShPersecutor_h
#define CShPersecutor_h 1

#include "Game/Entities/CShip.h"

class CShPersecutor : public CShip
{  
	public:
		 CShPersecutor();
		~CShPersecutor();

		virtual void Fire ();
		virtual void Think(float _fDelta);

		COrionEnt	*poTarget;
		float		fShotTime;
		int			iSpawnFlags;
};

#endif
