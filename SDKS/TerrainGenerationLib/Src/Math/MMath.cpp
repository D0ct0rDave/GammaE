//---------------------------------------------------------------------------
// Based on the text contents of the book
// Texturing and Modeling a procedural approach
//---------------------------------------------------------------------------
#include "MMath.h"
#include <math.h>

float MMath_Step(float a,float x)
{
    return( (float)(x>=a) );
}

float MMath_Pulse(float x,float a,float b)
{
    return(MMath_Step(a,x) - MMath_Step(b,x));
}

float MMath_Clamp(float x,float a,float b)
{
    return( (x<a)?a:((x>b)?b:x) );
}

float MMath_Min(float a,float b)
{
    return(a<b?a:b);
}

float MMath_Max(float a,float b)
{
    return(a<b?b:a);
}

float MMath_Abs(float x)
{
    return(x<0?-x:x);
}

float MMath_Sgn(float x)
{
    if (x<0) return(-1.0f); else return(1.0f);
}

float MMath_SmoothStep(float x,float a,float b)
{
    if (x<a) return(0);
    if (x>=b) return(1);
    x = (x-a)/(b-a);
    return(x*x*(3 - 2*x));
}

float MMath_Mod(float a,float b)
{
    a -= b*(int)(a/b);
    if (a<0) a+=b;
    return(a);
}

float MMath_Floor(float x)
{
   return( (int)x - ((x<0) && (x!=(int)x)) );
}

float MMath_Ceil(float x)
{
    return( (int)x - ((x>0) && (x!=(int)x)) );
}

float MMath_GammaCorrect(float Gamma,float x)
{
    return (pow(x,1.0f/Gamma));
}

float MMath_Bias(float Bias,float x)
{
    return ( pow(x,log(Bias)/log(0.5f)) );
}

float MMath_Gain(float Gain,float x)
{
    if (x<0.5f)
        return(MMath_Bias(1-Gain,2*x)/2.0f);
    else
        return (1.0f - MMath_Bias(1-Gain,2 - 2*x)/2 );
}
//---------------------------------------------------------------------------
float MMath_Lerp(float t,float x0,float x1)
{
	return(x0 + (x1-x0)*t);
}
//---------------------------------------------------------------------------
#define CR00 (float) -1.0f
#define CR01 (float)  3.0f
#define CR02 (float) -3.0f
#define CR03 (float)  1.0f

#define CR10 (float)  3.0f
#define CR11 (float) -6.0f
#define CR12 (float)  3.0f
#define CR13 (float)  0.0

#define CR20 (float) -3.0f
#define CR21 (float)  3.0f
#define CR22 (float)  0.0
#define CR23 (float)  0.0

#define CR30 (float)  1.0f
#define CR31 (float)  0.0
#define CR32 (float)  0.0
#define CR33 (float)  0.0

float MMath_Spline(float x,int NumKnots,float *Knot)
{
    int Span;
    int NumSpans = NumKnots - 3;

    if (NumSpans<1) return(0); // illegal number of knots

    // Find the appropriate 4 point span of the spline
    x = MMath_Clamp(x,0,1)*NumSpans;

    Span = (int)x;
    if (Span >= NumKnots - 3) return(Knot[NumKnots-1]);

    x    -= Span;
    Knot += Span;

    // Evaluate the span cubic at x using Horner's rule
    return( MMath_Spline4Knots( x , Knot) );
}
//---------------------------------------------------------------------------
// Values in range 0..1 only for 4 knots
float MMath_Spline4Knots(float x,float *Knot)
{
    float c0,c1,c2,c3;  // Coefficients of the cubic

    // Evaluate the span cubic at x using Horner's rule
    c3 = CR00*Knot[0] + CR01*Knot[1] + CR02*Knot[2] + CR03*Knot[3];
    c2 = CR10*Knot[0] + CR11*Knot[1] + CR12*Knot[2] + CR13*Knot[3];
    c1 = CR20*Knot[0] + CR21*Knot[1] + CR22*Knot[2] + CR23*Knot[3];
    c0 = CR30*Knot[0] + CR31*Knot[1] + CR32*Knot[2] + CR33*Knot[3];

    return( ((c3*x + c2)*x + c1)*x + c0);
}
//---------------------------------------------------------------------------
union MMath_FastSqrtUnion
{
	float 		  d;
    unsigned long i;
};

static int MMath_SqrtBuilt = 0;

// declare table of square roots
static unsigned long MMath_FastSqrtTable[0x10000];

void MMath_BuildSqrtTable()
{
	unsigned long i;
    MMath_FastSqrtUnion s;

    for (i = 1; i <= 0x7FFF; i++)
    {
	    // Build a float with the bit pattern i as mantissa
    	// and an exponent of 0, stored as 127
        s.i = (i << 8) | (0x7F << 23);
	    s.d = (float)sqrt(s.d);

    	// Take the square root then strip the first 7 bits of
	    // the mantissa into the table
	    MMath_FastSqrtTable[i + 0x8000] = (s.i & 0x7FFFFF);

	    // Repeat the process, this time with an exponent of 1,
        // stored as 128
    	s.i = (i << 8) | (0x80 << 23);
        s.d = (float)sqrt(s.d);
    	MMath_FastSqrtTable[i] = (s.i & 0x7FFFFF);
    }

    MMath_FastSqrtTable[0] = 0x1f800000;
    MMath_SqrtBuilt        = true;
}

float MMath_Sqrt(float x)
{
#ifdef _DEBUG
	return ( sqrt(x) );
#else
	if (! MMath_SqrtBuilt) MMath_BuildSqrtTable();

	*(int*)&x = MMath_FastSqrtTable[(*(int *)&x >> 8) & 0xFFFF] ^ ((((*(int*)&x - 0x3F800000) >> 1) + 0x3F800000) & 0x7F800000);
	return x;
#endif
}

//---------------------------------------------------------------------------