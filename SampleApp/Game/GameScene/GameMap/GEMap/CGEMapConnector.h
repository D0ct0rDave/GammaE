//## begin module%3CA0F25C00F7.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F25C00F7.cm

//## begin module%3CA0F25C00F7.cp preserve=no
//## end module%3CA0F25C00F7.cp

//## Module: CGEMapConnector%3CA0F25C00F7; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GEMap\CGEMapConnector.h

#ifndef CGEMapConnector_h
#define CGEMapConnector_h 1

//## begin module%3CA0F25C00F7.additionalIncludes preserve=no
//## end module%3CA0F25C00F7.additionalIncludes

//## begin module%3CA0F25C00F7.includes preserve=yes
//## end module%3CA0F25C00F7.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3CA0F25C00F7.additionalDeclarations preserve=yes
//## end module%3CA0F25C00F7.additionalDeclarations


//## begin CGEMapConnector%3CA0F25C00F7.preface preserve=yes
//## end CGEMapConnector%3CA0F25C00F7.preface

//## Class: CGEMapConnector%3CA0F25C00F7
//## Category: Game::GameScene::GameMap::GEMap%3CA0FEC20001
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CA4351D03DA;GammaE_Math { -> }
//## Uses: <unnamed>%3CA43C320232;GammaE_E3D { -> }

class CGEMapConnector 
{
  //## begin CGEMapConnector%3CA0F25C00F7.initialDeclarations preserve=yes
  //## end CGEMapConnector%3CA0F25C00F7.initialDeclarations

  public:
    //## Constructors (generated)
      CGEMapConnector();

    //## Destructor (generated)
      ~CGEMapConnector();

    // Data Members for Class Attributes

      //## Attribute: iRoomA%3CA0F64E03CB
      //## begin CGEMapConnector::iRoomA%3CA0F64E03CB.attr preserve=no  public: int {UA} 
      int iRoomA;
      //## end CGEMapConnector::iRoomA%3CA0F64E03CB.attr

      //## Attribute: iRoomB%3CA0F65802F3
      //## begin CGEMapConnector::iRoomB%3CA0F65802F3.attr preserve=no  public: int {UA} 
      int iRoomB;
      //## end CGEMapConnector::iRoomB%3CA0F65802F3.attr

      //## Attribute: oBBox%3CA43C1C033F
      //## begin CGEMapConnector::oBBox%3CA43C1C033F.attr preserve=no  public: CBoundingBox {UA} 
      CBoundingBox oBBox;
      //## end CGEMapConnector::oBBox%3CA43C1C033F.attr

    // Additional Public Declarations
      //## begin CGEMapConnector%3CA0F25C00F7.public preserve=yes
      //## end CGEMapConnector%3CA0F25C00F7.public

  protected:
    // Additional Protected Declarations
      //## begin CGEMapConnector%3CA0F25C00F7.protected preserve=yes
      //## end CGEMapConnector%3CA0F25C00F7.protected

  private:
    // Additional Private Declarations
      //## begin CGEMapConnector%3CA0F25C00F7.private preserve=yes
      //## end CGEMapConnector%3CA0F25C00F7.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGEMapConnector%3CA0F25C00F7.implementation preserve=yes
      //## end CGEMapConnector%3CA0F25C00F7.implementation

};

//## begin CGEMapConnector%3CA0F25C00F7.postscript preserve=yes
//## end CGEMapConnector%3CA0F25C00F7.postscript

// Class CGEMapConnector 

//## begin module%3CA0F25C00F7.epilog preserve=yes
//## end module%3CA0F25C00F7.epilog


#endif
