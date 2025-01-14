//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../Math/MMath.h"
#include "noise.h"


float bias(float a, float b)

{

	return powf(a, logf(b) / logf(0.5f));

}



float gain(float a, float b)

{

	float p = logf(1.0f - b) / logf(0.5f);



	if (a < 0.001f)

		return 0.0f;

	else if (a > 0.999f)

		return 1.0f;

	if (a < 0.5f)

		return powf(2.0f * a, p) / 2.0f;

	else

		return 1.0f - powf(2.0f * (1.0f - a), p) / 2.0f;

}



float Perlin_noise1(float arg);

float Perlin_noise2(float vec[]);

float Perlin_noise3(float vec[]);

float Perlin_noise(float vec[], int len)
{
	switch (len) {

	case 0:

		return 0.;

	case 1:

		return Perlin_noise1(vec[0]);

	case 2:

		return Perlin_noise2(vec);

	default:

		return Perlin_noise3(vec);

	}

}



float turbulence(float *v, float freq)

{

	float t, vec[3];



	for (t = 0. ; freq >= 1. ; freq /= 2) {

		vec[0] = freq * v[0];

		vec[1] = freq * v[1];

		vec[2] = freq * v[2];

		t += fabs(Perlin_noise3(vec)) / freq;

	}

	return t;

}



/* noise functions over 1, 2, and 3 dimensions */



#define B 0x100

#define BM 0xff

#define N 0x1000

#define NP 12   /* 2^N */

#define NM 0xfff



static int p[B + B + 2];

static float g3[B + B + 2][3];

static float g2[B + B + 2][2];

static float g1[B + B + 2];

static int start = 1;



static void Perlin_Init();



#define s_curve(t) ( t * t * (3. - 2. * t) )



#define lerp(t, a, b) ( a + t * (b - a) )



#define setup(i,b0,b1,r0,r1)\
	t = vec[i] + N;\
	b0 = ((int)t) & BM;\
	b1 = (b0+1) & BM;\
	r0 = t - (int)t;\
	r1 = r0 - 1.;



float Perlin_noise1(float arg)

{

	int bx0, bx1;

	float rx0, rx1, sx, t, u, v, vec[1];



	vec[0] = arg;

	if (start) {

		start = 0;

		Perlin_Init();

	}



	setup(0, bx0,bx1, rx0,rx1);



	sx = s_curve(rx0);



	u = rx0 * g1[ p[ bx0 ] ];

	v = rx1 * g1[ p[ bx1 ] ];



	return lerp(sx, u, v);

}



float Perlin_noise2(float vec[2])

{

	int bx0, bx1, by0, by1, b00, b10, b01, b11;

	float rx0, rx1, ry0, ry1, *q, sx, sy, a, b, t, u, v;

	register int i, j;

	if (start) {

		start = 0;

		Perlin_Init();

	}

	setup(0, bx0,bx1, rx0,rx1);
	setup(1, by0,by1, ry0,ry1);

	i = p[ bx0 ];
	j = p[ bx1 ];

	b00 = p[ i + by0 ];
	b10 = p[ j + by0 ];
	b01 = p[ i + by1 ];
	b11 = p[ j + by1 ];

	sx = s_curve(rx0);
	sy = s_curve(ry0);

#define at2(rx,ry) ( rx * q[0] + ry * q[1] )

	q = g2[ b00 ] ; u = at2(rx0,ry0);
	q = g2[ b10 ] ; v = at2(rx1,ry0);
	a = lerp(sx, u, v);

	q = g2[ b01 ] ; u = at2(rx0,ry1);
	q = g2[ b11 ] ; v = at2(rx1,ry1);
	b = lerp(sx, u, v);

	return lerp(sy, a, b);
}

float PerlinNoise2(float a,float b)
{
	float v[2];
    v[0] = a;
    v[1] = b;
    return(Perlin_noise2(v));
}

float Perlin_noise3(float vec[3])

{

	int bx0, bx1, by0, by1, bz0, bz1, b00, b10, b01, b11;
	float rx0, rx1, ry0, ry1, rz0, rz1, *q, sy, sz, a, b, c, d, t, u, v;
	register int i, j;

	if (start) {
		start = 0;
		Perlin_Init();
	}

	setup(0, bx0,bx1, rx0,rx1);
	setup(1, by0,by1, ry0,ry1);
	setup(2, bz0,bz1, rz0,rz1);

	i = p[ bx0 ];
	j = p[ bx1 ];

	b00 = p[ i + by0 ];
	b10 = p[ j + by0 ];
	b01 = p[ i + by1 ];
	b11 = p[ j + by1 ];

	t  = s_curve(rx0);
	sy = s_curve(ry0);
	sz = s_curve(rz0);

#define at3(rx,ry,rz) ( rx * q[0] + ry * q[1] + rz * q[2] )

	q = g3[ b00 + bz0 ] ; u = at3(rx0,ry0,rz0);
	q = g3[ b10 + bz0 ] ; v = at3(rx1,ry0,rz0);
	a = lerp(t, u, v);

	q = g3[ b01 + bz0 ] ; u = at3(rx0,ry1,rz0);
	q = g3[ b11 + bz0 ] ; v = at3(rx1,ry1,rz0);
	b = lerp(t, u, v);

	c = lerp(sy, a, b);

	q = g3[ b00 + bz1 ] ; u = at3(rx0,ry0,rz1);
	q = g3[ b10 + bz1 ] ; v = at3(rx1,ry0,rz1);
	a = lerp(t, u, v);

	q = g3[ b01 + bz1 ] ; u = at3(rx0,ry1,rz1);
	q = g3[ b11 + bz1 ] ; v = at3(rx1,ry1,rz1);
	b = lerp(t, u, v);

	d = lerp(sy, a, b);

	return lerp(sz, c, d);
}

