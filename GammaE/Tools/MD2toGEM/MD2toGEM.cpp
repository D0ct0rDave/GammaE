// MD2toGEM.cpp : Defines the entry point for the console application.
//
#include "GammaE.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{	
	if (argc!=3)
	{
		printf("Invalid number of arguments\n");
		printf("Usage MD2toGEM input.md2 output.gem");
		exit(0);
	}

	// Initialize...	
	CE3D_ShaderWH::Init(1024);
	CE3D_ShaderDefWH::Init(1024);
	CE3D_ShaderDefWH::iAddShaderFile("Shaders.txt");

	// Set bounding volume type
	CGraphBV_Manager::SetBVMode(eGraphBV_Box);

	// Load .MD2 file
	CLoaderMD2	oMD2Loader;
	CObject3D	*poObj;
	printf("Loading MD2 file...");
	poObj = oMD2Loader.pLoadQ2Player(argv[1]);
	printf("Ok\n");
	
	// Compute bounding volume
	printf("Compute bounding volume...\n");
	poObj->ComputeBoundVol();
	printf("Ok\n");

	// Pivot object to the base
	CObject3D_AnimCfg	*poAnim = (CObject3D_AnimCfg*)poObj;
	CObject3D_AnimMesh	*poAMesh= (CObject3D_AnimMesh *)poAnim->AnimObj;
	
	int			iState;
	int			iVert;
	float		fZMin;
	CMatrix4x4	oMat;
	CVect3		*poVXs = poAMesh->pMeshStates;
	CVect3		oBottom;

	for (iState=0;iState<poAnim->AnimObj->iGetNumStates();iState++)
	{	
		
		oBottom.Assign( poAMesh->pBVolStates[iState]->GetCenter());
		oBottom.Sub( 0.0f,0.0f,poAMesh->pBVolStates[iState]->GetExtents().Z());

		oMat.LoadIdentity();
		oMat.Translate3f(0.0f,0.0f,-oBottom.Z());

		for (iVert=0;iVert<poAMesh->iGetNumStateVXs();iVert++)
		{		
			oMat.TransformPoint(*poVXs);
			poVXs++;
		}
				
		poAMesh->pBVolStates[iState]->Transform(oMat);	
	}


	// Save file
	CSaverGEM oSaver;
	printf("Saving GEM file...");
	if (oSaver.iSave(argv[2],poObj))
		printf("Ok\n");
	else
		printf("Error writting file\n");

	return 0;
}