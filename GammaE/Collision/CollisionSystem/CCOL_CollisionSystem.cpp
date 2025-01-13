//## begin module%3B6F1A7F02E4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B6F1A7F02E4.cm

//## begin module%3B6F1A7F02E4.cp preserve=no
//## end module%3B6F1A7F02E4.cp

//## Module: CCOL_CollisionSystem%3B6F1A7F02E4; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\CollisionSystem\CCOL_CollisionSystem.cpp

//## begin module%3B6F1A7F02E4.additionalIncludes preserve=no
//## end module%3B6F1A7F02E4.additionalIncludes

//## begin module%3B6F1A7F02E4.includes preserve=yes
#include "Memory/GammaE_Mem.h"
//## end module%3B6F1A7F02E4.includes

// CCOL_CollisionSystem
#include "Collision\CollisionSystem\CCOL_CollisionSystem.h"
// CCOL_ST_Tris
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_Tris.h"
// CCOL_Scn_ColTester
#include "Collision\COL_Testers\COL_SceneTest\CCOL_Scn_ColTester.h"
//## begin module%3B6F1A7F02E4.additionalDeclarations preserve=yes
//## end module%3B6F1A7F02E4.additionalDeclarations


// Class CCOL_CollisionSystem 




CCOL_CollisionSystem::CCOL_CollisionSystem()
  //## begin CCOL_CollisionSystem::CCOL_CollisionSystem%.hasinit preserve=no
      : iMaxColliders(0), iNumColliders(0), poColliders(NULL)
  //## end CCOL_CollisionSystem::CCOL_CollisionSystem%.hasinit
  //## begin CCOL_CollisionSystem::CCOL_CollisionSystem%.initialization preserve=yes
  //## end CCOL_CollisionSystem::CCOL_CollisionSystem%.initialization
{
  //## begin CCOL_CollisionSystem::CCOL_CollisionSystem%.body preserve=yes
  //## end CCOL_CollisionSystem::CCOL_CollisionSystem%.body
}


CCOL_CollisionSystem::~CCOL_CollisionSystem()
{
  //## begin CCOL_CollisionSystem::~CCOL_CollisionSystem%.body preserve=yes
  	if (poColliders)
		mDel []poColliders;
  //## end CCOL_CollisionSystem::~CCOL_CollisionSystem%.body
}



//## Other Operations (implementation)
void CCOL_CollisionSystem::Init (int _iMaxColliders)
{
  //## begin CCOL_CollisionSystem::Init%999639512.body preserve=yes
	iMaxColliders = _iMaxColliders;
	iNumColliders = 0;
	
	// Create colliders
	poColliders	  = mNew CCOL_Collider *[iMaxColliders];
	assert (poColliders && "Unable to create collider array");
  //## end CCOL_CollisionSystem::Init%999639512.body
}

void CCOL_CollisionSystem::Reset ()
{
  //## begin CCOL_CollisionSystem::Reset%1018461840.body preserve=yes
	iNumColliders = 0;
  //## end CCOL_CollisionSystem::Reset%1018461840.body
}

int CCOL_CollisionSystem::iAddObject (CCOL_Collider* _poColObj)
{
  //## begin CCOL_CollisionSystem::iAddObject%1007074374.body preserve=yes
	assert ((iNumColliders < iMaxColliders) && "No more colliders allowed");

	// Not allowed
	if (_poColObj->GetColType() == eCOL_CT_None) return(-1);
	
	// Collision object identifier
	_poColObj->ColID = iNumColliders;
	
	poColliders[iNumColliders++] = _poColObj;

	return ( _poColObj->ColID );
  //## end CCOL_CollisionSystem::iAddObject%1007074374.body
}

void CCOL_CollisionSystem::CheckCollisions (float _fDelta)
{
  //## begin CCOL_CollisionSystem::CheckCollisions%999639513.body preserve=yes
	if (! _fDelta) return;	// There has been no movement in the current frame
	
	// Check for collisions	in all the system
	for (int iObj=0;iObj<iNumColliders;iObj++)
		bCheckCollision(*poColliders[iObj],_fDelta);

  //## end CCOL_CollisionSystem::CheckCollisions%999639513.body
}

