//## begin module%3B312EE00050.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B312EE00050.cm

//## begin module%3B312EE00050.cp preserve=no
//## end module%3B312EE00050.cp

//## Module: CSLM_HFieldSect%3B312EE00050; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_HFieldSect.h

#ifndef CSLM_HFieldSect_h
#define CSLM_HFieldSect_h 1

//## begin module%3B312EE00050.additionalIncludes preserve=no
//## end module%3B312EE00050.additionalIncludes

//## begin module%3B312EE00050.includes preserve=yes
//## end module%3B312EE00050.includes

// CSectorLoaderManager
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h"
// CHFSector_FN
#include "TerrainData\Sector\HeightField\CHFSector_FN.h"
//## begin module%3B312EE00050.additionalDeclarations preserve=yes
//## end module%3B312EE00050.additionalDeclarations


//## begin CSLM_HFieldSect%3B312EE00050.preface preserve=yes
//## end CSLM_HFieldSect%3B312EE00050.preface

//## Class: CSLM_HFieldSect%3B312EE00050
//## Category: TerrainData::Sector::SectorMatrix::CSectorLoaderManager%3B312E8502DA
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B3130A1032A;CHFSector_FN { -> }

class CSLM_HFieldSect : public CSectorLoaderManager  //## Inherits: <unnamed>%3B31310600A0
{
  //## begin CSLM_HFieldSect%3B312EE00050.initialDeclarations preserve=yes
  //## end CSLM_HFieldSect%3B312EE00050.initialDeclarations

  public:
    //## Constructors (generated)
      CSLM_HFieldSect();

    //## Destructor (generated)
      ~CSLM_HFieldSect();


    //## Other Operations (specified)
      //## Operation: poCreateClass%993079317
      virtual CSector * poCreateClass (FILE *_FD);

    // Additional Public Declarations
      //## begin CSLM_HFieldSect%3B312EE00050.public preserve=yes
      //## end CSLM_HFieldSect%3B312EE00050.public

  protected:
    // Additional Protected Declarations
      //## begin CSLM_HFieldSect%3B312EE00050.protected preserve=yes
      //## end CSLM_HFieldSect%3B312EE00050.protected

  private:
    // Additional Private Declarations
      //## begin CSLM_HFieldSect%3B312EE00050.private preserve=yes
      //## end CSLM_HFieldSect%3B312EE00050.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSLM_HFieldSect%3B312EE00050.implementation preserve=yes
      //## end CSLM_HFieldSect%3B312EE00050.implementation

};

//## begin CSLM_HFieldSect%3B312EE00050.postscript preserve=yes
//## end CSLM_HFieldSect%3B312EE00050.postscript

// Class CSLM_HFieldSect 

//## begin module%3B312EE00050.epilog preserve=yes
//## end module%3B312EE00050.epilog


#endif
