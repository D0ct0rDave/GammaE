//## begin module%3CDE418D0044.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDE418D0044.cm

//## begin module%3CDE418D0044.cp preserve=no
//## end module%3CDE418D0044.cp

//## Module: CRTME_Platform%3CDE418D0044; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\RTMapEntities\CRTME_Platform.cpp

//## begin module%3CDE418D0044.additionalIncludes preserve=no
//## end module%3CDE418D0044.additionalIncludes

//## begin module%3CDE418D0044.includes preserve=yes
//## end module%3CDE418D0044.includes

// CRTME_Platform
#include "Game\Entities\RTMapEntities\CRTME_Platform.h"
//## begin module%3CDE418D0044.additionalDeclarations preserve=yes
#define PLATST_ACC_FWD		1
#define PLATST_CTESPD_FWD	2
#define PLATST_DEC_FWD		3
#define PLATST_ACC_BCK		4
#define PLATST_CTESPD_BCK	5
#define PLATST_DEC_BCK		6
#define PLATST_STOP			7

#define	MAX_DRAGGED_ENTITIES 5
//## end module%3CDE418D0044.additionalDeclarations


// Class CRTME_Platform 















CRTME_Platform::CRTME_Platform()
  //## begin CRTME_Platform::CRTME_Platform%.hasinit preserve=no
      : poGrObj(NULL), fFact(0.0f), poPlatInfo(NULL), fCurSpd(0.0f), fCurAcc(0.0f), iState(0), fCurFact(0.0f), poColObj(NULL), bChDir(false)
  //## end CRTME_Platform::CRTME_Platform%.hasinit
  //## begin CRTME_Platform::CRTME_Platform%.initialization preserve=yes
  //## end CRTME_Platform::CRTME_Platform%.initialization
{
  //## begin CRTME_Platform::CRTME_Platform%.body preserve=yes
  //## end CRTME_Platform::CRTME_Platform%.body
}


CRTME_Platform::~CRTME_Platform()
{
  //## begin CRTME_Platform::~CRTME_Platform%.body preserve=yes
  //## end CRTME_Platform::~CRTME_Platform%.body
}



//## Other Operations (implementation)
void CRTME_Platform::Init (CMapEnt_Platform* _poPlatInfo)
{
  //## begin CRTME_Platform::Init%1021237870.body preserve=yes
	poGrObj = mNew CObject3D_Transf;

	poTargetInfo = _poPlatInfo;
	poPlatInfo   = _poPlatInfo;
	poGrObj->SetObject(_poPlatInfo->poScn);
	poGrObj->ComputeBoundVol();	

	oSpdDir.Assign(poPlatInfo->oDstPos);
	oSpdDir.Sub   (poPlatInfo->oSrcPos);
	oSpdDir.Normalize();

	oCurPos.Assign(poPlatInfo->oSrcPos);	
	
	//
	float fSpeed = poPlatInfo->fSpeed*0.25f;
	// float fSpeed = poPlatInfo->fSpeed*0.025f;
	fAccel =  fSpeed*fSpeed / 2*(poPlatInfo->fEndAc/100.0f);
	fDecel = -fSpeed*fSpeed / 2*(1.0f - (poPlatInfo->fStartDec/100.0f));
	
	// DEBUG_CODE
	// fAccel = 0.0f;
	// fDecel = 0.0f;
	//

	iState   = PLATST_ACC_FWD;
	fCurAcc  = fAccel;
	fCurFact = 0.0f;

	aoDragged.Init(MAX_DRAGGED_ENTITIES);
  //## end CRTME_Platform::Init%1021237870.body
}

int CRTME_Platform::iDragEntity (CGPhysicEntity* _poEnt)
{
  //## begin CRTME_Platform::iDragEntity%1021565344.body preserve=yes
	
	// Add the entity
	return(aoDragged.iAdd(_poEnt));

  //## end CRTME_Platform::iDragEntity%1021565344.body
}

