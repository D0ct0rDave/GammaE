//## begin module%3BB24FC100F3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BB24FC100F3.cm

//## begin module%3BB24FC100F3.cp preserve=no
//## end module%3BB24FC100F3.cp

//## Module: CLensFlare%3BB24FC100F3; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\LensFlare\CLensFlare.h

#ifndef CLensFlare_h
#define CLensFlare_h 1

//## begin module%3BB24FC100F3.additionalIncludes preserve=no
//## end module%3BB24FC100F3.additionalIncludes

//## begin module%3BB24FC100F3.includes preserve=yes
//## end module%3BB24FC100F3.includes

// CLensFlare_Elem
#include "SceneObjects\LensFlare\CLensFlare_Elem.h"
// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3BB24FC100F3.additionalDeclarations preserve=yes
//## end module%3BB24FC100F3.additionalDeclarations


//## begin CLensFlare%3BB24FC100F3.preface preserve=yes
//## end CLensFlare%3BB24FC100F3.preface

//## Class: CLensFlare%3BB24FC100F3
//## Category: SceneObjects::LensFlare%3BB24FB703B6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BB3A2FB03DA;CLensFlare_Elem { -> }

class CLensFlare : public CObject3D  //## Inherits: <unnamed>%3BB3A9B4038E
{
  //## begin CLensFlare%3BB24FC100F3.initialDeclarations preserve=yes
  //## end CLensFlare%3BB24FC100F3.initialDeclarations

  public:
    //## Constructors (generated)
      CLensFlare();

    //## Destructor (generated)
      virtual ~CLensFlare();


    //## Other Operations (specified)
      //## Operation: InitLensFlare%1001541675
      void InitLensFlare (int _iNumElems, CVect3 _SunPos);

      //## Operation: SetupFlareElem%1001625477
      void SetupFlareElem (int _iElem, float _fSize, float _fDist, CVect4 _Color, CE3D_Shader *_pMat);

      //## Operation: UpdateLensFlare%1001541676
      void UpdateLensFlare (CMatrix4x4& _ViewMatrix, CMatrix4x4& _ProjMatrix, float _fSunCamAngle);

      //## Operation: Render%1001541674
      virtual void Render ();

      //## Operation: poGetBoundVol%1001625479
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: ComputeBoundVol%1001625480
      virtual void ComputeBoundVol ();

    // Additional Public Declarations
      //## begin CLensFlare%3BB24FC100F3.public preserve=yes
      //## end CLensFlare%3BB24FC100F3.public

  protected:
    // Additional Protected Declarations
      //## begin CLensFlare%3BB24FC100F3.protected preserve=yes
      //## end CLensFlare%3BB24FC100F3.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: SunPos%3BB2502E0258
      //## begin CLensFlare::SunPos%3BB2502E0258.attr preserve=no  private: CVect3 {UA} 
      CVect3 SunPos;
      //## end CLensFlare::SunPos%3BB2502E0258.attr

      //## Attribute: FlareElems%3BB3A2FE037A
      //## begin CLensFlare::FlareElems%3BB3A2FE037A.attr preserve=no  private: CLensFlare_Elem* {UA} NULL
      CLensFlare_Elem* FlareElems;
      //## end CLensFlare::FlareElems%3BB3A2FE037A.attr

      //## Attribute: iNumElems%3BB3A38403A5
      //## begin CLensFlare::iNumElems%3BB3A38403A5.attr preserve=no  private: int {UA} 0
      int iNumElems;
      //## end CLensFlare::iNumElems%3BB3A38403A5.attr

      //## Attribute: MeshArray%3BB3A5160140
      //## begin CLensFlare::MeshArray%3BB3A5160140.attr preserve=no  private: CMesh_Rect * {UA} NULL
      CMesh_Rect *MeshArray;
      //## end CLensFlare::MeshArray%3BB3A5160140.attr

    // Additional Private Declarations
      //## begin CLensFlare%3BB24FC100F3.private preserve=yes
      //## end CLensFlare%3BB24FC100F3.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLensFlare%3BB24FC100F3.implementation preserve=yes
      //## end CLensFlare%3BB24FC100F3.implementation

};

//## begin CLensFlare%3BB24FC100F3.postscript preserve=yes
//## end CLensFlare%3BB24FC100F3.postscript

// Class CLensFlare 

//## begin module%3BB24FC100F3.epilog preserve=yes
//## end module%3BB24FC100F3.epilog


#endif
