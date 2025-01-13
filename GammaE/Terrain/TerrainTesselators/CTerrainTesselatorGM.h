//## begin module%3AFEFFA101CC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFFA101CC.cm

//## begin module%3AFEFFA101CC.cp preserve=no
//## end module%3AFEFFA101CC.cp

//## Module: CTerrainTesselatorGM%3AFEFFA101CC; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Terrain\TerrainTesselators\CTerrainTesselatorGM.h

#ifndef CTerrainTesselatorGM_h
#define CTerrainTesselatorGM_h 1

//## begin module%3AFEFFA101CC.additionalIncludes preserve=no
//## end module%3AFEFFA101CC.additionalIncludes

//## begin module%3AFEFFA101CC.includes preserve=yes
//## end module%3AFEFFA101CC.includes

// CTerrainTesselator
#include "Terrain\TerrainTesselators\CTerrainTesselator.h"
// GammaE_E3D
#include "E3D\GammaE_E3D.h"
//## begin module%3AFEFFA101CC.additionalDeclarations preserve=yes
//## end module%3AFEFFA101CC.additionalDeclarations


//## begin CTerrainTesselatorGM%3AFEFFA101CC.preface preserve=yes
//## end CTerrainTesselatorGM%3AFEFFA101CC.preface

//## Class: CTerrainTesselatorGM%3AFEFFA101CC
//## Category: Terrain::TerrainTesselators%3AFEFF2E0294
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C6C4E4303A9;GammaE_E3D { -> }

class CTerrainTesselatorGM : public CTerrainTesselator  //## Inherits: <unnamed>%3AFEFFB8038E
{
  //## begin CTerrainTesselatorGM%3AFEFFA101CC.initialDeclarations preserve=yes
  //## end CTerrainTesselatorGM%3AFEFFA101CC.initialDeclarations

  public:
    //## Constructors (generated)
      CTerrainTesselatorGM();

    //## Destructor (generated)
      ~CTerrainTesselatorGM();


    //## Other Operations (specified)
      //## Operation: Init%989790244
      void Init (int iMaxVertexs);

      //## Operation: Invalidate%990132091
      void Invalidate ();

      //## Operation: GenerateVertexData%990132088
      void GenerateVertexData ();

      //## Operation: GenerateVertexColorData%995233491
      void GenerateVertexColorData ();

      //## Operation: GenerateLightData%990132090
      void GenerateLightData ();

      //## Operation: GenerateGlobalCoordData%990132089
      void GenerateGlobalCoordData ();

      //## Operation: GetTileLOD%995799277
      int GetTileLOD (float fDistance, int iMaxLODs);

      //## Operation: TesselateGrid%990132095
      void TesselateGrid ();

      //## Operation: Render%989790245
      virtual void Render ();

      //## Operation: SetupRenderVariables%995233496
      void SetupRenderVariables ();

      //## Operation: GenerateHeightData%990132087
      void GenerateHeightData ();

      //## Operation: GenerateHeightData_Inner%995639493
      void GenerateHeightData_Inner (float fFactor);

      //## Operation: GenerateHeightData_Horizontal_3pN%995639487
      void GenerateHeightData_Horizontal_3pN (int iNeight, int iY);

      //## Operation: GenerateHeightData_Vertical_3pN%995639488
      void GenerateHeightData_Vertical_3pN (int iNeight, int iX);

      //## Operation: GenerateHeightData_Horizontal_N%995639489
      void GenerateHeightData_Horizontal_N (int iNeight, int iY);

      //## Operation: GenerateHeightData_Vertical_N%995639490
      void GenerateHeightData_Vertical_N (int iNeight, int iX);

      //## Operation: GenerateHeightData_Horizontal%995639491
      void GenerateHeightData_Horizontal (int iY, int iRes, float fFactor);

      //## Operation: GenerateHeightData_Vertical%995639492
      void GenerateHeightData_Vertical (int iX, int iRes, float fFactor);

      //## Operation: SetupTileMaterial%996008330
      void SetupTileMaterial ();

      //## Operation: SetTileLODPar%996008331
      void SetTileLODPar (float _fTileLODPar);

      //## Operation: SetBoundVol%996790583
      void SetBoundVol (CGraphBV *_BVol);

    // Additional Public Declarations
      //## begin CTerrainTesselatorGM%3AFEFFA101CC.public preserve=yes
      //## end CTerrainTesselatorGM%3AFEFFA101CC.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: HData%3AFEFFC302DA
      //## begin CTerrainTesselatorGM::HData%3AFEFFC302DA.attr preserve=no  protected: float * {UA} NULL
      float *HData;
      //## end CTerrainTesselatorGM::HData%3AFEFFC302DA.attr

      //## Attribute: LData%3B520EA90190
      //## begin CTerrainTesselatorGM::LData%3B520EA90190.attr preserve=no  protected: float * {UA} NULL
      float *LData;
      //## end CTerrainTesselatorGM::LData%3B520EA90190.attr

