//## begin module%3AFE944E02A8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFE944E02A8.cm

//## begin module%3AFE944E02A8.cp preserve=no
//## end module%3AFE944E02A8.cp

//## Module: CTexMap%3AFE944E02A8; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CTexMap.h

#ifndef CTexMap_h
#define CTexMap_h 1

//## begin module%3AFE944E02A8.additionalIncludes preserve=no
//## end module%3AFE944E02A8.additionalIncludes

//## begin module%3AFE944E02A8.includes preserve=yes
//## end module%3AFE944E02A8.includes

// CSectorMatrix
#include "TerrainData\Sector\SectorMatrix\CSectorMatrix.h"
// CTMSector_8_16
#include "TerrainData\Sector\TexMap\CTMSector_8_16.h"
// CSLM_TMapSect
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_TMapSect.h"
//## begin module%3AFE944E02A8.additionalDeclarations preserve=yes
//## end module%3AFE944E02A8.additionalDeclarations


//## begin CTexMap%3AFE944E02A8.preface preserve=yes
//## end CTexMap%3AFE944E02A8.preface

//## Class: CTexMap%3AFE944E02A8
//## Category: TerrainData::Sector::SectorMatrix%3AF9B6CF0384
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B12354D0064;CTMSector_8_16 { -> }
//## Uses: <unnamed>%3B313323000A;CSLM_TMapSect { -> }

class CTexMap : public CSectorMatrix  //## Inherits: <unnamed>%3AFE94590118
{
  //## begin CTexMap%3AFE944E02A8.initialDeclarations preserve=yes
  //## end CTexMap%3AFE944E02A8.initialDeclarations

  public:
    //## Constructors (generated)
      CTexMap();

    //## Destructor (generated)
      ~CTexMap();


    //## Other Operations (specified)
      //## Operation: CreateClass%990392863
      //	Creates a new object of the same class as the current
      //	object
      virtual CSector * CreateClass ();

      //## Operation: Init%991049054
      virtual void Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21);

      //## Operation: DataSize%991155096
      //	The size of the data from this object
      virtual unsigned long DataSize ();

    // Additional Public Declarations
      //## begin CTexMap%3AFE944E02A8.public preserve=yes
      //## end CTexMap%3AFE944E02A8.public

  protected:
    // Additional Protected Declarations
      //## begin CTexMap%3AFE944E02A8.protected preserve=yes
      //## end CTexMap%3AFE944E02A8.protected

  private:
    // Additional Private Declarations
      //## begin CTexMap%3AFE944E02A8.private preserve=yes
      //## end CTexMap%3AFE944E02A8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTexMap%3AFE944E02A8.implementation preserve=yes
      //## end CTexMap%3AFE944E02A8.implementation

};

//## begin CTexMap%3AFE944E02A8.postscript preserve=yes
//## end CTexMap%3AFE944E02A8.postscript

// Class CTexMap 

//## begin module%3AFE944E02A8.epilog preserve=yes
//## end module%3AFE944E02A8.epilog


#endif
