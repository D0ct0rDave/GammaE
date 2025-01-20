//## begin module%3C1FBD52007E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1FBD52007E.cm

//## begin module%3C1FBD52007E.cp preserve=no
//## end module%3C1FBD52007E.cp

//## Module: CCOL_DT_Box%3C1FBD52007E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Box.cpp

//## begin module%3C1FBD52007E.additionalIncludes preserve=no
//## end module%3C1FBD52007E.additionalIncludes

//## begin module%3C1FBD52007E.includes preserve=yes
//## end module%3C1FBD52007E.includes

// CCOL_DT_Box
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Box.h"
//## begin module%3C1FBD52007E.additionalDeclarations preserve=yes

//----------------------------------------------------------------------------
static bool bClip (float _fDenom, float _fNumer, float& _rfT0, float& _rfT1)
{
    // Return value is 'true' if line segment intersects the current test
    // plane.  Otherwise 'false' is returned in which case the line segment
    // is entirely clipped.

		if ( _fDenom > 0.0f )
		{
			if ( _fNumer > _fDenom*_rfT1 )
				return(false);

			if ( _fNumer > _fDenom*_rfT0 )
				_rfT0 = _fNumer/_fDenom;

			return(true);
		}
   else if ( _fDenom < 0.0f )
		{
			if ( _fNumer > _fDenom*_rfT0 )
				return (false);

			if ( _fNumer > _fDenom*_rfT1 )
				_rfT1 = _fNumer/_fDenom;

			return(true);
		}
   else {
		  return (_fNumer <= 0.0f);
		}
}
//----------------------------------------------------------------------------
bool bFindIntersection (CVect3& _roOrigin,CVect3& _roDir,CVect3& _roExt,float &_rfT0,float &_rfT1)
{
    float fSaveT0 = _rfT0, fSaveT1 = _rfT1;

    bool bNotEntirelyClipped =
        bClip(+_roDir.X(),-_roOrigin.X() - _roExt.X(),_rfT0,_rfT1) &&
        bClip(-_roDir.X(),+_roOrigin.X() - _roExt.X(),_rfT0,_rfT1) &&
        bClip(+_roDir.Y(),-_roOrigin.Y() - _roExt.Y(),_rfT0,_rfT1) &&
        bClip(-_roDir.Y(),+_roOrigin.Y() - _roExt.Y(),_rfT0,_rfT1) &&
        bClip(+_roDir.Z(),-_roOrigin.Z() - _roExt.Z(),_rfT0,_rfT1) &&
        bClip(-_roDir.Z(),+_roOrigin.Z() - _roExt.Z(),_rfT0,_rfT1);

    return ( bNotEntirelyClipped && 
			((_rfT0 != fSaveT0) || (_rfT1 != fSaveT1)) ); 
}
//----------------------------------------------------------------------------

//## end module%3C1FBD52007E.additionalDeclarations


// Class CCOL_DT_Box 

CCOL_DT_Box::CCOL_DT_Box()
  //## begin CCOL_DT_Box::CCOL_DT_Box%.hasinit preserve=no
  //## end CCOL_DT_Box::CCOL_DT_Box%.hasinit
  //## begin CCOL_DT_Box::CCOL_DT_Box%.initialization preserve=yes
  //## end CCOL_DT_Box::CCOL_DT_Box%.initialization
{
  //## begin CCOL_DT_Box::CCOL_DT_Box%.body preserve=yes
  //## end CCOL_DT_Box::CCOL_DT_Box%.body
}


CCOL_DT_Box::~CCOL_DT_Box()
{
  //## begin CCOL_DT_Box::~CCOL_DT_Box%.body preserve=yes
  //## end CCOL_DT_Box::~CCOL_DT_Box%.body
}



