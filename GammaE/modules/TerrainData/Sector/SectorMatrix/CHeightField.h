//## begin module%3AF9BE740014.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF9BE740014.cm

//## begin module%3AF9BE740014.cp preserve=no
//## end module%3AF9BE740014.cp

//## Module: CHeightField%3AF9BE740014; Pseudo Package specification
//## Source file: i:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CHeightField.h

#ifndef CHeightField_h
#define CHeightField_h 1

//## begin module%3AF9BE740014.additionalIncludes preserve=no
//## end module%3AF9BE740014.additionalIncludes

//## begin module%3AF9BE740014.includes preserve=yes
//## end module%3AF9BE740014.includes

// CSectorMatrix
#include "TerrainData\Sector\SectorMatrix\CSectorMatrix.h"
// CHFSector_FN
#include "TerrainData\Sector\HeightField\CHFSector_FN.h"
// CSLM_HFieldSect
#include "TerrainData\Sector\SectorMatrix\CSectorLoaderManager\CSLM_HFieldSect.h"
//## begin module%3AF9BE740014.additionalDeclarations preserve=yes

typedef struct{
	float fMaxHeight;	
	float fMinHeight;
}THeightFieldData;

//## end module%3AF9BE740014.additionalDeclarations


//## begin CHeightField%3AF9BE740014.preface preserve=yes
//## end CHeightField%3AF9BE740014.preface

//## Class: CHeightField%3AF9BE740014
//## Category: TerrainData::Sector::SectorMatrix%3AF9B6CF0384
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AFB0DBA00AA;CHFSector_FN { -> }
//## Uses: <unnamed>%3B31331500AA;CSLM_HFieldSect { -> }

class CHeightField : public CSectorMatrix  //## Inherits: <unnamed>%3AF9BE86035C
{
  //## begin CHeightField%3AF9BE740014.initialDeclarations preserve=yes
  //## end CHeightField%3AF9BE740014.initialDeclarations

  public:
    //## Constructors (generated)
      CHeightField();

    //## Destructor (generated)
      ~CHeightField();


    //## Other Operations (specified)
      //## Operation: CreateClass%989530853
      virtual CSector * CreateClass ();

      //## Operation: Init%989530856
      virtual void Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21);

      //## Operation: DataSize%989530863
      virtual unsigned long DataSize ();

      //## Operation: GetMaxHeight%990479649
      virtual float GetMaxHeight ();

      //## Operation: GetMinHeight%990479650
      virtual float GetMinHeight ();

      //## Operation: SetValue%990479657
      virtual void SetValue (int _X, int _Y, CSectElem &_Value);

      //## Operation: SetValueFromSect%990479658
      virtual void SetValueFromSect (int _iSect, int _X, int _Y, CSectElem &_Value);

      //## Operation: RecomputeMaxMins%990479659
      void RecomputeMaxMins ();

      //## Operation: GenerateLOD%991345748
      //	Generates a new object with  data corresponding to a
      //	given LOD
      virtual CSector * GenerateLOD (int _iLOD);

      //## Operation: GetValueF%1026770435
      virtual CSectElem & GetValueF (float _fX, float _fY);

    // Additional Public Declarations
      //## begin CHeightField%3AF9BE740014.public preserve=yes
      //## end CHeightField%3AF9BE740014.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: HFData%3AFB0A6C01E0
      //## begin CHeightField::HFData%3AFB0A6C01E0.attr preserve=no  protected: THeightFieldData {UA} 
      THeightFieldData HFData;
      //## end CHeightField::HFData%3AFB0A6C01E0.attr

    // Additional Protected Declarations
      //## begin CHeightField%3AF9BE740014.protected preserve=yes
      //## end CHeightField%3AF9BE740014.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: bRecomputeMaxMins%3B09904B00D2
      //## begin CHeightField::bRecomputeMaxMins%3B09904B00D2.attr preserve=no  private: bool {UA} false
      bool bRecomputeMaxMins;
      //## end CHeightField::bRecomputeMaxMins%3B09904B00D2.attr

    // Additional Private Declarations
      //## begin CHeightField%3AF9BE740014.private preserve=yes
      //## end CHeightField%3AF9BE740014.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHeightField%3AF9BE740014.implementation preserve=yes
      //## end CHeightField%3AF9BE740014.implementation

};

//## begin CHeightField%3AF9BE740014.postscript preserve=yes
//## end CHeightField%3AF9BE740014.postscript

// Class CHeightField 

//## begin module%3AF9BE740014.epilog preserve=yes
//## end module%3AF9BE740014.epilog


#endif
