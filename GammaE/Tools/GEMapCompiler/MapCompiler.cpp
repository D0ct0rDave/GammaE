// MapCompiler.cpp : Defines the entry point for the console application.
//
#include "Memory/GammaE_Mem.h"
#include "Misc/GammaE_Misc.h"
#include "Math/GammaE_Math.h"
#include "E3D/GammaE_E3D.h"
#include "Scene/GammaE_Scene.h"
#include "SceneObjects/GammaE_ScnObj.h"
#include "Terrain/GammaE_Terrain.h"

#include "MapData/CMapLoader.h"
#include "MapData/CMapScene.h"
#include "MapData/CMapTriSceneGen.h"
#include "QLEMap/CQLEMapLoader.h"
#include "QLEMap/CQLEMapScn.h"
#include "CGEMapGenerator.h"
#include "Game/GameScene/GameMap/GEMap/CGEMapSaver.h"
#include "Game/GameScene/GameMap/GEMap/CGEMapLoader.h"


#include <stdlib.h>

#ifdef _BORLANDC_
	#include <dir.h>
#else
	#ifdef _MBCS
	#include <direct.h>
	#endif
#endif

int main(int argc, char* argv[])
{	
	if (argc < 4)
	{
		printf("Invalid number of arguments\n");
		return(0);
	}

	CSaverGEM			oSaver;
	SCNUt_SceneBuilder	oScnBuild;
	
	// Initialize...	
	CE3D_ShaderWH::Init(1024);
	CE3D_ShaderDefWH::Init(1024);
	CE3D_ShaderDefWH::iAddShaderFile("Shaders.txt");

	CQLEMapScn		*poScn;
	CQLEMapLoader	oQLELoader;
	CGEMapGenerator	oGEMapGen;
	CGEMap			*poGEMap;

	chdir(argv[1]);
	
	// We want rooms to be bounding boxes
	CGraphBV_Manager::SetBVMode(eGraphBV_Box);
	
	// Load raw map data
	poScn   = oQLELoader.iLoad(argv[2]);

	// Generate GE data
	oGEMapGen.SetTexturePath(argv[1]);
	poGEMap = oGEMapGen.poGenerate(poScn);

	// Save GE data
	CGEMapSaver::Save(argv[3],poGEMap);
	poGEMap = CGEMapLoader::poLoad(argv[3]);

	return 0;
}