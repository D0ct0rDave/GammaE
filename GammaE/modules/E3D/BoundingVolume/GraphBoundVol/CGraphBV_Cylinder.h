//## begin module%3B70658502F8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B70658502F8.cm

//## begin module%3B70658502F8.cp preserve=no
//## end module%3B70658502F8.cp

//## Module: CGraphBV_Cylinder%3B70658502F8; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV_Cylinder.h

#ifndef CGraphBV_Cylinder_h
#define CGraphBV_Cylinder_h 1

//## begin module%3B70658502F8.additionalIncludes preserve=no
//## end module%3B70658502F8.additionalIncludes

//## begin module%3B70658502F8.includes preserve=yes
//## end module%3B70658502F8.includes

// CGraphBV
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV.h"
// CBoundingCylinder
#include "E3D\BoundingVolume\CBoundingCylinder.h"
//## begin module%3B70658502F8.additionalDeclarations preserve=yes
//## end module%3B70658502F8.additionalDeclarations


//## begin CGraphBV_Cylinder%3B70658502F8.preface preserve=yes
//## end CGraphBV_Cylinder%3B70658502F8.preface

//## Class: CGraphBV_Cylinder%3B70658502F8
//## Category: E3D::BoundingVolume::GraphBoundVol%3B7060820104
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGraphBV_Cylinder : public CGraphBV  //## Inherits: <unnamed>%3B7065B103D4
{
  //## begin CGraphBV_Cylinder%3B70658502F8.initialDeclarations preserve=yes
  //## end CGraphBV_Cylinder%3B70658502F8.initialDeclarations

  public:
    //## Constructors (generated)
      CGraphBV_Cylinder();

    //## Destructor (generated)
      ~CGraphBV_Cylinder();


    //## Other Operations (specified)
      //## Operation: Transform%997221297
      virtual void Transform (CMatrix4x4& M);

      //## Operation: Compute%997221298
      virtual void Compute (CVect3* VXs, int iNumVXs);

      //## Operation: GetRange%997221299
      virtual float GetRange (int iAxis);

      //## Operation: GetCenter%997221300
      virtual CVect3 & GetCenter ();

      //## Operation: TestFrustum%997221301
      virtual int TestFrustum (CE3D_Frustum& _Frustum);

      //## Operation: Init%997221307
      virtual void Init (CVect3 Max, CVect3 Min);

      //## Operation: pGetCylinder%1000933014
      CBoundingCylinder * pGetCylinder ();

      //## Operation: TestInside%1006904824
      virtual int TestInside (CVect3& _Pos);

    // Data Members for Associations

      //## Association: E3D::BoundingVolume::GraphBoundVol::<unnamed>%3B7065BD037A
      //## Role: CGraphBV_Cylinder::Vol%3B7065BE0187
      //## begin CGraphBV_Cylinder::Vol%3B7065BE0187.role preserve=no  public: CBoundingCylinder { -> VHAN}
      CBoundingCylinder Vol;
      //## end CGraphBV_Cylinder::Vol%3B7065BE0187.role

    // Additional Public Declarations
      //## begin CGraphBV_Cylinder%3B70658502F8.public preserve=yes
      //## end CGraphBV_Cylinder%3B70658502F8.public

  protected:
    // Additional Protected Declarations
      //## begin CGraphBV_Cylinder%3B70658502F8.protected preserve=yes
      //## end CGraphBV_Cylinder%3B70658502F8.protected

  private:
    // Additional Private Declarations
      //## begin CGraphBV_Cylinder%3B70658502F8.private preserve=yes
      //## end CGraphBV_Cylinder%3B70658502F8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGraphBV_Cylinder%3B70658502F8.implementation preserve=yes
      //## end CGraphBV_Cylinder%3B70658502F8.implementation

};

//## begin CGraphBV_Cylinder%3B70658502F8.postscript preserve=yes
//## end CGraphBV_Cylinder%3B70658502F8.postscript

// Class CGraphBV_Cylinder 

//## begin module%3B70658502F8.epilog preserve=yes
//## end module%3B70658502F8.epilog


#endif
