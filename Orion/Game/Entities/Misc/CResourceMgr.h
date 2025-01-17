#ifndef CResourceMgrH
#define CResourceMgrH

#include "Game/Entities/COrionEnt.h"

// Hacer con template ???

class CResourceMgr
{
	public:	CResourceMgr();
			~CResourceMgr();

			void Setup(COrionEnt* _poResBuffer,int _iNumRes,int _iResSize);
			COrionEnt	*poGet();

	private:
			COrionEnt	*poResBuff;
			int			iNumRes;			
			int			iPos;
			int			iResSize;
};


#endif