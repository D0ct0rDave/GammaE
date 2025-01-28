//-----------------------------------------------------------------------------
#include "GammaE.h"
#include "CGameFlow.h"
#include "App/Loop/Game/CGameGlobals.h"
#include "App/Loop/Game/Entities/CPlayer.h"
#include "App/Loop/Game/Entities/CGameCamera.h"
#include "App/Loop/Game/Entities/Lavadora/CLavadora.h"
#include "App/Loop/Game/Entities/Enemies/CEnemyGroup.h"
#include "App/Loop/Game/Entities/Enemies/CEnemyGroupExt.h"
//-----------------------------------------------------------------------------
void* CGGameFlow_CreateEntity(const CGString& _sParameters)
{
	CGDynArray<CGString> oParams;
	if (ParseUtils_ParseParameters(_sParameters,&oParams,',') == 0) return(NULL);

	// Create the entity type
	if ( oParams[0] |= "Player")
	{
		CPlayer*poPlayer = mNew CPlayer;
		poPlayer->Init(CVect3::oZero(),0);
		return(poPlayer);
	}
	// Create the entity type
else if ( oParams[0] |= "Camera")
	{
		CGameCamera* poCamera = mNew CGameCamera;
		poCamera->Init();
		return(poCamera);
	}
	// Create the entity type
else if ( oParams[0] |= "Lavadora")
	{
  		CLavadora* poLavadora = mNew CLavadora;
		poLavadora->Init();
		return(poLavadora);
	}
else if (oParams[0] |= "Enemy")
	{
		if (oParams.uiNumElems() < 9) return(NULL);

		float fEnergy = atof(oParams[1].szString());

		float fX  = atof(oParams[2].szString());
		float fY  = atof(oParams[3].szString());
		float fZ  = atof(oParams[4].szString());

		CVect3 oPos(fX,fY,fZ);

		if (oParams[5] == "NULL") oParams[5] = "";
		if (oParams[6] == "NULL") oParams[6] = "";
		if (oParams[7] == "NULL") oParams[7] = "";
		
		float fScale = atof(oParams[8].szString());

		CEnemy* poEnemy = mNew CEnemy;
		poEnemy->Init(fEnergy,oPos,oParams[5],oParams[6],oParams[7],fScale);

		return(poEnemy);
	}

	return(NULL);
}
//-----------------------------------------------------------------------------
void* CGGameFlow_CreateGroup(const CGString& _sParameters)
{
	CGDynArray<CGString> oParams;
	if (ParseUtils_ParseParameters(_sParameters,&oParams,',') == 0) return(NULL);

	if (oParams.uiNumElems() < 9) return(NULL);

	uint uiNumEnemies = atoi(oParams[0].szString());
	float fSpawnTime  = atof(oParams[1].szString());
	float fEnergy     = atof(oParams[2].szString());

	float fX  = atof(oParams[3].szString());
	float fY  = atof(oParams[4].szString());
	float fZ  = atof(oParams[5].szString());

	CVect3 oPos(fX,fY,fZ);

	if (oParams[6] == "NULL") oParams[6] = "";
	if (oParams[7] == "NULL") oParams[7] = "";
	if (oParams[8] == "NULL") oParams[8] = "";

	CEnemyGroup* poEG = mNew CEnemyGroup;
	poEG->Init(uiNumEnemies,fSpawnTime,fEnergy,oPos,oParams[6],oParams[7],oParams[8]);

	return(poEG);
}
//-----------------------------------------------------------------------------
void* CGGameFlow_CreateGroupExt(const CGString& _sParameters)
{
	CGDynArray<CGString> oParams;
	if (ParseUtils_ParseParameters(_sParameters,&oParams,',') == 0) return(NULL);

	if (oParams.uiNumElems() < 9) return(NULL);

	uint uiNumEnemies = atoi(oParams[0].szString());
	float fSpawnTime  = atof(oParams[1].szString());
	float fEnergy     = atof(oParams[2].szString());

	float fX  = atof(oParams[3].szString());
	float fY  = atof(oParams[4].szString());
	float fZ  = atof(oParams[5].szString());

	CVect3 oPos(fX,fY,fZ);

	if (oParams[6] == "NULL") oParams[6] = "";
	if (oParams[7] == "NULL") oParams[7] = "";
	if (oParams[8] == "NULL") oParams[8] = "";
	
	float fScaleRange  = 0.0f;
	if (oParams.uiNumElems() > 9) 
		fScaleRange = atof(oParams[9].szString());
	
	uint uiIniColor = 0xffffffff;
	if (oParams.uiNumElems() > 10) 
		sscanf(oParams[10].szString(),"%x",&uiIniColor);

	uint uiEndColor = 0xffffffff;
	if (oParams.uiNumElems() > 11) 
		sscanf(oParams[11].szString(),"%x",&uiEndColor);

	CEnemyGroupExt* poEG = mNew CEnemyGroupExt;
	poEG->Init(uiNumEnemies,fSpawnTime,fEnergy,oPos,oParams[6],oParams[7],oParams[8],fScaleRange,uiIniColor,uiEndColor);

	return(poEG);
}
//-----------------------------------------------------------------------------
void CGameFlow::Init()
{
	// Register gameflow extension functions
	CGScriptingSystem::I()->RegisterExtension("CreateEntity",CGGameFlow_CreateEntity,"sifsss","");
	CGScriptingSystem::I()->RegisterExtension("CreateGroup",CGGameFlow_CreateGroup,"sifsss","");
	CGScriptingSystem::I()->RegisterExtension("CreateGroupExt",CGGameFlow_CreateGroupExt,"sifsssfii","");

	// Set logger component
	Logger( mNew CGLogger() );

	// Set the logic for this entity
	CGGameEntityMgr::I()->uiRegister(this);
	Logic( mNew CGScriptInstance( SCRIPT_PATH + "/" + sClass()+".lua" ) );

	// 
	m_poEntities.Init(100);
}
//-----------------------------------------------------------------------------
void CGameFlow::Reinit()
{
	bool bStartRemoving = false;

	for (uint i=0;i<CGGameEntityMgr::I()->uiNumEntities();)
	{
		CGGameEntity* poEnt = CGGameEntityMgr::I()->poGetEntity(i);

		if (! bStartRemoving)
		{
			bStartRemoving = (poEnt == this);
			i++;
		}
		else
			CGGameEntityMgr::I()->Remove(poEnt);
	}

	SwitchToState(ENTSTATE_INIT);
}
//-----------------------------------------------------------------------------