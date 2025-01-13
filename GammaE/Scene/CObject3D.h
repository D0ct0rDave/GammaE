//## begin module%3AA256E702BC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AA256E702BC.cm

//## begin module%3AA256E702BC.cp preserve=no
//## end module%3AA256E702BC.cp

//## Module: CObject3D%3AA256E702BC; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\CObject3D.h

#ifndef CObject3D_h
#define CObject3D_h 1

//## begin module%3AA256E702BC.additionalIncludes preserve=no
//## end module%3AA256E702BC.additionalIncludes

//## begin module%3AA256E702BC.includes preserve=yes
//## end module%3AA256E702BC.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// e3DObjectTypeID
#include "Scene\e3DObjectTypeID.h"
//## begin module%3AA256E702BC.additionalDeclarations preserve=yes
//## end module%3AA256E702BC.additionalDeclarations


//## begin CObject3D%3AA256E702BC.preface preserve=yes
//## end CObject3D%3AA256E702BC.preface

//## Class: CObject3D%3AA256E702BC
//## Category: Scene%3AA2567D00C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1BF3A50345;GammaE_E3D { -> }
//## Uses: <unnamed>%3B8CFC79034E;e3DObjectTypeID { -> }

class CObject3D 
{
  //## begin CObject3D%3AA256E702BC.initialDeclarations preserve=yes
  //## end CObject3D%3AA256E702BC.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D();

    //## Destructor (generated)
      ~CObject3D();


    //## Other Operations (specified)
      //## Operation: poGetBoundVol%983822069
      virtual CGraphBV* poGetBoundVol () = 0;

      //## Operation: ComputeBoundVol%983822070
      virtual void ComputeBoundVol () = 0;

      //## Operation: Render%983822079
      virtual void Render () = 0;

      //## Operation: Reference%999094732
      void Reference ();

      //## Operation: UnReference%999094733
      void UnReference ();

      //## Operation: SetBoundVol%1000933017
      void SetBoundVol (CGraphBV *_pGBV);

      //## Operation: bVisible%1006904816
      virtual bool bVisible ();

      //## Operation: eGetTypeID%1018703875
      e3DObjectTypeID eGetTypeID ();

    // Additional Public Declarations
      //## begin CObject3D%3AA256E702BC.public preserve=yes
      //## end CObject3D%3AA256E702BC.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: BVol%3AA256E702BD
      //## begin CObject3D::BVol%3AA256E702BD.attr preserve=no  protected: CGraphBV * {UA} NULL
      CGraphBV *BVol;
      //## end CObject3D::BVol%3AA256E702BD.attr

      //## Attribute: NumRefs%3B8CF7F10346
      //## begin CObject3D::NumRefs%3B8CF7F10346.attr preserve=no  protected: int {UA} 0
      int NumRefs;
      //## end CObject3D::NumRefs%3B8CF7F10346.attr

      //## Attribute: bFrustumTest%3C04306C00EB
      //## begin CObject3D::bFrustumTest%3C04306C00EB.attr preserve=no  protected: bool {UA} false
      bool bFrustumTest;
      //## end CObject3D::bFrustumTest%3C04306C00EB.attr

      //## Attribute: TypeID%3CB82F85014A
      //## begin CObject3D::TypeID%3CB82F85014A.attr preserve=no  protected: e3DObjectTypeID {UA} 
      e3DObjectTypeID TypeID;
      //## end CObject3D::TypeID%3CB82F85014A.attr

    // Additional Protected Declarations
      //## begin CObject3D%3AA256E702BC.protected preserve=yes
      //## end CObject3D%3AA256E702BC.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D%3AA256E702BC.private preserve=yes
      //## end CObject3D%3AA256E702BC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D%3AA256E702BC.implementation preserve=yes
      //## end CObject3D%3AA256E702BC.implementation

};

//## begin CObject3D%3AA256E702BC.postscript preserve=yes
//## end CObject3D%3AA256E702BC.postscript

// Class CObject3D 


//## Other Operations (inline)
inline void CObject3D::SetBoundVol (CGraphBV *_pGBV)
{
  //## begin CObject3D::SetBoundVol%1000933017.body preserve=yes
	BVol = _pGBV;
  //## end CObject3D::SetBoundVol%1000933017.body
}

inline e3DObjectTypeID CObject3D::eGetTypeID ()
{
  //## begin CObject3D::eGetTypeID%1018703875.body preserve=yes
	return(TypeID);
  //## end CObject3D::eGetTypeID%1018703875.body
}

//## begin module%3AA256E702BC.epilog preserve=yes
//## end module%3AA256E702BC.epilog


#endif


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CObject3D::eGetTypeID%999094735.body preserve=no
	return (TypeID );
//## end CObject3D::eGetTypeID%999094735.body

#endif
