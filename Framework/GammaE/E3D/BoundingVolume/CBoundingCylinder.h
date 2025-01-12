//## begin module%3B55F4DC0154.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B55F4DC0154.cm

//## begin module%3B55F4DC0154.cp preserve=no
//## end module%3B55F4DC0154.cp

//## Module: CBoundingCylinder%3B55F4DC0154; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\CBoundingCylinder.h

#ifndef CBoundingCylinder_h
#define CBoundingCylinder_h 1

//## begin module%3B55F4DC0154.additionalIncludes preserve=no
//## end module%3B55F4DC0154.additionalIncludes

//## begin module%3B55F4DC0154.includes preserve=yes
//## end module%3B55F4DC0154.includes

// CBoundingVolume
#include "E3D\BoundingVolume\CBoundingVolume.h"
//## begin module%3B55F4DC0154.additionalDeclarations preserve=yes
//## end module%3B55F4DC0154.additionalDeclarations


//## begin CBoundingCylinder%3B55F4DC0154.preface preserve=yes
//## end CBoundingCylinder%3B55F4DC0154.preface

//## Class: CBoundingCylinder%3B55F4DC0154
//## Category: E3D::BoundingVolume%3AA3F01B0168
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CBoundingCylinder : public CBoundingVolume  //## Inherits: <unnamed>%3B706270005A
{
  //## begin CBoundingCylinder%3B55F4DC0154.initialDeclarations preserve=yes
  //## end CBoundingCylinder%3B55F4DC0154.initialDeclarations

  public:
    //## Constructors (generated)
      CBoundingCylinder();

    //## Destructor (generated)
      ~CBoundingCylinder();


    //## Other Operations (specified)
      //## Operation: Init%995837639
      void Init (CVect3 &_Center, float _Radius, float _Height);

      //## Operation: Init%997221302
      virtual void Init (CVect3& Max, CVect3& Min);

    // Data Members for Class Attributes

      //## Attribute: Center%3B55F4F40154
      //## begin CBoundingCylinder::Center%3B55F4F40154.attr preserve=no  public: CVect3 {UA} 
      CVect3 Center;
      //## end CBoundingCylinder::Center%3B55F4F40154.attr

      //## Attribute: Radius%3B55F5030262
      //## begin CBoundingCylinder::Radius%3B55F5030262.attr preserve=no  public: float {UA} 
      float Radius;
      //## end CBoundingCylinder::Radius%3B55F5030262.attr

      //## Attribute: Height%3B55F50701CC
      //## begin CBoundingCylinder::Height%3B55F50701CC.attr preserve=no  public: float {UA} 
      float Height;
      //## end CBoundingCylinder::Height%3B55F50701CC.attr

    // Additional Public Declarations
      //## begin CBoundingCylinder%3B55F4DC0154.public preserve=yes
      //## end CBoundingCylinder%3B55F4DC0154.public

  protected:
    // Additional Protected Declarations
      //## begin CBoundingCylinder%3B55F4DC0154.protected preserve=yes
      //## end CBoundingCylinder%3B55F4DC0154.protected

  private:
    // Additional Private Declarations
      //## begin CBoundingCylinder%3B55F4DC0154.private preserve=yes
      //## end CBoundingCylinder%3B55F4DC0154.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CBoundingCylinder%3B55F4DC0154.implementation preserve=yes
      //## end CBoundingCylinder%3B55F4DC0154.implementation

};

//## begin CBoundingCylinder%3B55F4DC0154.postscript preserve=yes
//## end CBoundingCylinder%3B55F4DC0154.postscript

// Class CBoundingCylinder 

//## begin module%3B55F4DC0154.epilog preserve=yes
//## end module%3B55F4DC0154.epilog


#endif
