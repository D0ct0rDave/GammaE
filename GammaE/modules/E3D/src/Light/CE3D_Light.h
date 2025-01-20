//-----------------------------------------------------------------------------
#ifndef CE3D_LightH
#define CE3D_LightH
//-----------------------------------------------------------------------------
#include "GammaE_Math.h"
#include "Materials/CGColor.h"
//-----------------------------------------------------------------------------
typedef enum
{
    LT_None,
    LT_Point,
    LT_Directional,
    LT_Spot
}eLightType;

class CE3D_Light
{
	public:
			CE3D_Light();
			~CE3D_Light();
	
	public:
			CGColor oLitAmb;
			CGColor oLitDiff;
			CGColor oLitSpec;
			
			CVect3	oPos;
			CVect3	oDir;

			// For spot lights
			float	fSpExp;
			float	fSpCutOff;

			float	fCAtt;			// Constant attenuation
			float	fLAtt;			// Linera attenuation
			float	fQAtt;			// Quadratic attenuation
			
			eLightType eType;
};

#endif
