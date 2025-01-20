//## begin module%3C2BCDC90337.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2BCDC90337.cm

//## begin module%3C2BCDC90337.cp preserve=no
//## end module%3C2BCDC90337.cp

//## Module: SCNUt_Scn2TriScnBuilder%3C2BCDC90337; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\Scn2TriScnBuilder\SCNUt_Scn2TriScnBuilder.cpp

//## begin module%3C2BCDC90337.additionalIncludes preserve=no
//## end module%3C2BCDC90337.additionalIncludes

//## begin module%3C2BCDC90337.includes preserve=yes
#include "Memory/GammaE_Mem.h"
//## end module%3C2BCDC90337.includes

// CObject3D_BSPNode
#include "Scene\CObject3D_BSPNode.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
// SCNUt_TriSceneAccumulator
#include "Scene\SceneUtils\SCNUt_TriSceneAccumulator.h"
// SCNUt_Scn2TriScnBuilder
#include "Scene\SceneUtils\Scn2TriScnBuilder\SCNUt_Scn2TriScnBuilder.h"
// SCNUt_TransformTriScene
#include "Scene\SceneUtils\TransfTriScn\SCNUt_TransformTriScene.h"
// SCNUt_Mesh2TriScene
#include "Scene\SceneUtils\Mesh2TriScn\SCNUt_Mesh2TriScene.h"
//## begin module%3C2BCDC90337.additionalDeclarations preserve=yes
#define TRANSF_STACK_SIZE   64
//## end module%3C2BCDC90337.additionalDeclarations


// Class SCNUt_Scn2TriScnBuilder 

SCNUt_Scn2TriScnBuilder::SCNUt_Scn2TriScnBuilder()
  //## begin SCNUt_Scn2TriScnBuilder::SCNUt_Scn2TriScnBuilder%.hasinit preserve=no
  //## end SCNUt_Scn2TriScnBuilder::SCNUt_Scn2TriScnBuilder%.hasinit
  //## begin SCNUt_Scn2TriScnBuilder::SCNUt_Scn2TriScnBuilder%.initialization preserve=yes
  //## end SCNUt_Scn2TriScnBuilder::SCNUt_Scn2TriScnBuilder%.initialization
{
  //## begin SCNUt_Scn2TriScnBuilder::SCNUt_Scn2TriScnBuilder%.body preserve=yes
  //## end SCNUt_Scn2TriScnBuilder::SCNUt_Scn2TriScnBuilder%.body
}


SCNUt_Scn2TriScnBuilder::~SCNUt_Scn2TriScnBuilder()
{
  //## begin SCNUt_Scn2TriScnBuilder::~SCNUt_Scn2TriScnBuilder%.body preserve=yes
  //## end SCNUt_Scn2TriScnBuilder::~SCNUt_Scn2TriScnBuilder%.body
}



//## Other Operations (implementation)
SCNUt_TriScene * SCNUt_Scn2TriScnBuilder::poBuild (CObject3D* _poScene, SCNUt_MaterialTable& _roMTable)
{
  //## begin SCNUt_Scn2TriScnBuilder::poBuild%1009496920.body preserve=yes
	CMatrix4x4			oMatStack[TRANSF_STACK_SIZE];
    oMatStack[0].LoadIdentity();
    
	return (poBuildRec(_poScene,oMatStack,0,_roMTable));
  //## end SCNUt_Scn2TriScnBuilder::poBuild%1009496920.body
}

SCNUt_TriScene* SCNUt_Scn2TriScnBuilder::poBuildRec (CObject3D* _poScene, CMatrix4x4 *_poMStack, int _iMPos, SCNUt_MaterialTable& _poMTab)
{
  //## begin SCNUt_Scn2TriScnBuilder::poBuildRec%1009496922.body preserve=yes
	if (!_poScene) return(NULL);

	switch (_poScene->eGetTypeID())
	{
		case e3DObj_Gen:
									break;

		case e3DObj_Leaf:
		{
			CObject3D_Leaf			*poLeaf;
			CMesh					*poMesh;
			int						iMatID;

			poLeaf = (CObject3D_Leaf*)_poScene;
			poMesh = poLeaf->poGetMesh();
			iMatID = _poMTab.iAddShader( poLeaf->poGetShader() );

			return( poBuildMesh (*poMesh,iMatID,_poMStack[_iMPos]) );
		}
		break;

		case e3DObj_Node:
		{           
			int							iObj;
			CObject3D_Node				*poNode;
			SCNUt_TriSceneAccumulator	*poTSA;
			SCNUt_TriScene				*poTS;

			poNode = (CObject3D_Node*)_poScene;

			// Create a triangle scene accumulator
			poTSA = mNew SCNUt_TriSceneAccumulator;

			for (iObj=0;iObj<poNode->iNumSubObjs();iObj++)
			{
				if (poNode->poGetObject(iObj))
				{
					poTS = poBuildRec(poNode->poGetObject(iObj),_poMStack,_iMPos,_poMTab);
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
			_poMStack[_iMPos].Multiply( _poMStack[_iMPos-1],poTransf->roTransf());

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
  //## end SCNUt_Scn2TriScnBuilder::poBuildRec%1009496922.body
}

SCNUt_TriScene* SCNUt_Scn2TriScnBuilder::poBuildMesh (CMesh& _roMesh, int _iMat, CMatrix4x4& _roMat)
{
  //## begin SCNUt_Scn2TriScnBuilder::poBuildMesh%1009496923.body preserve=yes
	SCNUt_Mesh2TriScene		oM2TS;
	SCNUt_TransformTriScene oTrTS;
	SCNUt_TriScene			*poTScn;
		
	poTScn = oM2TS.Generate(_roMesh,_iMat);
    if (! poTScn) return(NULL);

	oTrTS.Transform(*poTScn,_roMat);
    
	return(poTScn);
  //## end SCNUt_Scn2TriScnBuilder::poBuildMesh%1009496923.body
}

// Additional Declarations
  //## begin SCNUt_Scn2TriScnBuilder%3C2BCDC90337.declarations preserve=yes
  //## end SCNUt_Scn2TriScnBuilder%3C2BCDC90337.declarations

//## begin module%3C2BCDC90337.epilog preserve=yes
//## end module%3C2BCDC90337.epilog