void CRTME_Platform::Think (float _fDelta)
{
  //## begin CRTME_Platform::Think%1021199184.body preserve=yes
	if (! bTriggered()) return;	
	
	// Get "recorrido" factor percentage	
	float fRecFact = 100.0f * fCurFact / poPlatInfo->oSrcPos.Distance(poPlatInfo->oDstPos);

	// -------------
	// State Machine
	// -------------
	switch (iState)
	{
		case PLATST_ACC_FWD:
		{
			if (fRecFact > poPlatInfo->fEndAc)
			{
				iState = PLATST_CTESPD_FWD;
				fCurAcc= 0.0f;
			}
		}
		break;

		case PLATST_CTESPD_FWD:
		{
			if (fRecFact > poPlatInfo->fStartDec)
			{
				iState  = PLATST_DEC_FWD;
				fCurAcc = fDecel;
			}
		}
		break;

		case PLATST_DEC_FWD:
		{			
			if (bChDir) // Cambio de sentido
			{
 				fRecFact = 100.0f;
				if (poPlatInfo->eTriggerMode == eMapEnt_TM_Once)
				{
					iState = PLATST_STOP;
				}
				else
				{
					// Change direction
					iState = PLATST_ACC_BCK;
					fCurAcc= fDecel;
				}
			}
		}
		break;

		case PLATST_ACC_BCK:
		{
			if (fRecFact < poPlatInfo->fStartDec)
			{
				iState = PLATST_CTESPD_BCK;
				fCurAcc= 0.0f;
			}
		}
		break;

		case PLATST_CTESPD_BCK:
		{
			if (fRecFact < poPlatInfo->fEndAc)
			{
				iState = PLATST_DEC_BCK;
				fCurAcc= fAccel;
			}
		}
		break;

		case PLATST_DEC_BCK:
		{
			if (bChDir) // Cambio de sentido
			{
				// Change direction
				/*
				if (poPlatInfo->eTriggerMode == eMapEnt_TM_Multiple)
				{
					iState  = PLATST_STOP;
					fCurAcc = 0.0f;
				}
				else
				*/
				{
					iState = PLATST_ACC_FWD;
					fCurAcc= fAccel;
				}
			}
		}
		break;

		case PLATST_STOP:
		{
		}
		break;
	}
  //## end CRTME_Platform::Think%1021199184.body
}

void CRTME_Platform::ProcessCmds (float _fDelta)
{
  //## begin CRTME_Platform::ProcessCmds%1021565349.body preserve=yes
	if (_fDelta==0.0f) return;

	float fOldSpd = fCurSpd;
	fCurSpd = fCurSpd + fCurAcc*_fDelta;
	bChDir  = (fCurSpd*fOldSpd < 0.0f);

	// Compute position
	fCurFact += fCurSpd*_fDelta;
	oCurPos.LineEq(oCurPos,oSpdDir,fCurSpd*_fDelta);

	// Setup platform position
	poColObj->OldPos.Assign(poColObj->Pos);
	poColObj->Pos.Assign   (oCurPos);
	poColObj->Speed.Assign (poColObj->Pos);
	poColObj->Speed.Sub    (poColObj->OldPos);

	CVect3 oSpeed;
	oSpeed.Assign(poColObj->Speed);
	oSpeed.Scale (1.0f/_fDelta);

	// Add forces to dragged entities
	int iEnt;
	for (iEnt=0;iEnt<aoDragged.iNumElems();iEnt++)
		aoDragged[iEnt]->AddForce(oSpeed);
	
	// Once done, clear the array
	aoDragged.Clear();
  //## end CRTME_Platform::ProcessCmds%1021565349.body
}

void CRTME_Platform::Interact (float _fDelta)
{
  //## begin CRTME_Platform::Interact%1021578576.body preserve=yes

	// Set object position
	poGrObj->SetPos(oCurPos);

  //## end CRTME_Platform::Interact%1021578576.body
}

// Additional Declarations
  //## begin CRTME_Platform%3CDE418D0044.declarations preserve=yes
  //## end CRTME_Platform%3CDE418D0044.declarations

//## begin module%3CDE418D0044.epilog preserve=yes
//## end module%3CDE418D0044.epilog
