//## begin module%3B70604F01C2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B70604F01C2.cm

//## begin module%3B70604F01C2.cp preserve=no
//## end module%3B70604F01C2.cp

//## Module: CBoundingVolume%3B70604F01C2; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\CBoundingVolume.h

#ifndef CBoundingVolume_h
#define CBoundingVolume_h 1

//## begin module%3B70604F01C2.additionalIncludes preserve=no
//## end module%3B70604F01C2.additionalIncludes

//## begin module%3B70604F01C2.includes preserve=yes
//## end module%3B70604F01C2.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3B70604F01C2.additionalDeclarations preserve=yes
//## end module%3B70604F01C2.additionalDeclarations


//## begin CBoundingVolume%3B70604F01C2.preface preserve=yes
//## end CBoundingVolume%3B70604F01C2.preface

//## Class: CBoundingVolume%3B70604F01C2
//## Category: E3D::BoundingVolume%3AA3F01B0168
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BD8A1520254;GammaE_Math { -> }

class CBoundingVolume 
{
  //## begin CBoundingVolume%3B70604F01C2.initialDeclarations preserve=yes
  //## end CBoundingVolume%3B70604F01C2.initialDeclarations

  public:
    //## Constructors (generated)
      CBoundingVolume();

    //## Destructor (generated)
      ~CBoundingVolume();


    //## Other Operations (specified)
      //## Operation: Init%997221304
      virtual void Init (CVect3& Max, CVect3& Min);

    // Additional Public Declarations
      //## begin CBoundingVolume%3B70604F01C2.public preserve=yes
      //## end CBoundingVolume%3B70604F01C2.public

  protected:
    // Additional Protected Declarations
      //## begin CBoundingVolume%3B70604F01C2.protected preserve=yes
      //## end CBoundingVolume%3B70604F01C2.protected

  private:
    // Additional Private Declarations
      //## begin CBoundingVolume%3B70604F01C2.private preserve=yes
      //## end CBoundingVolume%3B70604F01C2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CBoundingVolume%3B70604F01C2.implementation preserve=yes
      //## end CBoundingVolume%3B70604F01C2.implementation

};

//## begin CBoundingVolume%3B70604F01C2.postscript preserve=yes
//## end CBoundingVolume%3B70604F01C2.postscript

// Class CBoundingVolume 

//## begin module%3B70604F01C2.epilog preserve=yes
//## end module%3B70604F01C2.epilog


#endif
