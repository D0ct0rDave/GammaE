



#include "GammaE_Mem.h"
#include "GammaE_Scene.h"
// SCNUt_TriSceneAccumulator
#include "SCNUt_TriSceneAccumulator.h"
// SCNUt_Scn2TriScnBuilder
#include "Scn2TriScnBuilder\SCNUt_Scn2TriScnBuilder.h"
// SCNUt_TransformTriScene
#include "TransfTriScn\SCNUt_TransformTriScene.h"
// SCNUt_Mesh2TriScene
#include "Mesh2TriScn\SCNUt_Mesh2TriScene.h"
#define TRANSF_STACK_SIZE   64


// Class SCNUt_Scn2TriScnBuilder 

SCNUt_Scn2TriScnBuilder::SCNUt_Scn2TriScnBuilder()
        {
}


SCNUt_Scn2TriScnBuilder::~SCNUt_Scn2TriScnBuilder()
{
}



SCNUt_TriScene * SCNUt_Scn2TriScnBuilder::poBuild (CObject3D* _poScene, SCNUt_MaterialTable& _oMTable)
{
  	CMatrix4x4			oMatStack[TRANSF_STACK_SIZE];
    oMatStack[0].LoadIdentity();
    
	return (poBuildRec(_poScene,oMatStack,0,_oMTable));
}

SCNUt_TriScene* SCNUt_Scn2TriScnBuilder::poBuildRec (CObject3D* _poScene, CMatrix4x4 *_poMStack, int _iMPos, SCNUt_MaterialTable& _poMTab)
{
  	if (!_poScene) return(NULL);

	switch (_poScene->eGetTypeID())
	{
		case e3DObj_Gen:
									break;

		case e3DObj_Leaf:
		{
			CObject3D_Leaf			*poLeaf;
			CMesh					*poMesh;
			uint					uiMatID;

			poLeaf = (CObject3D_Leaf*)_poScene;
			poMesh = poLeaf->poGetMesh();
			const CE3D_Shader*poShader = poLeaf->poGetShader();
			const char* szShaderName = CE3D_ShaderWH::I()->sGetName( poShader ).szString();
			
			uiMatID = _poMTab.iGetIdx(poShader);

			if (uiMatID == -1)
				uiMatID = _poMTab.uiAdd(poShader, szShaderName);

			return( poBuildMesh (*poMesh,uiMatID,_poMStack[_iMPos]) );
		}
		break;

		case e3DObj_Node:
		{           
			CObject3D_Node				*poNode;
			SCNUt_TriSceneAccumulator	*poTSA;
			SCNUt_TriScene				*poTS = NULL;

			poNode = (CObject3D_Node*)_poScene;

			// Create a triangle scene accumulator
			poTSA = mNew SCNUt_TriSceneAccumulator;

			for (uint uiObj=0;uiObj<poNode->uiNumSubObjs();uiObj++)
			{
				if (poNode->poGetObject(uiObj))
				{
					poTS = poBuildRec(poNode->poGetObject(uiObj),_poMStack,_iMPos,_poMTab);
					poTSA->AddTriScene(poTS);
					
					// Delete retrieved scene
					mDel poTS;
				}
			}

			return(poTSA);
		}
		break;

		case e3DObj_Transf:
		{
            if (_iMPos == TRANSF_STACK_SIZE) return(NULL);

			CObject3D_Transf			*poTransf;			
			poTransf = (CObject3D_Transf*)_poScene;

			// ----------------------------------
			// Update the top of the matrix stack
			// ----------------------------------
			_iMPos++;

			// Multiply by the node matrix
			_poMStack[_iMPos].Multiply( _poMStack[_iMPos-1],poTransf->oTransf());

			return(poBuildRec(poTransf->poGetObject(),_poMStack,_iMPos,_poMTab));
		}
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
		case e3DObj_BSPNode:
		{
			SCNUt_TriSceneAccumulator	*poTSA;
			SCNUt_TriScene				*poTS;			
			CObject3D_BSPNode			*poBSPNode;

			poBSPNode = (CObject3D_BSPNode*)_poScene;
			
			// Create a triangle scene accumulator
			poTSA = mNew SCNUt_TriSceneAccumulator;					

			if (poBSPNode->poGetBackNode())
			{
				poTS = poBuildRec(poBSPNode->poGetBackNode(),_poMStack,_iMPos,_poMTab);
				poTSA->AddTriScene(poTS);
				// Delete retrieved scene
				mDel poTS;
			}

			if (poBSPNode->poGetFrontNode())
			{
				poTS = poBuildRec(poBSPNode->poGetFrontNode(),_poMStack,_iMPos,_poMTab);
				poTSA->AddTriScene(poTS);
				// Delete retrieved scene
				mDel poTS;
			}
			
			return(poTSA);
		}
		break;

		case e3DObj_Mux:    		
									break;
 
		default:					
									break;
	}

	return(NULL);
}

SCNUt_TriScene* SCNUt_Scn2TriScnBuilder::poBuildMesh (CMesh& _oMesh, int _iMat, CMatrix4x4& _oMat)
{
  	SCNUt_Mesh2TriScene		oM2TS;
	SCNUt_TransformTriScene oTrTS;
	SCNUt_TriScene			*poTScn;
		
	poTScn = oM2TS.Generate(_oMesh,_iMat);
    if (! poTScn) return(NULL);

	oTrTS.Transform(poTScn,_oMat);
    
	return(poTScn);
}

// Additional Declarations
    
