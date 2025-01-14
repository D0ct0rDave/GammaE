//## begin module%3B5DFD6B014A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B5DFD6B014A.cm

//## begin module%3B5DFD6B014A.cp preserve=no
//## end module%3B5DFD6B014A.cp

//## Module: CPlayer%3B5DFD6B014A; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\Player\CPlayer.cpp

//## begin module%3B5DFD6B014A.additionalIncludes preserve=no
//## end module%3B5DFD6B014A.additionalIncludes

//## begin module%3B5DFD6B014A.includes preserve=yes

#include "Game\Globals\Globals.h"
#include "Game\Entities\CBoxEntity.h"
#include "Game/Entities/CGPEntityType.h"
// #define _DEBUG_COLLISION_
bool bInsidePlayer;
//## end module%3B5DFD6B014A.includes

// CPlayer
#include "Game\Entities\Player\CPlayer.h"
//## begin module%3B5DFD6B014A.additionalDeclarations preserve=yes

int iCurrentFrame = 1;

#define		DEF_ACCEL		 50.0f
#define		DEF_DECCEL	   -200.0f
#define		DEF_JUMPSPEED	500.0f
#define		MAX_SPEED_XY	200.0f
#define		MAX_SPEED_Z		100.0f
#define		DEF_GRAVITY		(-9.8f)

#define		FRAME_STAND		1
#define		FRAME_RUN		2
#define		FRAME_WALK		4
#define		FRAME_ATTACK	3
#define		FRAME_JUMP		7


#define		MFLAG_FW		0x01
#define		MFLAG_BK		0x02
#define		MFLAG_RT		0x04
#define		MFLAG_LF		0x08

#define		MFLAG_FWBK	(MFLAG_FW | MFLAG_BK)
#define		MFLAG_LFRT	(MFLAG_LF | MFLAG_RT)
#define		MFLAG_LFFW	(MFLAG_LF | MFLAG_FW)
#define		MFLAG_LFBK  (MFLAG_LF | MFLAG_BK)
#define		MFLAG_RTFW	(MFLAG_RT | MFLAG_FW)
#define		MFLAG_RTBK  (MFLAG_RT | MFLAG_BK)

// Roll up
#define		MFLAG_RU		0x10	
// Roll down
#define		MFLAG_RD		0x20	
// Yaw up
#define		MFLAG_YU		0x40
// Yaw down
#define		MFLAG_YD		0x80

#define		MFLAG_RURD	(MFLAG_RU | MFLAG_RD)
#define		MFLAG_YUYD  (MFLAG_YU | MFLAG_YD)


inline bool bExclusiveFlags(int iFlags,int Flag)
{
	return(iFlags == Flag);
}



#ifdef _DEBUG_COLLISION_
CMesh				gPlayerMesh;
CObject3D_Leaf		gPlayerLeaf;
CObject3D_Transf	gPlayerTransf;
#endif


//## end module%3B5DFD6B014A.additionalDeclarations


// Class CPlayer 









CPlayer::CPlayer()
  //## begin CPlayer::CPlayer%.hasinit preserve=no
      : ePrevState(PS_Idle), eState(PS_Idle), eLastCmd(PC_None), iState(0), iCFrame(0), iMFlags(0), fRoll(0), fYaw(0)
  //## end CPlayer::CPlayer%.hasinit
  //## begin CPlayer::CPlayer%.initialization preserve=yes
  //## end CPlayer::CPlayer%.initialization
{
  //## begin CPlayer::CPlayer%.body preserve=yes

  	// Initialize graphic object


  //## end CPlayer::CPlayer%.body
}


CPlayer::~CPlayer()
{
  //## begin CPlayer::~CPlayer%.body preserve=yes
  //## end CPlayer::~CPlayer%.body
}



//## Other Operations (implementation)
void CPlayer::Init (CObject3D* _poModel, CObject3D* _poMesh)
{
  //## begin CPlayer::Init%1019254138.body preserve=yes
	iState |= PS_Idle;
	iCFrame = FRAME_STAND;

	// Define collision information
	poModel = (CObject3D_Transf    *)_poModel;
	poMesh  = (CObject3D_AnimCfgGen*)_poMesh;
	
	ResponseType = CGame_ePRT_Slide;// CGame_ePRT_Stop;
	oColObj.Init(CGPET_Player,NULL,NULL,
				eCOL_CT_Dynamic,eCOL_TT_Tris/*eCOL_TT_BV*/,eCOL_TT_BV,
				poModel,
				250,10);

	CVect3 oPos(0.0f,0.0f,0.0f);
	poModel->SetPos		 (oPos);	
	oColObj.Pos.Assign   (oPos);
	oColObj.OldPos.Assign(oPos);
	oColObj.Speed.V3(0.0f,0.0f,0.0f);


	#ifdef _DEBUG_COLLISION_	
	gPlayerMesh.usNumPrims = 0;
	gPlayerMesh.usNumIdxs  = 0;
	gPlayerMesh.usNumVerts = 0;

	gPlayerLeaf.SetMesh(&gPlayerMesh);
	gPlayerLeaf.SetShader(NULL);
	
	gPlayerTransf.SetObject(&gPlayerLeaf);
	gDynObjs.iAddObject(&gPlayerTransf);	// Add object to render	
	#endif
  //## end CPlayer::Init%1019254138.body
}

