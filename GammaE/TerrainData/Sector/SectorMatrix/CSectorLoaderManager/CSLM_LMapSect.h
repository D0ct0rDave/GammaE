//## begin module%3B312EFC0136.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B312EFC0136.cm

//## begin module%3B312EFC0136.cp preserve=no
//## end module%3B312EFC0136.cp

//## Module: CSLM_LMapSect%3B312EFC0136; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_LMapSect.h

#ifndef CSLM_LMapSect_h
#define CSLM_LMapSect_h 1

//## begin module%3B312EFC0136.additionalIncludes preserve=no
//## end module%3B312EFC0136.additionalIncludes

//## begin module%3B312EFC0136.includes preserve=yes
//## end module%3B312EFC0136.includes

// CSectorLoaderManager
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h"
// CLMSector_Gray
#include "TerrainData\Sector\LightMap\CLMSector_Gray.h"
// CLMSector_Pal
#include "TerrainData\Sector\LightMap\CLMSector_Pal.h"
// CLMSector_RGB24
#include "TerrainData\Sector\LightMap\CLMSector_RGB24.h"
//## begin module%3B312EFC0136.additionalDeclarations preserve=yes
//## end module%3B312EFC0136.additionalDeclarations


//## begin CSLM_LMapSect%3B312EFC0136.preface preserve=yes
//## end CSLM_LMapSect%3B312EFC0136.preface

//## Class: CSLM_LMapSect%3B312EFC0136
//## Category: TerrainData::Sector::SectorMatrix::CSectorLoaderManager%3B312E8502DA
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B313135000A;CLMSector_RGB24 { -> }
//## Uses: <unnamed>%3B3131360294;CLMSector_Pal { -> }
//## Uses: <unnamed>%3B313138012C;CLMSector_Gray { -> }

class CSLM_LMapSect : public CSectorLoaderManager  //## Inherits: <unnamed>%3B31310A0294
{
  //## begin CSLM_LMapSect%3B312EFC0136.initialDeclarations preserve=yes
  //## end CSLM_LMapSect%3B312EFC0136.initialDeclarations

  public:
    //## Constructors (generated)
      CSLM_LMapSect();

    //## Destructor (generated)
      ~CSLM_LMapSect();


    //## Other Operations (specified)
      //## Operation: poCreateClass%993079315
      virtual CSector * poCreateClass (FILE *_FD);

    // Additional Public Declarations
      //## begin CSLM_LMapSect%3B312EFC0136.public preserve=yes
      //## end CSLM_LMapSect%3B312EFC0136.public

  protected:
    // Additional Protected Declarations
      //## begin CSLM_LMapSect%3B312EFC0136.protected preserve=yes
      //## end CSLM_LMapSect%3B312EFC0136.protected

  private:
    // Additional Private Declarations
      //## begin CSLM_LMapSect%3B312EFC0136.private preserve=yes
      //## end CSLM_LMapSect%3B312EFC0136.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSLM_LMapSect%3B312EFC0136.implementation preserve=yes
      //## end CSLM_LMapSect%3B312EFC0136.implementation

};

//## begin CSLM_LMapSect%3B312EFC0136.postscript preserve=yes
//## end CSLM_LMapSect%3B312EFC0136.postscript

// Class CSLM_LMapSect 

//## begin module%3B312EFC0136.epilog preserve=yes
//## end module%3B312EFC0136.epilog


#endif
