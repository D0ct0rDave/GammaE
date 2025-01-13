//## begin module%3C294DBE032E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C294DBE032E.cm

//## begin module%3C294DBE032E.cp preserve=no
//## end module%3C294DBE032E.cp

//## Module: CCOL_MT_TerrainMesh%3C294DBE032E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MT_TerrainMesh.h

#ifndef CCOL_MT_TerrainMesh_h
#define CCOL_MT_TerrainMesh_h 1

//## begin module%3C294DBE032E.additionalIncludes preserve=no
//## end module%3C294DBE032E.additionalIncludes

//## begin module%3C294DBE032E.includes preserve=yes
//## end module%3C294DBE032E.includes

// GammaE_TerrainData
#include "TerrainData\GammaE_TerrainData.h"
// CCOL_DT_ColTester
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_MeshTester
#include "Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MeshTester.h"
//## begin module%3C294DBE032E.additionalDeclarations preserve=yes
//## end module%3C294DBE032E.additionalDeclarations


//## begin CCOL_MT_TerrainMesh%3C294DBE032E.preface preserve=yes
//## end CCOL_MT_TerrainMesh%3C294DBE032E.preface

//## Class: CCOL_MT_TerrainMesh%3C294DBE032E
//## Category: Collision::COL_Testers::COL_SceneTest::COL_MeshTest%3C294D4B0315
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C29524B0171;GammaE_TerrainData { -> }
//## Uses: <unnamed>%3C2A5446030B;CCOL_ColState { -> }
//## Uses: <unnamed>%3C2A67310124;CCOL_DT_ColTester { -> }

class CCOL_MT_TerrainMesh : public CCOL_MeshTester  //## Inherits: <unnamed>%3C294DC901FD
{
  //## begin CCOL_MT_TerrainMesh%3C294DBE032E.initialDeclarations preserve=yes
  //## end CCOL_MT_TerrainMesh%3C294DBE032E.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_MT_TerrainMesh();

    //## Destructor (generated)
      ~CCOL_MT_TerrainMesh();


    //## Other Operations (specified)
      //## Operation: iTestCollision%1009321164
      virtual int iTestCollision (CMesh* _poMesh, int _iMat, CGraphBV* _poBVol, CCOL_TriList& _roTriList);

      //## Operation: iGetTriangles%1009321167
      int iGetTriangles (int _iX, int _iY, int _iRad, CVect3* _pVXs);

      //## Operation: GetTriangle%1009406733
      void GetTriangle (int _iX, int _iY, CVect3* _pa6VXs);

      //## Operation: GetHeight%1009321166
      float GetHeight (int iX, int iY);

      //## Operation: Init%1009321165
      void Init (CHeightField* _pHF, int _iSectorRes, float _fSectorSize);

    // Additional Public Declarations
      //## begin CCOL_MT_TerrainMesh%3C294DBE032E.public preserve=yes
      //## end CCOL_MT_TerrainMesh%3C294DBE032E.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_MT_TerrainMesh%3C294DBE032E.protected preserve=yes
      //## end CCOL_MT_TerrainMesh%3C294DBE032E.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: HF%3C295185019E
      //## begin CCOL_MT_TerrainMesh::HF%3C295185019E.attr preserve=no  private: CHeightField * {UA} NULL
      CHeightField *HF;
      //## end CCOL_MT_TerrainMesh::HF%3C295185019E.attr

      //## Attribute: iSectorRes%3C295198000B
      //## begin CCOL_MT_TerrainMesh::iSectorRes%3C295198000B.attr preserve=no  private: int {UA} 0
      int iSectorRes;
      //## end CCOL_MT_TerrainMesh::iSectorRes%3C295198000B.attr

      //## Attribute: fRatio%3C29519E0262
      //## begin CCOL_MT_TerrainMesh::fRatio%3C29519E0262.attr preserve=no  private: float {UA} 0
      float fRatio;
      //## end CCOL_MT_TerrainMesh::fRatio%3C29519E0262.attr

      //## Attribute: iTWidth%3C2951A2022C
      //## begin CCOL_MT_TerrainMesh::iTWidth%3C2951A2022C.attr preserve=no  private: int {UA} 0
      int iTWidth;
      //## end CCOL_MT_TerrainMesh::iTWidth%3C2951A2022C.attr

      //## Attribute: iTHeight%3C2951A7007A
      //## begin CCOL_MT_TerrainMesh::iTHeight%3C2951A7007A.attr preserve=no  private: int {UA} 0
      int iTHeight;
      //## end CCOL_MT_TerrainMesh::iTHeight%3C2951A7007A.attr

      //## Attribute: fInvRatio%3C2951AC01B8
      //## begin CCOL_MT_TerrainMesh::fInvRatio%3C2951AC01B8.attr preserve=no  private: float {UA} 0
      float fInvRatio;
      //## end CCOL_MT_TerrainMesh::fInvRatio%3C2951AC01B8.attr

    // Additional Private Declarations
      //## begin CCOL_MT_TerrainMesh%3C294DBE032E.private preserve=yes
      //## end CCOL_MT_TerrainMesh%3C294DBE032E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_MT_TerrainMesh%3C294DBE032E.implementation preserve=yes
      //## end CCOL_MT_TerrainMesh%3C294DBE032E.implementation

};

//## begin CCOL_MT_TerrainMesh%3C294DBE032E.postscript preserve=yes
//## end CCOL_MT_TerrainMesh%3C294DBE032E.postscript

// Class CCOL_MT_TerrainMesh 

//## begin module%3C294DBE032E.epilog preserve=yes
//## end module%3C294DBE032E.epilog


#endif
