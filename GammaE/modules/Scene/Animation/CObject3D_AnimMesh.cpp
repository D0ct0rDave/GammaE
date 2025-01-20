//## begin module%3B9E03DD0102.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9E03DD0102.cm

//## begin module%3B9E03DD0102.cp preserve=no
//## end module%3B9E03DD0102.cp

//## Module: CObject3D_AnimMesh%3B9E03DD0102; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimMesh.cpp

//## begin module%3B9E03DD0102.additionalIncludes preserve=no
//## end module%3B9E03DD0102.additionalIncludes

//## begin module%3B9E03DD0102.includes preserve=yes
#include <string.h>
//## end module%3B9E03DD0102.includes

// CObject3D_AnimMesh
#include "Scene\Animation\CObject3D_AnimMesh.h"
//## begin module%3B9E03DD0102.additionalDeclarations preserve=yes
//## end module%3B9E03DD0102.additionalDeclarations


// Class CObject3D_AnimMesh 






CObject3D_AnimMesh::CObject3D_AnimMesh()
  //## begin CObject3D_AnimMesh::CObject3D_AnimMesh%.hasinit preserve=no
      : pMeshStates(NULL), pNMeshStates(NULL), iNumStateVXs(0), pBVolStates(NULL), Leaf(NULL)
  //## end CObject3D_AnimMesh::CObject3D_AnimMesh%.hasinit
  //## begin CObject3D_AnimMesh::CObject3D_AnimMesh%.initialization preserve=yes
  //## end CObject3D_AnimMesh::CObject3D_AnimMesh%.initialization
{
  //## begin CObject3D_AnimMesh::CObject3D_AnimMesh%.body preserve=yes
	TypeID = e3DObj_AnimMesh;
	
	BVol		= CGraphBV_Manager::poCreate();
  //## end CObject3D_AnimMesh::CObject3D_AnimMesh%.body
}


CObject3D_AnimMesh::~CObject3D_AnimMesh()
{
  //## begin CObject3D_AnimMesh::~CObject3D_AnimMesh%.body preserve=yes
    int iState;

	if (Leaf) Leaf->UnReference();

	if (pBVolStates)
	{	
		for (iState=0;iState<iNumStates;iState++)
			mDel pBVolStates[iState];
		
		mDel []pBVolStates;
	}
	
	if (pMeshStates) mDel []pMeshStates;
  //## end CObject3D_AnimMesh::~CObject3D_AnimMesh%.body
}



//## Other Operations (implementation)
void CObject3D_AnimMesh::SetAnimState (int _iSrc, int _iDst, float _fFactor)
{
  //## begin CObject3D_AnimMesh::SetAnimState%1000205744.body preserve=yes
	assert (pMeshStates && "NULL Mesh state array");
	assert (pBVolStates && "NULL Bounding Volume State array");
	assert (Leaf        && "NULL Leaf Mesh");	

	if (iNumStates == 1)
	{
		memcpy(Leaf->poGetMesh()->VXs,pMeshStates ,iNumStateVXs*sizeof(CVect3));
		memcpy(Leaf->poGetMesh()->VNs,pNMeshStates,iNumStateVXs*sizeof(CVect3));		

		BVol->Copy(pBVolStates[0]);
		Leaf->poGetMesh()->BVol = BVol;
	}
	else
	{
		if (_iSrc>= iNumStates) _iSrc = iNumStates-1;
		if (_iDst>= iNumStates) _iDst = iNumStates-1;
		if (_fFactor == 1.0f)	_iSrc = _iDst;			// Optimization
	
		if ((_iSrc != _iDst) && (_fFactor>0.0f))
		{
			int				cVert;
			CVect3			*pSrcVX  = pMeshStates + iNumStateVXs*_iSrc;
			CVect3			*pDstVX  = pMeshStates + iNumStateVXs*_iDst;
			CVect3			*pMeshVX = Leaf->poGetMesh()->VXs;

			for (cVert=0;cVert<iNumStateVXs;cVert++)
			{	
				pMeshVX->Interpolate(*pSrcVX,*pDstVX,_fFactor);
				pSrcVX ++;
				pDstVX ++;
				pMeshVX++;
			}
		
			CVect3 oSMax,oSMin,oDMax,oDMin,oMax,oMin;
			
			CVect3 oSCen = pBVolStates[_iSrc]->GetCenter();
			CVect3 oDCen = pBVolStates[_iDst]->GetCenter();
			CVect3 oSExt = pBVolStates[_iSrc]->GetExtents();
			CVect3 oDExt = pBVolStates[_iDst]->GetExtents();
			oSMax.Assign(oSCen);	oSMax.Add(oSExt);
			oSMin.Assign(oSCen);	oSMin.Sub(oSExt);
			oDMax.Assign(oDCen);	oDMax.Add(oDExt);
			oDMin.Assign(oDCen);	oDMin.Sub(oDExt);

			oMax.Interpolate(oSMax,oDMax,_fFactor);
			oMin.Interpolate(oSMin,oDMin,_fFactor);

			BVol->Init(oMax,oMin);
			Leaf->poGetMesh()->BVol = BVol;
						
			memcpy(Leaf->poGetMesh()->VNs,pNMeshStates + iNumStateVXs*_iSrc,iNumStateVXs*sizeof(CVect3));
		}
		else
		{		
			// Src copy:		
			BVol->Copy(pBVolStates[_iSrc]);			
			Leaf->poGetMesh()->BVol = BVol;
						
			// Copy of the vertexs
			memcpy(Leaf->poGetMesh()->VXs,pMeshStates  + iNumStateVXs*_iSrc,iNumStateVXs*sizeof(CVect3));
			
			// Copy of the normals
			memcpy(Leaf->poGetMesh()->VNs,pNMeshStates + iNumStateVXs*_iSrc,iNumStateVXs*sizeof(CVect3));
		}
	}
  //## end CObject3D_AnimMesh::SetAnimState%1000205744.body
}

