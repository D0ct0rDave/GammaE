//	  %X% %Q% %Z% %W%





// CCOL_Scn_ColTester
#include "COL_Testers\COL_SceneTest\CCOL_Scn_ColTester.h"


// Class CCOL_Scn_ColTester 

CObject3D *CCOL_Scn_ColTester::SGrObj = NULL;

CObject3D *CCOL_Scn_ColTester::DGrObj = NULL;

int CCOL_Scn_ColTester::iNumColMeshes = 0;

CCOL_Mesh CCOL_Scn_ColTester::ColMeshes[64];

CCOL_Scn_ColTester::~CCOL_Scn_ColTester()
{
}



int CCOL_Scn_ColTester::iTestObjects ()
{
  	
	// Setup Collision tester object
	iNumColMeshes = 0;

	return ( iTest3DObj_Rec(DGrObj) );
}

int CCOL_Scn_ColTester::iTest3DObj_Rec (CObject3D *_poObj)
{
    	int				iRes;	

	switch ( _poObj->eGetTypeID() )
	{
		case e3DObj_Gen:			iRes = iTest3DObj((CObject3D*)_poObj);
									break;
		case e3DObj_Leaf:			iRes = iTest3DObj_Leaf((CObject3D_Leaf*)_poObj);
									break;
		case e3DObj_Node:			iRes = iTest3DObj_Node((CObject3D_Node*)_poObj);
									break;
		case e3DObj_Transf:			iRes = iTest3DObj_Transf((CObject3D_Transf*)_poObj);
									break;
		case e3DObj_AnimGen:		iRes = 0;
									break;
		case e3DObj_AnimNode:		iRes = 0;//iSave3DObj_AnimNode(_fd,(CObject3D_AnimNode*)_poObj);
									break;
		case e3DObj_AnimMesh:		iRes = 0;//iSave3DObj_AnimMesh(_fd,(CObject3D_AnimMesh*)_poObj);
									break;
		case e3DObj_AnimTransf:		iRes = 0;//iSave3DObj_AnimTransf(_fd,(CObject3D_AnimTransf*)_poObj);
									break;
		case e3DObj_AnimCfg:		iRes = 0;//iSave3DObj_AnimCfg(_fd,(CObject3D_AnimCfg*)_poObj);
									break;
		case e3DObj_AnimCfgMgr:		iRes = 0;//iSave3DObj_AnimCfgMgr(_fd,(CObject3D_AnimCfgMgr*)_poObj);
									break;
		case e3DObj_BSPNode:		iRes = iTest3DObj_BSPNode((CObject3D_BSPNode*)_poObj);
									break;
		case e3DObj_Mux:    		iRes = 0;//iTest3DObj_Mux(_fd,(CObject3D_Mux*)_poObj);
									break;
		case e3DObj_CompiledLeaf:	iRes = iTest3DObj_CompiledLeaf((CObject3D_CompiledLeaf*)_poObj);
									break;
		default:					iRes = 0;
									break;
	}

	return(iRes);
}

int CCOL_Scn_ColTester::iTest3DObj (CObject3D* _poObj)
{
    	if (iNumColMeshes == 64) return(0);

	float fFrameFact;
	fFrameFact = CCOL_DT_ColTester::fTestCollision(SGrObj->poGetBoundVol(),_poObj->poGetBoundVol());

	if (fFrameFact >= 0.0f)
	{
		ColMeshes[iNumColMeshes++].Set(NULL,-1,fFrameFact);
		return(1);
	}
	else 
		return(0);
}

int CCOL_Scn_ColTester::iTest3DObj_Node (CObject3D_Node* _poObj)
{
  
	// Look if there is a collision with the complete group
	if (CCOL_DT_ColTester::fTestCollision(SGrObj->poGetBoundVol(),_poObj->poGetBoundVol()) < 0.0f)
		return(0);

	int			 iRes;
	uint		 uiObj;
	CObject3D	*pSubObj;

	iRes = 0;
	for (uiObj=0;uiObj<_poObj->uiNumSubObjs();uiObj++)
	{
		pSubObj = _poObj->poGetObject(uiObj);

		if (pSubObj)
		{
			iRes |= iTest3DObj_Rec(pSubObj);
		}
	}

	return (iRes);
}

