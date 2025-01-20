//## begin module%3AF50861008C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF50861008C.cm

//## begin module%3AF50861008C.cp preserve=no
//## end module%3AF50861008C.cp

//## Module: CSectElem%3AF50861008C; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\SectElem\CSectElem.h

#ifndef CSectElem_h
#define CSectElem_h 1

//## begin module%3AF50861008C.additionalIncludes preserve=no
//## end module%3AF50861008C.additionalIncludes

//## begin module%3AF50861008C.includes preserve=yes
//## end module%3AF50861008C.includes

//## begin module%3AF50861008C.additionalDeclarations preserve=yes
#include <math.h>
#include "math/gammae_math.h"
//## end module%3AF50861008C.additionalDeclarations


//## begin CSectElem%3AF50861008C.preface preserve=yes
//## end CSectElem%3AF50861008C.preface

//## Class: CSectElem%3AF50861008C
//## Category: TerrainData::SectElem%3AF50839032A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSectElem 
{
  //## begin CSectElem%3AF50861008C.initialDeclarations preserve=yes
  //## end CSectElem%3AF50861008C.initialDeclarations

  public:
    //## Constructors (generated)
      CSectElem();

    //## Destructor (generated)
      ~CSectElem();


    //## Other Operations (specified)
      //## Operation: ByteSize%989139155
      virtual unsigned long ByteSize () = 0;

      //## Operation: Sum%989139161
      virtual CSectElem & Sum (CSectElem &a, CSectElem &b);

      //## Operation: Mult%989139162
      virtual CSectElem & Mult (CSectElem &a, CSectElem &b);

      //## Operation: LinInterpolate%989139163
      virtual CSectElem & LinInterpolate (CSectElem &a, CSectElem &b, float fFactor);

      //## Operation: CosInterpolate%989139164
      virtual CSectElem & CosInterpolate (CSectElem &a, CSectElem &b, float fFactor);

      //## Operation: Get%989139177
      virtual void * Get () = 0;

      //## Operation: Set%989139178
      virtual void Set (void *_Value) = 0;

      //## Operation: CreateClass%991155099
      virtual CSectElem * CreateClass () = 0;

      //## Operation: Clear%991155103
      virtual CSectElem & Clear ();

      //## Operation: Add%991155108
      virtual CSectElem & Add (CSectElem &a);

      //## Operation: Mult%991155109
      virtual CSectElem & Mult (CSectElem &a);

      //## Operation: Scale%991155110
      virtual CSectElem & Scale (float a);

    // Additional Public Declarations
      //## begin CSectElem%3AF50861008C.public preserve=yes
      //## end CSectElem%3AF50861008C.public

  protected:
    // Additional Protected Declarations
      //## begin CSectElem%3AF50861008C.protected preserve=yes
      //## end CSectElem%3AF50861008C.protected

  private:
    // Additional Private Declarations
      //## begin CSectElem%3AF50861008C.private preserve=yes
      //## end CSectElem%3AF50861008C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSectElem%3AF50861008C.implementation preserve=yes
      //## end CSectElem%3AF50861008C.implementation

};

//## begin CSectElem%3AF50861008C.postscript preserve=yes
//## end CSectElem%3AF50861008C.postscript

// Class CSectElem 

//## begin module%3AF50861008C.epilog preserve=yes
//## end module%3AF50861008C.epilog


#endif
