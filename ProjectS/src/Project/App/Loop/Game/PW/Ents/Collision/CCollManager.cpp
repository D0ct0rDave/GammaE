// -----------------------------------------------------------------------------
#ifdef PROFILE
#pragma optimize ("",off)
#endif
// -----------------------------------------------------------------------------
#include "CCollManager.h" 
// -----------------------------------------------------------------------------
bool				CCollManager::m_bCTTable[MAX_ENTITY_TYPES][MAX_ENTITY_TYPES];
TCollisionCallback	CCollManager::m_poCBTable[MAX_ENTITY_TYPES][MAX_ENTITY_TYPES];
CCollEntity*		CCollManager::m_poCE[MAX_ENTITIES];
unsigned int		CCollManager::m_uiNumEnts = 0;
// -----------------------------------------------------------------------------
void CCollManager::Init()
{
}
// -----------------------------------------------------------------------------
void CCollManager::Finish()
{
}
// -----------------------------------------------------------------------------
void CCollManager::RegisterCollisionTest(CCollEntity* _poEnt,unsigned int _uiEntMask)
{
	for (int i=0;i<MAX_ENTITY_TYPES;i++)
	{
		if (_uiEntMask & (1>>i))
			m_bCTTable[_poEnt->m_iType][i] = true;
	}

	m_poCE[m_uiNumEnts++] = _poEnt;
}
// -----------------------------------------------------------------------------
void CCollManager::Step()
{
	for (int iSEnt=0;iSEnt<m_uiNumEnts;iSEnt++)
	{
		CCollEntity* poSEnt = m_poCE[iSEnt];
		
		if (! poSEnt) continue;
		if (
			   (poSEnt->m_iType == 0)
			|| (poSEnt->m_eState == ENTSTATE_DEAD)
			|| (poSEnt->m_eState == ENTSTATE_NONE)
			|| (poSEnt->m_eState == ENTSTATE_INACTIVE)
			)
			continue;

		for (int iDEnt=iSEnt+1;iDEnt<m_uiNumEnts;iDEnt++)
		{
			CCollEntity* poDEnt = m_poCE[iDEnt];
			
			if (! poDEnt) continue;
			if ( 
				   (poDEnt->m_iType  == 0)
				|| (poDEnt->m_eState == ENTSTATE_DEAD)
				|| (poDEnt->m_eState == ENTSTATE_NONE)
				|| (poDEnt->m_eState == ENTSTATE_INACTIVE)
				|| (! m_bCTTable[poSEnt->m_iType][poDEnt->m_iType])
				)
				continue;
			{
				/*
				if (poDEnt->m_iType == ENT_WORLD)
				{
					// Test against the world
					TCollisionInfo* poInfo = CCollManager::poCheckParticleWorldCollision(_oPos,_oOPos,poDEnt);
					if (poInfo)
						return(poInfo);
				}
				else
				{
					// Test against this entity
					TCollisionInfo* poInfo = CCollManager::poCheckParticleCollision(_oPos,_oOPos,poDEnt);
					if (poInfo)
						return(poInfo);
				}
				*/
			}
 		}
	}
}
// -----------------------------------------------------------------------------
void CCollManager::RegisterCollisionCallback(unsigned int _uiSrcEnt,unsigned int _uiDstEnt,TCollisionCallback* _poCB)
{
}
// -----------------------------------------------------------------------------

