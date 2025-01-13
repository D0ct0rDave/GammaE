//## begin module%3C291C7D0387.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C291C7D0387.cm

//## begin module%3C291C7D0387.cp preserve=no
//## end module%3C291C7D0387.cp

//## Module: CCOL_DT_Tri%3C291C7D0387; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Tri.cpp

//## begin module%3C291C7D0387.additionalIncludes preserve=no
//## end module%3C291C7D0387.additionalIncludes

//## begin module%3C291C7D0387.includes preserve=yes
//## end module%3C291C7D0387.includes

// CCOL_DT_Tri
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Tri.h"
//## begin module%3C291C7D0387.additionalDeclarations preserve=yes


void ProjectTriangle (CVect3& _roD, CTriangle& _roTri, float& _rfMin, float& _rfMax)
{
	float fU,fV,fW;

	fU = _roD.DotProd( _roTri.VXs[0] );
	fV = _roD.DotProd( _roTri.VXs[1] );
	fW = _roD.DotProd( _roTri.VXs[2] );
	
	MATH_Utils::GetMaxMins(fU,fV,fW,_rfMax,_rfMin);
}


void ProjectBox (CVect3& _roD, CGraphBV_Box& _roBox, float& _rfMin, float& _rfMax)
{
	CVect3  oBExt= _roBox.GetExtents();
	float	fDdC = _roD.DotProd( _roBox.GetCenter() );
    float	fR   = oBExt.X()*MATH_Common::fAbs(_roD.DotProd( _roBox.GetAxis(0) )) +
				   oBExt.Y()*MATH_Common::fAbs(_roD.DotProd( _roBox.GetAxis(1) )) +
				   oBExt.Z()*MATH_Common::fAbs(_roD.DotProd( _roBox.GetAxis(2) ));

    _rfMin = fDdC - fR;
    _rfMax = fDdC + fR;
}

bool bNoIntersect (float _fTMax, float _fSpeed, float _fMin0, float _fMax0, float _fMin1, float _fMax1, float& _rfTFirst, float& _rfTLast)
{	
    float	fInvSpeed, fT;

    if ( _fMax1 < _fMin0 )  // C1 initially on left of C0
    {
        if ( _fSpeed <= 0.0f )
        {
            // intervals moving apart
            return true;
        }

        fInvSpeed = 1.0f/_fSpeed;

        fT = (_fMin0 - _fMax1)*fInvSpeed;
        if ( fT > _rfTFirst )		_rfTFirst = fT;
        if ( _rfTFirst > _fTMax )	return true;

        fT = (_fMax0 - _fMin1)*fInvSpeed;
        if ( fT < _rfTLast )		_rfTLast = fT;
        if ( _rfTFirst > _rfTLast )	return true;
    }
else if (_fMax0 < _fMin1 )  // C1 initially on right of C0
    {
        if ( _fSpeed >= 0.0f )
        {
            // intervals moving apart
            return true;
        }

        fInvSpeed = 1.0f/_fSpeed;

        fT = (_fMax0 - _fMin1)*fInvSpeed;
        if ( fT > _rfTFirst )		_rfTFirst = fT;
        if ( _rfTFirst > _fTMax )	return true;

        fT = (_fMin0 - _fMax1)*fInvSpeed;
        if ( fT < _rfTLast )		_rfTLast = fT;
        if ( _rfTFirst > _rfTLast )	return true;
    }
else{	// C0 and C1 overlap
        if ( _fSpeed > 0.0f )
        {
            fT = (_fMax0 - _fMin1)/_fSpeed;
            if ( fT < _rfTLast )		_rfTLast = fT;
            if ( _rfTFirst > _rfTLast )	return true;
        }
        else if ( _fSpeed < 0.0f )
        {
            fT = (_fMin0 - _fMax1)/_fSpeed;
            if ( fT < _rfTLast )		_rfTLast = fT;
            if ( _rfTFirst > _rfTLast )	return true;
        }
    }

    return false;
}

//## end module%3C291C7D0387.additionalDeclarations


// Class CCOL_DT_Tri 

CCOL_DT_Tri::CCOL_DT_Tri()
  //## begin CCOL_DT_Tri::CCOL_DT_Tri%.hasinit preserve=no
  //## end CCOL_DT_Tri::CCOL_DT_Tri%.hasinit
  //## begin CCOL_DT_Tri::CCOL_DT_Tri%.initialization preserve=yes
  //## end CCOL_DT_Tri::CCOL_DT_Tri%.initialization
{
  //## begin CCOL_DT_Tri::CCOL_DT_Tri%.body preserve=yes
  //## end CCOL_DT_Tri::CCOL_DT_Tri%.body
}


CCOL_DT_Tri::~CCOL_DT_Tri()
{
  //## begin CCOL_DT_Tri::~CCOL_DT_Tri%.body preserve=yes
  //## end CCOL_DT_Tri::~CCOL_DT_Tri%.body
}



//## Other Operations (implementation)
float CCOL_DT_Tri::fTestSphere (CGraphBV_Sphere& _Sphere, CTriangle& _Tri)
{
  //## begin CCOL_DT_Tri::fTestSphere%1009321154.body preserve=yes
	float fDist = MATH_Utils::fTriPointSqDistance(_Tri,_Sphere.GetCenter());
	
	if (fDist < _SQ_(_Sphere.pGetSphere()->Radius) )
		return(0.0f);		

	CGraphBV_Box Box;
	Box.Copy((CGraphBV*)&_Sphere);

	return (fTestBox(Box,_Tri));
  //## end CCOL_DT_Tri::fTestSphere%1009321154.body
}