void CPlayer::SetupFrameFromFlags ()
{
  //## begin CPlayer::SetupFrameFromFlags%996856077.body preserve=yes
	 if (iState & PS_Attacking)
	 {
		if (iCFrame != FRAME_ATTACK)
		{
			iCFrame = FRAME_ATTACK;			
			poMesh->SetFrameAnim(iCFrame);
		}
	 }
else if (iState & PS_Jumping)
	 {
		if (iCFrame != FRAME_JUMP)
		{		
			iCFrame = FRAME_JUMP;
			poMesh->SetFrameAnim(iCFrame);
		}
	 }
else if (iState & PS_Running)
	 {
		if (iCFrame != FRAME_RUN)
		{
			iCFrame = FRAME_RUN;
			poMesh->SetFrameAnim(iCFrame);
		}
	 }
else if (iCFrame != FRAME_STAND)
	{
		iCFrame = FRAME_STAND;
		poMesh->SetFrameAnim(iCFrame);
	}

  //## end CPlayer::SetupFrameFromFlags%996856077.body
}

void CPlayer::Fire ()
{
  //## begin CPlayer::Fire%1019293385.body preserve=yes
	CBoxEntity	*poBox = mNew CBoxEntity;

	CVect3 oSpeed;
	oSpeed.V3(	MATH_Common::fRand()-0.5f,
				MATH_Common::fRand()-0.5f,
				MATH_Common::fRand()-0.5f);

	oSpeed.Normalize();
	oSpeed.Scale(10.0f);
	
	poBox->Init(oColObj.Pos,oSpeed);

	// Add to world entities
	gWorldEntities.iAddEntity(poBox);
  //## end CPlayer::Fire%1019293385.body
}

void CPlayer::Think (float _fDelta)
{
  //## begin CPlayer::Think%1020720917.body preserve=yes
	
	// Process and generate input commands
	// AI will generate decisions and perform movements or actions

  //## end CPlayer::Think%1020720917.body
}

void CPlayer::ControlCmds (int _iCmd, bool _bEnabled, float _fValue)
{
  //## begin CPlayer::ControlCmds%1020720918.body preserve=yes

	CVect3	AccelFact;

	// Computo del vector de incremento	    
	switch (_iCmd)
	{
		case PC_Forward:							
		case PC_Backward:	
		case PC_Left:		
		case PC_Right:		if (iCFrame == FRAME_STAND)
							{
								poMesh->SetFrameAnim(FRAME_RUN);
								iCFrame = FRAME_RUN;
							}
							
							switch (_iCmd)
							{
								case PC_Forward:if (_bEnabled)
													iMFlags |= MFLAG_FW;
												else
													iMFlags &= ~MFLAG_FW;
												break;

								case PC_Backward:if (_bEnabled)
													iMFlags |= MFLAG_BK;
												else
													iMFlags &= ~MFLAG_BK;
												break;

								case PC_Left:	if (_bEnabled)
													iMFlags |= MFLAG_LF;
												else
													iMFlags &= ~MFLAG_LF;
												break;

								case PC_Right:	if (_bEnabled)
													iMFlags |= MFLAG_RT;
												else
													iMFlags &= ~MFLAG_RT;
												break;
							}
							// Control running flag
							if ((iMFlags & MFLAG_FW) | (iMFlags & MFLAG_BK) |
								(iMFlags & MFLAG_LF) | (iMFlags & MFLAG_RT))
								iState |= PS_Running;
							else
								iState &= ~PS_Running;
							break;

		case PC_Roll:		if (_bEnabled)
							{
								fRoll += 2.0f*_fValue;
								SetAngles(fRoll,fYaw,0.0f);
							}
							break;
		case PC_Yaw:		/*
							if (bEnabled)
							{
								fYaw += fValue;
								SetAngles(fRoll,fYaw);
							}
							*/
							break;

		case PC_Jump:		if (iState & PS_Jumping) return;

							if (
								(iCFrame == FRAME_STAND)||
								(iCFrame == FRAME_RUN)
								)
							{
								poMesh->SetFrameAnim(FRAME_JUMP);
								iCFrame = FRAME_JUMP;
							}
														
							oColObj.Speed.Add(0,0,DEF_JUMPSPEED);
							iState |= PS_Jumping;
							break;
		
		case PC_Shot:		/*		
							if (RocketFact)
							{
								CRocket *Rocket = RocketFact->Create(Pos,Dir,0);
								WorldEntities.AddEntity(Rocket);								
							}
							*/
							if (_bEnabled)							
							{
								Fire();
								iState |= PS_Attacking;
							}
							else
								iState &=~ PS_Attacking;
							break;		
	}

  //## end CPlayer::ControlCmds%1020720918.body
}

