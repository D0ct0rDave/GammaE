//## begin module%3B55F49C00F0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B55F49C00F0.cm

//## begin module%3B55F49C00F0.cp preserve=no
//## end module%3B55F49C00F0.cp

//## Module: CBoundingSphere%3B55F49C00F0; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\CBoundingSphere.h

#ifndef CBoundingSphere_h
#define CBoundingSphere_h 1

//## begin module%3B55F49C00F0.additionalIncludes preserve=no
//## end module%3B55F49C00F0.additionalIncludes

//## begin module%3B55F49C00F0.includes preserve=yes
//## end module%3B55F49C00F0.includes

// CBoundingVolume
#include "E3D\BoundingVolume\CBoundingVolume.h"
//## begin module%3B55F49C00F0.additionalDeclarations preserve=yes

//			y
//			|
//          |
//			|
//     Center----- x
//		   /
//        /
//	     z
//---------------------------------------------------------------------------

//## end module%3B55F49C00F0.additionalDeclarations


//## begin CBoundingSphere%3B55F49C00F0.preface preserve=yes
//## end CBoundingSphere%3B55F49C00F0.preface

//## Class: CBoundingSphere%3B55F49C00F0
//## Category: E3D::BoundingVolume%3AA3F01B0168
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CBoundingSphere : public CBoundingVolume  //## Inherits: <unnamed>%3B70626E0078
{
  //## begin CBoundingSphere%3B55F49C00F0.initialDeclarations preserve=yes
  //## end CBoundingSphere%3B55F49C00F0.initialDeclarations

  public:
    //## Constructors (generated)
      CBoundingSphere();

    //## Destructor (generated)
      ~CBoundingSphere();


    //## Other Operations (specified)
      //## Operation: Init%997221286
      void Init (CVect3 _Center, float _fRadius);

      //## Operation: Init%997221303
      virtual void Init (CVect3& Max, CVect3& Min);

    // Data Members for Class Attributes

      //## Attribute: Center%3B55F4AF02A8
      //## begin CBoundingSphere::Center%3B55F4AF02A8.attr preserve=no  public: CVect3 {UA} 
      CVect3 Center;
      //## end CBoundingSphere::Center%3B55F4AF02A8.attr

      //## Attribute: Radius%3B55F4BC0172
      //## begin CBoundingSphere::Radius%3B55F4BC0172.attr preserve=no  public: float {UA} 
      float Radius;
      //## end CBoundingSphere::Radius%3B55F4BC0172.attr

    // Additional Public Declarations
      //## begin CBoundingSphere%3B55F49C00F0.public preserve=yes
      //## end CBoundingSphere%3B55F49C00F0.public

  protected:
    // Additional Protected Declarations
      //## begin CBoundingSphere%3B55F49C00F0.protected preserve=yes
      //## end CBoundingSphere%3B55F49C00F0.protected

  private:
    // Additional Private Declarations
      //## begin CBoundingSphere%3B55F49C00F0.private preserve=yes
      //## end CBoundingSphere%3B55F49C00F0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CBoundingSphere%3B55F49C00F0.implementation preserve=yes
      //## end CBoundingSphere%3B55F49C00F0.implementation

};

//## begin CBoundingSphere%3B55F49C00F0.postscript preserve=yes
//## end CBoundingSphere%3B55F49C00F0.postscript

// Class CBoundingSphere 

//## begin module%3B55F49C00F0.epilog preserve=yes
//## end module%3B55F49C00F0.epilog


#endif
