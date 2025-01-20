//## begin module%3B5C902D0082.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B5C902D0082.cm

//## begin module%3B5C902D0082.cp preserve=no
//## end module%3B5C902D0082.cp

//## Module: CTerrainTesselatorTileGM%3B5C902D0082; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Terrain\TerrainTesselators\CTerrainTesselatorTileGM.h

#ifndef CTerrainTesselatorTileGM_h
#define CTerrainTesselatorTileGM_h 1

//## begin module%3B5C902D0082.additionalIncludes preserve=no
//## end module%3B5C902D0082.additionalIncludes

//## begin module%3B5C902D0082.includes preserve=yes
//## end module%3B5C902D0082.includes

// CTerrainTesselatorGM
#include "Terrain\TerrainTesselators\CTerrainTesselatorGM.h"
//## begin module%3B5C902D0082.additionalDeclarations preserve=yes
//## end module%3B5C902D0082.additionalDeclarations


//## begin CTerrainTesselatorTileGM%3B5C902D0082.preface preserve=yes
//## end CTerrainTesselatorTileGM%3B5C902D0082.preface

//## Class: CTerrainTesselatorTileGM%3B5C902D0082
//## Category: Terrain::TerrainTesselators%3AFEFF2E0294
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTerrainTesselatorTileGM : public CTerrainTesselatorGM  //## Inherits: <unnamed>%3B5C91280280
{
  //## begin CTerrainTesselatorTileGM%3B5C902D0082.initialDeclarations preserve=yes
  //## end CTerrainTesselatorTileGM%3B5C902D0082.initialDeclarations

  public:
    //## Constructors (generated)
      CTerrainTesselatorTileGM();

    //## Destructor (generated)
      ~CTerrainTesselatorTileGM();


    //## Other Operations (specified)
      //## Operation: GenerateTileCoordData%995922489
      void GenerateTileCoordData ();

      //## Operation: RenderTile%995922490
      void RenderTile (int iX, int iY);

      //## Operation: RenderTiling%995922491
      void RenderTiling ();

      //## Operation: GetTileMaterial%995922492
      CE3D_Shader * GetTileMaterial (int iX, int iY);

    // Additional Public Declarations
      //## begin CTerrainTesselatorTileGM%3B5C902D0082.public preserve=yes
      //## end CTerrainTesselatorTileGM%3B5C902D0082.public

  protected:
    // Additional Protected Declarations
      //## begin CTerrainTesselatorTileGM%3B5C902D0082.protected preserve=yes
      //## end CTerrainTesselatorTileGM%3B5C902D0082.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Tile_iMaxSteps%3B5C912F0118
      //## begin CTerrainTesselatorTileGM::Tile_iMaxSteps%3B5C912F0118.attr preserve=no  private: int {UA} 0
      int Tile_iMaxSteps;
      //## end CTerrainTesselatorTileGM::Tile_iMaxSteps%3B5C912F0118.attr

      //## Attribute: Tile_iSteps%3B5C913C02E4
      //## begin CTerrainTesselatorTileGM::Tile_iSteps%3B5C913C02E4.attr preserve=no  private: int {UA} 0
      int Tile_iSteps;
      //## end CTerrainTesselatorTileGM::Tile_iSteps%3B5C913C02E4.attr

      //## Attribute: Tile_iGridStep%3B5C914103C0
      //## begin CTerrainTesselatorTileGM::Tile_iGridStep%3B5C914103C0.attr preserve=no  private: int {UA} 0
      int Tile_iGridStep;
      //## end CTerrainTesselatorTileGM::Tile_iGridStep%3B5C914103C0.attr

      //## Attribute: Tile_iStride%3B5C91540244
      //## begin CTerrainTesselatorTileGM::Tile_iStride%3B5C91540244.attr preserve=no  private: int {UA} 0
      int Tile_iStride;
      //## end CTerrainTesselatorTileGM::Tile_iStride%3B5C91540244.attr

      //## Attribute: Tile_fTexStep%3B5C915A0190
      //## begin CTerrainTesselatorTileGM::Tile_fTexStep%3B5C915A0190.attr preserve=no  private: float {UA} 0
      float Tile_fTexStep;
      //## end CTerrainTesselatorTileGM::Tile_fTexStep%3B5C915A0190.attr

      //## Attribute: Tile_fMeters%3B5C91620320
      //## begin CTerrainTesselatorTileGM::Tile_fMeters%3B5C91620320.attr preserve=no  private: float {UA} 0
      float Tile_fMeters;
      //## end CTerrainTesselatorTileGM::Tile_fMeters%3B5C91620320.attr

      //## Attribute: Tile_Tile%3B5C916900AA
      //## begin CTerrainTesselatorTileGM::Tile_Tile%3B5C916900AA.attr preserve=no  private: CTile * {UA} NULL
      CTile *Tile_Tile;
      //## end CTerrainTesselatorTileGM::Tile_Tile%3B5C916900AA.attr

    // Additional Private Declarations
      //## begin CTerrainTesselatorTileGM%3B5C902D0082.private preserve=yes
      //## end CTerrainTesselatorTileGM%3B5C902D0082.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTerrainTesselatorTileGM%3B5C902D0082.implementation preserve=yes
      //## end CTerrainTesselatorTileGM%3B5C902D0082.implementation

};

//## begin CTerrainTesselatorTileGM%3B5C902D0082.postscript preserve=yes
//## end CTerrainTesselatorTileGM%3B5C902D0082.postscript

// Class CTerrainTesselatorTileGM 

//## begin module%3B5C902D0082.epilog preserve=yes
//## end module%3B5C902D0082.epilog


#endif
