//## begin module%3C51E67003B5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C51E67003B5.cm

//## begin module%3C51E67003B5.cp preserve=no
//## end module%3C51E67003B5.cp

//## Module: SCNUt_SceneCompiler%3C51E67003B5; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SceneCompiler\SCNUt_SceneCompiler.cpp

//## begin module%3C51E67003B5.additionalIncludes preserve=no
//## end module%3C51E67003B5.additionalIncludes

//## begin module%3C51E67003B5.includes preserve=yes
#include "Memory/GammaE_Mem.h"
//## end module%3C51E67003B5.includes

// SCNUt_SceneCompiler
#include "Scene\SceneUtils\SceneCompiler\SCNUt_SceneCompiler.h"
//## begin module%3C51E67003B5.additionalDeclarations preserve=yes
//## end module%3C51E67003B5.additionalDeclarations


// Class SCNUt_SceneCompiler 


SCNUt_SceneCompiler::SCNUt_SceneCompiler()
  //## begin SCNUt_SceneCompiler::SCNUt_SceneCompiler%.hasinit preserve=no
      : bNULLMaterials(true)
  //## end SCNUt_SceneCompiler::SCNUt_SceneCompiler%.hasinit
  //## begin SCNUt_SceneCompiler::SCNUt_SceneCompiler%.initialization preserve=yes
  //## end SCNUt_SceneCompiler::SCNUt_SceneCompiler%.initialization
{
  //## begin SCNUt_SceneCompiler::SCNUt_SceneCompiler%.body preserve=yes
  //## end SCNUt_SceneCompiler::SCNUt_SceneCompiler%.body
}


SCNUt_SceneCompiler::~SCNUt_SceneCompiler()
{
  //## begin SCNUt_SceneCompiler::~SCNUt_SceneCompiler%.body preserve=yes
  //## end SCNUt_SceneCompiler::~SCNUt_SceneCompiler%.body
}



//## Other Operations (implementation)
void SCNUt_SceneCompiler::CompileScene (CObject3D* _poScn)
{
  //## begin SCNUt_SceneCompiler::CompileScene%1011999903.body preserve=yes
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
			for (iObj=0;iObj<((CObject3D_Node*)_poScn)->iNumSubObjs();iObj++)
			{
				poSubObj = ((CObject3D_Node*)_poScn)->poGetObject(iObj);

				if (poSubObj)
				{
					if (poSubObj->eGetTypeID() == e3DObj_Leaf)
					{
						poLeaf = (CObject3D_Leaf*)poSubObj;

						// Generate a compiled mesh
						poCMesh = gpoE3DRenderer->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

						// Create and setup the compiled node
						poCLeaf = mNew CObject3D_CompiledLeaf;						
						
						poCLeaf->SetShader(bNULLMaterials?NULL:poLeaf->poGetShader());
							
						poCLeaf->SetCMesh(poCMesh);

						// Substitute the old non-compiled leaf node
						((CObject3D_Node*)_poScn)->SetObject(poCLeaf,iObj);

						// We didn't need the old node anymore
						poLeaf->UnReference();
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
						poCMesh = gpoE3DRenderer->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

						// Create and setup the compiled node
						poCLeaf = mNew CObject3D_CompiledLeaf;						
						
						poCLeaf->SetShader(bNULLMaterials?NULL:poLeaf->poGetShader());
							
						poCLeaf->SetCMesh(poCMesh);

						// Substitute the old non-compiled leaf node
						((CObject3D_Transf*)_poScn)->SetObject(poCLeaf);

						// We didn't need the old node anymore
						poCLeaf->UnReference();
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
					poCMesh = gpoE3DRenderer->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

					// Create and setup the compiled node
					poCLeaf = mNew CObject3D_CompiledLeaf;
					poCLeaf->SetShader( bNULLMaterials?NULL:poLeaf->poGetShader());
					poCLeaf->SetCMesh(poCMesh);

					// Substitute the old non-compiled leaf node
					((CObject3D_BSPNode*)_poScn)->SetBackNode(poSubObj);

					// We didn't need the old node anymore
					poLeaf->UnReference();
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
					poCMesh = gpoE3DRenderer->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

					// Create and setup the compiled node
					poCLeaf = mNew CObject3D_CompiledLeaf;
					poCLeaf->SetShader( bNULLMaterials?NULL:poLeaf->poGetShader());
					poCLeaf->SetCMesh(poCMesh);

					// Substitute the old non-compiled leaf node
					((CObject3D_BSPNode*)_poScn)->SetFrontNode(poSubObj);

					// We didn't need the old node anymore
					poLeaf->UnReference();
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
  //## end SCNUt_SceneCompiler::CompileScene%1011999903.body
}

// Additional Declarations
  //## begin SCNUt_SceneCompiler%3C51E67003B5.declarations preserve=yes
  //## end SCNUt_SceneCompiler%3C51E67003B5.declarations

//## begin module%3C51E67003B5.epilog preserve=yes
//## end module%3C51E67003B5.epilog