//## Other Operations (implementation)
float CCOL_DT_Box::fTestSphere (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDCenter, float _fDRadius)
{
  //## begin CCOL_DT_Box::fTestSphere%1008711893.body preserve=yes
	CVect3 DMaxs,DMins;
	
	// Setup destination bounding box
	DMaxs.Assign( _roDCenter );
	DMaxs.Add   (_fDRadius,_fDRadius,_fDRadius);

	DMins.Assign( _roDCenter );
	DMins.Sub   (_fDRadius,_fDRadius,_fDRadius);

	return( fTestBox(_roSMaxs,_roSMins,DMaxs,DMins) );
  //## end CCOL_DT_Box::fTestSphere%1008711893.body
}

float CCOL_DT_Box::fTestBox (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDMaxs, CVect3& _roDMins)
{
  //## begin CCOL_DT_Box::fTestBox%1008711894.body preserve=yes
	// Check if they were colliding in the previous frame
	if (CCOL_ST_Box::iTestBox(_roSMaxs,_roSMins,_roDMaxs,_roDMins)) return(0.0f);

  	CVect3 vA;
	CVect3 vB;	
	CVect3 vBA;
	CVect3 u0;
	CVect3 u1;

	float fAux,fU0,fU1;

	// Velocities
	vA.Assign(CCOL_ColState::SrcFPos);	// Traversed space in the current frame time
	vA.Sub   (CCOL_ColState::SrcIPos);
	
	vB.Assign(CCOL_ColState::DstFPos);	// Traversed space in the current delta time
	vB.Sub   (CCOL_ColState::DstIPos);
	
	// Get relative speed of B from A
	vBA.Assign(vB);
	vBA.Sub   (vA);


	// The objects could only collide if their velocities are different
	// vBA != (0,0,0);
	// if (vBA = (0,0,0)) the objects could only collide if at time 0 are
	// colliding. At this time the object hadn't collided due to the first
	// test.	
	if ((vBA.X() == 0) && (vBA.Y() == 0) && (vBA.Z() == 0)) return(-1.0f);
	

	// First time of overlap along each axis
	u0.V3(0.0f,0.0f,0.0f);
	
	// Last time of overlap along each axis
	u1.V3(1.0f,1.0f,1.0f);
	
	
	// Find the possible first and last times of overlap along each axis
	int i;
	for (i=0;i<3;i++)
	{
		//     max   min
  		//  |-a-|     |-b-|		
		if (_roSMaxs.v[i] < _roDMins.v[i])	// A 
		{
			if (vBA.v[i]<0.0f)
			{
				//     max   min
  				//  |-a-|     |-b-|
				//             <--
				u0.v[i] = (_roSMaxs.v[i] - _roDMins.v[i]) / vBA.v[i];
				u1.v[i] = (_roSMins.v[i] - _roDMaxs.v[i]) / vBA.v[i];
			}
			else
			{
				// B is moving away from A: 'i' is a separating axis
				//     max   min
  				//  |-a-|     |-b-|
				//              -->
				return(-1.0f);
			}
		}
		//     max   min
  		//  |-b-|     |-a-|
   else if (_roDMaxs.v[i] < _roSMins.v[i])
		{
			if (vBA.v[i]>0.0f)
			{
				//     max   min
  				//  |-b-|     |-a-|
				//   -->
				u0.v[i] = (_roSMins.v[i] - _roDMaxs.v[i]) / vBA.v[i];
				u1.v[i] = (_roSMaxs.v[i] - _roDMins.v[i]) / vBA.v[i];
			}
			else
			{
				// B is moving away from A: 'i' is a separating axis
				//     max   min
  				//  |-b-|     |-a-|
				//  <--
				return(-1.0f);
			}
		}
	}

	MATH_Utils::GetMaxMins(u0.X(),u0.Y(),u0.Z(),fU0,fAux);
	// MATH_Utils::GetMaxMins(u0.X(),u0.Y(),u0.Z(),fAux,fU1);
	
	if ((fU0<1.0f) /*&& (fU0 < fU1)*/)
	{
		return(fU0);
	}
	else
		return(-1.0f);
	/*
	// Miguel Gomez algorithm

	int i;
	for (i=0;i<3;i++)
	{
		// u0 times: Compute firsts times of colision
		if ((_SMaxs.v[i] < _DMins.v[i]) && (vBA.v[i]<0.0f))
		{
			u0.v[i] = (_SMaxs.v[i] - _DMins.v[i]) / vBA.v[i];				
		}

   else if ((_DMaxs.v[i] < _SMins.v[i]) && (vBA.v[i]>0.0f))
		{
			u0.v[i] = (_SMins.v[i] - _DMaxs.v[i]) / vBA.v[i];
		}
		
		// u1 times: Compute lasts times of colision
		if ((_DMaxs.v[i] > _SMins.v[i]) && (vBA.v[i]<0.0f))
		{
			u1.v[i] = (_SMins.v[i] - _DMaxs.v[i]) / vBA.v[i];	
		}
   else if ((_SMaxs.v[i] > _DMins.v[i]) && (vBA.v[i]>0.0f))
		{
			u1.v[i] = (_SMaxs.v[i] - _DMins.v[i]) / vBA.v[i];
		}
	}

	MATH_Utils::GetMaxMins(u0.X(),u0.Y(),u0.Z(),fU0,fAux);	
	MATH_Utils::GetMaxMins(u1.X(),u1.Y(),u1.Z(),fAux,fU1);

	// if the first time of overlap happens after last time of overlap
	// the object have not collided
	
	if (fU0 > fU1) return(-1.0f);
	if (fU0==0.0f) return(-1.0f);
	return(fU0);
	*/
  //## end CCOL_DT_Box::fTestBox%1008711894.body
}

