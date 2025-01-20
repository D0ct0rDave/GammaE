//	  %X% %Q% %Z% %W%





// CCOL_TriListGen
#include "COL_TriList\CCOL_TriListGen.h"


// Class CCOL_TriListGen 

CMesh* *CCOL_TriListGen::poMeshes = NULL;

int *CCOL_TriListGen::piMats = NULL;

int CCOL_TriListGen::iNumMeshes = 0;


CCOL_TriListGen::CCOL_TriListGen()
        {
}


CCOL_TriListGen::~CCOL_TriListGen()
{
}



int CCOL_TriListGen::GetTriList (CCOL_TriList& _oTriList, CVect3& _oPos, float _fRadius)
{
  	return(0);
}

void CCOL_TriListGen::SetMeshes (CMesh** _poMeshes, int* _piMats, int _iNumMeshes)
{
  	poMeshes	= _poMeshes;
	piMats		= _piMats;
	iNumMeshes	= _iNumMeshes;	
}

int CCOL_TriListGen::GetTrisFromMesh (CCOL_TriList& _oTriList, CMesh* _poMesh, int _iMat, CVect3& _oPos, float _fRadius)
{
  	return(0);
}

// Additional Declarations
    
