// AStar.h : Declaration of the CAStar

#ifndef CAI_StarH
#define CAI_StarH

/////////////////////////////////////////////////////////////////////////////
// CAStar
#include "CAI_CDXAStar.h"

#ifndef NULL
#define NULL 0
#endif

class CAI_AStar
{
public:

	CAI_AStar()
	{
		pAStar = NULL;
		bAllow8Directions = true;
		Width = 1;
		Height = 1;
	}

	~CAI_AStar()
	{
		if (pAStar != NULL)
		{
			delete pAStar;
		}
	}

// IAStar
public:
	long Height;
	long Width;
	void SetHeight(long lHeight);
	void SetWidth(long lWidth);
	void NewMap(long width, long height);
	void SetTile(long x, long y, long t);
	long lGetTile(long x, long y);
	bool bFindAPath  (long x1, long y1, long x2, long y2);
	bool bGoalReached();
	void NextPathNode();
	long lNodeGetX();
	long lNodeGetY();
	void Allow8Directions(bool bAllowed);

	CAI_Map     map;
	CDXAStar*   pAStar;
	bool bAllow8Directions;

	};

#endif //GameAI_AStar
