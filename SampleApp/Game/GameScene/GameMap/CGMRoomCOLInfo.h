//## begin module%3CE2D1090023.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CE2D1090023.cm

//## begin module%3CE2D1090023.cp preserve=no
//## end module%3CE2D1090023.cp

//## Module: CGMRoomCOLInfo%3CE2D1090023; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\CGMRoomCOLInfo.h

#ifndef CGMRoomCOLInfo_h
#define CGMRoomCOLInfo_h 1

//## begin module%3CE2D1090023.additionalIncludes preserve=no
//## end module%3CE2D1090023.additionalIncludes

//## begin module%3CE2D1090023.includes preserve=yes
#include "misc/gammae_misc.h"
//## end module%3CE2D1090023.includes

// CCOL_Collider
#include "Collision\Collider\CCOL_Collider.h"
//## begin module%3CE2D1090023.additionalDeclarations preserve=yes
//## end module%3CE2D1090023.additionalDeclarations


//## begin CGMRoomCOLInfo%3CE2D1090023.preface preserve=yes
//## end CGMRoomCOLInfo%3CE2D1090023.preface

//## Class: CGMRoomCOLInfo%3CE2D1090023
//## Category: Game::GameScene::GameMap%3C2B3ADF02B0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGMRoomCOLInfo 
{
  //## begin CGMRoomCOLInfo%3CE2D1090023.initialDeclarations preserve=yes
  //## end CGMRoomCOLInfo%3CE2D1090023.initialDeclarations

  public:
    //## Constructors (generated)
      CGMRoomCOLInfo();

    //## Destructor (generated)
      ~CGMRoomCOLInfo();

    // Data Members for Class Attributes

      //## Attribute: oStaticObj%3CE2D12E0171
      //## begin CGMRoomCOLInfo::oStaticObj%3CE2D12E0171.attr preserve=no  public: CCOL_Collider {UA} 
      CCOL_Collider oStaticObj;
      //## end CGMRoomCOLInfo::oStaticObj%3CE2D12E0171.attr

    // Data Members for Associations

      //## Association: Game::GameScene::GameMap::<unnamed>%3CE2D14E011D
      //## Role: CGMRoomCOLInfo::aoDynObjs%3CE2D14E029B
      //## begin CGMRoomCOLInfo::aoDynObjs%3CE2D14E029B.role preserve=no  public: CCOL_Collider { -> UHAN}
      CDynArray <CCOL_Collider> aoDynObjs;
      //## end CGMRoomCOLInfo::aoDynObjs%3CE2D14E029B.role

    // Additional Public Declarations
      //## begin CGMRoomCOLInfo%3CE2D1090023.public preserve=yes
      //## end CGMRoomCOLInfo%3CE2D1090023.public

  protected:
    // Additional Protected Declarations
      //## begin CGMRoomCOLInfo%3CE2D1090023.protected preserve=yes
      //## end CGMRoomCOLInfo%3CE2D1090023.protected

  private:
    // Additional Private Declarations
      //## begin CGMRoomCOLInfo%3CE2D1090023.private preserve=yes
      //## end CGMRoomCOLInfo%3CE2D1090023.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGMRoomCOLInfo%3CE2D1090023.implementation preserve=yes
      //## end CGMRoomCOLInfo%3CE2D1090023.implementation

};

//## begin CGMRoomCOLInfo%3CE2D1090023.postscript preserve=yes
//## end CGMRoomCOLInfo%3CE2D1090023.postscript

// Class CGMRoomCOLInfo 

//## begin module%3CE2D1090023.epilog preserve=yes
//## end module%3CE2D1090023.epilog


#endif
