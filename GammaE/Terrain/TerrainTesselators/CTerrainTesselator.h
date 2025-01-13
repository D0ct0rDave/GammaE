//## begin module%3AFEFF600212.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFF600212.cm

//## begin module%3AFEFF600212.cp preserve=no
//## end module%3AFEFF600212.cp

//## Module: CTerrainTesselator%3AFEFF600212; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Terrain\TerrainTesselators\CTerrainTesselator.h

#ifndef CTerrainTesselator_h
#define CTerrainTesselator_h 1

//## begin module%3AFEFF600212.additionalIncludes preserve=no
//## end module%3AFEFF600212.additionalIncludes

//## begin module%3AFEFF600212.includes preserve=yes
//## end module%3AFEFF600212.includes

// CTileBookmark
#include "Terrain\TerrainMaterials\CTileBookmark.h"
// CLODSelector
#include "Terrain\TerrainMath\CLODSelector.h"
// GammaE_TerrainData
#include "TerrainData\GammaE_TerrainData.h"
//## begin module%3AFEFF600212.additionalDeclarations preserve=yes
//## end module%3AFEFF600212.additionalDeclarations


//## begin CTerrainTesselator%3AFEFF600212.preface preserve=yes
//## end CTerrainTesselator%3AFEFF600212.preface

//## Class: CTerrainTesselator%3AFEFF600212
//## Category: Terrain::TerrainTesselators%3AFEFF2E0294
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B01A5040262;GammaE_TerrainData { -> }
//## Uses: <unnamed>%3B01AAD503CA;CTileBookmark { -> }

class CTerrainTesselator 
{
  //## begin CTerrainTesselator%3AFEFF600212.initialDeclarations preserve=yes
  //## end CTerrainTesselator%3AFEFF600212.initialDeclarations

  public:
    //## Constructors (generated)
      CTerrainTesselator();

    //## Destructor (generated)
      ~CTerrainTesselator();


    //## Other Operations (specified)
      //## Operation: Render%989790246
      virtual void Render ();

      //## Operation: SetData%989962904
      virtual void SetData (CHFSector* _HF, CLMSector* _LM, CTMSector* _TM, CTileBookmark* _TB, float *_fLODs, int *_iLODs, float _fXYScale);

      //## Operation: SetCameraPos%990132098
      void SetCameraPos (CVect3 _Pos);

    //## Get and Set Operations for Associations (generated)

      //## Association: Terrain::TerrainTesselators::<unnamed>%3B54BFCF015E
      //## Role: CTerrainTesselator::TileLODSel%3B54BFCF0352
      CLODSelector * GetTileLODSel ();
      void SetTileLODSel (CLODSelector * value);

    // Data Members for Associations

      //## Association: Terrain::TerrainTesselators::<unnamed>%3B54BFCF015E
      //## begin CTerrainTesselator::TileLODSel%3B54BFCF0352.role preserve=no  public: CLODSelector { -> RHAN}
      CLODSelector *TileLODSel;
      //## end CTerrainTesselator::TileLODSel%3B54BFCF0352.role

    // Additional Public Declarations
      //## begin CTerrainTesselator%3AFEFF600212.public preserve=yes
      //## end CTerrainTesselator%3AFEFF600212.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: fLODs%3B01A494037A
      //## begin CTerrainTesselator::fLODs%3B01A494037A.attr preserve=no  protected: float * {UA} NULL
      float *fLODs;
      //## end CTerrainTesselator::fLODs%3B01A494037A.attr

      //## Attribute: iLODs%3B01A49A0118
      //## begin CTerrainTesselator::iLODs%3B01A49A0118.attr preserve=no  protected: int * {UA} NULL
      int *iLODs;
      //## end CTerrainTesselator::iLODs%3B01A49A0118.attr

      //## Attribute: HF%3B01A4A10136
      //## begin CTerrainTesselator::HF%3B01A4A10136.attr preserve=no  protected: CHFSector * {UA} NULL
      CHFSector *HF;
      //## end CTerrainTesselator::HF%3B01A4A10136.attr

      //## Attribute: LM%3B01A4A501E0
      //## begin CTerrainTesselator::LM%3B01A4A501E0.attr preserve=no  protected: CLMSector * {UA} NULL
      CLMSector *LM;
      //## end CTerrainTesselator::LM%3B01A4A501E0.attr

      //## Attribute: TM%3B01A4A90258
      //## begin CTerrainTesselator::TM%3B01A4A90258.attr preserve=no  protected: CTMSector * {UA} NULL
      CTMSector *TM;
      //## end CTerrainTesselator::TM%3B01A4A90258.attr

      //## Attribute: TB%3B01A4AD0230
      //## begin CTerrainTesselator::TB%3B01A4AD0230.attr preserve=no  protected: CTileBookmark * {UA} NULL
      CTileBookmark *TB;
      //## end CTerrainTesselator::TB%3B01A4AD0230.attr

      //## Attribute: Cam%3B043D5803B6
      //## begin CTerrainTesselator::Cam%3B043D5803B6.attr preserve=no  protected: CVect3 {UA} 
      CVect3 Cam;
      //## end CTerrainTesselator::Cam%3B043D5803B6.attr

      //## Attribute: fXYScale%3B043F5C02BC
      //## begin CTerrainTesselator::fXYScale%3B043F5C02BC.attr preserve=no  protected: float {UA} NULL
      float fXYScale;
      //## end CTerrainTesselator::fXYScale%3B043F5C02BC.attr

    // Additional Protected Declarations
      //## begin CTerrainTesselator%3AFEFF600212.protected preserve=yes
      //## end CTerrainTesselator%3AFEFF600212.protected

  private:
    // Additional Private Declarations
      //## begin CTerrainTesselator%3AFEFF600212.private preserve=yes
      //## end CTerrainTesselator%3AFEFF600212.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTerrainTesselator%3AFEFF600212.implementation preserve=yes
      //## end CTerrainTesselator%3AFEFF600212.implementation

};

//## begin CTerrainTesselator%3AFEFF600212.postscript preserve=yes
//## end CTerrainTesselator%3AFEFF600212.postscript

// Class CTerrainTesselator 

//## Get and Set Operations for Associations (inline)

inline CLODSelector * CTerrainTesselator::GetTileLODSel ()
{
  //## begin CTerrainTesselator::GetTileLODSel%3B54BFCF0352.get preserve=no
  return TileLODSel;
  //## end CTerrainTesselator::GetTileLODSel%3B54BFCF0352.get
}

inline void CTerrainTesselator::SetTileLODSel (CLODSelector * value)
{
  //## begin CTerrainTesselator::SetTileLODSel%3B54BFCF0352.set preserve=no
  TileLODSel = value;
  //## end CTerrainTesselator::SetTileLODSel%3B54BFCF0352.set
}

//## begin module%3AFEFF600212.epilog preserve=yes
//## end module%3AFEFF600212.epilog


#endif
