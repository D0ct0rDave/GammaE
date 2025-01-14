//---------------------------------------------------------------------------
#ifndef noiseH
#define noiseH
//---------------------------------------------------------------------------

#include "perlin.h"
#include "DistortNoise.h"

//---------------------------------------------------------------------------
float Noise_Lattice3D (int x,int y,int z);
float Noise_Lattice2D (int x,int y);
float Noise_VNoise3D  (float x,float y,float z);
float Noise_VNoise2D  (float x,float y);

float Noise_GLattice3D(int ix,int iy,int iz,float fx,float fy,float fz);
float Noise_GLattice2D(int ix,int iy,float fx,float fy);
float Noise_GNoise3D  (float x,float y,float z);
float Noise_GNoise2D  (float x,float y);
//---------------------------------------------------------------------------
#endif
