//## begin module%3C74236B016C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C74236B016C.cm

//## begin module%3C74236B016C.cp preserve=no
//## end module%3C74236B016C.cp

//## Module: CMapLoader%3C74236B016C; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\CMapLoader.cpp

//## begin module%3C74236B016C.additionalIncludes preserve=no
//## end module%3C74236B016C.additionalIncludes

//## begin module%3C74236B016C.includes preserve=yes
#include "memory/gammae_mem.h"
#include "misc/Gammae_Misc.h"
#include <stdio.h>
#include <string.h>
//## end module%3C74236B016C.includes

// CMapLoader
#include "Tools\GEMapCompiler\MapData\CMapLoader.h"
//## begin module%3C74236B016C.additionalDeclarations preserve=yes

#define TK_MAPPARS_READY				0
#define TK_MAPPARS_START_BRACKET		1
#define TK_MAPPARS_END_BRACKET			2
#define TK_MAPPARS_CLASSNAME			3
#define TK_MAPPARS_CLASSDEF				4

//## end module%3C74236B016C.additionalDeclarations


// Class CMapLoader 

CMapLoader::CMapLoader()
  //## begin CMapLoader::CMapLoader%.hasinit preserve=no
  //## end CMapLoader::CMapLoader%.hasinit
  //## begin CMapLoader::CMapLoader%.initialization preserve=yes
  //## end CMapLoader::CMapLoader%.initialization
{
  //## begin CMapLoader::CMapLoader%.body preserve=yes
  //## end CMapLoader::CMapLoader%.body
}


CMapLoader::~CMapLoader()
{
  //## begin CMapLoader::~CMapLoader%.body preserve=yes
  //## end CMapLoader::~CMapLoader%.body
}



//## Other Operations (implementation)
CMapScene * CMapLoader::iLoad (char* _szFilename)
{
  //## begin CMapLoader::iLoad%1014246306.body preserve=yes
	
	char	*szMapStream = ParseUtils_ReadFile(_szFilename);
	if (! szMapStream) return(NULL);
	
	char	*szToken;
	char	*szMapStr;
	int		iState;
	int		iOpenBrackets;

	CMapScene	*poMapScn = mNew CMapScene;
	CMapEntity	*poEntity;

	szMapStr		= szMapStream;
	iState			= TK_MAPPARS_READY;
	iOpenBrackets	= 0;

	while (szMapStr)
	{
		NextToken(szToken,szMapStr);
		switch (iState)
		{
			case TK_MAPPARS_READY:
			{
				if (! strcmp(szToken,"{"))
				{
					iState = TK_MAPPARS_START_BRACKET;
					iOpenBrackets++;
				}
			}	
			case TK_MAPPARS_START_BRACKET:
			{
				if (! strcmp(szToken,"\"classname\""))
				{
					iState = TK_MAPPARS_CLASSNAME;
				}
			}
			case TK_MAPPARS_CLASSNAME:
			{
				if (! strcmp(szToken,"\"worldspawn\""))
				{
					ParseWorldSpawn(szMapStr,*poMapScn);
				}

			else if (! strcmp(szToken,"\"light\""))
				{					
					poEntity = poParseLightEntity(szMapStr);
					poMapScn->AddEntity(poEntity);
				}
			else if (! strcmp(szToken,"\"sound\""))
				{					
					poEntity = poParseLightEntity(szMapStr);
					poMapScn->AddEntity(poEntity);
				}
			else if (! strcmp(szToken,"\"monster\""))
				{					
					poEntity = poParseLightEntity(szMapStr);
					poMapScn->AddEntity(poEntity);
				}
			}
		}
	}
	
	free(szMapStream);
	return(poMapScn);
  //## end CMapLoader::iLoad%1014246306.body
}

void CMapLoader::ParseWorldSpawn (char*& _szMapStr, CMapScene& _roMap)
{
  //## begin CMapLoader::ParseWorldSpawn%1014246809.body preserve=yes
	char	*szToken;
	char	*szLine;
	int		iOpenBrackets;
	char	szTexture[80];
	int		iA[3];
	int		iB[3];
	int		iC[3];
	float	fRAngle;
	int		iUOfs,iVOfs;	
	float	fUScale,fVScale;
	CVect3	oVX[3];

	CMapBrush		*poBrush;
	CMapBrushSide	oBSide;

	iOpenBrackets = 0;
	
	while (iOpenBrackets >= 0)
	{		
		if (iOpenBrackets == 0)
		{
			NextToken(szToken,_szMapStr);
			
			if (! strcmp(szToken,"{"))
			{	
				// Create brush
				poBrush = mNew CMapBrush;
				iOpenBrackets++;
			}
	   else if (! strcmp(szToken,"}"))
			{
				iOpenBrackets--;
			}
		}
   else if (iOpenBrackets == 1)
		{
			NextLine(szLine,_szMapStr);
			sscanf(szLine,"( %d %d %d ) ( %d %d %d ) ( %d %d %d ) %s %d %d %f %f %f",
							&iA[0],&iA[1],&iA[2],&iB[0],&iB[1],&iB[2],&iC[0],&iC[1],&iC[2],
							szTexture,
							&iUOfs,&iVOfs,
							&fRAngle,&fUScale,&fVScale);
			
			NextToken(szToken,szLine);

			if (! strcmp(szToken,"}"))
			{
				iOpenBrackets--;
				// Add the brush to the map
				_roMap.AddBrush(poBrush);
			}
			else
			{
				// Setup brush side
				oBSide.oVecs[0].V3((float)iA[0],(float)iA[1],(float)iA[2]);
				oBSide.oVecs[1].V3((float)iB[0],(float)iB[1],(float)iB[2]);
				oBSide.oVecs[2].V3((float)iC[0],(float)iC[1],(float)iC[2]);

				oBSide.oPlane.GenerateFromPoints(oBSide.oVecs[0],oBSide.oVecs[1],oBSide.oVecs[2]);

				strcpy(oBSide.szTex,szTexture);				

				oBSide.fUOfs   = iUOfs;
				oBSide.fVOfs   = iVOfs;
				oBSide.fAngle  = fRAngle;

				oBSide.fUScale = fUScale;
				oBSide.fVScale = fVScale;
				if (oBSide.fUScale == 0.0f) oBSide.fUScale = 1.0f;
				if (oBSide.fVScale == 0.0f) oBSide.fVScale = 1.0f;

				poBrush->AddBrushSide(oBSide);
			}
		}
	}
  //## end CMapLoader::ParseWorldSpawn%1014246809.body
}

CMapEntity * CMapLoader::poParseLightEntity (char*& _szMapStr)
{
  //## begin CMapLoader::poParseLightEntity%1014246810.body preserve=yes
	return(NULL);
  //## end CMapLoader::poParseLightEntity%1014246810.body
}

// Additional Declarations
  //## begin CMapLoader%3C74236B016C.declarations preserve=yes
  //## end CMapLoader%3C74236B016C.declarations

//## begin module%3C74236B016C.epilog preserve=yes
//## end module%3C74236B016C.epilog