      //## Attribute: VXs%3AFEFFCD0046
      //## begin CTerrainTesselatorGM::VXs%3AFEFFCD0046.attr preserve=no  protected: CVect3 * {UA} NULL
      CVect3 *VXs;
      //## end CTerrainTesselatorGM::VXs%3AFEFFCD0046.attr

      //## Attribute: VCs%3AFEFFD402F8
      //## begin CTerrainTesselatorGM::VCs%3AFEFFD402F8.attr preserve=no  protected: CVect4 * {UA} NULL
      CVect4 *VCs;
      //## end CTerrainTesselatorGM::VCs%3AFEFFD402F8.attr

      //## Attribute: UVs%3AFEFFDC029E
      //## begin CTerrainTesselatorGM::UVs%3AFEFFDC029E.attr preserve=no  protected: CVect2 * {UA} NULL
      CVect2 *UVs;
      //## end CTerrainTesselatorGM::UVs%3AFEFFDC029E.attr

      //## Attribute: Idxs%3B0438C900B4
      //## begin CTerrainTesselatorGM::Idxs%3B0438C900B4.attr preserve=no  protected: unsigned short * {UA} NULL
      unsigned short *Idxs;
      //## end CTerrainTesselatorGM::Idxs%3B0438C900B4.attr

      //## Attribute: MaxVertexs%3B04373D03A2
      //## begin CTerrainTesselatorGM::MaxVertexs%3B04373D03A2.attr preserve=no  protected: int {UA} 0
      int MaxVertexs;
      //## end CTerrainTesselatorGM::MaxVertexs%3B04373D03A2.attr

      //## Attribute: Mesh%3B043BBD0230
      //## begin CTerrainTesselatorGM::Mesh%3B043BBD0230.attr preserve=no  protected: CMesh * {UA} NULL
      CMesh *Mesh;
      //## end CTerrainTesselatorGM::Mesh%3B043BBD0230.attr

      //## Attribute: uiSectorRes%3B043CD500F0
      //	Global variable
      //## begin CTerrainTesselatorGM::uiSectorRes%3B043CD500F0.attr preserve=no  protected: unsigned int {UA} 0
      unsigned int uiSectorRes;
      //## end CTerrainTesselatorGM::uiSectorRes%3B043CD500F0.attr

      //## Attribute: fTileLODPar%3B5AB67D037A
      //## begin CTerrainTesselatorGM::fTileLODPar%3B5AB67D037A.attr preserve=no  protected: float {UA} 0
      float fTileLODPar;
      //## end CTerrainTesselatorGM::fTileLODPar%3B5AB67D037A.attr

      //## Attribute: poTileMaterial%3B5DE0E9021C
      //## begin CTerrainTesselatorGM::poTileMaterial%3B5DE0E9021C.attr preserve=no  protected: CE3D_Shader * {UA} 
      CE3D_Shader *poTileMaterial;
      //## end CTerrainTesselatorGM::poTileMaterial%3B5DE0E9021C.attr

      //## Attribute: TileTex%3C6C4D9200C9
      //## begin CTerrainTesselatorGM::TileTex%3C6C4D9200C9.attr preserve=no  protected: CE3D_ShIns_Texture {UA} 
      CE3D_ShIns_Texture TileTex;
      //## end CTerrainTesselatorGM::TileTex%3C6C4D9200C9.attr

      //## Attribute: TileOp%3C6C4DB40212
      //## begin CTerrainTesselatorGM::TileOp%3C6C4DB40212.attr preserve=no  protected: CE3D_ShIns_TexOp {UA} 
      CE3D_ShIns_TexOp TileOp;
      //## end CTerrainTesselatorGM::TileOp%3C6C4DB40212.attr

      //## Attribute: TileMatFunc%3B5DE1130122
      //## begin CTerrainTesselatorGM::TileMatFunc%3B5DE1130122.attr preserve=no  protected: CEval_Const {UA} 
      CEval_Const TileMatFunc;
      //## end CTerrainTesselatorGM::TileMatFunc%3B5DE1130122.attr

    // Additional Protected Declarations
      //## begin CTerrainTesselatorGM%3AFEFFA101CC.protected preserve=yes
      //## end CTerrainTesselatorGM%3AFEFFA101CC.protected

  private:
    // Additional Private Declarations
      //## begin CTerrainTesselatorGM%3AFEFFA101CC.private preserve=yes
      //## end CTerrainTesselatorGM%3AFEFFA101CC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTerrainTesselatorGM%3AFEFFA101CC.implementation preserve=yes
      //## end CTerrainTesselatorGM%3AFEFFA101CC.implementation

};

//## begin CTerrainTesselatorGM%3AFEFFA101CC.postscript preserve=yes
//## end CTerrainTesselatorGM%3AFEFFA101CC.postscript

// Class CTerrainTesselatorGM 

//## begin module%3AFEFFA101CC.epilog preserve=yes
//## end module%3AFEFFA101CC.epilog


#endif
