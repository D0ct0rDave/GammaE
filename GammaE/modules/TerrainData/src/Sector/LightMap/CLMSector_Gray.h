//## begin module%3AFD2499003C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFD2499003C.cm

//## begin module%3AFD2499003C.cp preserve=no
//## end module%3AFD2499003C.cp

//## Module: CLMSector_Gray%3AFD2499003C; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\LightMap\CLMSector_Gray.h

#ifndef CLMSector_Gray_h
#define CLMSector_Gray_h 1

//## begin module%3AFD2499003C.additionalIncludes preserve=no
//## end module%3AFD2499003C.additionalIncludes

//## begin module%3AFD2499003C.includes preserve=yes
//## end module%3AFD2499003C.includes

// CLMSector
#include "TerrainData\Sector\CLMSector.h"
//## begin module%3AFD2499003C.additionalDeclarations preserve=yes
//## end module%3AFD2499003C.additionalDeclarations


//## begin CLMSector_Gray%3AFD2499003C.preface preserve=yes
//## end CLMSector_Gray%3AFD2499003C.preface

//## Class: CLMSector_Gray%3AFD2499003C
//## Category: TerrainData::Sector::LightMap%3AFC0D5A01AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLMSector_Gray : public CLMSector  //## Inherits: <unnamed>%3AFD24AB0384
{
  //## begin CLMSector_Gray%3AFD2499003C.initialDeclarations preserve=yes
  //## end CLMSector_Gray%3AFD2499003C.initialDeclarations

  public:
    //## Constructors (generated)
      CLMSector_Gray();

    //## Destructor (generated)
      ~CLMSector_Gray();


    //## Other Operations (specified)
      //## Operation: GetValue%989667583
      virtual CSectElem & GetValue (int _X, int _Y);

      //## Operation: SetValue%989667584
      virtual void SetValue (int _X, int _Y, CSectElem &_Value);

      //## Operation: CreateClass%989667586
      virtual CSector * CreateClass ();

      //## Operation: ElemArraySize%989667596
      virtual unsigned long ElemArraySize (int _iResolution);

    // Additional Public Declarations
      //## begin CLMSector_Gray%3AFD2499003C.public preserve=yes
      //## end CLMSector_Gray%3AFD2499003C.public

  protected:
    // Additional Protected Declarations
      //## begin CLMSector_Gray%3AFD2499003C.protected preserve=yes
      //## end CLMSector_Gray%3AFD2499003C.protected

  private:
    // Additional Private Declarations
      //## begin CLMSector_Gray%3AFD2499003C.private preserve=yes
      //## end CLMSector_Gray%3AFD2499003C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLMSector_Gray%3AFD2499003C.implementation preserve=yes
      //## end CLMSector_Gray%3AFD2499003C.implementation

};

//## begin CLMSector_Gray%3AFD2499003C.postscript preserve=yes
//## end CLMSector_Gray%3AFD2499003C.postscript

// Class CLMSector_Gray 

//## begin module%3AFD2499003C.epilog preserve=yes
//## end module%3AFD2499003C.epilog


#endif
