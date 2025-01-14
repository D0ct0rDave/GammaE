//---------------------------------------------------------------------------
#include <stdlib.h>
#include <math.h>
#include "math/mmath.h"
#include "noise.h"

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif

void Noise_InitAll();
bool NoiseInitialized = false;
//---------------------------------------------------------------------------
int random(int iValue)
{
	return(rand() % iValue);
}
//---------------------------------------------------------------------------

#define TABSIZE 256
#define TABMASK (TABSIZE-1)
#define PERM(x)	perm[(x) & TABMASK]
#define INDEX3D(ix,iy,iz) PERM((ix)+PERM((iy)+PERM(iz)))
#define INDEX2D(ix,iy) PERM((ix)+PERM(iy))

unsigned char perm[TABSIZE] = {
	225, 155, 210, 108, 175, 199, 221, 144, 203, 116,  70, 213,  69, 158,  33, 252,
      5,  82, 173, 133, 222, 139, 174,  27,   9,  71,  90, 246,  75, 130,  91, 191,
    169, 138,   2, 151, 194, 235,  81,   7,  25, 113, 228, 159, 205, 253, 134, 142,
    248,  65, 224, 217,  22, 121, 229,  63,  89, 103,  96, 104, 156,  17, 201, 129,
     36,   8, 165, 110, 237, 117, 231,  56, 132, 211, 152,  20, 181, 111, 239, 218,
    170, 163,  51, 172, 157,  47,  80, 212, 176, 250,  87,  49,  99, 242, 136, 189,
    162, 115,  44,  43, 124,  94, 150,  16, 141, 247,  32,  10, 198, 223, 255,  72,
     53, 131,  84,  57, 220, 197,  58,  50, 208,  11, 241,  28,   3, 192,  62, 202,
     18, 215, 153,  24,  76,  41,  15, 179,  39,  46,  55,   6, 128, 167,  23, 188,
    106,  34, 187, 140, 164,  73, 112, 182, 244, 195, 227,  13,  35,  77, 196, 185,
     26, 200, 226, 119,  31, 123, 168, 125, 249,  68, 183, 230, 177, 135, 160, 180,
     12,   1, 243, 148, 102, 166,  38, 238, 251,  37, 240, 126,  64,  74, 161,  40,
    184, 149, 171, 178, 101,  66,  29,  59, 146,  61, 254, 107,  41,  86, 154,   4,
    236, 232, 120,  21, 233, 209,  45,  98, 193, 114,  78,  19, 206,  14, 118, 127,
     48,  79, 147,  85,  30, 208, 219,   4,  88, 234, 190, 122,  95,  67, 143, 109,
    137, 214, 145,  93,  92, 100, 245,   0, 216, 186,  60,  83, 105,  97, 204,  52
};

void Noise_InitPerm()
{
	int i;
    unsigned char index1,index2;
    unsigned char aux;
	for (i=0;i<256;i++) perm[i] = 255-i;

    // Generate a permutated hash table
    for (i=0;i<256*256;i++)
    {
        index1 = random(256);
        index2 = random(256);

        aux = perm[index1];
		perm[index1] = perm[index2];
        perm[index2] = aux;
    }
}

#define RANDNBR	((float)random(65535)/(float)65535)

float ValueTab[TABSIZE];

void Noise_ValueTabInit(int seed)
{
	float *table = ValueTab;
    int i;

    srand(seed);

    Noise_InitPerm();

    for (i=0;i< TABSIZE;i++)
    	*table++ = /*1.0f - 2.0f**/RANDNBR;
}
//---------------------------------------------------------------------------
float Noise_Lattice3D(int x,int y,int z)
{
	if (! NoiseInitialized) Noise_InitAll();
	return( ValueTab[INDEX3D(x,y,z)] );
}

float Noise_Lattice2D(int x,int y)
{
	if (! NoiseInitialized) Noise_InitAll();
	return( ValueTab[INDEX2D(x,y)] );
}
//---------------------------------------------------------------------------
float Noise_VNoise3D(float x,float y,float z)
{
	int ix,iy,iz;
    int i,j,k;
    float fx,fy,fz;
    float xknots[4],yknots[4],zknots[4];

    ix = MMath_Floor(x);	fx = x - ix;
    iy = MMath_Floor(y);	fy = y - iy;
    iz = MMath_Floor(z);	fz = z - iz;

    for (k= -1;k<=2;k++)
    {
    	for (j= -1;j<=2;j++)
        {
        	for (i= -1;i<=2;i++)
            	xknots[i+1] = Noise_Lattice3D(ix+i,iy+j,iz+k);

            yknots[j+1] = MMath_Spline4Knots(fx,xknots);
        }
        zknots[k+1] = MMath_Spline4Knots(fy,yknots);
    }

    return( MMath_Spline4Knots(fz,xknots) );
}
//---------------------------------------------------------------------------
float Noise_VNoise2D(float x,float y)
{
	int ix,iy;
    int i,j;
    float fx,fy;
    float xknots[4],yknots[4];

    ix = MMath_Floor(x);	fx = x - ix;
    iy = MMath_Floor(y);	fy = y - iy;

    for (j= -1;j<=2;j++)
    {
    	for (i= -1;i<=2;i++)
        	xknots[i+1] = Noise_Lattice2D(ix+i,iy+j);

        yknots[j+1] = MMath_Spline4Knots(fx,xknots);
    }

    return(MMath_Spline4Knots(fy,yknots));
}
//---------------------------------------------------------------------------
float GradientTab[TABSIZE*3];

