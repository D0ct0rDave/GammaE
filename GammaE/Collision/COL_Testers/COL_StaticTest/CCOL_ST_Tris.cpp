//## begin module%3C0D5B9F007B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0D5B9F007B.cm

//## begin module%3C0D5B9F007B.cp preserve=no
//## end module%3C0D5B9F007B.cp

//## Module: CCOL_ST_Tris%3C0D5B9F007B; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_StaticTest\CCOL_ST_Tris.cpp

//## begin module%3C0D5B9F007B.additionalIncludes preserve=no
//## end module%3C0D5B9F007B.additionalIncludes

//## begin module%3C0D5B9F007B.includes preserve=yes
//## end module%3C0D5B9F007B.includes

// CCOL_ST_Tris
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_Tris.h"
//## begin module%3C0D5B9F007B.additionalDeclarations preserve=yes

inline void GetMinMaxRad2(int axis1,int axis2,CVect3 &v0,CVect3 &v1,float fS,
					 CVect3 &e,CVect3 &Abs,CVect3 &BHS,
					 float &min,float &max,float &rad)
{
	float p0,p1;

	p0 = fS*(e.v[axis2]*v0.v[axis1] - e.v[axis1]*v0.v[axis2]);
	p1 = fS*(e.v[axis2]*v1.v[axis1] - e.v[axis1]*v1.v[axis2]);
	
	if (p0<p1){min=p0;max=p1;} else {min=p1;max=p0;}
	rad = Abs.v[axis2]*BHS.v[axis1] + Abs.v[axis1]*BHS.v[axis2];
}
//## end module%3C0D5B9F007B.additionalDeclarations


// Class CCOL_ST_Tris 

//## begin CCOL_ST_Tris::Tri%3C0D5C0D00FC.attr preserve=no  public: static int {UA} 
int CCOL_ST_Tris::Tri;
//## end CCOL_ST_Tris::Tri%3C0D5C0D00FC.attr

//## begin CCOL_ST_Tris::pVX%3C0D5CD60390.attr preserve=no  protected: static CVect3 * {UA} NULL
CVect3 *CCOL_ST_Tris::pVX = NULL;
//## end CCOL_ST_Tris::pVX%3C0D5CD60390.attr

//## begin CCOL_ST_Tris::pVN%3C0D5CDE01BB.attr preserve=no  protected: static CVect3 * {UA} NULL
CVect3 *CCOL_ST_Tris::pVN = NULL;
//## end CCOL_ST_Tris::pVN%3C0D5CDE01BB.attr

//## begin CCOL_ST_Tris::iNumTris%3C0D5CE3032A.attr preserve=no  protected: static int {UA} 
int CCOL_ST_Tris::iNumTris;
//## end CCOL_ST_Tris::iNumTris%3C0D5CE3032A.attr

//## begin CCOL_ST_Tris::Pos%3C0D6CFC0131.attr preserve=no  protected: static CVect3 {UA} 
CVect3 CCOL_ST_Tris::Pos;
//## end CCOL_ST_Tris::Pos%3C0D6CFC0131.attr

CCOL_ST_Tris::CCOL_ST_Tris()
  //## begin CCOL_ST_Tris::CCOL_ST_Tris%.hasinit preserve=no
  //## end CCOL_ST_Tris::CCOL_ST_Tris%.hasinit
  //## begin CCOL_ST_Tris::CCOL_ST_Tris%.initialization preserve=yes
  //## end CCOL_ST_Tris::CCOL_ST_Tris%.initialization
{
  //## begin CCOL_ST_Tris::CCOL_ST_Tris%.body preserve=yes
  //## end CCOL_ST_Tris::CCOL_ST_Tris%.body
}


CCOL_ST_Tris::~CCOL_ST_Tris()
{
  //## begin CCOL_ST_Tris::~CCOL_ST_Tris%.body preserve=yes
  //## end CCOL_ST_Tris::~CCOL_ST_Tris%.body
}



//## Other Operations (implementation)
int CCOL_ST_Tris::iTestCollision (CVect3* _pVXs, CVect3* _pVNs, int _iNumTris, CGraphBV* _BV, CVect3& _Pos)
{
  //## begin CCOL_ST_Tris::iTestCollision%1007508516.body preserve=yes
	assert( _pVXs  && "NULL triangle list");
	assert( _pVNs  && "NULL normal  list");

	pVX      = _pVXs;
	pVN      = _pVNs;
	iNumTris = _iNumTris;
	Pos.Assign(_Pos);

	switch (_BV->eGetTypeID())
	{
		case eGraphBV_Sphere:	CBoundingSphere *BS;
								BS = ((CGraphBV_Sphere*)_BV)->pGetSphere();								
								return(iTestCollisionSphere(BS->Radius,BS->Center));
		case eGraphBV_Box:		CBoundingBox	*BB;
								BB = ((CGraphBV_Box*)_BV)->pGetBox();								
								return(iTestCollisionBox(BB->Maxs,BB->Mins));
		default:		
								return(false);
	}
  //## end CCOL_ST_Tris::iTestCollision%1007508516.body
}

