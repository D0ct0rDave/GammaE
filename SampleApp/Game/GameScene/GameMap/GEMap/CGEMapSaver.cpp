//## begin module%3CA0FD3800F5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0FD3800F5.cm

//## begin module%3CA0FD3800F5.cp preserve=no
//## end module%3CA0FD3800F5.cp

//## Module: CGEMapSaver%3CA0FD3800F5; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMapSaver.cpp

//## begin module%3CA0FD3800F5.additionalIncludes preserve=no
//## end module%3CA0FD3800F5.additionalIncludes

//## begin module%3CA0FD3800F5.includes preserve=yes
#include "FileSys/GammaE_FileSys.h"
#include "GEMapFile.h"
//## end module%3CA0FD3800F5.includes

// CGEMapSaver
#include "Game\GameScene\GameMap\GEMap\CGEMapSaver.h"
//## begin module%3CA0FD3800F5.additionalDeclarations preserve=yes
//## end module%3CA0FD3800F5.additionalDeclarations


// Class CGEMapSaver 

CGEMapSaver::CGEMapSaver()
  //## begin CGEMapSaver::CGEMapSaver%.hasinit preserve=no
  //## end CGEMapSaver::CGEMapSaver%.hasinit
  //## begin CGEMapSaver::CGEMapSaver%.initialization preserve=yes
  //## end CGEMapSaver::CGEMapSaver%.initialization
{
  //## begin CGEMapSaver::CGEMapSaver%.body preserve=yes
  //## end CGEMapSaver::CGEMapSaver%.body
}


CGEMapSaver::~CGEMapSaver()
{
  //## begin CGEMapSaver::~CGEMapSaver%.body preserve=yes
  //## end CGEMapSaver::~CGEMapSaver%.body
}



//## Other Operations (implementation)
void CGEMapSaver::Save (char* _szFilename, CGEMap *_poGEMap)
{
  //## begin CGEMapSaver::Save%1017327544.body preserve=yes
	CFile			oFile;
	CSaverGEM		oGEMSaver;
	int				iRoom;
	int				iConn;	
	int				iEnt;
	CGEMapRoom		*poRoom;
	

	// Open file for writting
	oFile.iOpen(_szFilename,"wb");
	
	
	CFileUtils::BeginRIFFBlock(GEMAPFILE_ID,oFile);
		
		oFile.Write((char)GEMAPFILE_MAJOR_VERSION);
		oFile.Write((char)GEMAPFILE_MINOR_VERSION);
				
		// Write world entity info
		CGEMapEntityFileIO::SaveEntity(&_poGEMap->oWEnt,oFile);

		// Write spawn rooms info
		oFile.Write(_poGEMap->iNumSpRooms);
		if (_poGEMap->iNumSpRooms)
			oFile.WriteIntArray(_poGEMap->piSpawnRooms,_poGEMap->iNumSpRooms);

		// Write connector info
		oFile.Write((int)_poGEMap->aoCons.iNumElems());
		if (_poGEMap->aoCons.iNumElems())
		{
			for (iConn=0;iConn<_poGEMap->aoCons.iNumElems();iConn++)
			{				
				oFile.Write(_poGEMap->aoCons[iConn].iRoomA);
				oFile.Write(_poGEMap->aoCons[iConn].iRoomB);
				oFile.WriteFloatArray((float*)_poGEMap->aoCons[iConn].oBBox.Maxs.v,3);
				oFile.WriteFloatArray((float*)_poGEMap->aoCons[iConn].oBBox.Mins.v,3);
			}
		}

		// Write Room info
		oFile.Write((int)_poGEMap->aoRooms.iNumElems());
		if (_poGEMap->aoRooms.iNumElems())
		{		
			for (iRoom=0;iRoom<_poGEMap->aoRooms.iNumElems();iRoom++)
			{
				// Get current room
				poRoom = _poGEMap->aoRooms[iRoom];

				// Save geometry
				if (_poGEMap->aoRooms[iRoom]->poScn)
					oGEMSaver.iSave(oFile,poRoom->poScn);
				
				// Save entities
				oFile.Write(poRoom->iNumEnts);
				if (poRoom->iNumEnts)
				{
					for (iEnt=0;iEnt<poRoom->iNumEnts;iEnt++)
						CGEMapEntityFileIO::SaveEntity(poRoom->poEnts[iEnt],oFile);
				}

				// Write adjacency info
				oFile.Write(poRoom->iNumARooms);
				oFile.Write(poRoom->iNumCons);
				
				if (poRoom->iNumARooms)
				{
					oFile.WriteIntArray(poRoom->piARoom,poRoom->iNumARooms);
					oFile.WriteIntArray(poRoom->piCons, poRoom->iNumARooms);
				}
			}
		}

	CFileUtils::EndRIFFBlock(oFile);
  //## end CGEMapSaver::Save%1017327544.body
}

// Additional Declarations
  //## begin CGEMapSaver%3CA0FD3800F5.declarations preserve=yes
  //## end CGEMapSaver%3CA0FD3800F5.declarations

//## begin module%3CA0FD3800F5.epilog preserve=yes
//## end module%3CA0FD3800F5.epilog
