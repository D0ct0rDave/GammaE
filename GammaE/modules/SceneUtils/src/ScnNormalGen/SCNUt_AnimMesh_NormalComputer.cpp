




// SCNUt_AnimMesh_NormalComputer
#include "ScnNormalGen\SCNUt_AnimMesh_NormalComputer.h"
SCNUt_AnimMesh_NormalComputer	glbAnimMesh_NormalGenerator;


// Class SCNUt_AnimMesh_NormalComputer 

SCNUt_AnimMesh_NormalComputer::SCNUt_AnimMesh_NormalComputer()
        {
}


SCNUt_AnimMesh_NormalComputer::~SCNUt_AnimMesh_NormalComputer()
{
}



void SCNUt_AnimMesh_NormalComputer::Generate (CObject3D_AnimMesh *_pObj)
{
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
}

// Additional Declarations
    