int CCOL_ST_Tris::iTestCollisionSphere (float _fRad, CVect3& _Center)
{
  //## begin CCOL_ST_Tris::iTestCollisionSphere%1007508517.body preserve=yes
	int		iCollidedTris;
	int		iTri;

	CVect3	*pReadVX  = pVX;
	CVect3	*pWriteVX = pVX;
	CVect3	*pReadVN  = pVN;
	CVect3	*pWriteVN = pVN;

	Pos.Add(_Center);
		
	iCollidedTris = 0;
	for (iTri=0;iTri<iNumTris;iTri++)
	{
		if (iTestTriangleSphere(pReadVX,_fRad,Pos))
		{
			pWriteVX[0].Assign( pReadVX[0] );
			pWriteVX[1].Assign( pReadVX[1] );
			pWriteVX[2].Assign( pReadVX[2] );
			
			pWriteVN->Assign( *pReadVN );
			
			pWriteVX += 3;
			pWriteVN ++;

			iCollidedTris++;
		}

		pReadVX += 3;
		pReadVN ++;
	}
	
	return (iCollidedTris);
  //## end CCOL_ST_Tris::iTestCollisionSphere%1007508517.body
}

int CCOL_ST_Tris::iTestCollisionBox (CVect3& _Maxs, CVect3& _Mins)
{
  //## begin CCOL_ST_Tris::iTestCollisionBox%1007508518.body preserve=yes
	int		iCollidedTris;
	int		iTri;
	CVect3	NMaxs,NMins;

	CVect3	*pReadVX  = pVX;
	CVect3	*pWriteVX = pVX;
	CVect3	*pReadVN  = pVN;
	CVect3	*pWriteVN = pVN;
	
	NMaxs.Assign(_Maxs);
	NMaxs.Add(Pos);
	
	NMins.Assign(_Mins);
	NMins.Add(Pos);

	iCollidedTris = 0;
	for (iTri=0;iTri<iNumTris;iTri++)
	{
		if (iTestTriangleBox(pReadVX,NMaxs,NMins))
		{
			pWriteVX[0].Assign( pReadVX[0] );
			pWriteVX[1].Assign( pReadVX[1] );
			pWriteVX[2].Assign( pReadVX[2] );
			
			pWriteVN->Assign( *pReadVN );
			
			pWriteVX += 3;
			pWriteVN ++;

			iCollidedTris++;
		}

		pReadVX += 3;
		pReadVN ++;
	}
	
	return (iCollidedTris);
  //## end CCOL_ST_Tris::iTestCollisionBox%1007508518.body
}

int CCOL_ST_Tris::iTestCollisionRay (CRay& _Ray)
{
  //## begin CCOL_ST_Tris::iTestCollisionRay%1007508519.body preserve=yes
	return(false);
  //## end CCOL_ST_Tris::iTestCollisionRay%1007508519.body
}

int CCOL_ST_Tris::iTestTriangleSphere (CVect3* _pVXs, float _fRad, CVect3& _Center)
{
  //## begin CCOL_ST_Tris::iTestTriangleSphere%1007685155.body preserve=yes
	CTriangle	Tri;
	Tri.Init(_pVXs);
	float fSqDist = MATH_Utils::fTriPointSqDistance(Tri,_Center);
	return ( fSqDist < _SQ_(_fRad) );
  //## end CCOL_ST_Tris::iTestTriangleSphere%1007685155.body
}

