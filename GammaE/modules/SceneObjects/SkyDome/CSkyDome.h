//## begin module%3BB0F0530382.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BB0F0530382.cm

//## begin module%3BB0F0530382.cp preserve=no
//## end module%3BB0F0530382.cp

//## Module: CSkyDome%3BB0F0530382; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\SkyDome\CSkyDome.h

#ifndef CSkyDome_h
#define CSkyDome_h 1

//## begin module%3BB0F0530382.additionalIncludes preserve=no
//## end module%3BB0F0530382.additionalIncludes

//## begin module%3BB0F0530382.includes preserve=yes
//## end module%3BB0F0530382.includes

// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
//## begin module%3BB0F0530382.additionalDeclarations preserve=yes
//## end module%3BB0F0530382.additionalDeclarations


//## begin CSkyDome%3BB0F0530382.preface preserve=yes
//## end CSkyDome%3BB0F0530382.preface

//## Class: CSkyDome%3BB0F0530382
//## Category: SceneObjects::SkyDome%3B597FFF038E
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSkyDome : public CObject3D_Leaf  //## Inherits: <unnamed>%3BB0F0E60076
{
  //## begin CSkyDome%3BB0F0530382.initialDeclarations preserve=yes
  //## end CSkyDome%3BB0F0530382.initialDeclarations

  public:
    //## Constructors (generated)
      CSkyDome();

    //## Destructor (generated)
      virtual ~CSkyDome();


    //## Other Operations (specified)
      //## Operation: SetRotation%1001451998
      void SetRotation (float _fRot);

      //## Operation: SetRadius%1001452000
      void SetRadius (float _fRadius);

      //## Operation: SetAxis%1001452001
      void SetAxis (CVect3 _Axis);

      //## Operation: SetPosition%1001452002
      void SetPosition (CVect3 _Pos);

      //## Operation: CreateDome%1001452003
      void CreateDome (bool _bFogAffected, int _iNumVSlices, int _iNumHSlices, int _iStartVSlice, int _iEndVSlice, float _fUTiling, float _fVTiling);

      //## Operation: Render%1001452004
      virtual void Render ();

    // Additional Public Declarations
      //## begin CSkyDome%3BB0F0530382.public preserve=yes
      //## end CSkyDome%3BB0F0530382.public

  protected:
    // Additional Protected Declarations
      //## begin CSkyDome%3BB0F0530382.protected preserve=yes
      //## end CSkyDome%3BB0F0530382.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: fRadius%3BB0F06C00E9
      //## begin CSkyDome::fRadius%3BB0F06C00E9.attr preserve=no  private: float {UA} 0.0f
      float fRadius;
      //## end CSkyDome::fRadius%3BB0F06C00E9.attr

      //## Attribute: fRot%3BB0F07E0059
      //## begin CSkyDome::fRot%3BB0F07E0059.attr preserve=no  private: float {UA} 0.0f
      float fRot;
      //## end CSkyDome::fRot%3BB0F07E0059.attr

      //## Attribute: Axis%3BB0F08F0338
      //## begin CSkyDome::Axis%3BB0F08F0338.attr preserve=no  private: CVect3 {UA} 
      CVect3 Axis;
      //## end CSkyDome::Axis%3BB0F08F0338.attr

      //## Attribute: Pos%3BB0F1CB02E2
      //## begin CSkyDome::Pos%3BB0F1CB02E2.attr preserve=no  private: CVect3 {UA} 
      CVect3 Pos;
      //## end CSkyDome::Pos%3BB0F1CB02E2.attr

      //## Attribute: FogAffected%3BFC421703A2
      //## begin CSkyDome::FogAffected%3BFC421703A2.attr preserve=no  private: bool {UA} false
      bool FogAffected;
      //## end CSkyDome::FogAffected%3BFC421703A2.attr

    // Additional Private Declarations
      //## begin CSkyDome%3BB0F0530382.private preserve=yes
      //## end CSkyDome%3BB0F0530382.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSkyDome%3BB0F0530382.implementation preserve=yes
      //## end CSkyDome%3BB0F0530382.implementation

};

//## begin CSkyDome%3BB0F0530382.postscript preserve=yes
//## end CSkyDome%3BB0F0530382.postscript

// Class CSkyDome 

//## begin module%3BB0F0530382.epilog preserve=yes
//## end module%3BB0F0530382.epilog


#endif
