//## begin module%3C742BB2030E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C742BB2030E.cm

//## begin module%3C742BB2030E.cp preserve=no
//## end module%3C742BB2030E.cp

//## Module: CMapTriSceneGen%3C742BB2030E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\CMapTriSceneGen.h

#ifndef CMapTriSceneGen_h
#define CMapTriSceneGen_h 1

//## begin module%3C742BB2030E.additionalIncludes preserve=no
//## end module%3C742BB2030E.additionalIncludes

//## begin module%3C742BB2030E.includes preserve=yes
//## end module%3C742BB2030E.includes

// GammaE_Scene
#include "Scene\GammaE_Scene.h"
// CMapScene
#include "Tools\GEMapCompiler\MapData\CMapScene.h"
// SCNUt_MaterialTable
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MaterialTable.h"
// SCNUt_TriUtils
#include "Scene\SceneUtils\ScnUtils\SCNUt_TriUtils.h"
//## begin module%3C742BB2030E.additionalDeclarations preserve=yes
//## end module%3C742BB2030E.additionalDeclarations


//## begin CMapTriSceneGen%3C742BB2030E.preface preserve=yes
//## end CMapTriSceneGen%3C742BB2030E.preface

//## Class: CMapTriSceneGen%3C742BB2030E
//## Category: Tools::GEMapCompiler::MapData%3C741F390140
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C742C05021D;CMapScene { -> }
//## Uses: <unnamed>%3C7432760200;GammaE_Scene { -> }
//## Uses: <unnamed>%3C76DBDE024F;SCNUt_TriUtils { -> }

class CMapTriSceneGen 
{
  //## begin CMapTriSceneGen%3C742BB2030E.initialDeclarations preserve=yes
  //## end CMapTriSceneGen%3C742BB2030E.initialDeclarations

  public:
    //## Constructors (generated)
      CMapTriSceneGen();

    //## Destructor (generated)
      ~CMapTriSceneGen();


    //## Other Operations (specified)
      //## Operation: poGenerateScene%1014246308
      static SCNUt_TriScene* poGenerateScene (CMapScene& _roMapScene);

      //## Operation: poDecomposeBrush%1014330409
      static SCNUt_TriScene * poDecomposeBrush (CMapBrush& _roBrush);

      //## Operation: bPointInBrush%1014762715
      static bool bPointInBrush (CVect3& _roPoint, CMapBrush& _roBrush);

      //## Operation: bPointAlreadyInList%1014767412
      static bool bPointAlreadyInList (CVect3& _roPnt, CVect3* _poVXs, int _iNumPnts);

      //## Operation: poBrush2Tris%1014330410
      static SCNUt_TriScene * poBrush2Tris (CVect3* _poPoints, int _iNumPoints, CMapBrush& _roBrush);

      //## Operation: poBrushSide2Tris%1014393896
      static SCNUt_TriScene * poBrushSide2Tris (CVect3* _poPoints, int _iNumPoints, CMapBrushSide& _roBSide);

      //## Operation: poPoly2Tris%1014393897
      static SCNUt_TriScene * poPoly2Tris (CVect3* _poPoints, int _iNumPoints, CMapBrushSide& _roBSide, int _iMaterial);

      //## Operation: ComputeTriUV%1014668746
      static void ComputeTriUV (SCNUt_Triangle &_roTri, CMapBrushSide& _roBSide);

      //## Operation: SetTexturePath%1018303589
      static void SetTexturePath (char *_szTexturePath);

    // Data Members for Associations

      //## Association: Tools::GEMapCompiler::MapData::<unnamed>%3C76E1A000D2
      //## Role: CMapTriSceneGen::poMatTable%3C76E1A0019B
      //## begin CMapTriSceneGen::poMatTable%3C76E1A0019B.role preserve=no  public: static SCNUt_MaterialTable { -> RHAN}
      static SCNUt_MaterialTable *poMatTable;
      //## end CMapTriSceneGen::poMatTable%3C76E1A0019B.role

    // Additional Public Declarations
      //## begin CMapTriSceneGen%3C742BB2030E.public preserve=yes
      //## end CMapTriSceneGen%3C742BB2030E.public

  protected:
    // Additional Protected Declarations
      //## begin CMapTriSceneGen%3C742BB2030E.protected preserve=yes
      //## end CMapTriSceneGen%3C742BB2030E.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: szTexturePath%3CB2144B033D
      //## begin CMapTriSceneGen::szTexturePath%3CB2144B033D.attr preserve=no  private: static char[256] {UA} 
      static char szTexturePath[256];
      //## end CMapTriSceneGen::szTexturePath%3CB2144B033D.attr

    // Additional Private Declarations
      //## begin CMapTriSceneGen%3C742BB2030E.private preserve=yes
      //## end CMapTriSceneGen%3C742BB2030E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapTriSceneGen%3C742BB2030E.implementation preserve=yes
      //## end CMapTriSceneGen%3C742BB2030E.implementation

};

//## begin CMapTriSceneGen%3C742BB2030E.postscript preserve=yes
//## end CMapTriSceneGen%3C742BB2030E.postscript

// Class CMapTriSceneGen 

//## begin module%3C742BB2030E.epilog preserve=yes
//## end module%3C742BB2030E.epilog


#endif
