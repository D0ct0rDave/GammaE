//## begin module%3B7061E0019A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7061E0019A.cm

//## begin module%3B7061E0019A.cp preserve=no
//## end module%3B7061E0019A.cp

//## Module: CGraphBV_Box%3B7061E0019A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV_Box.h

#ifndef CGraphBV_Box_h
#define CGraphBV_Box_h 1

//## begin module%3B7061E0019A.additionalIncludes preserve=no
//## end module%3B7061E0019A.additionalIncludes

//## begin module%3B7061E0019A.includes preserve=yes
//## end module%3B7061E0019A.includes

// CGraphBV
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV.h"
// CBoundingBox
#include "E3D\BoundingVolume\CBoundingBox.h"
//## begin module%3B7061E0019A.additionalDeclarations preserve=yes
//## end module%3B7061E0019A.additionalDeclarations


//## begin CGraphBV_Box%3B7061E0019A.preface preserve=yes
//## end CGraphBV_Box%3B7061E0019A.preface

//## Class: CGraphBV_Box%3B7061E0019A
//## Category: E3D::BoundingVolume::GraphBoundVol%3B7060820104
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGraphBV_Box : public CGraphBV  //## Inherits: <unnamed>%3B7061EE01D6
{
  //## begin CGraphBV_Box%3B7061E0019A.initialDeclarations preserve=yes
  //## end CGraphBV_Box%3B7061E0019A.initialDeclarations

  public:
    //## Constructors (generated)
      CGraphBV_Box();

    //## Destructor (generated)
      ~CGraphBV_Box();


    //## Other Operations (specified)
      //## Operation: Transform%997221292
      virtual void Transform (CMatrix4x4& M);

      //## Operation: Compute%997221293
      virtual void Compute (CVect3* VXs, int iNumVXs);

      //## Operation: GetRange%997221294
      virtual float GetRange (int iAxis);

      //## Operation: GetCenter%997221295
      virtual CVect3 & GetCenter ();

      //## Operation: TestFrustum%997221296
      virtual int TestFrustum (CE3D_Frustum& _Frustum);

      //## Operation: Init%997221308
      virtual void Init (CVect3 Max, CVect3 Min);

      //## Operation: pGetBox%1000933015
      CBoundingBox * pGetBox ();

      //## Operation: TestInside%1006904825
      virtual int TestInside (CVect3& _Pos);

      //## Operation: GetExtents%1008030326
      virtual CVect3 & GetExtents ();

      //## Operation: GetAxis%1009321160
      CVect3 & GetAxis (int _iAxis);

      //## Operation: roGetMax%1021629968
      virtual CVect3 & roGetMax ();

      //## Operation: roGetMin%1021629969
      virtual CVect3 & roGetMin ();

    // Data Members for Associations

      //## Association: E3D::BoundingVolume::GraphBoundVol::<unnamed>%3B706245008C
      //## Role: CGraphBV_Box::Vol%3B70624501A5
      //## begin CGraphBV_Box::Vol%3B70624501A5.role preserve=no  public: CBoundingBox { -> VHAN}
      CBoundingBox Vol;
      //## end CGraphBV_Box::Vol%3B70624501A5.role

    // Additional Public Declarations
      //## begin CGraphBV_Box%3B7061E0019A.public preserve=yes
      //## end CGraphBV_Box%3B7061E0019A.public

  protected:

    //## Other Operations (specified)
      //## Operation: ComputeAll%1021629970
      void ComputeAll ();

    // Data Members for Class Attributes

      //## Attribute: oExtents%3C1552900206
      //## begin CGraphBV_Box::oExtents%3C1552900206.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oExtents;
      //## end CGraphBV_Box::oExtents%3C1552900206.attr

      //## Attribute: oCenter%3CE4EE4801AF
      //## begin CGraphBV_Box::oCenter%3CE4EE4801AF.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oCenter;
      //## end CGraphBV_Box::oCenter%3CE4EE4801AF.attr

    // Additional Protected Declarations
      //## begin CGraphBV_Box%3B7061E0019A.protected preserve=yes
      //## end CGraphBV_Box%3B7061E0019A.protected

  private:
    // Additional Private Declarations
      //## begin CGraphBV_Box%3B7061E0019A.private preserve=yes
      //## end CGraphBV_Box%3B7061E0019A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGraphBV_Box%3B7061E0019A.implementation preserve=yes
      //## end CGraphBV_Box%3B7061E0019A.implementation

};

//## begin CGraphBV_Box%3B7061E0019A.postscript preserve=yes
//## end CGraphBV_Box%3B7061E0019A.postscript

// Class CGraphBV_Box 

//## begin module%3B7061E0019A.epilog preserve=yes
//## end module%3B7061E0019A.epilog


#endif
