//## begin module%3B4658C503C0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B4658C503C0.cm

//## begin module%3B4658C503C0.cp preserve=no
//## end module%3B4658C503C0.cp

//## Module: TERSceneLoader%3B4658C503C0; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Terrain\TerrainScene\SceneLoaders\TERScene\TERSceneLoader.h

#ifndef TERSceneLoader_h
#define TERSceneLoader_h 1

//## begin module%3B4658C503C0.additionalIncludes preserve=no
//## end module%3B4658C503C0.additionalIncludes

//## begin module%3B4658C503C0.includes preserve=yes
#include "Terrain\TerrainScene\SceneLoaders\EnvPars\EnvPars.h"
//## end module%3B4658C503C0.includes

// CSkyBox
#include "SceneObjects\SkyBox\CSkyBox.h"
// CSkyDome
#include "SceneObjects\SkyDome\CSkyDome.h"
// CTileBookmark
#include "Terrain\TerrainMaterials\CTileBookmark.h"
// CTerrainCircuit
#include "Terrain\TerrainScene\CTerrainCircuit.h"
// CTerrainSector
#include "Terrain\TerrainScene\CTerrainSector.h"
// CLODSelector_Array
#include "Terrain\TerrainMath\CLODSelector_Array.h"
// CTerrainTesselatorGM
#include "Terrain\TerrainTesselators\CTerrainTesselatorGM.h"
//## begin module%3B4658C503C0.additionalDeclarations preserve=yes
//## end module%3B4658C503C0.additionalDeclarations


//## begin TERSceneLoader%3B4658C503C0.preface preserve=yes
//## end TERSceneLoader%3B4658C503C0.preface

//## Class: TERSceneLoader%3B4658C503C0
//## Category: Terrain::TerrainScene::SceneLoaders::TERScene%3B4658B0010E
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B4658EF03D4;CTerrainSector { -> }
//## Uses: <unnamed>%3B4658F103C0;CTileBookmark { -> }
//## Uses: <unnamed>%3B4658F303DE;CTerrainTesselatorGM { -> }
//## Uses: <unnamed>%3B54BBEC017C;CLODSelector_Array { -> }
//## Uses: <unnamed>%3B4658ED03B6;CTerrainCircuit { -> }

class TERSceneLoader 
{
  //## begin TERSceneLoader%3B4658C503C0.initialDeclarations preserve=yes
  //## end TERSceneLoader%3B4658C503C0.initialDeclarations

  public:
    //## Constructors (generated)
      TERSceneLoader();

    //## Destructor (generated)
      ~TERSceneLoader();


    //## Other Operations (specified)
      //## Operation: Load%994466160
      CObject3D * Load (char *_Filename);

      //## Operation: LoadData%994715397
      void LoadData (FILE *fd);

      //## Operation: GenerateScene%994715398
      CObject3D * GenerateScene ();

      //## Operation: GenerateTileBookmark%994715400
      void GenerateTileBookmark ();

      //## Operation: CreateLODSelector%995406158
      CLODSelector * CreateLODSelector ();

      //## Operation: CreateSkyBox%996522680
      CSkyBox * CreateSkyBox ();

      //## Operation: CreateSkyDome%1001452005
      CSkyDome * CreateSkyDome ();

    // Data Members for Class Attributes

      //## Attribute: HF%3B4A26D001FE
      //## begin TERSceneLoader::HF%3B4A26D001FE.attr preserve=no  public: CHeightField * {UA} NULL
      CHeightField *HF;
      //## end TERSceneLoader::HF%3B4A26D001FE.attr

      //## Attribute: TM%3B4A26DE0050
      //## begin TERSceneLoader::TM%3B4A26DE0050.attr preserve=no  public: CTexMap * {UA} NULL
      CTexMap *TM;
      //## end TERSceneLoader::TM%3B4A26DE0050.attr

      //## Attribute: LM%3B4A26E50370
      //## begin TERSceneLoader::LM%3B4A26E50370.attr preserve=no  public: CLightMap * {UA} NULL
      CLightMap *LM;
      //## end TERSceneLoader::LM%3B4A26E50370.attr

      //## Attribute: TS%3B4A26C6023A
      //## begin TERSceneLoader::TS%3B4A26C6023A.attr preserve=no  public: TTexSet * {UA} NULL
      TTexSet *TS;
      //## end TERSceneLoader::TS%3B4A26C6023A.attr

      //## Attribute: iSectorRes%3B54CD8F0320
      //## begin TERSceneLoader::iSectorRes%3B54CD8F0320.attr preserve=no  public: int {UA} 0
      int iSectorRes;
      //## end TERSceneLoader::iSectorRes%3B54CD8F0320.attr

