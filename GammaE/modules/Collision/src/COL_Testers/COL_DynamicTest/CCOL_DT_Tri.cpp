// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// %X% %Q% %Z% %W%

// CCOL_DT_Tri
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Tri.h"

void ProjectTriangle (const CGVect3& _oD, const CGTriangle& _oTri, float& _fMin, float& _fMax)
{
    float fU,fV,fW;

    fU = _oD.fDotProd( _oTri.VXs[0] );
    fV = _oD.fDotProd( _oTri.VXs[1] );
    fW = _oD.fDotProd( _oTri.VXs[2] );

    Math::GetMaxMins(fU,fV,fW,_fMax,_fMin);
}

void ProjectBox (const CGVect3& _oD, const CGGraphBVAABB& _oBox, float& _fMin, float& _fMax)
{
    CGVect3 oBExt = _oBox.GetExtents();
    float fDdC = _oD.fDotProd( _oBox.oGetCenter() );
    float fR = oBExt.x * Math::fAbs( _oD.fDotProd( _oBox.GetAxis(0) ) ) +
               oBExt.y* Math::fAbs( _oD.fDotProd( _oBox.GetAxis(1) ) ) +
               oBExt.z* Math::fAbs( _oD.fDotProd( _oBox.GetAxis(2) ) );

    _fMin = fDdC - fR;
    _fMax = fDdC + fR;
}

bool bNoIntersect (float _fTMax, float _fSpeed, float _fMin0, float _fMax0, float _fMin1, float _fMax1, float& _fTFirst, float& _fTLast)
{
    float fInvSpeed, fT;

    if ( _fMax1 < _fMin0 )  // C1 initially on left of C0
    {
        if ( _fSpeed <= 0.0f )
        {
            // intervals moving apart
            return(true);
        }

        fInvSpeed = 1.0f / _fSpeed;

        fT = (_fMin0 - _fMax1) * fInvSpeed;
        if ( fT > _fTFirst ) _fTFirst = fT;
        if ( _fTFirst > _fTMax ) return(true);

        fT = (_fMax0 - _fMin1) * fInvSpeed;
        if ( fT < _fTLast ) _fTLast = fT;
        if ( _fTFirst > _fTLast ) return(true);
    }
    else if ( _fMax0 < _fMin1 ) // C1 initially on right of C0
    {
        if ( _fSpeed >= 0.0f )
        {
            // intervals moving apart
            return(true);
        }

        fInvSpeed = 1.0f / _fSpeed;

        fT = (_fMax0 - _fMin1) * fInvSpeed;
        if ( fT > _fTFirst ) _fTFirst = fT;
        if ( _fTFirst > _fTMax ) return(true);

        fT = (_fMin0 - _fMax1) * fInvSpeed;
        if ( fT < _fTLast ) _fTLast = fT;
        if ( _fTFirst > _fTLast ) return(true);
    }
    else // C0 and C1 overlap
    {
        if ( _fSpeed > 0.0f )
        {
            fT = (_fMax0 - _fMin1) / _fSpeed;
            if ( fT < _fTLast ) _fTLast = fT;
            if ( _fTFirst > _fTLast ) return(true);
        }
        else if ( _fSpeed < 0.0f )
        {
            fT = (_fMin0 - _fMax1) / _fSpeed;
            if ( fT < _fTLast ) _fTLast = fT;
            if ( _fTFirst > _fTLast ) return(true);
        }
    }

    return(false);
}

// Class CCOL_DT_Tri

CCOL_DT_Tri::CCOL_DT_Tri()
{
}

CCOL_DT_Tri::~CCOL_DT_Tri()
{
}
class Foo
{
public:
    const float& GetMemberConstReference() const
    {
        return member;
    }

    float member;
};

void Method(const Foo& _a)
{
    const float& constReference = _a.GetMemberConstReference();
}

float CCOL_DT_Tri::fTestSphere (const CGGraphBVSphere& _oSphere, const CGTriangle& _oTri)
{
    float fDist = Math::fTriPointSqDistance( _oTri, _oSphere.oGetCenter() );
    const float fRadius = _oSphere.oGetSphere().fGetRadius();

    if ( fDist < _SQ_(fRadius) )
        return(0.0f);

    CGGraphBVAABB Box;
    Box.Copy(_oSphere);

    return ( fTestBox(Box,_oTri) );
}

