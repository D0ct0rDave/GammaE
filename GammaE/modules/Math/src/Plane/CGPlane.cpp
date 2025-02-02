// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "CGPlane.h"
#include "Other/GMathCommon.h"
// ----------------------------------------------------------------------------
void CGPlane::GenerateFromVectors (CGVect3 VDir1, CGVect3 VDir2, CGVect3 VOrigin)
{
    // Compute plane normal
    m_oPlaneNormal.CrossProd(VDir1,VDir2);
    m_oPlaneNormal.Normalize();

    m_oPlaneOrigin = VOrigin;

    m_fPlaneD = -m_oPlaneNormal.fDotProd(m_oPlaneOrigin);
}

void CGPlane::GenerateFromPoints (const CGVect3& a, const CGVect3& b, const CGVect3& c)
{
// -----------------------------------------------------------------------------
// ___________ n ____   n = ab x cb
// /     a      |    /   b belongs to the plane-> we take it as
// /	 / \     |   /	  the plane origin
// /     b____\c     /
// /_________________/
//
// Plane equation : Ax + By + Cz + D = 0
// (A,B,C) = (nx,ny,nz) = plane normal components
// x y z are components of a point belonging to the plane
// point b (bx,by,bz) belongs also to the plane
// nx*bx + ny*by + nz*bz + D = 0
// nx*bx + ny*by + nz*bz = dot prod between b and n
// dotprod(b,n) + D = 0
// Then dotprod(b,n) = -D
// Then D = - dotprod(b,n)
// D = Distance from plane to the origin (0,0,0)
// ----------------------------------------------------------------------------

    m_oPlaneNormal.Normal(a,b,c);
    m_oPlaneNormal.Normalize();

    m_oPlaneOrigin = a;

    m_fPlaneD = -m_oPlaneNormal.fDotProd(m_oPlaneOrigin);
}

void CGPlane::GeneratePlaneFromFields (const CGVect3& VOrigin, const CGVect3& VNormal)
{
    m_oPlaneNormal = VNormal;
    m_oPlaneNormal.Normalize();

    m_oPlaneOrigin = VOrigin;

    m_fPlaneD = -m_oPlaneNormal.fDotProd(m_oPlaneOrigin);
}

float CGPlane::fGetDistanceToPoint (const CGVect3& Point) const
{
    /*
       CGVect3 oS;
       oS.Assign(Point);
       oS.Sub(m_oPlaneOrigin);
       return ( m_oPlaneNormal.DotProd(oS));
     */
    return (m_oPlaneNormal.fDotProd(Point) + m_fPlaneD);
}

bool CGPlane::bCoplanar (const CGPlane& Plane) const
{
// -----------------------------------------------------------------------------
// 2 planos son coplanarios, si los vectores normales son identicos (o angulo entre ellos 0)
// y el vector formado entre los puntos origen de ambos planos es perpendicular
// a la normal de los planos
// N1
// _|___
// N2 / |  /  Plano1
// |_xO1/
// _|/__
// /  x  /
// /__O2_/  Plano2
//
// -----------------------------------------------------------------------------
// What about the W field ???
// -----------------------------------------------------------------------------

    // angulo 0: dot product = 1 = coseno del angulo que forman los vectores
    // if (m_oPlaneNormal.DotProd(Plane.oGetNormal()) != 1.0f) return(false);
    if ( Math::fAbs( m_oPlaneNormal.fDotProd( Plane.oGetNormal() ) ) != 1.0f ) return(false);

    // angulo que forma la normal del plano con el vector diferencia
    // ha de ser de 90º: dot product = 0 = coseno del angulo de los 2 vectores
    CGVect3 VDiff = m_oPlaneOrigin;
    VDiff.Sub(m_oPlaneOrigin);

    return(m_oPlaneNormal.fDotProd(VDiff) == 0.0f);
}

void CGPlane::Transform (const CGMatrix4x4& _Transf)
{
    _Transf.TransformPoint (&m_oPlaneOrigin);
    _Transf.TransformVector(&m_oPlaneNormal);

    m_fPlaneD = -m_oPlaneNormal.fDotProd(m_oPlaneOrigin);
}

CGVect3 CGPlane::oProjectPoint (const CGVect3& _Point) const
{
    CGVect3 Proj;
    // Se proyecta el punto en direccion contraria a la normal
    Proj.LineEq( _Point,m_oPlaneNormal,-fGetDistanceToPoint(_Point) );
    return(Proj);
}

uint CGPlane::uiPlaneType () const
{
    if ( (m_oPlaneNormal.x == 1.0f) || (m_oPlaneNormal.x == -1.0f) )
        return(0);
    else
    if ( (m_oPlaneNormal.y == 1.0f) || (m_oPlaneNormal.y == -1.0f) )
        return(1);
    else
    if ( (m_oPlaneNormal.z == 1.0f) || (m_oPlaneNormal.z == -1.0f) )
        return(2);

    float aX,aY,aZ;

    aX = Math::fAbs( m_oPlaneNormal.x );
    aY = Math::fAbs( m_oPlaneNormal.y );
    aZ = Math::fAbs( m_oPlaneNormal.z );

    if ( aX >= aY && aX >= aZ )
        return(3);
    if ( aY >= aX && aY >= aZ )
        return(4);

    return(5);
}
// ----------------------------------------------------------------------------