      //## Attribute: fSectorSize%3B4A2CD201AE
      //## begin TERSceneLoader::fSectorSize%3B4A2CD201AE.attr preserve=no  public: float {UA} 0
      float fSectorSize;
      //## end TERSceneLoader::fSectorSize%3B4A2CD201AE.attr

      //## Attribute: fXYScale%3B52267B003C
      //## begin TERSceneLoader::fXYScale%3B52267B003C.attr preserve=no  public: float {UA} 0
      float fXYScale;
      //## end TERSceneLoader::fXYScale%3B52267B003C.attr

      //## Attribute: fIScale%3D4B9DBF031F
      //## begin TERSceneLoader::fIScale%3D4B9DBF031F.attr preserve=no  public: float {UA} 0
      float fIScale;
      //## end TERSceneLoader::fIScale%3D4B9DBF031F.attr

      //## Attribute: iCircXRes%3D4B9D7C02BF
      //## begin TERSceneLoader::iCircXRes%3D4B9D7C02BF.attr preserve=no  public: int {UA} 0
      int iCircXRes;
      //## end TERSceneLoader::iCircXRes%3D4B9D7C02BF.attr

      //## Attribute: iCircYRes%3D4B9D8D00ED
      //## begin TERSceneLoader::iCircYRes%3D4B9D8D00ED.attr preserve=no  public: int {UA} 0
      int iCircYRes;
      //## end TERSceneLoader::iCircYRes%3D4B9D8D00ED.attr

      //## Attribute: fCircXSize%3D4B9D9002E6
      //## begin TERSceneLoader::fCircXSize%3D4B9D9002E6.attr preserve=no  public: int {UA} 0
      int fCircXSize;
      //## end TERSceneLoader::fCircXSize%3D4B9D9002E6.attr

      //## Attribute: fCircYSize%3D4B9DAE0220
      //## begin TERSceneLoader::fCircYSize%3D4B9DAE0220.attr preserve=no  public: int {UA} 0
      int fCircYSize;
      //## end TERSceneLoader::fCircYSize%3D4B9DAE0220.attr

      //## Attribute: TB%3B4A30D100C8
      //## begin TERSceneLoader::TB%3B4A30D100C8.attr preserve=no  public: CTileBookmark * {UA} NULL
      CTileBookmark *TB;
      //## end TERSceneLoader::TB%3B4A30D100C8.attr

      //## Attribute: EnvPars%3B52249F0352
      //## begin TERSceneLoader::EnvPars%3B52249F0352.attr preserve=no  public: TEnvironmentPars {UA} 
      TEnvironmentPars EnvPars;
      //## end TERSceneLoader::EnvPars%3B52249F0352.attr

    // Data Members for Associations

      //## Association: Terrain::TerrainScene::SceneLoaders::TERScene::<unnamed>%3B770A6E0063
      //## Role: TERSceneLoader::SkyBox%3B770A6E014B
      //## begin TERSceneLoader::SkyBox%3B770A6E014B.role preserve=no  public: CSkyBox { -> RHAN}
      CSkyBox *SkyBox;
      //## end TERSceneLoader::SkyBox%3B770A6E014B.role

      //## Association: Terrain::TerrainScene::SceneLoaders::TERScene::<unnamed>%3BB0FA2401A5
      //## Role: TERSceneLoader::SkyDome%3BB0FA2402B4
      //## begin TERSceneLoader::SkyDome%3BB0FA2402B4.role preserve=no  public: CSkyDome { -> RHAN}
      CSkyDome *SkyDome;
      //## end TERSceneLoader::SkyDome%3BB0FA2402B4.role

    // Additional Public Declarations
      //## begin TERSceneLoader%3B4658C503C0.public preserve=yes
      //## end TERSceneLoader%3B4658C503C0.public

  protected:
    // Additional Protected Declarations
      //## begin TERSceneLoader%3B4658C503C0.protected preserve=yes
      //## end TERSceneLoader%3B4658C503C0.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: ATS%3B65E0AB0000
      //## begin TERSceneLoader::ATS%3B65E0AB0000.attr preserve=no  private: TTexSet * {UA} NULL
      TTexSet *ATS;
      //## end TERSceneLoader::ATS%3B65E0AB0000.attr

    // Additional Private Declarations
      //## begin TERSceneLoader%3B4658C503C0.private preserve=yes
      //## end TERSceneLoader%3B4658C503C0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin TERSceneLoader%3B4658C503C0.implementation preserve=yes
      //## end TERSceneLoader%3B4658C503C0.implementation

};

//## begin TERSceneLoader%3B4658C503C0.postscript preserve=yes
//## end TERSceneLoader%3B4658C503C0.postscript

// Class TERSceneLoader 

//## begin module%3B4658C503C0.epilog preserve=yes
//## end module%3B4658C503C0.epilog


#endif
