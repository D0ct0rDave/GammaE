//## begin module%3BA534E1028D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA534E1028D.cm

//## begin module%3BA534E1028D.cp preserve=no
//## end module%3BA534E1028D.cp

//## Module: CObject3D_AnimNode%3BA534E1028D; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimNode.cpp

//## begin module%3BA534E1028D.additionalIncludes preserve=no
//## end module%3BA534E1028D.additionalIncludes

//## begin module%3BA534E1028D.includes preserve=yes
//## end module%3BA534E1028D.includes

// CObject3D_AnimNode
#include "Scene\Animation\CObject3D_AnimNode.h"
//## begin module%3BA534E1028D.additionalDeclarations preserve=yes
#include <string.h>
//## end module%3BA534E1028D.additionalDeclarations


// Class CObject3D_AnimNode 





CObject3D_AnimNode::CObject3D_AnimNode()
  //## begin CObject3D_AnimNode::CObject3D_AnimNode%.hasinit preserve=no
      : poObjs(NULL), iNumObjs(0), iMaxObjs(0), poBVolStates(NULL)
  //## end CObject3D_AnimNode::CObject3D_AnimNode%.hasinit
  //## begin CObject3D_AnimNode::CObject3D_AnimNode%.initialization preserve=yes
  //## end CObject3D_AnimNode::CObject3D_AnimNode%.initialization
{
  //## begin CObject3D_AnimNode::CObject3D_AnimNode%.body preserve=yes
	TypeID = e3DObj_AnimNode;
  //## end CObject3D_AnimNode::CObject3D_AnimNode%.body
}


CObject3D_AnimNode::~CObject3D_AnimNode()
{
  //## begin CObject3D_AnimNode::~CObject3D_AnimNode%.body preserve=yes
  	
	for (int iObj=0;iObj<iNumObjs;iObj++)
		poObjs[iObj]->UnReference();
	
	delete []poObjs;

	if (poBVolStates)
	{	
		for (int iState=0;iState<iNumStates;iState++)
			delete poBVolStates[iState];
		
		delete []poBVolStates;
	}

  //## end CObject3D_AnimNode::~CObject3D_AnimNode%.body
}



//## Other Operations (implementation)
CGraphBV* CObject3D_AnimNode::poGetBoundVol ()
{
  //## begin CObject3D_AnimNode::poGetBoundVol%1000676445.body preserve=yes
  	return (BVol);
  //## end CObject3D_AnimNode::poGetBoundVol%1000676445.body
}

void CObject3D_AnimNode::ComputeBoundVol ()
{
  //## begin CObject3D_AnimNode::ComputeBoundVol%1000676446.body preserve=yes
	assert (poBVolStates && "NULL Bounding Volume State array");	

  	int				iState;
	int				iObj;
	CVect3			Center;
	CVect3			*pBVVXs;
	CGraphBV		*pBVol;
	e3DObjectTypeID	eObjType;

	pBVVXs = new CVect3[iNumObjs*2];
	
	for (iState=0;iState<iNumStates;iState++)
	{
	  	for (iObj=0;iObj<iNumObjs;iObj++)
		{
			poObjs[iObj]->ComputeBoundVol ();
			
			eObjType = poObjs[iObj]->eGetTypeID();

			if ((eObjType > e3DObj_Anim_Begin)	&&  (eObjType < e3DObj_Anim_End))
				pBVol = ((CObject3D_AnimGen*)poObjs[iObj])->poGetStateBVol(iState);
			else
				pBVol = poObjs[iObj]->poGetBoundVol();

			Center = pBVol->GetCenter();

			pBVVXs[iObj*2+0].V3(Center.X() - pBVol->GetRange(0),
								Center.Y() - pBVol->GetRange(1),
								Center.Z() - pBVol->GetRange(2));

			pBVVXs[iObj*2+1].V3(Center.X() + pBVol->GetRange(0),
								Center.Y() + pBVol->GetRange(1),
								Center.Z() + pBVol->GetRange(2));
		}
		
		poBVolStates[iState]->Compute  ( pBVVXs,iNumObjs*2    );
	}

	delete []pBVVXs;

	BVol = poBVolStates[0];

  //## end CObject3D_AnimNode::ComputeBoundVol%1000676446.body
}

