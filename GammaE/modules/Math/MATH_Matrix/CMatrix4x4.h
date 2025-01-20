//---------------------------------------------------------------------------
#ifndef CMatrix4x4H
#define CMatrix4x4H
//---------------------------------------------------------------------------
#include "MATH_Vector/cvect3.h"
#include "MATH_Vector/cvect4.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class CMatrix4x4
{
	public:	    CMatrix4x4();
    		   ~CMatrix4x4();

               	// Member initialization
				void LoadIdentity();
                void LoadFromAxis(CVect3 &e1,CVect3 &e2,CVect3 &e3);

                // Matrix operations
                void Translate	  (CVect3 &T);
                void TranslateAxis(char Axis,float Value);
                void Translate3f  (float x,float y,float z);

                void Scale	  	  (CVect3 &S);
                void ScaleAxis    (char Axis,float Value);
                void Scale3f  	  (float x,float y,float z);
                
                void RotateAxis(char Axis,float Value);
                void Rotate3f  (float Pitch,float Yaw,float Roll);
                void RotateFromArbitraryAxis      (float Angle,float x,float y,float z);

                // Matrix operations 2
                void Multiply  (CMatrix4x4 &M,CMatrix4x4 &N);
                void MultiplyBy(CMatrix4x4 &N);

                // Misc operations
                void TransformPoint (CVect3 &Vect);
                void TransformVector(CVect3 &Vect);

                CVect4 GetRowVector(int Row);
                CVect4 GetColVector(int Col);
                void SetRowVector  (int Row,float x,float y,float z,float w);
				void SetColVector  (int Col,float x,float y,float z,float w);
                
				void Transpose();
                void Inverse  ();
				void RTInverse();
                void Complementary();

                float Determinant();
				
				void  Set(int Row,int Col,float Value);
				float Get(int Row,int Col); 

				float f3ColDeterminant(int iCol0,int iCol1, int iCol2);
								
                // Member access
                float m[16];				// The matrix
    private:
                void RotateFromArbitraryAxisMatrix(float Angle,float x,float y,float z,float *m);    
};
//---------------------------------------------------------------------------
#endif
