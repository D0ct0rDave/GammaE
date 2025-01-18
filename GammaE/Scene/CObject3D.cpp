//## begin module%3AA256E702BC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AA256E702BC.cm

//## begin module%3AA256E702BC.cp preserve=no
//## end module%3AA256E702BC.cp

//## Module: CObject3D%3AA256E702BC; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\CObject3D.cpp

//## begin module%3AA256E702BC.additionalIncludes preserve=no
//## end module%3AA256E702BC.additionalIncludes

//## begin module%3AA256E702BC.includes preserve=yes
//## end module%3AA256E702BC.includes

// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3AA256E702BC.additionalDeclarations preserve=yes
//## end module%3AA256E702BC.additionalDeclarations


// Class CObject3D 








CObject3D::CObject3D()
  //## begin CObject3D::CObject3D%.hasinit preserve=no
      : BVol(NULL), NumRefs(0), bFrustumTest(false)
  //## end CObject3D::CObject3D%.hasinit
  //## begin CObject3D::CObject3D%.initialization preserve=yes
  //## end CObject3D::CObject3D%.initialization
{
  //## begin CObject3D::CObject3D%.body preserve=yes
	TypeID   = e3DObj_Gen;
  //## end CObject3D::CObject3D%.body
}


CObject3D::~CObject3D()
{
  //## begin CObject3D::~CObject3D%.body preserve=yes
  //## end CObject3D::~CObject3D%.body
}



//## Other Operations (implementation)
void CObject3D::Reference ()
{
  //## begin CObject3D::Reference%999094732.body preserve=yes
	NumRefs++;
  //## end CObject3D::Reference%999094732.body
}

void CObject3D::UnReference ()
{
  //## begin CObject3D::UnReference%999094733.body preserve=yes
	NumRefs--;
	if (! NumRefs) mDel (this);
  //## end CObject3D::UnReference%999094733.body
}

bool CObject3D::bVisible ()
{
  //## begin CObject3D::bVisible%1006904816.body preserve=yes
  	if (gpoE3DRenderer->UsingFrustumCulling())
	{
		if (! bFrustumTest) return(true);
		CGraphBV* poBV = poGetBoundVol();
		if (poBV != NULL)
		{
			return ( poGetBoundVol()->TestFrustum( gpoE3DRenderer->GetLocalFrustum() ) );
		}
		else
		{
			return(true);
		}
	}
	else
		return(true);
//## end CObject3D::bVisible%1006904816.body
}

// Additional Declarations
  //## begin CObject3D%3AA256E702BC.declarations preserve=yes
  //## end CObject3D%3AA256E702BC.declarations

//## begin module%3AA256E702BC.epilog preserve=yes
//## end module%3AA256E702BC.epilog
