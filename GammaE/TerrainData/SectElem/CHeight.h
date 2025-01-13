//## begin module%3AF508690258.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF508690258.cm

//## begin module%3AF508690258.cp preserve=no
//## end module%3AF508690258.cp

//## Module: CHeight%3AF508690258; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\SectElem\CHeight.h

#ifndef CHeight_h
#define CHeight_h 1

//## begin module%3AF508690258.additionalIncludes preserve=no
//## end module%3AF508690258.additionalIncludes

//## begin module%3AF508690258.includes preserve=yes
//## end module%3AF508690258.includes

// CSectElem
#include "TerrainData\SectElem\CSectElem.h"
//## begin module%3AF508690258.additionalDeclarations preserve=yes
//## end module%3AF508690258.additionalDeclarations


//## begin CHeight%3AF508690258.preface preserve=yes
//## end CHeight%3AF508690258.preface

//## Class: CHeight%3AF508690258
//## Category: TerrainData::SectElem%3AF50839032A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHeight : public CSectElem  //## Inherits: <unnamed>%3AF50883019A
{
  //## begin CHeight%3AF508690258.initialDeclarations preserve=yes
  //## end CHeight%3AF508690258.initialDeclarations

  public:
    //## Constructors (generated)
      CHeight();

    //## Destructor (generated)
      ~CHeight();


    //## Other Operations (specified)
      //## Operation: ByteSize%989139158
      virtual unsigned long ByteSize ();

      //## Operation: Sum%989139165
      virtual CSectElem & Sum (CSectElem &a, CSectElem &b);

      //## Operation: Mult%989139166
      virtual CSectElem & Mult (CSectElem &a, CSectElem &b);

      //## Operation: LinInterpolate%989139167
      virtual CSectElem & LinInterpolate (CSectElem &a, CSectElem &b, float fFactor);

      //## Operation: CosInterpolate%989139168
      virtual CSectElem & CosInterpolate (CSectElem &a, CSectElem &b, float fFactor);

      //## Operation: Get%989139179
      virtual void * Get ();

      //## Operation: Set%989139180
      virtual void Set (void *_Value);

      //## Operation: CreateClass%991155098
      virtual CSectElem * CreateClass ();

      //## Operation: Clear%991155107
      virtual CSectElem & Clear ();

      //## Operation: Add%991155117
      virtual CSectElem & Add (CSectElem &a);

      //## Operation: Mult%991155118
      virtual CSectElem & Mult (CSectElem &a);

      //## Operation: Scale%991155119
      virtual CSectElem & Scale (float a);

    // Additional Public Declarations
      //## begin CHeight%3AF508690258.public preserve=yes
      //## end CHeight%3AF508690258.public

  protected:
    // Additional Protected Declarations
      //## begin CHeight%3AF508690258.protected preserve=yes
      //## end CHeight%3AF508690258.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Value%3AF50ED60230
      //## begin CHeight::Value%3AF50ED60230.attr preserve=no  private: float {UA} 
      float Value;
      //## end CHeight::Value%3AF50ED60230.attr

    // Additional Private Declarations
      //## begin CHeight%3AF508690258.private preserve=yes
      //## end CHeight%3AF508690258.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHeight%3AF508690258.implementation preserve=yes
      //## end CHeight%3AF508690258.implementation

};

//## begin CHeight%3AF508690258.postscript preserve=yes
//## end CHeight%3AF508690258.postscript

// Class CHeight 


//## Other Operations (inline)
inline void * CHeight::Get ()
{
  //## begin CHeight::Get%989139179.body preserve=yes
  	return((void*)&Value);
  //## end CHeight::Get%989139179.body
}

inline void CHeight::Set (void *_Value)
{
  //## begin CHeight::Set%989139180.body preserve=yes
  	Value = *(float*)_Value;
  //## end CHeight::Set%989139180.body
}

//## begin module%3AF508690258.epilog preserve=yes
//## end module%3AF508690258.epilog


#endif
