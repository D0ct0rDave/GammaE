//## begin module%3C83D30502E1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C83D30502E1.cm

//## begin module%3C83D30502E1.cp preserve=no
//## end module%3C83D30502E1.cp

//## Module: CLightMapGenerator%3C83D30502E1; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\LightMapGen\MapLighting\CLightMapGenerator.h

#ifndef CLightMapGenerator_h
#define CLightMapGenerator_h 1

//## begin module%3C83D30502E1.additionalIncludes preserve=no
//## end module%3C83D30502E1.additionalIncludes

//## begin module%3C83D30502E1.includes preserve=yes
//## end module%3C83D30502E1.includes

// CMapEntity
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntity.h"
// CMapEntities
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntities.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
// GammaE_Scene
#include "Scene\GammaE_Scene.h"
//## begin module%3C83D30502E1.additionalDeclarations preserve=yes
//## end module%3C83D30502E1.additionalDeclarations


//## begin CLightMapGenerator%3C83D30502E1.preface preserve=yes
//## end CLightMapGenerator%3C83D30502E1.preface

//## Class: CLightMapGenerator%3C83D30502E1
//## Category: Tools::LightMapGen::MapLighting%3C83D2CC018B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C83D34E01EC;GammaE_Scene { -> }
//## Uses: <unnamed>%3C83D46003DB;CMapEntity { -> }
//## Uses: <unnamed>%3C83D8950127;GammaE_Math { -> }
//## Uses: <unnamed>%3C83DFBF023C;CMapEntities { -> }

class CLightMapGenerator 
{
  //## begin CLightMapGenerator%3C83D30502E1.initialDeclarations preserve=yes
  //## end CLightMapGenerator%3C83D30502E1.initialDeclarations

  public:
    //## Constructors (generated)
      CLightMapGenerator();

    //## Destructor (generated)
      ~CLightMapGenerator();


    //## Other Operations (specified)
      //## Operation: GenerateLighting%1015273104
      static void GenerateLighting (CObject3D* _poScene, CMapEntity * *_poEntities, int _iNumEntities);

      //## Operation: ComputeRayMatrix%1015354975
      static void ComputeRayMatrix (CRay& _roRay);

      //## Operation: EnumerateMeshes%1015273109
      static void EnumerateMeshes (CObject3D* _poObj);

      //## Operation: GenLitForLight%1015273108
      static void GenLitForLight (CMapEnt_Light& _roLight, CObject3D* _poScene);

      //## Operation: bRayToPos%1015273105
      static bool bRayToPos (CRay& _roRay, CVect3& _roPos, CObject3D* _poScene);

      //## Operation: MarkCrossedMeshes%1015273106
      static void MarkCrossedMeshes (CRay& _roRay, CObject3D* _poObj);

      //## Operation: poGetRayScene%1015273107
      static SCNUt_TriScene* poGetRayScene (CRay& _roRay);

      //## Operation: SetAmbientColor%1015279068
      static void SetAmbientColor (TFColor _roAmbColor);

    // Additional Public Declarations
      //## begin CLightMapGenerator%3C83D30502E1.public preserve=yes
      //## end CLightMapGenerator%3C83D30502E1.public

  protected:
    // Additional Protected Declarations
      //## begin CLightMapGenerator%3C83D30502E1.protected preserve=yes
      //## end CLightMapGenerator%3C83D30502E1.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: poEntity%3C83D38E0324
      //## begin CLightMapGenerator::poEntity%3C83D38E0324.attr preserve=no  private: static CMapEntity * * {UA} NULL
      static CMapEntity * *poEntity;
      //## end CLightMapGenerator::poEntity%3C83D38E0324.attr

      //## Attribute: iNumEntities%3C83D3A3034D
      //## begin CLightMapGenerator::iNumEntities%3C83D3A3034D.attr preserve=no  private: static int {UA} 0
      static int iNumEntities;
      //## end CLightMapGenerator::iNumEntities%3C83D3A3034D.attr

      //## Attribute: poMesh%3C83D4000120
      //## begin CLightMapGenerator::poMesh%3C83D4000120.attr preserve=no  private: static CMesh * * {UA} NULL
      static CMesh * *poMesh;
      //## end CLightMapGenerator::poMesh%3C83D4000120.attr

      //## Attribute: iNumMeshes%3C83D4090321
      //## begin CLightMapGenerator::iNumMeshes%3C83D4090321.attr preserve=no  private: static int {UA} 0
      static int iNumMeshes;
      //## end CLightMapGenerator::iNumMeshes%3C83D4090321.attr

      //## Attribute: poMarkedMeshes%3C83EDB202AF
      //## begin CLightMapGenerator::poMarkedMeshes%3C83EDB202AF.attr preserve=no  private: static CMesh ** {UA} NULL
      static CMesh **poMarkedMeshes;
      //## end CLightMapGenerator::poMarkedMeshes%3C83EDB202AF.attr

      //## Attribute: iNumMarkedMeshes%3C83EDC000A7
      //## begin CLightMapGenerator::iNumMarkedMeshes%3C83EDC000A7.attr preserve=no  private: static int {UA} 0
      static int iNumMarkedMeshes;
      //## end CLightMapGenerator::iNumMarkedMeshes%3C83EDC000A7.attr

      //## Attribute: oAmbColor%3C83F1A4022F
      //## begin CLightMapGenerator::oAmbColor%3C83F1A4022F.attr preserve=no  private: static TFColor {UA} 
      static TFColor oAmbColor;
      //## end CLightMapGenerator::oAmbColor%3C83F1A4022F.attr

      //## Attribute: oRayMat%3C853DC9028E
      //## begin CLightMapGenerator::oRayMat%3C853DC9028E.attr preserve=no  private: static CMatrix4x4 {UA} 
      static CMatrix4x4 oRayMat;
      //## end CLightMapGenerator::oRayMat%3C853DC9028E.attr

    // Additional Private Declarations
      //## begin CLightMapGenerator%3C83D30502E1.private preserve=yes
      //## end CLightMapGenerator%3C83D30502E1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLightMapGenerator%3C83D30502E1.implementation preserve=yes
      //## end CLightMapGenerator%3C83D30502E1.implementation

};

//## begin CLightMapGenerator%3C83D30502E1.postscript preserve=yes
//## end CLightMapGenerator%3C83D30502E1.postscript

// Class CLightMapGenerator 

//## begin module%3C83D30502E1.epilog preserve=yes
//## end module%3C83D30502E1.epilog


#endif
