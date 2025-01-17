//## begin module%3B7707FF019E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7707FF019E.cm

//## begin module%3B7707FF019E.cp preserve=no
//## end module%3B7707FF019E.cp

//## Module: CParticleSystemMgr%3B7707FF019E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\CParticleSystemMgr.cpp

//## begin module%3B7707FF019E.additionalIncludes preserve=no
//## end module%3B7707FF019E.additionalIncludes

//## begin module%3B7707FF019E.includes preserve=yes
//## end module%3B7707FF019E.includes

// CParticleSystemMgr
#include "CParticleSystemMgr.h"
//## begin module%3B7707FF019E.additionalDeclarations preserve=yes
//## end module%3B7707FF019E.additionalDeclarations


// Class CParticleSystemMgr 



CParticleSystemMgr::CParticleSystemMgr()
  //## begin CParticleSystemMgr::CParticleSystemMgr%.hasinit preserve=no
      : iNumPSs(0)
  //## end CParticleSystemMgr::CParticleSystemMgr%.hasinit
  //## begin CParticleSystemMgr::CParticleSystemMgr%.initialization preserve=yes
  //## end CParticleSystemMgr::CParticleSystemMgr%.initialization
{
  //## begin CParticleSystemMgr::CParticleSystemMgr%.body preserve=yes
	Reference();
	bFrustumTest = false;
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
	
	gpoE3DRenderer->SetFogPars(eE3D_FM_None,0,0,0,NULL);
	// gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Disable);

	// Render the particle systems
	int iObj;
	for (iObj=0;iObj<iNumPSs;iObj++)
		poSubObj[iObj]->Render();

	
	gpoE3DRenderer->SetFogPars(eE3D_FM_Last,0,0,0,NULL);
	// gpoE3DRenderer->SetZPars(eE3D_ZTF_Last,eE3D_ZW_Last);

  //## end CParticleSystemMgr::Render%997655856.body
}

int CParticleSystemMgr::iAddParticleSystem (CObject3D* _poPSys)
{
  //## begin CParticleSystemMgr::iAddParticleSystem%1018379844.body preserve=yes
	if (iNumSubObjs() == iNumPSs)
		iAddObject(_poPSys);
	else
		SetObject(_poPSys,iNumPSs);	

	iNumPSs++;
	return(iNumPSs-1);
  //## end CParticleSystemMgr::iAddParticleSystem%1018379844.body
}

void CParticleSystemMgr::Reset ()
{
  //## begin CParticleSystemMgr::Reset%1018385440.body preserve=yes
	iNumPSs = 0;
  //## end CParticleSystemMgr::Reset%1018385440.body
}

// Additional Declarations
  //## begin CParticleSystemMgr%3B7707FF019E.declarations preserve=yes
  //## end CParticleSystemMgr%3B7707FF019E.declarations

//## begin module%3B7707FF019E.epilog preserve=yes
//## end module%3B7707FF019E.epilog
