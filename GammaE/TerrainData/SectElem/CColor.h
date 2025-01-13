//## begin module%3AF5087A0014.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF5087A0014.cm

//## begin module%3AF5087A0014.cp preserve=no
//## end module%3AF5087A0014.cp

//## Module: CColor%3AF5087A0014; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\SectElem\CColor.h

#ifndef CColor_h
#define CColor_h 1

//## begin module%3AF5087A0014.additionalIncludes preserve=no
//## end module%3AF5087A0014.additionalIncludes

//## begin module%3AF5087A0014.includes preserve=yes
//## end module%3AF5087A0014.includes

// CSectElem
#include "TerrainData\SectElem\CSectElem.h"
//## begin module%3AF5087A0014.additionalDeclarations preserve=yes
//## end module%3AF5087A0014.additionalDeclarations


//## begin CColor%3AF5087A0014.preface preserve=yes
//## end CColor%3AF5087A0014.preface

//## Class: CColor%3AF5087A0014
//## Category: TerrainData::SectElem%3AF50839032A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CColor : public CSectElem  //## Inherits: <unnamed>%3AF5088800BE
{
  //## begin CColor%3AF5087A0014.initialDeclarations preserve=yes
  //## end CColor%3AF5087A0014.initialDeclarations

  public:
    //## Constructors (generated)
      CColor();

    //## Destructor (generated)
      ~CColor();


    //## Other Operations (specified)
      //## Operation: ByteSize%989139159
      virtual unsigned long ByteSize ();

      //## Operation: Sum%989139169
      virtual CSectElem & Sum (CSectElem &a, CSectElem &b);

      //## Operation: Mult%989139170
      virtual CSectElem & Mult (CSectElem &a, CSectElem &b);

      //## Operation: LinInterpolate%989139171
      virtual CSectElem & LinInterpolate (CSectElem &a, CSectElem &b, float fFactor);

      //## Operation: CosInterpolate%989139172
      virtual CSectElem & CosInterpolate (CSectElem &a, CSectElem &b, float fFactor);

      //## Operation: Get%989139181
      virtual void * Get ();

      //## Operation: Set%989139182
      virtual void Set (void *_Value);

      //## Operation: CreateClass%991155101
      virtual CSectElem * CreateClass ();

      //## Operation: Clear%991155105
      virtual CSectElem & Clear ();

      //## Operation: Add%991155111
      virtual CSectElem & Add (CSectElem &a);

      //## Operation: Mult%991155112
      virtual CSectElem & Mult (CSectElem &a);

      //## Operation: Scale%991155113
      virtual CSectElem & Scale (float a);

    // Additional Public Declarations
      //## begin CColor%3AF5087A0014.public preserve=yes
      //## end CColor%3AF5087A0014.public

  protected:
    // Additional Protected Declarations
      //## begin CColor%3AF5087A0014.protected preserve=yes
      //## end CColor%3AF5087A0014.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Value%3AF50EFE0294
      //## begin CColor::Value%3AF50EFE0294.attr preserve=no  private: float[4] {UA} 
      float Value[4];
      //## end CColor::Value%3AF50EFE0294.attr

    // Additional Private Declarations
      //## begin CColor%3AF5087A0014.private preserve=yes
      //## end CColor%3AF5087A0014.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CColor%3AF5087A0014.implementation preserve=yes
      //## end CColor%3AF5087A0014.implementation

};

//## begin CColor%3AF5087A0014.postscript preserve=yes
//## end CColor%3AF5087A0014.postscript

// Class CColor 


//## Other Operations (inline)
inline void * CColor::Get ()
{
  //## begin CColor::Get%989139181.body preserve=yes
  	return((void*)Value);
  //## end CColor::Get%989139181.body
}

inline void CColor::Set (void *_Value)
{
  //## begin CColor::Set%989139182.body preserve=yes
	Value[0] = ((float *)_Value)[0];
	Value[1] = ((float *)_Value)[1];
	Value[2] = ((float *)_Value)[2];
	Value[3] = ((float *)_Value)[3];
  //## end CColor::Set%989139182.body
}

//## begin module%3AF5087A0014.epilog preserve=yes
//## end module%3AF5087A0014.epilog


#endif
