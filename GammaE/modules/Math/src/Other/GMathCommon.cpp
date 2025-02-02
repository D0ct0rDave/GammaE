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
#include <stdlib.h>
#include <math.h>
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------

#ifdef __BORLANDC__
    #define sqrtf sqrt
    #define cosf  cos
    #define sinf  sin
    #define tanf  tan
    #define atanf atan
#endif

// Common
#include "Other\GMathCommon.h"

// ----------------------------------------------------------------------------
namespace Math {
// ----------------------------------------------------------------------------
union FastSqrtUnion
{
    float d;
    unsigned long i;
};

// declare table of square roots
static bool SqrtBuilt = false;
static uint FastSqrtTable[0x10000];

void BuildSqrtTable()
{
    unsigned long i;
    FastSqrtUnion s;

    for ( i = 0; i <= 0x7FFF; i++ )
    {
        // Build a float with the bit pattern i as mantissa
        // and an exponent of 0, stored as 127
        s.i = (i << 8) | (0x7F << 23);
        s.d = (float)sqrt(s.d);

        // Take the square root then strip the first 7 bits of
        // the mantissa into the table
        FastSqrtTable[i + 0x8000] = (s.i & 0x7FFFFF);

        // Repeat the process, this time with an exponent of 1,
        // stored as 128
        s.i = (i << 8) | (0x80 << 23);
        s.d = (float)sqrt(s.d);
        FastSqrtTable[i] = (s.i & 0x7FFFFF);
    }

    FastSqrtTable[0] = 0x1f800000;
    SqrtBuilt = true;
}
// ----------------------------------------------------------------------------
float fRand ()
{
    return ( (float)rand() / (float)RAND_MAX );
}
// ----------------------------------------------------------------------------
float fSRand()
{
    return ( (2.0f * (float)rand() / (float)RAND_MAX) - 1.0f );
}
// ----------------------------------------------------------------------------
float fSqrt (float _fValue)
{
    // #ifdef __BORLANDC__
    return( sqrtf(_fValue) );
    // #endif

    if ( !SqrtBuilt ) BuildSqrtTable();

    *(int*)&_fValue = FastSqrtTable[(*(int*)&_fValue >> 8) & 0xFFFF] ^ ( ( ( (*(int*)&_fValue - 0x3F800000) >> 1 ) + 0x3F800000 ) & 0x7F800000 );

    return(_fValue);
}
// ----------------------------------------------------------------------------
float fSin (float _fValue)
{
    return( sinf(_fValue) );
}
// ----------------------------------------------------------------------------
float fCos (float _fValue)
{
    return( cosf(_fValue) );
}
// ----------------------------------------------------------------------------
float fTan (float _fValue)
{
    return( tanf(_fValue) );
}
// ----------------------------------------------------------------------------
float fArcTan (float _fValue)
{
    return( atanf(_fValue) );
}
// ----------------------------------------------------------------------------
float fMod(float a,float b)
{
    a -= b * (int)(a / b);
    if ( a < 0 ) a += b;
    return(a);
}
// ----------------------------------------------------------------------------
}; // namespace Math
// ----------------------------------------------------------------------------
