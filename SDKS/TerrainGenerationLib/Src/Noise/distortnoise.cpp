//---------------------------------------------------------------------------
#include "Math/MMath.h"
#include "Perlin.h"

#include "DistortNoise.h"

//---------------------------------------------------------------------------
float DistortNoise(float a,float b)
{
	float offseta, offsetb;
	float Distortion = PerlinNoise2D(a,b);

	offseta = a+0.5;
    offsetb = b+0.5;
    offseta = PerlinNoise2D(offseta,offsetb);
    offseta = PerlinNoise2D(offseta,offsetb);

    offseta *= Distortion;
    offsetb *= Distortion;

    return( MMath_Clamp( PerlinNoise2D(a+offseta,b+offsetb),0,1) );
}
//---------------------------------------------------------------------------
