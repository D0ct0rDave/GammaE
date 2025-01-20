//## begin module%3AFE9A89014A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFE9A89014A.cm

//## begin module%3AFE9A89014A.cp preserve=no
//## end module%3AFE9A89014A.cp

//## Module: CTMSector_8_16%3AFE9A89014A; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\TexMap\CTMSector_8_16.h

#ifndef CTMSector_8_16_h
#define CTMSector_8_16_h 1

//## begin module%3AFE9A89014A.additionalIncludes preserve=no
//## end module%3AFE9A89014A.additionalIncludes

//## begin module%3AFE9A89014A.includes preserve=yes
//## end module%3AFE9A89014A.includes

// CTMSector
#include "TerrainData\Sector\CTMSector.h"
//## begin module%3AFE9A89014A.additionalDeclarations preserve=yes
//## end module%3AFE9A89014A.additionalDeclarations


//## begin CTMSector_8_16%3AFE9A89014A.preface preserve=yes
//## end CTMSector_8_16%3AFE9A89014A.preface

//## Class: CTMSector_8_16%3AFE9A89014A
//## Category: TerrainData::Sector::TexMap%3AFE99CB00F0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTMSector_8_16 : public CTMSector  //## Inherits: <unnamed>%3AFE9AAC017C
{
  //## begin CTMSector_8_16%3AFE9A89014A.initialDeclarations preserve=yes
  //## end CTMSector_8_16%3AFE9A89014A.initialDeclarations

  public:
    //## Constructors (generated)
      CTMSector_8_16();

    //## Destructor (generated)
      ~CTMSector_8_16();


    //## Other Operations (specified)
      //## Operation: CreateClass%989763986
      virtual CSector * CreateClass ();

      //## Operation: ElemArraySize%989763987
      virtual unsigned long ElemArraySize (int _iResolution);

      //## Operation: GetValue%989763988
      virtual CSectElem & GetValue (int _X, int _Y);

      //## Operation: SetValue%989763989
      virtual void SetValue (int _X, int _Y, CSectElem &_Value);

    // Additional Public Declarations
      //## begin CTMSector_8_16%3AFE9A89014A.public preserve=yes
      //## end CTMSector_8_16%3AFE9A89014A.public

  protected:
    // Additional Protected Declarations
      //## begin CTMSector_8_16%3AFE9A89014A.protected preserve=yes
      //## end CTMSector_8_16%3AFE9A89014A.protected

  private:
    // Additional Private Declarations
      //## begin CTMSector_8_16%3AFE9A89014A.private preserve=yes
      //## end CTMSector_8_16%3AFE9A89014A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTMSector_8_16%3AFE9A89014A.implementation preserve=yes
      //## end CTMSector_8_16%3AFE9A89014A.implementation

};

//## begin CTMSector_8_16%3AFE9A89014A.postscript preserve=yes
//## end CTMSector_8_16%3AFE9A89014A.postscript

// Class CTMSector_8_16 

//## begin module%3AFE9A89014A.epilog preserve=yes
//## end module%3AFE9A89014A.epilog


#endif
