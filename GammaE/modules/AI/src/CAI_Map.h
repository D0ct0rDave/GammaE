// Map.h: interface for the Map class.
//
//////////////////////////////////////////////////////////////////////
#ifndef CAI_MapH
#define CAI_MapH

class CAI_Map
{
public:
	void NewMap(long width, long height);
	void SetTile(long x, long y, long t);
	long GetTile(long x, long y);
	long m_Height;
	long m_Width;
	CAI_Map();
	virtual ~CAI_Map();
	
	long* lTiles;
};

#endif 