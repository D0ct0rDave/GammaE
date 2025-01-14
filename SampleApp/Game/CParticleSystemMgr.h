//## begin module%3B7707FF019E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7707FF019E.cm

//## begin module%3B7707FF019E.cp preserve=no
//## end module%3B7707FF019E.cp

//## Module: CParticleSystemMgr%3B7707FF019E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\CParticleSystemMgr.h

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
//## Category: Game%3B5DE98D0118
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
      ~CParticleSystemMgr();


    //## Other Operations (specified)
      //## Operation: Render%997655856
      virtual void Render ();

      //## Operation: InitPSystems%997655860
      void InitPSystems (int iNumPSs);

    // Additional Public Declarations
      //## begin CParticleSystemMgr%3B7707FF019E.public preserve=yes
      //## end CParticleSystemMgr%3B7707FF019E.public

  protected:
    // Additional Protected Declarations
      //## begin CParticleSystemMgr%3B7707FF019E.protected preserve=yes
      //## end CParticleSystemMgr%3B7707FF019E.protected

  private:
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
extern CParticleSystemMgr ParticleSystemMgr;
//## end module%3B7707FF019E.epilog


#endif
