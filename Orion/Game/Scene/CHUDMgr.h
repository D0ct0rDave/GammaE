//## begin module%3B770E250350.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B770E250350.cm

//## begin module%3B770E250350.cp preserve=no
//## end module%3B770E250350.cp

//## Module: CHUDMgr%3B770E250350; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\CHUDMgr.h

#ifndef CHUDMgr_h
#define CHUDMgr_h 1

//## begin module%3B770E250350.additionalIncludes preserve=no
//## end module%3B770E250350.additionalIncludes

//## begin module%3B770E250350.includes preserve=yes
//## end module%3B770E250350.includes

// CObject3D_Node
#include "GammaE.h"
//## begin module%3B770E250350.additionalDeclarations preserve=yes
//## end module%3B770E250350.additionalDeclarations


//## begin CHUDMgr%3B770E250350.preface preserve=yes
//## end CHUDMgr%3B770E250350.preface

//## Class: CHUDMgr%3B770E250350
//## Category: Game::GameScene%3B770ECD0030
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHUDMgr : protected CObject3D_Node  //## Inherits: <unnamed>%3B770E4001DC
{
  //## begin CHUDMgr%3B770E250350.initialDeclarations preserve=yes
  //## end CHUDMgr%3B770E250350.initialDeclarations

  public:
    //## Constructors (generated)
      CHUDMgr();

    //## Destructor (generated)
      virtual ~CHUDMgr();


    //## Other Operations (specified)
      //## Operation: Render%997655862
      virtual void Render ();

      //## Operation: SetHUD%997655863
      void SetHUD (CObject3D* _pHUD);

    // Additional Public Declarations
      //## begin CHUDMgr%3B770E250350.public preserve=yes
      //## end CHUDMgr%3B770E250350.public

  protected:
    // Additional Protected Declarations
      //## begin CHUDMgr%3B770E250350.protected preserve=yes
      //## end CHUDMgr%3B770E250350.protected

  private:
    // Additional Private Declarations
      //## begin CHUDMgr%3B770E250350.private preserve=yes
      //## end CHUDMgr%3B770E250350.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHUDMgr%3B770E250350.implementation preserve=yes
      //## end CHUDMgr%3B770E250350.implementation

};

//## begin CHUDMgr%3B770E250350.postscript preserve=yes
//## end CHUDMgr%3B770E250350.postscript

// Class CHUDMgr 

//## begin module%3B770E250350.epilog preserve=yes
//## end module%3B770E250350.epilog


#endif
