//## begin module%3CA0FD1D0254.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0FD1D0254.cm

//## begin module%3CA0FD1D0254.cp preserve=no
//## end module%3CA0FD1D0254.cp

//## Module: CGEMapLoader%3CA0FD1D0254; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMapLoader.cpp

//## begin module%3CA0FD1D0254.additionalIncludes preserve=no
//## end module%3CA0FD1D0254.additionalIncludes

//## begin module%3CA0FD1D0254.includes preserve=yes
#include "GEMapFile.h"
#include "memory/gammae_mem.h"
#include "scene/gammae_scene.h"
//## end module%3CA0FD1D0254.includes

// CGEMapLoader
#include "Game\GameScene\GameMap\GEMap\CGEMapLoader.h"
//## begin module%3CA0FD1D0254.additionalDeclarations preserve=yes
//## end module%3CA0FD1D0254.additionalDeclarations


// Class CGEMapLoader 

CGEMapLoader::CGEMapLoader()
  //## begin CGEMapLoader::CGEMapLoader%.hasinit preserve=no
  //## end CGEMapLoader::CGEMapLoader%.hasinit
  //## begin CGEMapLoader::CGEMapLoader%.initialization preserve=yes
  //## end CGEMapLoader::CGEMapLoader%.initialization
{
  //## begin CGEMapLoader::CGEMapLoader%.body preserve=yes
  //## end CGEMapLoader::CGEMapLoader%.body
}


CGEMapLoader::~CGEMapLoader()
{
  //## begin CGEMapLoader::~CGEMapLoader%.body preserve=yes
  //## end CGEMapLoader::~CGEMapLoader%.body
}



//## Other Operations (implementation)
CGEMap * CGEMapLoader::poLoad (char* _szFilename)
{
  //## begin CGEMapLoader::poLoad%1017327545.body preserve=yes
	CGEMap				*poGEMap;
	CFile				oFile;
	CLoaderGEM			oGEMLoader;
	int					iRoom;
	int					iConn;	
	int					iEnt;	
	unsigned int		uiID;
	unsigned int		uiBlockSize;
	unsigned char		ucMajorVersion;
	unsigned char		ucMinorVersion;
	int					iNumCons;
	CGEMapConnector		oConn;
	int					iNumRooms;
	CGEMapRoom			*poRoom;

	// Open file for writting
	if (! oFile.iOpen(_szFilename,"rb")) return(NULL);

		uiID        = oFile.iRead();
		uiBlockSize = oFile.iRead();

		if (uiID != GEMAPFILE_ID)
		{
			oFile.Close();
			return(NULL);
		}
	
		// Read file id and block size
		ucMajorVersion = oFile.cRead();
		ucMinorVersion = oFile.cRead();

		if ((ucMajorVersion != GEMAPFILE_MINOR_VERSION) &&
		    (ucMinorVersion != GEMAPFILE_MINOR_VERSION))
		{
			oFile.Close();
			return(NULL);
		}
		
		// Create GEMap object
		poGEMap = mNew CGEMap;

		if ( ! ((ucMajorVersion == 1) && (ucMinorVersion == 0)) )
		{
			// Read world entity info
			CMapEntity *poEnt = CGEMapEntityFileIO::poLoadEntity(oFile);
			if (poEnt)
			{
				poGEMap->oWEnt.oAmbColor = ((CMapEnt_World*)poEnt)->oAmbColor;
				strcpy(poGEMap->oWEnt.szWorldFile,((CMapEnt_World*)poEnt)->szWorldFile);
				mDel poEnt;
			}
		}

		// Read spawn rooms info
		poGEMap->iNumSpRooms = oFile.iRead();
		if (poGEMap->iNumSpRooms)
		{
			poGEMap->piSpawnRooms = mNew int[poGEMap->iNumSpRooms];
			oFile.ReadIntArray(poGEMap->piSpawnRooms,poGEMap->iNumSpRooms);
		}
		
		// Read connector info
		poGEMap->aoCons.Clear();		
		iNumCons = oFile.iRead();		

		if (iNumCons)
		{				
			for (iConn=0;iConn<iNumCons;iConn++)
			{				
				oConn.iRoomA = oFile.iRead();
				oConn.iRoomB = oFile.iRead();				
				oFile.ReadFloatArray(oConn.oBBox.Maxs.v,3);
				oFile.ReadFloatArray(oConn.oBBox.Mins.v,3);

				poGEMap->AddConnector(oConn);
			}
		}

		// Read Room info
		poGEMap->aoRooms.Clear();
		iNumRooms = oFile.iRead();

		if (iNumRooms)
		{
			for (iRoom=0;iRoom<iNumRooms;iRoom++)
			{				
				// Create room object
				poRoom = mNew CGEMapRoom;

				// Read geometry
				uiID        = oFile.iRead();
				uiBlockSize = oFile.iRead();
				
				if (uiID != GEM_FILE_IDENTIFIER)
				{
					mDel poRoom;					
					mDel poGEMap;
					oFile.Close();
					return(NULL);
				}

				poRoom->poScn = (CObject3D*)oGEMLoader.pLoad(oFile);

				// Load entities
				poRoom->iNumEnts = oFile.iRead();

				if (poRoom->iNumEnts)
				{
					poRoom->poEnts = mNew CMapEntity *[poRoom->iNumEnts];
					for (iEnt=0;iEnt<poRoom->iNumEnts;iEnt++)
						poRoom->poEnts[iEnt] = CGEMapEntityFileIO::poLoadEntity(oFile);
					
					// This is for runtime data
					poRoom->poRTEnts =mNew CRTME_Target *[poRoom->iNumEnts];
				}

				// Read adjacency info
				poRoom->iNumARooms = oFile.iRead();
				poRoom->iNumCons   = oFile.iRead();
				if (poRoom->iNumARooms)
				{
					poRoom->piARoom = mNew int [poRoom->iNumARooms];
					oFile.ReadIntArray(poRoom->piARoom,poRoom->iNumARooms);
					poRoom->piCons  = mNew int [poRoom->iNumARooms];
					oFile.ReadIntArray(poRoom->piCons,poRoom->iNumARooms);
				}

				poGEMap->aoRooms.iAdd(poRoom);
			}
		}

	return(poGEMap);
  //## end CGEMapLoader::poLoad%1017327545.body
}

// Additional Declarations
  //## begin CGEMapLoader%3CA0FD1D0254.declarations preserve=yes
  //## end CGEMapLoader%3CA0FD1D0254.declarations

//## begin module%3CA0FD1D0254.epilog preserve=yes
//## end module%3CA0FD1D0254.epilog
