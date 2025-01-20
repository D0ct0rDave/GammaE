//## begin module%3C0D5B9F007B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0D5B9F007B.cm

//## begin module%3C0D5B9F007B.cp preserve=no
//## end module%3C0D5B9F007B.cp

//## Module: CCOL_ST_Tris%3C0D5B9F007B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_StaticTest\CCOL_ST_Tris.h

#ifndef CCOL_ST_Tris_h
#define CCOL_ST_Tris_h 1

//## begin module%3C0D5B9F007B.additionalIncludes preserve=no
//## end module%3C0D5B9F007B.additionalIncludes

//## begin module%3C0D5B9F007B.includes preserve=yes
//## end module%3C0D5B9F007B.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C0D5B9F007B.additionalDeclarations preserve=yes
//## end module%3C0D5B9F007B.additionalDeclarations


//## begin CCOL_ST_Tris%3C0D5B9F007B.preface preserve=yes
//## end CCOL_ST_Tris%3C0D5B9F007B.preface

//## Class: CCOL_ST_Tris%3C0D5B9F007B
//## Category: Collision::COL_Testers::COL_StaticTest%3C1FBE770329
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C0D5C2D0333;GammaE_Math { -> }
//## Uses: <unnamed>%3C1D26E402A5;GammaE_E3D { -> }

class CCOL_ST_Tris 
{
  //## begin CCOL_ST_Tris%3C0D5B9F007B.initialDeclarations preserve=yes
  //## end CCOL_ST_Tris%3C0D5B9F007B.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_ST_Tris();

    //## Destructor (generated)
      ~CCOL_ST_Tris();


    //## Other Operations (specified)
      //## Operation: iTestCollision%1007508516
      static int iTestCollision (CVect3* _pVXs, CVect3* _pVNs, int _iNumTris, CGraphBV* _BV, CVect3& _Pos);

      //## Operation: iTestCollisionSphere%1007508517
      static int iTestCollisionSphere (float _fRad, CVect3& _Center);

      //## Operation: iTestCollisionBox%1007508518
      static int iTestCollisionBox (CVect3& _Maxs, CVect3& _Mins);

      //## Operation: iTestCollisionRay%1007508519
      static int iTestCollisionRay (CRay& _Ray);

      //## Operation: iTestTriangleSphere%1007685155
      static int iTestTriangleSphere (CVect3* _pVXs, float _fRad, CVect3& _Center);

      //## Operation: iTestTriangleBox%1007685156
      static int iTestTriangleBox (CVect3* _pVXs, CVect3& _Maxs, CVect3& _Mins);

      //## Operation: iTestTriangleRay%1007685157
      static int iTestTriangleRay (CVect3* _pVXs, CRay& _Ray);

    // Data Members for Class Attributes

      //## Attribute: Tri%3C0D5C0D00FC
      //## begin CCOL_ST_Tris::Tri%3C0D5C0D00FC.attr preserve=no  public: static int {UA} 
      static int Tri;
      //## end CCOL_ST_Tris::Tri%3C0D5C0D00FC.attr

    // Additional Public Declarations
      //## begin CCOL_ST_Tris%3C0D5B9F007B.public preserve=yes
      //## end CCOL_ST_Tris%3C0D5B9F007B.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: pVX%3C0D5CD60390
      //## begin CCOL_ST_Tris::pVX%3C0D5CD60390.attr preserve=no  protected: static CVect3 * {UA} NULL
      static CVect3 *pVX;
      //## end CCOL_ST_Tris::pVX%3C0D5CD60390.attr

      //## Attribute: pVN%3C0D5CDE01BB
      //## begin CCOL_ST_Tris::pVN%3C0D5CDE01BB.attr preserve=no  protected: static CVect3 * {UA} NULL
      static CVect3 *pVN;
      //## end CCOL_ST_Tris::pVN%3C0D5CDE01BB.attr

      //## Attribute: iNumTris%3C0D5CE3032A
      //## begin CCOL_ST_Tris::iNumTris%3C0D5CE3032A.attr preserve=no  protected: static int {UA} 
      static int iNumTris;
      //## end CCOL_ST_Tris::iNumTris%3C0D5CE3032A.attr

      //## Attribute: Pos%3C0D6CFC0131
      //## begin CCOL_ST_Tris::Pos%3C0D6CFC0131.attr preserve=no  protected: static CVect3 {UA} 
      static CVect3 Pos;
      //## end CCOL_ST_Tris::Pos%3C0D6CFC0131.attr

    // Additional Protected Declarations
      //## begin CCOL_ST_Tris%3C0D5B9F007B.protected preserve=yes
      //## end CCOL_ST_Tris%3C0D5B9F007B.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_ST_Tris%3C0D5B9F007B.private preserve=yes
      //## end CCOL_ST_Tris%3C0D5B9F007B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_ST_Tris%3C0D5B9F007B.implementation preserve=yes
      //## end CCOL_ST_Tris%3C0D5B9F007B.implementation

};

//## begin CCOL_ST_Tris%3C0D5B9F007B.postscript preserve=yes
//## end CCOL_ST_Tris%3C0D5B9F007B.postscript

// Class CCOL_ST_Tris 

//## begin module%3C0D5B9F007B.epilog preserve=yes
//## end module%3C0D5B9F007B.epilog


#endif
