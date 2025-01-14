//## begin module%3B7707F7000C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7707F7000C.cm

//## begin module%3B7707F7000C.cp preserve=no
//## end module%3B7707F7000C.cp

//## Module: CBackgroundMgr%3B7707F7000C; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\CBackgroundMgr.cpp

//## begin module%3B7707F7000C.additionalIncludes preserve=no
//## end module%3B7707F7000C.additionalIncludes

//## begin module%3B7707F7000C.includes preserve=yes
//## end module%3B7707F7000C.includes

// CBackgroundMgr
#include "Game\CBackgroundMgr.h"
//## begin module%3B7707F7000C.additionalDeclarations preserve=yes
CBackgroundMgr BackgroundMgr;
//## end module%3B7707F7000C.additionalDeclarations


// Class CBackgroundMgr 

CBackgroundMgr::CBackgroundMgr()
  //## begin CBackgroundMgr::CBackgroundMgr%.hasinit preserve=no
  //## end CBackgroundMgr::CBackgroundMgr%.hasinit
  //## begin CBackgroundMgr::CBackgroundMgr%.initialization preserve=yes
  //## end CBackgroundMgr::CBackgroundMgr%.initialization
{
  //## begin CBackgroundMgr::CBackgroundMgr%.body preserve=yes
  //## end CBackgroundMgr::CBackgroundMgr%.body
}


CBackgroundMgr::~CBackgroundMgr()
{
  //## begin CBackgroundMgr::~CBackgroundMgr%.body preserve=yes
  //## end CBackgroundMgr::~CBackgroundMgr%.body
}



//## Other Operations (implementation)
void CBackgroundMgr::Render ()
{
  //## begin CBackgroundMgr::Render%997655857.body preserve=yes
	bool bFog;
	bool bZBuff;

	bFog   = RenderState.GetRenderer()->UsingFog();
	bZBuff = RenderState.GetRenderer()->UsingZBuffer();
	
	RenderState.GetRenderer()->DisableFog();
	RenderState.GetRenderer()->DisableZBuffer();
	

	CObject3D_Node::Render();


	if (bFog)	RenderState.GetRenderer()->EnableFog();
	if (bZBuff)	RenderState.GetRenderer()->EnableZBuffer();
  //## end CBackgroundMgr::Render%997655857.body
}

void CBackgroundMgr::AddBackground (CObject3D_Node *_BG)
{
  //## begin CBackgroundMgr::AddBackground%997655859.body preserve=yes
  //## end CBackgroundMgr::AddBackground%997655859.body
}

// Additional Declarations
  //## begin CBackgroundMgr%3B7707F7000C.declarations preserve=yes
  //## end CBackgroundMgr%3B7707F7000C.declarations

//## begin module%3B7707F7000C.epilog preserve=yes
//## end module%3B7707F7000C.epilog
