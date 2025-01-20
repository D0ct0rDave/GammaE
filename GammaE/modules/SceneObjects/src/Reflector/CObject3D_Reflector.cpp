//## begin module%3BDB5AB6017E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BDB5AB6017E.cm

//## begin module%3BDB5AB6017E.cp preserve=no
//## end module%3BDB5AB6017E.cp

//## Module: CObject3D_Reflector%3BDB5AB6017E; Pseudo Package body
//## Source file: i:\Projects\GammaE\SceneObjects\Reflector\CObject3D_Reflector.cpp

//## begin module%3BDB5AB6017E.additionalIncludes preserve=no
//## end module%3BDB5AB6017E.additionalIncludes

//## begin module%3BDB5AB6017E.includes preserve=yes
#ifdef _MBCS
	#include <windows.h>
	#include <wingdi.h>
	
	#define TPixelFormatDescriptor	PIXELFORMATDESCRIPTOR
	#define TLogPalette				LOGPALETTE
	#define TPaletteEntry			PALETTEENTRY
#else
	#ifdef _BCB_
	#include <vcl\vcl.h>
	#endif
#endif

#include <gl/gl.h>
//## end module%3BDB5AB6017E.includes

// CObject3D_Reflector
#include "SceneObjects\Reflector\CObject3D_Reflector.h"
//## begin module%3BDB5AB6017E.additionalDeclarations preserve=yes
//## end module%3BDB5AB6017E.additionalDeclarations


// Class CObject3D_Reflector 



CObject3D_Reflector::CObject3D_Reflector()
  //## begin CObject3D_Reflector::CObject3D_Reflector%.hasinit preserve=no
      : Mirror(NULL)
  //## end CObject3D_Reflector::CObject3D_Reflector%.hasinit
  //## begin CObject3D_Reflector::CObject3D_Reflector%.initialization preserve=yes
  //## end CObject3D_Reflector::CObject3D_Reflector%.initialization
{
  //## begin CObject3D_Reflector::CObject3D_Reflector%.body preserve=yes
	Mirror = new CMesh_Rect();
  //## end CObject3D_Reflector::CObject3D_Reflector%.body
}


CObject3D_Reflector::~CObject3D_Reflector()
{
  //## begin CObject3D_Reflector::~CObject3D_Reflector%.body preserve=yes
	delete Mirror;
  //## end CObject3D_Reflector::~CObject3D_Reflector%.body
}



//## Other Operations (implementation)
void CObject3D_Reflector::Render ()
{
  //## begin CObject3D_Reflector::Render%1004231435.body preserve=yes
	CMatrix4x4	M;
	CMatrix4x4	PrjMatrix;
	CMatrix4x4	FPrjMat;
	
	// Enable stenciling
	gpoE3DRenderer->SetStencilPars(eE3D_SF_Always,1,~0,eE3D_SA_Keep,eE3D_SA_Keep,eE3D_SA_Replace);	

	// Render the reflector object first with stencil on
	gpoE3DRenderer->ClearBuffer(eE3D_RB_Stencil);

	gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Disable);
	gpoE3DRenderer->RenderMesh(Mirror);
	gpoE3DRenderer->SetZPars(eE3D_ZTF_Last,eE3D_ZW_Last);		
	
	// Disable Stenciling 
	gpoE3DRenderer->SetStencilPars(eE3D_SF_None,0,0,eE3D_SA_None,eE3D_SA_None,eE3D_SA_None);

	/*
	gpoE3DRenderer->GetGetProjectorMatrix(&M);
	// Setup reflection matrix
	SetupReflectionMatrix(PrjMatrix);

	// La reflexión tambien debe aparecer projectada en pantalla (por supuesto)
	FPrjMat.Multiply(PrjMatrix,M);
	
	// Setup reflection matrix
	gpoE3DRenderer->SetProjectorMatrix(&FPrjMat);
	
	// Normal Rendering
	CObject3D_Node::Render();

	// Restore previous matrix
	gpoE3DRenderer->SetProjectorMatrix(&M);
	*/
	
	gpoE3DRenderer->PushMatrix();
	
	// Setup reflection matrix
	SetupReflectionMatrix(PrjMatrix);
	
	gpoE3DRenderer->MultiplyMatrix(&PrjMatrix);	
	
	// Normal Rendering
	CObject3D_Node::Render();

	// Restore previous matrix
	gpoE3DRenderer->PopMatrix();	
	
	glDisable(GL_STENCIL_TEST);
  //## end CObject3D_Reflector::Render%1004231435.body
}

void CObject3D_Reflector::SetupReflectionMatrix (CMatrix4x4 &_roMat)
{
  //## begin CObject3D_Reflector::SetupReflectionMatrix%1004231436.body preserve=yes
	CPlane	Plane;
	CVect3	Normal;
	float	D;

	Plane.GenerateFromPoints(Mirror->VXs[0],Mirror->VXs[1],Mirror->VXs[2]);
	Normal.Assign(Plane.Normal());
	//Normal.V3(0,0,1);
	D = -1.0f*Plane.D();

	_roMat.Set(0,0,1.0f - 2.0f*Normal.X()*Normal.X());
	_roMat.Set(0,1,     - 2.0f*Normal.X()*Normal.Y());
	_roMat.Set(0,2,     - 2.0f*Normal.X()*Normal.Z());
	_roMat.Set(0,3,       2.0f*Normal.X()*D);

	_roMat.Set(1,0,     - 2.0f*Normal.Y()*Normal.X());
	_roMat.Set(1,1,1.0f - 2.0f*Normal.Y()*Normal.Y());
	_roMat.Set(1,2,     - 2.0f*Normal.Y()*Normal.Z());
	_roMat.Set(1,3,       2.0f*Normal.Y()*D);
	
	_roMat.Set(2,0,     - 2.0f*Normal.Z()*Normal.X());
	_roMat.Set(2,1,     - 2.0f*Normal.Z()*Normal.Y());
	_roMat.Set(2,2,1.0f - 2.0f*Normal.Z()*Normal.Z());
	_roMat.Set(2,3,       2.0f*Normal.Z()*D);

	_roMat.Set(3,0,0.0f);
	_roMat.Set(3,1,0.0f);
	_roMat.Set(3,2,0.0f);
	_roMat.Set(3,3,1.0f);
	
  //## end CObject3D_Reflector::SetupReflectionMatrix%1004231436.body
}

// Additional Declarations
  //## begin CObject3D_Reflector%3BDB5AB6017E.declarations preserve=yes
  //## end CObject3D_Reflector%3BDB5AB6017E.declarations

//## begin module%3BDB5AB6017E.epilog preserve=yes
//## end module%3BDB5AB6017E.epilog