static void normalize2(float v[2])
{
	float s;

	s = MMath_Sqrt(v[0] * v[0] + v[1] * v[1]);
	v[0] = v[0] / s;
	v[1] = v[1] / s;
}

static void normalize3(float v[3])
{
	float s;

	s = MMath_Sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	v[0] = v[0] / s;
	v[1] = v[1] / s;
	v[2] = v[2] / s;
}

void Perlin_Init()
{
	int i, j, k;

	for (i = 0 ; i < B ; i++) {
		p[i] = i;

		g1[i] = (float)((rand() % (B + B)) - B) / B;

		for (j = 0 ; j < 2 ; j++)
			g2[i][j] = (float)((rand() % (B + B)) - B) / B;
		normalize2(g2[i]);

		for (j = 0 ; j < 3 ; j++)
			g3[i][j] = (float)((rand() % (B + B)) - B) / B;
		normalize3(g3[i]);
	}

	while (--i) {
		k = p[i];
		p[i] = p[j = rand() % B];
		p[j] = k;
	}

	for (i = 0 ; i < B + 2 ; i++) {
		p[B + i] = p[i];
		g1[B + i] = g1[i];
		for (j = 0 ; j < 2 ; j++)
			g2[B + i][j] = g2[i][j];
		for (j = 0 ; j < 3 ; j++)
			g3[B + i][j] = g3[i][j];
	}
}
// -----------------------------------------------------------------------------
float Noise2D(int x,int y)
{
	int n = x + y*57;
    // int Res,i;
    unsigned int Res1;
    float Res;

    n = (n<<13)^n;
    Res1 = (n*n*n*15731+n*789221+1376342589) & 0x7fffffff;
    Res = 1.0f - ((float)Res1 / 0x7fffffff);

    return(Res);
}

float SmoothNoise2D(int x,int y)
{
	int px,gx,py,gy;
    px = x-1;	gx = x+1;	py = y-1;	gy = y+1;

	// Max = 4/16 = 1/4 = 0.25
	float corners = (Noise2D(px,py) + Noise2D(gx,py) + Noise2D(px,gy) + Noise2D(gx,gy))/16;
	// Max = 4/8 = 1/2 = 0.5
    float sides   = (Noise2D(px,y)   + Noise2D(gx,y)   + Noise2D(x,py)   + Noise2D(x,gy)) / 8;
    // Max = 1/4 = 0.25
    float center  = (Noise2D(x,y)/4);

    // Max = 1
    return(corners+sides+center);
}

float Interpolate(float a,float b,float factor)
{
	return (b*factor + a*(1.0f-factor));
}

float InterpolateNoise2D(float x,float y)
{
	int   intx  = (int)x;
    float fracx = x - intx;
	int   inty  = (int)y;
    float fracy = y - inty;

    float v1,v2,v3,v4,i1,i2;

 /*
    v1 = SmoothNoise2D(intx  ,inty);
    v2 = SmoothNoise2D(intx+1,inty);
    v3 = SmoothNoise2D(intx  ,inty+1);
    v4 = SmoothNoise2D(intx+1,inty+1);
*/

    v1 = Noise2D(intx  ,inty);
    v2 = Noise2D(intx+1,inty);
    v3 = Noise2D(intx  ,inty+1);
    v4 = Noise2D(intx+1,inty+1);

 	i1 = Interpolate(v1,v2,fracx);
    i2 = Interpolate(v3,v4,fracx);

    return( Interpolate(i1,i2,fracy) );
}

float PerlinNoise2D(float x,float y)
{
    float total     = 0;
    float p         = 0.45;	// persistence
    int   n           = 7; // octaves

    int   frec      = 1;
    float amplitude = 1;

    for (int i=0;i<n;i++)
    {
	    total += (InterpolateNoise2D(x*frec,y*frec)*amplitude);

    	frec      = (1 << (i+1));
        amplitude *= p;
    }
    return(total);
}
//---------------------------------------------------------------------------
