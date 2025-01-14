//## begin module%3B7DA09D0386.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7DA09D0386.cm

//## begin module%3B7DA09D0386.cp preserve=no
//## end module%3B7DA09D0386.cp

//## Module: CGPhysicEntity%3B7DA09D0386; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\CGPhysicEntity.cpp

//## begin module%3B7DA09D0386.additionalIncludes preserve=no
//## end module%3B7DA09D0386.additionalIncludes

//## begin module%3B7DA09D0386.includes preserve=yes
#include "Game/Globals/globals.h"
CVect3 GRAVITY(0.0f,0.0f,-9.8f);
//## end module%3B7DA09D0386.includes

// CGPhysicEntity
#include "Game\Entities\CGPhysicEntity.h"
//## begin module%3B7DA09D0386.additionalDeclarations preserve=yes

#define	_SLIDE_ANGLE_THRESHOLD_		-0.05f
#define	_MOVEMENT_THRESHOLD_		0.1f
#define	_MAX_ZOMBIE_TIME			50


void HandleSliding(CCOL_Collider &_roCol,CVect3 &_roNormal,float _fFrameFact,CVect3 &_roNewPos,CVect3 &_roNewSpeed,CVect3 &_roDMins)
{
	CVect3 oPos;
	oPos.Interpolate(_roCol.OldPos,_roCol.Pos,_fFrameFact);

	// -----------------------------------
	// Handle sliding: movement direction
	// -----------------------------------
	if (_roNormal.X()*_roCol.Speed.X() < _SLIDE_ANGLE_THRESHOLD_) 
	{
		// if (_roDMins.X() > _fFrameFact)
		{
			_roDMins.SetX(_fFrameFact);
			_roNewSpeed.SetX(0.0f);
			_roNewPos.SetX(oPos.X());
		}
	}
	// else
	//		se queda igual
	
	if (_roNormal.Y()*_roCol.Speed.Y() < _SLIDE_ANGLE_THRESHOLD_) 
	{
		// if (_roDMins.Y() > _fFrameFact)
		{
			_roDMins.SetY(_fFrameFact);
			_roNewSpeed.SetY(0.0f);
			_roNewPos.SetY(oPos.Y());
		}
	}
	// else
	//		se queda igual

	if (_roNormal.Z()*_roCol.Speed.Z() < _SLIDE_ANGLE_THRESHOLD_) 
	{
		// if (_roDMins.Z() > _fFrameFact)
		{
			_roDMins.SetZ(_fFrameFact);
			_roNewSpeed.SetZ(0.0f);
			_roNewPos.SetZ(oPos.Z());
		}
	}
	// else
	//		se queda igual	
}
//## end module%3B7DA09D0386.additionalDeclarations


// Class CGPhysicEntity 











CGPhysicEntity::CGPhysicEntity()
  //## begin CGPhysicEntity::CGPhysicEntity%.hasinit preserve=no
      : iZombieTime(0), fRestitutionFact(0.5f), iContacts(0), iNumForces(0)
  //## end CGPhysicEntity::CGPhysicEntity%.hasinit
  //## begin CGPhysicEntity::CGPhysicEntity%.initialization preserve=yes
  //## end CGPhysicEntity::CGPhysicEntity%.initialization
{
  //## begin CGPhysicEntity::CGPhysicEntity%.body preserve=yes
  //## end CGPhysicEntity::CGPhysicEntity%.body
}


CGPhysicEntity::~CGPhysicEntity()
{
  //## begin CGPhysicEntity::~CGPhysicEntity%.body preserve=yes
  //## end CGPhysicEntity::~CGPhysicEntity%.body
}



//## Other Operations (implementation)
bool CGPhysicEntity::bCheckCollisions ()
{
  //## begin CGPhysicEntity::bCheckCollisions%1008108906.body preserve=yes

	// Total number of objects that have collided with this physic entity
	return (gCollisionSystem.bCheckCollision(oColObj,gDeltaT));

  //## end CGPhysicEntity::bCheckCollisions%1008108906.body
}

