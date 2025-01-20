//## begin module%3AFC0D7200D2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFC0D7200D2.cm

//## begin module%3AFC0D7200D2.cp preserve=no
//## end module%3AFC0D7200D2.cp

//## Module: CLMSector_RGB24%3AFC0D7200D2; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\LightMap\CLMSector_RGB24.h

#ifndef CLMSector_RGB24_h
#define CLMSector_RGB24_h 1

//## begin module%3AFC0D7200D2.additionalIncludes preserve=no
//## end module%3AFC0D7200D2.additionalIncludes

//## begin module%3AFC0D7200D2.includes preserve=yes
//## end module%3AFC0D7200D2.includes

// CLMSector
#include "TerrainData\Sector\CLMSector.h"
//## begin module%3AFC0D7200D2.additionalDeclarations preserve=yes
//## end module%3AFC0D7200D2.additionalDeclarations


//## begin CLMSector_RGB24%3AFC0D7200D2.preface preserve=yes
//## end CLMSector_RGB24%3AFC0D7200D2.preface

//## Class: CLMSector_RGB24%3AFC0D7200D2
//## Category: TerrainData::Sector::LightMap%3AFC0D5A01AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLMSector_RGB24 : public CLMSector  //## Inherits: <unnamed>%3AFC0D920122
{
  //## begin CLMSector_RGB24%3AFC0D7200D2.initialDeclarations preserve=yes
  //## end CLMSector_RGB24%3AFC0D7200D2.initialDeclarations

  public:
    //## Constructors (generated)
      CLMSector_RGB24();

    //## Destructor (generated)
      ~CLMSector_RGB24();


    //## Other Operations (specified)
      //## Operation: GetValue%989597151
      virtual CSectElem & GetValue (int _X, int _Y);

      //## Operation: SetValue%989597152
      virtual void SetValue (int _X, int _Y, CSectElem &_Value);

      //## Operation: CreateClass%989597154
      virtual CSector * CreateClass ();

      //## Operation: ElemArraySize%989667595
      virtual unsigned long ElemArraySize (int _iResolution);

      //## Operation: GetLODData%995233498
      //	Gets the raw data of a given LOD
      virtual void GetLODData (int _iLOD, void *_pData);

    // Additional Public Declarations
      //## begin CLMSector_RGB24%3AFC0D7200D2.public preserve=yes
      //## end CLMSector_RGB24%3AFC0D7200D2.public

  protected:
    // Additional Protected Declarations
      //## begin CLMSector_RGB24%3AFC0D7200D2.protected preserve=yes
      //## end CLMSector_RGB24%3AFC0D7200D2.protected

  private:
    // Additional Private Declarations
      //## begin CLMSector_RGB24%3AFC0D7200D2.private preserve=yes
      //## end CLMSector_RGB24%3AFC0D7200D2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLMSector_RGB24%3AFC0D7200D2.implementation preserve=yes
      //## end CLMSector_RGB24%3AFC0D7200D2.implementation

};

//## begin CLMSector_RGB24%3AFC0D7200D2.postscript preserve=yes
//## end CLMSector_RGB24%3AFC0D7200D2.postscript

// Class CLMSector_RGB24 

//## begin module%3AFC0D7200D2.epilog preserve=yes
//## end module%3AFC0D7200D2.epilog


#endif
