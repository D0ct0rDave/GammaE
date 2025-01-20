//## begin module%3B312EED01E0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B312EED01E0.cm

//## begin module%3B312EED01E0.cp preserve=no
//## end module%3B312EED01E0.cp

//## Module: CSLM_TMapSect%3B312EED01E0; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_TMapSect.h

#ifndef CSLM_TMapSect_h
#define CSLM_TMapSect_h 1

//## begin module%3B312EED01E0.additionalIncludes preserve=no
//## end module%3B312EED01E0.additionalIncludes

//## begin module%3B312EED01E0.includes preserve=yes
//## end module%3B312EED01E0.includes

// CSectorLoaderManager
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h"
// CTMSector_8_16
#include "TerrainData\Sector\TexMap\CTMSector_8_16.h"
//## begin module%3B312EED01E0.additionalDeclarations preserve=yes
//## end module%3B312EED01E0.additionalDeclarations


//## begin CSLM_TMapSect%3B312EED01E0.preface preserve=yes
//## end CSLM_TMapSect%3B312EED01E0.preface

//## Class: CSLM_TMapSect%3B312EED01E0
//## Category: TerrainData::Sector::SectorMatrix::CSectorLoaderManager%3B312E8502DA
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B3131560046;CTMSector_8_16 { -> }

class CSLM_TMapSect : public CSectorLoaderManager  //## Inherits: <unnamed>%3B3131070398
{
  //## begin CSLM_TMapSect%3B312EED01E0.initialDeclarations preserve=yes
  //## end CSLM_TMapSect%3B312EED01E0.initialDeclarations

  public:
    //## Constructors (generated)
      CSLM_TMapSect();

    //## Destructor (generated)
      ~CSLM_TMapSect();


    //## Other Operations (specified)
      //## Operation: poCreateClass%993079316
      virtual CSector * poCreateClass (FILE *_FD);

    // Additional Public Declarations
      //## begin CSLM_TMapSect%3B312EED01E0.public preserve=yes
      //## end CSLM_TMapSect%3B312EED01E0.public

  protected:
    // Additional Protected Declarations
      //## begin CSLM_TMapSect%3B312EED01E0.protected preserve=yes
      //## end CSLM_TMapSect%3B312EED01E0.protected

  private:
    // Additional Private Declarations
      //## begin CSLM_TMapSect%3B312EED01E0.private preserve=yes
      //## end CSLM_TMapSect%3B312EED01E0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSLM_TMapSect%3B312EED01E0.implementation preserve=yes
      //## end CSLM_TMapSect%3B312EED01E0.implementation

};

//## begin CSLM_TMapSect%3B312EED01E0.postscript preserve=yes
//## end CSLM_TMapSect%3B312EED01E0.postscript

// Class CSLM_TMapSect 

//## begin module%3B312EED01E0.epilog preserve=yes
//## end module%3B312EED01E0.epilog


#endif
