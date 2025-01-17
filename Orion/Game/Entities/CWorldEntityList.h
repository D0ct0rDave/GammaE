#ifndef CWorldEntityList_h
#define CWorldEntityList_h 1

// CGameEntity
#include "Game\Entities\CGameEntity.h"
#include "Game/Entities/COrionEnt.h"

class CWorldEntityList: public CGameEntity  //## Inherits: <unnamed>%3B62D8A701A4
{
	public:
		CWorldEntityList();
		~CWorldEntityList();

		void Init (int _iMaxEntities);
		virtual void Think		(float _fDelta);

	public:
		CCircularArray <COrionEnt*> poEnt;
};


#endif