float CCOL_DT_Tri::fTestBox (const CGGraphBVAABB& _oBox, const CGTriangle& _oTri)
{
    // David Eberly code
    // Magic Software, Inc.
    // http://www.magic-software.com
    // Copyright (c) 2000, 2001.  All Rights Reserved

    // Get object velocities
    CGVect3 TriVel,BoxVel;
    TriVel.Assign(CCOL_ColState::DstFPos);
    TriVel.Sub   (CCOL_ColState::DstIPos);
    BoxVel.Assign(CCOL_ColState::SrcFPos);
    BoxVel.Sub   (CCOL_ColState::SrcIPos);

    float fMin0, fMax0, fMin1, fMax1;
    float fSpeed;
    float fTFirst,fTLast,fDdC;
    float fTMax = 1.0f;
    CGVect3 W,D, akE[3];
    CGVect3 BExt;

    // process as if triangle is stationary, box is moving
    W.Assign(BoxVel);
    W.Sub(TriVel);
    fTFirst = 0.0f;
    fTLast = 1e10f;

    // ---------------------------------
    // test direction of triangle normal
    akE[0].Assign(_oTri.e1);
    akE[1].Assign(_oTri.e2);

    D.CrossProd(akE[0],akE[1]); // Triangle normal ???

    fMin0 = D.fDotProd(_oTri.VXs[0]);
    fMax0 = fMin0;

    ProjectBox(D,_oBox,fMin1,fMax1);
    fSpeed = D.fDotProd(W);

    if ( bNoIntersect(fTMax,fSpeed,fMin0,fMax0,fMin1,fMax1,fTFirst,fTLast) )
        return(-1.0f);

    // ---------------------------------
    // test direction of box faces
    BExt = _oBox.GetExtents();
    for ( int i = 0; i < 3; i++ )
    {
        D.Assign( _oBox.GetAxis(i) );
        ProjectTriangle(D, _oTri,fMin0,fMax0);

        fDdC = D.fDotProd( _oBox.oGetCenter() );
        fMin1 = fDdC - BExt.v(i);
        fMax1 = fDdC + BExt.v(i);
        fSpeed = D.fDotProd(W);

        if ( bNoIntersect(fTMax,fSpeed,fMin0,fMax0,fMin1,fMax1,fTFirst,fTLast) )
        {
            return(-1.0f);
        }
    }

    // ---------------------------------
    // test direction of triangle-box edge cross products
    // return fTFirst;

    akE[2].Assign(akE[1]);
    akE[2].Sub   (akE[0]);

    for ( int i0 = 0; i0 < 3; i0++ )
    {
        for ( int i1 = 0; i1 < 3; i1++ )
        {
            D.CrossProd( akE[i0],_oBox.GetAxis(i1) );

            ProjectTriangle(D,_oTri,fMin0,fMax0);
            ProjectBox     (D,_oBox,fMin1,fMax1);

            fSpeed = D.fDotProd(W);

            if ( bNoIntersect(fTMax,fSpeed,fMin0,fMax0,fMin1,fMax1,fTFirst,fTLast) )
            {
                return(-1.0f);
            }
        }
    }

    if ( fTFirst > 1.0f )
        return (-1.0f);
    else
    {
        return (fTFirst);
    }
}

float CCOL_DT_Tri::fTestPoint (const CGVect3& _oPoint, const CGTriangle& _oTri)
{
    if ( CCOL_ColState::DSSp.fSqModule() == 0.0f ) return(-1.0f);

    CGVect3 oPI;             // Initial Point
    CGRay oRay;              // Ray segment
    CGVect3 oPrj;            // Projected point
    CGVect3 oDir;
    CGTriangle oATri;        // AuxTri

    // Point initial position in Triangle Ref system
    oPI.Assign(_oPoint);
    oPI.Sub(_oTri.VXs[0]);

    // Init ray
    oDir.Assign(CCOL_ColState::DSSp);
    oDir.Scale(-CCOL_ColState::fDeltaT);    // We are now in destination (tri) Ref system

    oRay.InitFromFields(oPI,oDir);

    // Triangle in triangle origin coordinate system
    // <OPTIMIZABLE>
    oATri = _oTri;
    oATri.VXs[1].Sub( oATri.VXs[0] );
    oATri.VXs[2].Sub( oATri.VXs[0] );
    oATri.VXs[0].Set(0.0f,0.0f,0.0f);

    if ( Math::iTestSegTriIntersection(oRay,oATri,oPrj) )
    {
        // return (MATH_Utils::fGetT () );

        // Projected point relative to segment initial position
        oPrj.Sub(oPI);
        float fFact = oPrj.fSqModule() / oDir.fSqModule();

        if ( fFact > 1.0f )
            return (-1.0f);
        else
            return (fFact* CCOL_ColState::fDeltaT);
    }
    else
    {
        return (-1.0f);
    }
}
