//## begin module%3C8667C4026C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C8667C4026C.cm

//## begin module%3C8667C4026C.cp preserve=no
//## end module%3C8667C4026C.cp

//## Module: CLightMapGenerator2%3C8667C4026C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\LightMapGen\MapLighting\CLightMapGenerator2.h

#ifndef CLightMapGenerator2_h
#define CLightMapGenerator2_h 1

//## begin module%3C8667C4026C.additionalIncludes preserve=no
//## end module%3C8667C4026C.additionalIncludes

//## begin module%3C8667C4026C.includes preserve=yes
//## end module%3C8667C4026C.includes

// CMapEntities
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntities.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
// GammaE_Scene
#include "Scene\GammaE_Scene.h"
// GammaE_Collision
#include "Collision\GammaE_Collision.h"
//## begin module%3C8667C4026C.additionalDeclarations preserve=yes
//## end module%3C8667C4026C.additionalDeclarations


//## begin CLightMapGenerator2%3C8667C4026C.preface preserve=yes
//## end CLightMapGenerator2%3C8667C4026C.preface

//## Class: CLightMapGenerator2%3C8667C4026C
//## Category: Tools::LightMapGen::MapLighting%3C83D2CC018B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C866EC70191;CMapEntities { -> }
//## Uses: <unnamed>%3C866FEC00C0;GammaE_Scene { -> }
//## Uses: <unnamed>%3C86727001A2;GammaE_Collision { -> }
//## Uses: <unnamed>%3C866FE90224;GammaE_Math { -> }

class CLightMapGenerator2 
{
  //## begin CLightMapGenerator2%3C8667C4026C.initialDeclarations preserve=yes
  //## end CLightMapGenerator2%3C8667C4026C.initialDeclarations

  public:
    //## Constructors (generated)
      CLightMapGenerator2();

    //## Destructor (generated)
      ~CLightMapGenerator2();


    //## Other Operations (specified)
      //## Operation: SetAmbientColor%1015443445
      static void SetAmbientColor (TFColor _roAmbColor);

      //## Operation: GenerateLighting%1015443440
      static void GenerateLighting (CObject3D* _poScene, CDynArray <CMapEntity *> _oEntities);

      //## Operation: Clear%1015456519
      static void Clear (CObject3D* _poObj);

      //## Operation: ClearMesh%1015456520
      static void ClearMesh (CMesh *_poMesh);

      //## Operation: GenLitForLight%1015443442
      static void GenLitForLight (CMapEnt_Light& _roLight);

      //## Operation: SelectMeshes%1015443443
      static void SelectMeshes (CGraphBV_Sphere& _roSphere, CObject3D* _poObj);

      //## Operation: SelectTris%1015443446
      static void SelectTris (float _fRadius, CVect3& _roPos);

    // Additional Public Declarations
      //## begin CLightMapGenerator2%3C8667C4026C.public preserve=yes
      //## end CLightMapGenerator2%3C8667C4026C.public

  protected:
    // Additional Protected Declarations
      //## begin CLightMapGenerator2%3C8667C4026C.protected preserve=yes
      //## end CLightMapGenerator2%3C8667C4026C.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: oAmbColor%3C866FBC031A
      //## begin CLightMapGenerator2::oAmbColor%3C866FBC031A.attr preserve=no  private: static TFColor {UA} 
      static TFColor oAmbColor;
      //## end CLightMapGenerator2::oAmbColor%3C866FBC031A.attr

      //## Attribute: poScene%3C86747B02F9
      //## begin CLightMapGenerator2::poScene%3C86747B02F9.attr preserve=no  private: static CObject3D* {UA} 
      static CObject3D* poScene;
      //## end CLightMapGenerator2::poScene%3C86747B02F9.attr

    // Additional Private Declarations
      //## begin CLightMapGenerator2%3C8667C4026C.private preserve=yes
      //## end CLightMapGenerator2%3C8667C4026C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLightMapGenerator2%3C8667C4026C.implementation preserve=yes
      //## end CLightMapGenerator2%3C8667C4026C.implementation

};

//## begin CLightMapGenerator2%3C8667C4026C.postscript preserve=yes
//## end CLightMapGenerator2%3C8667C4026C.postscript

// Class CLightMapGenerator2 

//## begin module%3C8667C4026C.epilog preserve=yes
//## end module%3C8667C4026C.epilog


#endif