void CObject3D_AnimNode::Render ()
{
  //## begin CObject3D_AnimNode::Render%1000676447.body preserve=yes
   	assert( poObjs && "NULL animated object array");

	for (int cObj=0;cObj<iNumObjs;cObj++)
		poObjs[cObj]->Render();

  //## end CObject3D_AnimNode::Render%1000676447.body
}

void CObject3D_AnimNode::SetAnimState (int _iSrc, int _iDst, float _fFactor)
{
  //## begin CObject3D_AnimNode::SetAnimState%1000676448.body preserve=yes
	assert (poBVolStates && "NULL Bounding Volume State array");

  	// Set animation state of child objects
  	for (int cObj=0;cObj<iNumObjs;cObj++)
	{
		if ((poObjs[cObj]->eGetTypeID() > e3DObj_Anim_Begin)	 &&
		    (poObjs[cObj]->eGetTypeID() < e3DObj_Anim_End))
				((CObject3D_AnimGen*)poObjs[cObj])->SetAnimState(_iSrc,_iDst,_fFactor);
	}		
	BVol = poBVolStates[_iSrc];

  //## end CObject3D_AnimNode::SetAnimState%1000676448.body
}

CGraphBV * CObject3D_AnimNode::poGetStateBVol (int _iState)
{
  //## begin CObject3D_AnimNode::poGetStateBVol%1000676449.body preserve=yes
	assert (poBVolStates && "NULL Bounding Volume State array");

  	if (_iState >= iNumStates) _iState =iNumStates-1;
	return (poBVolStates[_iState]);
  //## end CObject3D_AnimNode::poGetStateBVol%1000676449.body
}

void CObject3D_AnimNode::Init (int _iMaxObjs)
{
  //## begin CObject3D_AnimNode::Init%1000676450.body preserve=yes
	iMaxObjs = _iMaxObjs;
	iNumObjs = 0;

	poObjs    = new CObject3D *[iMaxObjs];
	memset(poObjs,0,4*iMaxObjs);
  //## end CObject3D_AnimNode::Init%1000676450.body
}

int CObject3D_AnimNode::AddObject (CObject3D_AnimGen* _poObj)
{
  //## begin CObject3D_AnimNode::AddObject%1000676451.body preserve=yes
  	assert( poObjs				 && "NULL animated object array");
	assert((iNumObjs < iMaxObjs) && "Full animated object array");
	
	poObjs[iNumObjs++] = _poObj;	
	return(iNumObjs-1);
  //## end CObject3D_AnimNode::AddObject%1000676451.body
}

void CObject3D_AnimNode::CreateStates (int _iNumStates)
{
  //## begin CObject3D_AnimNode::CreateStates%1000676452.body preserve=yes
  	int iState;

	iNumStates   = _iNumStates;

	// OPTIMIZE (SIZE): Memory sucker!
	poBVolStates = new CGraphBV *[iNumStates];
	
	for (iState=0;iState<iNumStates;iState++)
		poBVolStates[iState] = CGraphBV_Manager::poCreate();
  
  //## end CObject3D_AnimNode::CreateStates%1000676452.body
}

void CObject3D_AnimNode::Clear ()
{
  //## begin CObject3D_AnimNode::Clear%1000676453.body preserve=yes
  	assert( poObjs && "NULL animated object array");

	for (int cObj=0;cObj<iNumObjs;cObj++)
		poObjs[cObj]->UnReference();

  //## end CObject3D_AnimNode::Clear%1000676453.body
}

CObject3D* CObject3D_AnimNode::poGetObject (int _iObj)
{
  //## begin CObject3D_AnimNode::poGetObject%1000933006.body preserve=yes
	assert( poObjs              && "NULL animated object array");
	assert( (_iObj < iNumObjs) && "Object out of bounds");

	return (poObjs[_iObj]);
  //## end CObject3D_AnimNode::poGetObject%1000933006.body
}

// Additional Declarations
  //## begin CObject3D_AnimNode%3BA534E1028D.declarations preserve=yes
  //## end CObject3D_AnimNode%3BA534E1028D.declarations

//## begin module%3BA534E1028D.epilog preserve=yes
//## end module%3BA534E1028D.epilog
