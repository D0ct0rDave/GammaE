//## begin module%3CB3429C00AC.cm preserve=no
//## end module%3CB3429C00AC.cm

//## begin module%3CB3429C00AC.cp preserve=no
//## end module%3CB3429C00AC.cp

//## Module: CObject3D_Transf%3CB3429C00AC; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\CObject3D_Transf.cpp

//## begin module%3CB3429C00AC.additionalIncludes preserve=no
//## end module%3CB3429C00AC.additionalIncludes

//## begin module%3CB3429C00AC.includes preserve=yes
#include "E3D/Drivers/OGL/CE3D_OGL_Win_Renderer.h"
//## end module%3CB3429C00AC.includes

// CObject3D_Transf
#include "Scene\CObject3D_Transf.h"
//## begin module%3CB3429C00AC.additionalDeclarations preserve=yes
//## end module%3CB3429C00AC.additionalDeclarations


// Class CObject3D_Transf 







CObject3D_Transf::CObject3D_Transf()
  //## begin CObject3D_Transf::CObject3D_Transf%.hasinit preserve=no
  //## end CObject3D_Transf::CObject3D_Transf%.hasinit
  //## begin CObject3D_Transf::CObject3D_Transf%.initialization preserve=yes
  //## end CObject3D_Transf::CObject3D_Transf%.initialization
{
  //## begin CObject3D_Transf::CObject3D_Transf%.body preserve=yes
	TypeID		 = e3DObj_Transf;

	oPos.V3 (0.0f,0.0f,0.0f);	
	
	oSide.V3(1.0f,0.0f,0.0f);
	oDir.V3 (0.0f,1.0f,0.0f);
	oUp.V3  (0.0f,0.0f,1.0f);

    oTransf.LoadIdentity();
	
	BVol		 = CGraphBV_Manager::poCreate();
	bFrustumTest = false;
  //## end CObject3D_Transf::CObject3D_Transf%.body
}


CObject3D_Transf::~CObject3D_Transf()
{
  //## begin CObject3D_Transf::~CObject3D_Transf%.body preserve=yes
  //## end CObject3D_Transf::~CObject3D_Transf%.body
}



//## Other Operations (implementation)
void CObject3D_Transf::SetPos (CVect3& _roPos)
{
  //## begin CObject3D_Transf::SetPos%1018703073.body preserve=yes
	oPos.Assign(_roPos);
	SetupTransformation();
  //## end CObject3D_Transf::SetPos%1018703073.body
}

CVect3& CObject3D_Transf::roPos ()
{
  //## begin CObject3D_Transf::roPos%1018703074.body preserve=yes
	return (oPos);
  //## end CObject3D_Transf::roPos%1018703074.body
}

void CObject3D_Transf::SetDir (CVect3& _roDir)
{
  //## begin CObject3D_Transf::SetDir%1019293387.body preserve=yes
	oDir.Assign(_roDir);
	SetupTransformation();
  //## end CObject3D_Transf::SetDir%1019293387.body
}

CVect3& CObject3D_Transf::roDir ()
{
  //## begin CObject3D_Transf::roDir%1019293388.body preserve=yes
	return(oDir);
  //## end CObject3D_Transf::roDir%1019293388.body
}

void CObject3D_Transf::SetUp (CVect3& _roUp)
{
  //## begin CObject3D_Transf::SetUp%1019293389.body preserve=yes
	oUp.Assign(_roUp);
	SetupTransformation();
  //## end CObject3D_Transf::SetUp%1019293389.body
}

CVect3& CObject3D_Transf::roUp ()
{
  //## begin CObject3D_Transf::roUp%1019293390.body preserve=yes
	return(oUp);
  //## end CObject3D_Transf::roUp%1019293390.body
}

void CObject3D_Transf::SetSide (CVect3& _roSide)
{
  //## begin CObject3D_Transf::SetSide%1019293391.body preserve=yes
	oSide.Assign(_roSide);
	SetupTransformation();
  //## end CObject3D_Transf::SetSide%1019293391.body
}

CVect3& CObject3D_Transf::roSide ()
{
  //## begin CObject3D_Transf::roSide%1019293392.body preserve=yes
	return(oSide);
  //## end CObject3D_Transf::roSide%1019293392.body
}

void CObject3D_Transf::Setup (CVect3& _roPos, CVect3& _roDir, CVect3& _roSide, CVect3& _roUp)
{
  //## begin CObject3D_Transf::Setup%1019293393.body preserve=yes
	oPos .Assign(_roPos);
	oDir .Assign(_roDir);
	oSide.Assign(_roSide);
	oUp  .Assign(_roUp);
	
	SetupTransformation();
  //## end CObject3D_Transf::Setup%1019293393.body
}

