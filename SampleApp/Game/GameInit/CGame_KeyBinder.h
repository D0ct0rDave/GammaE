//## begin module%3BDC909002FF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BDC909002FF.cm

//## begin module%3BDC909002FF.cp preserve=no
//## end module%3BDC909002FF.cp

//## Module: CGame_KeyBinder%3BDC909002FF; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameInit\CGame_KeyBinder.h

#ifndef CGame_KeyBinder_h
#define CGame_KeyBinder_h 1

//## begin module%3BDC909002FF.additionalIncludes preserve=no
//## end module%3BDC909002FF.additionalIncludes

//## begin module%3BDC909002FF.includes preserve=yes
//## end module%3BDC909002FF.includes

// GammaE_Misc
#include "Misc\GammaE_Misc.h"
//## begin module%3BDC909002FF.additionalDeclarations preserve=yes
//## end module%3BDC909002FF.additionalDeclarations


//## begin CGame_KeyBinder%3BDC909002FF.preface preserve=yes
//## end CGame_KeyBinder%3BDC909002FF.preface

//## Class: CGame_KeyBinder%3BDC909002FF
//## Category: Game::GameInit%3BDC90800021
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BDC916B034A;GammaE_Misc { -> }

class CGame_KeyBinder 
{
  //## begin CGame_KeyBinder%3BDC909002FF.initialDeclarations preserve=yes
  //## end CGame_KeyBinder%3BDC909002FF.initialDeclarations

  public:
    //## Constructors (generated)
      CGame_KeyBinder();

    //## Destructor (generated)
      ~CGame_KeyBinder();


    //## Other Operations (specified)
      //## Operation: Init%1004309119
      bool Init (char *_szFilename);

    // Additional Public Declarations
      //## begin CGame_KeyBinder%3BDC909002FF.public preserve=yes
      //## end CGame_KeyBinder%3BDC909002FF.public

  protected:
    // Additional Protected Declarations
      //## begin CGame_KeyBinder%3BDC909002FF.protected preserve=yes
      //## end CGame_KeyBinder%3BDC909002FF.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: CmdBindings%3BDC916F0331
      //## begin CGame_KeyBinder::CmdBindings%3BDC916F0331.attr preserve=no  private: CLookupArray {UA} 
      CLookupArray CmdBindings;
      //## end CGame_KeyBinder::CmdBindings%3BDC916F0331.attr

      //## Attribute: KeyBindings%3BDC9432011B
      //## begin CGame_KeyBinder::KeyBindings%3BDC9432011B.attr preserve=no  private: CLookupArray {UA} 
      CLookupArray KeyBindings;
      //## end CGame_KeyBinder::KeyBindings%3BDC9432011B.attr

    // Additional Private Declarations
      //## begin CGame_KeyBinder%3BDC909002FF.private preserve=yes
      //## end CGame_KeyBinder%3BDC909002FF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGame_KeyBinder%3BDC909002FF.implementation preserve=yes
      //## end CGame_KeyBinder%3BDC909002FF.implementation

};

//## begin CGame_KeyBinder%3BDC909002FF.postscript preserve=yes
//## end CGame_KeyBinder%3BDC909002FF.postscript

// Class CGame_KeyBinder 

//## begin module%3BDC909002FF.epilog preserve=yes
//## end module%3BDC909002FF.epilog


#endif
