//## begin module%3C0ED22E0331.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0ED22E0331.cm

//## begin module%3C0ED22E0331.cp preserve=no
//## end module%3C0ED22E0331.cp

//## Module: CCOL_Scn_TriListGen%3C0ED22E0331; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Collision\COL_TriList\CCOL_Scn_TriListGen.h

#ifndef CCOL_Scn_TriListGen_h
#define CCOL_Scn_TriListGen_h 1

//## begin module%3C0ED22E0331.additionalIncludes preserve=no
//## end module%3C0ED22E0331.additionalIncludes

//## begin module%3C0ED22E0331.includes preserve=yes
#include "Scene/GammaE_Scene.h"
//## end module%3C0ED22E0331.includes

// CCOL_TriListGen
#include "Collision\COL_TriList\CCOL_TriListGen.h"
//## begin module%3C0ED22E0331.additionalDeclarations preserve=yes
//## end module%3C0ED22E0331.additionalDeclarations


//## begin CCOL_Scn_TriListGen%3C0ED22E0331.preface preserve=yes
//## end CCOL_Scn_TriListGen%3C0ED22E0331.preface

//## Class: CCOL_Scn_TriListGen%3C0ED22E0331
//## Category: Collision::COL_TriList%3C1BEBCD00BD
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCOL_Scn_TriListGen : public CCOL_TriListGen  //## Inherits: <unnamed>%3C1BEC930018
{
  //## begin CCOL_Scn_TriListGen%3C0ED22E0331.initialDeclarations preserve=yes
  //## end CCOL_Scn_TriListGen%3C0ED22E0331.initialDeclarations

  public:
    //## Constructors (generated)
      CCOL_Scn_TriListGen();

    //## Destructor (generated)
      ~CCOL_Scn_TriListGen();


    //## Other Operations (specified)
      //## Operation: GetTriList%1007604292
      virtual int GetTriList (CCOL_TriList& _roTriList, CVect3& _roPos, float _fRadius);

      //## Operation: GetTrisFromMesh%1008711903
      virtual int GetTrisFromMesh (CCOL_TriList& _roTriList, CMesh* _poMesh, int _iMat, CVect3& _roPos, float _fRadius);

    // Additional Public Declarations
      //## begin CCOL_Scn_TriListGen%3C0ED22E0331.public preserve=yes
      //## end CCOL_Scn_TriListGen%3C0ED22E0331.public

  protected:
    // Additional Protected Declarations
      //## begin CCOL_Scn_TriListGen%3C0ED22E0331.protected preserve=yes
      //## end CCOL_Scn_TriListGen%3C0ED22E0331.protected

  private:
    // Additional Private Declarations
      //## begin CCOL_Scn_TriListGen%3C0ED22E0331.private preserve=yes
      //## end CCOL_Scn_TriListGen%3C0ED22E0331.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOL_Scn_TriListGen%3C0ED22E0331.implementation preserve=yes
      //## end CCOL_Scn_TriListGen%3C0ED22E0331.implementation

};

//## begin CCOL_Scn_TriListGen%3C0ED22E0331.postscript preserve=yes
//## end CCOL_Scn_TriListGen%3C0ED22E0331.postscript

// Class CCOL_Scn_TriListGen 

//## begin module%3C0ED22E0331.epilog preserve=yes
//## end module%3C0ED22E0331.epilog


#endif
