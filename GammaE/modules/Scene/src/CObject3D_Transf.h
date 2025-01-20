//## begin module%3CB3429C00AC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB3429C00AC.cm

//## begin module%3CB3429C00AC.cp preserve=no
//## end module%3CB3429C00AC.cp

//## Module: CObject3D_Transf%3CB3429C00AC; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\CObject3D_Transf.h

#ifndef CObject3D_Transf_h
#define CObject3D_Transf_h 1

//## begin module%3CB3429C00AC.additionalIncludes preserve=no
//## end module%3CB3429C00AC.additionalIncludes

//## begin module%3CB3429C00AC.includes preserve=yes
//## end module%3CB3429C00AC.includes

// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3CB3429C00AC.additionalDeclarations preserve=yes
//## end module%3CB3429C00AC.additionalDeclarations


//## begin CObject3D_Transf%3CB3429C00AC.preface preserve=yes
//## end CObject3D_Transf%3CB3429C00AC.preface

//## Class: CObject3D_Transf%3CB3429C00AC
//## Category: Scene%3AA2567D00C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_Transf : public CObject3D  //## Inherits: <unnamed>%3CB342AE02F7
{
  //## begin CObject3D_Transf%3CB3429C00AC.initialDeclarations preserve=yes
  //## end CObject3D_Transf%3CB3429C00AC.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_Transf();

    //## Destructor (generated)
      ~CObject3D_Transf();


    //## Other Operations (specified)
      //## Operation: SetPos%1018703073
      void SetPos (CVect3& _roPos);

      //## Operation: roPos%1018703074
      CVect3& roPos ();

      //## Operation: SetDir%1019293387
      void SetDir (CVect3& _roDir);

      //## Operation: roDir%1019293388
      CVect3& roDir ();

      //## Operation: SetUp%1019293389
      void SetUp (CVect3& _roUp);

      //## Operation: roUp%1019293390
      CVect3& roUp ();

      //## Operation: SetSide%1019293391
      void SetSide (CVect3& _roSide);

      //## Operation: roSide%1019293392
      CVect3& roSide ();

      //## Operation: Setup%1019293393
      void Setup (CVect3& _roPos, CVect3& _roDir, CVect3& _roSide, CVect3& _roUp);

      //## Operation: SetTransf%1018703083
      void SetTransf (CMatrix4x4& _roTransf);

      //## Operation: roTransf%1018703084
      CMatrix4x4& roTransf ();

      //## Operation: SetObject%1018703876
      void SetObject (CObject3D* _poObj);

      //## Operation: poGetObject%1018703877
      CObject3D* poGetObject ();

      //## Operation: ComputeBoundVol%1018703071
      virtual void ComputeBoundVol ();

      //## Operation: poGetBoundVol%1018703070
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: Render%1018703072
      virtual void Render ();

    // Additional Public Declarations
      //## begin CObject3D_Transf%3CB3429C00AC.public preserve=yes
      //## end CObject3D_Transf%3CB3429C00AC.public

  protected:

    //## Other Operations (specified)
      //## Operation: SetupTransformation%1018703878
      void SetupTransformation ();

    // Data Members for Class Attributes

      //## Attribute: oTransf%3CB342D201FE
      //## begin CObject3D_Transf::oTransf%3CB342D201FE.attr preserve=no  protected: CMatrix4x4 {UA} 
      CMatrix4x4 oTransf;
      //## end CObject3D_Transf::oTransf%3CB342D201FE.attr

      //## Attribute: oPos%3CB342E10368
      //## begin CObject3D_Transf::oPos%3CB342E10368.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oPos;
      //## end CObject3D_Transf::oPos%3CB342E10368.attr

      //## Attribute: oDir%3CB3430601EF
      //## begin CObject3D_Transf::oDir%3CB3430601EF.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oDir;
      //## end CObject3D_Transf::oDir%3CB3430601EF.attr

      //## Attribute: oUp%3CB3430A006E
      //## begin CObject3D_Transf::oUp%3CB3430A006E.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oUp;
      //## end CObject3D_Transf::oUp%3CB3430A006E.attr

      //## Attribute: oSide%3CB3430E02B9
      //## begin CObject3D_Transf::oSide%3CB3430E02B9.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oSide;
      //## end CObject3D_Transf::oSide%3CB3430E02B9.attr

      //## Attribute: poObj%3CB82D740154
      //## begin CObject3D_Transf::poObj%3CB82D740154.attr preserve=no  protected: CObject3D* {UA} 
      CObject3D* poObj;
      //## end CObject3D_Transf::poObj%3CB82D740154.attr

    // Additional Protected Declarations
      //## begin CObject3D_Transf%3CB3429C00AC.protected preserve=yes
      //## end CObject3D_Transf%3CB3429C00AC.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_Transf%3CB3429C00AC.private preserve=yes
      //## end CObject3D_Transf%3CB3429C00AC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_Transf%3CB3429C00AC.implementation preserve=yes
      //## end CObject3D_Transf%3CB3429C00AC.implementation

};

//## begin CObject3D_Transf%3CB3429C00AC.postscript preserve=yes
//## end CObject3D_Transf%3CB3429C00AC.postscript

// Class CObject3D_Transf 

//## begin module%3CB3429C00AC.epilog preserve=yes
//## end module%3CB3429C00AC.epilog


#endif
