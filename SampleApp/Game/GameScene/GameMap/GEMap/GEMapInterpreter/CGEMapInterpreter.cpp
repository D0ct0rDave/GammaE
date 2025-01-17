//## begin module%3CAA12EF010B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CAA12EF010B.cm

//## begin module%3CAA12EF010B.cp preserve=no
//## end module%3CAA12EF010B.cp

//## Module: CGEMapInterpreter%3CAA12EF010B; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\GEMapInterpreter\CGEMapInterpreter.cpp

//## begin module%3CAA12EF010B.additionalIncludes preserve=no
//## end module%3CAA12EF010B.additionalIncludes

//## begin module%3CAA12EF010B.includes preserve=yes
#include "game/globals/globals.h"
#include "memory/gammae_mem.h"
#include "sceneobjects/gammae_scnobj.h"
#include "scene/gammae_scene.h"
//## end module%3CAA12EF010B.includes

// CGEMapInterpreter
#include "Game\GameScene\GameMap\GEMap\GEMapInterpreter\CGEMapInterpreter.h"
// CMapEntities
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntities.h"
//## begin module%3CAA12EF010B.additionalDeclarations preserve=yes
CRTME_Target *poCreateLight(CMapEnt_Light *_poLight)
{
	// ------------------------------------------------
	// Particle object
	// ------------------------------------------------	
//	PS = mNew CParticleSystem_Sparks();		
	CParticleSystem_Coolant	*PS = mNew CParticleSystem_Coolant();
	
	TFColor oFactColor;
	oFactColor.r = oFactColor.g = oFactColor.b = 0.0025f;
	oFactColor.a = 1.0f;

	// Create and setup particle system
	PS->InitPS			(32,true,false);
	PS->SetPSParams		(true,1.0f,0.05f);
	PS->PSSpeed.V3		(0,0,25.0f);	
	PS->SetColorsFact	(_poLight->Color,oFactColor);
	PS->SetSizeFact		(4.0f);
	PS->SetSpeedFact	(12.0f);
	PS->SetEnergyFact	(0.25f,0.01f);

	CE3D_Shader *poParticleShader = CE3D_ShaderWH::poCreateShader("LightPS");
	PS->SetShader(poParticleShader);

	// Move the particle system in the map
	CObject3D_Transf	*poNode;
	poNode = mNew CObject3D_Transf;
	poNode->SetObject(PS);
	poNode->SetPos(_poLight->oPos);	

	// To enable or disable
	CObject3D_Mux	*poSwitch = mNew CObject3D_Mux;
	poSwitch->Init(1);
	poSwitch->iAddObject(poNode);	
	poSwitch->ComputeBoundVol();

	// To handle enablement
	CRTME_Light *poLightEnt = mNew CRTME_Light;
	poLightEnt->poSwitch   = poSwitch;	
	poLightEnt->Init(_poLight);
	return(poLightEnt);
}

CRTME_Target *poCreateTrigger(CMapEnt_Trigger *_poTrigger)
{
	// To handle enablement
	CRTME_Trigger *poTriggerEnt = mNew CRTME_Trigger;	
	poTriggerEnt->Init(_poTrigger);
	return(poTriggerEnt);
}

CRTME_Target *poCreatePlatform(CMapEnt_Platform *_poPlatform)
{
	// To handle enablement
	CRTME_Platform *poPlatformEnt = mNew CRTME_Platform;
	poPlatformEnt->Init(_poPlatform);
	return(poPlatformEnt);
}

//## end module%3CAA12EF010B.additionalDeclarations


// Class CGEMapInterpreter 

CGEMapInterpreter::CGEMapInterpreter()
  //## begin CGEMapInterpreter::CGEMapInterpreter%.hasinit preserve=no
  //## end CGEMapInterpreter::CGEMapInterpreter%.hasinit
  //## begin CGEMapInterpreter::CGEMapInterpreter%.initialization preserve=yes
  //## end CGEMapInterpreter::CGEMapInterpreter%.initialization
{
  //## begin CGEMapInterpreter::CGEMapInterpreter%.body preserve=yes
  //## end CGEMapInterpreter::CGEMapInterpreter%.body
}


CGEMapInterpreter::~CGEMapInterpreter()
{
  //## begin CGEMapInterpreter::~CGEMapInterpreter%.body preserve=yes
  //## end CGEMapInterpreter::~CGEMapInterpreter%.body
}



