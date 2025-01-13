//---------------------------------------------------------------------------
#include "CMatrix4x4.h"
#include "MATH_Other/MATH_Common.h"
#include <string.h>
#include <math.h>
//---------------------------------------------------------------------------
CMatrix4x4::CMatrix4x4()
{
}
CMatrix4x4::~CMatrix4x4()
{
}
//---------------------------------------------------------------------------
// Column stored matrix
//---------------------------------------------------------------------------
#define GetAxis(Axis) (Axis - 'x')
#define M(Row,Col) m[Col*4 + Row]
//---------------------------------------------------------------------------
void CMatrix4x4::LoadIdentity()
{
	M(0,0) = 1;    M(0,1) = 0;    M(0,2) = 0;    M(0,3) = 0;
    M(1,0) = 0;    M(1,1) = 1;    M(1,2) = 0;    M(1,3) = 0;
    M(2,0) = 0;    M(2,1) = 0;    M(2,2) = 1;    M(2,3) = 0;
    M(3,0) = 0;    M(3,1) = 0;    M(3,2) = 0;    M(3,3) = 1;
}

void CMatrix4x4::Set(int Row,int Col,float Value)
{
	M(Row,Col) = Value;	
}

float CMatrix4x4::Get(int Row,int Col)
{
	return ( M(Row,Col) );
}
//---------------------------------------------------------------------------
void CMatrix4x4::LoadFromAxis(CVect3 &e1,CVect3 &e2,CVect3 &e3)
{
    M(0,0) = e1.v[0];	M(0,1) = e1.v[1];	M(0,2) = e1.v[2];	M(0,3) = 0;
    M(1,0) = e2.v[0];	M(1,1) = e2.v[1];	M(1,2) = e2.v[2];	M(1,3) = 0;
    M(2,0) = e3.v[0];	M(2,1) = e3.v[1];	M(2,2) = e3.v[2];	M(2,3) = 0;
    M(3,0) = 0;  		M(3,1) = 0;			M(3,2) = 0;			M(3,3) = 1;
}
//---------------------------------------------------------------------------
void CMatrix4x4::Translate(CVect3 &T)
{
	// From Mesa 3.2: matrix.c glTranslatef
	M(0,3) += ( M(0,0) * T.v[0] + M(0,1) * T.v[1] + M(0,2) * T.v[2] );
	M(1,3) += ( M(1,0) * T.v[0] + M(1,1) * T.v[1] + M(1,2) * T.v[2] );
	M(2,3) += ( M(2,0) * T.v[0] + M(2,1) * T.v[1] + M(2,2) * T.v[2] );
	M(3,3) += ( M(3,0) * T.v[0] + M(3,1) * T.v[1] + M(3,2) * T.v[2] );
}
//---------------------------------------------------------------------------
void CMatrix4x4::TranslateAxis(char Axis,float Value)
{
    unsigned int e = GetAxis(Axis);

	M(0,3) += (M(0,e) * Value);
	M(1,3) += (M(1,e) * Value);
    M(2,3) += (M(2,e) * Value);
	M(3,3) += (M(3,e) * Value);
}
//---------------------------------------------------------------------------
void CMatrix4x4::Translate3f(float x,float y,float z)
{
	M(0,3) += ( M(0,0)*x + M(0,1)*y + M(0,2)*z );
	M(1,3) += ( M(1,0)*x + M(1,1)*y + M(1,2)*z );
	M(2,3) += ( M(2,0)*x + M(2,1)*y + M(2,2)*z );
	M(3,3) += ( M(3,0)*x + M(3,1)*y + M(3,2)*z );
}
//---------------------------------------------------------------------------
void CMatrix4x4::Scale(CVect3 &S)
{
	M(0,0) *= S.X();	M(0,1) *= S.Y();	M(0,2) *= S.Z();
    M(1,0) *= S.X();	M(1,1) *= S.Y();	M(1,2) *= S.Z();
    M(2,0) *= S.X();	M(2,1) *= S.Y();	M(2,2) *= S.Z();
    M(3,0) *= S.X();	M(3,1) *= S.Y();	M(3,2) *= S.Z();
}
//---------------------------------------------------------------------------
void CMatrix4x4::ScaleAxis(char Axis,float Value)
{
	unsigned int e = GetAxis(Axis);

	M(0,e) *= Value;
    M(1,e) *= Value;
    M(2,e) *= Value;
    M(3,e) *= Value;
}
//---------------------------------------------------------------------------
void CMatrix4x4::Scale3f(float x,float y,float z)
{
	M(0,0) *= x;	M(0,1) *= y;	M(0,2) *= z;
    M(1,0) *= x;	M(1,1) *= y;	M(1,2) *= z;
    M(2,0) *= x;	M(2,1) *= y;	M(2,2) *= z;
    M(3,0) *= x;	M(3,1) *= y;	M(3,2) *= z;
}

