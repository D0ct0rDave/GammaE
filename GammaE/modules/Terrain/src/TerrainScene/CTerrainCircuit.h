//## begin module%3AFEFDB300B4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFEFDB300B4.cm

//## begin module%3AFEFDB300B4.cp preserve=no
//## end module%3AFEFDB300B4.cp

//## Module: CTerrainCircuit%3AFEFDB300B4; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Terrain\TerrainScene\CTerrainCircuit.h

#ifndef CTerrainCircuit_h
#define CTerrainCircuit_h 1

//## begin module%3AFEFDB300B4.additionalIncludes preserve=no
//## end module%3AFEFDB300B4.additionalIncludes

//## begin module%3AFEFDB300B4.includes preserve=yes
//## end module%3AFEFDB300B4.includes

// CLODSelector
#include "Terrain\TerrainMath\CLODSelector.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
//## begin module%3AFEFDB300B4.additionalDeclarations preserve=yes
//## end module%3AFEFDB300B4.additionalDeclarations


//## begin CTerrainCircuit%3AFEFDB300B4.preface preserve=yes
//## end CTerrainCircuit%3AFEFDB300B4.preface

//## Class: CTerrainCircuit%3AFEFDB300B4
//## Category: Terrain::TerrainScene%3AFEFA9E0154
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTerrainCircuit : public CObject3D_Node  //## Inherits: <unnamed>%3B018F260000
{
  //## begin CTerrainCircuit%3AFEFDB300B4.initialDeclarations preserve=yes
  //## end CTerrainCircuit%3AFEFDB300B4.initialDeclarations

  public:
    //## Constructors (generated)
      CTerrainCircuit();

    //## Destructor (generated)
      virtual ~CTerrainCircuit();


    //## Other Operations (specified)
      //## Operation: Init%994715399
      void Init (int _SecsPerRow, int _SecsPerCol, float _SectorSize);

      //## Operation: SetSector%990048933
      void SetSector (int _iX, int _iY, CObject3D *_pSector);

      //## Operation: Render%989790242
      virtual void Render ();

      //## Operation: ComputeVISLODMatrix%995406154
      void ComputeVISLODMatrix ();

      //## Operation: ComputeLODArrays%995488540
      void ComputeLODArrays (int iX, int iY);

      //## Operation: SetLOD%995639486
      void SetLOD (int iBlockIdx, int iX, int iY);

      //## Operation: BlockInRange%995639485
      bool BlockInRange (int iX, int iY);

    //## Get and Set Operations for Associations (generated)

      //## Association: Terrain::TerrainScene::<unnamed>%3B54BB910168
      //## Role: CTerrainCircuit::LODSelector%3B54BB910213
      CLODSelector * GetLODSelector ();
      void SetLODSelector (CLODSelector * value);

    // Data Members for Associations

      //## Association: Terrain::TerrainScene::<unnamed>%3B54BB910168
      //## begin CTerrainCircuit::LODSelector%3B54BB910213.role preserve=no  public: CLODSelector { -> RHAN}
      CLODSelector *LODSelector;
      //## end CTerrainCircuit::LODSelector%3B54BB910213.role

    // Additional Public Declarations
      //## begin CTerrainCircuit%3AFEFDB300B4.public preserve=yes
      //## end CTerrainCircuit%3AFEFDB300B4.public

  protected:
    // Additional Protected Declarations
      //## begin CTerrainCircuit%3AFEFDB300B4.protected preserve=yes
      //## end CTerrainCircuit%3AFEFDB300B4.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: SecsPerRow%3AFEFDBC019A
      //## begin CTerrainCircuit::SecsPerRow%3AFEFDBC019A.attr preserve=no  private: int {UA} 0
      int SecsPerRow;
      //## end CTerrainCircuit::SecsPerRow%3AFEFDBC019A.attr

      //## Attribute: SecsPerCol%3AFEFDC402BC
      //## begin CTerrainCircuit::SecsPerCol%3AFEFDC402BC.attr preserve=no  private: int {UA} 0
      int SecsPerCol;
      //## end CTerrainCircuit::SecsPerCol%3AFEFDC402BC.attr

      //## Attribute: SectorSize%3B02F71302EE
      //## begin CTerrainCircuit::SectorSize%3B02F71302EE.attr preserve=no  private: float {UA} 0
      float SectorSize;
      //## end CTerrainCircuit::SectorSize%3B02F71302EE.attr

      //## Attribute: iLODs%3B521A1801AE
      //## begin CTerrainCircuit::iLODs%3B521A1801AE.attr preserve=no  private: int[5] {UA} 
      int iLODs[5];
      //## end CTerrainCircuit::iLODs%3B521A1801AE.attr

      //## Attribute: fLODs%3B521A21003C
      //## begin CTerrainCircuit::fLODs%3B521A21003C.attr preserve=no  private: float[5] {UA} 
      float fLODs[5];
      //## end CTerrainCircuit::fLODs%3B521A21003C.attr

      //## Attribute: fLODMatrix%3B54B4AC0302
      //## begin CTerrainCircuit::fLODMatrix%3B54B4AC0302.attr preserve=no  private: float * {UA} NULL
      float *fLODMatrix;
      //## end CTerrainCircuit::fLODMatrix%3B54B4AC0302.attr

      //## Attribute: bVISMatrix%3B54B4B600A0
      //## begin CTerrainCircuit::bVISMatrix%3B54B4B600A0.attr preserve=no  private: bool * {UA} NULL
      bool *bVISMatrix;
      //## end CTerrainCircuit::bVISMatrix%3B54B4B600A0.attr

    // Additional Private Declarations
      //## begin CTerrainCircuit%3AFEFDB300B4.private preserve=yes
      //## end CTerrainCircuit%3AFEFDB300B4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTerrainCircuit%3AFEFDB300B4.implementation preserve=yes
      //## end CTerrainCircuit%3AFEFDB300B4.implementation

};

//## begin CTerrainCircuit%3AFEFDB300B4.postscript preserve=yes
//## end CTerrainCircuit%3AFEFDB300B4.postscript

// Class CTerrainCircuit 

//## Get and Set Operations for Associations (inline)

inline CLODSelector * CTerrainCircuit::GetLODSelector ()
{
  //## begin CTerrainCircuit::GetLODSelector%3B54BB910213.get preserve=no
  return LODSelector;
  //## end CTerrainCircuit::GetLODSelector%3B54BB910213.get
}

inline void CTerrainCircuit::SetLODSelector (CLODSelector * value)
{
  //## begin CTerrainCircuit::SetLODSelector%3B54BB910213.set preserve=no
  LODSelector = value;
  //## end CTerrainCircuit::SetLODSelector%3B54BB910213.set
}

//## begin module%3AFEFDB300B4.epilog preserve=yes
//## end module%3AFEFDB300B4.epilog


#endif