bool CCOL_CollisionSystem::bCheckCollision (CCOL_Collider& _Src, float _fDelta)
{
  //## begin CCOL_CollisionSystem::bCheckCollision%1007327354.body preserve=yes
	int				iDst;
	CCOL_Collider	*poDst;	
	bool			bCollided	 = false;
	bool			bHasCollided = false;
		
	// Reset previous frame collisions
	_Src.Reset();

	// Perform the testing
	
	// Check collisions against all other static and non-static objects
	for (iDst=0;iDst<iNumColliders;iDst++)
	{
		poDst = poColliders[iDst];
		
		// Check that the source and the destination are not the same object
		if (_Src.ColID != poDst->ColID)
		{
			// If we could store a possible collision
			// if ( _Src.ColStack.GetNumCollisions() < iColStackSize)
			{
				// ------------------------------------------------------
				// BEGIN: CD Broad approach
				// ------------------------------------------------------
				CCOL_ColState::SrcIPos.Assign(_Src.OldPos);
				CCOL_ColState::SrcFPos.Assign(_Src.Pos);
				CCOL_ColState::SrcSp.Assign	 (_Src.Speed);

				CCOL_ColState::DstIPos.Assign(poDst->OldPos);
				CCOL_ColState::DstFPos.Assign(poDst->Pos);
				CCOL_ColState::DstSp.Assign	 (poDst->Speed);					

				CCOL_ColState::DSSp.Assign	 (CCOL_ColState::DstSp);
				CCOL_ColState::DSSp.Sub		 (CCOL_ColState::SrcSp);
				CCOL_ColState::fDeltaT		 = _fDelta;				
				CCOL_ColState::fMinColTime	 = 1e6;

				bHasCollided = bTestBroadCD(_Src,*poDst);
				// ------------------------------------------------------
				// END: CD Broad approach
				// ------------------------------------------------------


				// ------------------------------------------------------
				// BEGIN: CD Narrow approach
				// ------------------------------------------------------
				if (bHasCollided)
				{
					if (
						((poDst->GetColType() == eCOL_CT_Static) && (_Src.GetStTest() == eCOL_TT_Tris)) 
						/*
						||						
						((poDst->GetColType() == eCOL_CT_Dynamic) && (_Src.GetDynTest() == eCOL_TT_Tris))
						*/
					   )
					{
						if (bTestNarrowCD (_Src,*poDst))
							bCollided = true;
					}
					else
					{
						// This path is only valid for non static or no BV-Triangle 
						// collision test objects
						_Src.GetColStack().AddCollision(poDst,CCOL_ColState::fMinColTime);
						bCollided = true;
					}
				}
				// ------------------------------------------------------
				// END: CD Narrow approach
				// ------------------------------------------------------


				// Setup both objects as tested
				/*
				Colliders[_Src.ColID ].Tested(pDst->ColID);
				Colliders[pDst->ColID].Tested(_Src.ColID );
				*/
			}
		}
	}
	
	// Recompute the minimum time and position a collision occurred
	return(bCollided);
  //## end CCOL_CollisionSystem::bCheckCollision%1007327354.body
}

bool CCOL_CollisionSystem::bTestBroadCD (CCOL_Collider& _Src, CCOL_Collider& _Dst)
{
  //## begin CCOL_CollisionSystem::bTestBroadCD%1008711905.body preserve=yes
	bool	bCollided;

	CCOL_Scn_ColTester::SGrObj = _Src.GrObj;
	CCOL_Scn_ColTester::DGrObj = _Dst.GrObj;

	// Test if there is a collision
	bCollided = CCOL_Scn_ColTester::iTestObjects();

	return(bCollided);
  //## end CCOL_CollisionSystem::bTestBroadCD%1008711905.body
}

bool CCOL_CollisionSystem::bTestNarrowCD (CCOL_Collider& _Src, CCOL_Collider& _Dst)
{
  //## begin CCOL_CollisionSystem::bTestNarrowCD%1008463032.body preserve=yes
 
	if (! _Dst.GetMeshTester()) 
		return(false);

	int			iNumTris;
	int			iMesh;	

	// Initialize minimum collision time so here we perform a finer test
	CCOL_ColState::fMinColTime		= 1e6;

	// Compute collided triangles (if any)	
	iNumTris = 0;
	for (iMesh=0;iMesh<CCOL_Scn_ColTester::iNumColMeshes;iMesh++)
	{
		iNumTris += _Dst.GetMeshTester()->iTestCollision(CCOL_Scn_ColTester::ColMeshes[iMesh].poMesh,
														 CCOL_Scn_ColTester::ColMeshes[iMesh].iMat,
														 _Src.GrObj->poGetBoundVol(),
														 _Src.GetTriList());
	}

	return( iNumTris > 0);

  //## end CCOL_CollisionSystem::bTestNarrowCD%1008463032.body
}

// Additional Declarations
  //## begin CCOL_CollisionSystem%3B6F1A7F02E4.declarations preserve=yes
  //## end CCOL_CollisionSystem%3B6F1A7F02E4.declarations

//## begin module%3B6F1A7F02E4.epilog preserve=yes
//## end module%3B6F1A7F02E4.epilog
