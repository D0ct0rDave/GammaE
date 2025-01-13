//## begin module%3AFD246C0316.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFD246C0316.cm

//## begin module%3AFD246C0316.cp preserve=no
//## end module%3AFD246C0316.cp

//## Module: CLMSector_Pal%3AFD246C0316; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\Sector\LightMap\CLMSector_Pal.h

#ifndef CLMSector_Pal_h
#define CLMSector_Pal_h 1

//## begin module%3AFD246C0316.additionalIncludes preserve=no
//## end module%3AFD246C0316.additionalIncludes

//## begin module%3AFD246C0316.includes preserve=yes
//## end module%3AFD246C0316.includes

// CLMSector
#include "TerrainData\Sector\CLMSector.h"
//## begin module%3AFD246C0316.additionalDeclarations preserve=yes
//## end module%3AFD246C0316.additionalDeclarations


//## begin CLMSector_Pal%3AFD246C0316.preface preserve=yes
//## end CLMSector_Pal%3AFD246C0316.preface

//## Class: CLMSector_Pal%3AFD246C0316
//## Category: TerrainData::Sector::LightMap%3AFC0D5A01AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLMSector_Pal : public CLMSector  //## Inherits: <unnamed>%3AFD247F038E
{
  //## begin CLMSector_Pal%3AFD246C0316.initialDeclarations preserve=yes
  //## end CLMSector_Pal%3AFD246C0316.initialDeclarations

  public:
    //## Constructors (generated)
      CLMSector_Pal();

    //## Destructor (generated)
      ~CLMSector_Pal();


    //## Other Operations (specified)
      //## Operation: GetValue%989667589
      virtual CSectElem & GetValue (int _X, int _Y);

      //## Operation: SetValue%989667590
      virtual void SetValue (int _X, int _Y, CSectElem &_Value);

      //## Operation: DataSize%989667591
      virtual unsigned long DataSize ();

      //## Operation: CreateClass%989667592
      virtual CSector * CreateClass ();

      //## Operation: set_Pal%989667598
      void set_Pal (char *_Pal);

      //## Operation: ElemArraySize%989667599
      virtual unsigned long ElemArraySize (int _iResolution);

    // Additional Public Declarations
      //## begin CLMSector_Pal%3AFD246C0316.public preserve=yes
      //## end CLMSector_Pal%3AFD246C0316.public

  protected:
    // Additional Protected Declarations
      //## begin CLMSector_Pal%3AFD246C0316.protected preserve=yes
      //## end CLMSector_Pal%3AFD246C0316.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Pal%3AFD24820064
      //## begin CLMSector_Pal::Pal%3AFD24820064.attr preserve=no  private: char[768] {UA} 
      char Pal[768];
      //## end CLMSector_Pal::Pal%3AFD24820064.attr

    // Additional Private Declarations
      //## begin CLMSector_Pal%3AFD246C0316.private preserve=yes
      //## end CLMSector_Pal%3AFD246C0316.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLMSector_Pal%3AFD246C0316.implementation preserve=yes
      //## end CLMSector_Pal%3AFD246C0316.implementation

};

//## begin CLMSector_Pal%3AFD246C0316.postscript preserve=yes
//## end CLMSector_Pal%3AFD246C0316.postscript

// Class CLMSector_Pal 

//## begin module%3AFD246C0316.epilog preserve=yes
//## end module%3AFD246C0316.epilog


#endif
