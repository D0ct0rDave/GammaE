//## begin module%3AFEFE430136.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFE430136.cm

//## begin module%3AFEFE430136.cp preserve=no
//## end module%3AFEFE430136.cp

//## Module: CTerrainSector%3AFEFE430136; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Terrain\TerrainScene\CTerrainSector.h

#ifndef CTerrainSector_h
#define CTerrainSector_h 1

//## begin module%3AFEFE430136.additionalIncludes preserve=no
//## end module%3AFEFE430136.additionalIncludes

//## begin module%3AFEFE430136.includes preserve=yes
//## end module%3AFEFE430136.includes

// CTileBookmark
#include "Terrain\TerrainMaterials\CTileBookmark.h"
// CTerrainTesselator
#include "Terrain\TerrainTesselators\CTerrainTesselator.h"
// GammaE_TerrainData
#include "TerrainData\GammaE_TerrainData.h"
// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3AFEFE430136.additionalDeclarations preserve=yes
//## end module%3AFEFE430136.additionalDeclarations


//## begin CTerrainSector%3AFEFE430136.preface preserve=yes
//## end CTerrainSector%3AFEFE430136.preface

//## Class: CTerrainSector%3AFEFE430136
//## Category: Terrain::TerrainScene%3AFEFA9E0154
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B01ABDB0320;GammaE_TerrainData { -> }
//## Uses: <unnamed>%3B01AC0E030C;CTileBookmark { -> }
//## Uses: <unnamed>%3B01AC6900F0;CTerrainTesselator { -> }

class CTerrainSector : public CObject3D  //## Inherits: <unnamed>%3B018EFE023A
{
  //## begin CTerrainSector%3AFEFE430136.initialDeclarations preserve=yes
  //## end CTerrainSector%3AFEFE430136.initialDeclarations

  public:
    //## Constructors (generated)
      CTerrainSector();

    //## Destructor (generated)
      virtual ~CTerrainSector();


    //## Other Operations (specified)
      //## Operation: Render%989790237
      virtual void Render ();

      //## Operation: ComputeBoundVol%997221309
      virtual void ComputeBoundVol ();

      //## Operation: poGetBoundVol%997221310
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: SetMaxsMins%1007327359
      void SetMaxsMins (CVect3& _Maxs, CVect3& _Mins);

    // Data Members for Class Attributes

      //## Attribute: HF%3B01AB7A03CA
      //## begin CTerrainSector::HF%3B01AB7A03CA.attr preserve=no  public: CHFSector * {UA} NULL
      CHFSector *HF;
      //## end CTerrainSector::HF%3B01AB7A03CA.attr

      //## Attribute: LM%3B01AB8C0294
      //## begin CTerrainSector::LM%3B01AB8C0294.attr preserve=no  public: CLMSector * {UA} NULL
      CLMSector *LM;
      //## end CTerrainSector::LM%3B01AB8C0294.attr

      //## Attribute: TM%3B01AB9701A4
      //## begin CTerrainSector::TM%3B01AB9701A4.attr preserve=no  public: CTMSector * {UA} NULL
      CTMSector *TM;
      //## end CTerrainSector::TM%3B01AB9701A4.attr

      //## Attribute: TB%3B01AB9C024E
      //## begin CTerrainSector::TB%3B01AB9C024E.attr preserve=no  public: CTileBookmark * {UA} NULL
      CTileBookmark *TB;
      //## end CTerrainSector::TB%3B01AB9C024E.attr

      //## Attribute: Tess%3B01ABA70050
      //## begin CTerrainSector::Tess%3B01ABA70050.attr preserve=no  public: CTerrainTesselator * {UA} NULL
      CTerrainTesselator *Tess;
      //## end CTerrainSector::Tess%3B01ABA70050.attr

      //## Attribute: fXYScale%3B043E9700BE
      //## begin CTerrainSector::fXYScale%3B043E9700BE.attr preserve=no  public: float {UA} 0
      float fXYScale;
      //## end CTerrainSector::fXYScale%3B043E9700BE.attr

    // Additional Public Declarations
      //## begin CTerrainSector%3AFEFE430136.public preserve=yes
      //## end CTerrainSector%3AFEFE430136.public

  protected:
    // Additional Protected Declarations
      //## begin CTerrainSector%3AFEFE430136.protected preserve=yes
      //## end CTerrainSector%3AFEFE430136.protected

  private:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: fLODs%3AFEFED703AC
      float * GetfLODs ();

    // Data Members for Class Attributes

      //## begin CTerrainSector::fLODs%3AFEFED703AC.attr preserve=no  private: float * {UA} NULL
      float *fLODs;
      //## end CTerrainSector::fLODs%3AFEFED703AC.attr

      //## Attribute: iLODs%3AFEFEE50230
      //## begin CTerrainSector::iLODs%3AFEFEE50230.attr preserve=no  private: int * {UA} NULL
      int *iLODs;
      //## end CTerrainSector::iLODs%3AFEFEE50230.attr

      //## Attribute: Mins%3C0ABEA202E3
      //## begin CTerrainSector::Mins%3C0ABEA202E3.attr preserve=no  private: CVect3 {UA} 
      CVect3 Mins;
      //## end CTerrainSector::Mins%3C0ABEA202E3.attr

      //## Attribute: Maxs%3C0ABEA60339
      //## begin CTerrainSector::Maxs%3C0ABEA60339.attr preserve=no  private: CVect3 {UA} 
      CVect3 Maxs;
      //## end CTerrainSector::Maxs%3C0ABEA60339.attr

    // Additional Private Declarations
      //## begin CTerrainSector%3AFEFE430136.private preserve=yes
      //## end CTerrainSector%3AFEFE430136.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTerrainSector%3AFEFE430136.implementation preserve=yes
      //## end CTerrainSector%3AFEFE430136.implementation

};

//## begin CTerrainSector%3AFEFE430136.postscript preserve=yes
//## end CTerrainSector%3AFEFE430136.postscript

// Class CTerrainSector 

//## Get and Set Operations for Class Attributes (inline)

inline float * CTerrainSector::GetfLODs ()
{
  //## begin CTerrainSector::GetfLODs%3AFEFED703AC.get preserve=no
  return fLODs;
  //## end CTerrainSector::GetfLODs%3AFEFED703AC.get
}

//## begin module%3AFEFE430136.epilog preserve=yes
//## end module%3AFEFE430136.epilog


#endif
