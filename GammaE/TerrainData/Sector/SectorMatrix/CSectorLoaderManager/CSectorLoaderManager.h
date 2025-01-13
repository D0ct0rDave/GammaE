//## begin module%3B312E900334.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B312E900334.cm

//## begin module%3B312E900334.cp preserve=no
//## end module%3B312E900334.cp

//## Module: CSectorLoaderManager%3B312E900334; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h

#ifndef CSectorLoaderManager_h
#define CSectorLoaderManager_h 1

//## begin module%3B312E900334.additionalIncludes preserve=no
//## end module%3B312E900334.additionalIncludes

//## begin module%3B312E900334.includes preserve=yes
//## end module%3B312E900334.includes

// CSector
#include "TerrainData\Sector\CSector.h"
//## begin module%3B312E900334.additionalDeclarations preserve=yes
//## end module%3B312E900334.additionalDeclarations


//## begin CSectorLoaderManager%3B312E900334.preface preserve=yes
//## end CSectorLoaderManager%3B312E900334.preface

//## Class: CSectorLoaderManager%3B312E900334
//## Category: TerrainData::Sector::SectorMatrix::CSectorLoaderManager%3B312E8502DA
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B3131A902DA;CSector { -> }

class CSectorLoaderManager 
{
  //## begin CSectorLoaderManager%3B312E900334.initialDeclarations preserve=yes
  //## end CSectorLoaderManager%3B312E900334.initialDeclarations

  public:
    //## Constructors (generated)
      CSectorLoaderManager();

    //## Destructor (generated)
      ~CSectorLoaderManager();


    //## Other Operations (specified)
      //## Operation: poCreateClass%993079313
      virtual CSector * poCreateClass (FILE *_FD);

    // Additional Public Declarations
      //## begin CSectorLoaderManager%3B312E900334.public preserve=yes
      //## end CSectorLoaderManager%3B312E900334.public

  protected:
    // Additional Protected Declarations
      //## begin CSectorLoaderManager%3B312E900334.protected preserve=yes
      //## end CSectorLoaderManager%3B312E900334.protected

  private:
    // Additional Private Declarations
      //## begin CSectorLoaderManager%3B312E900334.private preserve=yes
      //## end CSectorLoaderManager%3B312E900334.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSectorLoaderManager%3B312E900334.implementation preserve=yes
      //## end CSectorLoaderManager%3B312E900334.implementation

};

//## begin CSectorLoaderManager%3B312E900334.postscript preserve=yes
//## end CSectorLoaderManager%3B312E900334.postscript

// Class CSectorLoaderManager 

//## begin module%3B312E900334.epilog preserve=yes
//## end module%3B312E900334.epilog


#endif
