//## begin module%3AF878DE0320.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF878DE0320.cm

//## begin module%3AF878DE0320.cp preserve=no
//## end module%3AF878DE0320.cp

//## Module: CHFSector_FN%3AF878DE0320; Pseudo Package specification
//## Source file: i:\Projects\GammaE\TerrainData\Sector\HeightField\CHFSector_FN.h

#ifndef CHFSector_FN_h
#define CHFSector_FN_h 1

//## begin module%3AF878DE0320.additionalIncludes preserve=no
//## end module%3AF878DE0320.additionalIncludes

//## begin module%3AF878DE0320.includes preserve=yes
//## end module%3AF878DE0320.includes

// CHFSector
#include "TerrainData\Sector\CHFSector.h"
//## begin module%3AF878DE0320.additionalDeclarations preserve=yes
//## end module%3AF878DE0320.additionalDeclarations


//## begin CHFSector_FN%3AF878DE0320.preface preserve=yes
//## end CHFSector_FN%3AF878DE0320.preface

//## Class: CHFSector_FN%3AF878DE0320
//## Category: TerrainData::Sector::HeightField%3AF8795F0302
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHFSector_FN : public CHFSector  //## Inherits: <unnamed>%3AF878F5010E
{
  //## begin CHFSector_FN%3AF878DE0320.initialDeclarations preserve=yes
  //## end CHFSector_FN%3AF878DE0320.initialDeclarations

  public:
    //## Constructors (generated)
      CHFSector_FN();

    //## Destructor (generated)
      ~CHFSector_FN();


    //## Other Operations (specified)
      //## Operation: GetValue%989359135
      virtual CSectElem & GetValue (int _X, int _Y);

      //## Operation: SetValue%989359136
      virtual void SetValue (int _X, int _Y, CSectElem &_Value);

      //## Operation: CreateClass%989359138
      virtual CSector * CreateClass ();

      //## Operation: ElemArraySize%989667593
      virtual unsigned long ElemArraySize (int _iResolution);

      //## Operation: GetLODData%995233497
      //	Gets the raw data of a given LOD
      virtual void GetLODData (int _iLOD, void *_pData);

      //## Operation: GetValueF%1026770434
      virtual CSectElem & GetValueF (float _fX, float _fY);

    // Additional Public Declarations
      //## begin CHFSector_FN%3AF878DE0320.public preserve=yes
      //## end CHFSector_FN%3AF878DE0320.public

  protected:
    // Additional Protected Declarations
      //## begin CHFSector_FN%3AF878DE0320.protected preserve=yes
      //## end CHFSector_FN%3AF878DE0320.protected

  private:
    // Additional Private Declarations
      //## begin CHFSector_FN%3AF878DE0320.private preserve=yes
      //## end CHFSector_FN%3AF878DE0320.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHFSector_FN%3AF878DE0320.implementation preserve=yes
      //## end CHFSector_FN%3AF878DE0320.implementation

};

//## begin CHFSector_FN%3AF878DE0320.postscript preserve=yes
//## end CHFSector_FN%3AF878DE0320.postscript

// Class CHFSector_FN 

//## begin module%3AF878DE0320.epilog preserve=yes
//## end module%3AF878DE0320.epilog


#endif
