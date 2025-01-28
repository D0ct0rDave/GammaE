//-----------------------------------------------------------------------------
#include "CGGEntityCollisionMgr.h"
#include "Collision/CGColliderResource.h"
#include "Collision/CGColliderInstance.h"

//-----------------------------------------------------------------------------
static CGCollisionInfo gsCollInfo;
CGCollisionInfo*  CGGEntityCollisionMgr::poCheckParticleCollision(CGColliderPrimitive* _poCT,float _fScale)
{
	// Perform test
	switch (_poCT->eType())
	{
		case CPT_Sphere:
		{
			CGCPTSphere* poSph = (CGCPTSphere*)_poCT;

			CGVect3 oPos = poSph->m_oCenter;
			oPos.Scale(_fScale);
			oPos.Add( CCOL_ColState::DstFPos );

			float fScale = poSph->m_fRadius * _fScale;

			/*
			float fT = CCOL_DT_Point::fTestSphere(_roPos,poDstCol->m_oPos,((CGCPTSphere*)poDstCol->m_poCT)->m_fRadius);
			
			if (fT >= 0.0f)
			{
				gsCollInfo.m_fU = fT;
				gsCollInfo.m_oP.LineEq(CCOL_ColState::SrcIPos,CCOL_ColState::SrcSp,fT / CCOL_ColState::fDeltaT);
				gsCollInfo.m_oP = _roPos;
				gsCollInfo.m_poEnt = _poEnt;
				return( &gsCollInfo );
			}
			*/

  			bool bCollided = CCOL_ST_Point::iTestSphere(CCOL_ColState::SrcFPos,oPos,fScale);
			
			if (bCollided)
			{
				CGVect3 oDir = CCOL_ColState::SrcFPos;
				oDir.Sub(oPos);
				oDir.Normalize();
				
				gsCollInfo.m_fU    = 0.0f;
				gsCollInfo.m_oP.LineEq(oPos,oDir,fScale);
				gsCollInfo.m_poCP  = poSph;

				return( &gsCollInfo );
			}
		}
		break;
		
		case CPT_Composite:		
		{
			CGCPTComposite* poCompo = (CGCPTComposite*)_poCT;

			// Perform broad collision test first
			if ((poCompo->poGlobalCollider()) && (poCheckParticleCollision(poCompo->poGlobalCollider(),_fScale) == NULL))
				return(NULL);
			
			// 
			bool bFound = false;
			for (uint i=0;i<poCompo->uiNumElems();i++)
			{
				CGCollisionInfo* poCI = poCheckParticleCollision(poCompo->poElem(i),_fScale);

				if (poCI)
					return(poCI);
			}
		}
		break;
	}
	return(NULL);
}
//-----------------------------------------------------------------------------
CGCollisionInfo* CGGEntityCollisionMgr::poCheckParticleCollision(CGColliderInstance* _poDstCI)
{
	// 
	if ((_poDstCI->m_poResource == NULL) || (_poDstCI->m_poResource->m_poCT == NULL)) return(NULL);

	// Setup some collision system variables
	CCOL_ColState::DstFPos = _poDstCI->m_oPos;
	CCOL_ColState::DstIPos = _poDstCI->m_oOldPos;
	CCOL_ColState::DstSp.Assign(CCOL_ColState::DstFPos);
	CCOL_ColState::DstSp.Sub   (CCOL_ColState::DstIPos);
	CCOL_ColState::DSSp.Assign (CCOL_ColState::DstSp);
	CCOL_ColState::DSSp.Sub    (CCOL_ColState::SrcSp);

	// check collision
	return ( poCheckParticleCollision(_poDstCI->m_poResource->m_poCT,_poDstCI->m_fScale) );
}
//-----------------------------------------------------------------------------
CGCollisionInfo* CGGEntityCollisionMgr::poCheckParticleCollision(const CGVect3& _roPos,const CGVect3& _roOldPos,CGGameEntity* _poParent)
{
	// Setup some collision system variables
	CCOL_ColState::SrcIPos = _roOldPos;
	CCOL_ColState::SrcFPos = _roPos;
	CCOL_ColState::SrcSp.Assign(CCOL_ColState::SrcFPos);
	CCOL_ColState::SrcSp.Sub   (CCOL_ColState::SrcIPos);

	// Perform the test
	for (uint i=0;i<CGGameEntityMgr::I()->uiNumEntities();i++)
	{
		CGGameEntity*     poDstEnt   = CGGameEntityMgr::I()->poGetEntity(i);
		CGColliderInstance* poDstCol = (CGColliderInstance*)poDstEnt->poCollider();

		if (
				(_poParent != poDstEnt)									// Is the source entity the destination one?
			 && (poDstEnt->bIsEnabled())								// Is this entity enabled?
			 && (poDstCol)												// Has collider information?
			)
		{
			// Test against this entity
			CGCollisionInfo* poInfo = poCheckParticleCollision(poDstCol);

			if (poInfo)
			{
				poInfo->m_poEnt = poDstEnt;
				return(poInfo);
			}
		}
	}

	// no collision
	return(NULL);
}
//-----------------------------------------------------------------------------
CGCollisionInfo* CGGEntityCollisionMgr::poCheckCollision(const CGVect3& _oSrcPos,float _fSrcRadius,CGColliderPrimitive* _poDstCol,float _fDstScale)
{
	// Perform test
	switch (_poDstCol->eType())
	{
		case CPT_Sphere:
		{
			CGCPTSphere* poSph = (CGCPTSphere*)_poDstCol;

			CGVect3 oPos = poSph->m_oCenter;
			oPos.Scale(_fDstScale);
			oPos.Add( CCOL_ColState::DstFPos );

			float fScale = poSph->m_fRadius * _fDstScale;

			#if 0
			float fT = CCOL_DT_Point::fTestSphere(_roPos,poDstCol->m_oPos,((CGCPTSphere*)poDstCol->m_poCT)->m_fRadius);
			
			if (fT >= 0.0f)
			{
				gsCollInfo.m_fU = fT;
				gsCollInfo.m_oP.LineEq(CCOL_ColState::SrcIPos,CCOL_ColState::SrcSp,fT / CCOL_ColState::fDeltaT);
				gsCollInfo.m_oP = _roPos;
				gsCollInfo.m_poEnt = _poEnt;
				return( &gsCollInfo );
			}
			#endif
			
			CGVect3 oSrcPos = _oSrcPos;
			CGVect3 oDstPos = oPos;
			
  			bool bCollided = CCOL_ST_Sphere::iTestSphere(oSrcPos,_fSrcRadius,oDstPos,fScale);

			if (bCollided)
			{
				CGVect3 oDir = CCOL_ColState::SrcFPos;
				oDir.Sub(oPos);
				oDir.Normalize();
				
				gsCollInfo.m_fU    = 0.0f;
				gsCollInfo.m_oP.LineEq(oPos,oDir,fScale);
				gsCollInfo.m_poCP  = poSph;

				return( &gsCollInfo );
			}
		}
		break;

		case CPT_Composite:
		{
			CGCPTComposite* poCompo = (CGCPTComposite*)_poDstCol;

			// Perform broad collision test first
			if ((poCompo->poGlobalCollider()) && (poCheckCollision(_oSrcPos,_fSrcRadius,poCompo->poGlobalCollider(),_fDstScale) == NULL))
				return(NULL);

			// 
			bool bFound = false;
			for (uint i=0;i<poCompo->uiNumElems();i++)
			{
				CGCollisionInfo* poCI = poCheckCollision(_oSrcPos,_fSrcRadius,poCompo->poElem(i),_fDstScale);

				if (poCI)
					return(poCI);
			}
		}
		break;
	}

	// no collision
	return(NULL);
}
//-----------------------------------------------------------------------------
CGCollisionInfo* CGGEntityCollisionMgr::poCheckCollision(CGColliderPrimitive* _poSrcCol,float _fSrcScale,CGColliderPrimitive* _poDstCol,float _fDstScale)
{
	// Perform test
	switch (_poSrcCol->eType())
	{
		case CPT_Sphere:
		{
			CGCPTSphere* poSph = (CGCPTSphere*)_poSrcCol;

			CGVect3 oPos = poSph->m_oCenter;
			oPos.Scale(_fSrcScale);
			oPos.Add( CCOL_ColState::SrcFPos );

			float fScale = poSph->m_fRadius * _fSrcScale;

			return ( poCheckCollision(oPos,fScale,_poDstCol,_fDstScale) ) ;
		}
		break;

		case CPT_Composite:		
		{
			CGCPTComposite* poCompo = (CGCPTComposite*)_poSrcCol;

			// Perform broad collision test first
			if ((poCompo->poGlobalCollider()) && (poCheckCollision(poCompo->poGlobalCollider(),_fSrcScale,_poDstCol,_fDstScale) == NULL))
				return(NULL);

			// 
			bool bFound = false;
			for (uint i=0;i<poCompo->uiNumElems();i++)
			{
				CGCollisionInfo* poCI = poCheckCollision(poCompo->poElem(i),_fSrcScale,_poDstCol,_fDstScale);

				if (poCI)
					return(poCI);
			}
		}
		break;
	}

	return(NULL);
}
//-----------------------------------------------------------------------------
CGCollisionInfo* CGGEntityCollisionMgr::poCheckCollision(CGColliderInstance* _poSrcCI,CGColliderInstance* _poDstCI)
{
	// 
	if ((_poDstCI->m_poResource == NULL) || (_poDstCI->m_poResource->m_poCT == NULL)) return(NULL);

	CCOL_ColState::DstFPos = _poDstCI->m_oPos;
	CCOL_ColState::DstIPos = _poDstCI->m_oOldPos;
	CCOL_ColState::DstSp.Assign(CCOL_ColState::DstFPos);
	CCOL_ColState::DstSp.Sub   (CCOL_ColState::DstIPos);
	CCOL_ColState::DSSp.Assign (CCOL_ColState::DstSp);
	CCOL_ColState::DSSp.Sub    (CCOL_ColState::SrcSp);

	// Check collision
	return( poCheckCollision(_poSrcCI->m_poResource->m_poCT,_poSrcCI->m_fScale,_poDstCI->m_poResource->m_poCT,_poDstCI->m_fScale) );
}
//-----------------------------------------------------------------------------
CGCollisionInfo* CGGEntityCollisionMgr::poCheckCollision(CGGameEntity* _poSrcEnt)
{
	CGColliderInstance* poSrcCol = (CGColliderInstance*)_poSrcEnt->poCollider();
	if (poSrcCol == NULL) return(NULL);

	// Setup some collision system variables
	CCOL_ColState::SrcIPos = poSrcCol->m_oOldPos;
	CCOL_ColState::SrcFPos = poSrcCol->m_oPos;
	CCOL_ColState::SrcSp.Assign(CCOL_ColState::SrcFPos);
	CCOL_ColState::SrcSp.Sub   (CCOL_ColState::SrcIPos);

	// Perform the test along all the active entities
	for (uint i=0;i<CGGameEntityMgr::I()->uiNumEntities();i++)
	{		
		CGGameEntity*     poDstEnt   = CGGameEntityMgr::I()->poGetEntity(i);
		CGColliderInstance* poDstCol = (CGColliderInstance*)poDstEnt->poCollider();

		if (
			   (poDstEnt != _poSrcEnt)									// Is the source entity the destination one?
			&& (poDstEnt->bIsEnabled())									// Is this entity enabled?
			&& (poDstCol)												// Has collider information?
			// This entity should be tested against the source one?
			// && (poSrcCol->m_poResource->m_uiTestMask & poDstCol->m_poResource->m_uiEntType)
			)
		{
			// Test against this entity
			CGCollisionInfo* poInfo = poCheckCollision(poSrcCol,poDstCol);

			if (poInfo != NULL)
			{
				poInfo->m_poEnt = poDstEnt;
				return(poInfo);
			}
		}
	}

	// no collision
	return(NULL);
}
//-----------------------------------------------------------------------------
void CGGEntityCollisionMgr::Update(float _fDeltaT)
{
	// Setup some collision system variables
	CCOL_ColState::fDeltaT = _fDeltaT;

	// Perform the test along all the active entities
	for (uint i=0;i<CGGameEntityMgr::I()->uiNumEntities();i++)
	{
		CGGameEntity*     poEnt  = CGGameEntityMgr::I()->poGetEntity(i);
		CGColliderInstance* poCI = (CGColliderInstance*)poEnt->poCollider();

		if ((poEnt != NULL) && (poEnt->bIsEnabled()) && (poCI != NULL))
			poCheckCollision( poEnt );
	}
}
//-----------------------------------------------------------------------------
