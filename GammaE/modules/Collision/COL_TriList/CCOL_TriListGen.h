//## begin module%3C1BEC41027D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1BEC41027D.cm

//## begin module%3C1BEC41027D.cp preserve=no
//## end module%3C1BEC41027D.cp

//## Module: CCOL_TriListGen%3C1BEC41027D; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_TriList\CCOL_TriListGen.h

#ifndef CCOL_TriListGen_h
#define CCOL_TriListGen_h 1

//## begin module%3C1BEC41027D.additionalIncludes preserve=no
//## end module%3C1BEC41027D.additionalIncludes

//## begin module%3C1BEC41027D.includes preserve=yes
//## end module%3C1BEC41027D.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
// CCOL_TriList
#include "Collision\COL_TriList\CCOL_TriList.h"
//## begin module%3C1BEC41027D.additionalDeclarations preserve=yes
//## end module%3C1BEC41027D.additionalDeclarations


//## begin CCOL_TriListGen%3C1BEC41027D.preface preserve=yes
//## end CCOL_TriListGen%3C1BEC41027D.preface

//## Class: CCOL_TriListGen%3C1BEC41027D
//## Category: Collision::COL_TriList%3C1BEBCD00BD
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1BF54103D4;GammaE_E3D { -> }
//## Uses: <unnamed>%3C1BF22F0207;GammaE_Math { -> }
//## Uses: <unnamed>%3C1D056E0226;CCOL_TriList { -> }

class CCOL_TriListGen 
{
  //## begin CCOL_TriListGen%3C1BEC41027D.initialDeclarations preserve=yes
  //## end CCOL_TriListGen%3C1BEC41027D.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_TriListGen();

    //## Destructor (generated)
      ~CCOL_TriListGen();


    //## Other Operations (specified)
      //## Operation: GetTriList%1008463028
      virtual int GetTriList (CCOL_TriList& _roTriList, CVect3& _roPos, float _fRadius);

      //## Operation: SetMeshes%1008463029
      virtual void SetMeshes (CMesh** _poMeshes, int* _piMats, int _iNumMeshes);

      //## Operation: GetTrisFromMesh%1008711902
      virtual int GetTrisFromMesh (CCOL_TriList& _roTriList, CMesh* _poMesh, int _iMat, CVect3& _roPos, float _fRadius);

    // Additional Public Declarations
      //## begin CCOL_TriListGen%3C1BEC41027D.public preserve=yes
      //## end CCOL_TriListGen%3C1BEC41027D.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: poMeshes%3C1BED81016E
      //## begin CCOL_TriListGen::poMeshes%3C1BED81016E.attr preserve=no  protected: static CMesh* * {UA} NULL
      static CMesh* *poMeshes;
      //## end CCOL_TriListGen::poMeshes%3C1BED81016E.attr

      //## Attribute: piMats%3CCD03E702FB
      //## begin CCOL_TriListGen::piMats%3CCD03E702FB.attr preserve=no  protected: static int * {UA} NULL
      static int *piMats;
      //## end CCOL_TriListGen::piMats%3CCD03E702FB.attr

      //## Attribute: iNumMeshes%3C1BED8D03D9
      //## begin CCOL_TriListGen::iNumMeshes%3C1BED8D03D9.attr preserve=no  protected: static int {UA} 0
      static int iNumMeshes;
      //## end CCOL_TriListGen::iNumMeshes%3C1BED8D03D9.attr

    // Additional Protected Declarations
      //## begin CCOL_TriListGen%3C1BEC41027D.protected preserve=yes
      //## end CCOL_TriListGen%3C1BEC41027D.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_TriListGen%3C1BEC41027D.private preserve=yes
      //## end CCOL_TriListGen%3C1BEC41027D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_TriListGen%3C1BEC41027D.implementation preserve=yes
      //## end CCOL_TriListGen%3C1BEC41027D.implementation

};

//## begin CCOL_TriListGen%3C1BEC41027D.postscript preserve=yes
//## end CCOL_TriListGen%3C1BEC41027D.postscript

// Class CCOL_TriListGen 

//## begin module%3C1BEC41027D.epilog preserve=yes
//## end module%3C1BEC41027D.epilog


#endif
