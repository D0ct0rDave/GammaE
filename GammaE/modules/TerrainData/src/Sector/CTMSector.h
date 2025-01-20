//## begin module%3AF50E6C0370.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF50E6C0370.cm

//## begin module%3AF50E6C0370.cp preserve=no
//## end module%3AF50E6C0370.cp

//## Module: CTMSector%3AF50E6C0370; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\CTMSector.h

#ifndef CTMSector_h
#define CTMSector_h 1

//## begin module%3AF50E6C0370.additionalIncludes preserve=no
//## end module%3AF50E6C0370.additionalIncludes

//## begin module%3AF50E6C0370.includes preserve=yes
//## end module%3AF50E6C0370.includes

// CSector
#include "TerrainData\Sector\CSector.h"
// CTile
#include "TerrainData\SectElem\CTile.h"
//## begin module%3AF50E6C0370.additionalDeclarations preserve=yes
//## end module%3AF50E6C0370.additionalDeclarations


//## begin CTMSector%3AF50E6C0370.preface preserve=yes
//## end CTMSector%3AF50E6C0370.preface

//## Class: CTMSector%3AF50E6C0370
//## Category: TerrainData::Sector%3AF5122E008C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AFE99AC00C8;CTile { -> }

class CTMSector : public CSector  //## Inherits: <unnamed>%3AFB11BD006E
{
  //## begin CTMSector%3AF50E6C0370.initialDeclarations preserve=yes
  //## end CTMSector%3AF50E6C0370.initialDeclarations

  public:
    //## Constructors (generated)
      CTMSector();

    //## Destructor (generated)
      ~CTMSector();

    // Additional Public Declarations
      //## begin CTMSector%3AF50E6C0370.public preserve=yes
      //## end CTMSector%3AF50E6C0370.public

  protected:
    // Additional Protected Declarations
      //## begin CTMSector%3AF50E6C0370.protected preserve=yes
      //## end CTMSector%3AF50E6C0370.protected

  private:
    // Additional Private Declarations
      //## begin CTMSector%3AF50E6C0370.private preserve=yes
      //## end CTMSector%3AF50E6C0370.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTMSector%3AF50E6C0370.implementation preserve=yes
      //## end CTMSector%3AF50E6C0370.implementation

};

//## begin CTMSector%3AF50E6C0370.postscript preserve=yes
//## end CTMSector%3AF50E6C0370.postscript

// Class CTMSector 

//## begin module%3AF50E6C0370.epilog preserve=yes
//## end module%3AF50E6C0370.epilog


#endif
