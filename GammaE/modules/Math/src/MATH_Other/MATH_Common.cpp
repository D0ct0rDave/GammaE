//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <math.h>
//-----------------------------------------------------------------------------

#ifdef __BORLANDC__
#define sqrtf sqrt
#define sinf  sin
#define cosf  cos
#define tanf  tan
#define atanf atan
#endif

// MATH_Common
#include "MATH_Other\MATH_Common.h"

//-----------------------------------------------------------------------------
union MATH_FastSqrtUnion
{
	float 		  d;
    unsigned long i;
};

// declare table of square roots
static bool			MATH_SqrtBuilt = false;
static unsigned int MATH_FastSqrtTable[0x10000];

void MATH_BuildSqrtTable()
{
	unsigned long		i;
    MATH_FastSqrtUnion	s;

    for (i = 0; i <= 0x7FFF; i++)
    {
	    // Build a float with the bit pattern i as mantissa
    	// and an exponent of 0, stored as 127
        s.i = (i << 8) | (0x7F << 23);
	    s.d = (float)sqrt(s.d);

    	// Take the square root then strip the first 7 bits of
	    // the mantissa into the table
	    MATH_FastSqrtTable[i + 0x8000] = (s.i & 0x7FFFFF);

	    // Repeat the process, this time with an exponent of 1,
        // stored as 128
    	s.i = (i << 8) | (0x80 << 23);
        s.d = (float)sqrt(s.d);
    	MATH_FastSqrtTable[i] = (s.i & 0x7FFFFF);
}

    MATH_FastSqrtTable[0] = 0x1f800000;
    MATH_SqrtBuilt        = true;
}
//-----------------------------------------------------------------------------
float MATH_Common::fRand ()
{
  	return ((float)rand()/(float)RAND_MAX);
}
//-----------------------------------------------------------------------------
float MATH_Common::fSRand()
{
  	return ( (2.0f * (float)rand()/(float)RAND_MAX) - 1.0f);
}
//-----------------------------------------------------------------------------
float MATH_Common::fSqrt (float _fValue)
{
      // #ifdef __BORLANDC__
    return(sqrtf(_fValue));
    // #endif

	if (! MATH_SqrtBuilt) MATH_BuildSqrtTable();

	*(int*)&_fValue = MATH_FastSqrtTable[(*(int *)&_fValue >> 8) & 0xFFFF] ^ ((((*(int*)&_fValue - 0x3F800000) >> 1) + 0x3F800000) & 0x7F800000);

	return _fValue;
}
//-----------------------------------------------------------------------------
float MATH_Common::fSin (float _fValue)
{
  	return(sinf(_fValue));
}
//-----------------------------------------------------------------------------
float MATH_Common::fCos (float _fValue)
{
  	return(cosf(_fValue));
}
//-----------------------------------------------------------------------------
float MATH_Common::fTan (float _fValue)
{
  	return(tanf(_fValue));
}
//-----------------------------------------------------------------------------
float MATH_Common::fArcTan (float _fValue)
{
  	return(atanf(_fValue));
}
//-----------------------------------------------------------------------------
float MATH_Common::fMod(float a,float b)
{
    a -= b*(int)(a/b);
    if (a<0) a+=b;
    return(a);
}
//-----------------------------------------------------------------------------