void CObject3D_Transf::SetTransf (CMatrix4x4& _roTransf)
{
  //## begin CObject3D_Transf::SetTransf%1018703083.body preserve=yes
	CVect4 oP = _roTransf.GetColVector(3);	
	CVect4 oS = _roTransf.GetColVector(0);	// X
	CVect4 oD = _roTransf.GetColVector(1);	// Y
	CVect4 oU = _roTransf.GetColVector(2);	// Z

	oPos .V3(oP.X(),oP.Y(),oP.Z());
	oSide.V3(oS.X(),oS.Y(),oS.Z());
	oDir .V3(oD.X(),oD.Y(),oD.Z());
	oUp  .V3(oU.X(),oU.Y(),oU.Z());
	
	oTransf = _roTransf;

	// Recompute Bounding Volume
	BVol->Copy( poObj->poGetBoundVol() );
	BVol->Transform(oTransf);
  //## end CObject3D_Transf::SetTransf%1018703083.body
}

CMatrix4x4& CObject3D_Transf::roTransf ()
{
  //## begin CObject3D_Transf::roTransf%1018703084.body preserve=yes
	return(oTransf);
  //## end CObject3D_Transf::roTransf%1018703084.body
}

void CObject3D_Transf::SetObject (CObject3D* _poObj)
{
  //## begin CObject3D_Transf::SetObject%1018703876.body preserve=yes
	assert (_poObj && "NULL Object");
	poObj = _poObj;
  //## end CObject3D_Transf::SetObject%1018703876.body
}

CObject3D* CObject3D_Transf::poGetObject ()
{
  //## begin CObject3D_Transf::poGetObject%1018703877.body preserve=yes
	return (poObj);	
  //## end CObject3D_Transf::poGetObject%1018703877.body
}

void CObject3D_Transf::SetupTransformation ()
{
  //## begin CObject3D_Transf::SetupTransformation%1018703878.body preserve=yes

	// Setup transformation matrix from separate vectors
	oTransf.SetColVector(0,oSide.X(),oSide.Y(),oSide.Z(),0.0f);
	oTransf.SetColVector(1,oDir .X(),oDir .Y(),oDir .Z(),0.0f);
	oTransf.SetColVector(2,oUp  .X(),oUp  .Y(),oUp  .Z(),0.0f);
	oTransf.SetColVector(3,oPos .X(),oPos .Y(),oPos .Z(),1.0f);

	// Recompute Bounding Volume
	BVol->Copy( poObj->poGetBoundVol() );
	BVol->Transform(oTransf);

  //## end CObject3D_Transf::SetupTransformation%1018703878.body
}

void CObject3D_Transf::ComputeBoundVol ()
{
  //## begin CObject3D_Transf::ComputeBoundVol%1018703071.body preserve=yes
	poObj->ComputeBoundVol();
	BVol->Copy( poObj->poGetBoundVol() );
	BVol->Transform(oTransf);
  //## end CObject3D_Transf::ComputeBoundVol%1018703071.body
}

CGraphBV* CObject3D_Transf::poGetBoundVol ()
{
  //## begin CObject3D_Transf::poGetBoundVol%1018703070.body preserve=yes
	return (BVol);
  //## end CObject3D_Transf::poGetBoundVol%1018703070.body
}

void CObject3D_Transf::Render ()
{
  //## begin CObject3D_Transf::Render%1018703072.body preserve=yes
	gpoE3DRenderer->PushLocalFrustum();	
	gpoE3DRenderer->PushMatrix();

		if (gpoE3DRenderer->UsingBBoxRender())
		{
			((CE3D_OGL_Win_Renderer*)gpoE3DRenderer)->RenderBBox(poGetBoundVol());
		}
		
		// Setup new reference system
		gpoE3DRenderer->MultiplyMatrix(&oTransf);

		// Get the local frustum
		/*
		if ((poObj->eGetTypeID() != e3DObj_Leaf) &&
			(poObj->eGetTypeID() != e3DObj_CompiledLeaf))
		*/
			gpoE3DRenderer->ComputeLocalFrustum();
		
		// We only can test visibility after performing the camera transformation
		if ( bVisible() ) 
			poObj->Render();

	// Restore current state
	gpoE3DRenderer->PopMatrix();
	gpoE3DRenderer->PopLocalFrustum();
  //## end CObject3D_Transf::Render%1018703072.body
}

// Additional Declarations
  //## begin CObject3D_Transf%3CB3429C00AC.declarations preserve=yes
  //## end CObject3D_Transf%3CB3429C00AC.declarations

//## begin module%3CB3429C00AC.epilog preserve=yes
//## end module%3CB3429C00AC.epilog
