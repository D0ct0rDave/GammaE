//## begin module%3B7060AD0140.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7060AD0140.cm

//## begin module%3B7060AD0140.cp preserve=no
//## end module%3B7060AD0140.cp

//## Module: CGraphBV_Sphere%3B7060AD0140; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV_Sphere.h

#ifndef CGraphBV_Sphere_h
#define CGraphBV_Sphere_h 1

//## begin module%3B7060AD0140.additionalIncludes preserve=no
//## end module%3B7060AD0140.additionalIncludes

//## begin module%3B7060AD0140.includes preserve=yes
//## end module%3B7060AD0140.includes

// CGraphBV
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV.h"
// CBoundingSphere
#include "E3D\BoundingVolume\CBoundingSphere.h"
//## begin module%3B7060AD0140.additionalDeclarations preserve=yes
//## end module%3B7060AD0140.additionalDeclarations


//## begin CGraphBV_Sphere%3B7060AD0140.preface preserve=yes
//## end CGraphBV_Sphere%3B7060AD0140.preface

//## Class: CGraphBV_Sphere%3B7060AD0140
//## Category: E3D::BoundingVolume::GraphBoundVol%3B7060820104
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGraphBV_Sphere : public CGraphBV  //## Inherits: <unnamed>%3B70619B032A
{
  //## begin CGraphBV_Sphere%3B7060AD0140.initialDeclarations preserve=yes
  //## end CGraphBV_Sphere%3B7060AD0140.initialDeclarations

  public:
    //## Constructors (generated)
      CGraphBV_Sphere();

    //## Destructor (generated)
      ~CGraphBV_Sphere();


    //## Other Operations (specified)
      //## Operation: Transform%997221281
      virtual void Transform (CMatrix4x4& M);

      //## Operation: Compute%997221282
      virtual void Compute (CVect3* VXs, int iNumVXs);

      //## Operation: GetRange%997221283
      virtual float GetRange (int iAxis);

      //## Operation: GetCenter%997221284
      virtual CVect3 & GetCenter ();

      //## Operation: TestFrustum%997221285
      virtual int TestFrustum (CE3D_Frustum& _Frustum);

      //## Operation: Init%997221306
      virtual void Init (CVect3 Max, CVect3 Min);

      //## Operation: pGetSphere%1000933016
      CBoundingSphere * pGetSphere ();

      //## Operation: TestInside%1006904826
      virtual int TestInside (CVect3& _Pos);

      //## Operation: Copy%1020117913
      virtual void Copy (CGraphBV* Src);

    // Data Members for Associations

      //## Association: E3D::BoundingVolume::GraphBoundVol::<unnamed>%3B7061610096
      //## Role: CGraphBV_Sphere::Vol%3B7061610281
      //## begin CGraphBV_Sphere::Vol%3B7061610281.role preserve=no  public: CBoundingSphere { -> VHAN}
      CBoundingSphere Vol;
      //## end CGraphBV_Sphere::Vol%3B7061610281.role

    // Additional Public Declarations
      //## begin CGraphBV_Sphere%3B7060AD0140.public preserve=yes
      //## end CGraphBV_Sphere%3B7060AD0140.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: oExtents%3CE4EE5803A6
      //## begin CGraphBV_Sphere::oExtents%3CE4EE5803A6.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oExtents;
      //## end CGraphBV_Sphere::oExtents%3CE4EE5803A6.attr

    // Additional Protected Declarations
      //## begin CGraphBV_Sphere%3B7060AD0140.protected preserve=yes
      //## end CGraphBV_Sphere%3B7060AD0140.protected

  private:
    // Additional Private Declarations
      //## begin CGraphBV_Sphere%3B7060AD0140.private preserve=yes
      //## end CGraphBV_Sphere%3B7060AD0140.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGraphBV_Sphere%3B7060AD0140.implementation preserve=yes
      //## end CGraphBV_Sphere%3B7060AD0140.implementation

};

//## begin CGraphBV_Sphere%3B7060AD0140.postscript preserve=yes
//## end CGraphBV_Sphere%3B7060AD0140.postscript

// Class CGraphBV_Sphere 

//## begin module%3B7060AD0140.epilog preserve=yes
//## end module%3B7060AD0140.epilog


#endif
