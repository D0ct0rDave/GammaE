//## begin module%3C0ED68801F2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0ED68801F2.cm

//## begin module%3C0ED68801F2.cp preserve=no
//## end module%3C0ED68801F2.cp

//## Module: CCOL_CollidedMeshes%3C0ED68801F2; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\Collider\CCOL_CollidedMeshes.cpp

//## begin module%3C0ED68801F2.additionalIncludes preserve=no
//## end module%3C0ED68801F2.additionalIncludes

//## begin module%3C0ED68801F2.includes preserve=yes
//## end module%3C0ED68801F2.includes

// CCOL_CollidedMeshes
#include "Collision\Collider\CCOL_CollidedMeshes.h"
//## begin module%3C0ED68801F2.additionalDeclarations preserve=yes
//## end module%3C0ED68801F2.additionalDeclarations


// Class CCOL_CollidedMeshes 



CCOL_CollidedMeshes::CCOL_CollidedMeshes()
  //## begin CCOL_CollidedMeshes::CCOL_CollidedMeshes%.hasinit preserve=no
  //## end CCOL_CollidedMeshes::CCOL_CollidedMeshes%.hasinit
  //## begin CCOL_CollidedMeshes::CCOL_CollidedMeshes%.initialization preserve=yes
  //## end CCOL_CollidedMeshes::CCOL_CollidedMeshes%.initialization
{
  //## begin CCOL_CollidedMeshes::CCOL_CollidedMeshes%.body preserve=yes
  //## end CCOL_CollidedMeshes::CCOL_CollidedMeshes%.body
}


CCOL_CollidedMeshes::~CCOL_CollidedMeshes()
{
  //## begin CCOL_CollidedMeshes::~CCOL_CollidedMeshes%.body preserve=yes
  //## end CCOL_CollidedMeshes::~CCOL_CollidedMeshes%.body
}



//## Other Operations (implementation)
void CCOL_CollidedMeshes::Reset ()
{
  //## begin CCOL_CollidedMeshes::Reset%1007604297.body preserve=yes
	iNumMeshes = 0;
  //## end CCOL_CollidedMeshes::Reset%1007604297.body
}

void CCOL_CollidedMeshes::AddMesh (CMesh* _pMesh)
{
  //## begin CCOL_CollidedMeshes::AddMesh%1007604298.body preserve=yes
	if (iNumMeshes<10)
		pMesh[iNumMeshes++]=_pMesh;
  //## end CCOL_CollidedMeshes::AddMesh%1007604298.body
}

int CCOL_CollidedMeshes::iGetNumMeshes ()
{
  //## begin CCOL_CollidedMeshes::iGetNumMeshes%1007604299.body preserve=yes
	return(iNumMeshes);
  //## end CCOL_CollidedMeshes::iGetNumMeshes%1007604299.body
}

CMesh* CCOL_CollidedMeshes::pGetMesh (int _iMesh)
{
  //## begin CCOL_CollidedMeshes::pGetMesh%1007604300.body preserve=yes
	assert ((_iMesh < 10) && "Mesh index out of bounds");
	return (pMesh[_iMesh]);
  //## end CCOL_CollidedMeshes::pGetMesh%1007604300.body
}

// Additional Declarations
  //## begin CCOL_CollidedMeshes%3C0ED68801F2.declarations preserve=yes
  //## end CCOL_CollidedMeshes%3C0ED68801F2.declarations

//## begin module%3C0ED68801F2.epilog preserve=yes
//## end module%3C0ED68801F2.epilog
