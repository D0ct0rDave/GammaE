//## begin module%3AF50E67029E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF50E67029E.cm

//## begin module%3AF50E67029E.cp preserve=no
//## end module%3AF50E67029E.cp

//## Module: CLMSector%3AF50E67029E; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\CLMSector.h

#ifndef CLMSector_h
#define CLMSector_h 1

//## begin module%3AF50E67029E.additionalIncludes preserve=no
//## end module%3AF50E67029E.additionalIncludes

//## begin module%3AF50E67029E.includes preserve=yes
//## end module%3AF50E67029E.includes

// CSector
#include "TerrainData\Sector\CSector.h"
// CLightElem
#include "TerrainData\SectElem\CLightElem.h"
//## begin module%3AF50E67029E.additionalDeclarations preserve=yes
//## end module%3AF50E67029E.additionalDeclarations


//## begin CLMSector%3AF50E67029E.preface preserve=yes
//## end CLMSector%3AF50E67029E.preface

//## Class: CLMSector%3AF50E67029E
//## Category: TerrainData::Sector%3AF5122E008C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AF87875037A;CLightElem { -> }

class CLMSector : public CSector  //## Inherits: <unnamed>%3AFE99F20230
{
  //## begin CLMSector%3AF50E67029E.initialDeclarations preserve=yes
  //## end CLMSector%3AF50E67029E.initialDeclarations

  public:
    //## Constructors (generated)
      CLMSector();

    //## Destructor (generated)
      ~CLMSector();

    // Additional Public Declarations
      //## begin CLMSector%3AF50E67029E.public preserve=yes
      //## end CLMSector%3AF50E67029E.public

  protected:
    // Additional Protected Declarations
      //## begin CLMSector%3AF50E67029E.protected preserve=yes
      //## end CLMSector%3AF50E67029E.protected

  private:
    // Additional Private Declarations
      //## begin CLMSector%3AF50E67029E.private preserve=yes
      //## end CLMSector%3AF50E67029E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLMSector%3AF50E67029E.implementation preserve=yes
      //## end CLMSector%3AF50E67029E.implementation

};

//## begin CLMSector%3AF50E67029E.postscript preserve=yes
//## end CLMSector%3AF50E67029E.postscript

// Class CLMSector 

//## begin module%3AF50E67029E.epilog preserve=yes
//## end module%3AF50E67029E.epilog


#endif
