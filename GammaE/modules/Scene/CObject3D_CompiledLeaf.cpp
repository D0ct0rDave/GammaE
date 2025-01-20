//## begin module%3C50A9EA01AF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C50A9EA01AF.cm

//## begin module%3C50A9EA01AF.cp preserve=no
//## end module%3C50A9EA01AF.cp

//## Module: CObject3D_CompiledLeaf%3C50A9EA01AF; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\CObject3D_CompiledLeaf.cpp

//## begin module%3C50A9EA01AF.additionalIncludes preserve=no
//## end module%3C50A9EA01AF.additionalIncludes

//## begin module%3C50A9EA01AF.includes preserve=yes
//## end module%3C50A9EA01AF.includes

// CObject3D_CompiledLeaf
#include "Scene\CObject3D_CompiledLeaf.h"
//## begin module%3C50A9EA01AF.additionalDeclarations preserve=yes
//## end module%3C50A9EA01AF.additionalDeclarations


// Class CObject3D_CompiledLeaf 



CObject3D_CompiledLeaf::CObject3D_CompiledLeaf()
  //## begin CObject3D_CompiledLeaf::CObject3D_CompiledLeaf%.hasinit preserve=no
      : poCMesh(NULL), poShader(NULL)
  //## end CObject3D_CompiledLeaf::CObject3D_CompiledLeaf%.hasinit
  //## begin CObject3D_CompiledLeaf::CObject3D_CompiledLeaf%.initialization preserve=yes
  //## end CObject3D_CompiledLeaf::CObject3D_CompiledLeaf%.initialization
{
  //## begin CObject3D_CompiledLeaf::CObject3D_CompiledLeaf%.body preserve=yes
  //## end CObject3D_CompiledLeaf::CObject3D_CompiledLeaf%.body
}


CObject3D_CompiledLeaf::~CObject3D_CompiledLeaf()
{
  //## begin CObject3D_CompiledLeaf::~CObject3D_CompiledLeaf%.body preserve=yes
  //## end CObject3D_CompiledLeaf::~CObject3D_CompiledLeaf%.body
}



//## Other Operations (implementation)
void CObject3D_CompiledLeaf::Render ()
{
  //## begin CObject3D_CompiledLeaf::Render%1011911202.body preserve=yes
	
	// If NULL material process is still valid	
	gpoE3DRenderer->RenderCompiledMesh(poGetCMesh(),poGetShader());

  //## end CObject3D_CompiledLeaf::Render%1011911202.body
}

void CObject3D_CompiledLeaf::SetCMesh (CCompiledMesh *_poCMesh)
{
  //## begin CObject3D_CompiledLeaf::SetCMesh%1011911203.body preserve=yes
	poCMesh = _poCMesh;
  //## end CObject3D_CompiledLeaf::SetCMesh%1011911203.body
}

CCompiledMesh * CObject3D_CompiledLeaf::poGetCMesh ()
{
  //## begin CObject3D_CompiledLeaf::poGetCMesh%1011911205.body preserve=yes
	return(poCMesh);
  //## end CObject3D_CompiledLeaf::poGetCMesh%1011911205.body
}

CGraphBV* CObject3D_CompiledLeaf::poGetBoundVol ()
{
  //## begin CObject3D_CompiledLeaf::poGetBoundVol%1011911206.body preserve=yes
	return( poGetCMesh()->poGetBV() );
  //## end CObject3D_CompiledLeaf::poGetBoundVol%1011911206.body
}

void CObject3D_CompiledLeaf::ComputeBoundVol ()
{
  //## begin CObject3D_CompiledLeaf::ComputeBoundVol%1011911207.body preserve=yes
  //## end CObject3D_CompiledLeaf::ComputeBoundVol%1011911207.body
}

void CObject3D_CompiledLeaf::SetShader (CE3D_Shader* _poShader)
{
  //## begin CObject3D_CompiledLeaf::SetShader%1011999904.body preserve=yes
	poShader = _poShader;
  //## end CObject3D_CompiledLeaf::SetShader%1011999904.body
}

CE3D_Shader* CObject3D_CompiledLeaf::poGetShader ()
{
  //## begin CObject3D_CompiledLeaf::poGetShader%1011999905.body preserve=yes
	return ( poShader);
  //## end CObject3D_CompiledLeaf::poGetShader%1011999905.body
}

// Additional Declarations
  //## begin CObject3D_CompiledLeaf%3C50A9EA01AF.declarations preserve=yes
  //## end CObject3D_CompiledLeaf%3C50A9EA01AF.declarations

//## begin module%3C50A9EA01AF.epilog preserve=yes
//## end module%3C50A9EA01AF.epilog
