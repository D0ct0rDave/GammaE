//	  %X% %Q% %Z% %W%



const int _X_ = 0;
const int _Y_ = 1;
const int _Z_ = 2;

// CCOL_ST_Tris
#include "COL_Testers\COL_StaticTest\CCOL_ST_Tris.h"

inline void GetMinMaxRad2(int axis1,int axis2,CVect3 &v0,CVect3 &v1,float fS,
					 CVect3 &e,CVect3 &Abs,CVect3 &BHS,
					 float &min,float &max,float &rad)
{
	float p0,p1;

	p0 = fS*(e.v(axis2)*v0.v(axis1) - e.v(axis1)*v0.v(axis2));
	p1 = fS*(e.v(axis2)*v1.v(axis1) - e.v(axis1)*v1.v(axis2));
	
	if (p0<p1){min=p0;max=p1;} else {min=p1;max=p0;}
	rad = Abs.v(axis2)*BHS.v(axis1) + Abs.v(axis1)*BHS.v(axis2);
}


// Class CCOL_ST_Tris 

int CCOL_ST_Tris::Tri;

CVect3 *CCOL_ST_Tris::pVX = NULL;

CVect3 *CCOL_ST_Tris::pVN = NULL;

int CCOL_ST_Tris::iNumTris;

CVect3 CCOL_ST_Tris::Pos;

CCOL_ST_Tris::CCOL_ST_Tris()
        {
}


CCOL_ST_Tris::~CCOL_ST_Tris()
{
}



int CCOL_ST_Tris::iTestCollision (CVect3* _pVXs, CVect3* _pVNs, int _iNumTris, CGraphBV* _BV, CVect3& _Pos)
{
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
}

int CCOL_ST_Tris::iTestCollisionSphere (float _fRad, CVect3& _Center)
{
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
}

int CCOL_ST_Tris::iTestCollisionBox (CVect3& _Maxs, CVect3& _Mins)
{
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
}

int CCOL_ST_Tris::iTestCollisionRay (CRay& _ay)
{
  	return(false);
}

int CCOL_ST_Tris::iTestTriangleSphere (CVect3* _pVXs, float _fRad, CVect3& _Center)
{
  	CTriangle	Tri;
	Tri.Init(_pVXs);
	float fSqDist = MATH_Utils::fTriPointSqDistance(Tri,_Center);
	return ( fSqDist < _SQ_(_fRad) );
}

int CCOL_ST_Tris::iTestTriangleBox (CVect3* _pVXs, CVect3& _Maxs, CVect3& _Mins)
{
  	
	// ---------------------------------------------------------
	//	Based on AABB-triangle overlap test code by Tomas M�ller
	// ---------------------------------------------------------
	

	// First we test if the triangle bounding box intersects with the source bounding box
	// This is performed using the separating axis test, which is done separatelly with
	// every one of the 3 bounding box axis
	CVect3  TMins,TMaxs;	

	// Test X axis:
	MATH_Utils::GetMaxMins( _pVXs[0].x,_pVXs[1].x,_pVXs[2].x,TMaxs.v(0),TMins.v(0) );
	if ( (TMins.x > _Maxs.x) || (TMaxs.x < _Mins.x) ) return(0);
	
	// Test Y axis:
	MATH_Utils::GetMaxMins( _pVXs[0].y,_pVXs[1].y,_pVXs[2].y,TMaxs.v(1),TMins.v(1) );
	if ( (TMins.y > _Maxs.y) || (TMaxs.y < _Mins.y) ) return(0);

	// Test Z axis:
	MATH_Utils::GetMaxMins( _pVXs[0].z,_pVXs[1].z,_pVXs[2].z,TMaxs.v(2),TMins.v(2) );
	if ( (TMins.z > _Maxs.z) || (TMaxs.z < _Mins.z) ) return(0);




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
	
	//-----------------------------------------------------------------------------
	// test e0 edge
	//-----------------------------------------------------------------------------
	Edge.Assign(_pVXs[0]);	Edge.Sub(_pVXs[1]);
	AbsE.V3( fabs(Edge.x),fabs(Edge.y),fabs(Edge.z) );

	GetMinMaxRad2(_Y_,_Z_,v0,v2, 1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);
	
	GetMinMaxRad2(_X_,_Z_,v0,v2,-1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	GetMinMaxRad2(_X_,_Y_,v1,v2, 1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	//-----------------------------------------------------------------------------
	// test e1 edge
	//-----------------------------------------------------------------------------
	Edge.Assign(_pVXs[1]);	Edge.Sub   (_pVXs[2]);
	AbsE.V3( fabs(Edge.x),fabs(Edge.y),fabs(Edge.z) );

	GetMinMaxRad2(_Y_,_Z_,v0,v2, 1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);
	
	GetMinMaxRad2(_X_,_Z_,v0,v2,-1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	GetMinMaxRad2(_X_,_Y_,v0,v1, 1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	//-----------------------------------------------------------------------------
	// test e2 edge
	//-----------------------------------------------------------------------------
	Edge.Assign(_pVXs[2]);	Edge.Sub   (_pVXs[0]);
	AbsE.V3( fabs(Edge.x),fabs(Edge.y),fabs(Edge.z) );

	GetMinMaxRad2(_Y_,_Z_,v0,v1,-1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	GetMinMaxRad2(_X_,_Z_,v0,v1,-1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	GetMinMaxRad2(_X_,_Y_,v1,v2, 1.0f,Edge,AbsE,BoxHalfSize,min,max,rad);
	if ((min>rad) || (max <-rad)) return(0);

	return(1);
}

int CCOL_ST_Tris::iTestTriangleRay (CVect3* _pVXs, CRay& _ay)
{
  	CTriangle Tri;
	Tri.Init(_pVXs);

	return (MATH_Utils::iTestRayTriIntersection(_ay,Tri));
}

// Additional Declarations
    
