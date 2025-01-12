//## begin module%3C4D994901BD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C4D994901BD.cm

//## begin module%3C4D994901BD.cp preserve=no
//## end module%3C4D994901BD.cp

//## Module: CGraphBV_Point%3C4D994901BD; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV_Point.h

#ifndef CGraphBV_Point_h
#define CGraphBV_Point_h 1

//## begin module%3C4D994901BD.additionalIncludes preserve=no
//## end module%3C4D994901BD.additionalIncludes

//## begin module%3C4D994901BD.includes preserve=yes
//## end module%3C4D994901BD.includes

// CGraphBV
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV.h"
//## begin module%3C4D994901BD.additionalDeclarations preserve=yes
//## end module%3C4D994901BD.additionalDeclarations


//## begin CGraphBV_Point%3C4D994901BD.preface preserve=yes
//## end CGraphBV_Point%3C4D994901BD.preface

//## Class: CGraphBV_Point%3C4D994901BD
//## Category: E3D::BoundingVolume::GraphBoundVol%3B7060820104
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGraphBV_Point : public CGraphBV  //## Inherits: <unnamed>%3C4D995C0387
{
  //## begin CGraphBV_Point%3C4D994901BD.initialDeclarations preserve=yes
  //## end CGraphBV_Point%3C4D994901BD.initialDeclarations

  public:
    //## Constructors (generated)
      CGraphBV_Point();

    //## Destructor (generated)
      ~CGraphBV_Point();


    //## Other Operations (specified)
      //## Operation: Transform%1011722634
      virtual void Transform (CMatrix4x4& M);

      //## Operation: Compute%1011722635
      virtual void Compute (CVect3* VXs, int iNumVXs);

      //## Operation: GetCenter%1011722636
      virtual CVect3 & GetCenter ();

      //## Operation: GetRange%1011722637
      virtual float GetRange (int iAxis);

      //## Operation: TestFrustum%1011722638
      virtual int TestFrustum (CE3D_Frustum& _Frustum);

      //## Operation: Init%1011722639
      virtual void Init (CVect3 Max, CVect3 Min);

      //## Operation: TestInside%1011722640
      virtual int TestInside (CVect3& _Pos);

      //## Operation: pGetPoint%1011722641
      CVect3 * pGetPoint ();

    // Additional Public Declarations
      //## begin CGraphBV_Point%3C4D994901BD.public preserve=yes
      //## end CGraphBV_Point%3C4D994901BD.public

  protected:
    // Additional Protected Declarations
      //## begin CGraphBV_Point%3C4D994901BD.protected preserve=yes
      //## end CGraphBV_Point%3C4D994901BD.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Point%3C4D9A6400B5
      //## begin CGraphBV_Point::Point%3C4D9A6400B5.attr preserve=no  private: CVect3 {UA} 
      CVect3 Point;
      //## end CGraphBV_Point::Point%3C4D9A6400B5.attr

    // Additional Private Declarations
      //## begin CGraphBV_Point%3C4D994901BD.private preserve=yes
      //## end CGraphBV_Point%3C4D994901BD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGraphBV_Point%3C4D994901BD.implementation preserve=yes
      //## end CGraphBV_Point%3C4D994901BD.implementation

};

//## begin CGraphBV_Point%3C4D994901BD.postscript preserve=yes
//## end CGraphBV_Point%3C4D994901BD.postscript

// Class CGraphBV_Point 

//## begin module%3C4D994901BD.epilog preserve=yes
//## end module%3C4D994901BD.epilog


#endif
