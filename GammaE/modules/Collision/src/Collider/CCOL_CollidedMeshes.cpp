//	  %X% %Q% %Z% %W%





// CCOL_CollidedMeshes
#include "Collision\Collider\CCOL_CollidedMeshes.h"


// Class CCOL_CollidedMeshes 



CCOL_CollidedMeshes::CCOL_CollidedMeshes()
        {
}


CCOL_CollidedMeshes::~CCOL_CollidedMeshes()
{
}



void CCOL_CollidedMeshes::Reset ()
{
  	iNumMeshes = 0;
}

void CCOL_CollidedMeshes::AddMesh (CMesh* _pMesh)
{
  	if (iNumMeshes<10)
		pMesh[iNumMeshes++]=_pMesh;
}

int CCOL_CollidedMeshes::iGetNumMeshes ()
{
  	return(iNumMeshes);
}

CMesh* CCOL_CollidedMeshes::pGetMesh (int _iMesh)
{
  	assert ((_iMesh < 10) && "Mesh index out of bounds");
	return (pMesh[_iMesh]);
}

// Additional Declarations
    
