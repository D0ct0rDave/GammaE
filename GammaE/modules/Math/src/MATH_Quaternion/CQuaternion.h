//-----------------------------------------------------------------------------
#ifndef CQuaternion_h
#define CQuaternion_h 1
//-----------------------------------------------------------------------------
#include "..\MATH_Other\MATH_Common.h"
//-----------------------------------------------------------------------------
#include "..\MATH_Matrix\CMatrix4x4.h"
#include "..\MATH_Vector\CVect4.h"
#include "..\MATH_Vector\CVect3.h"
//-----------------------------------------------------------------------------
class CQuaternion 
{
  public:
      void Slerp (CQuaternion& _Src, CQuaternion& _Dst, float _fFactor);

      
      CMatrix4x4 & ToMatrix ();

      
      void FromMatrix(CMatrix4x4 &_Matrix);
      void FromVector(CVect4& _Vect);
	  void FromComponents(CVect3& _Vect,float _fRotation);
    
  private:
      float quat[4];

};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