//---------------------------------------------------------------------------
void CMatrix4x4::RotateAxis(char Axis,float Value)
{
	CVect3  e;

	switch (Axis)
	{
		case 'x':	e.V3(1.0f,0.0f,0.0f);
					break;
		case 'y':	e.V3(0.0f,1.0f,0.0f);
					break;
		case 'z':	e.V3(0.0f,0.0f,1.0f);
					break;
	}

	TransformVector(e);
	RotateFromArbitraryAxis(Value,e.X(),e.Y(),e.Z());
 /*
    CMatrix4x4 R;

	float Cos = cos (Value);
    float Sin = sin (Value);

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
//---------------------------------------------------------------------------
void CMatrix4x4::Rotate3f(float Pitch,float Yaw,float Roll)
{
	if ((! Pitch) && (! Yaw) && (!Roll)) return;

	if (Pitch)
	{
		CVect3 eX;
		eX.V3(1.0f,0.0f,0.0f);

		TransformVector(eX);
		RotateFromArbitraryAxis(Pitch,eX.X(),eX.Y(),eX.Z());
	}

	if (Yaw)
	{
		CVect3 eY;
		eY.V3(0.0f,1.0f,0.0f);
		TransformVector(eY);
		RotateFromArbitraryAxis(Yaw,eY.X(),eY.Y(),eY.Z());
	}
	
	if (Roll)
	{
		CVect3 eZ;
		eZ.V3(0.0f,0.0f,1.0f);
		TransformVector(eZ);			
		RotateFromArbitraryAxis(Roll,eZ.X(),eZ.Y(),eZ.Z());	
	}
}
//---------------------------------------------------------------------------
void CMatrix4x4::RotateFromArbitraryAxis(float Angle,float x,float y,float z)
{
	CMatrix4x4 R;
    RotateFromArbitraryAxisMatrix(Angle,x,y,z,R.m);
    MultiplyBy(R);
}
//---------------------------------------------------------------------------
// Stolen from Mesa 3.2
//---------------------------------------------------------------------------
void CMatrix4x4::RotateFromArbitraryAxisMatrix(float Angle,float x,float y,float z,float *m)
{
   /* This function contributed by Erich Boleyn (erich@uruk.org) */
   float mag, s, c;
   float xx, yy, zz, xy, yz, zx, xs, ys, zs, one_c;

   s = sin( Angle );
   c = cos( Angle );

   mag = MATH_Common::fSqrt( x*x + y*y + z*z );

   if (mag == 0.0) {
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
    *  represents the sines and cosines of the angles to rotate the
    *  X-axis to the same orientation, with theta being the angle about
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
//-------------------------------------------------------------------
// Multiplica M * N
//-------------------------------------------------------------------
// Algorithm:
//	For each row of M
//		For each col of N
//          ResMatrix(Row,Col) = DotProduct ( RowVector(M,Row) , ColVector(N,Col) )
//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
void CMatrix4x4::Multiply(CMatrix4x4 &A,CMatrix4x4 &B)
{
	int i,j;

    // Para cada fila
	for (i=0;i<4;i++)
    	// Para cada columna
		for (j=0;j<4;j++)
		{
            M(i,j) = A.M(i,0)*B.M(0,j) +
            		 A.M(i,1)*B.M(1,j) +
                     A.M(i,2)*B.M(2,j) +
                     A.M(i,3)*B.M(3,j);
        }
}
//---------------------------------------------------------------------------
// Computes this * B matrix multiplication
//---------------------------------------------------------------------------
void CMatrix4x4::MultiplyBy(CMatrix4x4 &B)
{
	int i,j;
    CMatrix4x4 A =*this;

    // Para cada fila
	for (i=0;i<4;i++)
    	// Para cada columna
		for (j=0;j<4;j++)
		{
            M(i,j)= A.M(i,0)*B.M(0,j) +
            		A.M(i,1)*B.M(1,j) +
                    A.M(i,2)*B.M(2,j) +
                    A.M(i,3)*B.M(3,j);
        }
}
//---------------------------------------------------------------------------
// Multiplicacion 	Matriz*vector
//---------------------------------------------------------------------------
//              a
// A  - - - -   |  = (A.a,B.a,C.a,D.a)
// B  - - - - * |
// C  - - - -   |  =  - - - -
// D  - - - -   |
//---------------------------------------------------------------------------
// Dot product entre point4D (x,y,z,1) y matrix
//---------------------------------------------------------------------------
void CMatrix4x4::TransformPoint (CVect3 &Vect)
{
	int i;
    CVect3 v = Vect;

    // Optimized version
    for (i=0;i<3;i++)
    {
    	// Hacer dot product del vector y la fila
    	Vect.v[i] = M(i,0) * v.v[0] +
        		    M(i,1) * v.v[1] +
                    M(i,2) * v.v[2] +
                    M(i,3) /* * (v.v[3) = 1) */ ;
    }
}
//---------------------------------------------------------------------------
// Dot product entre vector4D (x,y,z,0) y matrix
//---------------------------------------------------------------------------
void CMatrix4x4::TransformVector(CVect3 &Vect)
{
	// Make a copy of the source point
	CVect3 v = Vect;
	int    i;

    // Optimized version
    for (i=0;i<3;i++)
    {
    	// Hacer dot product del vector y la fila
    	Vect.v[i] = M(i,0) * v.v[0] + 
					M(i,1) * v.v[1] + 
					M(i,2) * v.v[2];
               // + M(i,3) * (v.v[3] = 0) */;
    }
}
//---------------------------------------------------------------------------
CVect4 CMatrix4x4::GetRowVector(int Row)
{
	CVect4 Res;
    Res.v[0] = M(Row,0);
    Res.v[1] = M(Row,1);
    Res.v[2] = M(Row,2);
    Res.v[3] = M(Row,3);
    return(Res);
}
//---------------------------------------------------------------------------
CVect4 CMatrix4x4::GetColVector(int Col)
{
	CVect4 Res;
    Res.v[0] = M(0,Col);
    Res.v[1] = M(1,Col);
    Res.v[2] = M(2,Col);
    Res.v[3] = M(3,Col);
    return(Res);
}
//---------------------------------------------------------------------------
void CMatrix4x4::SetRowVector(int Row,float x,float y,float z,float w)
{
    M(Row,0) = x;
	M(Row,1) = y;
	M(Row,2) = z;
	M(Row,3) = w;
}

void CMatrix4x4::SetColVector(int Col,float x,float y,float z,float w)
{
    M(0,Col) = x;
	M(1,Col) = y;
	M(2,Col) = z;
	M(3,Col) = w;
}
//---------------------------------------------------------------------------
void CMatrix4x4::Transpose()
{
	// axiliary matrix
	float	aux[16];
	memcpy(aux,m,16*sizeof(float));

	m[0*4+0] = aux[0*4+0];
	m[1*4+0] = aux[0*4+1];
	m[2*4+0] = aux[0*4+2];
	m[3*4+0] = aux[0*4+3];
	
	m[0*4+1] = aux[1*4+0];
	m[1*4+1] = aux[1*4+1];
	m[2*4+1] = aux[1*4+2];
	m[3*4+1] = aux[1*4+3];

	m[0*4+2] = aux[2*4+0];
	m[1*4+2] = aux[2*4+1];
	m[2*4+2] = aux[2*4+2];
	m[3*4+2] = aux[2*4+3];
	
	m[0*4+3] = aux[3*4+0];
	m[1*4+3] = aux[3*4+1];
	m[2*4+3] = aux[3*4+2];
	m[3*4+3] = aux[3*4+3];
}
//---------------------------------------------------------------------------
float CMatrix4x4::Determinant()
{
    return(
           (
           M(0,0)*M(1,1)*M(2,2)*M(3,3) + M(0,1)*M(1,2)*M(2,3)*M(3,0) +
           M(0,2)*M(1,3)*M(2,0)*M(3,1) + M(0,3)*M(1,0)*M(2,1)*M(3,2)
           )
           -
           (
           M(0,3)*M(1,2)*M(2,1)*M(3,0) + M(0,2)*M(1,1)*M(2,0)*M(3,3) +
           M(0,1)*M(1,0)*M(2,3)*M(3,2) + M(0,0)*M(1,3)*M(2,2)*M(3,1)
		   )
		  );
}
//---------------------------------------------------------------------------
void CMatrix4x4::Complementary()
{
    unsigned char Matrix3x3SelTable[4][3] = {{1,2,3},{0,2,3},{0,1,3},{0,1,2}};
    unsigned char cC0,cC1,cC2,cR0,cR1,cR2;
    unsigned char cRow,cCol;

    float fDet;
    CMatrix4x4 O = *this;

    for (cRow=0;cRow<4;cRow++)
    {
    	cR0 = Matrix3x3SelTable[cRow][0];
        cR1 = Matrix3x3SelTable[cRow][1];
        cR2 = Matrix3x3SelTable[cRow][2];

    	for (cCol=0;cCol<4;cCol++)
        {
        	// Adjoint A(i,j) (take out i row j col of A)
    		cC0 = Matrix3x3SelTable[cCol][0];
        	cC1 = Matrix3x3SelTable[cCol][1];
        	cC2 = Matrix3x3SelTable[cCol][2];

    		// Compute the determinant of the current adjoint matrix
            fDet =(
            		O.M(cR0,cC0)*O.M(cR1,cC1)*O.M(cR2,cC2) +
            	    O.M(cR0,cC1)*O.M(cR1,cC2)*O.M(cR2,cC0) +
                    O.M(cR0,cC2)*O.M(cR1,cC0)*O.M(cR2,cC1)
                  )
                  -
                  (
                  	O.M(cR0,cC2)*O.M(cR1,cC1)*O.M(cR2,cC0) +
                    O.M(cR0,cC1)*O.M(cR1,cC0)*O.M(cR2,cC2) +
        			O.M(cR0,cC0)*O.M(cR1,cC2)*O.M(cR2,cC1)
            	  );
            // Compute sign: Sgn = (-1)^(i+j)
            if ((cRow+cCol)& 0x01) fDet *= -1;

            // Store the computed value
            M(cRow,cCol) = O.M(cRow,cCol) * fDet;
        }
	}
}
//---------------------------------------------------------------------------
//   -1    1
// M    =  -  * Adj(M)
//        |M|
//---------------------------------------------------------------------------
void CMatrix4x4::Inverse()
{
	float fDet = Determinant();

    if (! fDet) return;

    unsigned int cRow,cCol;

    Transpose();
	Complementary();
    
    fDet = 1.0f/fDet;

    for (cRow=0;cRow<4;cRow++)
		for (cCol=0;cCol<4;cCol++)
        	M(cRow,cCol) *= fDet;
}
//---------------------------------------------------------------------------
// Performs the inverse of a rotation & translation matrix
//---------------------------------------------------------------------------
void CMatrix4x4::RTInverse()
{		
	// auxiliary matrix
	float aux[16];
	memcpy(aux,m,16*sizeof(float));

	// Inverse of the rotation
	M(0,0)  = aux[4*0+0];
	M(0,1)  = aux[4*0+1];
	M(0,2)  = aux[4*0+2];
	
	M(1,0)  = aux[4*1+0];
	M(1,1)  = aux[4*1+1];
	M(1,2)  = aux[4*1+2];
	
	M(2,0)  = aux[4*2+0];
	M(2,1)  = aux[4*2+1];
	M(2,2)  = aux[4*2+2];

	// Inverse of the translation: 
	// From Mesa 3.2: matrix.c invert_matrix_3d

	//  x = Dot( Input.Col(3),Output.Row(0) )
	//  y = Dot( Input.Col(3),Output.Row(1) )
	//  z = Dot( Input.Col(3),Output.Row(2) )
	
	M(0,3) = - (aux[3*4+0] * M(0,0) + aux[3*4+1] * M(0,1) + aux[3*4+2] * M(0,2) );
	M(1,3) = - (aux[3*4+0] * M(1,0) + aux[3*4+1] * M(1,1) + aux[3*4+2] * M(1,2) );
	M(2,3) = - (aux[3*4+0] * M(2,0) + aux[3*4+1] * M(2,1) + aux[3*4+2] * M(2,2) );	
}
//---------------------------------------------------------------------------
float CMatrix4x4::f3ColDeterminant(int iCol0,int iCol1, int iCol2)
{
	return(
           (M(0,iCol0)*M(1,iCol1)*M(2,iCol2) + 
			M(0,iCol1)*M(1,iCol2)*M(2,iCol0) +
			M(0,iCol2)*M(1,iCol0)*M(2,iCol1))
			-							
           (M(0,iCol2)*M(1,iCol1)*M(2,iCol0)+
		    M(0,iCol0)*M(1,iCol2)*M(2,iCol1)+
		    M(0,iCol1)*M(1,iCol0)*M(2,iCol2))
		  );
}
//---------------------------------------------------------------------------

#undef M(Row,Col)
