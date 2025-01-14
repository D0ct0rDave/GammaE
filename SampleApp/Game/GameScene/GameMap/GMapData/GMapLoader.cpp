//## begin module%3C7E06E900AF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E06E900AF.cm

//## begin module%3C7E06E900AF.cp preserve=no
//## end module%3C7E06E900AF.cp

//## Module: GMapLoader%3C7E06E900AF; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GMapData\GMapLoader.cpp

//## begin module%3C7E06E900AF.additionalIncludes preserve=no
//## end module%3C7E06E900AF.additionalIncludes

//## begin module%3C7E06E900AF.includes preserve=yes
#include "GameMap.h"
#include "FileSys/GammaE_FileSys.h"
#include "Memory/GammaE_Mem.h"
//## end module%3C7E06E900AF.includes

// GMapLoader
#include "Game\GameScene\GameMap\GMapData\GMapLoader.h"
//## begin module%3C7E06E900AF.additionalDeclarations preserve=yes
//## end module%3C7E06E900AF.additionalDeclarations


// Class GMapLoader 

GMapLoader::GMapLoader()
  //## begin GMapLoader::GMapLoader%.hasinit preserve=no
  //## end GMapLoader::GMapLoader%.hasinit
  //## begin GMapLoader::GMapLoader%.initialization preserve=yes
  //## end GMapLoader::GMapLoader%.initialization
{
  //## begin GMapLoader::GMapLoader%.body preserve=yes
  //## end GMapLoader::GMapLoader%.body
}


GMapLoader::~GMapLoader()
{
  //## begin GMapLoader::~GMapLoader%.body preserve=yes
  //## end GMapLoader::~GMapLoader%.body
}



//## Other Operations (implementation)
GMapData* GMapLoader::poLoad (char* _szFilename)
{
  //## begin GMapLoader::poLoad%1014892585.body preserve=yes
	CFile oFile;
	if (!oFile.iOpen(_szFilename,"rb")) return(NULL);
	
	return (poLoad(oFile));
  //## end GMapLoader::poLoad%1014892585.body
}

GMapData* GMapLoader::poLoad (CFile& _roFile)
{
  //## begin GMapLoader::poLoad%1014892587.body preserve=yes
	unsigned int	uiID;
	unsigned int	iLen;
	unsigned char	ucMajor;
	unsigned char	ucMinor;
	GMapData		*poGMap= mNew GMapData;

	_roFile.iRead(&uiID,4);
	_roFile.iRead(&iLen,4);
	
	if (uiID != GM_FILEIDENTIFIER) return(NULL);

	_roFile.iRead(&ucMajor,1);
	_roFile.iRead(&ucMinor,1);
	
	if (ucMajor > GM_MAJORVERSION) return(NULL);
	if ((ucMajor==GM_MAJORVERSION) && (ucMinor>GM_MINORVERSION)) return(NULL);
	
	// Read entities	
	_roFile.iRead(&poGMap->iNumEntities,4);
	poGMap->poEntity = mNew CMapEntity *[poGMap->iNumEntities];

	for (int iEnt=0;iEnt<poGMap->iNumEntities;iEnt++)
		poGMap->poEntity[iEnt] = poLoadEntity(_roFile);

	// Write geometry
	CLoaderGEM	oGEMLoader;
	poGMap->poMap = (CObject3D_Gen*)oGEMLoader.pLoad(_roFile);
	
	return(poGMap);
  //## end GMapLoader::poLoad%1014892587.body
}

CMapEntity* GMapLoader::poLoadEntity (CFile& _roFile)
{
  //## begin GMapLoader::poLoadEntity%1014912984.body preserve=yes
	CMapEntityClass eClass;
	
	// Write entity type
	_roFile.iRead(&eClass,4);

	switch(eClass)
	{
		case eMapEnt_Sound:		return( poLoad_SoundEnt	 (_roFile));
		case eMapEnt_Light:		return( poLoad_LightEnt	 (_roFile));
		case eMapEnt_Monster:	return( poLoad_MonsterEnt(_roFile));
		case eMapEnt_PowerUp:	return( poLoad_PowerUpEnt(_roFile));
		case eMapEnt_Item:		return( poLoad_ItemEnt	 (_roFile));
		case eMapEnt_Trigger:	return( poLoad_TriggerEnt(_roFile));
	}

	return(NULL);
  //## end GMapLoader::poLoadEntity%1014912984.body
}

CMapEnt_Sound* GMapLoader::poLoad_SoundEnt (CFile& _roFile)
{
  //## begin GMapLoader::poLoad_SoundEnt%1014933243.body preserve=yes
	CMapEnt_Sound *poEnt = mNew CMapEnt_Sound;
	_roFile.iRead(&poEnt->iType,4);
	_roFile.iRead(&poEnt->oPos ,sizeof(CVect3));
	_roFile.iRead(poEnt->oName,16);
	return(poEnt);
  //## end GMapLoader::poLoad_SoundEnt%1014933243.body
}

CMapEnt_Light* GMapLoader::poLoad_LightEnt (CFile& _roFile)
{
  //## begin GMapLoader::poLoad_LightEnt%1014933244.body preserve=yes
	CMapEnt_Light *poEnt = mNew CMapEnt_Light;
	_roFile.iRead(&poEnt->iType,4);
	_roFile.iRead(&poEnt->oPos ,sizeof(CVect3));
	return(poEnt);
  //## end GMapLoader::poLoad_LightEnt%1014933244.body
}

CMapEnt_Monster* GMapLoader::poLoad_MonsterEnt (CFile& _roFile)
{
  //## begin GMapLoader::poLoad_MonsterEnt%1014933245.body preserve=yes
	CMapEnt_Monster*poEnt = mNew CMapEnt_Monster;
	_roFile.iRead(&poEnt->iType,4);
	_roFile.iRead(&poEnt->oPos ,sizeof(CVect3));
	return(poEnt);
  //## end GMapLoader::poLoad_MonsterEnt%1014933245.body
}

CMapEnt_Item* GMapLoader::poLoad_ItemEnt (CFile& _roFile)
{
  //## begin GMapLoader::poLoad_ItemEnt%1014933246.body preserve=yes
	CMapEnt_Item*poEnt = mNew CMapEnt_Item;
	_roFile.iRead(&poEnt->iType,4);
	_roFile.iRead(&poEnt->oPos ,sizeof(CVect3));
	return(poEnt);
  //## end GMapLoader::poLoad_ItemEnt%1014933246.body
}

CMapEnt_PowerUp* GMapLoader::poLoad_PowerUpEnt (CFile& _roFile)
{
  //## begin GMapLoader::poLoad_PowerUpEnt%1014933247.body preserve=yes
	CMapEnt_PowerUp *poEnt = mNew CMapEnt_PowerUp;
	_roFile.iRead(&poEnt->iType,4);
	_roFile.iRead(&poEnt->oPos ,sizeof(CVect3));
	return(poEnt);
  //## end GMapLoader::poLoad_PowerUpEnt%1014933247.body
}

CMapEnt_Trigger* GMapLoader::poLoad_TriggerEnt (CFile& _roFile)
{
  //## begin GMapLoader::poLoad_TriggerEnt%1014933248.body preserve=yes
	return(NULL);
  //## end GMapLoader::poLoad_TriggerEnt%1014933248.body
}

// Additional Declarations
  //## begin GMapLoader%3C7E06E900AF.declarations preserve=yes
  //## end GMapLoader%3C7E06E900AF.declarations

//## begin module%3C7E06E900AF.epilog preserve=yes
//## end module%3C7E06E900AF.epilog
