//## begin module%3CA0F2B100EF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F2B100EF.cm

//## begin module%3CA0F2B100EF.cp preserve=no
//## end module%3CA0F2B100EF.cp

//## Module: CGEMapRoom%3CA0F2B100EF; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMapRoom.h

#ifndef CGEMapRoom_h
#define CGEMapRoom_h 1

//## begin module%3CA0F2B100EF.additionalIncludes preserve=no
//## end module%3CA0F2B100EF.additionalIncludes

//## begin module%3CA0F2B100EF.includes preserve=yes
//## end module%3CA0F2B100EF.includes

// CRTME_Target
#include "Game\Entities\RTMapEntities\CRTME_Target.h"
// CMapEntity
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntity.h"
// GammaE_Scene
#include "Scene\GammaE_Scene.h"
//## begin module%3CA0F2B100EF.additionalDeclarations preserve=yes
//## end module%3CA0F2B100EF.additionalDeclarations


//## begin CGEMapRoom%3CA0F2B100EF.preface preserve=yes
//## end CGEMapRoom%3CA0F2B100EF.preface

//## Class: CGEMapRoom%3CA0F2B100EF
//	poScn : Geometría de la habitación
//	iNumEnts , poEnts : Entidades de mapa que pertenecen a
//	la habitación.
//	bVisited: indica si durante el frame actual, esta
//	habitación ha sido visitada (en rendering por ejemplo,
//	aunque podría ser util para otra cosa, colisiones,
//	sonido...)
//	poAuxScn: Geometria auxilar de la habitación. Algunas
//	entidades que en tiempo de carga implican geometría
//	adicional.
//## Category: Game::GameScene::GameMap::GEMap%3CA0FEC20001
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CA347DD03D7;GammaE_Scene { -> }

class CGEMapRoom 
{
  //## begin CGEMapRoom%3CA0F2B100EF.initialDeclarations preserve=yes
  //## end CGEMapRoom%3CA0F2B100EF.initialDeclarations

  public:
    //## Constructors (generated)
      CGEMapRoom();

    //## Destructor (generated)
      ~CGEMapRoom();

    // Data Members for Class Attributes

      //## Attribute: poScn%3CA0F8050119
      //## begin CGEMapRoom::poScn%3CA0F8050119.attr preserve=no  public: CObject3D * {UA} NULL
      CObject3D *poScn;
      //## end CGEMapRoom::poScn%3CA0F8050119.attr

      //## Attribute: poAdjScn%3CE00646003E
      //## begin CGEMapRoom::poAdjScn%3CE00646003E.attr preserve=no  public: CObject3D_Node * {UA} NULL
      CObject3D_Node *poAdjScn;
      //## end CGEMapRoom::poAdjScn%3CE00646003E.attr

      //## Attribute: poAdjScnCol%3CE006500273
      //## begin CGEMapRoom::poAdjScnCol%3CE006500273.attr preserve=no  public: CObject3D_Node * {UA} NULL
      CObject3D_Node *poAdjScnCol;
      //## end CGEMapRoom::poAdjScnCol%3CE006500273.attr

      //## Attribute: iNumEnts%3CA0F9650328
      //## begin CGEMapRoom::iNumEnts%3CA0F9650328.attr preserve=no  public: int {UA} 0
      int iNumEnts;
      //## end CGEMapRoom::iNumEnts%3CA0F9650328.attr

      //## Attribute: piCons%3CA4352E0171
      //## begin CGEMapRoom::piCons%3CA4352E0171.attr preserve=no  public: int * {UA} NULL
      int *piCons;
      //## end CGEMapRoom::piCons%3CA4352E0171.attr

      //## Attribute: iNumCons%3CD51543038E
      //## begin CGEMapRoom::iNumCons%3CD51543038E.attr preserve=no  public: int {UA} 0
      int iNumCons;
      //## end CGEMapRoom::iNumCons%3CD51543038E.attr

      //## Attribute: piARoom%3CA43559019B
      //## begin CGEMapRoom::piARoom%3CA43559019B.attr preserve=no  public: int * {UA} NULL
      int *piARoom;
      //## end CGEMapRoom::piARoom%3CA43559019B.attr

      //## Attribute: iNumARooms%3CA435730080
      //## begin CGEMapRoom::iNumARooms%3CA435730080.attr preserve=no  public: int {UA} 0
      int iNumARooms;
      //## end CGEMapRoom::iNumARooms%3CA435730080.attr

      //## Attribute: bVisited%3CA0FB2001C6
      //## begin CGEMapRoom::bVisited%3CA0FB2001C6.attr preserve=no  public: bool {UA} false
      bool bVisited;
      //## end CGEMapRoom::bVisited%3CA0FB2001C6.attr

    // Data Members for Associations

      //## Association: Game::GameScene::GameMap::GEMap::<unnamed>%3CDEDAE901DA
      //## Role: CGEMapRoom::poRTEnts%3CDEDAE902AE
      //## begin CGEMapRoom::poRTEnts%3CDEDAE902AE.role preserve=no  public: CRTME_Target { -> UHAN}
      CRTME_Target **poRTEnts;
      //## end CGEMapRoom::poRTEnts%3CDEDAE902AE.role

      //## Association: Tools::GEMapCompiler::<unnamed>%3CA0F94A029D
      //## Role: CGEMapRoom::poEnts%3CA0F94A0352
      //## begin CGEMapRoom::poEnts%3CA0F94A0352.role preserve=no  public: CMapEntity { -> RHAN}
      CMapEntity **poEnts;
      //## end CGEMapRoom::poEnts%3CA0F94A0352.role

    // Additional Public Declarations
      //## begin CGEMapRoom%3CA0F2B100EF.public preserve=yes
      //## end CGEMapRoom%3CA0F2B100EF.public

  protected:
    // Additional Protected Declarations
      //## begin CGEMapRoom%3CA0F2B100EF.protected preserve=yes
      //## end CGEMapRoom%3CA0F2B100EF.protected

  private:
    // Additional Private Declarations
      //## begin CGEMapRoom%3CA0F2B100EF.private preserve=yes
      //## end CGEMapRoom%3CA0F2B100EF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGEMapRoom%3CA0F2B100EF.implementation preserve=yes
      //## end CGEMapRoom%3CA0F2B100EF.implementation

};

//## begin CGEMapRoom%3CA0F2B100EF.postscript preserve=yes
//## end CGEMapRoom%3CA0F2B100EF.postscript

// Class CGEMapRoom 

//## begin module%3CA0F2B100EF.epilog preserve=yes
//## end module%3CA0F2B100EF.epilog


#endif
