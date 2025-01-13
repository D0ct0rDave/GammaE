//## begin module%3BE9C5D6002E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE9C5D6002E.cm

//## begin module%3BE9C5D6002E.cp preserve=no
//## end module%3BE9C5D6002E.cp

//## Module: CObject3D_BSPNode%3BE9C5D6002E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\CObject3D_BSPNode.cpp

//## begin module%3BE9C5D6002E.additionalIncludes preserve=no
//## end module%3BE9C5D6002E.additionalIncludes

//## begin module%3BE9C5D6002E.includes preserve=yes
//## end module%3BE9C5D6002E.includes

// CObject3D_BSPNode
#include "Scene\CObject3D_BSPNode.h"
//## begin module%3BE9C5D6002E.additionalDeclarations preserve=yes
//## end module%3BE9C5D6002E.additionalDeclarations


// Class CObject3D_BSPNode 




CObject3D_BSPNode::CObject3D_BSPNode()
  //## begin CObject3D_BSPNode::CObject3D_BSPNode%.hasinit preserve=no
      : poBackNode(NULL), poFrontNode(NULL)
  //## end CObject3D_BSPNode::CObject3D_BSPNode%.hasinit
  //## begin CObject3D_BSPNode::CObject3D_BSPNode%.initialization preserve=yes
  //## end CObject3D_BSPNode::CObject3D_BSPNode%.initialization
{
  //## begin CObject3D_BSPNode::CObject3D_BSPNode%.body preserve=yes
    TypeID		 = e3DObj_BSPNode;
	BVol		 = CGraphBV_Manager::poCreate();
	bFrustumTest = true;
  //## end CObject3D_BSPNode::CObject3D_BSPNode%.body
}


CObject3D_BSPNode::~CObject3D_BSPNode()
{
  //## begin CObject3D_BSPNode::~CObject3D_BSPNode%.body preserve=yes
  //## end CObject3D_BSPNode::~CObject3D_BSPNode%.body
}



//## Other Operations (implementation)
void CObject3D_BSPNode::Render ()
{
  //## begin CObject3D_BSPNode::Render%1005176633.body preserve=yes
	float			fCamPlaneAngle;
	float			fCamPlaneDist;
	CE3D_Camera		*poCam;
	float			fFOV;
	float			fAngleLimit;		

	poCam      = gpoE3DRenderer->GetCamera();
	fFOV       = gpoE3DRenderer->GetProjector()->fFOV;

	// Get the angle between the camera and the plane
	fCamPlaneAngle = oPartitionPlane.Normal().DotProd( poCam->Dir );	

	// Test the side of the plane the camera is
	if ( MATH_Utils::iTestPointPlane(poCam->Pos,oPartitionPlane) >= 0)
	{
		// The camera is in the front half space of the plane
		fAngleLimit= cos((90.0f - fFOV*0.5f)*_PI_OVER_180_);	 // cos(90 - Fov/2);

		// The camera could see part of the back space of the plane?
		// if (fCamPlaneAngle < fAngleLimit)
			if (poBackNode)
				if (poBackNode->bVisible() )
					poBackNode->Render();	
		
		if (poFrontNode)
			poFrontNode->Render();
	}
	else
	{
		// The camera is in the back half space of the plane
		fAngleLimit= cos( (90.0f + fFOV*0.5f)*_PI_OVER_180_ );

		// The camera could see part of the front space of the plane?
		// if (fCamPlaneAngle > fAngleLimit)
			if (poFrontNode)
				if (poFrontNode->bVisible() )
					poFrontNode->Render();					// farthest area in rendering

		// Back to front display
		if (poBackNode)
			poBackNode->Render();		
	}	
  //## end CObject3D_BSPNode::Render%1005176633.body
}

CGraphBV* CObject3D_BSPNode::poGetBoundVol ()
{
  //## begin CObject3D_BSPNode::poGetBoundVol%1005176631.body preserve=yes
	return (BVol);
  //## end CObject3D_BSPNode::poGetBoundVol%1005176631.body
}

