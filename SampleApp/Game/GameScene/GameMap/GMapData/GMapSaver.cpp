//## begin module%3C7E06EF02CA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E06EF02CA.cm

//## begin module%3C7E06EF02CA.cp preserve=no
//## end module%3C7E06EF02CA.cp

//## Module: GMapSaver%3C7E06EF02CA; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GMapData\GMapSaver.cpp

//## begin module%3C7E06EF02CA.additionalIncludes preserve=no
//## end module%3C7E06EF02CA.additionalIncludes

//## begin module%3C7E06EF02CA.includes preserve=yes
#include "Scene/GammaE_Scene.h"
#include "GameMap.h"
//## end module%3C7E06EF02CA.includes

// GMapSaver
#include "Game\GameScene\GameMap\GMapData\GMapSaver.h"
//## begin module%3C7E06EF02CA.additionalDeclarations preserve=yes
//## end module%3C7E06EF02CA.additionalDeclarations


// Class GMapSaver 

GMapSaver::GMapSaver()
  //## begin GMapSaver::GMapSaver%.hasinit preserve=no
  //## end GMapSaver::GMapSaver%.hasinit
  //## begin GMapSaver::GMapSaver%.initialization preserve=yes
  //## end GMapSaver::GMapSaver%.initialization
{
  //## begin GMapSaver::GMapSaver%.body preserve=yes
  //## end GMapSaver::GMapSaver%.body
}


GMapSaver::~GMapSaver()
{
  //## begin GMapSaver::~GMapSaver%.body preserve=yes
  //## end GMapSaver::~GMapSaver%.body
}



//## Other Operations (implementation)
bool GMapSaver::bSave (char* _szFilename, GMapData* _poGMap)
{
  //## begin GMapSaver::bSave%1014892584.body preserve=yes
  	CFile oFile;
	if (!oFile.iOpen(_szFilename,"wb")) return(false);
	return (bSave(oFile,_poGMap));
  //## end GMapSaver::bSave%1014892584.body
}

bool GMapSaver::bSave (CFile& _roFile, GMapData* _poGMap)
{
  //## begin GMapSaver::bSave%1014892586.body preserve=yes
	unsigned int ucMajor = GM_MAJORVERSION;
	unsigned int ucMinor = GM_MINORVERSION;
	
	CFileUtils::BeginRIFFBlock(GM_FILEIDENTIFIER,_roFile);
	
	_roFile.iWrite(&ucMajor,1);
	_roFile.iWrite(&ucMinor,1);
	
	// Write entities
	_roFile.iWrite(&_poGMap->iNumEntities,4);
	for (int iEnt=0;iEnt<_poGMap->iNumEntities;iEnt++)
		bSaveEntity(_roFile,_poGMap->poEntity[iEnt]);
				
	// Write geometry
	CSaverGEM	oGEMSaver;
	oGEMSaver.iSave(_roFile,_poGMap->poMap);

	CFileUtils::EndRIFFBlock(_roFile);
	return(true);
  //## end GMapSaver::bSave%1014892586.body
}

bool GMapSaver::bSaveEntity (CFile& _roFile, CMapEntity* _poEntity)
{
  //## begin GMapSaver::bSaveEntity%1014912985.body preserve=yes
	CMapEntityClass eClass = _poEntity->eClass;
	
	// Write entity type
	_roFile.iWrite(&eClass,4);

	switch(eClass)
	{
		case eMapEnt_Sound:		return( bSave_SoundEnt	(_roFile,(CMapEnt_Sound		*)_poEntity) );
		case eMapEnt_Light:		return( bSave_LightEnt	(_roFile,(CMapEnt_Light		*)_poEntity) );
		case eMapEnt_Monster:	return( bSave_MonsterEnt(_roFile,(CMapEnt_Monster	*)_poEntity) );
		case eMapEnt_PowerUp:	return( bSave_PowerUpEnt(_roFile,(CMapEnt_PowerUp	*)_poEntity) );
		case eMapEnt_Item:		return( bSave_ItemEnt	(_roFile,(CMapEnt_Item		*)_poEntity) );
		case eMapEnt_Trigger:	return( bSave_TriggerEnt(_roFile,(CMapEnt_Trigger	*)_poEntity) );
	}

	return(false);
  //## end GMapSaver::bSaveEntity%1014912985.body
}

bool GMapSaver::bSave_SoundEnt (CFile& _roFile, CMapEnt_Sound* _poEnt)
{
  //## begin GMapSaver::bSave_SoundEnt%1014933237.body preserve=yes
	_roFile.iWrite(&_poEnt->iType,4);
	_roFile.iWrite(&_poEnt->oPos ,sizeof(CVect3));

	_roFile.iWrite(&_poEnt->szFileName,16);
	return(true);
  //## end GMapSaver::bSave_SoundEnt%1014933237.body
}

bool GMapSaver::bSave_LightEnt (CFile& _roFile, CMapEnt_Light* _poEnt)
{
  //## begin GMapSaver::bSave_LightEnt%1014933238.body preserve=yes
	_roFile.iWrite(&_poEnt->iType,4);
	_roFile.iWrite(&_poEnt->oPos ,sizeof(CVect3));
	return(true);
  //## end GMapSaver::bSave_LightEnt%1014933238.body
}

bool GMapSaver::bSave_MonsterEnt (CFile& _roFile, CMapEnt_Monster* _poEnt)
{
  //## begin GMapSaver::bSave_MonsterEnt%1014933239.body preserve=yes
	_roFile.iWrite(&_poEnt->iType,4);
	_roFile.iWrite(&_poEnt->oPos ,sizeof(CVect3));
	return(true);
  //## end GMapSaver::bSave_MonsterEnt%1014933239.body
}

bool GMapSaver::bSave_ItemEnt (CFile& _roFile, CMapEnt_Item* _poEnt)
{
  //## begin GMapSaver::bSave_ItemEnt%1014933240.body preserve=yes
	_roFile.iWrite(&_poEnt->iType,4);
	_roFile.iWrite(&_poEnt->oPos ,sizeof(CVect3));
	return(true);
  //## end GMapSaver::bSave_ItemEnt%1014933240.body
}

bool GMapSaver::bSave_PowerUpEnt (CFile& _roFile, CMapEnt_PowerUp* _poEnt)
{
  //## begin GMapSaver::bSave_PowerUpEnt%1014933241.body preserve=yes
	_roFile.iWrite(&_poEnt->iType,4);
	_roFile.iWrite(&_poEnt->oPos ,sizeof(CVect3));
	return(true);
  //## end GMapSaver::bSave_PowerUpEnt%1014933241.body
}

bool GMapSaver::bSave_TriggerEnt (CFile& _roFile, CMapEnt_Trigger* _poEnt)
{
  //## begin GMapSaver::bSave_TriggerEnt%1014933242.body preserve=yes
	/*
	_roFile.iWrite(&_poEnt->iType,4)
	_roFile.iWrite(&_poEnt->oPos ,sizeof(CVect3));
	*/
	return(false);
  //## end GMapSaver::bSave_TriggerEnt%1014933242.body
}

// Additional Declarations
  //## begin GMapSaver%3C7E06EF02CA.declarations preserve=yes
  //## end GMapSaver%3C7E06EF02CA.declarations

//## begin module%3C7E06EF02CA.epilog preserve=yes
//## end module%3C7E06EF02CA.epilog
