//## begin module%3CA0F7040368.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F7040368.cm

//## begin module%3CA0F7040368.cp preserve=no
//## end module%3CA0F7040368.cp

//## Module: CGEMap%3CA0F7040368; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMap.cpp

//## begin module%3CA0F7040368.additionalIncludes preserve=no
//## end module%3CA0F7040368.additionalIncludes

//## begin module%3CA0F7040368.includes preserve=yes
//## end module%3CA0F7040368.includes

// CGEMap
#include "Game\GameScene\GameMap\GEMap\CGEMap.h"
//## begin module%3CA0F7040368.additionalDeclarations preserve=yes
#include "game/globals/globals.h"
//## end module%3CA0F7040368.additionalDeclarations


// Class CGEMap 








CGEMap::CGEMap()
  //## begin CGEMap::CGEMap%.hasinit preserve=no
      : piSpawnRooms(NULL), iNumSpRooms(0), iCurrentRoom(0), iMaxDepth(-1)
  //## end CGEMap::CGEMap%.hasinit
  //## begin CGEMap::CGEMap%.initialization preserve=yes
  //## end CGEMap::CGEMap%.initialization
{
  //## begin CGEMap::CGEMap%.body preserve=yes
  //## end CGEMap::CGEMap%.body
}


CGEMap::~CGEMap()
{
  //## begin CGEMap::~CGEMap%.body preserve=yes
  //## end CGEMap::~CGEMap%.body
}



//## Other Operations (implementation)
CGraphBV* CGEMap::poGetBoundVol ()
{
  //## begin CGEMap::poGetBoundVol%1017778985.body preserve=yes
	return (NULL);
  //## end CGEMap::poGetBoundVol%1017778985.body
}

void CGEMap::ComputeBoundVol ()
{
  //## begin CGEMap::ComputeBoundVol%1017778986.body preserve=yes
  //## end CGEMap::ComputeBoundVol%1017778986.body
}

void CGEMap::Render ()
{
  //## begin CGEMap::Render%1017327548.body preserve=yes
	if (iCurrentRoom == -1) return;
	
	Reset();
	RenderRec (iCurrentRoom,0);
  //## end CGEMap::Render%1017327548.body
}

void CGEMap::RenderRec (int _iRoom, int _iDepth)
{
  //## begin CGEMap::RenderRec%1017327552.body preserve=yes
	if ((_iDepth>=iMaxDepth) && (iMaxDepth>-1)) return;
	
	CGEMapRoom *poRoom = aoRooms[_iRoom];

	// Render this room
	poRoom->poScn      ->Render();
	poRoom->poAdjScn   ->Render();
	poRoom->poAdjScnCol->Render();
	poRoom->bVisited = true;

	// Traverse the adjacent room list
	int iARoomElem;
	int	iARoom;

	for (iARoomElem=0;iARoomElem<poRoom->iNumARooms;iARoomElem++)
	{
		iARoom = poRoom->piARoom[iARoomElem];

		if (! aoRooms[iARoom]->bVisited)
			RenderRec(iARoom,_iDepth+1);
	}
  //## end CGEMap::RenderRec%1017327552.body
}

void CGEMap::AddConnector (CGEMapConnector &_roCon)
{
  //## begin CGEMap::AddConnector%1017327546.body preserve=yes
	aoCons.iAdd(_roCon);
  //## end CGEMap::AddConnector%1017327546.body
}

void CGEMap::AddRoom (CGEMapRoom &_roRoom)
{
  //## begin CGEMap::AddRoom%1017327547.body preserve=yes
	aoRooms.iAdd(&_roRoom);
  //## end CGEMap::AddRoom%1017327547.body
}

void CGEMap::Reset ()
{
  //## begin CGEMap::Reset%1017327551.body preserve=yes
	int iRoom;
	for (iRoom=0;iRoom<aoRooms.iNumElems();iRoom++)
		aoRooms[iRoom]->bVisited = false;
  //## end CGEMap::Reset%1017327551.body
}

void CGEMap::Think ()
{
  //## begin CGEMap::Think%1017327549.body preserve=yes
  //## end CGEMap::Think%1017327549.body
}

int CGEMap::iGetRoomFromPos (CVect3 &_roPos)
{
  //## begin CGEMap::iGetRoomFromPos%1018385443.body preserve=yes
 	
	int iRoom;
	int	iARoom;

	// Search in the current room
	if ( aoRooms[iCurrentRoom]->poScn->poGetBoundVol()->TestInside(_roPos) )
			return(iCurrentRoom);

	// Search in the adjacent room list
	for (iRoom=0;iRoom<aoRooms[iCurrentRoom]->iNumARooms;iRoom++)
	{		
		iARoom = aoRooms[iCurrentRoom]->piARoom[iRoom];

		if ( aoRooms[iARoom]->poScn->poGetBoundVol()->TestInside(_roPos) )
			return(iARoom);
	}

	// Test all the rooms in the list
	for (iRoom=0;iRoom<aoRooms.iNumElems();iRoom++)
	{
		if ( aoRooms[iRoom]->poScn->poGetBoundVol()->TestInside(_roPos) )
			return(iRoom);
	}

	return(-1);
  //## end CGEMap::iGetRoomFromPos%1018385443.body
}

// Additional Declarations
  //## begin CGEMap%3CA0F7040368.declarations preserve=yes
  //## end CGEMap%3CA0F7040368.declarations

//## begin module%3CA0F7040368.epilog preserve=yes
//## end module%3CA0F7040368.epilog
