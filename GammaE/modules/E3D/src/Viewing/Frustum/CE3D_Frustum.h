//## begin module%3BD7363100C9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD7363100C9.cm

//## begin module%3BD7363100C9.cp preserve=no
//## end module%3BD7363100C9.cp

//## Module: CE3D_Frustum%3BD7363100C9; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Viewing\Frustum\CE3D_Frustum.h

#ifndef CE3D_Frustum_h
#define CE3D_Frustum_h 1

//## begin module%3BD7363100C9.additionalIncludes preserve=no
//## end module%3BD7363100C9.additionalIncludes

//## begin module%3BD7363100C9.includes preserve=yes
//## end module%3BD7363100C9.includes

// CE3D_Projector
#include "E3D\Viewing\Projector\CE3D_Projector.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3BD7363100C9.additionalDeclarations preserve=yes
//## end module%3BD7363100C9.additionalDeclarations


//## begin CE3D_Frustum%3BD7363100C9.preface preserve=yes
//## end CE3D_Frustum%3BD7363100C9.preface

//## Class: CE3D_Frustum%3BD7363100C9
//## Category: E3D::Viewing::Frustum%3A9AD68301A4
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BD7417C038D;CE3D_Projector { -> }
//## Uses: <unnamed>%3BD8A11D0153;GammaE_Math { -> }

class CE3D_Frustum 
{
  //## begin CE3D_Frustum%3BD7363100C9.initialDeclarations preserve=yes
  //## end CE3D_Frustum%3BD7363100C9.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_Frustum();

    //## Destructor (generated)
      ~CE3D_Frustum();


    //## Other Operations (specified)
      //## Operation: Compute%1003953253
      void Compute (CE3D_Projector *_Projector, float _fRatio);

      //## Operation: GetPlane%1003953255
      CPlane & GetPlane (int iPlane);

      //## Operation: TestBBox%1003953256
      int TestBBox (CVect3& Maxs, CVect3 &Mins);

      //## Operation: TestSphere%1003953257
      int TestSphere (float Radius, CVect3 &Center);

      //## Operation: TestPoint%1011722642
      int TestPoint (CVect3& _roPoint);

      //## Operation: Transform%1006987065
      void Transform (CMatrix4x4 &_Transf);

      //## Operation: Copy%1006987066
      void Copy (CE3D_Frustum &_pFrust);

    // Additional Public Declarations
      //## begin CE3D_Frustum%3BD7363100C9.public preserve=yes
      //## end CE3D_Frustum%3BD7363100C9.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_Frustum%3BD7363100C9.protected preserve=yes
      //## end CE3D_Frustum%3BD7363100C9.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Plane%3BD7368802B9
      //## begin CE3D_Frustum::Plane%3BD7368802B9.attr preserve=no  private: CPlane[6] {UA} 
      CPlane Plane[6];
      //## end CE3D_Frustum::Plane%3BD7368802B9.attr

    // Additional Private Declarations
      //## begin CE3D_Frustum%3BD7363100C9.private preserve=yes
      //## end CE3D_Frustum%3BD7363100C9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_Frustum%3BD7363100C9.implementation preserve=yes
      //## end CE3D_Frustum%3BD7363100C9.implementation

};

//## begin CE3D_Frustum%3BD7363100C9.postscript preserve=yes
//## end CE3D_Frustum%3BD7363100C9.postscript

// Class CE3D_Frustum 

//## begin module%3BD7363100C9.epilog preserve=yes
//## end module%3BD7363100C9.epilog


#endif
