//## begin module%3AF714B70168.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF714B70168.cm

//## begin module%3AF714B70168.cp preserve=no
//## end module%3AF714B70168.cp

//## Module: CObject3D_Camera%3AF714B70168; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\CObject3D_Camera.cpp

//## begin module%3AF714B70168.additionalIncludes preserve=no
//## end module%3AF714B70168.additionalIncludes

//## begin module%3AF714B70168.includes preserve=yes
//## end module%3AF714B70168.includes

// CObject3D_Camera
#include "Scene\CObject3D_Camera.h"
//## begin module%3AF714B70168.additionalDeclarations preserve=yes
//## end module%3AF714B70168.additionalDeclarations


// Class CObject3D_Camera 







CObject3D_Camera::CObject3D_Camera()
  //## begin CObject3D_Camera::CObject3D_Camera%.hasinit preserve=no
      : poCam(NULL), poProj(NULL), poVpt(NULL), poOldCam(NULL), poOldProj(NULL), poOldVpt(NULL)
  //## end CObject3D_Camera::CObject3D_Camera%.hasinit
  //## begin CObject3D_Camera::CObject3D_Camera%.initialization preserve=yes
  //## end CObject3D_Camera::CObject3D_Camera%.initialization
{
  //## begin CObject3D_Camera::CObject3D_Camera%.body preserve=yes
	bFrustumTest = false;
  //## end CObject3D_Camera::CObject3D_Camera%.body
}


CObject3D_Camera::~CObject3D_Camera()
{
  //## begin CObject3D_Camera::~CObject3D_Camera%.body preserve=yes
  //## end CObject3D_Camera::~CObject3D_Camera%.body
}



//## Other Operations (implementation)
void CObject3D_Camera::PreRender ()
{
  //## begin CObject3D_Camera::PreRender%1018461832.body preserve=yes
	
	// Get current state attributes
	poOldCam = gpoE3DRenderer->GetCamera();
	poOldProj= gpoE3DRenderer->GetProjector();
	poOldVpt = gpoE3DRenderer->GetViewport();

	gpoE3DRenderer->PushCameraMatrix();
	gpoE3DRenderer->PushProjectorMatrix();

	// Send current attributes to render engine
	gpoE3DRenderer->PushLocalFrustum();

	if (poCam)	gpoE3DRenderer->SetCamera	(poCam);
	if (poProj)	gpoE3DRenderer->SetProjector(poProj);
	if (poVpt)	gpoE3DRenderer->SetViewport	(poVpt);

	gpoE3DRenderer->ComputeLocalFrustum();

  //## end CObject3D_Camera::PreRender%1018461832.body
}

void CObject3D_Camera::Render ()
{
  //## begin CObject3D_Camera::Render%989269076.body preserve=yes
	
	PreRender();
		
		// Render 
		CObject3D_Node::Render();
	
	PostRender();

  //## end CObject3D_Camera::Render%989269076.body
}

void CObject3D_Camera::PostRender ()
{
  //## begin CObject3D_Camera::PostRender%1018461833.body preserve=yes

	// Restore previously defined attributes	
	if (poCam)	gpoE3DRenderer->SetCamera	(poOldCam);
	if (poProj)	gpoE3DRenderer->SetProjector(poOldProj);
	if (poVpt)	gpoE3DRenderer->SetViewport	(poOldVpt);

	gpoE3DRenderer->PopLocalFrustum();

	gpoE3DRenderer->PopProjectorMatrix();
	gpoE3DRenderer->PopCameraMatrix();	

  //## end CObject3D_Camera::PostRender%1018461833.body
}

// Additional Declarations
  //## begin CObject3D_Camera%3AF714B70168.declarations preserve=yes
  //## end CObject3D_Camera%3AF714B70168.declarations

//## begin module%3AF714B70168.epilog preserve=yes
//## end module%3AF714B70168.epilog