void CObject3D_BSPNode::ComputeBoundVol ()
{
  //## begin CObject3D_BSPNode::ComputeBoundVol%1005176632.body preserve=yes

  	// Las bounding boxes de los objetos deben tener en cuenta
	// las transformaciones que se deben realizar en los nodos 
	// hijos. Probar a transformar la BoundingBox mediante la
	// matriz asociada al nodo. Despues volver a obtener
	// los max y los mins, para volver a tener una AABB
	
	int				cObj;
	float			fXSide,fYSide,fZSide;
    CVect3			Maxs,Mins,Center;
	CGraphBV		*BV;
	CObject3D		*poSubObjs[2];

	poSubObjs[0] = poFrontNode;
	poSubObjs[1] = poBackNode;

    Mins.V3( 1000000000, 1000000000, 1000000000);
    Maxs.V3(-1000000000,-1000000000,-1000000000);

    for (cObj=0;cObj<2;cObj++)
    {
		if (poSubObjs[cObj])
		{
			// Compute the AABB for the object
			poSubObjs[cObj]->ComputeBoundVol();
			BV = poSubObjs[cObj]->poGetBoundVol();

			// Get object properties
			fXSide = BV->GetRange(0)*0.5f;
			fYSide = BV->GetRange(1)*0.5f;
			fZSide = BV->GetRange(2)*0.5f;			
			Center = BV->GetCenter();

			// Compute Maxs/Mins vectors
			if ( Center.X() + fXSide > Maxs.X() ) Maxs.SetX(Center.X() + fXSide);
			if ( Center.X() - fXSide < Mins.X() ) Mins.SetX(Center.X() - fXSide);

			if ( Center.Y() + fYSide > Maxs.Y() ) Maxs.SetY(Center.Y() + fYSide);
			if ( Center.Y() - fYSide < Mins.Y() ) Mins.SetY(Center.Y() - fYSide);

			if ( Center.Z() + fZSide > Maxs.Z() ) Maxs.SetZ(Center.Z() + fZSide);
			if ( Center.Z() - fZSide < Mins.Z() ) Mins.SetZ(Center.Z() - fZSide);
		}
    }

	BVol->Init(Maxs,Mins);	
  //## end CObject3D_BSPNode::ComputeBoundVol%1005176632.body
}

void CObject3D_BSPNode::Setup (CObject3D* _poBack, CObject3D *_poFront, CPlane& _roPlane)
{
  //## begin CObject3D_BSPNode::Setup%1005176628.body preserve=yes
	poBackNode       = _poBack;
	poFrontNode      = _poFront;
	oPartitionPlane  = _roPlane;
  //## end CObject3D_BSPNode::Setup%1005176628.body
}

void CObject3D_BSPNode::SetBackNode (CObject3D* _poBack)
{
  //## begin CObject3D_BSPNode::SetBackNode%1005176629.body preserve=yes
	poBackNode = _poBack;
  //## end CObject3D_BSPNode::SetBackNode%1005176629.body
}

void CObject3D_BSPNode::SetFrontNode (CObject3D* _poFront)
{
  //## begin CObject3D_BSPNode::SetFrontNode%1005176630.body preserve=yes
	poFrontNode = _poFront;
  //## end CObject3D_BSPNode::SetFrontNode%1005176630.body
}

CObject3D* CObject3D_BSPNode::poGetBackNode ()
{
  //## begin CObject3D_BSPNode::poGetBackNode%1011999907.body preserve=yes
	return(poBackNode);
  //## end CObject3D_BSPNode::poGetBackNode%1011999907.body
}

CObject3D* CObject3D_BSPNode::poGetFrontNode ()
{
  //## begin CObject3D_BSPNode::poGetFrontNode%1011999908.body preserve=yes
	return (poFrontNode);
  //## end CObject3D_BSPNode::poGetFrontNode%1011999908.body
}

void CObject3D_BSPNode::SetPartitionPlane (CPlane &_roPlane)
{
  //## begin CObject3D_BSPNode::SetPartitionPlane%1005176634.body preserve=yes
	oPartitionPlane = _roPlane;
  //## end CObject3D_BSPNode::SetPartitionPlane%1005176634.body
}

CPlane * CObject3D_BSPNode::poGetPartitionPlane ()
{
  //## begin CObject3D_BSPNode::poGetPartitionPlane%1011999909.body preserve=yes
	return (&oPartitionPlane);
  //## end CObject3D_BSPNode::poGetPartitionPlane%1011999909.body
}

// Additional Declarations
  //## begin CObject3D_BSPNode%3BE9C5D6002E.declarations preserve=yes
  //## end CObject3D_BSPNode%3BE9C5D6002E.declarations

//## begin module%3BE9C5D6002E.epilog preserve=yes
//## end module%3BE9C5D6002E.epilog
