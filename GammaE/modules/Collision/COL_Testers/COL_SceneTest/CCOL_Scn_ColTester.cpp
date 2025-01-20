//## begin module%3C081B0A0386.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C081B0A0386.cm

//## begin module%3C081B0A0386.cp preserve=no
//## end module%3C081B0A0386.cp

//## Module: CCOL_Scn_ColTester%3C081B0A0386; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_SceneTest\CCOL_Scn_ColTester.cpp

//## begin module%3C081B0A0386.additionalIncludes preserve=no
//## end module%3C081B0A0386.additionalIncludes

//## begin module%3C081B0A0386.includes preserve=yes
//## end module%3C081B0A0386.includes

// CCOL_Scn_ColTester
#include "Collision\COL_Testers\COL_SceneTest\CCOL_Scn_ColTester.h"
//## begin module%3C081B0A0386.additionalDeclarations preserve=yes
//## end module%3C081B0A0386.additionalDeclarations


// Class CCOL_Scn_ColTester 

//## begin CCOL_Scn_ColTester::SGrObj%3C0B94FD011B.attr preserve=no  public: static CObject3D * {UA} NULL
CObject3D *CCOL_Scn_ColTester::SGrObj = NULL;
//## end CCOL_Scn_ColTester::SGrObj%3C0B94FD011B.attr

//## begin CCOL_Scn_ColTester::DGrObj%3C0B95080262.attr preserve=no  public: static CObject3D * {UA} NULL
CObject3D *CCOL_Scn_ColTester::DGrObj = NULL;
//## end CCOL_Scn_ColTester::DGrObj%3C0B95080262.attr

//## begin CCOL_Scn_ColTester::iNumColMeshes%3C1BF0DC00AB.attr preserve=no  public: static int {UA} 0
int CCOL_Scn_ColTester::iNumColMeshes = 0;
//## end CCOL_Scn_ColTester::iNumColMeshes%3C1BF0DC00AB.attr

//## begin CCOL_Scn_ColTester::ColMeshes%3C1FDD78002C.role preserve=no  public: static CCOL_Mesh {n -> 64UHAN}
CCOL_Mesh CCOL_Scn_ColTester::ColMeshes[64];
//## end CCOL_Scn_ColTester::ColMeshes%3C1FDD78002C.role

CCOL_Scn_ColTester::~CCOL_Scn_ColTester()
{
  //## begin CCOL_Scn_ColTester::~CCOL_Scn_ColTester%.body preserve=yes
  //## end CCOL_Scn_ColTester::~CCOL_Scn_ColTester%.body
}



//## Other Operations (implementation)
int CCOL_Scn_ColTester::iTestObjects ()
{
  //## begin CCOL_Scn_ColTester::iTestObjects%1007160409.body preserve=yes
	
	// Setup Collision tester object
	iNumColMeshes = 0;

	return ( iTest3DObj_Rec(DGrObj) );
  //## end CCOL_Scn_ColTester::iTestObjects%1007160409.body
}

int CCOL_Scn_ColTester::iTest3DObj_Rec (CObject3D *_poObj)
{
  //## begin CCOL_Scn_ColTester::iTest3DObj_Rec%1007160413.body preserve=yes
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
  //## end CCOL_Scn_ColTester::iTest3DObj_Rec%1007160413.body
}

int CCOL_Scn_ColTester::iTest3DObj (CObject3D* _poObj)
{
  //## begin CCOL_Scn_ColTester::iTest3DObj%1007327360.body preserve=yes
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
  //## end CCOL_Scn_ColTester::iTest3DObj%1007327360.body
}

int CCOL_Scn_ColTester::iTest3DObj_Node (CObject3D_Node* _poObj)
{
  //## begin CCOL_Scn_ColTester::iTest3DObj_Node%1007160412.body preserve=yes

	// Look if there is a collision with the complete group
	if (CCOL_DT_ColTester::fTestCollision(SGrObj->poGetBoundVol(),_poObj->poGetBoundVol()) < 0.0f)
		return(0);

	int			 iRes;
	int			 iObj;
	CObject3D	*pSubObj;

	iRes = 0;
	for (iObj=0;iObj<_poObj->iNumSubObjs();iObj++)
	{
		pSubObj = _poObj->poGetObject(iObj);

		if (pSubObj)
		{
			iRes |= iTest3DObj_Rec(pSubObj);
		}
	}

	return (iRes);
  //## end CCOL_Scn_ColTester::iTest3DObj_Node%1007160412.body
}

int CCOL_Scn_ColTester::iTest3DObj_Transf (CObject3D_Transf* _poObj)
{
  //## begin CCOL_Scn_ColTester::iTest3DObj_Transf%1018775601.body preserve=yes
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
		oInvMat = _poObj->roTransf();
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
  //## end CCOL_Scn_ColTester::iTest3DObj_Transf%1018775601.body
}

int CCOL_Scn_ColTester::iTest3DObj_CompiledLeaf (CObject3D_CompiledLeaf* _poObj)
{
  //## begin CCOL_Scn_ColTester::iTest3DObj_CompiledLeaf%1012005359.body preserve=yes
	if (CCOL_DT_ColTester::fTestCollision(SGrObj->poGetBoundVol(),_poObj->poGetBoundVol()) >= 0.0f)
	{		
		return(1);
	}
	else 
		return(0);
  //## end CCOL_Scn_ColTester::iTest3DObj_CompiledLeaf%1012005359.body
}

int CCOL_Scn_ColTester::iTest3DObj_Leaf (CObject3D_Leaf* _poObj)
{
  //## begin CCOL_Scn_ColTester::iTest3DObj_Leaf%1007160411.body preserve=yes
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

  //## end CCOL_Scn_ColTester::iTest3DObj_Leaf%1007160411.body
}

int CCOL_Scn_ColTester::iTest3DObj_BSPNode (CObject3D_BSPNode* _poObj)
{
  //## begin CCOL_Scn_ColTester::iTest3DObj_BSPNode%1007160410.body preserve=yes
		
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
  //## end CCOL_Scn_ColTester::iTest3DObj_BSPNode%1007160410.body
}

// Additional Declarations
  //## begin CCOL_Scn_ColTester%3C081B0A0386.declarations preserve=yes
  //## end CCOL_Scn_ColTester%3C081B0A0386.declarations

//## begin module%3C081B0A0386.epilog preserve=yes
//## end module%3C081B0A0386.epilog
