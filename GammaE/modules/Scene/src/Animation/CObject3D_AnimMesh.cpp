



#include <string.h>

// CObject3D_AnimMesh
#include "Animation\CObject3D_AnimMesh.h"


// Class CObject3D_AnimMesh 






CObject3D_AnimMesh::CObject3D_AnimMesh()
        : pMeshStates(NULL), pNMeshStates(NULL), iNumStateVXs(0), pBVolStates(NULL), Leaf(NULL)
      {
  	TypeID = e3DObj_AnimMesh;	
	BVol		= CGraphBV_Manager::poCreate();
}


CObject3D_AnimMesh::~CObject3D_AnimMesh()
{
      int iState;

	if (Leaf) Leaf->Deref();

	if (pBVolStates)
	{	
		for (iState=0;iState<iNumStates;iState++)
			mDel pBVolStates[iState];
		
		mDel []pBVolStates;
	}
	
	if (pMeshStates)  mDel []pMeshStates;
	if (pNMeshStates) mDel []pNMeshStates;
	
	if (BVol) mDel BVol;
}



void CObject3D_AnimMesh::SetAnimState (int _iSrc, int _iDst, float _fFactor)
{
  	assert (pMeshStates && "NULL Mesh state array");
	assert (pBVolStates && "NULL Bounding Volume State array");
	assert (Leaf        && "NULL Leaf Mesh");	

	if (iNumStates == 1)
	{
		memcpy(Leaf->poGetMesh()->VXs,pMeshStates ,iNumStateVXs*sizeof(CVect3));
		memcpy(Leaf->poGetMesh()->VNs,pNMeshStates,iNumStateVXs*sizeof(CVect3));		

		BVol->Copy(pBVolStates[0]);
		Leaf->poGetMesh()->BVol->Copy(BVol);
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

			/*
			// No se nota tanto la diferecia
			CVect3			*pSrcVN  = pNMeshStates + iNumStateVXs*_iSrc;
			CVect3			*pDstVN  = pNMeshStates + iNumStateVXs*_iDst;
			CVect3			*pMeshVN = Leaf->poGetMesh()->VNs;
			for (cVert=0;cVert<iNumStateVXs;cVert++)
			{	

				pMeshVN->Interpolate(*pSrcVN,*pDstVN,_fFactor);

				pSrcVN ++;
				pDstVN ++;
				pMeshVN++;
			}
			*/			
			memcpy(Leaf->poGetMesh()->VNs,pNMeshStates + iNumStateVXs*_iSrc,iNumStateVXs*sizeof(CVect3));


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
			Leaf->poGetMesh()->BVol->Copy(BVol);			
		}
		else
		{		
			// Src copy:		
			BVol->Copy(pBVolStates[_iSrc]);			
			Leaf->poGetMesh()->BVol->Copy(BVol);
						
			// Copy of the vertexs
			memcpy(Leaf->poGetMesh()->VXs,pMeshStates  + iNumStateVXs*_iSrc,iNumStateVXs*sizeof(CVect3));
			
			// Copy of the normals
			memcpy(Leaf->poGetMesh()->VNs,pNMeshStates + iNumStateVXs*_iSrc,iNumStateVXs*sizeof(CVect3));
		}
	}
}

void CObject3D_AnimMesh::CreateStates (int _iNumStates, int _iNumStateVXs)
{
  	int				iState;

	iNumStates   = _iNumStates;
	iNumStateVXs = _iNumStateVXs;

	pMeshStates  = mNew CVect3[_iNumStateVXs*_iNumStates];	// Vertexs
	pNMeshStates = mNew CVect3[_iNumStateVXs*_iNumStates];	// Normals

	// OPTIMIZE (SIZE): Memory sucker!
	pBVolStates = mNew CGraphBV *[_iNumStates];

	for (iState=0;iState<_iNumStates;iState++)
		pBVolStates[iState] = CGraphBV_Manager::poCreate();
}

void CObject3D_AnimMesh::Render ()
{
  	assert (Leaf && "NULL Leaf Mesh");
	Leaf->Render();
}

CGraphBV* CObject3D_AnimMesh::poGetBoundVol ()
{
  	return (BVol);
}

void CObject3D_AnimMesh::ComputeBoundVol ()
{
  	assert (pBVolStates && "NULL Bounding Volume State array");

	for (int iState=0;iState<iNumStates;iState++)
		pBVolStates[iState]->Compute(&pMeshStates[iState * iNumStateVXs],iNumStateVXs);

	BVol->Copy(pBVolStates[0]);	
}

void CObject3D_AnimMesh::SetLeaf (CObject3D_Leaf *_pLeafMesh)
{
  	assert (_pLeafMesh && "Assigning NULL Leaf mesh");

	Leaf = _pLeafMesh;
	Leaf->Ref();
}

CGraphBV * CObject3D_AnimMesh::poGetStateBVol (int _iState)
{
  	assert (pBVolStates && "NULL Bounding Volume State array");

	if (_iState >= iNumStates) _iState = iNumStates-1;
	return ( pBVolStates[_iState] );
}

// Additional Declarations
    
