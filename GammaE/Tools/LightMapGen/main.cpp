// MapCompiler.cpp : Defines the entry point for the console application.
//
#include "Memory/GammaE_Mem.h"
#include "Misc/GammaE_Misc.h"
#include "Math/GammaE_Math.h"
#include "E3D/GammaE_E3D.h"
#include "Scene/GammaE_Scene.h"
#include "SceneObjects/GammaE_ScnObj.h"
#include "Terrain/GammaE_Terrain.h"

#include "MapLighting/CLightMapGenerator.h"
#include "game/GameScene/GameMap/MapData/MapEntity/CMapEntities.h"

int main(int argc, char* argv[])
{
	CLoaderGEM			oLoader;
	CSaverGEM			oSaver;	
	CObject3D_Gen		*poObj;
	// Initialize...
	GammaE_E3D::Init();
	CE3D_ShaderWH::Init(1024);
	CE3D_ShaderDefWH::Init(1024);
	CE3D_ShaderDefWH::iAddShaderFile("Shaders.txt");

	// Load .GEM file 
	poObj = (CObject3D_Gen *)oLoader.pLoad("j:/graphics/mapper/cubo.gem");

	// Illuminate the scene
	CMapEnt_Light	oLEnt;
	CMapEntity		*poEnts[1];
	poEnts[0] = &oLEnt;
	oLEnt.iType = 0;
	oLEnt.oPos.V3(100.0f,100.0f,100.0f);

	CLightMapGenerator::SetEntities(poEnts,1);
	CLightMapGenerator::GenerateLighting(poObj);		

	// Save scene
	oSaver.iSave("j:/graphics/mapper/cubo_lit.gem",poObj);

	return 0;
}