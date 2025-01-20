//## begin module%3B5DED78033E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B5DED78033E.cm

//## begin module%3B5DED78033E.cp preserve=no
//## end module%3B5DED78033E.cp

//## Module: CCOL_TRN_TriListGen%3B5DED78033E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_TriList\CCOL_TRN_TriListGen.h

#ifndef CCOL_TRN_TriListGen_h
#define CCOL_TRN_TriListGen_h 1

//## begin module%3B5DED78033E.additionalIncludes preserve=no
//## end module%3B5DED78033E.additionalIncludes

//## begin module%3B5DED78033E.includes preserve=yes
//## end module%3B5DED78033E.includes

// GammaE_TerrainData
#include "TerrainData\GammaE_TerrainData.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
// CCOL_TriListGen
#include "Collision\COL_TriList\CCOL_TriListGen.h"
//## begin module%3B5DED78033E.additionalDeclarations preserve=yes
//## end module%3B5DED78033E.additionalDeclarations


//## begin CCOL_TRN_TriListGen%3B5DED78033E.preface preserve=yes
//## end CCOL_TRN_TriListGen%3B5DED78033E.preface

//## Class: CCOL_TRN_TriListGen%3B5DED78033E
//## Category: Collision::COL_TriList%3C1BEBCD00BD
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B5DF60300FA;GammaE_TerrainData { -> }
//## Uses: <unnamed>%3C06CDC8013A;GammaE_Math { -> }

class CCOL_TRN_TriListGen : public CCOL_TriListGen  //## Inherits: <unnamed>%3C1BEC900367
{
  //## begin CCOL_TRN_TriListGen%3B5DED78033E.initialDeclarations preserve=yes
  //## end CCOL_TRN_TriListGen%3B5DED78033E.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_TRN_TriListGen();

    //## Destructor (generated)
      ~CCOL_TRN_TriListGen();


    //## Other Operations (specified)
      //## Operation: GetHeight%996008335
      static float GetHeight (float fX, float fY);

      //## Operation: GetHeight%996008338
      static float GetHeight (int iX, int iY);

      //## Operation: Init%996008336
      static void Init (int _iSecsPerRow, int _iSecsPerCol, int _iSectorRes, float _fSectorSize);

      //## Operation: SetSector%996008337
      static void SetSector (int iSect, CHFSector *HFSect);

      //## Operation: GetTriList%1008463030
      virtual int GetTriList (CCOL_TriList& _roTriList, CVect3& _roPos, float _fRadius);

      //## Operation: GetTrisFromMesh%1008711904
      virtual int GetTrisFromMesh (CCOL_TriList& _roTriList, CMesh* _poMesh, int _iMat, CVect3& _roPos, float _fRadius);

    // Additional Public Declarations
      //## begin CCOL_TRN_TriListGen%3B5DED78033E.public preserve=yes
      //## end CCOL_TRN_TriListGen%3B5DED78033E.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_TRN_TriListGen%3B5DED78033E.protected preserve=yes
      //## end CCOL_TRN_TriListGen%3B5DED78033E.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: fSectorSize%3B5DEE170190
      //## begin CCOL_TRN_TriListGen::fSectorSize%3B5DEE170190.attr preserve=no  private: static float {UA} 
      static float fSectorSize;
      //## end CCOL_TRN_TriListGen::fSectorSize%3B5DEE170190.attr

      //## Attribute: HFs%3B5DEE1F008C
      //## begin CCOL_TRN_TriListGen::HFs%3B5DEE1F008C.attr preserve=no  private: static CHFSector* * {UA} NULL
      static CHFSector* *HFs;
      //## end CCOL_TRN_TriListGen::HFs%3B5DEE1F008C.attr

      //## Attribute: iSecsPerRow%3B5DEE8701F4
      //## begin CCOL_TRN_TriListGen::iSecsPerRow%3B5DEE8701F4.attr preserve=no  private: static int {UA} 0
      static int iSecsPerRow;
      //## end CCOL_TRN_TriListGen::iSecsPerRow%3B5DEE8701F4.attr

      //## Attribute: iSecsPerCol%3B5DEE8D0334
      //## begin CCOL_TRN_TriListGen::iSecsPerCol%3B5DEE8D0334.attr preserve=no  private: static int {UA} 0
      static int iSecsPerCol;
      //## end CCOL_TRN_TriListGen::iSecsPerCol%3B5DEE8D0334.attr

      //## Attribute: iSectorRes%3B5DF2670046
      //## begin CCOL_TRN_TriListGen::iSectorRes%3B5DF2670046.attr preserve=no  private: static int {UA} 0
      static int iSectorRes;
      //## end CCOL_TRN_TriListGen::iSectorRes%3B5DF2670046.attr

      //## Attribute: fRatio%3B5DF2C20320
      //## begin CCOL_TRN_TriListGen::fRatio%3B5DF2C20320.attr preserve=no  private: static float {UA} 0
      static float fRatio;
      //## end CCOL_TRN_TriListGen::fRatio%3B5DF2C20320.attr

      //## Attribute: iTWidth%3C0C1061030F
      //## begin CCOL_TRN_TriListGen::iTWidth%3C0C1061030F.attr preserve=no  private: static int {UA} 0
      static int iTWidth;
      //## end CCOL_TRN_TriListGen::iTWidth%3C0C1061030F.attr

      //## Attribute: iTHeight%3C0C106C02C5
      //## begin CCOL_TRN_TriListGen::iTHeight%3C0C106C02C5.attr preserve=no  private: static int {UA} 0
      static int iTHeight;
      //## end CCOL_TRN_TriListGen::iTHeight%3C0C106C02C5.attr

      //## Attribute: fInvRatio%3C0D6F1C00A7
      //## begin CCOL_TRN_TriListGen::fInvRatio%3C0D6F1C00A7.attr preserve=no  private: static float {UA} 0
      static float fInvRatio;
      //## end CCOL_TRN_TriListGen::fInvRatio%3C0D6F1C00A7.attr

    // Additional Private Declarations
      //## begin CCOL_TRN_TriListGen%3B5DED78033E.private preserve=yes
      //## end CCOL_TRN_TriListGen%3B5DED78033E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_TRN_TriListGen%3B5DED78033E.implementation preserve=yes
      //## end CCOL_TRN_TriListGen%3B5DED78033E.implementation

};

//## begin CCOL_TRN_TriListGen%3B5DED78033E.postscript preserve=yes
//## end CCOL_TRN_TriListGen%3B5DED78033E.postscript

// Class CCOL_TRN_TriListGen 

//## begin module%3B5DED78033E.epilog preserve=yes
//## end module%3B5DED78033E.epilog


#endif
