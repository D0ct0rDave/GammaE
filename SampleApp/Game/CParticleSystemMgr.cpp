//## begin module%3B7707FF019E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7707FF019E.cm

//## begin module%3B7707FF019E.cp preserve=no
//## end module%3B7707FF019E.cp

//## Module: CParticleSystemMgr%3B7707FF019E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\CParticleSystemMgr.cpp

//## begin module%3B7707FF019E.additionalIncludes preserve=no
//## end module%3B7707FF019E.additionalIncludes

//## begin module%3B7707FF019E.includes preserve=yes
//## end module%3B7707FF019E.includes

// CParticleSystemMgr
#include "Game\CParticleSystemMgr.h"
//## begin module%3B7707FF019E.additionalDeclarations preserve=yes
CParticleSystemMgr ParticleSystemMgr;
//## end module%3B7707FF019E.additionalDeclarations


// Class CParticleSystemMgr 

CParticleSystemMgr::CParticleSystemMgr()
  //## begin CParticleSystemMgr::CParticleSystemMgr%.hasinit preserve=no
  //## end CParticleSystemMgr::CParticleSystemMgr%.hasinit
  //## begin CParticleSystemMgr::CParticleSystemMgr%.initialization preserve=yes
  //## end CParticleSystemMgr::CParticleSystemMgr%.initialization
{
  //## begin CParticleSystemMgr::CParticleSystemMgr%.body preserve=yes
  //## end CParticleSystemMgr::CParticleSystemMgr%.body
}


CParticleSystemMgr::~CParticleSystemMgr()
{
  //## begin CParticleSystemMgr::~CParticleSystemMgr%.body preserve=yes
  //## end CParticleSystemMgr::~CParticleSystemMgr%.body
}



//## Other Operations (implementation)
void CParticleSystemMgr::Render ()
{
  //## begin CParticleSystemMgr::Render%997655856.body preserve=yes
	bool bZBuff;

	bZBuff = RenderState.GetRenderer()->UsingZBuffer();
	
	RenderState.GetRenderer()->DisableZBuffer();
	
	CObject3D_Node::Render();

	if (bZBuff)	RenderState.GetRenderer()->EnableZBuffer();
  //## end CParticleSystemMgr::Render%997655856.body
}

void CParticleSystemMgr::InitPSystems (int iNumPSs)
{
  //## begin CParticleSystemMgr::InitPSystems%997655860.body preserve=yes
  //## end CParticleSystemMgr::InitPSystems%997655860.body
}

// Additional Declarations
  //## begin CParticleSystemMgr%3B7707FF019E.declarations preserve=yes
  //## end CParticleSystemMgr%3B7707FF019E.declarations

//## begin module%3B7707FF019E.epilog preserve=yes
//## end module%3B7707FF019E.epilog
