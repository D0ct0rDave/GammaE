//## begin module%3CC130A10022.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CC130A10022.cm

//## begin module%3CC130A10022.cp preserve=no
//## end module%3CC130A10022.cp

//## Module: CGameMetaEntity%3CC130A10022; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\CGameMetaEntity.h

#ifndef CGameMetaEntity_h
#define CGameMetaEntity_h 1

//## begin module%3CC130A10022.additionalIncludes preserve=no
//## end module%3CC130A10022.additionalIncludes

//## begin module%3CC130A10022.includes preserve=yes
//## end module%3CC130A10022.includes

// CGameEntity
#include "Game\Entities\CGameEntity.h"
//## begin module%3CC130A10022.additionalDeclarations preserve=yes
//## end module%3CC130A10022.additionalDeclarations


//## begin CGameMetaEntity%3CC130A10022.preface preserve=yes
//## end CGameMetaEntity%3CC130A10022.preface

//## Class: CGameMetaEntity%3CC130A10022
//## Category: Game::Entities%3B5DE99E0136
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGameMetaEntity : public CGameEntity  //## Inherits: <unnamed>%3CC130D5017B
{
  //## begin CGameMetaEntity%3CC130A10022.initialDeclarations preserve=yes
  //## end CGameMetaEntity%3CC130A10022.initialDeclarations

  public:
    //## Constructors (generated)
      CGameMetaEntity();

    //## Destructor (generated)
      ~CGameMetaEntity();

    // Additional Public Declarations
      //## begin CGameMetaEntity%3CC130A10022.public preserve=yes
      //## end CGameMetaEntity%3CC130A10022.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: oPos%3CC130D7005C
      //## begin CGameMetaEntity::oPos%3CC130D7005C.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oPos;
      //## end CGameMetaEntity::oPos%3CC130D7005C.attr

      //## Attribute: oSpeed%3CC130DA0255
      //## begin CGameMetaEntity::oSpeed%3CC130DA0255.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oSpeed;
      //## end CGameMetaEntity::oSpeed%3CC130DA0255.attr

    // Additional Protected Declarations
      //## begin CGameMetaEntity%3CC130A10022.protected preserve=yes
      //## end CGameMetaEntity%3CC130A10022.protected

  private:
    // Additional Private Declarations
      //## begin CGameMetaEntity%3CC130A10022.private preserve=yes
      //## end CGameMetaEntity%3CC130A10022.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGameMetaEntity%3CC130A10022.implementation preserve=yes
      //## end CGameMetaEntity%3CC130A10022.implementation

};

//## begin CGameMetaEntity%3CC130A10022.postscript preserve=yes
//## end CGameMetaEntity%3CC130A10022.postscript

// Class CGameMetaEntity 

//## begin module%3CC130A10022.epilog preserve=yes
//## end module%3CC130A10022.epilog


#endif
