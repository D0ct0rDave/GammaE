//## begin module%3B55F43401AE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B55F43401AE.cm

//## begin module%3B55F43401AE.cp preserve=no
//## end module%3B55F43401AE.cp

//## Module: CBoundingBox%3B55F43401AE; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\CBoundingBox.h

#ifndef CBoundingBox_h
#define CBoundingBox_h 1

//## begin module%3B55F43401AE.additionalIncludes preserve=no
//## end module%3B55F43401AE.additionalIncludes

//## begin module%3B55F43401AE.includes preserve=yes
//## end module%3B55F43401AE.includes

// CBoundingVolume
#include "E3D\BoundingVolume\CBoundingVolume.h"
//## begin module%3B55F43401AE.additionalDeclarations preserve=yes

//---------------------------------------------------------------------------
//			  e---f
//           /|  /|
//			a-g-b h
//          |/  |/
//          c---d
//---------------------------------------------------------------------------

//## end module%3B55F43401AE.additionalDeclarations


//## begin CBoundingBox%3B55F43401AE.preface preserve=yes
//## end CBoundingBox%3B55F43401AE.preface

//## Class: CBoundingBox%3B55F43401AE
//## Category: E3D::BoundingVolume%3AA3F01B0168
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CBoundingBox : public CBoundingVolume  //## Inherits: <unnamed>%3B70626C00BE
{
  //## begin CBoundingBox%3B55F43401AE.initialDeclarations preserve=yes
  //## end CBoundingBox%3B55F43401AE.initialDeclarations

  public:
    //## Constructors (generated)
      CBoundingBox();

    //## Destructor (generated)
      ~CBoundingBox();


    //## Other Operations (specified)
      //## Operation: Init%995837647
      void Init (CVect3& Max, CVect3& Min);

    // Data Members for Class Attributes

      //## Attribute: Maxs%3B55F4650140
      //## begin CBoundingBox::Maxs%3B55F4650140.attr preserve=no  public: CVect3 {UA} 
      CVect3 Maxs;
      //## end CBoundingBox::Maxs%3B55F4650140.attr

      //## Attribute: Mins%3B55F47002E4
      //## begin CBoundingBox::Mins%3B55F47002E4.attr preserve=no  public: CVect3 {UA} 
      CVect3 Mins;
      //## end CBoundingBox::Mins%3B55F47002E4.attr

      //## Attribute: Points%3B55F4750316
      //## begin CBoundingBox::Points%3B55F4750316.attr preserve=no  public: CVect3[8] {UA} 
      CVect3 Points[8];
      //## end CBoundingBox::Points%3B55F4750316.attr

    // Additional Public Declarations
      //## begin CBoundingBox%3B55F43401AE.public preserve=yes
      //## end CBoundingBox%3B55F43401AE.public

  protected:
    // Additional Protected Declarations
      //## begin CBoundingBox%3B55F43401AE.protected preserve=yes
      //## end CBoundingBox%3B55F43401AE.protected

  private:
    // Additional Private Declarations
      //## begin CBoundingBox%3B55F43401AE.private preserve=yes
      //## end CBoundingBox%3B55F43401AE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CBoundingBox%3B55F43401AE.implementation preserve=yes
      //## end CBoundingBox%3B55F43401AE.implementation

};

//## begin CBoundingBox%3B55F43401AE.postscript preserve=yes
//## end CBoundingBox%3B55F43401AE.postscript

// Class CBoundingBox 

//## begin module%3B55F43401AE.epilog preserve=yes
//## end module%3B55F43401AE.epilog


#endif
