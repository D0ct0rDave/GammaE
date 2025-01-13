//## begin module%3B9E7C9F013E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9E7C9F013E.cm

//## begin module%3B9E7C9F013E.cp preserve=no
//## end module%3B9E7C9F013E.cp

//## Module: CQuaternion%3B9E7C9F013E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Math\MATH_Quaternion\CQuaternion.cpp

//## begin module%3B9E7C9F013E.additionalIncludes preserve=no
//## end module%3B9E7C9F013E.additionalIncludes

//## begin module%3B9E7C9F013E.includes preserve=yes
	/*
	Quaternion code extracted from "Advance OpenGL MD3Load"
	Author	: Mustata Bogdan (LoneRunner)
	Contact	: lonerunner@planetquake.com

	NOTE: Be careful in his code 
		MAT ( row,col) and in GammaE CMatrix4x4.Get(Col,Row)
	*/
	#include <math.h>	

//## end module%3B9E7C9F013E.includes

// CQuaternion
#include "Math\MATH_Quaternion\CQuaternion.h"
//## begin module%3B9E7C9F013E.additionalDeclarations preserve=yes
	#define X 0
	#define Y 1
	#define Z 2
	#define W 3
	#define QUAT_EPSILON 0.1f
//## end module%3B9E7C9F013E.additionalDeclarations


// Class CQuaternion 


CQuaternion::CQuaternion()
  //## begin CQuaternion::CQuaternion%.hasinit preserve=no
  //## end CQuaternion::CQuaternion%.hasinit
  //## begin CQuaternion::CQuaternion%.initialization preserve=yes
  //## end CQuaternion::CQuaternion%.initialization
{
  //## begin CQuaternion::CQuaternion%.body preserve=yes
  //## end CQuaternion::CQuaternion%.body
}



//## Other Operations (implementation)
void CQuaternion::Slerp (CQuaternion& _Src, CQuaternion& _Dst, float _fFactor)
{
  //## begin CQuaternion::Slerp%1000239577.body preserve=yes
	static float        to1[4];
	static float        omega, cosom, sinom, scale0, scale1;

	// calc cosine
	cosom = _Src.quat[X]*_Dst.quat[X] + 
			_Src.quat[Y]*_Dst.quat[Y] + 
			_Src.quat[Z]*_Dst.quat[Z] + 
			_Src.quat[W]*_Dst.quat[W];

	// adjust signs (if necessary)
	if ( cosom < 0.0 )
	{ 
		  cosom  = -cosom; 
		  to1[0] = - _Dst.quat[X];
          to1[1] = - _Dst.quat[Y];
          to1[2] = - _Dst.quat[Z];
          to1[3] = - _Dst.quat[W];
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
          omega  = (float)acos(cosom);
          sinom  = (float)sin(omega);
          scale0 = (float)sin((1.0f - _fFactor) * omega) / sinom;
          scale1 = (float)sin(_fFactor * omega) / sinom;
	} 
	else
	{        
      // "from" and "to" quaternions are very close 
      //  ... so we can do a linear interpolation
          scale0 = 1.0f - _fFactor;
          scale1 = _fFactor;
	}

	// calculate final values
	quat[X] = scale0 * _Src.quat[X] + scale1 * to1[0];
	quat[Y] = scale0 * _Src.quat[Y] + scale1 * to1[1];
	quat[Z] = scale0 * _Src.quat[Z] + scale1 * to1[2];
	quat[W] = scale0 * _Src.quat[W] + scale1 * to1[3];
  //## end CQuaternion::Slerp%1000239577.body
}

CMatrix4x4 & CQuaternion::ToMatrix ()
{
  //## begin CQuaternion::ToMatrix%1000239578.body preserve=yes
	static		 CMatrix4x4 Mat;
	static float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;
             
	// calculate coefficients
	    
	x2 = quat[X] + quat[X]; 
	y2 = quat[Y] + quat[Y]; 
	z2 = quat[Z] + quat[Z];
	xx = quat[X] * x2;   xy = quat[X] * y2;   xz = quat[X] * z2;
	yy = quat[Y] * y2;   yz = quat[Y] * z2;   zz = quat[Z] * z2;
	wx = quat[W] * x2;   wy = quat[W] * y2;   wz = quat[W] * z2;

	Mat.Set(0,0,1.0f - (yy + zz));   Mat.Set(0,1,        xy - wz);
	Mat.Set(0,2,         xz + wy);   Mat.Set(0,3,           0.0f);
                  
	Mat.Set(1,0,         xy + wz);   Mat.Set(1,1,1.f - (xx + zz));
	Mat.Set(1,2,         yz - wx);   Mat.Set(1,3,           0.0f);

	Mat.Set(2,0,         xz - wy);   Mat.Set(2,1,        yz + wx);
	Mat.Set(2,2,1.0f - (xx + yy));   Mat.Set(2,3,           0.0f);

	Mat.Set(3,0,            0.0f);   Mat.Set(3,1,           0.0f);
	Mat.Set(3,2,            0.0f);   Mat.Set(3,3,           1.0f);

	return (Mat);
  //## end CQuaternion::ToMatrix%1000239578.body
}

void CQuaternion::FromMatrix (CMatrix4x4 &_Matrix)
{
  //## begin CQuaternion::FromMatrix%1000239579.body preserve=yes
	static float  tr, s, q[4];
	static int    i, j, k;
	static int	  nxt[3];  

	nxt[0] = 1;
	nxt[1] = 2;
	nxt[2] = 0;

	tr = _Matrix.Get(0,0) + _Matrix.Get(1,1) + _Matrix.Get(2,2);

	// check the diagonal
	if (tr > 0.0)
	{
		s = (float)MATH_Common::fSqrt(tr + 1.f);
		quat[W] = s / 2.0f;
		s = 0.5f / s;
		
		quat[X] = (_Matrix.Get(1,2) - _Matrix.Get(2,1)) * s;
		quat[Y] = (_Matrix.Get(2,0) - _Matrix.Get(0,2)) * s;
		quat[Z] = (_Matrix.Get(0,1) - _Matrix.Get(1,0)) * s;
	} 
	else
	{                
		// diagonal is negative
		i = 0;
		
		if (_Matrix.Get(1,1) > _Matrix.Get(0,0)) i = 1;
		if (_Matrix.Get(2,2) > _Matrix.Get(i,i)) i = 2;

		j = nxt[i];
		k = nxt[j];

	    s = (float)MATH_Common::fSqrt( (_Matrix.Get(i,i) - (_Matrix.Get(j,j) + _Matrix.Get(k,k)) ) + 1.0);
                       
		q[i] = s * (float)0.5;
                             
		if (s != 0.0f) s = 0.5f / s;

		q[3] = (_Matrix.Get(i,k) - _Matrix.Get(k,j)) * s;
		q[j] = (_Matrix.Get(i,j) + _Matrix.Get(j,i)) * s;
		q[k] = (_Matrix.Get(i,k) + _Matrix.Get(k,i)) * s;

		quat[X] = q[0];
		quat[Y] = q[1];
		quat[Z] = q[2];
		quat[W] = q[3];
	}
  //## end CQuaternion::FromMatrix%1000239579.body
}

// Additional Declarations
  //## begin CQuaternion%3B9E7C9F013E.declarations preserve=yes
  	#undef	X
	#undef  Y
	#undef  Z
	#undef  W
	#undef  QuatEpsilon
  //## end CQuaternion%3B9E7C9F013E.declarations
//## begin module%3B9E7C9F013E.epilog preserve=yes
//## end module%3B9E7C9F013E.epilog
