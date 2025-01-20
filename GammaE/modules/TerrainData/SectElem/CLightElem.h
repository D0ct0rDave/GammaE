//## begin module%3AF508750276.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF508750276.cm

//## begin module%3AF508750276.cp preserve=no
//## end module%3AF508750276.cp

//## Module: CLightElem%3AF508750276; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\SectElem\CLightElem.h

#ifndef CLightElem_h
#define CLightElem_h 1

//## begin module%3AF508750276.additionalIncludes preserve=no
//## end module%3AF508750276.additionalIncludes

//## begin module%3AF508750276.includes preserve=yes
//## end module%3AF508750276.includes

// CSectElem
#include "TerrainData\SectElem\CSectElem.h"
//## begin module%3AF508750276.additionalDeclarations preserve=yes
//## end module%3AF508750276.additionalDeclarations


//## begin CLightElem%3AF508750276.preface preserve=yes
//## end CLightElem%3AF508750276.preface

//## Class: CLightElem%3AF508750276
//## Category: TerrainData::SectElem%3AF50839032A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLightElem : public CSectElem  //## Inherits: <unnamed>%3AF508850294
{
  //## begin CLightElem%3AF508750276.initialDeclarations preserve=yes
  //## end CLightElem%3AF508750276.initialDeclarations

  public:
    //## Constructors (generated)
      CLightElem();

    //## Destructor (generated)
      ~CLightElem();


    //## Other Operations (specified)
      //## Operation: ByteSize%989139160
      virtual unsigned long ByteSize ();

      //## Operation: Sum%989139173
      virtual CSectElem & Sum (CSectElem &a, CSectElem &b);

      //## Operation: Mult%989139174
      virtual CSectElem & Mult (CSectElem &a, CSectElem &b);

      //## Operation: LinInterpolate%989139175
      virtual CSectElem & LinInterpolate (CSectElem &a, CSectElem &b, float fFactor);

      //## Operation: CosInterpolate%989139176
      virtual CSectElem & CosInterpolate (CSectElem &a, CSectElem &b, float fFactor);

      //## Operation: Get%989139183
      virtual void * Get ();

      //## Operation: Set%989139184
      virtual void Set (void *_Value);

      //## Operation: CreateClass%991155100
      virtual CSectElem * CreateClass ();

      //## Operation: Clear%991155106
      virtual CSectElem & Clear ();

      //## Operation: Add%991155114
      virtual CSectElem & Add (CSectElem &a);

      //## Operation: Mult%991155115
      virtual CSectElem & Mult (CSectElem &a);

      //## Operation: Scale%991155116
      virtual CSectElem & Scale (float a);

    // Additional Public Declarations
      //## begin CLightElem%3AF508750276.public preserve=yes
      //## end CLightElem%3AF508750276.public

  protected:
    // Additional Protected Declarations
      //## begin CLightElem%3AF508750276.protected preserve=yes
      //## end CLightElem%3AF508750276.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Value%3AF50EEA03DE
      //## begin CLightElem::Value%3AF50EEA03DE.attr preserve=no  private: float[3] {UA} 
      float Value[3];
      //## end CLightElem::Value%3AF50EEA03DE.attr

    // Additional Private Declarations
      //## begin CLightElem%3AF508750276.private preserve=yes
      //## end CLightElem%3AF508750276.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLightElem%3AF508750276.implementation preserve=yes
      //## end CLightElem%3AF508750276.implementation

};

//## begin CLightElem%3AF508750276.postscript preserve=yes
//## end CLightElem%3AF508750276.postscript

// Class CLightElem 


//## Other Operations (inline)
inline void * CLightElem::Get ()
{
  //## begin CLightElem::Get%989139183.body preserve=yes
	return((void *)&Value);
  //## end CLightElem::Get%989139183.body
}

inline void CLightElem::Set (void *_Value)
{
  //## begin CLightElem::Set%989139184.body preserve=yes
  	Value[0] = ((float *)(_Value))[0];
	Value[1] = ((float *)(_Value))[1];
	Value[2] = ((float *)(_Value))[2];
  //## end CLightElem::Set%989139184.body
}

//## begin module%3AF508750276.epilog preserve=yes
//## end module%3AF508750276.epilog


#endif
