




// SCNUt_ShaderAssigner
#include "ScnShaderAssigner\SCNUt_ShaderAssigner.h"


// Class SCNUt_ShaderAssigner 

SCNUt_ShaderAssigner::SCNUt_ShaderAssigner()
        {
}


SCNUt_ShaderAssigner::~SCNUt_ShaderAssigner()
{
}



void SCNUt_ShaderAssigner::AssignShader (CE3D_Shader* _poShader, CObject3D* _poObj)
{
  	switch ( _poObj->eGetTypeID() )
	{
		case e3DObj_Gen:			break;
		case e3DObj_Leaf:			((CObject3D_Leaf*)_poObj)->SetShader(_poShader);
									break;
		case e3DObj_Node:			int iSubObj;
									for (iSubObj=0;iSubObj<((CObject3D_Node*)_poObj)->uiNumSubObjs();iSubObj++)
									{
										if ( ((CObject3D_Node*)_poObj)->poGetObject(iSubObj))
											AssignShader(_poShader,((CObject3D_Node*)_poObj)->poGetObject(iSubObj));
									}		
									break;
		case e3DObj_Transf:			AssignShader(_poShader, ((CObject3D_Transf*)_poObj)->poGetObject() );
									break;
		case e3DObj_AnimGen:		
									break;
		case e3DObj_AnimNode:		
									break;
		case e3DObj_AnimMesh:		
									break;
		case e3DObj_AnimTransf:		
									break;
		case e3DObj_AnimCfg:		
									break;
		case e3DObj_AnimCfgMgr:		
									break;
		case e3DObj_BSPNode:		AssignShader(_poShader, ((CObject3D_BSPNode*)_poObj)->poGetBackNode()  );
									AssignShader(_poShader, ((CObject3D_BSPNode*)_poObj)->poGetFrontNode() );
									break;
		case e3DObj_Mux:    		//iTest3DObj_Mux(_fd,(CObject3D_Mux*)_poObj);
									break;
		case e3DObj_CompiledLeaf:	((CObject3D_CompiledLeaf*)_poObj)->SetShader( _poShader);
									break;
		default:					
									break;
	}
}

// Additional Declarations
    
