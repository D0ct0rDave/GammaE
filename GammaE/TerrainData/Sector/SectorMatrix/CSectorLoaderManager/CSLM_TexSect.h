//## begin module%3B312F0F0064.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B312F0F0064.cm

//## begin module%3B312F0F0064.cp preserve=no
//## end module%3B312F0F0064.cp

//## Module: CSLM_TexSect%3B312F0F0064; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_TexSect.h

#ifndef CSLM_TexSect_h
#define CSLM_TexSect_h 1

//## begin module%3B312F0F0064.additionalIncludes preserve=no
//## end module%3B312F0F0064.additionalIncludes

//## begin module%3B312F0F0064.includes preserve=yes
//## end module%3B312F0F0064.includes

// CSectorLoaderManager
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h"
//## begin module%3B312F0F0064.additionalDeclarations preserve=yes
//## end module%3B312F0F0064.additionalDeclarations


//## begin CSLM_TexSect%3B312F0F0064.preface preserve=yes
//## end CSLM_TexSect%3B312F0F0064.preface

//## Class: CSLM_TexSect%3B312F0F0064
//## Category: TerrainData::Sector::SectorMatrix::CSectorLoaderManager%3B312E8502DA
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSLM_TexSect : public CSectorLoaderManager  //## Inherits: <unnamed>%3B31310C02B2
{
  //## begin CSLM_TexSect%3B312F0F0064.initialDeclarations preserve=yes
  //## end CSLM_TexSect%3B312F0F0064.initialDeclarations

  public:
    //## Constructors (generated)
      CSLM_TexSect();

    //## Destructor (generated)
      ~CSLM_TexSect();


    //## Other Operations (specified)
      //## Operation: poCreateClass%993079314
      virtual CSector * poCreateClass (FILE *_FD);

    // Additional Public Declarations
      //## begin CSLM_TexSect%3B312F0F0064.public preserve=yes
      //## end CSLM_TexSect%3B312F0F0064.public

  protected:
    // Additional Protected Declarations
      //## begin CSLM_TexSect%3B312F0F0064.protected preserve=yes
      //## end CSLM_TexSect%3B312F0F0064.protected

  private:
    // Additional Private Declarations
      //## begin CSLM_TexSect%3B312F0F0064.private preserve=yes
      //## end CSLM_TexSect%3B312F0F0064.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSLM_TexSect%3B312F0F0064.implementation preserve=yes
      //## end CSLM_TexSect%3B312F0F0064.implementation

};

//## begin CSLM_TexSect%3B312F0F0064.postscript preserve=yes
//## end CSLM_TexSect%3B312F0F0064.postscript

// Class CSLM_TexSect 

//## begin module%3B312F0F0064.epilog preserve=yes
//## end module%3B312F0F0064.epilog


#endif
