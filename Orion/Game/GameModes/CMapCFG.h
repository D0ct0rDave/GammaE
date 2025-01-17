// ----------------------------------------------------------------------------
#ifndef CMapCFGH
#define CMapCFGH
// ----------------------------------------------------------------------------

#ifndef MAX_CHARS
#define MAX_CHARS 256
#endif

#include "GammaE.h"

// ----------------------------------------------------------------------------
typedef struct{
	
	int			iType;
	CVect3		oPos;

}TPowerUpSpawnInfo;


typedef struct
{
	char szLine[MAX_CHARS];

}TDescriptionLine;

typedef struct{

	int		iEnemyType;
	int		iNumSpawns;
	int		iSpawnType;	// 0 h line,1 v line, 2 cross,3 circle
	float	fSpawnDist;
	float	fSpawnTime;
	
	// Runtime field
	float	fCurSpawnTime;

}TEnemySpawnInfo;
// ----------------------------------------------------------------------------
class CMapCFG
{
	public:	 CMapCFG();
			~CMapCFG();

			static bool bLoadMapCFG(char *_szFilename);

	public:
			static char szTrnFile [MAX_CHARS];
			static char szMeshFile[MAX_CHARS];
			static char szMiniMapFile[MAX_CHARS];
			
			static char szMapName [MAX_CHARS];			
			static char szImgFile [MAX_CHARS];

			static char szSndPlayFile[MAX_CHARS];
			static char szBGMFile[MAX_CHARS];

			static CDynArray <TDescriptionLine>		oDescription;

			static CVect3							oPlayerSpawn;
			static CVect3							oBossSpawn;
			static CDynArray <TPowerUpSpawnInfo>	oPWSpawnInfo;
			static CDynArray <TEnemySpawnInfo>		oESpawnInfo;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------