//## begin module%3B5DE9A4012C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B5DE9A4012C.cm

//## begin module%3B5DE9A4012C.cp preserve=no
//## end module%3B5DE9A4012C.cp

//## Module: CGameEntity%3B5DE9A4012C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\CGameEntity.h

#ifndef CGameEntity_h
#define CGameEntity_h 1

//## begin module%3B5DE9A4012C.additionalIncludes preserve=no
//## end module%3B5DE9A4012C.additionalIncludes

//## begin module%3B5DE9A4012C.includes preserve=yes
//## end module%3B5DE9A4012C.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3B5DE9A4012C.additionalDeclarations preserve=yes
//## end module%3B5DE9A4012C.additionalDeclarations


//## begin CGameEntity%3B5DE9A4012C.preface preserve=yes
//## end CGameEntity%3B5DE9A4012C.preface

//## Class: CGameEntity%3B5DE9A4012C
//## Category: Game::Entities%3B5DE99E0136
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CB855C0000D;GammaE_Math { -> }

class CGameEntity 
{
  //## begin CGameEntity%3B5DE9A4012C.initialDeclarations preserve=yes
  //## end CGameEntity%3B5DE9A4012C.initialDeclarations

  public:
    //## Constructors (generated)
      CGameEntity();

    //## Destructor (generated)
      ~CGameEntity();


    //## Other Operations (specified)
      //## Operation: Think%996008333
      virtual void Think (float _fDelta);

      //## Operation: ProcessCmds%1021565343
      virtual void ProcessCmds (float _fDelta);

      //## Operation: Interact%1021565348
      virtual void Interact (float _fDelta);

    // Data Members for Class Attributes

      //## Attribute: Destroy%3CE3DF300040
      //## begin CGameEntity::Destroy%3CE3DF300040.attr preserve=no  public: bool {UA} false
      bool Destroy;
      //## end CGameEntity::Destroy%3CE3DF300040.attr

    // Additional Public Declarations
      //## begin CGameEntity%3B5DE9A4012C.public preserve=yes
      //## end CGameEntity%3B5DE9A4012C.public

  protected:
    // Additional Protected Declarations
      //## begin CGameEntity%3B5DE9A4012C.protected preserve=yes
      //## end CGameEntity%3B5DE9A4012C.protected

  private:
    // Additional Private Declarations
      //## begin CGameEntity%3B5DE9A4012C.private preserve=yes
      //## end CGameEntity%3B5DE9A4012C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGameEntity%3B5DE9A4012C.implementation preserve=yes
      //## end CGameEntity%3B5DE9A4012C.implementation

};

//## begin CGameEntity%3B5DE9A4012C.postscript preserve=yes
//## end CGameEntity%3B5DE9A4012C.postscript

// Class CGameEntity 

//## begin module%3B5DE9A4012C.epilog preserve=yes
//## end module%3B5DE9A4012C.epilog


#endif
