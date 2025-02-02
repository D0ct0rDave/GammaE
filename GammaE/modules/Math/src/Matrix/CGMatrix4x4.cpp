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
#include "CGMatrix4x4.h"
#include "Other/GMathCommon.h"
#include <string.h>
#include <math.h>
// ----------------------------------------------------------------------------
// Column stored matrix
// ----------------------------------------------------------------------------
#define GetAxis(Axis) (Axis - 'x')
#define M(_uiRow,_uiCol) m[_uiCol * 4 + _uiRow]
// ----------------------------------------------------------------------------
void CGMatrix4x4::LoadIdentity()
{
    M(0,0) = 1;
    M(0,1) = 0;
    M(0,2) = 0;
    M(0,3) = 0;
    M(1,0) = 0;
    M(1,1) = 1;
    M(1,2) = 0;
    M(1,3) = 0;
    M(2,0) = 0;
    M(2,1) = 0;
    M(2,2) = 1;
    M(2,3) = 0;
    M(3,0) = 0;
    M(3,1) = 0;
    M(3,2) = 0;
    M(3,3) = 1;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::Set(uint _uiRow,uint _uiCol,float _fValue)
{
    M(_uiRow,_uiCol) = _fValue;
}
// ----------------------------------------------------------------------------
float CGMatrix4x4::fGet(uint _uiRow,uint _uiCol) const
{
    return ( M(_uiRow,_uiCol) );
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::LoadFromAxes(const CGVect3& _oX,const CGVect3& _oY,const CGVect3& _oZ)
{
    M(0,0) = _oX.x;
    M(0,1) = _oX.y;
    M(0,2) = _oX.z;
    M(0,3) = 0;
    M(1,0) = _oY.x;
    M(1,1) = _oY.y;
    M(1,2) = _oY.z;
    M(1,3) = 0;
    M(2,0) = _oZ.x;
    M(2,1) = _oZ.y;
    M(2,2) = _oZ.z;
    M(2,3) = 0;
    M(3,0) = 0;
    M(3,1) = 0;
    M(3,2) = 0;
    M(3,3) = 1;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::Translate(const CGVect3& _oT)
{
    // From Mesa 3.2: matrix.c glTranslatef
    M(0,3) += (M(0,0) * _oT.x + M(0,1) * _oT.y + M(0,2) * _oT.z);
    M(1,3) += (M(1,0) * _oT.x + M(1,1) * _oT.y + M(1,2) * _oT.z);
    M(2,3) += (M(2,0) * _oT.x + M(2,1) * _oT.y + M(2,2) * _oT.z);
    M(3,3) += (M(3,0) * _oT.x + M(3,1) * _oT.y + M(3,2) * _oT.z);
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::Translate(float _fValue,char _cAxis)
{
    uint e = GetAxis(_cAxis);

    M(0,3) += (M(0,e) * _fValue);
    M(1,3) += (M(1,e) * _fValue);
    M(2,3) += (M(2,e) * _fValue);
    M(3,3) += (M(3,e) * _fValue);
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::Translate(float x,float y,float z)
{
    M(0,3) += (M(0,0) * x + M(0,1) * y + M(0,2) * z);
    M(1,3) += (M(1,0) * x + M(1,1) * y + M(1,2) * z);
    M(2,3) += (M(2,0) * x + M(2,1) * y + M(2,2) * z);
    M(3,3) += (M(3,0) * x + M(3,1) * y + M(3,2) * z);
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::Scale(const CGVect3 &_oS)
{
    M(0,0) *= _oS.x;
    M(0,1) *= _oS.y;
    M(0,2) *= _oS.z;
    M(1,0) *= _oS.x;
    M(1,1) *= _oS.y;
    M(1,2) *= _oS.z;
    M(2,0) *= _oS.x;
    M(2,1) *= _oS.y;
    M(2,2) *= _oS.z;
    M(3,0) *= _oS.x;
    M(3,1) *= _oS.y;
    M(3,2) *= _oS.z;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::Scale(float _fValue,char _cAxis)
{
    uint e = GetAxis(_cAxis);

    M(0,e) *= _fValue;
    M(1,e) *= _fValue;
    M(2,e) *= _fValue;
    M(3,e) *= _fValue;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::Scale(float x,float y,float z)
{
    M(0,0) *= x;
    M(0,1) *= y;
    M(0,2) *= z;
    M(1,0) *= x;
    M(1,1) *= y;
    M(1,2) *= z;
    M(2,0) *= x;
    M(2,1) *= y;
    M(2,2) *= z;
    M(3,0) *= x;
    M(3,1) *= y;
    M(3,2) *= z;
}

// ----------------------------------------------------------------------------
void CGMatrix4x4::Rotate(float _fValue,char _cAxis)
{
    CGVect3 e;

    // upper case
    if ( (_cAxis >= 'X') && (_cAxis >= 'Z') ) _cAxis += 32;

    switch ( _cAxis )
    {
        case 'x':   e = CGVect3::oX();
        break;

        case 'y':   e = CGVect3::oY();
        break;

        case 'z':   e = CGVect3::oZ();
        break;
    }

    TransformVector(&e);
    RotateFromArbitraryAxis(_fValue,e.x,e.y,e.z);
    /*
       CGMatrix4x4 R;

       float Cos = cos (_fValue);
       float Sin = sin (_fValue);

       if ((Cos<0.00005) && (Cos>-0.0005)) Cos = 0;
       if ((Sin<0.00005) && (Sin>-0.0005)) Sin = 0;

       switch (Axis)
       {
           case 'x':R.M(0,0) = 1;    R.M(0,1) = 0;    R.M(0,2) = 0;    R.M(0,3) = 0;
                    R.M(1,0) = 0;    R.M(1,1) = Cos;  R.M(1,2) = -Sin; R.M(1,3) = 0;
                    R.M(2,0) = 0;    R.M(2,1) = Sin;  R.M(2,2) = Cos;  R.M(2,3) = 0;
                    R.M(3,0) = 0;    R.M(3,1) = 0;    R.M(3,2) = 0;    R.M(3,3) = 1;
                    break;
           case 'y':R.M(0,0) = Cos;  R.M(0,1) = 0;    R.M(0,2) = Sin;  R.M(0,3) = 0;
                    R.M(1,0) = 0;    R.M(1,1) = 1;    R.M(1,2) = 0;    R.M(1,3) = 0;
                    R.M(2,0) = -Sin; R.M(2,1) = 0;    R.M(2,2) = Cos;  R.M(2,3) = 0;
                    R.M(3,0) = 0;    R.M(3,1) = 0;    R.M(3,2) = 0;    R.M(3,3) = 1;
                    break;
           case 'z':R.M(0,0) = Cos;  R.M(0,1) = -Sin; R.M(0,2) = 0;    R.M(0,3) = 0;
                    R.M(1,0) = Sin;  R.M(1,1) = Cos;  R.M(1,2) = 0;    R.M(1,3) = 0;
                    R.M(2,0) = 0;    R.M(2,1) = 0;    R.M(2,2) = 1;    R.M(2,3) = 0;
                    R.M(3,0) = 0;    R.M(3,1) = 0;    R.M(3,2) = 0;    R.M(3,3) = 1;
                    break;
       }

       // Automultiplicarse por R
       MultiplyBy(R);
     */
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::Rotate(float _fPitch,float _fYaw,float _fRoll)
{
    if ( (!_fPitch) && (!_fYaw) && (!_fRoll) ) return;

    if ( _fPitch )
    {
        CGVect3 oX;
        oX.Set(1.0f,0.0f,0.0f);

        TransformVector(&oX);
        RotateFromArbitraryAxis(_fPitch,oX.x,oX.y,oX.z);
    }

    if ( _fYaw )
    {
        CGVect3 oY;
        oY.Set(0.0f,1.0f,0.0f);
        TransformVector(&oY);
        RotateFromArbitraryAxis(_fYaw,oY.x,oY.y,oY.z);
    }

    if ( _fRoll )
    {
        CGVect3 oZ;
        oZ.Set(0.0f,0.0f,1.0f);
        TransformVector(&oZ);
        RotateFromArbitraryAxis(_fRoll,oZ.x,oZ.y,oZ.z);
    }
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::RotateFromArbitraryAxis(float _fAngle, const CGVect3& _oAxis)
{
    RotateFromArbitraryAxis(_fAngle, _oAxis.x, _oAxis.y, _oAxis.z);
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::RotateFromArbitraryAxis(float _fAngle,float x,float y,float z)
{
    CGMatrix4x4 R;
    RotateFromArbitraryAxisMatrix(_fAngle,x,y,z,R.m);
    MultiplyBy(R);
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::RotateFromArbitraryAxisMatrix(float _fAngle,float x,float y,float z,float* m)
{
    /* This function contributed by Erich Boleyn (erich@uruk.org) */
    float mag, s, c;
    float xx, yy, zz, xy, yz, zx, xs, ys, zs, one_c;

    s = sin( _fAngle );
    c = cos( _fAngle );

    mag = Math::fSqrt( x * x + y * y + z * z );

    if ( mag == 0.0 )
    {
        /* generate an identity matrix and return */
        LoadIdentity();
        return;
    }

    x /= mag;
    y /= mag;
    z /= mag;

    /*
     *     Arbitrary axis rotation matrix.
     *
     *  This is composed of 5 matrices, Rz, Ry, T, Ry', Rz', multiplied
     *  like so:  Rz * Ry * T * Ry' * Rz'.  T is the final rotation
     *  (which is about the X-axis), and the two composite transforms
     *  Ry' * Rz' and Rz * Ry are (respectively) the rotations necessary
     *  from the arbitrary axis to the X-axis then back.  They are
     *  all elementary rotations.
     *
     *  Rz' is a rotation about the Z-axis, to bring the axis vector
     *  into the x-z plane.  Then Ry' is applied, rotating about the
     *  Y-axis to bring the axis vector parallel with the X-axis.  The
     *  rotation about the X-axis is then performed.  Ry and Rz are
     *  simply the respective inverse transforms to bring the arbitrary
     *  axis back to it's original orientation.  The first transforms
     *  Rz' and Ry' are considered inverses, since the data from the
     *  arbitrary axis gives you info on how to get to it, not how
     *  to get away from it, and an inverse must be applied.
     *
     *  The basic calculation used is to recognize that the arbitrary
     *  axis vector (x, y, z), since it is of unit length, actually
     *  represents the sines and cosines of the _fAngles to rotate the
     *  X-axis to the same orientation, with theta being the _fAngle about
     *  Z and phi the angle about Y (in the order described above)
     *  as follows:
     *
     *  cos ( theta ) = x / sqrt ( 1 - z^2 )
     *  sin ( theta ) = y / sqrt ( 1 - z^2 )
     *
     *  cos ( phi ) = sqrt ( 1 - z^2 )
     *  sin ( phi ) = z
     *
     *  Note that cos ( phi ) can further be inserted to the above
     *  formulas:
     *
     *  cos ( theta ) = x / cos ( phi )
     *  sin ( theta ) = y / sin ( phi )
     *
     *  ...etc.  Because of those relations and the standard trigonometric
     *  relations, it is pssible to reduce the transforms down to what
     *  is used below.  It may be that any primary axis chosen will give the
     *  same results (modulo a sign convention) using thie method.
     *
     *  Particularly nice is to notice that all divisions that might
     *  have caused trouble when parallel to certain planes or
     *  axis go away with care paid to reducing the expressions.
     *  After checking, it does perform correctly under all cases, since
     *  in all the cases of division where the denominator would have
     *  been zero, the numerator would have been zero as well, giving
     *  the expected result.
     */

    xx = x * x;
    yy = y * y;
    zz = z * z;
    xy = x * y;
    yz = y * z;
    zx = z * x;
    xs = x * s;
    ys = y * s;
    zs = z * s;
    one_c = 1.0F - c;

    M(0,0) = (one_c * xx) + c;
    M(0,1) = (one_c * xy) - zs;
    M(0,2) = (one_c * zx) + ys;
    M(0,3) = 0.0F;

    M(1,0) = (one_c * xy) + zs;
    M(1,1) = (one_c * yy) + c;
    M(1,2) = (one_c * yz) - xs;
    M(1,3) = 0.0F;

    M(2,0) = (one_c * zx) - ys;
    M(2,1) = (one_c * yz) + xs;
    M(2,2) = (one_c * zz) + c;
    M(2,3) = 0.0F;

    M(3,0) = 0.0F;
    M(3,1) = 0.0F;
    M(3,2) = 0.0F;
    M(3,3) = 1.0F;
}
// -----------------------------------------------------------------------------
// Multiplica M * N
// -----------------------------------------------------------------------------
// Algorithm:
// For each row of M
// For each col of N
// ResMatrix(Row,Col) = DotProduct ( RowVector(M,Row) , ColVector(N,Col) )
// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void CGMatrix4x4::Multiply(const CGMatrix4x4& A,const CGMatrix4x4& B)
{
    // Para cada fila
    for ( uint i = 0; i < 4; i++ )
        // Para cada columna
        for ( uint j = 0; j < 4; j++ )
        {
            M(i,j) = A.M(i,0) * B.M(0,j) +
                     A.M(i,1) * B.M(1,j) +
                     A.M(i,2) * B.M(2,j) +
                     A.M(i,3) * B.M(3,j);
        }
}
// ----------------------------------------------------------------------------
// Computes this * B matrix multiplication
// ----------------------------------------------------------------------------
void CGMatrix4x4::MultiplyBy(const CGMatrix4x4& B)
{
    CGMatrix4x4 A = *this;

    // Para cada fila
    for ( uint i = 0; i < 4; i++ )
        // Para cada columna
        for ( uint j = 0; j < 4; j++ )
        {
            M(i,j) = A.M(i,0) * B.M(0,j) +
                     A.M(i,1) * B.M(1,j) +
                     A.M(i,2) * B.M(2,j) +
                     A.M(i,3) * B.M(3,j);
        }
}
// ----------------------------------------------------------------------------
// Multiplicacion   Matriz*vector
// -----------------------------------------------------------------------------
// a
// A  - - - -   |  = (A.a,B.a,C.a,D.a)
// B  - - - - * |
// C  - - - -   |  =  - - - -
// D  - - - -   |
// ----------------------------------------------------------------------------
// Dot product entre point4D (x,y,z,1) y matrix
// ----------------------------------------------------------------------------
void CGMatrix4x4::TransformPoint(CGVect3* _poVect) const
{
    *_poVect = oTransformPoint(*_poVect);
}

const CGVect3& CGMatrix4x4::oTransformPoint(const CGVect3& _oVect) const
{
    static CGVect3 v;

    // Hacer dot product del vector y la fila
    v.x = M(0,0) * _oVect.x +
          M(0,1) * _oVect.y +
          M(0,2) * _oVect.z +
          M(0,3) /* * (_oVect.v[3) = 1) */;

    v.y = M(1,0) * _oVect.x +
          M(1,1) * _oVect.y +
          M(1,2) * _oVect.z +
          M(1,3) /* * (_oVect.v[3) = 1) */;

    v.z = M(2,0) * _oVect.x +
          M(2,1) * _oVect.y +
          M(2,2) * _oVect.z +
          M(2,3) /* * (_oVect.v[3) = 1) */;

    return(v);
}
// ----------------------------------------------------------------------------
// Dot product entre vector3D (x,y,z,0) y matrix
// ----------------------------------------------------------------------------
void CGMatrix4x4::TransformVector(CGVect3* _poVect) const
{
    *_poVect = oTransformVector(*_poVect);
}

const CGVect3& CGMatrix4x4::oTransformVector(const CGVect3& _oVect) const
{
    static CGVect3 v;

    // Hacer dot product del vector y la fila
    v.x = M(0,0) * _oVect.x +
          M(0,1) * _oVect.y +
          M(0,2) * _oVect.z
          /* + M(0,3)*(_oVect.v[3]) (_oVect.v[3] = 0) */;

    v.y = M(1,0) * _oVect.x +
          M(1,1) * _oVect.y +
          M(1,2) * _oVect.z
          /* + M(1,3)*(_oVect.v[3]) (_oVect.v[3] = 0) */;

    v.z = M(2,0) * _oVect.x +
          M(2,1) * _oVect.y +
          M(2,2) * _oVect.z
          /* + M(2,3)*(_oVect.v[3]) (_oVect.v[3] = 0) */;

    return(v);
}
// ----------------------------------------------------------------------------
// Dot product entre point4D (x,y,z,w) y matrix
// ----------------------------------------------------------------------------
void CGMatrix4x4::TransformVector(CGVect4* _poVect) const
{
    *_poVect = oTransformVector(*_poVect);
}

const CGVect4& CGMatrix4x4::oTransformVector(const CGVect4& _oVect) const
{
    static CGVect4 v;

    // Optimized version
    for ( uint i = 0; i < 3; i++ )
    {
        // Hacer dot product del vector y la fila
        v.v(i) = M(i,0) * _oVect.x +
                 M(i,1) * _oVect.y +
                 M(i,2) * _oVect.z +
                 M(i,3) * _oVect.w;
    }

    return(v);
}
// ----------------------------------------------------------------------------
const CGVect4& CGMatrix4x4::oGetRow(uint _uiRow) const
{
    static CGVect4 Res;
    Res.x = M(_uiRow,0);
    Res.y = M(_uiRow,1);
    Res.z = M(_uiRow,2);
    Res.w = M(_uiRow,3);
    return(Res);
}
// ----------------------------------------------------------------------------
const CGVect4& CGMatrix4x4::oGetCol(uint _uiCol) const
{
    static CGVect4 Res;
    Res.x = M(0,_uiCol);
    Res.y = M(1,_uiCol);
    Res.z = M(2,_uiCol);
    Res.w = M(3,_uiCol);
    return(Res);
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::SetRow(uint _uiRow,const CGVect4& _oR)
{
    M(_uiRow,0) = _oR.x;
    M(_uiRow,1) = _oR.y;
    M(_uiRow,2) = _oR.z;
    M(_uiRow,3) = _oR.w;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::SetCol(uint _uiCol,const CGVect4& _oC)
{
    M(0,_uiCol) = _oC.x;
    M(1,_uiCol) = _oC.y;
    M(2,_uiCol) = _oC.z;
    M(3,_uiCol) = _oC.w;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::SetRow(uint _uiRow,float x,float y,float z,float w)
{
    M(_uiRow,0) = x;
    M(_uiRow,1) = y;
    M(_uiRow,2) = z;
    M(_uiRow,3) = w;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::SetCol(uint _uiCol,float x,float y,float z,float w)
{
    M(0,_uiCol) = x;
    M(1,_uiCol) = y;
    M(2,_uiCol) = z;
    M(3,_uiCol) = w;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::SetRow(uint _uiRow,const CGVect3& _oR)
{
    M(_uiRow,0) = _oR.x;
    M(_uiRow,1) = _oR.y;
    M(_uiRow,2) = _oR.z;
    M(_uiRow,3) = (_uiRow == 3)?1.0f:0.0f;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::SetCol(uint _uiCol,const CGVect3& _oC)
{
    M(0,_uiCol) = _oC.x;
    M(1,_uiCol) = _oC.y;
    M(2,_uiCol) = _oC.z;
    M(3,_uiCol) = (_uiCol == 3)?1.0f:0.0f;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::SetRow(uint _uiRow,float x,float y,float z)
{
    M(_uiRow,0) = x;
    M(_uiRow,1) = y;
    M(_uiRow,2) = z;
    M(_uiRow,3) = (_uiRow == 3)?1.0f:0.0f;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::SetCol(uint _uiCol,float x,float y,float z)
{
    M(0,_uiCol) = x;
    M(1,_uiCol) = y;
    M(2,_uiCol) = z;
    M(3,_uiCol) = (_uiCol == 3)?1.0f:0.0f;
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::Transpose()
{
    // axiliary matrix
    float aux[16];
    memcpy( aux,m,16 * sizeof(float) );

    m[0 * 4 + 0] = aux[0 * 4 + 0];
    m[1 * 4 + 0] = aux[0 * 4 + 1];
    m[2 * 4 + 0] = aux[0 * 4 + 2];
    m[3 * 4 + 0] = aux[0 * 4 + 3];

    m[0 * 4 + 1] = aux[1 * 4 + 0];
    m[1 * 4 + 1] = aux[1 * 4 + 1];
    m[2 * 4 + 1] = aux[1 * 4 + 2];
    m[3 * 4 + 1] = aux[1 * 4 + 3];

    m[0 * 4 + 2] = aux[2 * 4 + 0];
    m[1 * 4 + 2] = aux[2 * 4 + 1];
    m[2 * 4 + 2] = aux[2 * 4 + 2];
    m[3 * 4 + 2] = aux[2 * 4 + 3];

    m[0 * 4 + 3] = aux[3 * 4 + 0];
    m[1 * 4 + 3] = aux[3 * 4 + 1];
    m[2 * 4 + 3] = aux[3 * 4 + 2];
    m[3 * 4 + 3] = aux[3 * 4 + 3];
}
// ----------------------------------------------------------------------------
float CGMatrix4x4::fDeterminant() const
{
    return(
               (
                   M(0,0) * M(1,1) * M(2,2) * M(3,3) + M(0,1) * M(1,2) * M(2,3) * M(3,0) +
                   M(0,2) * M(1,3) * M(2,0) * M(3,1) + M(0,3) * M(1,0) * M(2,1) * M(3,2)
               )
               -
               (
                   M(0,3) * M(1,2) * M(2,1) * M(3,0) + M(0,2) * M(1,1) * M(2,0) * M(3,3) +
                   M(0,1) * M(1,0) * M(2,3) * M(3,2) + M(0,0) * M(1,3) * M(2,2) * M(3,1)
               )
               );
}
// ----------------------------------------------------------------------------
void CGMatrix4x4::Complementary()
{
    unsigned char Matrix3x3SelTable[4][3] = {{1,2,3},{0,2,3},{0,1,3},{0,1,2}};
    unsigned char cC0,cC1,cC2,cR0,cR1,cR2;

    float fDet;
    CGMatrix4x4 O = *this;

    for ( uint cRow = 0; cRow < 4; cRow++ )
    {
        cR0 = Matrix3x3SelTable[cRow][0];
        cR1 = Matrix3x3SelTable[cRow][1];
        cR2 = Matrix3x3SelTable[cRow][2];

        for ( uint cCol = 0; cCol < 4; cCol++ )
        {
            // Adjoint A(i,j) (take out i row j col of A)
            cC0 = Matrix3x3SelTable[cCol][0];
            cC1 = Matrix3x3SelTable[cCol][1];
            cC2 = Matrix3x3SelTable[cCol][2];

            // Compute the determinant of the current adjoint matrix
            fDet = (
                O.M(cR0,cC0) * O.M(cR1,cC1) * O.M(cR2,cC2) +
                O.M(cR0,cC1) * O.M(cR1,cC2) * O.M(cR2,cC0) +
                O.M(cR0,cC2) * O.M(cR1,cC0) * O.M(cR2,cC1)
                )
                   -
                   (
                O.M(cR0,cC2) * O.M(cR1,cC1) * O.M(cR2,cC0) +
                O.M(cR0,cC1) * O.M(cR1,cC0) * O.M(cR2,cC2) +
                O.M(cR0,cC0) * O.M(cR1,cC2) * O.M(cR2,cC1)
                   );
            // Compute sign: Sgn = (-1)^(i+j)
            if ( (cRow + cCol) & 0x01 ) fDet *= -1;

            // Store the computed value
            M(cRow,cCol) = O.M(cRow,cCol) * fDet;
        }
    }
}
// ----------------------------------------------------------------------------
// 1    1
// M    =  -  * Adj(M)
// |M|
// ----------------------------------------------------------------------------
void CGMatrix4x4::Inverse()
{
    float fDet = fDeterminant();

    if ( !fDet ) return;

    uint cRow,cCol;

    Transpose();
    Complementary();

    fDet = 1.0f / fDet;

    for ( cRow = 0; cRow < 4; cRow++ )
        for ( cCol = 0; cCol < 4; cCol++ )
            M(cRow,cCol) *= fDet;
}
// ----------------------------------------------------------------------------
// Performs the inverse of a rotation & translation matrix
// ----------------------------------------------------------------------------
void CGMatrix4x4::RTInverse()
{
    // auxiliary matrix
    float aux[16];
    memcpy( aux,m,16 * sizeof(float) );

    // Inverse of the rotation
    M(0,0) = aux[4 * 0 + 0];
    M(0,1) = aux[4 * 0 + 1];
    M(0,2) = aux[4 * 0 + 2];

    M(1,0) = aux[4 * 1 + 0];
    M(1,1) = aux[4 * 1 + 1];
    M(1,2) = aux[4 * 1 + 2];

    M(2,0) = aux[4 * 2 + 0];
    M(2,1) = aux[4 * 2 + 1];
    M(2,2) = aux[4 * 2 + 2];

    // Inverse of the translation:
    // From Mesa 3.2: matrix.c invert_matrix_3d

    // x = Dot( Input.Col(3),Output.Row(0) )
    // y = Dot( Input.Col(3),Output.Row(1) )
    // z = Dot( Input.Col(3),Output.Row(2) )

    M(0,3) = -( aux[3 * 4 + 0] * M(0,0) + aux[3 * 4 + 1] * M(0,1) + aux[3 * 4 + 2] * M(0,2) );
    M(1,3) = -( aux[3 * 4 + 0] * M(1,0) + aux[3 * 4 + 1] * M(1,1) + aux[3 * 4 + 2] * M(1,2) );
    M(2,3) = -( aux[3 * 4 + 0] * M(2,0) + aux[3 * 4 + 1] * M(2,1) + aux[3 * 4 + 2] * M(2,2) );
}
// ----------------------------------------------------------------------------
float CGMatrix4x4::f3ColDeterminant(uint _uiCol0,uint _uiCol1, uint _uiCol2) const
{
    return(
               ( M(0,_uiCol0) * M(1,_uiCol1) * M(2,_uiCol2) +
                M(0,_uiCol1) * M(1,_uiCol2) * M(2,_uiCol0) +
                M(0,_uiCol2) * M(1,_uiCol0) * M(2,_uiCol1) )
               -
               ( M(0,_uiCol2) * M(1,_uiCol1) * M(2,_uiCol0) +
                M(0,_uiCol0) * M(1,_uiCol2) * M(2,_uiCol1) +
                M(0,_uiCol1) * M(1,_uiCol0) * M(2,_uiCol2) )
               );
}
// ----------------------------------------------------------------------------
const CGMatrix4x4 CGMatrix4x4::operator* (const CGMatrix4x4 &_oB) const
{
    CGMatrix4x4 oA = *this;
    oA.MultiplyBy( (CGMatrix4x4 &)_oB );
    return(oA);
}
// ----------------------------------------------------------------------------
#undef M
// ----------------------------------------------------------------------------