float CCOL_DT_Tri::fTestBox (CGraphBV_Box& _Box, CTriangle& _Tri)
{
  //## begin CCOL_DT_Tri::fTestBox%1009321155.body preserve=yes

	// David Eberly code
	// Magic Software, Inc.
	// http://www.magic-software.com
	// Copyright (c) 2000, 2001.  All Rights Reserved
  
	// Get object velocities
	CVect3 TriVel,BoxVel;
	TriVel.Assign(CCOL_ColState::DstFPos);
	TriVel.Sub   (CCOL_ColState::DstIPos);
	BoxVel.Assign(CCOL_ColState::SrcFPos);
	BoxVel.Sub   (CCOL_ColState::SrcIPos);
	
	float	fMin0, fMax0, fMin1, fMax1;
	float   fSpeed;
	float	fTFirst,fTLast,fDdC;
	float	fTMax = 1.0f;
    CVect3	W,D, akE[3];
	CVect3	BExt;

    // process as if triangle is stationary, box is moving    
	W.Assign(BoxVel);	W.Sub(TriVel);
    fTFirst = 0.0f;
    fTLast  = 1e10f;
	
	// ---------------------------------
    // test direction of triangle normal
	akE[0].Assign(_Tri.e1);
	akE[1].Assign(_Tri.e2);
    
	D.CrossProd(akE[0],akE[1]);	// Triangle normal ???	

    fMin0 = D.DotProd(_Tri.VXs[0]);
    fMax0 = fMin0;

    ProjectBox(D,_Box,fMin1,fMax1);
    fSpeed = D.DotProd(W);
	
    if ( bNoIntersect(fTMax,fSpeed,fMin0,fMax0,fMin1,fMax1,fTFirst,fTLast) )
        return -1.0f;

	// ---------------------------------
    // test direction of box faces
	BExt = _Box.GetExtents();
    for (int i = 0; i < 3; i++)
    {
        D.Assign( _Box.GetAxis(i) );
        ProjectTriangle(D,_Tri,fMin0,fMax0);

        fDdC   = D.DotProd( _Box.GetCenter() );
        fMin1  = fDdC - BExt.v[i];
        fMax1  = fDdC + BExt.v[i];
        fSpeed = D.DotProd(W);

        if ( bNoIntersect(fTMax,fSpeed,fMin0,fMax0,fMin1,fMax1,fTFirst,fTLast) )
        {
            return -1.0f;
        }
    }

	// ---------------------------------
    // test direction of triangle-box edge cross products
	// return fTFirst;

    akE[2].Assign(akE[1]);
	akE[2].Sub   (akE[0]);

    for (int i0 = 0; i0 < 3; i0++)
    {
        for (int i1 = 0; i1 < 3; i1++)
        {
            D.CrossProd(akE[i0],_Box.GetAxis(i1));

            ProjectTriangle(D,_Tri,fMin0,fMax0);
            ProjectBox     (D,_Box,fMin1,fMax1);

            fSpeed = D.DotProd(W);

            if ( bNoIntersect(fTMax,fSpeed,fMin0,fMax0,fMin1,fMax1,fTFirst,fTLast) )
            {
                return -1.0f;
            }
        }
    }

	if (fTFirst > 1.0f)
		return (-1.0f);
	else
	{
		return (fTFirst);
	}
  //## end CCOL_DT_Tri::fTestBox%1009321155.body
}

float CCOL_DT_Tri::fTestPoint (CVect3& _roPoint, CTriangle& _Tri)
{
  //## begin CCOL_DT_Tri::fTestPoint%1011748897.body preserve=yes
	if (CCOL_ColState::DSSp.SqModule() == 0.0f) return(-1.0f);

	CVect3			oPI;	// Initial Point	
	CRay			oRay;	// Ray segment
	CVect3			oPrj;	// Projected point
	CVect3			oDir;
	CTriangle		oATri;	// AuxTri

	// Point initial position in Triangle reference system
	oPI.Assign(_roPoint);
	oPI.Sub(_Tri.VXs[0]);

	// Init ray
	oDir.Assign(CCOL_ColState::DSSp);
	oDir.Scale(-CCOL_ColState::fDeltaT);	// We are now in destination (tri) reference system

	oRay.InitFromFields(oPI,oDir);
	
	// Triangle in triangle origin coordinate system
	//<OPTIMIZABLE>
	oATri = _Tri;
	oATri.VXs[1].Sub( oATri.VXs[0] );
	oATri.VXs[2].Sub( oATri.VXs[0] );
	oATri.VXs[0].V3 (0.0f,0.0f,0.0f);

	if (MATH_Utils::iTestSegTriIntersection(oRay,oATri,oPrj))
	{
		// return (MATH_Utils::fGetT () );
		
		// Projected point relative to segment initial position
		oPrj.Sub(oPI);
		float fFact = oPrj.SqModule() / oDir.SqModule();
		
		if (fFact > 1.0f) 
			return (-1.0f);
		else
			return (fFact*CCOL_ColState::fDeltaT);
	}
	else
	{
		return (-1.0f);
	}
  //## end CCOL_DT_Tri::fTestPoint%1011748897.body
}

// Additional Declarations
  //## begin CCOL_DT_Tri%3C291C7D0387.declarations preserve=yes
  //## end CCOL_DT_Tri%3C291C7D0387.declarations

//## begin module%3C291C7D0387.epilog preserve=yes
//## end module%3C291C7D0387.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
