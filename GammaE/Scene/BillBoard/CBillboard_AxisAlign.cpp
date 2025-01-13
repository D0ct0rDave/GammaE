//## begin module%3AC8FC760122.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC8FC760122.cm

//## begin module%3AC8FC760122.cp preserve=no
//## end module%3AC8FC760122.cp

//## Module: CBillboard_AxisAlign%3AC8FC760122; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\Billboard\CBillboard_AxisAlign.cpp

//## begin module%3AC8FC760122.additionalIncludes preserve=no
//## end module%3AC8FC760122.additionalIncludes

//## begin module%3AC8FC760122.includes preserve=yes
//## end module%3AC8FC760122.includes

// CBillboard_AxisAlign
#include "Scene\Billboard\CBillboard_AxisAlign.h"
//## begin module%3AC8FC760122.additionalDeclarations preserve=yes
//## end module%3AC8FC760122.additionalDeclarations


// Class CBillboard_AxisAlign 


CBillboard_AxisAlign::CBillboard_AxisAlign()
  //## begin CBillboard_AxisAlign::CBillboard_AxisAlign%.hasinit preserve=no
  //## end CBillboard_AxisAlign::CBillboard_AxisAlign%.hasinit
  //## begin CBillboard_AxisAlign::CBillboard_AxisAlign%.initialization preserve=yes
  //## end CBillboard_AxisAlign::CBillboard_AxisAlign%.initialization
{
  //## begin CBillboard_AxisAlign::CBillboard_AxisAlign%.body preserve=yes
  //## end CBillboard_AxisAlign::CBillboard_AxisAlign%.body
}


CBillboard_AxisAlign::~CBillboard_AxisAlign()
{
  //## begin CBillboard_AxisAlign::~CBillboard_AxisAlign%.body preserve=yes
  //## end CBillboard_AxisAlign::~CBillboard_AxisAlign%.body
}



//## Other Operations (implementation)
void CBillboard_AxisAlign::SetAxis (bool x, bool y, bool z)
{
  //## begin CBillboard_AxisAlign::SetAxis%986249628.body preserve=yes
	Flags = 0;
	if (x) Flags |= 0x01;
	if (y) Flags |= 0x02;
	if (z) Flags |= 0x04;
  //## end CBillboard_AxisAlign::SetAxis%986249628.body
}

void CBillboard_AxisAlign::Render ()
{
  //## begin CBillboard_AxisAlign::Render%986249627.body preserve=yes
	CVect3		 InvPos;
	CMatrix4x4	 M;
	CE3D_Camera	*Cam = gpoE3DRenderer->GetCamera();
	
	if (Flags & 0x01) InvPos.SetX(-Cam->Pos.X()); else  InvPos.SetX(0);
	if (Flags & 0x02) InvPos.SetY(-Cam->Pos.Y()); else  InvPos.SetY(0);
	if (Flags & 0x04) InvPos.SetZ(-Cam->Pos.Z()); else  InvPos.SetZ(0);

	gpoE3DRenderer->Translate(InvPos.X(),InvPos.Y(),InvPos.Z());

	CObject3D_Node::Render();
  //## end CBillboard_AxisAlign::Render%986249627.body
}

// Additional Declarations
  //## begin CBillboard_AxisAlign%3AC8FC760122.declarations preserve=yes
  //## end CBillboard_AxisAlign%3AC8FC760122.declarations

//## begin module%3AC8FC760122.epilog preserve=yes
//## end module%3AC8FC760122.epilog
