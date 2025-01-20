// -----------------------------------------------------------------------------
#include "CCamera.h"
#include "Game/GameGraphics/C3DObjWH.h"
#include "Game/CGameGlobals.h"
#include "Game/Ents/CEntityMgr.h"
#include "Game/GameGraphics/CEntRend.h"

#define DEFAULT_FOV			45
#define TRANSITION_FACT		0.25f

int				m_iLastType;
// -----------------------------------------------------------------------------
CCamera::CCamera()
{
	m_iType     = ENT_CAMERA;
	m_iSubType  = 6;
	m_iDir		= 1;

	m_oHAAvg.Init(0.0f,TRANSITION_FACT);
	m_oVAAvg.Init(0.0f,TRANSITION_FACT);
	m_oRAvg.Init (0.0f,TRANSITION_FACT);

	m_oPitchAvg.Init (0.0f,TRANSITION_FACT);
	m_oYawAvg.Init (0.0f,TRANSITION_FACT);
	m_oRollAvg.Init (0.0f,TRANSITION_FACT);
	
	CCameraGraphicInstance* poCamGI = pNew CCameraGraphicInstance;
	poCamGI->m_poCam = &m_oCam;

	m_poGI = poCamGI;
}
// -----------------------------------------------------------------------------
CCamera::~CCamera()
{
}
// -----------------------------------------------------------------------------
void CCamera::Init(MTH_CPoint3& _oPos,int _iPlayerID)
{
	// Get the player ID
	m_iPlayerID = _iPlayerID;

	// Add entity to the entity manager
	CEntityMgr::iAddEntity(this);
	
	//
	CEntRend::iAdd(this);

	// Initialize camera
	m_oFrame.Identity();	
	m_oFrame.m_oMatrix.SetAt(2,2,-1);
	m_oCam.SetFrame(&m_oFrame);	
	// m_oCam.Perspective(45.0f, (float)STD_SCR_WIDTH / (float)STD_SCR_HEIGHT, 1.0f, 2000.0f);
	m_oCam.Frustum(0,STD_SCR_WIDTH,0,STD_SCR_HEIGHT,1.0f, 5000.0f);
	m_oPos = _oPos + MTH_CPoint3(1,1,1);
	
	MTH_CPoint3 oUp    (0,1,0);
	MTH_CPoint3 oTarget(0,0,1);

	m_oCam.LookAt(m_oPos,_oPos,oUp,DEFAULT_FOV);
	
	// Setup global variable
	gpoCamera[m_iPlayerID] = this;
	m_eState = ENTSTATE_ALIVE;
}
// -----------------------------------------------------------------------------
void CCamera::CheckNewPos(float m_fDeltaT)
{

}
// -----------------------------------------------------------------------------
void CCamera::RadialCamera(float m_fDeltaT,float _fH,float _fRad,float _fHAng,float _fVAng)
{
	MTH_CPoint3 oCamOfs;
	MTH_CPoint3 oRelPos(gpoPlayer[giCurPlayer]->m_oPos.x,0.0f,gpoPlayer[giCurPlayer]->m_oPos.z);

	float fVAng = m_oVAAvg.fAverager(m_fDeltaT,_fVAng,TRANSITION_FACT);
	float fHAng = m_oHAAvg.fAverager(m_fDeltaT,_fHAng,TRANSITION_FACT);
	float fRad  = m_oRAvg .fAverager(m_fDeltaT, _fRad,TRANSITION_FACT);

    oCamOfs.x = -fRad*fCos(fHAng)*fCos(fVAng);
	oCamOfs.y = -fRad*fSin(fVAng);
	oCamOfs.z = -fRad*fSin(fHAng)*fCos(fVAng);

	MTH_CPoint3 oDir;
	MTH_CPoint3 oUp (0,1,0);
	
	MTH_CPoint3 oCamPos = oRelPos - oCamOfs;	
	oCamPos.y    += _fH;
	
	MTH_CPoint3 oTargetPos = gpoPlayer[giCurPlayer]->m_oPos;
	oTargetPos.y += _fH;

	m_oCam.LookAt(oCamPos,oTargetPos, oUp,DEFAULT_FOV );

	// Cargar matrices de camara en display context
	m_oCam.PrepareDC(gDC);

	m_oOPos = m_oPos;
	m_oPos  = oCamPos;
}
// -----------------------------------------------------------------------------
void CCamera::Think(float _fDeltaT)
{
	if ((m_eState == ENTSTATE_INACTIVE) || (m_eState == ENTSTATE_DEAD) || (m_eState == ENTSTATE_NONE)) return;
	
	// Free / Normal camera change
	/*
	if (gaInput[m_iPlayerID].justpressed.r3)
	{
		if (m_iSubType == 0)
			m_iSubType = m_iLastType;
		else
		{
			m_iLastType = m_iSubType;
			m_iSubType = 0;
		}
	}
	*/

	switch (m_iSubType)
	{
		// --------------------------------------------
		// Free camera
		case 0:
		{
			MTH_CPoint3 oDir,oUp,oSide,oPos,oTarget;

			/*
			m_oCamFrame.m_oMatrix.GetRow0(&oSide);
			m_oCamFrame.m_oMatrix.GetRow1(&oUp);
			m_oCamFrame.m_oMatrix.GetRow2(&oDir);
			m_oCamFrame.m_oMatrix.GetCol3(&oPos);
			*/

			oSide = m_oCam.m_oSide;
			oPos  = m_oCam.m_oPos;
			oUp   = m_oCam.m_oUp;
			oDir  = m_oCam.m_oDir;

			oSide.y = 0.0f;
			oSide.Unit();

			oDir.Cross(oSide,oUp);

			// This allows change the camera speed movement while debugging
			static float s_fXZStepFact = 25.0f;
			static float s_fYStepFact  = 25.0f;
			static float s_fAStepFact  = 0.75f;
			static float s_fBStepFact  = 0.25f;

			// Control input
			float fXZStepFact = s_fXZStepFact;
			float fYStepFact  = s_fYStepFact;
			float fAStepFact  = s_fAStepFact;
			float fBStepFact  = s_fBStepFact;

			if (gaInput[m_iPlayerID].pressed.l3) 
			{
				const float _f1OVER3 = 1.0f / 3.0f;

				fXZStepFact *= _f1OVER3;
				fAStepFact  *= _f1OVER3;
			}


			float fXZStep = gfDeltaT*fXZStepFact;
			float fYStep  = gfDeltaT*fYStepFact;    
			float fAStep  = gfDeltaT*fAStepFact;
			float fBStep  = gfDeltaT*fBStepFact;

			
			// ---------------------------------------------------------------------------	
			if (gaInput[m_iPlayerID].pressed.square)
				oPos -= (oSide * fXZStep);

			if (gaInput[m_iPlayerID].pressed.circle)
				oPos += (oSide * fXZStep);

			if (gaInput[m_iPlayerID].pressed.triangle)
				oPos -= (oDir * fXZStep);

			if (gaInput[m_iPlayerID].pressed.cross)
				oPos += (oDir * fXZStep);

			if (! gaInput[m_iPlayerID].pressed.l3)
			{
				if (gaInput[m_iPlayerID].pressed.r1)
					oPos += (oUp*fYStep);

				if (gaInput[m_iPlayerID].pressed.l1)
					oPos -= (oUp*fYStep);
			}

			if ((gaInput[m_iPlayerID].pressed.left) || (gaInput[m_iPlayerID].pressed.lstick.left))
			{			
				MTH_CMat4x4 oRMat;
				float fFact = fMax( (float)gaInput[m_iPlayerID].pressed.lstick.left / 255.0f,
									 gaInput[m_iPlayerID].pressed.left);
				MTH_CPoint3 oUp(0,1,0);
				oRMat.Rotate(oUp,fAStep*fFact);

				oRMat.MultVec3(oDir,oDir);
				oSide.Cross(oDir,oUp);
			}

			if ((gaInput[m_iPlayerID].pressed.right) || (gaInput[m_iPlayerID].pressed.lstick.right))
			{			
				MTH_CMat4x4 oRMat;
				float fFact = fMax( (float)gaInput[m_iPlayerID].pressed.lstick.right / 255.0f,
									 gaInput[m_iPlayerID].pressed.right);

				MTH_CPoint3 oUp(0,1,0);
				oRMat.Rotate(oUp,-fAStep*fFact);
				
				oRMat.MultVec3(oDir,oDir);
				oSide.Cross(oDir,oUp);
			}

			if ((gaInput[m_iPlayerID].pressed.up) || (gaInput[m_iPlayerID].pressed.lstick.up))
			{
				MTH_CMat4x4 oRMat;
				float fFact = fMax( (float)gaInput[m_iPlayerID].pressed.lstick.up / 255.0f,
									 gaInput[m_iPlayerID].pressed.up);

				oRMat.Rotate(oSide,fAStep*fFact);
				oRMat.MultVec3(oDir,oDir);
				oDir.Cross(oSide,oUp);
			}

			if ((gaInput[m_iPlayerID].pressed.down) || (gaInput[m_iPlayerID].pressed.lstick.down))
			{			
				MTH_CMat4x4 oRMat;
				float fFact = fMax( (float)gaInput[m_iPlayerID].pressed.lstick.down / 255.0f,
									 gaInput[m_iPlayerID].pressed.down);
				
				oRMat.Rotate(oSide,-fAStep*fFact);
								
				oRMat.MultVec3(oDir,oDir);
				oDir.Cross(oSide,oUp);
			}

			// Set new camera properties
			oTarget.AddScaled(oPos,oDir,-1.0f);
			m_oCam.LookAt(oPos,oTarget, oUp,DEFAULT_FOV );
			// m_oCam.Ortho(0,(float)STD_SCR_WIDTH,0.0f,(float)STD_SCR_HEIGHT, 1.0f, 2000.0f);
			m_oCam.Ortho(-1,1,-1,1, 1.0f, 1000.0f);
			// m_oCam.Perspective(45.0f,4.0f/3.0f,1,1000);

			m_oPos = m_oCam.m_oPos;
		}
		break;
		
		// --------------------------------------------
		// Game camera near
		case 1:
		{
			#define MIN_RAD 1
			#define MAX_RAD 2

			#define MIN_ANG 30*_PI_/180.0f
			#define MAX_ANG 15*_PI_/180.0f

			/*
			m_fHAng = _PI2_;
			m_fVAng = fInterpol(MAX_ANG,MIN_ANG,(gpoPlayer[giCurPlayer]->m_oPos.z+16)/32);
			m_fRad  = fInterpol(MAX_RAD,MIN_RAD,(gpoPlayer[giCurPlayer]->m_oPos.z+16)/32);
			m_fH    = 0.0f;
			*/

			m_fHAng = -_PI2_;
			m_fVAng = -_PI2_;
			m_fRad  = fInterpol(MAX_RAD,MIN_RAD,(gpoPlayer[giCurPlayer]->m_oPos.z+16)/32);
			m_fH    = 0.0f;

			RadialCamera(m_fDeltaT,m_fH,m_fRad,m_fHAng,m_fVAng);
		}
		break;
		
		// --------------------------------------------
		// Game camera far
		case 2:
		{
			m_fHAng = _PI2_;
			m_fVAng = 30.5f*_PI_/180.0f;
			m_fRad  = 25.0f;
			m_fH    = 0.0f;

			RadialCamera(m_fDeltaT,m_fH,m_fRad,m_fHAng,m_fVAng);
		}
		break;

		
		// --------------------------------------------
		// Game camera third person: Rayman 3 style
		case 3:
		{
			m_fVAng	  		= 15.5f*_PI_/180.0f;
			m_fRad 	  		= 9.0f;
			m_fH	  		= 4.0f;
			m_fMinDst 		= 2.5f;
			m_fRecoverAngle	= 1.5f;

			float fRad   = m_oRAvg .fAverager(m_fDeltaT,m_fRad, TRANSITION_FACT);
			float fAng   = m_oVAAvg.fAverager(m_fDeltaT,m_fVAng,TRANSITION_FACT);
			float fYDist = fRad*fSin(fAng);

			// 
			MTH_CPoint3 oCamPos;
			MTH_CPoint3 oDir;

			// Set Camera Target position
			MTH_CPoint3 m_oTargetPos = gpoPlayer[giCurPlayer]->m_oPos + MTH_CPoint3(0, m_fH - fYDist,0);

			// Proyected into Plane Player Position
			MTH_CPoint3	m_oPPPPos(gpoPlayer[giCurPlayer]->m_oPos.x,0,gpoPlayer[giCurPlayer]->m_oPos.z);

			// Proyected into Plane Camera Position
			MTH_CPoint3	m_oPPCPos(m_oPos.x,0,m_oPos.z);

			oDir = m_oPPPPos - m_oPPCPos;
			
			// Projected distance
			float fDist = oDir.fGetLength();
			oDir *= (1.0f / fDist);

			if ( fDist > m_fRad)
			{
				oCamPos.x = m_oTargetPos.x - fRad*oDir.x;
				oCamPos.y = m_fH;
				oCamPos.z = m_oTargetPos.z - fRad*oDir.z;
			}

			
		else if (fDist < m_fMinDst)
			{
				MTH_CPoint3 oNewDir;
				MTH_CMat4x4 oRMat;

				oRMat.RotateY(m_fRecoverAngle);
				oRMat.Mult3x3Vec3(oDir,oNewDir);

				oCamPos.x = m_oTargetPos.x - m_fMinDst*oNewDir.x;
				oCamPos.y = m_fH;
				oCamPos.z = m_oTargetPos.z - m_fMinDst*oNewDir.z;
			}
		else
			{
				oCamPos = m_oPos;
			}

			MTH_CPoint3 oUp (0,1,0);
			m_oCam.LookAt( oCamPos, m_oTargetPos, oUp,DEFAULT_FOV );

			m_oPos = oCamPos;

			// Cargar matrices de camara en display context
			m_oCam.PrepareDC(gDC);
			m_oOPos = m_oPos;
		}
		break;

		// -----------------------------------------
		// Game camera third person
		case 4:
		{
			m_fVAng  		= 15.5f*_PI_/180.0f;
			m_fRad   		= 9.0f;
			m_fH     		= 4.0f;
			m_fMinDst		= 4.0f;
			m_fRecoverAngle = 1.5f;
			m_fRecoverFact  = 1.0f;

			float fRad   = m_fRad; // m_oRAvg.fAverager(m_fDeltaT,m_fRad,	TRANSITION_FACT);
			float fAng   = m_fVAng; // m_oVAAvg.fAverager(m_fDeltaT,m_fVAng,	TRANSITION_FACT);
			float fYDist = fRad*fSin(fAng);

			// 
			MTH_CPoint3 oCamPos;
			MTH_CPoint3 oDir;

			// Set Camera Target position
			MTH_CPoint3 m_oTargetPos = gpoPlayer[giCurPlayer]->m_oPos + MTH_CPoint3(0, m_fH - fYDist,0);
			float fDist = m_oPos.fDistance(m_oTargetPos);
			
			if (fDist > fRad)
			{
				//
				// DMC ProjectQ: gpoPlayer[giCurPlayer]->m_poGI->GetOrientation(&oDir,NULL,NULL);

				MTH_CPoint3 oIdealCamPos;

				oIdealCamPos.x = m_oTargetPos.x - fRad*oDir.x;
				oIdealCamPos.y = m_fH;
				oIdealCamPos.z = m_oTargetPos.z - fRad*oDir.z;

				oCamPos.x = fInterpol(m_oPos.x,oIdealCamPos.x,m_fRecoverFact*m_fDeltaT);
				oCamPos.y = fInterpol(m_oPos.y,oIdealCamPos.y,m_fRecoverFact*m_fDeltaT);
				oCamPos.z = fInterpol(m_oPos.z,oIdealCamPos.z,m_fRecoverFact*m_fDeltaT);
			}
		else if (fDist < m_fMinDst)
			{
				oDir = m_oTargetPos - m_oPos;
				oDir.Unit();

				MTH_CPoint3 oNewDir;
				MTH_CMat4x4 oRMat;

				oRMat.RotateY(m_fRecoverAngle);
				oRMat.Mult3x3Vec3(oDir,oNewDir);

				oCamPos.x = m_oTargetPos.x - m_fMinDst*oNewDir.x;
				oCamPos.y = m_fH;
				oCamPos.z = m_oTargetPos.z - m_fMinDst*oNewDir.z;
			}
		else
			{
				oCamPos = m_oPos;
			}

			MTH_CPoint3 oUp (0,1,0);
			m_oCam.LookAt( oCamPos, m_oTargetPos, oUp,DEFAULT_FOV );

			m_oPos = oCamPos;

			// Cargar matrices de camara en display context
			m_oCam.PrepareDC(gDC);
			m_oOPos = m_oPos;
		}
		break;

		// --------------------------------------------
		case 5:
		{
			MTH_CPoint3 oUp (0,1,0);
			
			m_oPos      .Set(0,20,32);
			m_oTargetPos.Set(0,19.5,31);

			m_oCam.LookAt( m_oPos, m_oTargetPos, oUp,DEFAULT_FOV );

			// Cargar matrices de camara en display context
			m_oCam.PrepareDC(gDC);
			m_oOPos = m_oPos;
		}
		break;
		
		// --------------------------------------------
		// Bomberman like camera: Pad controlled camera
		case 6:
		{
			// Handle camera input
			if (gaInput[m_iPlayerID].justpressed.rtrigger)
			{
				m_iDir = m_iDir + 1;
				if (m_iDir >= 4)
				{
					m_iDir = 0;
					m_oHAAvg.Init(-_PI2_,TRANSITION_FACT);	// To avoid averager discontinuity
				}
			}
			if (gaInput[m_iPlayerID].justpressed.ltrigger)
			{
				m_iDir = m_iDir - 1;
				if (m_iDir < 0)
				{
					m_iDir = 3;
					m_oHAAvg.Init(_2PI_,TRANSITION_FACT);		// To avoid averager discontinuity
				}
			}

			m_fHAng = m_iDir*_PI2_;
			m_fVAng = 10.0f*_PI_/180.0f;
			m_fRad  = 10.0f;
			m_fH    = 2.0f;

			RadialCamera(m_fDeltaT,m_fH,m_fRad,m_fHAng,m_fVAng);
		}
		break;		
		
		// --------------------------------------------
		// FPS: Cam
		case 7:
		{
			/*
			DMC ProjectQ

			m_oOPos = m_oPos;
			
			MTH_CPoint3 oDir;
			MTH_CPoint3 oSide;
			MTH_CPoint3 oUp;
			MTH_CMat4x4 oMat;
			float fPitch,fYaw,fRoll;
			
			// Compute position
			oMat = gpoPlayer[giCurPlayer]->m_poGI->m_oMat;
			oMat.GetCol0(&oSide);
			oMat.GetCol1(&oUp);
			oMat.GetCol2(&oDir);

			m_oPos = gpoPlayer[giCurPlayer]->m_oPos + (oDir		* (-1.75f)) + (oUp * 2.0f) + (oSide*0.0f);

			// Compute orientation
			oMat.GetEulerAngles(&fPitch,&fYaw,&fRoll);
			fPitch = m_oPitchAvg.fAverager(m_fDeltaT,fPitch, TRANSITION_FACT);
			fYaw   = m_oYawAvg.fAverager  (m_fDeltaT,fYaw  , TRANSITION_FACT);
			fRoll  = m_oRollAvg.fAverager (m_fDeltaT,fRoll , TRANSITION_FACT);

			oMat.SetEulerAngles(fPitch,fYaw,fRoll);
			oMat.GetCol0(&oSide);
			oMat.GetCol1(&oUp);	
			oMat.GetCol2(&oDir);

			m_oTargetPos = m_oPos + oDir;

			m_oCam.LookAt(m_oPos,m_oTargetPos,oUp,DEFAULT_FOV );			


			m_oCam.PrepareDC(gDC);	
			*/
		}
		break;		

		// --------------------------------------------
		// Side cam: For side scroller
		case 8:
		{
			m_oOPos = m_oPos;

			MTH_CPoint3 oDir;
			MTH_CPoint3 oSide;
			MTH_CPoint3 oUp;
			MTH_CMat4x4 oMat;
			float fPitch,fYaw,fRoll;

			oSide.Set(1,0,0);
			oUp.Set  (0,1,0);			
			m_oOPos = m_oPos;
			
			m_oTargetPos	= MTH_CPoint3::oZero();
			m_oPos			= MTH_CPoint3::oZero();
			m_oPos.z		= 10.0f;

			m_oCam.LookAt(m_oPos,m_oTargetPos,oUp,DEFAULT_FOV );
			m_oCam.Ortho(0.0f,STD_SCR_WIDTH,STD_SCR_HEIGHT,0.0f,1.0f,1000.0f);
			// m_oCam.Perspective(45.0f, (float)STD_SCR_WIDTH / (float)STD_SCR_HEIGHT, 1.0f, 2000.0f);
			// m_oCam.Frustum(0,STD_SCR_WIDTH,0,STD_SCR_HEIGHT,1.0f, 2000.0f);
		}
		break;		
		
		
		default:
			// Cargar matrices de camara en display context
			m_oCam.PrepareDC(gDC);
		break;
	}

	// Setup camera matrices
	m_oCam.PrepareDC(gDC);


	// Set world to camera matrix
	#ifdef _XBOX
	MTH_CMat4x4 oCamMat;
	gDC->SetMatrixMode(DC_EMatrixMode_MODELVIEW);
	gDC->GetCurrentMatrix(oCamMat);		
	extern void DC_SetWorld2CameraMatrix(MTH_CMat4x4 &_oW2CMat);
	DC_SetWorld2CameraMatrix( oCamMat );
	#endif
	
	
	CheckNewPos(m_fDeltaT);
}
// -----------------------------------------------------------------------------