//-----------------------------------------------------------------------------
#ifndef MATH_Common_h
#define MATH_Common_h 1
//-----------------------------------------------------------------------------
#define _PI_		  3.1415926535897932384626433832795f
#define _2PI_		  6.283185307179586476925286766558f
#define _PI2_		  1.5707963267948966192313216916395f
#define _PI_OVER_180_ 0.0174532925199432957692369076848833f
#define _180_OVER_PI_ 57.2957795130823208767981548141052f

#define _SQ_(x) ((x)*(x))
#define _P2_(x) ((x)*(x))
#define _P3_(x) ((x)*(x)*(x))
#define _P4_(x) ((x)*(x)*(x)*(x))

#define _EPSILON_ 1e-5f
//-----------------------------------------------------------------------------
class MATH_Common 
{
	public:

		static float fRand();
		
		static float fSRand();

		static float fSqrt(float _fValue);

		static float fSin(float _fValue);

		static float fCos(float _fValue);

		static float fTan(float _fValue);

		static float fArcTan(float _fValue);

		static float fAbs(float _fValue);

		static float fSign(float _fValue);

		static bool bInRange(float _fValue, float _fMin, float _fMax);

		static bool bEqual(float _fA, float _fB, float _fEpsilon = 1e-3f);

		static float fClamp(float _fA,float _fB,float _fValue);

		static float fMin(float a,float b);

		static float fMax(float a,float b);

		static float fMod(float a,float b);

		static float fFloor(float x);

		static float fCeil (float x);

		static float fLerp(float a,float b,float f);
};
//-----------------------------------------------------------------------------
inline float MATH_Common::fAbs(float _fValue)
{
	*((unsigned int*)&_fValue) &= 0x7fffffff;
	return(_fValue); 
}
//-----------------------------------------------------------------------------
inline float MATH_Common::fSign(float _fValue)
{
	return ( (*((unsigned int*)&_fValue) >> 31)*-2.0f + 1.0f);  
}
//-----------------------------------------------------------------------------
inline bool MATH_Common::bInRange(float _fValue, float _fMin, float _fMax)
{  
	return ((_fValue >= _fMin) && (_fValue<=_fMax)); 
}
//-----------------------------------------------------------------------------
inline bool MATH_Common::bEqual(float _fA, float _fB, float _fEpsilon )
{  
	return ( MATH_Common::fAbs(_fA - _fB) < _fEpsilon ); 
}
//-----------------------------------------------------------------------------
inline float MATH_Common::fClamp(float _fA,float _fB,float _fValue)
{
	if (_fValue<_fA)
		return(_fA);

	if (_fValue>_fB)
		return(_fB);
	else
		return(_fValue);		
}
//-----------------------------------------------------------------------------
inline float MATH_Common::fMin(float a,float b)
{
    return(a<b?a:b);
}
//-----------------------------------------------------------------------------
inline float MATH_Common::fMax(float a,float b)
{
    return(a<b?b:a);
}
//-----------------------------------------------------------------------------
inline float MATH_Common::fFloor(float x)
{
	return( (float)((int)x - ((x<0) && (x!=(int)x))) );
}
//-----------------------------------------------------------------------------
inline float MATH_Common::fCeil(float x)
{
	return( (float)((int)x - ((x>0) && (x!=(int)x))) );
}
//-----------------------------------------------------------------------------
inline float MATH_Common::fLerp(float a,float b,float f)
{
	return(a + (b-a)*f);
}
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