//## Other Operations (implementation)
void CGEMapInterpreter::Interpret (CGEMap& _roMap)
{
  //## begin CGEMapInterpreter::Interpret%1017778984.body preserve=yes
	int					iRoom;	
	int					iEnt;	
	CGEMapRoom			*poRoom;
	CMapEntity			*poEnt;	

	for (iRoom=0;iRoom<_roMap.aoRooms.iNumElems();iRoom++)
	{
		poRoom              = _roMap.aoRooms[iRoom];		
		poRoom->poAdjScn    = mNew CObject3D_Node;
		poRoom->poAdjScnCol = mNew CObject3D_Node;

		for (iEnt=0;iEnt<poRoom->iNumEnts;iEnt++)
		{
			// Initialize this entity data 
			poRoom->poRTEnts[iEnt] = NULL;
			
			poEnt   = poRoom->poEnts[iEnt];			
			switch (poEnt->eClass)
			{
				case eMapEnt_Sound:
				{
				}
				break;
				
				case eMapEnt_Light:
				{
					CRTME_Light *poRTMELight= (CRTME_Light *)poCreateLight((CMapEnt_Light*)poEnt);
					poRoom->poRTEnts[iEnt]	= poRTMELight;
					// poRoom->poAdjScn->iAddObject(poRTMELight->poSwitch);
				}
				break;
				
				case eMapEnt_PlayerStart:
				{
					// gCamera.poCam->Pos.Assign(((CMapEnt_PlayerStart*)poEnt)->oPos);
					gPlayer->roColObj().Pos.Assign( ((CMapEnt_PlayerStart*)poEnt)->oPos );
				}
				break;

				case eMapEnt_Trigger:
				{
					CRTME_Trigger *poTrigger = (CRTME_Trigger *)poCreateTrigger((CMapEnt_Trigger*)poEnt);					
					poRoom->poRTEnts[iEnt] = poTrigger;
				}
				break;

				case eMapEnt_Platform:
				{
					CRTME_Platform *poRTMEPlate = (CRTME_Platform *)poCreatePlatform((CMapEnt_Platform*)poEnt);
					poRoom->poRTEnts[iEnt]		= poRTMEPlate;
					poRoom->poAdjScnCol->iAddObject( poRTMEPlate->poGrObj );
				}
				break;
				
			}

			poEnt++;		
		}	

		poRoom->poAdjScn->ComputeBoundVol();
		poRoom->poAdjScnCol->ComputeBoundVol();

	}	

	LinkTriggeredTargets(_roMap);
  //## end CGEMapInterpreter::Interpret%1017778984.body
}

void CGEMapInterpreter::LinkTriggeredTargets (CGEMap& _roMap)
{
  //## begin CGEMapInterpreter::LinkTriggeredTargets%1021237868.body preserve=yes
	int					iSrcRoom;	
	CGEMapRoom			*poSrcRoom;	
	int					iSrcEnt;
	CRTME_Target		*poSrcTarget;
	CRTME_Trigger		*poTrigger;

	for (iSrcRoom=0;iSrcRoom<_roMap.aoRooms.iNumElems();iSrcRoom++)
	{
		poSrcRoom   = _roMap.aoRooms[iSrcRoom];
		for (iSrcEnt=0;iSrcEnt<poSrcRoom->iNumEnts;iSrcEnt++)
		{
			poSrcTarget = (CRTME_Target*)poSrcRoom->poRTEnts[iSrcEnt];
			if (poSrcTarget)
			{
				if ( poSrcTarget->poTargetInfo )
				{
					if (poSrcTarget->poTargetInfo->eClass == eMapEnt_Trigger)
					{
						poTrigger = (CRTME_Trigger*)poSrcTarget;
						poTrigger->Target    = poFindTarget( poTrigger->poTrigInfo->szTargetName,_roMap);
						poTrigger->SecTarget = poFindTarget( poTrigger->poTrigInfo->szSecTarget, _roMap);
					}
				}
			}
		}
	}
  //## end CGEMapInterpreter::LinkTriggeredTargets%1021237868.body
}

CRTME_Target* CGEMapInterpreter::poFindTarget (char* _szTargetName, CGEMap& _roMap)
{
  //## begin CGEMapInterpreter::poFindTarget%1021237869.body preserve=yes

	int					iDstRoom;	
	CGEMapRoom			*poDstRoom;	
	CRTME_Target		*poTarget;
	int					iDstEnt;

	for (iDstRoom=0;iDstRoom<_roMap.aoRooms.iNumElems();iDstRoom++)
	{
		poDstRoom   = _roMap.aoRooms[iDstRoom];
		for (iDstEnt=0;iDstEnt<poDstRoom->iNumEnts;iDstEnt++)
		{
			poTarget = (CRTME_Target*)poDstRoom->poRTEnts[iDstEnt];
			if (poTarget)
			{
				if (poTarget->poTargetInfo)
				{
					if (! strcmp(_szTargetName,poTarget->poTargetInfo->szName))
					{
						return(poTarget);
					}
				}
			}
			
		}
	}

	return(NULL);
  //## end CGEMapInterpreter::poFindTarget%1021237869.body
}

// Additional Declarations
  //## begin CGEMapInterpreter%3CAA12EF010B.declarations preserve=yes
  //## end CGEMapInterpreter%3CAA12EF010B.declarations

//## begin module%3CAA12EF010B.epilog preserve=yes
//## end module%3CAA12EF010B.epilog
