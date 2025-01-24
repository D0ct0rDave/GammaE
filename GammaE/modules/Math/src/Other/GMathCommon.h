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
#ifndef CommonH
#define CommonH
// ----------------------------------------------------------------------------
namespace Math {
// ----------------------------------------------------------------------------
#define _PI_          3.1415926535897932384626433832795f
#define _2PI_         6.283185307179586476925286766558f
#define _PI2_         1.5707963267948966192313216916395f
#define _PI_OVER_180_ 0.0174532925199432957692369076848833f
#define _180_OVER_PI_ 57.2957795130823208767981548141052f

#define _SQ_(x) ( (x) * (x) )
#define _P2_(x) ( (x) * (x) )
#define _P3_(x) ( (x) * (x) * (x) )
#define _P4_(x) ( (x) * (x) * (x) * (x) )

#define _EPSILON_ 1e-5f
#define _INFINITE_ 1e12f
// ----------------------------------------------------------------------------
float fRand();

float fSRand();

float fSqrt(float _fValue);

float fSin(float _fValue);

float fCos(float _fValue);

float fTan(float _fValue);

float fArcTan(float _fValue);

float fAbs(float _fValue);

float fSign(float _fValue);

bool bInRange(float _fValue, float _fMin, float _fMax);

bool bEqual(float _fA, float _fB, float _fEpsilon = 1e-3f);

float fClamp(float _fA,float _fB,float _fValue);

float fMin(float a,float b);

float fMax(float a,float b);

float fMod(float a,float b);

float fFloor(float x);

float fCeil(float x);

float fLerp(float a,float b,float f);
// ----------------------------------------------------------------------------
inline float fAbs(float _fValue)
{
    *( (unsigned int*)&_fValue ) &= 0x7fffffff;
    return(_fValue);
}
// ----------------------------------------------------------------------------
inline float fSign(float _fValue)
{
    return ( (*( (unsigned int*)&_fValue ) >> 31) * -2.0f + 1.0f );
}
// ----------------------------------------------------------------------------
inline bool bInRange(float _fValue, float _fMin, float _fMax)
{
    return ( (_fValue >= _fMin) && (_fValue <= _fMax) );
}
// ----------------------------------------------------------------------------
inline bool bEqual(float _fA, float _fB, float _fEpsilon )
{
    return (fAbs(_fA - _fB) < _fEpsilon);
}
// ----------------------------------------------------------------------------
inline float fClamp(float _fA,float _fB,float _fValue)
{
    if ( _fValue < _fA )
        return(_fA);

    if ( _fValue > _fB )
        return(_fB);
    else
        return(_fValue);
}
// ----------------------------------------------------------------------------
inline float fMin(float a,float b)
{
    return(a < b?a:b);
}
// ----------------------------------------------------------------------------
inline float fMax(float a,float b)
{
    return(a < b?b:a);
}
// ----------------------------------------------------------------------------
inline float fFloor(float x)
{
    return( (float)( (int)x - ( (x < 0) && (x != (int)x) ) ) );
}
// ----------------------------------------------------------------------------
inline float fCeil(float x)
{
    return( (float)( (int)x - ( (x > 0) && (x != (int)x) ) ) );
}
// ----------------------------------------------------------------------------
inline float fLerp(float a,float b,float f)
{
    return(a + (b - a) * f);
}
// ----------------------------------------------------------------------------
}; // namespace Math
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
