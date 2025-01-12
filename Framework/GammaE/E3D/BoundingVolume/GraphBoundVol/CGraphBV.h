//## begin module%3B706099014A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B706099014A.cm

//## begin module%3B706099014A.cp preserve=no
//## end module%3B706099014A.cp

//## Module: CGraphBV%3B706099014A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV.h

#ifndef CGraphBV_h
#define CGraphBV_h 1

//## begin module%3B706099014A.additionalIncludes preserve=no
//## end module%3B706099014A.additionalIncludes

//## begin module%3B706099014A.includes preserve=yes
//## end module%3B706099014A.includes

// eGraphBV_TypeID
#include "E3D\BoundingVolume\GraphBoundVol\eGraphBV_TypeID.h"
// CE3D_Frustum
#include "E3D\Viewing\Frustum\CE3D_Frustum.h"
//## begin module%3B706099014A.additionalDeclarations preserve=yes
//## end module%3B706099014A.additionalDeclarations


//## begin CGraphBV%3B706099014A.preface preserve=yes
//## end CGraphBV%3B706099014A.preface

//## Class: CGraphBV%3B706099014A
//## Category: E3D::BoundingVolume::GraphBoundVol%3B7060820104
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BA9104A01D8;eGraphBV_TypeID { -> }
//## Uses: <unnamed>%3BD87F8F0292;CE3D_Frustum { -> }

class CGraphBV 
{
  //## begin CGraphBV%3B706099014A.initialDeclarations preserve=yes
  //## end CGraphBV%3B706099014A.initialDeclarations

  public:
    //## Constructors (generated)
      CGraphBV();

    //## Destructor (generated)
      ~CGraphBV();


    //## Other Operations (specified)
      //## Operation: Transform%997221287
      virtual void Transform (CMatrix4x4& M);

      //## Operation: Compute%997221288
      virtual void Compute (CVect3* VXs, int iNumVXs);

      //## Operation: GetRange%997221289
      virtual float GetRange (int iAxis);

      //## Operation: GetCenter%997221290
      virtual CVect3 & GetCenter ();

      //## Operation: TestFrustum%997221291
      virtual int TestFrustum (CE3D_Frustum& _Frustum);

      //## Operation: Init%997221305
      virtual void Init (CVect3 Max, CVect3 Min);

      //## Operation: Copy%997314338
      virtual void Copy (CGraphBV* Src);

      //## Operation: eGetTypeID%1000933011
      eGraphBV_TypeID eGetTypeID ();

      //## Operation: TestInside%1006904827
      virtual int TestInside (CVect3& _Pos);

      //## Operation: GetExtents%1008030327
      virtual CVect3 & GetExtents ();

      //## Operation: roGetMax%1021629966
      virtual CVect3 & roGetMax ();

      //## Operation: roGetMin%1021629967
      virtual CVect3 & roGetMin ();

    // Additional Public Declarations
      //## begin CGraphBV%3B706099014A.public preserve=yes
      //## end CGraphBV%3B706099014A.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: eTypeID%3BA90FCD0279
      //## begin CGraphBV::eTypeID%3BA90FCD0279.attr preserve=no  protected: eGraphBV_TypeID {UA} 
      eGraphBV_TypeID eTypeID;
      //## end CGraphBV::eTypeID%3BA90FCD0279.attr

    // Additional Protected Declarations
      //## begin CGraphBV%3B706099014A.protected preserve=yes
      //## end CGraphBV%3B706099014A.protected

  private:
    // Additional Private Declarations
      //## begin CGraphBV%3B706099014A.private preserve=yes
      //## end CGraphBV%3B706099014A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGraphBV%3B706099014A.implementation preserve=yes
      //## end CGraphBV%3B706099014A.implementation

};

//## begin CGraphBV%3B706099014A.postscript preserve=yes
//## end CGraphBV%3B706099014A.postscript

// Class CGraphBV 


//## Other Operations (inline)
inline eGraphBV_TypeID CGraphBV::eGetTypeID ()
{
  //## begin CGraphBV::eGetTypeID%1000933011.body preserve=yes
	return (eTypeID);
  //## end CGraphBV::eGetTypeID%1000933011.body
}

//## begin module%3B706099014A.epilog preserve=yes
//## end module%3B706099014A.epilog


#endif
