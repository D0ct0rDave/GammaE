//## begin module%3AC8FC3D0032.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC8FC3D0032.cm

//## begin module%3AC8FC3D0032.cp preserve=no
//## end module%3AC8FC3D0032.cp

//## Module: CBillboard_ScrAlign%3AC8FC3D0032; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\Billboard\CBillboard_ScrAlign.cpp

//## begin module%3AC8FC3D0032.additionalIncludes preserve=no
//## end module%3AC8FC3D0032.additionalIncludes

//## begin module%3AC8FC3D0032.includes preserve=yes
//## end module%3AC8FC3D0032.includes

// CBillboard_ScrAlign
#include "Scene\Billboard\CBillboard_ScrAlign.h"
//## begin module%3AC8FC3D0032.additionalDeclarations preserve=yes
//## end module%3AC8FC3D0032.additionalDeclarations


// Class CBillboard_ScrAlign 

CBillboard_ScrAlign::CBillboard_ScrAlign()
  //## begin CBillboard_ScrAlign::CBillboard_ScrAlign%.hasinit preserve=no
  //## end CBillboard_ScrAlign::CBillboard_ScrAlign%.hasinit
  //## begin CBillboard_ScrAlign::CBillboard_ScrAlign%.initialization preserve=yes
  //## end CBillboard_ScrAlign::CBillboard_ScrAlign%.initialization
{
  //## begin CBillboard_ScrAlign::CBillboard_ScrAlign%.body preserve=yes
  //## end CBillboard_ScrAlign::CBillboard_ScrAlign%.body
}


CBillboard_ScrAlign::~CBillboard_ScrAlign()
{
  //## begin CBillboard_ScrAlign::~CBillboard_ScrAlign%.body preserve=yes
  //## end CBillboard_ScrAlign::~CBillboard_ScrAlign%.body
}



//## Other Operations (implementation)
void CBillboard_ScrAlign::Render ()
{
  //## begin CBillboard_ScrAlign::Render%986249626.body preserve=yes
  	CMatrix4x4	 M,M1;
	CE3D_Camera	*Cam = gpoE3DRenderer->GetCamera();
	
	CVect3 e1,e2,e3;
	// e1.Assign(Cam->Side);	e1.Scale(-1);
	e2.Assign(Cam->Up  );	e2.Scale( 1);
	e3.Assign(Cam->Dir );	e3.Scale(-1);
	e1.CrossProd(e2,e3);
	M.LoadFromAxis(e1,e2,e3);

	gpoE3DRenderer->GetCurrentMatrix(&M1);	

	M1.Set(0,3,0);	M1.Set(1,3,0);	M1.Set(2,3,0);
	M1.Transpose();

	gpoE3DRenderer->PushMatrix();

		gpoE3DRenderer->MultiplyMatrix(&M);
		CObject3D_Node::Render();

	gpoE3DRenderer->PopMatrix();
  //## end CBillboard_ScrAlign::Render%986249626.body
}

// Additional Declarations
  //## begin CBillboard_ScrAlign%3AC8FC3D0032.declarations preserve=yes
  //## end CBillboard_ScrAlign%3AC8FC3D0032.declarations

//## begin module%3AC8FC3D0032.epilog preserve=yes
//## end module%3AC8FC3D0032.epilog