int CCOL_ST_Tris::iTestTriangleBox (CVect3* _pVXs, CVect3& _Maxs, CVect3& _Mins)
{
  //## begin CCOL_ST_Tris::iTestTriangleBox%1007685156.body preserve=yes
	
	// ---------------------------------------------------------
	//	Based on AABB-triangle overlap test code by Tomas Möller
	// ---------------------------------------------------------
	

	// First we test if the triangle bounding box intersects with the source bounding box
	// This is performed using the separating axis test, which is done separatelly with
	// every one of the 3 bounding box axis
	CVect3  TMins,TMaxs;	

	// Test X axis:
	MATH_Utils::GetMaxMins( _pVXs[0].X(),_pVXs[1].X(),_pVXs[2].X(),TMaxs.v[0],TMins.v[0] );
	if ( (TMins.X() > _Maxs.X()) || (TMaxs.X() < _Mins.X()) ) return(0);
	
	// Test Y axis:
	MATH_Utils::GetMaxMins( _pVXs[0].Y(),_pVXs[1].Y(),_pVXs[2].Y(),TMaxs.v[1],TMins.v[1] );
	if ( (TMins.Y() > _Maxs.Y()) || (TMaxs.Y() < _Mins.Y()) ) return(0);

	// Test Z axis:
	MATH_Utils::GetMaxMins( _pVXs[0].Z(),_pVXs[1].Z(),_pVXs[2].Z(),TMaxs.v[2],TMins.v[2] );
	if ( (TMins.Z() > _Maxs.Z()) || (TMaxs.Z() < _Mins.Z()) ) return(0);




	// Test if the triangle really crosses the bounding box. This is performed by testing 
	// if the triangle plane splits the box. If not, then the triangle doesn't overlap the box
	CPlane	Plane;
	Plane.GenerateFromPoints(_pVXs[0],_pVXs[1],_pVXs[2]);
	if ( MATH_Utils::iTestBoxPlane(_Maxs,_Mins,Plane) != 0) return(0);	
	
	// Ok now test if the box crosses some of the 3 triangle edges
	// Get triangle edges
	CVect3	Edge;
	CVect3	AbsE;
	float	min,max,rad;
	
	CVect3	BoxCenter,BoxHalfSize,v0,v1,v2;

	BoxCenter.Assign(_Maxs);	BoxCenter.Add   (_Mins);	BoxCenter.Scale (0.5f );
	BoxHalfSize.Assign(_Maxs);	BoxHalfSize.Sub   (_Mins);	BoxHalfSize.Scale (0.5f );
	v0.Assign(_pVXs[0]);	v0.Sub   (BoxCenter);
	v1.Assign(_pVXs[1]);	v1.Sub   (BoxCenter);
	v2.Assign(_pVXs[2]);	v2.Sub   (BoxCenter);
	
	//-------------
	// test e0 edge
	//-------------
	Edge.Assign(_pVXs[0]);	Edge.Sub(_pVXs[1]);
	AbsE.V3( fabs(Edge.X()),fabs(Edge.Y()),fabs(Edge.Z()) );

	GetMinMaxRad2(_Y_,_Z_,v0,v2, 1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);
	
	GetMinMaxRad2(_X_,_Z_,v0,v2,-1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	GetMinMaxRad2(_X_,_Y_,v1,v2, 1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	//-------------
	// test e1 edge
	//-------------
	Edge.Assign(_pVXs[1]);	Edge.Sub   (_pVXs[2]);
	AbsE.V3( fabs(Edge.X()),fabs(Edge.Y()),fabs(Edge.Z()) );

	GetMinMaxRad2(_Y_,_Z_,v0,v2, 1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);
	
	GetMinMaxRad2(_X_,_Z_,v0,v2,-1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	GetMinMaxRad2(_X_,_Y_,v0,v1, 1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	//-------------
	// test e2 edge
	//-------------
	Edge.Assign(_pVXs[2]);	Edge.Sub   (_pVXs[0]);
	AbsE.V3( fabs(Edge.X()),fabs(Edge.Y()),fabs(Edge.Z()) );

	GetMinMaxRad2(_Y_,_Z_,v0,v1,-1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	GetMinMaxRad2(_X_,_Z_,v0,v1,-1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	GetMinMaxRad2(_X_,_Y_,v1,v2, 1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	return(1);
  //## end CCOL_ST_Tris::iTestTriangleBox%1007685156.body
}

int CCOL_ST_Tris::iTestTriangleRay (CVect3* _pVXs, CRay& _Ray)
{
  //## begin CCOL_ST_Tris::iTestTriangleRay%1007685157.body preserve=yes
	CTriangle Tri;
	Tri.Init(_pVXs);

	return (MATH_Utils::iTestRayTriIntersection(_Ray,Tri));
  //## end CCOL_ST_Tris::iTestTriangleRay%1007685157.body
}

// Additional Declarations
  //## begin CCOL_ST_Tris%3C0D5B9F007B.declarations preserve=yes
  //## end CCOL_ST_Tris%3C0D5B9F007B.declarations

//## begin module%3C0D5B9F007B.epilog preserve=yes
//## end module%3C0D5B9F007B.epilog
