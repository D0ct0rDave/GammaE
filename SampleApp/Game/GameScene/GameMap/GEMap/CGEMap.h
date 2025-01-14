//## begin module%3CA0F7040368.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F7040368.cm

//## begin module%3CA0F7040368.cp preserve=no
//## end module%3CA0F7040368.cp

//## Module: CGEMap%3CA0F7040368; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMap.h

#ifndef CGEMap_h
#define CGEMap_h 1

//## begin module%3CA0F7040368.additionalIncludes preserve=no
//## end module%3CA0F7040368.additionalIncludes

//## begin module%3CA0F7040368.includes preserve=yes
#include <vector>
using namespace std;
//## end module%3CA0F7040368.includes

// CGEMapRoom
#include "Game\GameScene\GameMap\GEMap\CGEMapRoom.h"
// CGEMapConnector
#include "Game\GameScene\GameMap\GEMap\CGEMapConnector.h"
// CMapEnt_World
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_World.h"
// CObject3D
#include "Scene\CObject3D.h"
// GammaE_Misc
#include "Misc\GammaE_Misc.h"
//## begin module%3CA0F7040368.additionalDeclarations preserve=yes
//## end module%3CA0F7040368.additionalDeclarations


//## begin CGEMap%3CA0F7040368.preface preserve=yes
//## end CGEMap%3CA0F7040368.preface

//## Class: CGEMap%3CA0F7040368
//	Render: 1 vez por frame / Viewport.
//	Think: 1 vez por frame, podría gestionar, entidades de
//	la habitación o algo así.
//	SetCurrentRoom: La pueden llamar cada vez que se desee
//	gestionar 1 player.
//
//	Podríamos la gestión total del sistema a nivel de
//	habitación. Es decir, solo renderizar lo que hay en la
//	habitación, sólo gestión del sonido de la habitación.
//	Gestión de las entidades de la habitación, etc...
//	La otra alternativa consiste en utilizar las clases de
//	propósito general e introducir las entidades de manera
//	que la gestión se haga automáticamente. Meter entidades
//	en el sistema de gestión de  entidades, meter objetos
//	físicos en el sistema de colisiones, sonido en el
//	sistema de sonido, etc, y dejar que todo evolucione.
//
//	Parece una buena alternativa la gestión a nivel de
//	habitación. Se puede probar a utilizar los subsistemas
//	actuales pero restringidos al contenido de las
//	habitaciones accesibles.
//	- A cada frame introducir datos en cada subsistema y
//	hacerlos funcionar.
//	- Cada vez que se cambie de habitación, rellenar los
//	subsistemas con info de nuevas habitaciones
//## Category: Game::GameScene::GameMap::GEMap%3CA0FEC20001
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: >%3CB4A5C001C6;GammaE_Misc { -> }
//## Uses: <unnamed>%3CB4A5C602F1;GammaE_Misc { -> }

class CGEMap : public CObject3D  //## Inherits: <unnamed>%3CAA14AC035A
{
  //## begin CGEMap%3CA0F7040368.initialDeclarations preserve=yes
  //## end CGEMap%3CA0F7040368.initialDeclarations

  public:
    //## Constructors (generated)
      CGEMap();

    //## Destructor (generated)
      ~CGEMap();


    //## Other Operations (specified)
      //## Operation: poGetBoundVol%1017778985
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: ComputeBoundVol%1017778986
      virtual void ComputeBoundVol ();

      //## Operation: Render%1017327548
      virtual void Render ();

      //## Operation: AddConnector%1017327546
      void AddConnector (CGEMapConnector &_roCon);

      //## Operation: AddRoom%1017327547
      void AddRoom (CGEMapRoom &_roRoom);

      //## Operation: Think%1017327549
      //	Render : 1 vez por frame
      void Think ();

      //## Operation: iGetRoomFromPos%1018385443
      int iGetRoomFromPos (CVect3 &_roPos);

    // Data Members for Class Attributes

      //## Attribute: piSpawnRooms%3CA0F7160093
      //## begin CGEMap::piSpawnRooms%3CA0F7160093.attr preserve=no  public: int * {UA} NULL
      int *piSpawnRooms;
      //## end CGEMap::piSpawnRooms%3CA0F7160093.attr

      //## Attribute: iNumSpRooms%3CA0F7300325
      //## begin CGEMap::iNumSpRooms%3CA0F7300325.attr preserve=no  public: int {UA} 0
      int iNumSpRooms;
      //## end CGEMap::iNumSpRooms%3CA0F7300325.attr

      //## Attribute: iCurrentRoom%3CA10162035A
      //## begin CGEMap::iCurrentRoom%3CA10162035A.attr preserve=no  public: int {UA} 0
      int iCurrentRoom;
      //## end CGEMap::iCurrentRoom%3CA10162035A.attr

      //## Attribute: iMaxDepth%3CA4340301D6
      //## begin CGEMap::iMaxDepth%3CA4340301D6.attr preserve=no  public: int {UA} -1
      int iMaxDepth;
      //## end CGEMap::iMaxDepth%3CA4340301D6.attr

    // Data Members for Associations

      //## Association: Tools::GEMapCompiler::<unnamed>%3CA0F7930101
      //## Role: CGEMap::aoCons%3CA0F7930260
      //## begin CGEMap::aoCons%3CA0F7930260.role preserve=no  public: CGEMapConnector { -> RHAN}
      CDynArray <CGEMapConnector> aoCons;
      //## end CGEMap::aoCons%3CA0F7930260.role

      //## Association: Tools::GEMapCompiler::<unnamed>%3CA0F81703E6
      //## Role: CGEMap::aoRooms%3CA0F81800DB
      //## begin CGEMap::aoRooms%3CA0F81800DB.role preserve=no  public: CGEMapRoom { -> RHAN}
      CDynArray <CGEMapRoom*> aoRooms;
      //## end CGEMap::aoRooms%3CA0F81800DB.role

      //## Association: Game::GameScene::GameMap::GEMap::<unnamed>%3CF9D4DF012A
      //## Role: CGEMap::oWEnt%3CF9D4E000DC
      //## begin CGEMap::oWEnt%3CF9D4E000DC.role preserve=no  public: CMapEnt_World { -> VHAN}
      CMapEnt_World oWEnt;
      //## end CGEMap::oWEnt%3CF9D4E000DC.role

    // Additional Public Declarations
      //## begin CGEMap%3CA0F7040368.public preserve=yes
      //## end CGEMap%3CA0F7040368.public

  protected:

    //## Other Operations (specified)
      //## Operation: RenderRec%1017327552
      void RenderRec (int _iRoom, int _iDepth);

      //## Operation: Reset%1017327551
      void Reset ();

    // Additional Protected Declarations
      //## begin CGEMap%3CA0F7040368.protected preserve=yes
      //## end CGEMap%3CA0F7040368.protected

  private:
    // Additional Private Declarations
      //## begin CGEMap%3CA0F7040368.private preserve=yes
      //## end CGEMap%3CA0F7040368.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGEMap%3CA0F7040368.implementation preserve=yes
      //## end CGEMap%3CA0F7040368.implementation

};

//## begin CGEMap%3CA0F7040368.postscript preserve=yes
//## end CGEMap%3CA0F7040368.postscript

// Class CGEMap 

//## begin module%3CA0F7040368.epilog preserve=yes
//## end module%3CA0F7040368.epilog


#endif
