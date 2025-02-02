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
/*
   Quaternion code extracted from "Advance OpenGL MD3Load"
   Author	: Mustata Bogdan (LoneRunner)
   Contact	: lonerunner@planetquake.com

   NOTE: Be careful in his code
    MAT ( row,col) and in GammaE CGMatrix4x4.fGet(Col,Row)
 */
#include <math.h>

// CGQuaternion
#include "Quaternion\CGQuaternion.h"
#define X 0
#define Y 1
#define Z 2
#define W 3
#define QUAT_EPSILON 0.1f

// ----------------------------------------------------------------------------
void CGQuaternion::Slerp (CGQuaternion& _Src, CGQuaternion& _Dst, float _fFactor)
{
    static float to1[4];
    static float omega, cosom, sinom, scale0, scale1;

    // calc cosine
    cosom = _Src.quat[X] * _Dst.quat[X] +
            _Src.quat[Y] * _Dst.quat[Y] +
            _Src.quat[Z] * _Dst.quat[Z] +
            _Src.quat[W] * _Dst.quat[W];

    // adjust signs (if necessary)
    if ( cosom < 0.0 )
    {
        cosom = -cosom;
        to1[0] = -_Dst.quat[X];
        to1[1] = -_Dst.quat[Y];
        to1[2] = -_Dst.quat[Z];
        to1[3] = -_Dst.quat[W];
    }
    else
    {
        to1[0] = _Dst.quat[X];
        to1[1] = _Dst.quat[Y];
        to1[2] = _Dst.quat[Z];
        to1[3] = _Dst.quat[W];
    }

    // calculate coefficients
    if ( (1.0 - cosom) > QUAT_EPSILON )
    {
        // standard case (slerp)
        omega = (float)acos(cosom);
        sinom = (float)sin(omega);
        scale0 = (float)sin( (1.0f - _fFactor) * omega ) / sinom;
        scale1 = (float)sin(_fFactor * omega) / sinom;
    }
    else
    {
        // "from" and "to" quaternions are very close
        // ... so we can do a linear interpolation
        scale0 = 1.0f - _fFactor;
        scale1 = _fFactor;
    }

    // calculate final values
    quat[X] = scale0 * _Src.quat[X] + scale1 * to1[0];
    quat[Y] = scale0 * _Src.quat[Y] + scale1 * to1[1];
    quat[Z] = scale0 * _Src.quat[Z] + scale1 * to1[2];
    quat[W] = scale0 * _Src.quat[W] + scale1 * to1[3];
}

CGMatrix4x4 & CGQuaternion::ToMatrix ()
{
    static CGMatrix4x4 Mat;
    static float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;

    // calculate coefficients

    x2 = quat[X] + quat[X];
    y2 = quat[Y] + quat[Y];
    z2 = quat[Z] + quat[Z];
    xx = quat[X] * x2;
    xy = quat[X] * y2;
    xz = quat[X] * z2;
    yy = quat[Y] * y2;
    yz = quat[Y] * z2;
    zz = quat[Z] * z2;
    wx = quat[W] * x2;
    wy = quat[W] * y2;
    wz = quat[W] * z2;

    Mat.Set( 0,0,1.0f - (yy + zz) );
    Mat.Set(0,1,        xy - wz);
    Mat.Set(0,2,         xz + wy);
    Mat.Set(0,3,           0.0f);

    Mat.Set(1,0,         xy + wz);
    Mat.Set( 1,1,1.f - (xx + zz) );
    Mat.Set(1,2,         yz - wx);
    Mat.Set(1,3,           0.0f);

    Mat.Set(2,0,         xz - wy);
    Mat.Set(2,1,        yz + wx);
    Mat.Set( 2,2,1.0f - (xx + yy) );
    Mat.Set(2,3,           0.0f);

    Mat.Set(3,0,            0.0f);
    Mat.Set(3,1,           0.0f);
    Mat.Set(3,2,            0.0f);
    Mat.Set(3,3,           1.0f);

    return (Mat);
}

void CGQuaternion::FromMatrix (CGMatrix4x4 &_Matrix)
{
    static float tr, s, q[4];
    static int i, j, k;
    static int nxt[3];

    nxt[0] = 1;
    nxt[1] = 2;
    nxt[2] = 0;

    tr = _Matrix.fGet(0,0) + _Matrix.fGet(1,1) + _Matrix.fGet(2,2);

    // check the diagonal
    if ( tr > 0.0 )
    {
        s = (float)Math::fSqrt(tr + 1.f);
        quat[W] = s / 2.0f;
        s = 0.5f / s;

        quat[X] = ( _Matrix.fGet(1,2) - _Matrix.fGet(2,1) ) * s;
        quat[Y] = ( _Matrix.fGet(2,0) - _Matrix.fGet(0,2) ) * s;
        quat[Z] = ( _Matrix.fGet(0,1) - _Matrix.fGet(1,0) ) * s;
    }
    else
    {
        // diagonal is negative
        i = 0;

        if ( _Matrix.fGet(1,1) > _Matrix.fGet(0,0) ) i = 1;
        if ( _Matrix.fGet(2,2) > _Matrix.fGet(i,i) ) i = 2;

        j = nxt[i];
        k = nxt[j];

        s = Math::fSqrt( ( _Matrix.fGet(i,i) - ( _Matrix.fGet(j,j) + _Matrix.fGet(k,k) ) ) + 1.0f );

        q[i] = s * (float)0.5;

        if ( s != 0.0f ) s = 0.5f / s;

        q[3] = ( _Matrix.fGet(i,k) - _Matrix.fGet(k,j) ) * s;
        q[j] = ( _Matrix.fGet(i,j) + _Matrix.fGet(j,i) ) * s;
        q[k] = ( _Matrix.fGet(i,k) + _Matrix.fGet(k,i) ) * s;

        quat[X] = q[0];
        quat[Y] = q[1];
        quat[Z] = q[2];
        quat[W] = q[3];
    }
}

#undef  X
#undef  Y
#undef  Z
#undef  W
#undef  QuatEpsilon

void CGQuaternion::FromVector(CGVect4& _Vect)
{
    quat[0] = _Vect.x;
    quat[1] = _Vect.y;
    quat[2] = _Vect.z;
    quat[3] = _Vect.w;
}

void CGQuaternion::FromComponents(CGVect3& _Vect,float _fRotation)
{
    quat[0] = _Vect.x;
    quat[1] = _Vect.y;
    quat[2] = _Vect.z;
    quat[3] = _fRotation;
}
// ----------------------------------------------------------------------------
