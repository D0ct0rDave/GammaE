//## begin module%3A9AD9D4032A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AD9D4032A.cm

//## begin module%3A9AD9D4032A.cp preserve=no
//## end module%3A9AD9D4032A.cp

//## Module: CPlane%3A9AD9D4032A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Plane\CPlane.h

#ifndef CPlane_h
#define CPlane_h 1

//## begin module%3A9AD9D4032A.additionalIncludes preserve=no
//## end module%3A9AD9D4032A.additionalIncludes

//## begin module%3A9AD9D4032A.includes preserve=yes
//## end module%3A9AD9D4032A.includes

// CVect3
#include "Math\MATH_Vector\CVect3.h"
// CMatrix4x4
#include "Math\MATH_Matrix\CMatrix4x4.h"
// MATH_Common
#include "Math\MATH_Other\MATH_Common.h"
//## begin module%3A9AD9D4032A.additionalDeclarations preserve=yes
//## end module%3A9AD9D4032A.additionalDeclarations


//## begin CPlane%3A9AD9D4032A.preface preserve=yes
//## end CPlane%3A9AD9D4032A.preface

//## Class: CPlane%3A9AD9D4032A
//## Category: Math::MATH_Plane%3C275CF3003C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B7FDB1002D2;CVect3 { -> }
//## Uses: <unnamed>%3C056833033F;CMatrix4x4 { -> }
//## Uses: <unnamed>%3C96745A03E4;MATH_Common { -> }

class CPlane 
{
  //## begin CPlane%3A9AD9D4032A.initialDeclarations preserve=yes
  //## end CPlane%3A9AD9D4032A.initialDeclarations

  public:
    //## Constructors (generated)
      CPlane();


    //## Other Operations (specified)
      //## Operation: SetNormal%998231928
      void SetNormal (CVect3& _Normal);

      //## Operation: SetD%998231929
      void SetD (float _D);

      //## Operation: SetOrigin%998231930
      void SetOrigin (CVect3& _Origin);

      //## Operation: GenerateFromVectors%998231931
      void GenerateFromVectors (CVect3 VDir1, CVect3 VDir2, CVect3 VOrigin);

      //## Operation: GenerateFromPoints%998231932
      void GenerateFromPoints (CVect3& a, CVect3& b, CVect3& c);

      //## Operation: GeneratePlaneFromFields%998231933
      void GeneratePlaneFromFields (CVect3& VOrigin, CVect3& VNormal);

      //## Operation: GetDistanceToPoint%998231934
      float GetDistanceToPoint (CVect3& Point);

      //## Operation: Coplanar%998231935
      bool Coplanar (CPlane& Plane);

      //## Operation: Normal%998231936
      CVect3 & Normal ();

      //## Operation: Origin%998231937
      CVect3 & Origin ();

      //## Operation: D%998231938
      float D ();

      //## Operation: Transform%1006987067
      void Transform (CMatrix4x4& _Transf);

      //## Operation: ProjectPoint%1007685158
      CVect3 ProjectPoint (CVect3& _Point);

      //## Operation: iPlaneType%1014330411
      int iPlaneType ();

    // Additional Public Declarations
      //## begin CPlane%3A9AD9D4032A.public preserve=yes
      //## end CPlane%3A9AD9D4032A.public

  protected:
    // Additional Protected Declarations
      //## begin CPlane%3A9AD9D4032A.protected preserve=yes
      //## end CPlane%3A9AD9D4032A.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: PlaneD%3B7FD99F0354
      //## begin CPlane::PlaneD%3B7FD99F0354.attr preserve=no  private: float {UA} 0
      float PlaneD;
      //## end CPlane::PlaneD%3B7FD99F0354.attr

      //## Attribute: PlaneOrigin%3B7FD9B702FE
      //## begin CPlane::PlaneOrigin%3B7FD9B702FE.attr preserve=no  private: CVect3 {UA} 
      CVect3 PlaneOrigin;
      //## end CPlane::PlaneOrigin%3B7FD9B702FE.attr

      //## Attribute: PlaneNormal%3B7FD9C700EE
      //## begin CPlane::PlaneNormal%3B7FD9C700EE.attr preserve=no  private: CVect3 {UA} 
      CVect3 PlaneNormal;
      //## end CPlane::PlaneNormal%3B7FD9C700EE.attr

    // Additional Private Declarations
      //## begin CPlane%3A9AD9D4032A.private preserve=yes
      //## end CPlane%3A9AD9D4032A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPlane%3A9AD9D4032A.implementation preserve=yes
      //## end CPlane%3A9AD9D4032A.implementation

};

//## begin CPlane%3A9AD9D4032A.postscript preserve=yes
//## end CPlane%3A9AD9D4032A.postscript

// Class CPlane 


//## Other Operations (inline)
inline void CPlane::SetNormal (CVect3& _Normal)
{
  //## begin CPlane::SetNormal%998231928.body preserve=yes
	PlaneNormal.Assign(_Normal);
  //## end CPlane::SetNormal%998231928.body
}

inline void CPlane::SetD (float _D)
{
  //## begin CPlane::SetD%998231929.body preserve=yes
	PlaneD = _D;
  //## end CPlane::SetD%998231929.body
}

inline void CPlane::SetOrigin (CVect3& _Origin)
{
  //## begin CPlane::SetOrigin%998231930.body preserve=yes
	PlaneOrigin.Assign(_Origin);
  //## end CPlane::SetOrigin%998231930.body
}

inline CVect3 & CPlane::Normal ()
{
  //## begin CPlane::Normal%998231936.body preserve=yes
	return (PlaneNormal);
  //## end CPlane::Normal%998231936.body
}

inline CVect3 & CPlane::Origin ()
{
  //## begin CPlane::Origin%998231937.body preserve=yes
	return (PlaneOrigin);
  //## end CPlane::Origin%998231937.body
}

inline float CPlane::D ()
{
  //## begin CPlane::D%998231938.body preserve=yes
	return (PlaneD);
  //## end CPlane::D%998231938.body
}

//## begin module%3A9AD9D4032A.epilog preserve=yes
//## end module%3A9AD9D4032A.epilog


#endif
