#ifndef CGameEntityList_h
#define CGameEntityList_h 1

// CGameEntity
#include "Game\Entities\CGameEntity.h"

class CGameEntityList: public CGameEntity  //## Inherits: <unnamed>%3B62D8A701A4
{
	public:
		CGameEntityList();
		~CGameEntityList();

		void Init (int _iMaxEntities);
		virtual void Think		(float _fDelta);
	
	public:
		CCircularArray <CGameEntity*> poEnt;
};


#endif