/*
#include "Loop/Game/GameMode/History/Levels/CGMHLevel.h"
#include "Loop/Game/CGameGlobals.h"

// #define _2DCOLLISIONS_
TCollisionInfo goCollInfo;

// Circular queue
MEM_DynamicArray<TCylinder>*				CCollManager::m_poCL = NULL;
MEM_DynamicArray<CAABBCylinderContainer>*	CCollManager::m_poAABBCC;
// -----------------------------------------------------------------------------
const float fIniOfs			= 0.0001f;
const float fMaxStep		= 1.0f / 10.0f;
const float fExtrusionFact	= 10.0f;
const float fRefinationFact = 0.95f;
const float fAngleThresh	= 0.001f;

void CCollManager::Init()
{
	float fF       = fIniOfs;
	
	m_poCL = pNew MEM_DynamicArray<TCylinder>;
	
	#if 1
	while (fF < fRefinationFact)
	{
		TCylinder C;
		C.oRS  = gpoMap->m_oPath.oGetRefSys(fF);
		C.fRad = gpoMap->m_fRadius;

		MTH_CPoint3 oNextPos;
		MTH_CPoint3 oNextDir;
		MTH_CPoint3 oDS;
		MTH_CPoint3 oPos;
		MTH_CPoint3 oDD;
		
		C.oRS.GetCol2(&oDS);
		oPos = gpoMap->m_oPath.oGetPos(fF);

		// Adaptative step
		bool bFound = false;
		float fCurStep = fMaxStep;
		do{
			
			MTH_CMat4x4 oM = gpoMap->m_oPath.oGetRefSys(fF + fCurStep);
			oM.GetCol3(&oNextPos);
			oM.GetCol2(&oNextDir);

			oDD = oNextPos - oPos;
			oDD.Unit();

			float fDotP  = oDS.fDot(oDD);
			float fDotP2 = oDS.fDot(oNextDir);

			if (bEq(fDotP,1.0f,fAngleThresh) && bEq(fDotP2,1.0f,fAngleThresh))
				bFound = true;
			else
				fCurStep *= fRefinationFact;

		}while (! bFound);

		fF += fCurStep;		

		oNextPos = gpoMap->m_oPath.oGetPos(fF);

		C.fH = oNextPos.fDistance(oPos) + fExtrusionFact;

		// Translate cylinder center to the center of the volume
		oPos += (oDS*(C.fH*0.5f));
		C.oRS.SetCol3(oPos);

		m_poCL->iAdd(C);
	}

	#else

		TCylinder C;
		C.oRS.Identity();
		C.fRad = gpoMap->m_fRadius;
		C.fH   = 100.0f;

		m_poCL->iAdd(C);

	#endif

	// Build AABB Cylinder Container List	
	m_poAABBCC = pNew MEM_DynamicArray<CAABBCylinderContainer>;

	CAABBCylinderContainer oCC;
	oCC.SetVolumeThreshold(250*250*250);

	for (int i=0;i<m_poCL->iGetNbElem();i++)
	{
		if (oCC.bFull())
		{
			m_poAABBCC->iAdd(oCC);
			oCC.Reset();
		}

		TCylinder* poCyl = m_poCL->poGetAt(i);
		oCC.AddCylinder(i,poCyl);
	}

	m_poAABBCC->iAdd(oCC);
}
// -----------------------------------------------------------------------------
bool CCollManager::bCheckPoint(MTH_CPoint3 &_oPos,CEntity *_poEnt)
{
	if (!_poEnt)
		return(false);

	if (!_poEnt->m_poGI)
		return(false);
 
	MTH_CPoint3 oMaxs,oMins;

 	oMaxs.x = _poEnt->m_poGI->m_poModel->m_fBBXMax + _poEnt->m_oPos.x;
 	#ifndef _2DCOLLISIONS_
 	oMaxs.y = _poEnt->m_poGI->m_poModel->m_fBBYMax + _poEnt->m_oPos.y;
 	#endif
 	oMaxs.z = _poEnt->m_poGI->m_poModel->m_fBBZMax + _poEnt->m_oPos.z;

 	oMins.x = _poEnt->m_poGI->m_poModel->m_fBBXMin + _poEnt->m_oPos.x;
 	#ifndef _2DCOLLISIONS_
 	oMins.y = _poEnt->m_poGI->m_poModel->m_fBBYMin + _poEnt->m_oPos.y;
 	#endif
 	oMins.z = _poEnt->m_poGI->m_poModel->m_fBBZMin + _poEnt->m_oPos.z;

	return ( 
			bGEq(_oPos.x,oMins.x) && bLEq(_oPos.x,oMaxs.x) &&

			#ifndef _2DCOLLISIONS_
			bGEq(_oPos.y,oMins.y) && bLEq(_oPos.y,oMaxs.y) &&
			#endif

			bGEq(_oPos.z,oMins.z) && bLEq(_oPos.z,oMaxs.z)
			);
}
// -----------------------------------------------------------------------------
CEntity* CCollManager::poCheckPoint(MTH_CPoint3& _oPos,unsigned int _uiTypesFlag)
{
	for (int iEnt=0;iEnt<MAX_ENTITIES;iEnt++)
	{
		CEntity* poDEnt = CEntityMgr::m_poList[iEnt];

		if (! poDEnt) continue;

		if (   (poDEnt->m_iType  != ENT_NONE)
			&& (poDEnt->m_iState != ENTSTATE_DEAD)
			&& (poDEnt->m_iState != ENTSTATE_NONE)
			&& (poDEnt->m_iState != ENTSTATE_INACTIVE)
			&& (_uiTypesFlag & poDEnt->m_iType))
		{
			if (poDEnt->m_iType == ENT_WORLD)
			{
				// Test against the world
			}
			else
			{
				// Test against this entity
				if (CCollManager::bCheckPoint(_oPos,poDEnt))
					return(poDEnt);
			}
		}
 	}

	return(NULL);
}
// -----------------------------------------------------------------------------
// Debe permitirse que 2 aabb se toquen pero que no se solapen, es decir, una cara
// de una aabb comparta plano con otra cara de la otra AABB
// -----------------------------------------------------------------------------
bool bAABBOverlaps(MTH_CPoint3& _oAPos,MTH_CPoint3& _oAExt,MTH_CPoint3& _oBPos,MTH_CPoint3& _oBExt)
{
	if ( bGEq( fAbs(_oAPos.x - _oBPos.x),_oAExt.x + _oBExt.x) ) return(false);
	
	#ifndef _2DCOLLISIONS_
	if ( bGEq( fAbs(_oAPos.y - _oBPos.y),_oAExt.y + _oBExt.y) ) return(false);
	#endif

	if ( bGEq( fAbs(_oAPos.z - _oBPos.z),_oAExt.z + _oBExt.z) ) return(false);
	
	return(true);
}


#define NOCOLLISION_TIME 1.0f

bool bAABBSweep(MTH_CPoint3& Ea, //extents of AABB A
				MTH_CPoint3& A0, //its previous position
				MTH_CPoint3& A1, //its current position
				MTH_CPoint3& Eb, //extents of AABB B
				MTH_CPoint3& B0, //its previous position
				MTH_CPoint3& B1)
{
	//last times of overlap along each axis
	//check if they were overlapping
	// on the previous frame
	if(bAABBOverlaps(A0,Ea,B0,Eb) )
	{	  
		goCollInfo.fU0      = goCollInfo.fU1 = 0;
		goCollInfo.iColAxis = 0;
		return(true);
	}


	const MTH_CPoint3 va = A1 - A0;	// displacement of A
	const MTH_CPoint3 vb = B1 - B0;	// displacement of B

	//the problem is solved in A's frame of reference
	float v[3];
	v[0] = vb.x - va.x;	v[1] = vb.y - va.y;	v[2] = vb.z - va.z;

	// The objects could only collide if their velocities are different
	// v != (0,0,0);
	// if (v = (0,0,0)) the objects could only collide if at time 0 are
	// colliding. At this time the object hadn't collided due to the first
	// test.
	if ((v[0] == 0) && (v[1] == 0) && (v[2] == 0)) return(false);



	// First time of overlap along each axis
	float u1[3]={ 1.0f, 1.0f, 1.0f};

	// Last time of overlap along each axis
	float u0[3]={-1.0f,-1.0f,-1.0f};

	//find the possible first and last times
	//of overlap along each axis
	float maxA[3],minA[3],maxB[3],minB[3];

	maxA[0]= A0.x + Ea.x;	maxA[1]= A0.y + Ea.y;	maxA[2]= A0.z + Ea.z;
	minA[0]= A0.x - Ea.x;	minA[1]= A0.y - Ea.y;	minA[2]= A0.z - Ea.z;
	maxB[0]= B0.x + Eb.x;	maxB[1]= B0.y + Eb.y;	maxB[2]= B0.z + Eb.z;
	minB[0]= B0.x - Eb.x;	minB[1]= B0.y - Eb.y;	minB[2]= B0.z - Eb.z;

	// Find the possible first and last times of overlap along each axis
	for (int i=0;i<3;i++)
	{
		#ifdef _2DCOLLISIONS_
		if (i != 1)
		#endif

		//     max   min
  		//  |-a-|     |-b-|		
		if (bLEq(maxA[i],minB[i]))	// A 
		{
			if (v[i] < 0.0f)
			{
				//     max   min
  				//  |-a-|     |-b-|
				//             <--
				u0[i] = (maxA[i] - minB[i]) / v[i];
			}
			else
			{
				return(false);
			}
		}
		//     max   min
  		//  |-b-|     |-a-|
   else if (bLEq(maxB[i],minA[i]))
		{
			if (v[i]>0.0f)
			{
				//     max   min
  				//  |-b-|     |-a-|
				//   -->
				u0[i] = (minA[i] - maxB[i]) / v[i];
			}
			else 
			{
				return(false);
			}
		}

		// last time overlap 
		if ((maxB[i] < minA[i]) && (v[i]<0.0f))
		{
			u1[i] = (minA[i] - maxB[i]) / v[i];
		}

   else if ((maxA[i] > minB[i]) && (v[i]>0.0f))
		{
			u1[i] = (maxA[i] - minB[i]) / v[i];
		}
	}

	// Get max u0 and min u1
	goCollInfo.fU0 = -1.0f;
	goCollInfo.fU1 =  1.0f;

	for (int i=0;i<3;i++)
	{
		if (u0[i] > goCollInfo.fU0)
		{
			goCollInfo.fU0      = u0[i];
			goCollInfo.iColAxis = i;
		}
		if (u1[i] < goCollInfo.fU1)
			goCollInfo.fU1 = u1[i];
	}

	//they could have only collided if
	//the first time of overlap occurred
	//before the last time of overlap
	if ((goCollInfo.fU0 <= goCollInfo.fU1) && (goCollInfo.fU0 >= 0.0f) && (goCollInfo.fU0 <= NOCOLLISION_TIME))
		return(true);	
	else
		return(false);
}
// -----------------------------------------------------------------------------
TCollisionInfo* CCollManager::poCheckCollision(CEntity* _poSrc,CEntity* _poDst)
{
	// if ((_poSrc->m_poGI->m_poModel == NULL) || (_poDst->m_poGI->m_poModel == NULL)) return(NULL);
	
	MTH_CPoint3 oSE;
	oSE.x = _poSrc->m_fRadius; // (_poSrc->m_poModel->m_fBBXMax - _poSrc->m_poModel->m_fBBXMin)*0.5f;
	oSE.y = _poSrc->m_fRadius; // (_poSrc->m_poModel->m_fBBYMax - _poSrc->m_poModel->m_fBBYMin)*0.5f;
	oSE.z = _poSrc->m_fRadius; // (_poSrc->m_poModel->m_fBBZMax - _poSrc->m_poModel->m_fBBZMin)*0.5f;

	MTH_CPoint3 oDE;
	oDE.x = _poDst->m_fRadius; // (_poDst->m_poModel->m_fBBXMax - _poDst->m_poModel->m_fBBXMin)*0.5f;
	oDE.y = _poDst->m_fRadius; // (_poDst->m_poModel->m_fBBYMax - _poDst->m_poModel->m_fBBYMin)*0.5f;
	oDE.z = _poDst->m_fRadius; // (_poDst->m_poModel->m_fBBZMax - _poDst->m_poModel->m_fBBZMin)*0.5f;
	
	if (bAABBSweep(oSE,_poSrc->m_oOPos,_poSrc->m_oPos,oDE,_poDst->m_oOPos,_poDst->m_oPos))
	{
		goCollInfo.poEnt = _poDst;
		return(&goCollInfo);
	}
	else
		return(NULL);
}
// -----------------------------------------------------------------------------
TCollisionInfo*  CCollManager::poCheckParticleWorldCollision(MTH_CPoint3& _oPos,MTH_CPoint3& _oOPos,CEntity* _poW)
{
	// AABB Cylinder Containter List Test
	MTH_CPoint3 oDir = _oPos - _oOPos;
	MTH_CSegment oS(_oOPos,oDir);

	for (int j=0;j<m_poAABBCC->iGetNbElem();j++)
	{
		int		iQ;
		float   fT[2];

		CAABBCylinderContainer* poAABBCC = m_poAABBCC->poGetAt(j);

		if (oS.bFindAABBIntersection(poAABBCC->m_oMaxs,poAABBCC->m_oMins,iQ,fT))
		{
			// Test agains these AABB cylinders			
			for (int i=0;i<poAABBCC->m_uiNumCyls;i++)
			{
				TCylinder* poC = poAABBCC->m_poCylList[i];

				if (oS.bFindCapCylIntersection(poC->oRS,poC->fRad,poC->fH,iQ,fT))
				{
					// if (bDeterminate(fT[0]) && (fT[0]>=0.0f) && (fT[0] < 1.0f))
					{
						goCollInfo.poEnt    = NULL;
						goCollInfo.fU0      = fT[0];
						goCollInfo.fU1      = fT[1];
						goCollInfo.oP0      = _oOPos + oDir * fT[0];
						goCollInfo.oP1      = _oOPos + oDir * fT[1];
						goCollInfo.iColAxis = poAABBCC->m_iCylIDList[i];
						goCollInfo.iNum     = iQ;
						goCollInfo.poEnt    = _poW;
						return(&goCollInfo);
					}
				}
			}				
		}
	}

	return(NULL);
}
// -----------------------------------------------------------------------------
TCollisionInfo* CCollManager::poCheckWorldCollision(CEntity* _poSrc,CEntity* _poW)
{
	// if (! _poSrc->m_poModel) return(NULL);
	
	CGMHLevel *_poL = (CGMHLevel *)_poW;

	MTH_CPoint3 oSE;
	oSE.x = _poSrc->m_fRadius; // (_poSrc->m_poModel->m_fBBXMax - _poSrc->m_poModel->m_fBBXMin)*0.5f;
	oSE.y = _poSrc->m_fRadius; // (_poSrc->m_poModel->m_fBBYMax - _poSrc->m_poModel->m_fBBYMin)*0.5f;
	oSE.z = _poSrc->m_fRadius; // (_poSrc->m_poModel->m_fBBZMax - _poSrc->m_poModel->m_fBBZMin)*0.5f;

	MTH_CPoint3 oDE;
	
	oDE.x = TILE_BLOCK_WIDTH *0.5f;
	oDE.y = TILE_BLOCK_HEIGHT*0.5f;
	oDE.z = TILE_BLOCK_HEIGHT*0.5f;	
	
	for (int iR=0;iR<_poL->m_poMap->m_iRows;iR++)
		for (int iC=0;iC<_poL->m_poMap->m_iCols;iC++)
		{
			if (_poL->m_poMap->m_ucMap[iR][iC] >= 3)
			{
				MTH_CPoint3 oBlockPos;
				oBlockPos.x = _poL->m_poMap->m_fXOfs + iC*TILE_BLOCK_WIDTH ;
				oBlockPos.y = 1.0f;
				oBlockPos.z = _poL->m_poMap->m_fZOfs + iR*TILE_BLOCK_HEIGHT;

				if (bAABBSweep(oSE,_poSrc->m_oOPos,_poSrc->m_oPos,oDE,oBlockPos,oBlockPos))
				{
					goCollInfo.poEnt = _poW;
					return(&goCollInfo);
				}
			}
		}

	return(NULL);
}
// -----------------------------------------------------------------------------
TCollisionInfo* CCollManager::poCheckCollision(CEntity *_poEnt,unsigned int _uiTypesFlag)
{
	if (!_poEnt)
		return(NULL);
 
	for (int iEnt=0;iEnt<MAX_ENTITIES;iEnt++)
	{
		CEntity* poDEnt = CEntityMgr::m_poList[iEnt];
		if (! poDEnt) continue;

		if (   (poDEnt->m_iType  != ENT_NONE)
			&& (poDEnt->m_iState != ENTSTATE_DEAD)
			&& (poDEnt->m_iState != ENTSTATE_NONE)
			&& (poDEnt->m_iState != ENTSTATE_INACTIVE)
			&& (_poEnt != poDEnt)
			&& (_uiTypesFlag & poDEnt->m_iType))
		{
			if (poDEnt->m_iType == ENT_WORLD)
			{
				// Test against the world
				TCollisionInfo* poInfo = CCollManager::poCheckWorldCollision(_poEnt,poDEnt);
				if (poInfo)
					return(poInfo);
			}
			else
			{
				// Test against this entity
				TCollisionInfo* poInfo = CCollManager::poCheckCollision(_poEnt,poDEnt);
				if (poInfo)
					return(poInfo);
			}
		}
 	}

	return(NULL);
}
// -----------------------------------------------------------------------------
TCollisionInfo* CCollManager::poCheckParticleCollision(MTH_CPoint3& _oPos,MTH_CPoint3& _oOPos,CEntity* _poDst)
{
	// if ((_poSrc->m_poGI->m_poModel == NULL) || (_poDst->m_poGI->m_poModel == NULL)) return(NULL);
	
	MTH_CPoint3 oIP,oFP;
	oIP = _oOPos - _poDst->m_oSpd;
	oFP =  _oPos - _poDst->m_oSpd;

	MTH_CPoint3 oD  = oFP - oIP;
	MTH_CSegment oS (oFP,oD);

	int iQ;
	float fT[2];
	if (oS.bFindSphereIntersection(_poDst->m_fRadius,_poDst->m_oPos,iQ,fT))
	{
		goCollInfo.fU0   = fT[0];
		goCollInfo.fU1   = fT[1];
		goCollInfo.iNum  = iQ;
		goCollInfo.poEnt = _poDst;
		goCollInfo.oP0   = oIP + oD * fT[0];
		goCollInfo.oP1   = oIP + oD * fT[1];

		return(&goCollInfo);
	}

	return (NULL);
}
// -----------------------------------------------------------------------------
TCollisionInfo* CCollManager::poCheckParticleCollision(MTH_CPoint3& _oPos,MTH_CPoint3& _oOPos,unsigned int _uiTypesFlag)
{
	for (int iEnt=0;iEnt<MAX_ENTITIES;iEnt++)
	{
		CEntity* poDEnt = CEntityMgr::m_poList[iEnt];
		if (! poDEnt) continue;

		if (   (poDEnt->m_iType  != ENT_NONE)
			&& (poDEnt->m_iState != ENTSTATE_DEAD)
			&& (poDEnt->m_iState != ENTSTATE_NONE)
			&& (poDEnt->m_iState != ENTSTATE_INACTIVE)
			&& (_uiTypesFlag & poDEnt->m_iType))
		{
			if (poDEnt->m_iType == ENT_WORLD)
			{
				// Test against the world
				TCollisionInfo* poInfo = CCollManager::poCheckParticleWorldCollision(_oPos,_oOPos,poDEnt);
				if (poInfo)
					return(poInfo);
			}
			else
			{
				// Test against this entity
				TCollisionInfo* poInfo = CCollManager::poCheckParticleCollision(_oPos,_oOPos,poDEnt);
				if (poInfo)
					return(poInfo);
			}
		}
 	}

	return(NULL);
}
// -----------------------------------------------------------------------------
*/
#ifdef PROFILE
#pragma optimize ("",on)
#endif
