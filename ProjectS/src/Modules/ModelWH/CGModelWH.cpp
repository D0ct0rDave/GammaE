//-----------------------------------------------------------------------------
#include "CGModelWH.h"
//-----------------------------------------------------------------------------
CGSceneNode* CGModelWH::poGetInstance(const CGString& _sModelName)
{
    bool bExists = (CGGraphicResourceWH::I()->poFind(_sModelName) != NULL);
    CGGraphicResource* poGRes = CGGraphicResourceWH::I()->poLoad(_sModelName);
    
    if (! bExists)
    {
          // Return directly the loaded model
          return (  poInstantiate(poGRes->poModel()) );
    }
    else
    {
        // Build a new instance and return it
        
        return (  poGRes->poModel() );
    }
}
//-----------------------------------------------------------------------------
CGSceneNode* CGModelWH::poGetModel(const CGString& _sModelName)
{
    CGGraphicResource* poGRes = CGGraphicResourceWH::I()->poLoad(_sModelName);
	if ( poGRes == NULL) return(NULL);
    return (  poGRes->poModel() );
}
//-----------------------------------------------------------------------------
CGSceneNode* CGModelWH::poInstantiate(CGSceneNode* _poObj)
{

	switch (_poObj->eGetTypeID())
	{
	    /*
		case e3DObj_NULL:		return (NULL);
								break;
		case e3DObj_Gen:		return (NULL);
								break;
		case e3DObj_Leaf:		return (pLoad3DObj_Leaf(_oFile));
								break;
		case e3DObj_Node:		return (pLoad3DObj_Node(_oFile));
								break;
		case e3DObj_Transf:		return (pLoad3DObj_Transf(_oFile));
								break;
		case e3DObj_AnimGen:	return (NULL);
								break;
		case e3DObj_Camera:
								break;

		case e3DObj_BSPNode:    return (pLoad3DObj_BSPNode(_oFile));
								break;

		case e3DObj_Mux:        return (pLoad3DObj_Mux(_oFile));
								break;
        */
		case e3DObj_AnimNode:	return (poInstantiate((CGSceneAnimNode*)_poObj));
								break;
		case e3DObj_AnimMesh:	return (poInstantiate((CGSceneAnimMesh*)_poObj));
								break;
		case e3DObj_AnimTransf:	return (poInstantiate((CGSceneAnimTransf*)_poObj));
								break;
		case e3DObj_AnimCfg:	return (poInstantiate((CGSceneAnimCfg*)_poObj));
								break;
		case e3DObj_AnimCfgMgr:	return (poInstantiate((CGSceneAnimCfgMgr*)_poObj));
								break;
	}

	return (NULL);

}
//-----------------------------------------------------------------------------
CGSceneAnimNode* CGModelWH::poInstantiate(CGSceneAnimNode* _poObj)
{
    // TODO
    return ( _poObj );    
    // CObject3D_AnimNode* poNode = mNew CObject3D_AnimNode;
    // poNode->   
}
//-----------------------------------------------------------------------------
CGSceneAnimMesh* CGModelWH::poInstantiate(CGSceneAnimMesh* _poObj)
{
    CGSceneAnimMesh* poObj = mNew CGSceneAnimMesh;

    // Set references to original object
    poObj->CreateStates(_poObj->iGetNumStates(),_poObj->iGetNumStateVXs(),_poObj->pBVolStates,_poObj->pMeshStates,_poObj->pNMeshStates);

    // Create rendering mesh
    CMesh* poSrcMesh = _poObj->Leaf->poGetMesh();
    CMesh* poMesh = mNew CMesh;
    poMesh->Init( poSrcMesh->usNumVerts,poSrcMesh->usNumPrims,poSrcMesh->eMeshType,MESH_FIELD_VERTEXS | MESH_FIELD_VNORMALS);

    // Set references to original object
    poMesh->usNumIdxs = poSrcMesh->usNumIdxs;
    poMesh->Idxs = poSrcMesh->Idxs;
    poMesh->UVs  = poSrcMesh->UVs;
    poMesh->UVs2 = poSrcMesh->UVs2;
    poMesh->VCs  = poSrcMesh->VCs;
    
    // Create Leaf Node
    CGSceneLeaf* poLeaf = mNew CGSceneLeaf;
    poLeaf->SetShader( _poObj->Leaf->poGetShader() );
    poLeaf->SetMesh( poMesh );

    // Setup Animated Mesh
    poObj->SetLeaf( poLeaf );
    
    // Return the instantiated object
    return( poObj);
}
//-----------------------------------------------------------------------------
CGSceneAnimTransf* CGModelWH::poInstantiate(CGSceneAnimTransf* _poObj)
{
    // TODO
    return (_poObj);
}
//-----------------------------------------------------------------------------
CGSceneAnimCfg* CGModelWH::poInstantiate(CGSceneAnimCfg* _poObj)
{
    CGSceneAnimCfg* poObj = mNew CGSceneAnimCfg;

    *poObj = *_poObj;
    poObj->AnimObj = (CObject3D_AnimGen*)poInstantiate( _poObj->AnimObj );

    return (poObj);
}
//-----------------------------------------------------------------------------
CGSceneAnimCfgMgr* CGModelWH::poInstantiate(CGSceneAnimCfgMgr* _poObj)
{
    // TODO
    // CObject3D_AnimCfgMgr* poObj = mNew CObject3D_AnimCfgMgr;
    return (_poObj);
}
//-----------------------------------------------------------------------------
