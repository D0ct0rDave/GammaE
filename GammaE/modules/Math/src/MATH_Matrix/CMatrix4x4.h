//-----------------------------------------------------------------------------
#ifndef CMatrix4x4H
#define CMatrix4x4H
//-----------------------------------------------------------------------------
#include "../MATH_Vector/cvect3.h"
#include "../MATH_Vector/cvect4.h"
//-----------------------------------------------------------------------------
class CMatrix4x4
{
	public:	    // Member initialization
				void LoadIdentity();
                void LoadFromAxis(const CVect3& e1,const CVect3& e2,const CVect3& e3);

                // Matrix operations
                void Translate(const CVect3& T);
                void Translate(char Axis,float Value);
                void Translate(float x,float y,float z);

                void Scale(const CVect3& S);
                void Scale(char Axis,float Value);
                void Scale(float x,float y,float z);

                void Rotate(char Axis,float Value);
                void Rotate(float Pitch,float Yaw,float Roll);
                void RotateFromArbitraryAxis(float Angle,float x,float y,float z);

                // Matrix operations 2
                void Multiply  (const CMatrix4x4& M,const CMatrix4x4& N);
                void MultiplyBy(const CMatrix4x4& N);

                // Misc operations
                void TransformPoint (CVect3& Vect) const;
                void TransformVector(CVect3& Vect) const;
                void TransformVector(CVect4& Vect) const;

                CVect4 GetRowVector(int Row) const;
                CVect4 GetColVector(int Col) const;
                void SetRowVector  (int Row,float x,float y,float z,float w);
				void SetColVector  (int Col,float x,float y,float z,float w);
                void SetRowVector  (int Row,const CVect4& _oR);
				void SetColVector  (int Col,const CVect4& _oC);

				void Transpose();
                void Inverse  ();
				void RTInverse();
                void Complementary();

                float Determinant() const;

				void  Set(int Row,int Col,float Value);
				float Get(int Row,int Col) const; 

				float f3ColDeterminant(int iCol0,int iCol1, int iCol2) const;

				//## Operation: operator*%971941763
				const CMatrix4x4 operator * (const CMatrix4x4 &B) const;

                // Member access
                float m[16];				// The matrix
    private:
                void RotateFromArbitraryAxisMatrix(float Angle,float x,float y,float z,float *m);    
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------

