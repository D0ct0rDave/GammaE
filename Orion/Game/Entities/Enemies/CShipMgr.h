#ifndef CShipMgrH
#define CShipMgrH

#include "GammaE.h"
#include "Game/Entities/CGameEntity.h"
#include "Game/Entities/CShip.h"

class CShipMgr : public CGameEntity
{  
	public:
		 CShipMgr();
		~CShipMgr();
		void Init(int _iMaxShips);
		virtual void Think		(float _fDelta);
		virtual void ProcessCmds(float _fDelta);
		virtual void Interact	(float _fDelta);
		virtual void ComputeCollisionResponse ();

		void	Add(CShip *poShip);

		CCircularArray <CShip *>	oShips;
};

#endif
