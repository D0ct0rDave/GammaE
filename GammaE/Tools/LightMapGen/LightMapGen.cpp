// MapCompiler.cpp : Defines the entry point for the console application.
//
#include "GammaE.h"

#include "MapLighting/CLightMapGenerator.h"
#include "MapLighting/CLightMapGenerator2.h"
#include "MapLighting/CLightMapGenerator3.h"

#include "tools/GEMapCompiler/MapData/MapEntity/CMapEntities.h"
#include "Game/GameScene/GameMap/GEMap/CGEMapLoader.h"
#include "Game/GameScene/GameMap/GEMap/CGEMapSaver.h"

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("Bad number of arguments\n");
		return(0);
	}

	// Initialize...	
	CE3D_ShaderWH::Init(1024);
	CE3D_ShaderDefWH::Init(1024);
	CE3D_ShaderDefWH::iAddShaderFile("Shaders.txt");

	// --------------
	// Load .GMP file 
	// -----------
	CGEMap *poGEMap;
	poGEMap = CGEMapLoader::poLoad(argv[1]);	

	if (! poGEMap)
	{
		printf("Unable to open %s file\n",argv[1]);
		return(0);
	}
	
	// -----------
	// Traverse all the rooms and seek for entities. Push room into Room Node
	// -----------
	int						iRoom;
	int						iEnt;
	CObject3D_Node			*poRoomNode = mNew CObject3D_Node;
	CDynArray <CMapEntity*>	oGMapEnts;
	CGEMapRoom				*poCurRoom;
	CMapEnt_Light			*poLight;
	
	oGMapEnts.Clear();
	for (iRoom=0;iRoom<poGEMap->aoRooms.iNumElems();iRoom++)
	{
		// Add room scene to room node
		poCurRoom = poGEMap->aoRooms[iRoom];
		poRoomNode->iAddObject(poCurRoom->poScn);
		
		for (iEnt=0;iEnt<poCurRoom->iNumEnts;iEnt++)
		{
			oGMapEnts.iAdd( poCurRoom->poEnts[iEnt] );
			if (poCurRoom->poEnts[iEnt]->eClass == eMapEnt_Light)
			{
				poLight = (CMapEnt_Light *)poCurRoom->poEnts[iEnt];
				// Setup light physical props			
				poLight->fRadius = 200.0f;
				poLight->Color.r = MATH_Common::fRand();
				poLight->Color.g = MATH_Common::fRand();
				poLight->Color.b = 0.75f;
				poLight->Color.a = 1.0f;				
				
			}
		}
	}
	// Mandatory
	poRoomNode->ComputeBoundVol();

	// -----------
	// Illuminate the scene
	// -----------
	TFColor			AmbColor;
	AmbColor.r = 0.35f;
	AmbColor.g = 0.35f;
	AmbColor.b = 0.35f;

	CLightMapGenerator3::SetAmbientColor (AmbColor);	
	CLightMapGenerator3::GenerateLighting(poRoomNode,oGMapEnts);

	// -----------
	// Save GE Map
	// -----------
	CGEMapSaver::Save(argv[2],poGEMap);
	

	// Destroy all...
	mDel poRoomNode;
	oGMapEnts.Clear();

	return 0;
}