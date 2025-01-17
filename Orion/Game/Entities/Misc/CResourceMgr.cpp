#include "Game/Entities/Misc/CResourceMgr.h"

CResourceMgr::CResourceMgr()
{
	poResBuff	= NULL;
	iNumRes		= 0;
	iPos		= -1;
}

CResourceMgr::~CResourceMgr()
{
	if (poResBuff) mDel []poResBuff;
}

void CResourceMgr::Setup(COrionEnt* _poResBuffer,int _iNumRes,int _iResSize)
{
	assert (_poResBuffer && "NULL Resource buffer");
	assert (_iNumRes     && "Resource buffer with 0 elements");

	poResBuff = _poResBuffer;
	iNumRes	  = _iNumRes;
	iResSize  = _iResSize;
}

COrionEnt *CResourceMgr::poGet()
{
	assert (poResBuff && "Get with NULL Resource buffer");
	
	COrionEnt *poEnt = poResBuff;

	int iCurPos = iPos;
	do{
		
		iPos = (iPos+1) % iNumRes;

		poEnt = (COrionEnt *)((unsigned char *)poResBuff + iPos*iResSize);

		if (! poEnt->bActive)
			return( poEnt );

	}while (iPos != iCurPos);

	// <WARNING>
	return(NULL);
}