float CCOL_DT_Box::fTestPoint (CVect3& _roSMaxs, CVect3& _roSMins, CVect3& _roDPoint)
{
  //## begin CCOL_DT_Box::fTestPoint%1008711895.body preserve=yes
	if (CCOL_ST_Box::iTestPoint(_roSMaxs,_roSMins,_roDPoint)) 
		return(0.0f);

	// Based on Magic Software, Inc.
	// http://www.magic-software.com
	// Copyright (c) 2000, 2001.  All Rights Reserved

    // convert segment to box coordinates and test:
    // Vector3 kDiff = rkSegment.Origin() - rkBox.Center(); == oPI		
    // Vector3 kOrigin(kDiff.Dot(rkBox.Axis(0)),kDiff.Dot(rkBox.Axis(1)),kDiff.Dot(rkBox.Axis(2)));
	// rkBox.Axis(0) = (1,0,0) rkBox.Axis(1) = (0,1,0) ..., then rkOrigin = kDiff = oPI
    
	// Vector3 kDirection(rkSegment.Direction().Dot(rkBox.Axis(0)),
    // rkSegment.Direction().Dot(rkBox.Axis(1)),rkSegment.Direction().Dot(rkBox.Axis(2)));
	// Same for segment direction

	// El segmento tiene como vector director respecto al sistema de coordenadas de la caja
	// el mismo vector velocidad de Dst respecto a Src, es decir, CCOL_ColState::DSSp

	CVect3	oPI;	// Initial Point
	CVect3	oBoxC;	// Box center
	CVect3	oBExt;	// Box extents
	
	// Compute box center
	oBoxC.Interpolate(_roSMaxs,_roSMins,0.5f);

	// Point initial position in Box reference system
	oPI.Assign(_roDPoint);	oPI.Sub(oBoxC);
	
	// Compute box extents
	oBExt.Assign(_roSMaxs);
	oBExt.Sub   (_roSMins);
	oBExt.Scale (0.5f);

    float fT0 = 0.0f, fT1 = 1.0f;
		
	if ( bFindIntersection(oPI,CCOL_ColState::DSSp,oBExt,fT0,fT1) )
		return(fT0);
	else
		return(-1.0f);
  //## end CCOL_DT_Box::fTestPoint%1008711895.body
}

// Additional Declarations
  //## begin CCOL_DT_Box%3C1FBD52007E.declarations preserve=yes
  //## end CCOL_DT_Box%3C1FBD52007E.declarations

//## begin module%3C1FBD52007E.epilog preserve=yes
//## end module%3C1FBD52007E.epilog
