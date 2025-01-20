#ifdef PROFILE
#pragma optimize ("",off)
#endif

#include "CEntCollision.h" 
#include "CEntityMgr.h"
#include "antares.h"

// #include "Loop/Game/GameMode/History/Levels/CGMHLevel.h"
// #include "Loop/Game/CGameGlobals.h"

// #include "Loop/Map/CHeightField.h"

// #define _2DCOLLISIONS_
TCollisionInfo goCollInfo;

// Circular queue
MEM_DynamicArray<TCylinder>*				CEntCollision::m_poCL = NULL;
MEM_DynamicArray<CAABBCylinderContainer>*	CEntCollision::m_poAABBCC;
// -----------------------------------------------------------------------------
const float fIniOfs			= 0.0001f;
const float fMaxStep		= 1.0f / 10.0f;
const float fExtrusionFact	= 10.0f;
const float fRefinationFact = 0.95f;
const float fAngleThresh	= 0.001f;

void CEntCollision::Init()
{
}
// -----------------------------------------------------------------------------
bool CEntCollision::bCheckPoint(MTH_CPoint3 &_oPos,CVisEntity *_poEnt)
{
#if 0
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
#endif
return (false);
}
// -----------------------------------------------------------------------------
CVisEntity* CEntCollision::poCheckPoint(MTH_CPoint3& _oPos,unsigned int _uiTypesFlag)
{
	for (int iEnt=0;iEnt<MAX_ENTITIES;iEnt++)
	{
		CVisEntity* poDEnt = (CVisEntity*)CEntityMgr::m_poList[iEnt];

		if (! poDEnt) continue;

		if (   (poDEnt->m_iType  != ENT_NONE)
			&& (poDEnt->m_eState != ENTSTATE_DEAD)
			&& (poDEnt->m_eState != ENTSTATE_NONE)
			&& (poDEnt->m_eState != ENTSTATE_INACTIVE)
			&& (_uiTypesFlag & poDEnt->m_iType))
		{
			if (poDEnt->m_iType == ENT_WORLD)
			{
				// Test against the world
			}
			else
			{
				// Test against this entity
				if (CEntCollision::bCheckPoint(_oPos,poDEnt))
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
	
	/*
	if(bAABBOverlaps(A1,Ea,B1,Eb) )
	{	  
		int a = 0;
	}
	*/

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
TCollisionInfo* CEntCollision::poCheckCollision(CVisEntity* _poSrc,CVisEntity* _poDst)
{
	// if ((_poSrc->m_poGI->m_poModel == NULL) || (_poDst->m_poGI->m_poModel == NULL)) return(NULL);
	/*
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
	*/
		return(NULL);
}
// -----------------------------------------------------------------------------
TCollisionInfo* CEntCollision::poCheckCollision(CVisEntity *_poEnt,unsigned int _uiTypesFlag)
{
	if (! _poEnt)
		return(NULL);

	/*
	if (!_poEnt->m_poModel)
		return(NULL);
	*/

	for (int iEnt=0;iEnt<MAX_ENTITIES;iEnt++)
	{
		CVisEntity* poDEnt = (CVisEntity*)CEntityMgr::m_poList[iEnt];
		if (! poDEnt) continue;

		if (   (poDEnt->m_iType  != ENT_NONE)
			&& (poDEnt->m_eState != ENTSTATE_DEAD)
			&& (poDEnt->m_eState != ENTSTATE_NONE)
			&& (poDEnt->m_eState != ENTSTATE_INACTIVE)
			&& (_poEnt != poDEnt)
			&& (_uiTypesFlag & poDEnt->m_iType))
		{
			// Test against this entity
			TCollisionInfo* poInfo = CEntCollision::poCheckCollision(_poEnt,poDEnt);
			if (poInfo)
				return(poInfo);
		}
 	}

	return(NULL);
}
// -----------------------------------------------------------------------------
TCollisionInfo* CEntCollision::poCheckParticleCollision(MTH_CPoint3& _oPos,MTH_CPoint3& _oOPos,CVisEntity* _poDst)
{
	// if ((_poSrc->m_poGI->m_poModel == NULL) || (_poDst->m_poGI->m_poModel == NULL)) return(NULL);
	float fHRad;

	// Build 3D point using curve offset and height to curve
	MTH_CPoint3 oPos = _oPos;

	// Collision
	MTH_CPoint3 oD  = oPos - _oOPos;
	MTH_CSegment oS (oPos,oD);

	int iQ;
	float fT[2];

	switch (_poDst->m_poBV->eType())
	{
		case BVT_Sphere:
		{
			if (oS.bFindSphereIntersection( ((CBVSphere*)_poDst->m_poBV)->m_fRadius,_poDst->m_oPos,iQ,fT))
			{
				goCollInfo.fU0   = fT[0];
				goCollInfo.fU1   = fT[1];
				goCollInfo.iNum  = iQ;
				goCollInfo.poEnt = _poDst;
				goCollInfo.oP0   = _oOPos + oD * fT[0];
				goCollInfo.oP1   = _oOPos + oD * fT[1];

				return(&goCollInfo);
			}
		}
	}

	return (NULL);
}
// -----------------------------------------------------------------------------
TCollisionInfo* CEntCollision::poCheckParticleCollision(MTH_CPoint3& _oPos,MTH_CPoint3& _oOPos,unsigned int _uiTypesFlag)
{
	/*
	if (!_poEnt->m_poModel)
		return(NULL);
	*/

	for (int iEnt=0;iEnt<MAX_ENTITIES;iEnt++)
	{
		CVisEntity* poDEnt = (CVisEntity*)CEntityMgr::m_poList[iEnt];
		if (! poDEnt) continue;

		if (   (poDEnt->m_iType  != ENT_NONE)
			&& (poDEnt->m_eState != ENTSTATE_DEAD)
			&& (poDEnt->m_eState != ENTSTATE_NONE)
			&& (poDEnt->m_eState != ENTSTATE_INACTIVE)
			&& (_uiTypesFlag & poDEnt->m_iType))
		{
			// Test against this entity
			TCollisionInfo* poInfo = CEntCollision::poCheckParticleCollision(_oPos,_oOPos,poDEnt);
			if (poInfo)
				return(poInfo);
		}
 	}

	return(NULL);
}
// -----------------------------------------------------------------------------

#ifdef PROFILE
#pragma optimize ("",on)
#endif
