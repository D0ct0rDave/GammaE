#ifndef CProjectileH
#define CProjectileH

#include "GammaE.h"
#include "Game/Entities/COrionEnt.h"

typedef struct{
	
	int		iModel;
	float	fSpeed;
	float	fStrenght;
	float	fActionRadius;
	float	fProjPerSec;
	int		iAmmoPack;
	int		iMaxAmmo;
		
}TProjectileProps;

extern TProjectileProps goProjProps[11];

class CProjectile : public COrionEnt
{
	public:
		 CProjectile();
		~CProjectile();

		void Init(int _iType,CVect3 &_roPos,CVect3 &_roDir,float _fSpeed,COrionEnt *_poParent);
		virtual void Think    (float _fDelta);
		virtual void Interact (float _fDelta);
		
		CVect3				oSpeed;		// Current frame speed
		float				fSpeed;		// Current frame speed
		
		float				fLife;		// Life time
		
		COrionEnt			*poTarget;	// Target of this projectile

	private:		
		void CheckForTarget();
		void ToTheTarget();
};

#endif