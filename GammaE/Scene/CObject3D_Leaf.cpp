//## begin module%3AA256E702BF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AA256E702BF.cm

//## begin module%3AA256E702BF.cp preserve=no
//## end module%3AA256E702BF.cp

//## Module: CObject3D_Leaf%3AA256E702BF; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\CObject3D_Leaf.cpp

//## begin module%3AA256E702BF.additionalIncludes preserve=no
//## end module%3AA256E702BF.additionalIncludes

//## begin module%3AA256E702BF.includes preserve=yes
#include "Memory/GammaE_Mem.h"
//## end module%3AA256E702BF.includes

// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
//## begin module%3AA256E702BF.additionalDeclarations preserve=yes
//## end module%3AA256E702BF.additionalDeclarations


// Class CObject3D_Leaf 




CObject3D_Leaf::CObject3D_Leaf()
  //## begin CObject3D_Leaf::CObject3D_Leaf%.hasinit preserve=no
      : poMesh(NULL), poShader(NULL)
  //## end CObject3D_Leaf::CObject3D_Leaf%.hasinit
  //## begin CObject3D_Leaf::CObject3D_Leaf%.initialization preserve=yes
  //## end CObject3D_Leaf::CObject3D_Leaf%.initialization
{
  //## begin CObject3D_Leaf::CObject3D_Leaf%.body preserve=yes
	TypeID   = e3DObj_Leaf;
  //## end CObject3D_Leaf::CObject3D_Leaf%.body
}


CObject3D_Leaf::~CObject3D_Leaf()
{
  //## begin CObject3D_Leaf::~CObject3D_Leaf%.body preserve=yes
	Clear();
  //## end CObject3D_Leaf::~CObject3D_Leaf%.body
}



//## Other Operations (implementation)
void CObject3D_Leaf::Clear ()
{
  //## begin CObject3D_Leaf::Clear%986154963.body preserve=yes
	mDel poMesh;
	poMesh = NULL;
  //## end CObject3D_Leaf::Clear%986154963.body
}

CGraphBV * CObject3D_Leaf::poGetBoundVol ()
{
  //## begin CObject3D_Leaf::poGetBoundVol%983822073.body preserve=yes
	return( poMesh->BVol );
  //## end CObject3D_Leaf::poGetBoundVol%983822073.body
}

void CObject3D_Leaf::ComputeBoundVol ()
{
  //## begin CObject3D_Leaf::ComputeBoundVol%983822074.body preserve=yes
	poMesh->ComputeBoundVol();	
  //## end CObject3D_Leaf::ComputeBoundVol%983822074.body
}

void CObject3D_Leaf::SetMesh (CMesh *_poMesh)
{
  //## begin CObject3D_Leaf::SetMesh%983822080.body preserve=yes
	poMesh = _poMesh;
  //## end CObject3D_Leaf::SetMesh%983822080.body
}

CMesh * CObject3D_Leaf::poGetMesh ()
{
  //## begin CObject3D_Leaf::poGetMesh%983717868.body preserve=yes
	return(poMesh);
  //## end CObject3D_Leaf::poGetMesh%983717868.body
}

void CObject3D_Leaf::Render ()
{
  //## begin CObject3D_Leaf::Render%983822077.body preserve=yes
	gpoE3DRenderer->RenderMesh(poGetMesh(),poGetShader());
  //## end CObject3D_Leaf::Render%983822077.body
}

// Additional Declarations
  //## begin CObject3D_Leaf%3AA256E702BF.declarations preserve=yes
  //## end CObject3D_Leaf%3AA256E702BF.declarations

//## begin module%3AA256E702BF.epilog preserve=yes
//## end module%3AA256E702BF.epilog
