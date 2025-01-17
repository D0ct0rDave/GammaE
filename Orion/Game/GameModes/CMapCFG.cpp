// ----------------------------------------------------------------------------
#include "CMapCFG.h"
// ----------------------------------------------------------------------------
char							CMapCFG::szMapName [MAX_CHARS];
CDynArray <TDescriptionLine>	CMapCFG::oDescription;
char							CMapCFG::szImgFile [MAX_CHARS];
char							CMapCFG::szTrnFile [MAX_CHARS];
char							CMapCFG::szMeshFile[MAX_CHARS];
char							CMapCFG::szMiniMapFile[MAX_CHARS];

char							CMapCFG::szSndPlayFile[MAX_CHARS];
char							CMapCFG::szBGMFile[MAX_CHARS];

CVect3							CMapCFG::oPlayerSpawn;
CVect3							CMapCFG::oBossSpawn;
CDynArray <TPowerUpSpawnInfo>	CMapCFG::oPWSpawnInfo;
CDynArray <TEnemySpawnInfo>		CMapCFG::oESpawnInfo;
// ----------------------------------------------------------------------------
CMapCFG::CMapCFG()
{
}

CMapCFG::~CMapCFG()
{
}

// ----------------------------------------------------------------------------
bool CMapCFG::bLoadMapCFG(char *_szFilename)
{
	char *szStrmFile = ParseUtils_ReadFile(_szFilename);		
	if (! szStrmFile) return(false);

	TEnemySpawnInfo		tESI;
	TPowerUpSpawnInfo	tPWSI;
	CVect3				oPos;

	char				*szToken,*szLine,*szStream = szStrmFile;
	
	NextToken(szToken,szStream);

	// Read Name	
	if (! stricmp(szToken,"MAPNAME"))
	{
		NextLine(szLine,szStream);
		strcpy(szMapName,szLine);
		NextToken(szToken,szStream);
	}

	// Read Description	
	TDescriptionLine	oDescLine;
	do{		
		
		if (! stricmp(szToken,"DESCRIPTION"))
		{
			NextLine(szLine,szStream);
			strcpy(oDescLine.szLine,szLine);
			oDescription.iAdd(oDescLine);
			
			NextToken(szToken,szStream);
		}

	}while(! stricmp(szToken,"DESCRIPTION"));

	// Read Image filename
	if (! stricmp(szToken,"IMAGE"))
	{
		NextToken(szToken,szStream);
		strcpy(szImgFile,szToken);
		
		NextToken(szToken,szStream);
	}
	
	// Read Terrain filename	
	if (! stricmp(szToken,"TERRAIN"))
	{
		NextToken(szToken,szStream);
		strcpy(szTrnFile,szToken);

		NextToken(szToken,szStream);
	}
	
	// Read Mesh filename	
	if (! stricmp(szToken,"MESH"))
	{
		NextToken(szToken,szStream);
		strcpy(szMeshFile,szToken);

		NextToken(szToken,szStream);
	}

	// Read Minimap filename	
	if (! stricmp(szToken,"MINIMAP"))
	{
		NextToken(szToken,szStream);
		strcpy(szMiniMapFile,szToken);

		NextToken(szToken,szStream);
	}

	// Read Sound player filename
	if (! stricmp(szToken,"SOUNDPLAY"))
	{
		NextToken(szToken,szStream);
		strcpy(szSndPlayFile,szToken);

		NextToken(szToken,szStream);
	}

	// Read BGM filename
	if (! stricmp(szToken,"BGM"))
	{
		NextToken(szToken,szStream);
		strcpy(szBGMFile,szToken);

		NextToken(szToken,szStream);
	}

	// Read Player spawn info
	if (! stricmp(szToken,"PLAYERSPAWN"))
	{
		NextLine(szLine,szStream);
		int iScans = sscanf(szLine,"%f %f %f",&oPlayerSpawn.v[0],&oPlayerSpawn.v[1],&oPlayerSpawn.v[2]);

		NextToken(szToken,szStream);
	}

	// Read Boss spawn info
	if (! stricmp(szToken,"BOSSSPAWN"))
	{
		NextLine(szLine,szStream);
		int iScans = sscanf(szLine,"%f %f %f",&oBossSpawn.v[0],&oBossSpawn.v[1],&oBossSpawn.v[2]);

		NextToken(szToken,szStream);
	}

	// Read Powerup spawn info
	do{
		if (! stricmp(szToken,"POWERUPSPAWN"))
		{
			NextLine(szLine,szStream);
			int iScans = sscanf(szLine,"%d %f %f %f",
								&tPWSI.iType,
								&tPWSI.oPos.v[0],
								&tPWSI.oPos.v[1],
								&tPWSI.oPos.v[2]);

			if (iScans == 4)		
				oPWSpawnInfo.iAdd(tPWSI);

			NextToken(szToken,szStream);		
		}
	}while (! stricmp(szToken,"POWERUPSPAWN"));



	// Read Enemy spawn info
	do{
		if (! stricmp(szToken,"ENEMYSPAWN"))
		{	
			NextLine(szLine,szStream);

			// Clear info
			memset(&tESI,0,sizeof(TEnemySpawnInfo));

			int iScans = sscanf(szLine,"%d %d %d %f %f",
								&tESI.iEnemyType,
								&tESI.iNumSpawns,
								&tESI.iSpawnType,
								&tESI.fSpawnDist,
								&tESI.fSpawnTime);

			if (iScans == 5)		
				oESpawnInfo.iAdd(tESI);

			NextToken(szToken,szStream);		
		}
	}while (! stricmp(szToken,"ENEMYSPAWN"));

	mFree(szStrmFile);
	return(true);
}
// ----------------------------------------------------------------------------