void Noise_GradientTabInit(int Seed)
{
	float *table = GradientTab;
    float z,r,theta;
    int i;

	srand(Seed);
    for (i=0;i<TABSIZE;i++)
    {
    	z = -1.0f + 2.0f*RANDNBR;
        r = MMath_Sqrt(1 - z*z);

        theta    = 2*PI*RANDNBR;
        *table++ = r*cos(theta);
        *table++ = r*sin(theta);
        *table++ = z;
    }
}

float Noise_GLattice3D(int ix,int iy,int iz,float fx,float fy,float fz)
{
	if (! NoiseInitialized) Noise_InitAll();

	float *g =&GradientTab[INDEX3D(ix,iy,iz)*3];
    return (g[0]*fx + g[1]*fy + g[2]*fz);
}

float Noise_GLattice2D(int ix,int iy,float fx,float fy)
{
	if (! NoiseInitialized) Noise_InitAll();

	float *g =&GradientTab[INDEX2D(ix,iy)*3];
    return (g[0]*fx + g[1]*fy);
}
//---------------------------------------------------------------------------
float Noise_GNoise3D(float x,float y,float z)
{
	int ix,iy,iz;
    float fx0,fy0,fz0,fx1,fy1,fz1;

    float wx,wy,wz;
    float vx0,vx1,vy0,vy1,vz0,vz1;

    ix = MMath_Floor(x);	fx0 = x - ix;	fx1 = fx0 - 1;	wx = MMath_SmoothStep(fx0,0,1);
    iy = MMath_Floor(y);	fy0 = y - iy;	fy1 = fy0 - 1;  wy = MMath_SmoothStep(fy0,0,1);
    iz = MMath_Floor(z);	fz0 = z - iz;	fz1 = fz0 - 1;  wz = MMath_SmoothStep(fz0,0,1);

    vx0 = Noise_GLattice3D(ix  ,iy,iz,fx0,fy0,fz0);
    vx1 = Noise_GLattice3D(ix+1,iy,iz,fx1,fy0,fz0);
    vy0 = MMath_Lerp(wx,vx0,vx1);

    vx0 = Noise_GLattice3D(ix  ,iy+1,iz,fx0,fy1,fz0);
    vx1 = Noise_GLattice3D(ix+1,iy+1,iz,fx1,fy1,fz0);
    vy1 = MMath_Lerp   (wx,vx0,vx1);

    vz0 = MMath_Lerp(wy,vy0,vy1);

    vx0 = Noise_GLattice3D(ix  ,iy,iz+1,fx0,fy0,fz1);
    vx1 = Noise_GLattice3D(ix+1,iy,iz+1,fx1,fy0,fz1);
    vy0 = MMath_Lerp(wx,vx0,vx1);

    vx0 = Noise_GLattice3D(ix  ,iy+1,iz+1,fx0,fy1,fz1);
    vx1 = Noise_GLattice3D(ix+1,iy+1,iz+1,fx1,fy1,fz1);
    vy1 = MMath_Lerp(wx,vx0,vx1);

	vz1 = MMath_Lerp(wy,vy0,vy1);

    return( MMath_Lerp(wz,vz0,vz1) );
}
//---------------------------------------------------------------------------
float Noise_GNoise2D(float x,float y)
{
	int ix,iy;
    float fx0,fy0,fx1,fy1;

    float wx,wy;
    float vx0,vx1,vy0,vy1;

    ix = MMath_Floor(x);	fx0 = x - ix;	fx1 = fx0 - 1;	wx = MMath_SmoothStep(fx0,0,1);
    iy = MMath_Floor(y);	fy0 = y - iy;	fy1 = fy0 - 1;  wy = MMath_SmoothStep(fy0,0,1);

    vx0 = Noise_GLattice2D(ix  ,iy,fx0,fy0);
    vx1 = Noise_GLattice2D(ix+1,iy,fx1,fy0);
    vy0 = MMath_Lerp    (wx,vx0,vx1);

    vx0 = Noise_GLattice2D(ix  ,iy+1,fx0,fy1);
    vx1 = Noise_GLattice2D(ix+1,iy+1,fx1,fy1);
    vy1 = MMath_Lerp    (wx,vx0,vx1);

    return ( MMath_Lerp(wy,vy0,vy1) );
}
//---------------------------------------------------------------------------
void Noise_InitAll()
{
	// Noise_InitPerm();
    Noise_ValueTabInit(665);
    Noise_GradientTabInit(665);

    NoiseInitialized = true;
}
//---------------------------------------------------------------------------
