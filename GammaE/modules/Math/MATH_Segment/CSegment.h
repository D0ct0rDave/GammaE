//## begin module%3CC5D588008C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CC5D588008C.cm

//## begin module%3CC5D588008C.cp preserve=no
//## end module%3CC5D588008C.cp

//## Module: CSegment%3CC5D588008C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Segment\CSegment.h

#ifndef CSegment_h
#define CSegment_h 1

//## begin module%3CC5D588008C.additionalIncludes preserve=no
//## end module%3CC5D588008C.additionalIncludes

//## begin module%3CC5D588008C.includes preserve=yes
//## end module%3CC5D588008C.includes

// CVect3
#include "Math\MATH_Vector\CVect3.h"
//## begin module%3CC5D588008C.additionalDeclarations preserve=yes
//## end module%3CC5D588008C.additionalDeclarations


//## begin CSegment%3CC5D588008C.preface preserve=yes
//## end CSegment%3CC5D588008C.preface

//## Class: CSegment%3CC5D588008C
//## Category: Math::MATH_Segment%3CC5D57C00A3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CC5D5D4013F;CVect3 { -> }

class CSegment 
{
  //## begin CSegment%3CC5D588008C.initialDeclarations preserve=yes
  //## end CSegment%3CC5D588008C.initialDeclarations

  public:
    //## Constructors (generated)
      CSegment();


    //## Other Operations (specified)
      //## Operation: Init%1019598321
      void Init (CVect3& _roIni, CVect3& _roEnd);

      //## Operation: ProjectPoint%1019598322
      CVect3 ProjectPoint (CVect3& _roPoint);

    // Additional Public Declarations
      //## begin CSegment%3CC5D588008C.public preserve=yes
      //## end CSegment%3CC5D588008C.public

  protected:
    // Additional Protected Declarations
      //## begin CSegment%3CC5D588008C.protected preserve=yes
      //## end CSegment%3CC5D588008C.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: oIni%3CC5D59E01D8
      //## begin CSegment::oIni%3CC5D59E01D8.attr preserve=no  private: CVect3 {UA} 
      CVect3 oIni;
      //## end CSegment::oIni%3CC5D59E01D8.attr

      //## Attribute: oEnd%3CC5D5A50070
      //## begin CSegment::oEnd%3CC5D5A50070.attr preserve=no  private: CVect3 {UA} 
      CVect3 oEnd;
      //## end CSegment::oEnd%3CC5D5A50070.attr

    // Additional Private Declarations
      //## begin CSegment%3CC5D588008C.private preserve=yes
      //## end CSegment%3CC5D588008C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSegment%3CC5D588008C.implementation preserve=yes
      //## end CSegment%3CC5D588008C.implementation

};

//## begin CSegment%3CC5D588008C.postscript preserve=yes
//## end CSegment%3CC5D588008C.postscript

// Class CSegment 


//## Other Operations (inline)
inline void CSegment::Init (CVect3& _roIni, CVect3& _roEnd)
{
  //## begin CSegment::Init%1019598321.body preserve=yes
	oIni.Assign(_roIni);
	oEnd.Assign(_roEnd);
  //## end CSegment::Init%1019598321.body
}

//## begin module%3CC5D588008C.epilog preserve=yes
//## end module%3CC5D588008C.epilog


#endif
