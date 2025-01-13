//## begin module%3D02277501EE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3D02277501EE.cm

//## begin module%3D02277501EE.cp preserve=no
//## end module%3D02277501EE.cp

//## Module: SCNUt_ShaderAssigner%3D02277501EE; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnShaderAssigner\SCNUt_ShaderAssigner.cpp

//## begin module%3D02277501EE.additionalIncludes preserve=no
//## end module%3D02277501EE.additionalIncludes

//## begin module%3D02277501EE.includes preserve=yes
//## end module%3D02277501EE.includes

// SCNUt_ShaderAssigner
#include "Scene\SceneUtils\ScnShaderAssigner\SCNUt_ShaderAssigner.h"
//## begin module%3D02277501EE.additionalDeclarations preserve=yes
//## end module%3D02277501EE.additionalDeclarations


// Class SCNUt_ShaderAssigner 

SCNUt_ShaderAssigner::SCNUt_ShaderAssigner()
  //## begin SCNUt_ShaderAssigner::SCNUt_ShaderAssigner%.hasinit preserve=no
  //## end SCNUt_ShaderAssigner::SCNUt_ShaderAssigner%.hasinit
  //## begin SCNUt_ShaderAssigner::SCNUt_ShaderAssigner%.initialization preserve=yes
  //## end SCNUt_ShaderAssigner::SCNUt_ShaderAssigner%.initialization
{
  //## begin SCNUt_ShaderAssigner::SCNUt_ShaderAssigner%.body preserve=yes
  //## end SCNUt_ShaderAssigner::SCNUt_ShaderAssigner%.body
}


SCNUt_ShaderAssigner::~SCNUt_ShaderAssigner()
{
  //## begin SCNUt_ShaderAssigner::~SCNUt_ShaderAssigner%.body preserve=yes
  //## end SCNUt_ShaderAssigner::~SCNUt_ShaderAssigner%.body
}



//## Other Operations (implementation)
void SCNUt_ShaderAssigner::AssignShader (CE3D_Shader* _poShader, CObject3D* _poObj)
{
  //## begin SCNUt_ShaderAssigner::AssignShader%1023551463.body preserve=yes
	switch ( _poObj->eGetTypeID() )
	{
		case e3DObj_Gen:			break;
		case e3DObj_Leaf:			((CObject3D_Leaf*)_poObj)->SetShader(_poShader);
									break;
		case e3DObj_Node:			int iSubObj;
									for (iSubObj=0;iSubObj<((CObject3D_Node*)_poObj)->iNumSubObjs();iSubObj++)
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
  //## end SCNUt_ShaderAssigner::AssignShader%1023551463.body
}

// Additional Declarations
  //## begin SCNUt_ShaderAssigner%3D02277501EE.declarations preserve=yes
  //## end SCNUt_ShaderAssigner%3D02277501EE.declarations

//## begin module%3D02277501EE.epilog preserve=yes
//## end module%3D02277501EE.epilog
