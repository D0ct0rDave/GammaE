




// CPlane
#include "MATH_Plane\CPlane.h"


// Class CPlane 






void CPlane::GenerateFromVectors (CVect3 VDir1, CVect3 VDir2, CVect3 VOrigin)
{
    	
	// Compute plane normal
	PlaneNormal.CrossProd(VDir1,VDir2);
    PlaneNormal.Normalize();

    PlaneOrigin = VOrigin;

    PlaneD = - PlaneNormal.fDotProd(PlaneOrigin);
}

void CPlane::GenerateFromPoints (CVect3& a, CVect3& b, CVect3& c)
{
  
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------

    PlaneNormal.Normal(a,b,c);
    PlaneNormal.Normalize();

	PlaneOrigin = a;

	PlaneD = - PlaneNormal.fDotProd(PlaneOrigin);
}

void CPlane::GeneratePlaneFromFields (CVect3& VOrigin, CVect3& VNormal)
{
  	PlaneNormal = VNormal;
    PlaneNormal.Normalize();

	PlaneOrigin = VOrigin;

    PlaneD = - PlaneNormal.fDotProd(PlaneOrigin);
}

float CPlane::GetDistanceToPoint (CVect3& Point)
{
  	/*
	CVect3 oS;
	oS.Assign(Point);
	oS.Sub(PlaneOrigin);
	return ( PlaneNormal.DotProd(oS));
	*/
	return ( PlaneNormal.fDotProd(Point) + PlaneD );
}

bool CPlane::Coplanar (CPlane& Plane)
{
  
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
// What about the W field ???
//-----------------------------------------------------------------------------

	// angulo 0: dot product = 1 = coseno del angulo que forman los vectores
	// if (PlaneNormal.DotProd(Plane.Normal()) != 1.0f) return(false);
	if (MATH_Common::fAbs( PlaneNormal.fDotProd(Plane.Normal()) ) != 1.0f) return(false);

    // angulo que forma la normal del plano con el vector diferencia
    // ha de ser de 90º: dot product = 0 = coseno del angulo de los 2 vectores
    CVect3 VDiff = PlaneOrigin;	VDiff.Sub(PlaneOrigin);

    return(PlaneNormal.fDotProd(VDiff) == 0.0f);
}

void CPlane::Transform (CMatrix4x4& _Transf)
{
  	_Transf.TransformPoint (PlaneOrigin);
	_Transf.TransformVector(PlaneNormal);

	PlaneD = - PlaneNormal.fDotProd(PlaneOrigin);
}

CVect3 CPlane::ProjectPoint (CVect3& _Point)
{
  	CVect3 Proj;
	// Se proyecta el punto en direccion contraria a la normal
	Proj.LineEq(_Point,PlaneNormal,-GetDistanceToPoint(_Point));
	return(Proj);
}

int CPlane::iPlaneType ()
{
  	 if ((PlaneNormal.x == 1.0f) || (PlaneNormal.x == -1.0f))
	 	return(0);
else if ((PlaneNormal.y == 1.0f) || (PlaneNormal.y == -1.0f))
		return(1);
else if ((PlaneNormal.z == 1.0f) || (PlaneNormal.z == -1.0f))
		return(2);

	float aX,aY,aZ;
		
	aX = MATH_Common::fAbs( PlaneNormal.x );
	aY = MATH_Common::fAbs( PlaneNormal.y );
	aZ = MATH_Common::fAbs( PlaneNormal.z );
	
	if(aX >= aY && aX >= aZ)
		return(3);
	if(aY >= aX && aY >= aZ)
		return(4);
	
	return(5);
}

// Additional Declarations
    
