//## begin module%3B7707FF019E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7707FF019E.cm

//## begin module%3B7707FF019E.cp preserve=no
//## end module%3B7707FF019E.cp

//## Module: CParticleSystemMgr%3B7707FF019E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\GameScene\CParticleSystemMgr.h

#ifndef CParticleSystemMgr_h
#define CParticleSystemMgr_h 1

//## begin module%3B7707FF019E.additionalIncludes preserve=no
//## end module%3B7707FF019E.additionalIncludes

//## begin module%3B7707FF019E.includes preserve=yes
//## end module%3B7707FF019E.includes

// CObject3D_Node
#include "Scene\CObject3D_Node.h"
//## begin module%3B7707FF019E.additionalDeclarations preserve=yes
//## end module%3B7707FF019E.additionalDeclarations


//## begin CParticleSystemMgr%3B7707FF019E.preface preserve=yes
//## end CParticleSystemMgr%3B7707FF019E.preface

//## Class: CParticleSystemMgr%3B7707FF019E
//## Category: Game::GameScene%3B770ECD0030
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CParticleSystemMgr : public CObject3D_Node  //## Inherits: <unnamed>%3B77082D00BE
{
  //## begin CParticleSystemMgr%3B7707FF019E.initialDeclarations preserve=yes
  //## end CParticleSystemMgr%3B7707FF019E.initialDeclarations

  public:
    //## Constructors (generated)
      CParticleSystemMgr();

    //## Destructor (generated)
      virtual ~CParticleSystemMgr();


    //## Other Operations (specified)
      //## Operation: Render%997655856
      virtual void Render ();

      //## Operation: iAddParticleSystem%1018379844
      int iAddParticleSystem (CObject3D* _poPSys);

      //## Operation: Reset%1018385440
      void Reset ();

    // Additional Public Declarations
      //## begin CParticleSystemMgr%3B7707FF019E.public preserve=yes
      //## end CParticleSystemMgr%3B7707FF019E.public

  protected:
    // Additional Protected Declarations
      //## begin CParticleSystemMgr%3B7707FF019E.protected preserve=yes
      //## end CParticleSystemMgr%3B7707FF019E.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iNumPSs%3CB354560350
      //## begin CParticleSystemMgr::iNumPSs%3CB354560350.attr preserve=no  private: int {UA} 0
      int iNumPSs;
      //## end CParticleSystemMgr::iNumPSs%3CB354560350.attr

    // Additional Private Declarations
      //## begin CParticleSystemMgr%3B7707FF019E.private preserve=yes
      //## end CParticleSystemMgr%3B7707FF019E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CParticleSystemMgr%3B7707FF019E.implementation preserve=yes
      //## end CParticleSystemMgr%3B7707FF019E.implementation

};

//## begin CParticleSystemMgr%3B7707FF019E.postscript preserve=yes
//## end CParticleSystemMgr%3B7707FF019E.postscript

// Class CParticleSystemMgr 

//## begin module%3B7707FF019E.epilog preserve=yes
//## end module%3B7707FF019E.epilog


#endif