void CObject3D_AnimMesh::CreateStates (int _iNumStates, int _iNumStateVXs)
{
  //## begin CObject3D_AnimMesh::CreateStates%1000205745.body preserve=yes
	int				iState;

	iNumStates   = _iNumStates;
	iNumStateVXs = _iNumStateVXs;

	pMeshStates  = mNew CVect3[_iNumStateVXs*_iNumStates];	// Vertexs
	pNMeshStates = mNew CVect3[_iNumStateVXs*_iNumStates];	// Normals
	
	// OPTIMIZE (SIZE): Memory sucker!
	pBVolStates = mNew CGraphBV *[_iNumStates];
	
	for (iState=0;iState<_iNumStates;iState++)
		pBVolStates[iState] = CGraphBV_Manager::poCreate();
  //## end CObject3D_AnimMesh::CreateStates%1000205745.body
}

void CObject3D_AnimMesh::Render ()
{
  //## begin CObject3D_AnimMesh::Render%1000205746.body preserve=yes
	assert (Leaf && "NULL Leaf Mesh");
	Leaf->Render();
  //## end CObject3D_AnimMesh::Render%1000205746.body
}

CGraphBV* CObject3D_AnimMesh::poGetBoundVol ()
{
  //## begin CObject3D_AnimMesh::poGetBoundVol%1000205747.body preserve=yes
	return (BVol);
  //## end CObject3D_AnimMesh::poGetBoundVol%1000205747.body
}

void CObject3D_AnimMesh::ComputeBoundVol ()
{
  //## begin CObject3D_AnimMesh::ComputeBoundVol%1000205748.body preserve=yes
	assert (pBVolStates && "NULL Bounding Volume State array");

	for (int iState=0;iState<iNumStates;iState++)
		pBVolStates[iState]->Compute(&pMeshStates[iState * iNumStateVXs],iNumStateVXs);

	BVol->Copy(pBVolStates[0]);	
  //## end CObject3D_AnimMesh::ComputeBoundVol%1000205748.body
}

void CObject3D_AnimMesh::SetLeaf (CObject3D_Leaf *_pLeafMesh)
{
  //## begin CObject3D_AnimMesh::SetLeaf%1000239575.body preserve=yes
	assert (_pLeafMesh && "Assigning NULL Leaf mesh");

	Leaf = _pLeafMesh;
	Leaf->Reference();
  //## end CObject3D_AnimMesh::SetLeaf%1000239575.body
}

CGraphBV * CObject3D_AnimMesh::poGetStateBVol (int _iState)
{
  //## begin CObject3D_AnimMesh::poGetStateBVol%1000479979.body preserve=yes
	assert (pBVolStates && "NULL Bounding Volume State array");

	if (_iState >= iNumStates) _iState = iNumStates-1;
	return ( pBVolStates[_iState] );
  //## end CObject3D_AnimMesh::poGetStateBVol%1000479979.body
}

// Additional Declarations
  //## begin CObject3D_AnimMesh%3B9E03DD0102.declarations preserve=yes
  //## end CObject3D_AnimMesh%3B9E03DD0102.declarations

//## begin module%3B9E03DD0102.epilog preserve=yes
//## end module%3B9E03DD0102.epilog