int CCOL_Scn_ColTester::iTest3DObj_Transf (CObject3D_Transf* _poObj)
{
  	if (CCOL_DT_ColTester::fTestCollision(SGrObj->poGetBoundVol(),_poObj->poGetBoundVol()) < 0.0f)
		return(0);
	else
	{
		return(1);

		// Aqui se deberia poder realizar un test más fino. Para ello probablemente
		// se debería de poder transformar las velocidades y las bounding volumes
		// del objeto al sistema de referencia del objeto _poObj.

		// O eso, o transformar lo que cuelga de este nodo al sistema de referencia
		// común, lo que implica transformar mallas de triangulos que probablemente
		// cuelguen de aquí.

		// Si se hace lo primero, al salir de la llamada se debe restaurar el 
		// contexto al antiguo.
		CGraphBV_Box oBox;
		oBox.Copy(SGrObj->poGetBoundVol());
		
		CMatrix4x4 oInvMat;
		oInvMat = _poObj->oTransf();
		oInvMat.Inverse();

		oBox.Transform(oInvMat);
		
		// Backup data
		CVect3 oSIPos,oSFPos,oSSpd,oDIPos,oDFPos,oDSpd,oDSSp;
		oSIPos.Assign(CCOL_ColState::SrcIPos);
		oSFPos.Assign(CCOL_ColState::SrcFPos);
		oSSpd.Assign (CCOL_ColState::SrcSp  );

		oDIPos.Assign(CCOL_ColState::DstIPos);
		oDFPos.Assign(CCOL_ColState::DstFPos);
		oDSpd.Assign (CCOL_ColState::DstSp  );

		// Setup new data
		CCOL_ColState::SrcIPos.Assign(oSIPos);
		oInvMat.TransformPoint(CCOL_ColState::SrcIPos);
		CCOL_ColState::SrcFPos.Assign(oSFPos);
		oInvMat.TransformPoint(CCOL_ColState::SrcFPos);
		CCOL_ColState::SrcSp.Assign  (oSSpd );
		oInvMat.TransformPoint(CCOL_ColState::SrcSp);

		CCOL_ColState::DstIPos.Assign(oDIPos);
		oInvMat.TransformPoint(CCOL_ColState::DstIPos);
		CCOL_ColState::DstFPos.Assign(oDFPos);
		oInvMat.TransformPoint(CCOL_ColState::DstFPos);
		CCOL_ColState::DstSp.Assign  (oDSpd );
		oInvMat.TransformPoint(CCOL_ColState::DstSp);

		CCOL_ColState::DSSp.Assign	(CCOL_ColState::DstSp);
		CCOL_ColState::DSSp.Sub		(CCOL_ColState::SrcSp);

		// Perform test
		int iRes = iTest3DObj_Rec(_poObj->poGetObject());

		// Restore data
		CCOL_ColState::SrcIPos.Assign(oSIPos);
		CCOL_ColState::SrcFPos.Assign(oSFPos);
		CCOL_ColState::SrcSp.Assign  (oSSpd);

		CCOL_ColState::DstIPos.Assign(oDIPos);
		CCOL_ColState::DstFPos.Assign(oDFPos);
		CCOL_ColState::DstSp.Assign  (oDSpd  );

		CCOL_ColState::DSSp.Assign	(CCOL_ColState::DstSp);
		CCOL_ColState::DSSp.Sub		(CCOL_ColState::SrcSp);

		return(iRes);
	}
}

int CCOL_Scn_ColTester::iTest3DObj_CompiledLeaf (CObject3D_CompiledLeaf* _poObj)
{
  	if (CCOL_DT_ColTester::fTestCollision(SGrObj->poGetBoundVol(),_poObj->poGetBoundVol()) >= 0.0f)
	{		
		return(1);
	}
	else 
		return(0);
}

