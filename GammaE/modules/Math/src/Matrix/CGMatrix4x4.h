// ----------------------------------------------------------------------------
/*! \class CGMatrix4x4
 *  \brief 4x4 Matrix Arithmetic.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGMatrix4x4H
#define CGMatrix4x4H
// ----------------------------------------------------------------------------
#include "Vector/CGVect3.h"
#include "Vector/CGVect4.h"
// ----------------------------------------------------------------------------
class CGMatrix4x4
{
    public:

        // / Loads the identity into the current matrix.
        void LoadIdentity();

        // / Loads the matrix with the specified axes.
        void LoadFromAxes(const CGVect3& _oX,const CGVect3& _oY,const CGVect3& _oZ);

        // / Translates the current matrix by the given vector.
        void Translate(const CGVect3& _oT);

        // / Translates the current matrix along each of the axis, usign the given values.
        void Translate(float x,float y,float z);

        // / Translates the current matrix by the given value along the given axis.
        // / @param char _cAxis: possible values 'x','X','y','Y','z','Z'
        void Translate(float _fOffset,char _cAxis);

        // / Scales the current matrix along the XYZ axis, using the data stored in the XYZ components of the given vector.
        void Scale(const CGVect3& _oS);

        // / Performs the scaling of the current matrix along all the axis by the given values.
        void Scale(float x,float y,float z);

        // / Performs the scaling of the current matrix along an axis by a given value.
        // / @param char _cAxis: possible values 'x','X','y','Y','z','Z'
        void Scale(float _fScale,char _cAxis);

        // / Rotates the current matrix by the given angles around X,Y,Z axis.
        void Rotate(float _fPitch,float _fYaw,float _fRoll);

        // / Rotates the current matrix by the given angle around the axis represented by the given char.
        // / @param char _cAxis: possible values 'x','X','y','Y','z','Z'
        void Rotate(float _fValue,char _cAxis);

        // / Rotates the current matrix by a given angle and axis components.
        void RotateFromArbitraryAxis(float _fAngle,float x,float y,float z);

        // / Rotates the current matrix by a given angle and axis vector.
        void RotateFromArbitraryAxis(float _fAngle,const CGVect3& _oAxis);

        // / Multiplies the given matrices and stores the result as the current matrix.
        void Multiply(const CGMatrix4x4& _oM,const CGMatrix4x4& _oN);

        // / Multiplies the current matrix by the given one.
        void MultiplyBy(const CGMatrix4x4& _oN);

        // / Transform the given position by the current matrix.
        void TransformPoint(CGVect3* _poVect) const;

        // / Transform the given position by the current matrix.
        const CGVect3& oTransformPoint(const CGVect3& _oVect) const;

        // / Transform the given 3 component  vector by the current matrix.
        void TransformVector(CGVect3* _poVect) const;

        // / Transform the given 3 component  vector by the current matrix.
        const CGVect3& oTransformVector(const CGVect3& _oVect) const;

        // / Transform the given 4 component  vector by the current matrix.
        void TransformVector(CGVect4* _poVect) const;

        // / Transform the given 3 component  vector by the current matrix.
        const CGVect4& oTransformVector(const CGVect4& _oVect) const;

        // / Retrieves the specified row of the current matrix.
        const CGVect4& oGetRow(uint _uiRow) const;

        // / Retrieves the specified column of the current matrix.
        const CGVect4& oGetCol(uint _uiCol) const;

        // / Sets the specified row for the current matrix.
        void SetRow(uint _uiRow,const CGVect4& _oR);

        // / Sets the specified column for the current matrix.
        void SetCol(uint _uiCol,const CGVect4& _oC);

        // / Sets the specified row with the given values.
        void SetRow(uint _uiRow,float x,float y,float z,float w);

        // / Sets the specified column with the given values.
        void SetCol(uint _uiCol,float x,float y,float z,float w);

        // / Sets the specified row for the current matrix.
        void SetRow(uint _uiRow,const CGVect3& _oR);

        // / Sets the specified column for the current matrix.
        void SetCol(uint _uiCol,const CGVect3& _oC);

        // / Sets the specified row with the given values.
        void SetRow(uint _uiRow,float x,float y,float z);

        // / Sets the specified column with the given values.
        void SetCol(uint _uiCol,float x,float y,float z);

        // / Performs the transpose of the matrix.
        void Transpose();

        // / Performs the inverse of the matrix.
        void Inverse();

        // / Performs the inverse of the Rotation Translated matrix.
        void RTInverse();

        // / Performs the complementary of the matrix.
        void Complementary();

        // / Retrieve the determinant of the whole matrix.
        float fDeterminant() const;

        // / Retrieves the determinant of a given 3 column submatrix.
        float f3ColDeterminant(uint _uiCol0,uint _uiCol1,uint _uiCol2) const;

        // / Sets the value for a given element represented by its column and row.
        void Set(uint _uiRow,uint _uiCol,float _fValue);

        // / Retrieves the value of a given element represented by its column and row.
        float fGet(uint _uiRow,uint _uiCol) const;

        // / Retrieve a pointer to the matrix data.
        float* pfGetData() const
        {
            return( (float*)m );
        }

        // / Multiplies the matrix by the given one an returns the result
        const CGMatrix4x4 operator* (const CGMatrix4x4 &_oB) const;

    protected:

        // Member access
        float m[16];

        void RotateFromArbitraryAxisMatrix(float Angle,float x,float y,float z,float* m);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