void CPlayer::ProcessCmds (float _fDelta)
{
  //## begin CPlayer::ProcessCmds%1021497765.body preserve=yes

  	// Process input commands

  	CVect3	oNewPos;
	CVect3	oNewSpeed;
	CVect3  oDir;
	CVect3	at,vt,v0,p0;	

	// La gravedad por un lado
	at.V3(0.0f,0.0f,GRAVITY.Z());
	at.Scale(_fDelta);
	at.SetZ(at.Z()*MAX_SPEED_Z + oColObj.Speed.Z());	
	AddForce(at);

	// Velocidad por otro
	v0.V3(0.0f,0.0f,0.0f);
	if (iMFlags & MFLAG_FW)	{ v0.Add( poModel->roDir() );	iState |= PS_Running; }
	if (iMFlags & MFLAG_BK)	{ v0.Sub( poModel->roDir() );	iState |= PS_Running; }
	if (iMFlags & MFLAG_LF)	{ v0.Sub( poModel->roSide() );	iState |= PS_Running; }
	if (iMFlags & MFLAG_RT)	{ v0.Add( poModel->roSide() );	iState |= PS_Running; }

	oNewSpeed.Assign(v0);	
	oNewSpeed.SetX(oNewSpeed.X() * MAX_SPEED_XY);
	oNewSpeed.SetY(oNewSpeed.Y() * MAX_SPEED_XY);
	oNewSpeed.SetZ(oNewSpeed.Z() * MAX_SPEED_Z );

	AddForce(oNewSpeed);
  //## end CPlayer::ProcessCmds%1021497765.body
}

void CPlayer::ComputeCollisionResponse ()
{
  //## begin CPlayer::ComputeCollisionResponse%1021497766.body preserve=yes
	
	// Detect collided entities during this frame
	int				iCObj;
	CCOL_Collider	*poCol;
	int				iEnt;

	for (iCObj=0;iCObj<oColObj.GetColStack().GetNumCollisions();iCObj++)
	{
		// If the entity is a Platform, add to the dragged object list
		poCol = (CCOL_Collider*)oColObj.GetColStack().GetCollided()->poCObj;

		if ( poCol->UserID == CGPET_Platform)
		{		
			for (iEnt=0;iEnt<gaoPlatforms.iNumElems();iEnt++)
			{
				if (gaoPlatforms[iEnt]->poColObj == poCol)
				{												
					gaoPlatforms[iEnt]->iDragEntity(this);
					break;
				}
			}
		}
	}

	CGPhysicEntity::ComputeCollisionResponse();
  //## end CPlayer::ComputeCollisionResponse%1021497766.body
}

void CPlayer::Interact (float _fDelta)
{
  //## begin CPlayer::Interact%1021565346.body preserve=yes

	// Apply forces from the input commands (and some previous frame info)
	ApplyForces(_fDelta);
	ClearForces();				// Clear forces after applying all of them

	// Setup new model position as the result of applying previous forces
	// poModel->SetPos(oColObj.Pos);

	#ifdef _DEBUG_COLLISION_
	gPlayerMesh.usNumPrims = 0;
	gPlayerMesh.usNumVerts = 0;
	#endif
	
	bInsidePlayer = true;
	if ( bCheckCollisions() ) 
	{	
		ComputeCollisionResponse();		
		
		#ifdef _DEBUG_COLLISION_
		gPlayerMesh.VXs			= oColObj.GetTriList().poVXs;
		gPlayerMesh.VNs			= NULL;
		gPlayerMesh.usNumPrims	= oColObj.GetTriList().iNumTris;
		gPlayerMesh.usNumVerts	= oColObj.GetTriList().iNumTris*3;
		gPlayerMesh.eMeshType	= E3D_MESH_NITRIS;
		gPlayerMesh.BVol		= NULL;
		#endif
	}
	bInsidePlayer = false;

	if (iState & PS_Jumping)
	{
		// if there was a floor collision during the previous and the current frame
		if (oColObj.OldPos.Z() == oColObj.Pos.Z())
		{
			iState &= ~PS_Jumping;
			oColObj.Speed.SetZ(0);
		}
	}

	SetupFrameFromFlags();

	// Setup model position for this frame
	poModel->SetPos(oColObj.Pos);

  //## end CPlayer::Interact%1021565346.body
}

// Additional Declarations
  //## begin CPlayer%3B5DFD6B014A.declarations preserve=yes
  //## end CPlayer%3B5DFD6B014A.declarations

//## begin module%3B5DFD6B014A.epilog preserve=yes
//## end module%3B5DFD6B014A.epilog
