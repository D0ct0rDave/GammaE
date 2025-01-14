//## begin module%3B7707F7000C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7707F7000C.cm

//## begin module%3B7707F7000C.cp preserve=no
//## end module%3B7707F7000C.cp

//## Module: CBackgroundMgr%3B7707F7000C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\CBackgroundMgr.h

#ifndef CBackgroundMgr_h
#define CBackgroundMgr_h 1

//## begin module%3B7707F7000C.additionalIncludes preserve=no
//## end module%3B7707F7000C.additionalIncludes

//## begin module%3B7707F7000C.includes preserve=yes
//## end module%3B7707F7000C.includes

// CObject3D_Node
#include "Scene\CObject3D_Node.h"
//## begin module%3B7707F7000C.additionalDeclarations preserve=yes
//## end module%3B7707F7000C.additionalDeclarations


//## begin CBackgroundMgr%3B7707F7000C.preface preserve=yes
//## end CBackgroundMgr%3B7707F7000C.preface

//## Class: CBackgroundMgr%3B7707F7000C
//## Category: Game::GameScene%3B770ECD0030
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CBackgroundMgr : protected CObject3D_Node  //## Inherits: <unnamed>%3B77082F0016
{
  //## begin CBackgroundMgr%3B7707F7000C.initialDeclarations preserve=yes
  //## end CBackgroundMgr%3B7707F7000C.initialDeclarations

  public:
    //## Constructors (generated)
      CBackgroundMgr();

    //## Destructor (generated)
      virtual ~CBackgroundMgr();


    //## Other Operations (specified)
      //## Operation: Render%997655857
      virtual void Render ();

      //## Operation: SetBackground%997655859
      void SetBackground (CObject3D* _poBG);

    // Additional Public Declarations
      //## begin CBackgroundMgr%3B7707F7000C.public preserve=yes
      //## end CBackgroundMgr%3B7707F7000C.public

  protected:
    // Additional Protected Declarations
      //## begin CBackgroundMgr%3B7707F7000C.protected preserve=yes
      //## end CBackgroundMgr%3B7707F7000C.protected

  private:
    // Additional Private Declarations
      //## begin CBackgroundMgr%3B7707F7000C.private preserve=yes
      //## end CBackgroundMgr%3B7707F7000C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CBackgroundMgr%3B7707F7000C.implementation preserve=yes
      //## end CBackgroundMgr%3B7707F7000C.implementation

};

//## begin CBackgroundMgr%3B7707F7000C.postscript preserve=yes
//## end CBackgroundMgr%3B7707F7000C.postscript

// Class CBackgroundMgr 

//## begin module%3B7707F7000C.epilog preserve=yes
//## end module%3B7707F7000C.epilog


#endif
