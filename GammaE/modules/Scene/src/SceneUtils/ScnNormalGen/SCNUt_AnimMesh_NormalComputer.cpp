//## begin module%3BA7B3200274.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA7B3200274.cm

//## begin module%3BA7B3200274.cp preserve=no
//## end module%3BA7B3200274.cp

//## Module: SCNUt_AnimMesh_NormalComputer%3BA7B3200274; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnNormalGen\SCNUt_AnimMesh_NormalComputer.cpp

//## begin module%3BA7B3200274.additionalIncludes preserve=no
//## end module%3BA7B3200274.additionalIncludes

//## begin module%3BA7B3200274.includes preserve=yes
//## end module%3BA7B3200274.includes

// SCNUt_AnimMesh_NormalComputer
#include "Scene\SceneUtils\ScnNormalGen\SCNUt_AnimMesh_NormalComputer.h"
//## begin module%3BA7B3200274.additionalDeclarations preserve=yes
SCNUt_AnimMesh_NormalComputer	glbAnimMesh_NormalGenerator;
//## end module%3BA7B3200274.additionalDeclarations


// Class SCNUt_AnimMesh_NormalComputer 

SCNUt_AnimMesh_NormalComputer::SCNUt_AnimMesh_NormalComputer()
  //## begin SCNUt_AnimMesh_NormalComputer::SCNUt_AnimMesh_NormalComputer%.hasinit preserve=no
  //## end SCNUt_AnimMesh_NormalComputer::SCNUt_AnimMesh_NormalComputer%.hasinit
  //## begin SCNUt_AnimMesh_NormalComputer::SCNUt_AnimMesh_NormalComputer%.initialization preserve=yes
  //## end SCNUt_AnimMesh_NormalComputer::SCNUt_AnimMesh_NormalComputer%.initialization
{
  //## begin SCNUt_AnimMesh_NormalComputer::SCNUt_AnimMesh_NormalComputer%.body preserve=yes
  //## end SCNUt_AnimMesh_NormalComputer::SCNUt_AnimMesh_NormalComputer%.body
}


SCNUt_AnimMesh_NormalComputer::~SCNUt_AnimMesh_NormalComputer()
{
  //## begin SCNUt_AnimMesh_NormalComputer::~SCNUt_AnimMesh_NormalComputer%.body preserve=yes
  //## end SCNUt_AnimMesh_NormalComputer::~SCNUt_AnimMesh_NormalComputer%.body
}



//## Other Operations (implementation)
void SCNUt_AnimMesh_NormalComputer::Generate (CObject3D_AnimMesh *_pObj)
{
  //## begin SCNUt_AnimMesh_NormalComputer::Generate%1000845950.body preserve=yes
	assert (_pObj && "NULL Animated Mesh Object");

	CObject3D_Leaf *pLeaf     = _pObj->GetLeaf();
	CMesh		   *pLeafMesh = pLeaf->poGetMesh();
	
	CVect3		   *pOldVXs   = pLeafMesh->VXs;
	CVect3		   *pOldVNs   = pLeafMesh->VNs;

	int				iState;	

	for (iState=0;iState<_pObj->iGetNumStates();iState++)
	{
		pLeafMesh->VXs = _pObj->pMeshStates  + _pObj->iGetNumStateVXs()*iState;
		pLeafMesh->VNs = _pObj->pNMeshStates + _pObj->iGetNumStateVXs()*iState;
		
		NormalGen_ComputeVertexsNormals(*pLeafMesh);
	}

	pLeafMesh->VXs = pOldVXs;
	pLeafMesh->VNs = pOldVNs;
  //## end SCNUt_AnimMesh_NormalComputer::Generate%1000845950.body
}

// Additional Declarations
  //## begin SCNUt_AnimMesh_NormalComputer%3BA7B3200274.declarations preserve=yes
  //## end SCNUt_AnimMesh_NormalComputer%3BA7B3200274.declarations

//## begin module%3BA7B3200274.epilog preserve=yes
//## end module%3BA7B3200274.epilog
