//## begin module%3AFC0CA80212.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFC0CA80212.cm

//## begin module%3AFC0CA80212.cp preserve=no
//## end module%3AFC0CA80212.cp

//## Module: CLightMap%3AFC0CA80212; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CLightMap.h

#ifndef CLightMap_h
#define CLightMap_h 1

//## begin module%3AFC0CA80212.additionalIncludes preserve=no
//## end module%3AFC0CA80212.additionalIncludes

//## begin module%3AFC0CA80212.includes preserve=yes
//## end module%3AFC0CA80212.includes

// CSectorMatrix
#include "TerrainData\Sector\SectorMatrix\CSectorMatrix.h"
// CLMSector_RGB24
#include "TerrainData\Sector\LightMap\CLMSector_RGB24.h"
// CSLM_LMapSect
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_LMapSect.h"
//## begin module%3AFC0CA80212.additionalDeclarations preserve=yes
//## end module%3AFC0CA80212.additionalDeclarations


//## begin CLightMap%3AFC0CA80212.preface preserve=yes
//## end CLightMap%3AFC0CA80212.preface

//## Class: CLightMap%3AFC0CA80212
//## Category: TerrainData::Sector::SectorMatrix%3AF9B6CF0384
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AFC0DF402D0;CLMSector_RGB24 { -> }
//## Uses: <unnamed>%3B31332F0028;CSLM_LMapSect { -> }

class CLightMap : public CSectorMatrix  //## Inherits: <unnamed>%3AFC0CB101E0
{
  //## begin CLightMap%3AFC0CA80212.initialDeclarations preserve=yes
  //## end CLightMap%3AFC0CA80212.initialDeclarations

  public:
    //## Constructors (generated)
      CLightMap();

    //## Destructor (generated)
      ~CLightMap();


    //## Other Operations (specified)
      //## Operation: DataSize%989597155
      virtual unsigned long DataSize ();

      //## Operation: CreateClass%989597156
      virtual CSector * CreateClass ();

      //## Operation: Init%989597157
      virtual void Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21);

    // Additional Public Declarations
      //## begin CLightMap%3AFC0CA80212.public preserve=yes
      //## end CLightMap%3AFC0CA80212.public

  protected:
    // Additional Protected Declarations
      //## begin CLightMap%3AFC0CA80212.protected preserve=yes
      //## end CLightMap%3AFC0CA80212.protected

  private:
    // Additional Private Declarations
      //## begin CLightMap%3AFC0CA80212.private preserve=yes
      //## end CLightMap%3AFC0CA80212.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLightMap%3AFC0CA80212.implementation preserve=yes
      //## end CLightMap%3AFC0CA80212.implementation

};

//## begin CLightMap%3AFC0CA80212.postscript preserve=yes
//## end CLightMap%3AFC0CA80212.postscript

// Class CLightMap 

//## begin module%3AFC0CA80212.epilog preserve=yes
//## end module%3AFC0CA80212.epilog


#endif
