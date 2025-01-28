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
          return (  poInstantiate(poGRes->poGetModel()) );
    }
    else
    {
        // Build a new instance and return it
        
        return (  poGRes->poGetModel() );
    }
}
//-----------------------------------------------------------------------------
CGSceneNode* CGModelWH::poGetModel(const CGString& _sModelName)
{
    CGGraphicResource* poGRes = CGGraphicResourceWH::I()->poLoad(_sModelName);
	if ( poGRes == NULL) return(NULL);
    return (  poGRes->poGetModel() );
}
//-----------------------------------------------------------------------------
CGSceneNode* CGModelWH::poInstantiate(CGSceneNode* _poObj)
{

	switch (_poObj->eGetNodeType())
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
        case ESceneNodeType::SNT_AnimNode:	
            return (poInstantiate((CGSceneAnimNode*)_poObj));
		break;
		case ESceneNodeType::SNT_AnimMesh:	
            return (poInstantiate((CGSceneAnimMesh*)_poObj));
        break;
		case ESceneNodeType::SNT_AnimTransf:	
            return (poInstantiate((CGSceneAnimTransf*)_poObj));
		break;
        case ESceneNodeType::SNT_AnimInstance:
		    return (poInstantiate((CGSceneAnimInstance*)_poObj));
		break;
		
        case ESceneNodeType::SNT_AnimCfg:
            return (poInstantiate((CGSceneAnimCfg*)_poObj));
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

    // Create rendering mesh
    CGMesh* poSrcMesh = _poObj->poGetMesh();

    CGMesh* poMesh = mNew CGMesh;
    poMesh->Init( poSrcMesh->uiGetNumVXs(), poSrcMesh->uiGetNumPrims(), poSrcMesh->eGetPrimitiveType(), MESH_FIELD_VERTEXS | MESH_FIELD_VNORMALS);

    poObj->Setup(poMesh, _poObj->uiGetNumStates(), _poObj->uiGetNumFrameVXs());

    // Set references to original object
    // DMC Refactor
    // poMesh->m_uiNumIdxs = poSrcMesh->usNumIdxs;

    poMesh->m_pusIdx = poSrcMesh->m_pusIdx;
    poMesh->m_poUV  = poSrcMesh->m_poUV;
    poMesh->m_poUV2 = poSrcMesh->m_poUV2;
    poMesh->m_poVC  = poSrcMesh->m_poVC;
    
    poObj->SetShader( _poObj->poGetShader() );

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
