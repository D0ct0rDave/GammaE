//## begin module%3CA32E37015F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA32E37015F.cm

//## begin module%3CA32E37015F.cp preserve=no
//## end module%3CA32E37015F.cp

//## Module: CQLE_GEPreprocessor%3CA32E37015F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\CQLE_GEPreprocessor.h

#ifndef CQLE_GEPreprocessor_h
#define CQLE_GEPreprocessor_h 1

//## begin module%3CA32E37015F.additionalIncludes preserve=no
//## end module%3CA32E37015F.additionalIncludes

//## begin module%3CA32E37015F.includes preserve=yes
//## end module%3CA32E37015F.includes

// CQLEMapScn
#include "Tools\GEMapCompiler\QLEMap\CQLEMapScn.h"
// CMapScene
#include "Tools\GEMapCompiler\MapData\CMapScene.h"
// CMapEntities
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntities.h"
// GammaE_Misc
#include "Misc\GammaE_Misc.h"
//## begin module%3CA32E37015F.additionalDeclarations preserve=yes
//## end module%3CA32E37015F.additionalDeclarations


//## begin CQLE_GEPreprocessor%3CA32E37015F.preface preserve=yes
//## end CQLE_GEPreprocessor%3CA32E37015F.preface

//## Class: CQLE_GEPreprocessor%3CA32E37015F
//## Category: Tools::GEMapCompiler%3CA0F23A02A7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CA345330187;CQLEMapScn { -> }
//## Uses: <unnamed>%3CAA3FFF03A8;CMapEntities { -> }
//## Uses: <unnamed>%3CD1B27303B2;GammaE_Misc { -> }

class CQLE_GEPreprocessor 
{
  //## begin CQLE_GEPreprocessor%3CA32E37015F.initialDeclarations preserve=yes
  //## end CQLE_GEPreprocessor%3CA32E37015F.initialDeclarations

  public:
    //## Constructors (generated)
      CQLE_GEPreprocessor();

    //## Destructor (generated)
      ~CQLE_GEPreprocessor();


    //## Other Operations (specified)
      //## Operation: Preprocess%1017327540
      static void Preprocess (CQLEMapScn *_poMap);

      //## Operation: poGenerateTrigger%1020982174
      static CMapEntity * poGenerateTrigger (CQLEObject *_poObj, CQLEMapScn *_poMap, CMapScene* _poRoom);

      //## Operation: poGenerateTargetMultiple%1021107564
      static CMapEntity * poGenerateTargetMultiple (CQLEObject *_poObj, CQLEMapScn *_poMap, CMapScene* _poRoom);

      //## Operation: poGeneratePlatform%1021126162
      static CMapEntity * poGeneratePlatform (CQLEObject *_poObj, CQLEMapScn *_poMap, CMapScene* _poRoom);

      //## Operation: SetWorldSpaceSubobjects%1017778988
      static void SetWorldSpaceSubobjects (CQLEMapScn *_poMap, CQLEObject* _poObj, CVect3 _oOfs);

    // Data Members for Associations

      //## Association: Tools::GEMapCompiler::<unnamed>%3CA32E920105
      //## Role: CQLE_GEPreprocessor::aoQLERoom%3CA32E930126
      //## begin CQLE_GEPreprocessor::aoQLERoom%3CA32E930126.role preserve=no  public: static CMapScene { -> RHAN}
      static CDynArray <CMapScene *> aoQLERoom;
      //## end CQLE_GEPreprocessor::aoQLERoom%3CA32E930126.role

      //## Association: Tools::GEMapCompiler::<unnamed>%3CA43D2A029D
      //## Role: CQLE_GEPreprocessor::aoQLEConn%3CA43D2A03D4
      //## begin CQLE_GEPreprocessor::aoQLEConn%3CA43D2A03D4.role preserve=no  public: static CMapScene { -> UHAN}
      static CDynArray <CMapScene*> aoQLEConn;
      //## end CQLE_GEPreprocessor::aoQLEConn%3CA43D2A03D4.role

    // Additional Public Declarations
      //## begin CQLE_GEPreprocessor%3CA32E37015F.public preserve=yes
      //## end CQLE_GEPreprocessor%3CA32E37015F.public

  protected:

    //## Other Operations (specified)
      //## Operation: GenerateRoom%1017327541
      static void GenerateRoom (CQLEObject *_poObj, CQLEMapScn *_poMap, CMapScene* _poRoom);

      //## Operation: GenerateConnectors%1017392881
      static void GenerateConnectors (CQLEMapScn *_poMap);

    // Data Members for Class Attributes

      //## Attribute: pbBrushInRoom%3CA430450065
      //## begin CQLE_GEPreprocessor::pbBrushInRoom%3CA430450065.attr preserve=no  protected: static bool* {UA} NULL
      static bool* pbBrushInRoom;
      //## end CQLE_GEPreprocessor::pbBrushInRoom%3CA430450065.attr

    // Additional Protected Declarations
      //## begin CQLE_GEPreprocessor%3CA32E37015F.protected preserve=yes
      //## end CQLE_GEPreprocessor%3CA32E37015F.protected

  private:
    // Additional Private Declarations
      //## begin CQLE_GEPreprocessor%3CA32E37015F.private preserve=yes
      //## end CQLE_GEPreprocessor%3CA32E37015F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CQLE_GEPreprocessor%3CA32E37015F.implementation preserve=yes
      //## end CQLE_GEPreprocessor%3CA32E37015F.implementation

};

//## begin CQLE_GEPreprocessor%3CA32E37015F.postscript preserve=yes
//## end CQLE_GEPreprocessor%3CA32E37015F.postscript

// Class CQLE_GEPreprocessor 

//## begin module%3CA32E37015F.epilog preserve=yes
//## end module%3CA32E37015F.epilog


#endif
