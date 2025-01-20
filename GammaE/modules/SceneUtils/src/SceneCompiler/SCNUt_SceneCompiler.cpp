



#include "GammaE_Mem.h"

// SCNUt_SceneCompiler
#include "SceneCompiler\SCNUt_SceneCompiler.h"


// Class SCNUt_SceneCompiler 


SCNUt_SceneCompiler::SCNUt_SceneCompiler()
        : bNULLMaterials(true)
      {
}


SCNUt_SceneCompiler::~SCNUt_SceneCompiler()
{
}



void SCNUt_SceneCompiler::CompileScene (CObject3D* _poScn)
{
  	int						iObj;
	CObject3D				*poSubObj;
	CCompiledMesh			*poCMesh;
	CObject3D_CompiledLeaf	*poCLeaf;
	CObject3D_Leaf			*poLeaf;

	switch ( _poScn->eGetTypeID() )
	{
		case e3DObj_Gen:			break;
		case e3DObj_Leaf:			break;

		case e3DObj_Node:
		{
			for (iObj=0;iObj<((CObject3D_Node*)_poScn)->uiNumSubObjs();iObj++)
			{
				poSubObj = ((CObject3D_Node*)_poScn)->poGetObject(iObj);

				if (poSubObj)
				{
					if (poSubObj->eGetTypeID() == e3DObj_Leaf)
					{
						poLeaf = (CObject3D_Leaf*)poSubObj;

						// Generate a compiled mesh
						poCMesh = CGRenderer::I()->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

						// Create and setup the compiled node
						poCLeaf = mNew CObject3D_CompiledLeaf;						
						
						poCLeaf->SetShader(bNULLMaterials?NULL:poLeaf->poGetShader());
							
						poCLeaf->SetCMesh(poCMesh);

						// Substitute the old non-compiled leaf node
						((CObject3D_Node*)_poScn)->SetObject(poCLeaf,iObj);

						// We didn't need the old node anymore
						poLeaf->Deref();
					}
					else
						CompileScene(poSubObj);
				}
			}
		}
		break;
		case e3DObj_Transf:
		{
			poSubObj = ((CObject3D_Transf*)_poScn)->poGetObject();
			if ( poSubObj->eGetTypeID() == e3DObj_Leaf)
			{
						poLeaf = (CObject3D_Leaf*) poSubObj;

						// Generate a compiled mesh
						poCMesh = CGRenderer::I()->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

						// Create and setup the compiled node
						poCLeaf = mNew CObject3D_CompiledLeaf;						
						
						poCLeaf->SetShader(bNULLMaterials?NULL:poLeaf->poGetShader());
							
						poCLeaf->SetCMesh(poCMesh);

						// Substitute the old non-compiled leaf node
						((CObject3D_Transf*)_poScn)->SetObject(poCLeaf);

						// We didn't need the old node anymore
						poCLeaf->Deref();
			}
			else
			{
				CompileScene(poSubObj);
			}
		}
		break;

		case e3DObj_AnimGen:		break;
		case e3DObj_AnimNode:		break;
		case e3DObj_AnimMesh:		break;
		case e3DObj_AnimTransf:		break;
		case e3DObj_AnimCfg:		break;
		case e3DObj_AnimCfgMgr:		break;
		case e3DObj_BSPNode:
		{
			// Back node
			poSubObj = ((CObject3D_BSPNode*)_poScn)->poGetBackNode();
			if (poSubObj)
			{
				if ( poSubObj->eGetTypeID() == e3DObj_Leaf)
				{
					poLeaf = (CObject3D_Leaf*)poSubObj;

					// Generate a compiled mesh
					poCMesh = CGRenderer::I()->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

					// Create and setup the compiled node
					poCLeaf = mNew CObject3D_CompiledLeaf;
					poCLeaf->SetShader( bNULLMaterials?NULL:poLeaf->poGetShader());
					poCLeaf->SetCMesh(poCMesh);

					// Substitute the old non-compiled leaf node
					((CObject3D_BSPNode*)_poScn)->SetBackNode(poSubObj);

					// We didn't need the old node anymore
					poLeaf->Deref();
				}
				else					
					CompileScene( poSubObj );
			}
			

			// Front node
			poSubObj = ((CObject3D_BSPNode*)_poScn)->poGetFrontNode();
			if (poSubObj )
			{
				if (poSubObj->eGetTypeID() == e3DObj_Leaf)
				{
					poLeaf = (CObject3D_Leaf*)poSubObj;

					// Generate a compiled mesh
					poCMesh = CGRenderer::I()->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

					// Create and setup the compiled node
					poCLeaf = mNew CObject3D_CompiledLeaf;
					poCLeaf->SetShader( bNULLMaterials?NULL:poLeaf->poGetShader());
					poCLeaf->SetCMesh(poCMesh);

					// Substitute the old non-compiled leaf node
					((CObject3D_BSPNode*)_poScn)->SetFrontNode(poSubObj);

					// We didn't need the old node anymore
					poLeaf->Deref();
				}
				else					
					CompileScene( poSubObj );
			}

		}
									break;
		case e3DObj_Mux:    		//iTest3DObj_Mux(_fd,(CObject3D_Mux*)_pObj);
									break;
		default:					break;
	}
}

// Additional Declarations
    
