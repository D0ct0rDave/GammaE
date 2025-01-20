//## begin module%3A9AD9D4032A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AD9D4032A.cm

//## begin module%3A9AD9D4032A.cp preserve=no
//## end module%3A9AD9D4032A.cp

//## Module: CPlane%3A9AD9D4032A; Pseudo Package body
//## Source file: i:\Projects\GammaE\Math\MATH_Plane\CPlane.cpp

//## begin module%3A9AD9D4032A.additionalIncludes preserve=no
//## end module%3A9AD9D4032A.additionalIncludes

//## begin module%3A9AD9D4032A.includes preserve=yes
//## end module%3A9AD9D4032A.includes

// CPlane
#include "Math\MATH_Plane\CPlane.h"
//## begin module%3A9AD9D4032A.additionalDeclarations preserve=yes
//## end module%3A9AD9D4032A.additionalDeclarations


// Class CPlane 





CPlane::CPlane()
  //## begin CPlane::CPlane%.hasinit preserve=no
      : PlaneD(0)
  //## end CPlane::CPlane%.hasinit
  //## begin CPlane::CPlane%.initialization preserve=yes
  //## end CPlane::CPlane%.initialization
{
  //## begin CPlane::CPlane%.body preserve=yes
  //## end CPlane::CPlane%.body
}



//## Other Operations (implementation)
void CPlane::GenerateFromVectors (CVect3 VDir1, CVect3 VDir2, CVect3 VOrigin)
{
  //## begin CPlane::GenerateFromVectors%998231931.body preserve=yes
  	
	// Compute plane normal
	PlaneNormal.CrossProd(VDir1,VDir2);
    PlaneNormal.Normalize();

    PlaneOrigin = VOrigin;

    PlaneD = - PlaneNormal.DotProd(PlaneOrigin);
  //## end CPlane::GenerateFromVectors%998231931.body
}

void CPlane::GenerateFromPoints (CVect3& a, CVect3& b, CVect3& c)
{
  //## begin CPlane::GenerateFromPoints%998231932.body preserve=yes

//---------------------------------------------------------------------------
//               ___________ n ____   n = ab x cb
//              /     a      |    /   b belongs to the plane-> we take it as 
//			   /	 / \     |   /	  the plane origin
//            /     b____\c     /	  
//           /_________________/
// 
//  Plane equation : Ax + By + Cz + D = 0
//				  (A,B,C) = (nx,ny,nz) = plane normal components
//				  x y z are components of a point belonging to the plane
//				  point b (bx,by,bz) belongs also to the plane
//				  nx*bx + ny*by + nz*bz + D = 0
//				  nx*bx + ny*by + nz*bz = dot prod between b and n
//				  dotprod(b,n) + D = 0
//				  Then dotprod(b,n) = -D
//				  Then D = - dotprod(b,n)
//				  D = Distance from plane to the origin (0,0,0)
//---------------------------------------------------------------------------

    PlaneNormal.Normal(a,b,c);
    PlaneNormal.Normalize();

	PlaneOrigin = a;

	PlaneD = - PlaneNormal.DotProd(PlaneOrigin);
  //## end CPlane::GenerateFromPoints%998231932.body
}

void CPlane::GeneratePlaneFromFields (CVect3& VOrigin, CVect3& VNormal)
{
  //## begin CPlane::GeneratePlaneFromFields%998231933.body preserve=yes
	PlaneNormal = VNormal;
    PlaneNormal.Normalize();

	PlaneOrigin = VOrigin;

    PlaneD = - PlaneNormal.DotProd(PlaneOrigin);
  //## end CPlane::GeneratePlaneFromFields%998231933.body
}

float CPlane::GetDistanceToPoint (CVect3& Point)
{
  //## begin CPlane::GetDistanceToPoint%998231934.body preserve=yes
	/*
	CVect3 oS;
	oS.Assign(Point);
	oS.Sub(PlaneOrigin);
	return ( PlaneNormal.DotProd(oS));
	*/
	return ( PlaneNormal.DotProd(Point) + PlaneD );
  //## end CPlane::GetDistanceToPoint%998231934.body
}

bool CPlane::Coplanar (CPlane& Plane)
{
  //## begin CPlane::Coplanar%998231935.body preserve=yes

//---------------------------------------------------------------------------
// 2 planos son coplanarios, si los vectores normales son identicos (o angulo entre ellos 0)
// y el vector formado entre los puntos origen de ambos planos es perpendicular
// a la normal de los planos
//                         N1
//                        _|___
//                    N2 / |  /  Plano1
//                      |_xO1/
//                     _|/__
//					 /  x  /
//                  /__O2_/  Plano2
//
//---------------------------------------------------------------------------
// What about the W field ???
//---------------------------------------------------------------------------

	// angulo 0: dot product = 1 = coseno del angulo que forman los vectores
	// if (PlaneNormal.DotProd(Plane.Normal()) != 1.0f) return(false);
	if (MATH_Common::fAbs( PlaneNormal.DotProd(Plane.Normal()) ) != 1.0f) return(false);

    // angulo que forma la normal del plano con el vector diferencia
    // ha de ser de 90º: dot product = 0 = coseno del angulo de los 2 vectores
    CVect3 VDiff = PlaneOrigin;	VDiff.Sub(PlaneOrigin);

    return(PlaneNormal.DotProd(VDiff) == 0.0f);
  //## end CPlane::Coplanar%998231935.body
}

void CPlane::Transform (CMatrix4x4& _Transf)
{
  //## begin CPlane::Transform%1006987067.body preserve=yes
	_Transf.TransformPoint (PlaneOrigin);
	_Transf.TransformVector(PlaneNormal);

	PlaneD = - PlaneNormal.DotProd(PlaneOrigin);
  //## end CPlane::Transform%1006987067.body
}

CVect3 CPlane::ProjectPoint (CVect3& _Point)
{
  //## begin CPlane::ProjectPoint%1007685158.body preserve=yes
	CVect3 Proj;
	// Se proyecta el punto en direccion contraria a la normal
	Proj.LineEq(_Point,PlaneNormal,-GetDistanceToPoint(_Point));
	return(Proj);
  //## end CPlane::ProjectPoint%1007685158.body
}

int CPlane::iPlaneType ()
{
  //## begin CPlane::iPlaneType%1014330411.body preserve=yes
	 if ((PlaneNormal.X() == 1.0f) || (PlaneNormal.X() == -1.0f))
	 	return(0);
else if ((PlaneNormal.Y() == 1.0f) || (PlaneNormal.Y() == -1.0f))
		return(1);
else if ((PlaneNormal.Z() == 1.0f) || (PlaneNormal.Z() == -1.0f))
		return(2);

	float aX,aY,aZ;
		
	aX = MATH_Common::fAbs( PlaneNormal.X() );
	aY = MATH_Common::fAbs( PlaneNormal.Y() );
	aZ = MATH_Common::fAbs( PlaneNormal.Z() );
	
	if(aX >= aY && aX >= aZ)
		return(3);
	if(aY >= aX && aY >= aZ)
		return(4);
	
	return(5);
  //## end CPlane::iPlaneType%1014330411.body
}

// Additional Declarations
  //## begin CPlane%3A9AD9D4032A.declarations preserve=yes
  //## end CPlane%3A9AD9D4032A.declarations

//## begin module%3A9AD9D4032A.epilog preserve=yes
//## end module%3A9AD9D4032A.epilog
