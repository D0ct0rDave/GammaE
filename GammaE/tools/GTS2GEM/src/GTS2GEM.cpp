// G2GEM.cpp : Defines the entry point for the console application.
//
// #include "AnsiString.h"
// #include "VCLWrapper.h"

#include "GammaE.h"
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// MEMMgr::Init(1024*1024*20);

	// Obtener el directorio actual
	char szOldDir[1024];
	GetCurrentDirectory(1024,szOldDir);

	// extraer el directorio y establecerlo como actual
	CGString asFullFilename  = (CGString)argv[1];
	CGString asDirectory = Utils::ExtractFileDir(asFullFilename);
	CGString asFilename  = Utils::ExtractFileName(asFullFilename);
	CGString asShortFilename = Utils::ExtractShortFileName(asFullFilename);

	SetCurrentDirectory(asDirectory.szString());
	
	// Let's load the file ...	
	SCNUt_TriSceneLoader oLoader;

	// Save the files...
	// AnsiString asGEMFile = asShortFilename + ".gem";
	// CSaverGEM oSaver;
	// oSaver.iSave((char*)asGEMFile.szString(),poObj);

	
	// Build a trinangle scene
	SCNUt_MaterialTable     oMT;
	// oMT.Init(128);

	SCNUt_TriScene* poScn = oLoader.poLoad( (char*)asFilename.szString(), oMT);

	// Restore old initial directory
	SetCurrentDirectory(szOldDir);

	CGMatrix4x4 oVMat;
	CGMatrix4x4 oNMat;
	const float fScale = 0.01f;	// ok for umbrella
	// const float fScale = 0.03f;	// ok for marvinpig
	// const float fScale = 0.02f; // ok for brainslug
	// const float fScale = 0.01f;	// ok for egg
	oVMat.LoadIdentity();
	oVMat.Scale(fScale,fScale,fScale);
	oNMat.LoadIdentity();
	
	SCNUt_TransformTriScene oScnTransf;
	oScnTransf.Transform(poScn,oVMat,oNMat);
	
	// Normalize normals ... just in case	
	for (uint i=0;i<poScn->NumTris;i++)
	{
		poScn->Tris[i].VNs[0].Normalize();
		poScn->Tris[i].VNs[1].Normalize();
		poScn->Tris[i].VNs[2].Normalize();
	}

	// Build scene
	SCNUt_SceneBuilder oSB;
	CGSceneNode* poObj2 = oSB.poBuildScene(*poScn,oMT);

	// Save the files...
	CSaverGEM oSaver;
	CGString asGEMFile = asShortFilename + ".gem";
 	oSaver.bSave(asGEMFile,poObj2);

	return 0;
}