void CGPhysicEntity::ComputeCollisionResponse ()
{
  //## begin CGPhysicEntity::ComputeCollisionResponse%1008204519.body preserve=yes
/*
	int idxs[1024];
	int iCollidedTris =	CCOL_TriColTester::iTestCollision(oColObj.TriList.VXs,oColObj.TriList.VNs,idxs,
														  oColObj.TriList.iNumTris,
														  iColTris,oColObj.GrObj->GetBoundVol(),Pos);
	if (! iCollidedTris) return;
*/
	switch (ResponseType)
	{
		case CGame_ePRT_Bounce:
		{	
			CVect3	NewSpeed;
			CVect3	AccumNormal;
			int		iTri;

			// Compute accumulated normal: average of the normals of all triangle colliders
			AccumNormal.V3(0.0f,0.0f,0.0f);
			
			for (iTri=0;iTri<oColObj.GetTriList().iNumTris;iTri++)
			{
				AccumNormal.Add(oColObj.GetTriList().poVNs[iTri]);
			}

			/*
			float	fSpeedModule;
			float	fInvSpeedMod;
			CVect3	UnitSpeed;
			CVect3	Vt,Vn;					// We need the tangential and normal speed components						

			Vn.Assign(AccumNormal);
			Vn.Scale (Speed.DotProd(AccumNormal));
			
			Vt.Assign(Speed);
			Vt.Sub(Vn);
			UnitSpeed.LineEq(Vt,Vn, -(_RESTITUTION_FACTOR_) );
			UnitSpeed.Normalize();
			Speed.Mult(UnitSpeed);			
			*/

			AccumNormal.Normalize();

			float	fSpeedModule;
			float	fInvSpeedMod;
			CVect3	UnitSpeed;
			CVect3	Vt,Vn;					// We need the tangential and normal speed components

			fSpeedModule = oColObj.Speed.Module();
			fInvSpeedMod = 1.0f/fSpeedModule;

			UnitSpeed.Assign(oColObj.Speed);
			UnitSpeed.Scale(fInvSpeedMod);

			Vn.Assign(AccumNormal);
			Vn.Scale (UnitSpeed.DotProd(AccumNormal));
			
			Vt.Assign(UnitSpeed);
			Vt.Sub(Vn);
			
			oColObj.Speed.LineEq(Vt,Vn, -(fRestitutionFact) );
			oColObj.Speed.Scale (fSpeedModule);	

			CVect3	DX;
			float	fMod;
			DX.Assign(oColObj.Pos);
			DX.Sub   (oColObj.OldPos);
			fMod = DX.Module();

			if (fMod < _MOVEMENT_THRESHOLD_) 
				iZombieTime++;
			else
				iZombieTime = 0;

			if (iZombieTime == _MAX_ZOMBIE_TIME)
			{
				oColObj.Speed.V3(0.0f,0.0f,0.0f);
			}
		}
		break;

		case CGame_ePRT_Stop:
		{						
			CVect3	oNewPos;
			float	fFrameFact;

			if (oColObj.GetTriList().iNumTris)
				fFrameFact = oColObj.GetTriList().pfFrameFacts[0];
			else
				fFrameFact = oColObj.ColStack.Collided[0].fFrameFact;
		
			// oNewPos.LineEq(oColObj.OldPos,oColObj.Speed,fDTime);
			oNewPos.Interpolate(oColObj.OldPos,oColObj.Pos,fFrameFact);

			oColObj.Pos.Assign(oNewPos);
			oColObj.Speed.V3  (0.0f,0.0f,0.0f);
		}
		break;
		
		case CGame_ePRT_Slide:
		{
			// -------------------------------------------------------------
			// General response code for dynamic BV-BV collision detection
			// -------------------------------------------------------------
			CVect3			oNewPos,oNewSpeed;
			oNewPos.Assign    (oColObj.Pos);
			oNewSpeed.Assign  (oColObj.Speed);

			int				iCObj;
			CCOL_Collider	*poCol;
			float			fFrameFact;
			
			CVect3			oSPos,oDPos;
			CVect3			oSCen,oDCen;
			CVect3			oSMin,oSMax;
			CVect3			oDMin,oDMax;
			CVect3			oPivotDiff;

			CVect3			oDMins(1e6f,1e6f,1e6f);
			CVect3			oDDsp;						// Destination Displacement
			CVect3			oSExt;
			
			CVect3			oFaceNormal;				// Destination Box collision face

			// Object extents
			oSExt.Assign( oColObj.GrObj->poGetBoundVol()->GetExtents() );

			// Get object pivot
			oPivotDiff.Assign ( oColObj.GrObj->poGetBoundVol()->GetCenter() );
			oPivotDiff.Sub    ( oColObj.OldPos );			

			for (iCObj=0;iCObj<oColObj.GetColStack().GetNumCollisions();iCObj++)
			{
				poCol      = (CCOL_Collider*)oColObj.GetColStack().GetCollided()->poCObj;
				fFrameFact = oColObj.GetColStack().GetCollided()->fFrameFact;

				// Get object positions at collision point
				oSPos.Interpolate(oColObj.OldPos,oColObj.Pos,fFrameFact);				

				// Recompute source bounding box at fFrameFact time (at collision point)
				oSCen.Assign( oSPos );
				oSCen.Add   ( oPivotDiff );
				oSMin.Assign( oSCen );
				oSMin.Sub   ( oColObj.GrObj->poGetBoundVol()->GetExtents() );
				oSMax.Assign( oSCen );
				oSMax.Add   ( oColObj.GrObj->poGetBoundVol()->GetExtents() );

				// Recompute destination box at collision point
				oDCen.Interpolate(poCol->OldPos ,poCol->Pos ,fFrameFact);				
				oDCen.Add   (poCol->GrObj->poGetBoundVol()->GetCenter());
				oDCen.Sub   (poCol->OldPos);
				oDMin.Assign(oDCen);
				oDMin.Sub   (poCol->GrObj->poGetBoundVol()->GetExtents());
				oDMax.Assign(oDCen);
				oDMax.Add   (poCol->GrObj->poGetBoundVol()->GetExtents());
				

				// WARNING!!!!!!!!!!!!!!
				// Adivinar como solucionar de una manera elegante el efecto bounding volumes
				// mutables. Esto hace que en momento 0 ya esten penetradas las BBoxes

				// GUARRING CODE!!!!!!!
				// evita el problema arriba citado
				CVect3 oEps;				// Epsilons
				if (fFrameFact == 0.0f)
				{					
					oEps.Assign(oSExt);
					oEps.Scale(0.5f);
				}
				else
					oEps.V3(1e-3f,1e-3f,1e-3f);
				
				// Get the box face that the object is colliding
				 oFaceNormal.V3(0,0,0);
				 if (MATH_Common::bEqualF(oSMax.X(),oDMin.X(),oEps.X())) oFaceNormal.V3(-1 , 0, 0);
			else if (MATH_Common::bEqualF(oSMin.X(),oDMax.X(),oEps.X())) oFaceNormal.V3( 1 , 0, 0);
			else if (MATH_Common::bEqualF(oSMax.Y(),oDMin.Y(),oEps.Y())) oFaceNormal.V3( 0 ,-1, 0);
			else if (MATH_Common::bEqualF(oSMin.Y(),oDMax.Y(),oEps.Y())) oFaceNormal.V3( 0 , 1, 0);
			else if (MATH_Common::bEqualF(oSMax.Z(),oDMin.Z(),oEps.Z())) oFaceNormal.V3( 0 , 0,-1);
			else if (MATH_Common::bEqualF(oSMin.Z(),oDMax.Z(),oEps.Z())) oFaceNormal.V3( 0 , 0, 1);

				HandleSliding(oColObj,oFaceNormal,fFrameFact,oNewPos,oNewSpeed,oDMins);
				
				// Controlar situacion al final del frame				
				oDCen.Assign(poCol->Pos);
				oDCen.Add   (poCol->GrObj->poGetBoundVol()->GetCenter());
				oDCen.Sub   (poCol->OldPos);
				oDMin.Assign(oDCen);
				oDMin.Sub   (poCol->GrObj->poGetBoundVol()->GetExtents());
				oDMax.Assign(oDCen);
				oDMax.Add   (poCol->GrObj->poGetBoundVol()->GetExtents());
												
				// Comprobar collision al final del frame
				if (oFaceNormal.X())
				{
					if(oFaceNormal.X()<0)
					{
						if (oSMax.X() > oDMin.X())						
							// penetracion
							oNewPos.SetX( oDMin.X() - oSExt.X() - oPivotDiff.X() );
					}
					else
					{
						if (oSMin.X() < oDMax.X())
							// penetracion
							oNewPos.SetX( oDMax.X() + oSExt.X() - oPivotDiff.X() );
					}
				}
		   else if (oFaceNormal.Y())
				{
					if(oFaceNormal.Y()<0)
					{
						if (oSMax.Y() > oDMin.Y())
							// penetracion
							oNewPos.SetY( oDMin.Y() - oSExt.Y() - oPivotDiff.Y() );
					}
					else
					{
						if (oSMin.Y() < oDMax.Y())
							// penetracion
							oNewPos.SetY( oDMax.Y() + oSExt.Y() - oPivotDiff.Y() );
					}
				}
		   else if (oFaceNormal.Z())
				{
					if(oFaceNormal.Z()<0)
					{
						if (oSMax.Z() > oDMin.Z())
							// penetracion
							oNewPos.SetZ( oDMin.Z() - oSExt.Z() - oPivotDiff.Z() );
					}
					else
					{
						if (oSMin.Z() < oDMax.Z())
							// penetracion
							oNewPos.SetZ( oDMax.Z() + oSExt.Z() - oPivotDiff.Z() );
					}
				}
			}

			// -------------------------------------------------------------
			// General response code for dynamic BV-Tris collision detection
			// -------------------------------------------------------------

			// Si las componentes Velocidad/Triangulo tienen signo distinto, se anulan
			// si no, de las que no, se obtiene la nueva velocidad
			// speed = (1.0f,0.0f,-9.8f) / Triangulo(0.0f,0.0f,1.0f)
			// NewSpeed = (1.0f,0.0f,0.0f);

			#define fAbs MATH_Common::fAbs


			CVect3 *poVN;
			CVect3 *poVX;
			int		iTri;
			CVect3	oPos;			
			
			
			CVect3	oMCent		= oColObj.GrObj->poGetBoundVol()->GetCenter();
			float	fRange		= oColObj.GrObj->poGetBoundVol()->GetRange(2);
			float	fExtZ		= fRange*0.5f;
			float	fStepSize	= fRange / 5.0f;
			float	fMinHeight	= oMCent.Z() + fExtZ - fStepSize;

			for (iTri=0;iTri<oColObj.GetTriList().iNumTris;iTri++)
			{
				poVN       = &oColObj.GetTriList().poVNs[iTri];
				poVX	   = &oColObj.GetTriList().poVXs[iTri*3];
				fFrameFact =  oColObj.GetTriList().pfFrameFacts[iTri];
				oPos.Interpolate(oColObj.OldPos,oColObj.Pos,fFrameFact);
			
				// -----------------------------------	
				// Ignore vertical triangles just below the model
				// -----------------------------------
				if ( ( fAbs(poVN->X()) > fAbs(poVN->Z()) ) || 
					 ( fAbs(poVN->Y()) > fAbs(poVN->Z()) ) )
				{	
					if ((poVX[0].Z() < fMinHeight) &&
					    (poVX[1].Z() < fMinHeight) &&
						(poVX[2].Z() < fMinHeight))
						continue;
				}
				
				HandleSliding(oColObj,*poVN,fFrameFact,oNewPos,oNewSpeed,oDMins);
			}

			// -----------------------------------
			// Control stair steps
			// -----------------------------------
			int   ai6[6];
			float af6[6];
			CCOL_TriList_BVRayTest::Test(oMCent,
										 oColObj.GetTriList(),
										 1 << 5,
										 af6,
										 ai6);
			if (ai6[5] != -1)
			{
				if ((af6[5] < fExtZ) && (fExtZ - af6[5] < fStepSize))
				{
					// Over a new tri
					oNewPos.SetZ(oMCent.Z() - af6[5]);
				}
			}


			// Setup new position and speed
			oColObj.Pos.Assign(oNewPos);
			oColObj.Speed.Assign(oNewSpeed);
		}
		break;

	}
	
  //## end CGPhysicEntity::ComputeCollisionResponse%1008204519.body
}

void CGPhysicEntity::ApplyForces (float _fDelta)
{
  //## begin CGPhysicEntity::ApplyForces%1021497763.body preserve=yes
	CVect3 oNewPos;
	CVect3 oNewSpeed = oFinalForce();	

	// x = x0 + vt
	oNewPos.Assign(oNewSpeed);
	oNewPos.Scale (_fDelta);
	oNewPos.Add	  (oColObj.Pos);

	oColObj.OldPos.Assign(oColObj.Pos);
	oColObj.Pos.Assign   (oNewPos);
	oColObj.Speed.Assign (oNewSpeed);
  //## end CGPhysicEntity::ApplyForces%1021497763.body
}

void CGPhysicEntity::ProcessCmds (float _fDelta)
{
  //## begin CGPhysicEntity::ProcessCmds%1021497764.body preserve=yes
  //## end CGPhysicEntity::ProcessCmds%1021497764.body
}

// Additional Declarations
  //## begin CGPhysicEntity%3B7DA09D0386.declarations preserve=yes
  //## end CGPhysicEntity%3B7DA09D0386.declarations

//## begin module%3B7DA09D0386.epilog preserve=yes
//## end module%3B7DA09D0386.epilog
