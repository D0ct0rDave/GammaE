//## begin module%3BDC90DB00CC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BDC90DB00CC.cm

//## begin module%3BDC90DB00CC.cp preserve=no
//## end module%3BDC90DB00CC.cp

//## Module: GammaE_Misc%3BDC90DB00CC; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Misc\GammaE_Misc.h

#ifndef GammaE_Misc_h
#define GammaE_Misc_h 1

//## begin module%3BDC90DB00CC.additionalIncludes preserve=no
//## end module%3BDC90DB00CC.additionalIncludes

//## begin module%3BDC90DB00CC.includes preserve=yes
#include "Misc/ParseUtils/ParseUtils.h"
#include "Misc/Timming/Chronos.h"
#include "Misc/Console/ConsoleIO.h"
//## end module%3BDC90DB00CC.includes

// CStArray
#include "Misc\TAD\CStArray.h"
// CDynArray
#include "Misc\TAD\CDynArray.h"
// CLookupArray
#include "Misc\TAD\CLookupArray.h"
// CHashTable
#include "Misc\TAD\CHashTable.h"
// CChrono
#include "Misc\Timing\CChrono.h"
// CCircularArray
#include "Misc\TAD\CCircularArray.h"
//## begin module%3BDC90DB00CC.additionalDeclarations preserve=yes
//## end module%3BDC90DB00CC.additionalDeclarations


//## begin GammaE_Misc%3BDC90DB00CC.preface preserve=yes
//## end GammaE_Misc%3BDC90DB00CC.preface

//## Class: GammaE_Misc%3BDC90DB00CC
//## Category: Misc%3B74641600DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BDC911202FC;CHashTable { -> }
//## Uses: <unnamed>%3BDC911602BB;CLookupArray { -> }
//## Uses: <unnamed>%3BDC91180264;CChrono { -> }
//## Uses: <unnamed>%3CB49924018D;CDynArray { -> }
//## Uses: <unnamed>%3CE3DD1303BD;CStArray { -> }
//## Uses: <unnamed>%3D0A3FDA0081;CCircularArray { -> }

class GammaE_Misc 
{
  //## begin GammaE_Misc%3BDC90DB00CC.initialDeclarations preserve=yes
  //## end GammaE_Misc%3BDC90DB00CC.initialDeclarations

  public:
    //## Constructors (generated)
      GammaE_Misc();

    //## Destructor (generated)
      ~GammaE_Misc();

    // Additional Public Declarations
      //## begin GammaE_Misc%3BDC90DB00CC.public preserve=yes
      //## end GammaE_Misc%3BDC90DB00CC.public

  protected:
    // Additional Protected Declarations
      //## begin GammaE_Misc%3BDC90DB00CC.protected preserve=yes
      //## end GammaE_Misc%3BDC90DB00CC.protected

  private:
    // Additional Private Declarations
      //## begin GammaE_Misc%3BDC90DB00CC.private preserve=yes
      //## end GammaE_Misc%3BDC90DB00CC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin GammaE_Misc%3BDC90DB00CC.implementation preserve=yes
      //## end GammaE_Misc%3BDC90DB00CC.implementation

};

//## begin GammaE_Misc%3BDC90DB00CC.postscript preserve=yes
//## end GammaE_Misc%3BDC90DB00CC.postscript

// Class GammaE_Misc 

//## begin module%3BDC90DB00CC.epilog preserve=yes
//## end module%3BDC90DB00CC.epilog


#endif
