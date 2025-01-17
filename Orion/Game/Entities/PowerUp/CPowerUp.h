#ifndef CPowerUpH
#define CPowerUpH

#include "Game/Entities/COrionEnt.h"

class CPowerUp : public COrionEnt
{
	public:
		 CPowerUp ();
		~CPowerUp ();		

		void SetupPowerUp(int _iPWType,CVect3 &_roPos,COrionEnt *_poParent);
};

#endif