//## begin module%3CD4FA30005C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CD4FA30005C.cm

//## begin module%3CD4FA30005C.cp preserve=no
//## end module%3CD4FA30005C.cp

//## Module: CLightMapGenerator3%3CD4FA30005C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\LightMapGen\MapLighting\CLightMapGenerator3.h

#ifndef CLightMapGenerator3_h
#define CLightMapGenerator3_h 1

//## begin module%3CD4FA30005C.additionalIncludes preserve=no
//## end module%3CD4FA30005C.additionalIncludes

//## begin module%3CD4FA30005C.includes preserve=yes
//## end module%3CD4FA30005C.includes

// CMapEntities
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntities.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
// GammaE_Scene
#include "Scene\GammaE_Scene.h"
// GammaE_Collision
#include "Collision\GammaE_Collision.h"
//## begin module%3CD4FA30005C.additionalDeclarations preserve=yes
//## end module%3CD4FA30005C.additionalDeclarations


//## begin CLightMapGenerator3%3CD4FA30005C.preface preserve=yes
//## end CLightMapGenerator3%3CD4FA30005C.preface

//## Class: CLightMapGenerator3%3CD4FA30005C
//## Category: Tools::LightMapGen::MapLighting%3C83D2CC018B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CD4FA80031E;GammaE_Collision { -> }
//## Uses: <unnamed>%3CD4FA8300B6;GammaE_Math { -> }
//## Uses: <unnamed>%3CD4FA850113;CMapEntities { -> }
//## Uses: <unnamed>%3CD4FA8701F2;GammaE_Scene { -> }

class CLightMapGenerator3 
{
  //## begin CLightMapGenerator3%3CD4FA30005C.initialDeclarations preserve=yes
  //## end CLightMapGenerator3%3CD4FA30005C.initialDeclarations

  public:
    //## Constructors (generated)
      CLightMapGenerator3();

    //## Destructor (generated)
      ~CLightMapGenerator3();


    //## Other Operations (specified)
      //## Operation: SetAmbientColor%1020591274
      static void SetAmbientColor (TFColor _roAmbColor);

      //## Operation: GenerateLighting%1020591275
      static void GenerateLighting (CObject3D* _poScene, CDynArray <CMapEntity *> _oEntities);

      //## Operation: Clear%1020591276
      static void Clear (CObject3D* _poObj);

      //## Operation: ClearMesh%1020591277
      static void ClearMesh (CMesh *_poMesh);

      //## Operation: GenLitForLight%1020591278
      static void GenLitForLight (CMapEnt_Light& _roLight);

      //## Operation: SelectMeshes%1020591279
      static void SelectMeshes (CGraphBV_Sphere& _roSphere, CObject3D* _poObj);

    // Additional Public Declarations
      //## begin CLightMapGenerator3%3CD4FA30005C.public preserve=yes
      //## end CLightMapGenerator3%3CD4FA30005C.public

  protected:
    // Additional Protected Declarations
      //## begin CLightMapGenerator3%3CD4FA30005C.protected preserve=yes
      //## end CLightMapGenerator3%3CD4FA30005C.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: oAmbColor%3CD4FA470100
      //## begin CLightMapGenerator3::oAmbColor%3CD4FA470100.attr preserve=no  private: static TFColor {UA} 
      static TFColor oAmbColor;
      //## end CLightMapGenerator3::oAmbColor%3CD4FA470100.attr

      //## Attribute: poScene%3CD4FA530247
      //## begin CLightMapGenerator3::poScene%3CD4FA530247.attr preserve=no  private: static CObject3D* {UA} 
      static CObject3D* poScene;
      //## end CLightMapGenerator3::poScene%3CD4FA530247.attr

    // Additional Private Declarations
      //## begin CLightMapGenerator3%3CD4FA30005C.private preserve=yes
      //## end CLightMapGenerator3%3CD4FA30005C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLightMapGenerator3%3CD4FA30005C.implementation preserve=yes
      //## end CLightMapGenerator3%3CD4FA30005C.implementation

};

//## begin CLightMapGenerator3%3CD4FA30005C.postscript preserve=yes
//## end CLightMapGenerator3%3CD4FA30005C.postscript

// Class CLightMapGenerator3 

//## begin module%3CD4FA30005C.epilog preserve=yes
//## end module%3CD4FA30005C.epilog


#endif
