//## begin module%3CA0FCA702FF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0FCA702FF.cm

//## begin module%3CA0FCA702FF.cp preserve=no
//## end module%3CA0FCA702FF.cp

//## Module: CGEMapGenerator%3CA0FCA702FF; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\CGEMapGenerator.h

#ifndef CGEMapGenerator_h
#define CGEMapGenerator_h 1

//## begin module%3CA0FCA702FF.additionalIncludes preserve=no
//## end module%3CA0FCA702FF.additionalIncludes

//## begin module%3CA0FCA702FF.includes preserve=yes
//## end module%3CA0FCA702FF.includes

// GammaE_Scene
#include "Scene\GammaE_Scene.h"
// CGEMap
#include "Game\GameScene\GameMap\GEMap\CGEMap.h"
// CQLEMapScn
#include "Tools\GEMapCompiler\QLEMap\CQLEMapScn.h"
// SCNUt_VisibilityTester
#include "Scene\SceneUtils\ScnVisibilityTester\SCNUt_VisibilityTester.h"
//## begin module%3CA0FCA702FF.additionalDeclarations preserve=yes
//## end module%3CA0FCA702FF.additionalDeclarations


//## begin CGEMapGenerator%3CA0FCA702FF.preface preserve=yes
//## end CGEMapGenerator%3CA0FCA702FF.preface

//## Class: CGEMapGenerator%3CA0FCA702FF
//## Category: Tools::GEMapCompiler%3CA0F23A02A7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CA0FD1301E2;CQLEMapScn { -> }
//## Uses: <unnamed>%3CA1005000D5;CGEMap { -> }
//## Uses: <unnamed>%3CA32F0400F5;CQLE_GEPreprocessor { -> }
//## Uses: <unnamed>%3CA43AE30046;CMapTriSceneGen { -> }
//## Uses: <unnamed>%3CA43F270172;GammaE_Scene { -> }
//## Uses: <unnamed>%3CD5130B01C4;SCNUt_VisibilityTester { -> }

class CGEMapGenerator 
{
  //## begin CGEMapGenerator%3CA0FCA702FF.initialDeclarations preserve=yes
  //## end CGEMapGenerator%3CA0FCA702FF.initialDeclarations

  public:
    //## Constructors (generated)
      CGEMapGenerator();

    //## Destructor (generated)
      ~CGEMapGenerator();


    //## Other Operations (specified)
      //## Operation: SetTexturePath%1017265242
      void SetTexturePath (char* _szTexPath);

      //## Operation: poGenerate%1018303590
      CGEMap * poGenerate (CQLEMapScn *_poMap);

      //## Operation: DestroyInvisibleTris%1020591280
      void DestroyInvisibleTris (CDynArray <SCNUt_TriScene *>& _roRoomTScn, CDynArray <CBoundingBox>& _roRoomBBoxes, CGEMap *_poGEMap);

      //## Operation: ProcessBrushedEntities%1021126165
      void ProcessBrushedEntities (CGEMapRoom *_poRoom);

    // Additional Public Declarations
      //## begin CGEMapGenerator%3CA0FCA702FF.public preserve=yes
      //## end CGEMapGenerator%3CA0FCA702FF.public

  protected:

    //## Other Operations (specified)
      //## Operation: GenerateRoomTScenes%1020591273
      void GenerateRoomTScenes (CQLEMapScn *_poMap, CDynArray <SCNUt_TriScene *>& _roRoomTScn, CDynArray<SCNUt_MaterialTable>& _roRoomMTab, CDynArray <CBoundingBox>& _roRoomBBox);

      //## Operation: GenerateRoomArray%1017393300
      void GenerateRoomArray (CDynArray <SCNUt_TriScene *>& _roRoomTScn, CDynArray<SCNUt_MaterialTable>& _roRoomMTab, CGEMap *_poGEMap);

      //## Operation: GenerateConnectorArray%1017396148
      void GenerateConnectorArray (CQLEMapScn *_poMap, CGEMap *_poGEMap, CDynArray <CBoundingBox>& _roRoomBBoxes);

      //## Operation: bGetABConnRooms%1017396150
      bool bGetABConnRooms (CGEMapConnector* _poConn, CDynArray <CBoundingBox>& _roRoomBBoxes, int& _riA, int& _riB);

      //## Operation: GenerateAdjacencyInfo%1017414738
      void GenerateAdjacencyInfo (CGEMap *_poGEMap);

      //## Operation: ComputeRoomAdjacencyInfo%1017414736
      void ComputeRoomAdjacencyInfo (int _iRoom, CGEMap* _poMap);

    // Additional Protected Declarations
      //## begin CGEMapGenerator%3CA0FCA702FF.protected preserve=yes
      //## end CGEMapGenerator%3CA0FCA702FF.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: szTexPath%3CB214AC0025
      //## begin CGEMapGenerator::szTexPath%3CB214AC0025.attr preserve=no  private: char[256] {UA} 
      char szTexPath[256];
      //## end CGEMapGenerator::szTexPath%3CB214AC0025.attr

    // Additional Private Declarations
      //## begin CGEMapGenerator%3CA0FCA702FF.private preserve=yes
      //## end CGEMapGenerator%3CA0FCA702FF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGEMapGenerator%3CA0FCA702FF.implementation preserve=yes
      //## end CGEMapGenerator%3CA0FCA702FF.implementation

};

//## begin CGEMapGenerator%3CA0FCA702FF.postscript preserve=yes
//## end CGEMapGenerator%3CA0FCA702FF.postscript

// Class CGEMapGenerator 

//## begin module%3CA0FCA702FF.epilog preserve=yes
//## end module%3CA0FCA702FF.epilog


#endif