int CCOL_Scn_ColTester::iTest3DObj_Leaf (CObject3D_Leaf* _poObj)
{
  	if (iNumColMeshes == 64) return(0);

	float fFrameFact;
	fFrameFact = CCOL_DT_ColTester::fTestCollision(SGrObj->poGetBoundVol(),_poObj->poGetBoundVol());

	if ( fFrameFact >= 0.0f)
	{
		ColMeshes[iNumColMeshes++].Set(_poObj->poGetMesh(),(int)_poObj->poGetShader(),fFrameFact);
		return(1);
	}
	else 
		return(0);

}

int CCOL_Scn_ColTester::iTest3DObj_BSPNode (CObject3D_BSPNode* _poObj)
{
  		
	// Look if there is a collision with the complete group
	int		iResF,iResB;
	int		iPlaneRes;
	
	if (CCOL_DT_ColTester::fTestCollision(SGrObj->poGetBoundVol(),_poObj->poGetBoundVol()) < 0.0f)
		return(0);
		
	// Miramos si hay que testear con cada uno de los subarboles
 	iPlaneRes = CCOL_ST_ColTester::iTestPlane(SGrObj->poGetBoundVol(),*_poObj->poGetPartitionPlane());

	// iPlaneRes = 0;
	switch (iPlaneRes)
	{
				// The object is behind the partition plane
		case -1:return ( iTest3DObj_Rec(_poObj->poGetBackNode()) );
				/*
				if ( CCOL_ColTester::fTestCollision(SrcObj->GrObj->GetBoundVol(),
													SrcObj->Pos,
													SrcObj->Speed,
													_poObj->BackNode->GetBoundVol(),
													DstObj->Pos,
													DstObj->Speed,
													0.0f)
				)
				{
					// if there is a collision we need to continue the testing
					return ( iTest3DObj_Rec(_poObj->BackNode) );
				}

				// No colision
				return(0);
				*/
				break;

		case  1:return ( iTest3DObj_Rec(_poObj->poGetFrontNode()) );
				/*
				if ( CCOL_ColTester::fTestCollision(SrcObj->GrObj->GetBoundVol(),
													SrcObj->Pos,
													SrcObj->Speed,
													_poObj->FrontNode->GetBoundVol(),
													DstObj->Pos,													
													DstObj->Speed,
													0.0f)
				)
				{
					// if there is a collision we need to continue the testing
					return ( iTest3DObj_Rec(_poObj->BackNode) );
				}

				// No colision
				*/
				break;

		case  0:// Test agains the 2 nodes				
				iResF = iTest3DObj_Rec( _poObj->poGetFrontNode() );
				iResB = iTest3DObj_Rec( _poObj->poGetBackNode()  );
				return(iResF | iResB);

				/*
				iResF = 0;
				fResF = CCOL_ColTester::fTestCollision(SrcObj->GrObj->GetBoundVol(),
													  SrcObj->Pos,
													  SrcObj->Speed,
													  _poObj->FrontNode->GetBoundVol(),
													  DstObj->Pos,													
													  DstObj->Speed,
													  0.0f);
				if (fResF)
				{
					iResF = iTest3DObj_Rec(_poObj->FrontNode);
					// We've traversed the front node until the end and finally it was a collision
					if (iResF) return(1);
				}
			
				// Check the back node
				fResB = CCOL_ColTester::fTestCollision(SrcObj->GrObj->GetBoundVol(),
														SrcObj->Pos,
														SrcObj->Speed,
														_poObj->BackNode->GetBoundVol(),
														DstObj->Pos,
														DstObj->Speed,
														0.0f);
				// No collision?
				if (! fResB) return(0);
				
				// Traverse the back node
				return ( iTest3DObj_Rec(_poObj->BackNode) );
				*/				
				break;
	}
	
	return(0);
}

// Additional Declarations
    
