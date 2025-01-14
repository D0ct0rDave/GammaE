//## begin module%3C7E070B02A2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E070B02A2.cm

//## begin module%3C7E070B02A2.cp preserve=no
//## end module%3C7E070B02A2.cp

//## Module: GMapData%3C7E070B02A2; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GMapData\GMapData.h

#ifndef GMapData_h
#define GMapData_h 1

//## begin module%3C7E070B02A2.additionalIncludes preserve=no
//## end module%3C7E070B02A2.additionalIncludes

//## begin module%3C7E070B02A2.includes preserve=yes
#include "Scene/GammaE_Scene.h"
//## end module%3C7E070B02A2.includes

// CMapEntity
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntity.h"
// CMapEntities
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntities.h"
//## begin module%3C7E070B02A2.additionalDeclarations preserve=yes
//## end module%3C7E070B02A2.additionalDeclarations


//## begin GMapData%3C7E070B02A2.preface preserve=yes
//## end GMapData%3C7E070B02A2.preface

//## Class: GMapData%3C7E070B02A2
//## Category: Game::GameScene::GameMap::GMapData%3C7E06DC03D1
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7E07AD0359;CMapEntity { -> }
//## Uses: <unnamed>%3C7EB64203CE;CMapEntities { -> }

class GMapData 
{
  //## begin GMapData%3C7E070B02A2.initialDeclarations preserve=yes
  //## end GMapData%3C7E070B02A2.initialDeclarations

  public:
    //## Constructors (generated)
      GMapData();

    //## Destructor (generated)
      ~GMapData();


    //## Other Operations (specified)
      //## Operation: SetEntities%1014892582
      void SetEntities (CMapEntity** _poEntities, int _iNumEntities);

      //## Operation: SetMap%1014892583
      void SetMap (CObject3D_Gen *_poMap);

    // Data Members for Class Attributes

      //## Attribute: poEntity%3C7E07B101ED
      //## begin GMapData::poEntity%3C7E07B101ED.attr preserve=no  public: CMapEntity* * {UA} NULL
      CMapEntity* *poEntity;
      //## end GMapData::poEntity%3C7E07B101ED.attr

      //## Attribute: iNumEntities%3C7E07C10204
      //## begin GMapData::iNumEntities%3C7E07C10204.attr preserve=no  public: int {UA} 0
      int iNumEntities;
      //## end GMapData::iNumEntities%3C7E07C10204.attr

      //## Attribute: poMap%3C7E07EE0367
      //## begin GMapData::poMap%3C7E07EE0367.attr preserve=no  public: CObject3D_Gen * {UA} NULL
      CObject3D_Gen *poMap;
      //## end GMapData::poMap%3C7E07EE0367.attr

    // Additional Public Declarations
      //## begin GMapData%3C7E070B02A2.public preserve=yes
      //## end GMapData%3C7E070B02A2.public

  protected:
    // Additional Protected Declarations
      //## begin GMapData%3C7E070B02A2.protected preserve=yes
      //## end GMapData%3C7E070B02A2.protected

  private:
    // Additional Private Declarations
      //## begin GMapData%3C7E070B02A2.private preserve=yes
      //## end GMapData%3C7E070B02A2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin GMapData%3C7E070B02A2.implementation preserve=yes
      //## end GMapData%3C7E070B02A2.implementation

};

//## begin GMapData%3C7E070B02A2.postscript preserve=yes
//## end GMapData%3C7E070B02A2.postscript

// Class GMapData 

//## begin module%3C7E070B02A2.epilog preserve=yes
//## end module%3C7E070B02A2.epilog


#endif
